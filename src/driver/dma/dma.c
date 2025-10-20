/**
 **************************************************************************************
 * @file    drv_dma.c
 * @brief   Driver API for DMA
 *
 * @author  Aixing.Li
 * @version V1.0.0
 *
 * &copy; 2019 BEKEN Corporation Ltd. All rights reserved.
 **************************************************************************************
 */

#include <stddef.h>
#include "BK3437_RegList.h"
#include "user_config.h"
#include "dma.h"



#define DMA_CHANNEL_NUM     (16)
#define dmac                ((volatile DMAContext*)BASEADDR_GENER_DMA)

dma_int_cb_t dma_completed_cb[DMA_CHANNEL_NUM]={NULL};


typedef struct _DMAConfig
{
    volatile uint32_t enable             : 1;
    volatile uint32_t finish_int_en      : 1;
    volatile uint32_t half_finish_int_en : 1;
    volatile uint32_t dma_mode           : 1; //0: SINGLE, 1:REPEAT
    volatile uint32_t src_data_width     : 2; //0: 8 bits, 1: 16 bits, 2: 32 bits
    volatile uint32_t dst_data_width     : 2; //0: 8 bits, 1: 16 bits, 2: 32 bits
    volatile uint32_t src_addr_mode      : 1; //0: no change, 1: increase
    volatile uint32_t dst_addr_mode      : 1; //0: no change, 1: increase
    volatile uint32_t src_addr_loop      : 1; //0: no loop, 1: loop
    volatile uint32_t dst_addr_loop      : 1; //0: no loop, 1: loop
    volatile uint32_t prioprity          : 3; //bigger & higher
    volatile uint32_t                    : 1; //bigger & higher
    volatile uint32_t trans_len          :16; //actually len = trans + 1
    volatile uint32_t                    : 0;

    volatile uint32_t dst_start_addr;
    volatile uint32_t src_start_addr;
    volatile uint32_t dst_loop_stop_addr;
    volatile uint32_t dst_loop_start_addr;
    volatile uint32_t src_loop_stop_addr;
    volatile uint32_t src_loop_start_addr;

    volatile uint32_t dma_request        :10; //@see DMA_REQ
    volatile uint32_t                    : 2;
    volatile uint32_t src_rd_interval    : 4; //source read operate interval, unit in cycle.
    volatile uint32_t dst_wr_interval    : 4; //destination write operate interval, unit in cycle.
    volatile uint32_t                    : 0;
}DMAConfig;

typedef struct _DMAStatus
{
    volatile uint32_t remain_length         :17;
    volatile uint32_t flush_src_buff        : 1;
    volatile uint32_t reserved              : 6;
    volatile uint32_t finish_int_cnt        : 4;
    volatile uint32_t half_finish_int_cnt   : 4;
}DMAStatus;

typedef struct _DMAContext
{
    volatile DMAConfig config[DMA_CHANNEL_NUM];

    volatile uint32_t src_address[DMA_CHANNEL_NUM];
    volatile uint32_t dst_address[DMA_CHANNEL_NUM];
    volatile uint32_t src_pointer[DMA_CHANNEL_NUM];
    volatile uint32_t dst_pointer[DMA_CHANNEL_NUM];

    volatile DMAStatus status[DMA_CHANNEL_NUM];

    volatile uint32_t prio_mode            : 1;//0:round-robin, 1:fixed prioprity
    volatile uint32_t                       :31;

    volatile uint32_t finish_int_flag;
}DMAContext;

static uint16_t dma_channels_used = 0;

void* dma_channel_malloc(void)
{
    uint32_t i;

    for(i = 0; i < DMA_CHANNEL_NUM; i++)
    {
        if(!(dma_channels_used & (1 << i)))
        {
            dma_channels_used |= (1 << i);
            break;
        }
    }

    return i < DMA_CHANNEL_NUM ? (void*)&dmac->config[i] : NULL;
}

void dma_channel_free(void* dma)
{
    uint32_t i = ((uint32_t)dma - (uint32_t)&dmac->config[0]) / sizeof(DMAConfig);

    if(i < DMA_CHANNEL_NUM && (uint32_t)&dmac->config[i] == (uint32_t)dma)
    {
        dma_channels_used &= (~(1 << i)) & ((1 << DMA_CHANNEL_NUM) - 1);
        dma = NULL;
    }
}

void dma_isr(void)
{
    int i;
    uint32_t dma_int_channel;
    uint32_t int_status=dmac->finish_int_flag;
    dmac->finish_int_flag |= int_status;
    
    if(int_status&0xffff)
    {
        dma_int_channel=1;
        for(i=0;i<DMA_CHANNEL_NUM;i++)
        {
            if(int_status&dma_int_channel)
            {
                if(dma_completed_cb[i])
                {
                    dma_completed_cb[i](INT_TYPE_END);
                    break;
                }
            }
            dma_int_channel<<=1;
        }
    }
    if((int_status>>16)&0xffff)
    {
        int_status>>=16;
        dma_int_channel=1;
        for(i=0;i<DMA_CHANNEL_NUM;i++)
        {
            if(int_status&dma_int_channel)
            {
                if(dma_completed_cb[i])
                {
                    dma_completed_cb[i](INT_TYPE_HALF);
                    break;
                }
            }
            dma_int_channel<<=1;
        }
    }
}

void dma_channel_config(void*           _dma,
                        DMA_REQ         req,
                        DMA_MODE        mode,
                        uint32_t        src_start_addr,
                        uint32_t        src_stop_addr,
                        DMA_ADDR_MODE   src_addr_mode,
                        DMA_DATA_TYPE   src_data_type,
                        uint32_t        dst_start_addr,
                        uint32_t        dst_stop_addr,
                        DMA_ADDR_MODE   dst_addr_mode,
                        DMA_DATA_TYPE   dst_data_type,
                        uint32_t        data_length
                       )
{
    if(_dma)
    {
        uint32_t   idx = ((uint32_t)_dma - (uint32_t)&dmac->config[0]) / sizeof(DMAConfig);
        DMAConfig* dma = (DMAConfig*)_dma;

        dma->trans_len           = data_length - 1;
        dma->enable              = 0;
        dma->finish_int_en       = 0;
        dma->half_finish_int_en  = 0;
        dma->dma_request         = req;
        dma->dma_mode            = mode;
        dma->src_start_addr      = src_start_addr;
        dma->src_loop_start_addr = src_start_addr;
        dma->src_loop_stop_addr  = src_stop_addr;
        dma->src_addr_loop       = src_addr_mode;
        dma->src_addr_mode       = src_addr_mode;
        dma->src_data_width      = src_data_type;
        dma->dst_start_addr      = dst_start_addr;
        dma->dst_loop_start_addr = dst_start_addr;
        dma->dst_loop_stop_addr  = dst_stop_addr;
        dma->dst_addr_loop       = dst_addr_mode;
        dma->dst_addr_mode       = dst_addr_mode;
        dma->dst_data_width      = dst_data_type;

        dmac->src_address[idx] = (src_addr_mode == DMA_ADDR_NO_CHANGE) ? 0 : src_start_addr;
        dmac->dst_address[idx] = (dst_addr_mode == DMA_ADDR_NO_CHANGE) ? 0 : dst_start_addr;
    }
}


void dma_channel_enable(void* dma, uint32_t enable)
{
    ((DMAConfig*)dma)->enable = !!enable;
}

void dma_channel_src_curr_address_set(void* dma, uint32_t addr)
{
    dmac->src_address[((uint32_t)dma - (uint32_t)&dmac->config[0]) / sizeof(DMAConfig)] = addr;
}

void dma_channel_dst_curr_address_set(void* dma, uint32_t addr)
{
    dmac->dst_address[((uint32_t)dma - (uint32_t)&dmac->config[0]) / sizeof(DMAConfig)] = addr;
}

uint32_t dma_channel_src_curr_pointer_get(void* dma)
{
    return dmac->src_pointer[((uint32_t)dma - (uint32_t)&dmac->config[0]) / sizeof(DMAConfig)];
}

uint32_t dma_channel_dst_curr_pointer_get(void* dma)
{
    return dmac->dst_pointer[((uint32_t)dma - (uint32_t)&dmac->config[0]) / sizeof(DMAConfig)];
}
/// @brief link DMA to source memory
/// @param dma DMA channel handler
/// @param addr buffer pointer
/// @param sz buffer size
void dma_channel_link_src(void* dma, uint32_t addr, int sz)
{
    if(sz>0x10000)
    {
        while(1);
    }
    DMAConfig*pdma=(DMAConfig*)dma;
    pdma->src_start_addr=addr;
    pdma->trans_len=(sz);
}

/// @brief link DMA to distine memory
/// @param dma DMA channel handler
/// @param addr buffer pointer
/// @param sz buffer size
void dma_channel_link_dst(void* dma, uint32_t addr, int sz)
{
    if(sz>0x10000)
    {
        while(1);
    }
    DMAConfig*pdma=(DMAConfig*)dma;
    pdma->dst_start_addr=addr;
    pdma->trans_len=(sz);
}

void dma_channel_set_int_type(void*dma,int hf2_tc1)
{
    DMAConfig*pdma=(DMAConfig*)dma;
    if(hf2_tc1==0)
    {
        pdma->finish_int_en=0;
        pdma->half_finish_int_en=0;
    }
    else
    {
        if(hf2_tc1&1)pdma->finish_int_en=1;
        if(hf2_tc1&2)pdma->half_finish_int_en=1;
    }
    uart_printf("dmacntl=%x\r\n",*((uint32_t*)pdma));
}
int dma_channel_get_index(void*dma)
{
    return ((uint32_t)dma - (uint32_t)&dmac->config[0]) / sizeof(DMAConfig);
}

void dma_channel_set_completed_cbk(void*dma,void*cbk)
{
    int idx=dma_channel_get_index(dma);
    if((idx<0)||(idx>=DMA_CHANNEL_NUM))return;
    dma_completed_cb[idx]=(dma_int_cb_t)cbk;
}
void *dma_channel_get_completed_cbk(void*dma)
{
    int idx=dma_channel_get_index(dma);
    if((idx<0)||(idx>=DMA_CHANNEL_NUM))return NULL;
    return((void*)dma_completed_cb[idx]);
}
