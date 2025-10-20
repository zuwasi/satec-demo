/**
 **************************************************************************************
 * @file    drv_dma.h
 * @brief   Driver API for DMA
 *
 * @author  Aixing.Li
 * @version V1.0.0
 *
 * &copy; 2019 BEKEN Corporation Ltd. All rights reserved.
 **************************************************************************************
 */

#ifndef __DRV_DMA_H__
#define __DRV_DMA_H__

#include <stdint.h>


typedef void (*dma_int_cb_t)(uint8_t);


#define INT_TYPE_END    1
#define INT_TYPE_HALF   0

/**
 * @brief DMA request definition
 */
typedef enum
{
    MEM_READ_REQ=0,
    I2S0_REQ_RX=1,
    UART1_REQ_RX=2,
    UART2_REQ_RX=3,
    SPI_REQ_RX=4,
    ADC_REQ_RX=5,

    I2S0_REQ_TX=1<<5,
    UART1_REQ_TX=2<<5,
    UART2_REQ_TX=3<<5,
    SPI_REQ_TX=4<<5,
    ADC_REQ_TX=5<<5,
}DMA_REQ;

/**
 * @brief DMA transfer mode definition
 */
typedef enum
{
    DMA_MODE_SINGLE = 0,
    DMA_MODE_REPEAT,
}DMA_MODE;

/**
 * @brief DMA address mode definition
 */
typedef enum
{
    DMA_ADDR_NO_CHANGE     = 0,
    DMA_ADDR_AUTO_INCREASE = 1,
}DMA_ADDR_MODE;

/**
 * @brief DMA data type (or width) definition
 */
typedef enum
{
    DMA_DATA_TYPE_CHAR = 0,
    DMA_DATA_TYPE_SHORT,
    DMA_DATA_TYPE_LONG,
}DMA_DATA_TYPE;

/**
 * @brief DMA control command definition
 */
typedef enum
{
    DMA_CTRL_CMD_NULL,
    DMA_CTRL_CMD_PRIOPRITY_SET,
    DMA_CTRL_CMD_FINISH_INT_EN,
    DMA_CTRL_CMD_HALF_FINISH_INT_EN,
    DMA_CTRL_CMD_FINISH_INT_FLAG_GET,
    DMA_CTRL_CMD_HALF_FINISH_INT_FLAG_GET,
    DMA_CTRL_CMD_SRC_RD_INTERVAL_SET,
    DMA_CTRL_CMD_DST_WR_INTERVAL_SET,
    DMA_CTRL_CMD_REMAIN_LENGTH_GET,
    DMA_CTRL_CMD_SRC_BUFF_FLUSH,
}DMA_CTRL_CMD;

/**
 * @brief DMA channel malloc
 * @return DMA channel handler
 */
void* dma_channel_malloc(void);

/**
 * @brief DMA channel free
 * @param dma DMA channel handler
 */
void  dma_channel_free(void* dma);

/**
 * @brief DMA channel configuration
 * @param dma  DMA channel handler
 * @param req  DMA request mode, @see DMA_REQ
 * @param mode DMA transfer mode, @see DMA_MODE
 * @param src_start_addr src start address
 * @param src_stop_addr  src stop  address
 * @param src_addr_mode  src address mode, @see DMA_ADDR_MODE
 * @param src_data_type  src data type, @see DMA_DATA_TYPE
 * @param dst_start_addr dst start address
 * @param dst_stop_addr  dst stop  address
 * @param dst_addr_mode  dst address mode, @see DMA_ADDR_MODE
 * @param dst_data_type  dst data type, @see DMA_DATA_TYPE
 * @param data_length    transfer data length
 */
void dma_channel_config(void*           dma,
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
                       );

/**
 * @brief DMA channel control
 * @param dma DMA channel handler
 * @param dma control command
 * @param dma control argument
 */
void dma_channel_ctrl(void* dma, uint32_t cmd, uint32_t arg);

/**
 * @brief DMA channel enable
 * @param dma DMA channel handler
 * @param enable 0:disable, 1:enable
 */
void dma_channel_enable(void* dma, uint32_t enable);

/**
 * @brief Set current source address
 * @param dma DMA channel handler
 * @param addr address
 */
void dma_channel_src_curr_address_set(void* dma, uint32_t addr);

/**
 * @brief Set current destination address
 * @param dma DMA channel handler
 * @param addr address
 */
void dma_channel_dst_curr_address_set(void* dma, uint32_t addr);

/**
 * @brief Get current source read address
 * @param dma DMA channel handler
 * @return current source read address
 */
uint32_t dma_channel_src_curr_pointer_get(void* dma);

/**
 * @brief Get current destination write address
 * @param dma DMA channel handler
 * @return current destination write address
 */
uint32_t dma_channel_dst_curr_pointer_get(void* dma);
void dma_isr(void);

/**
 * @brief DMA channel link to source buf
 * @param dma DMA channel handler
 * @param buf,sz buffer parameter
 * @return none
 */
void dma_channel_link_src(void* dma, uint32_t buf, int sz);

/**
 * @brief DMA channel link to destine buf
 * @param dma DMA channel handler
 * @param buf,sz buffer parameter
 * @return none
 */
void dma_channel_link_dst(void* dma, uint32_t buf, int sz);

/**
 * @brief set DMA transfer completion callback
 * @param cbk DMA channel handler
 * @return old callback
 */
void* dma_set_int(void*cbk);

/**
 * @brief set DMA transfer interrupt type
 * @param dma DMA channel handler
 * @param hf2_tc1 bit0:all,bit1:half
 * @return 
 */
void dma_channel_set_int_type(void*dma,int hf2_tc1);

/**
 * @brief get DMA channel index
 * @param dma DMA channel handler
 * @return index of dma
 */
int dma_channel_get_index(void*dma);

/**
 * @brief access(set/get) DMA transfer completion callback
 * @param dma DMA channel handler
 * @return 
 */
void dma_channel_set_half_completed_cbk(void*dma,void*cbk);
void *dma_channel_get_half_completed_cbk(void*dma);
void dma_channel_set_completed_cbk(void*dma,void*cbk);
void *dma_channel_get_completed_cbk(void*dma);
#endif//__DRV_DMA_H__
