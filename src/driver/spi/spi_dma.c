
/**
 ****************************************************************************************
 *
 * @file spi.c
 *
 * @brief spi driver
 *
 * Copyright (C) BeKen 2009-2017
 *
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stddef.h>     // standard definition
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "spi.h"       // uart definition
#include "uart1.h"
#include "dma.h"
#include "driver_gpio.h"
#include "BK3437_RegList.h"
#include "user_config.h"
#include "icu.h"


#if(SPI_DRIVER)
#if(SPI_DMA_MODE) 
extern spi_param_t spi_param; 
static void* dma_handle=NULL;
void spi_write_dma_init(uint32_t *buff,uint32_t len,DMA_DATA_TYPE dst_data_type,dma_int_cb_t int_cb)
{
    void* spi_dma = dma_channel_malloc();

    dma_channel_config( 
                       spi_dma,
                       SPI_REQ_TX,
                       DMA_MODE_REPEAT,
                       (uint32_t)buff,
                       (uint32_t)buff+len,
                       DMA_ADDR_AUTO_INCREASE,
                       DMA_DATA_TYPE_LONG,
                       (uint32_t)&SPI_REG0X3_DAT,
                       (uint32_t)&SPI_REG0X3_DAT,
                       DMA_ADDR_NO_CHANGE,
                       dst_data_type,//DMA_DATA_TYPE_SHORT,
                       len
                      );

    dma_handle = spi_dma;
    dma_channel_src_curr_address_set(spi_dma,(uint32_t)buff+len);
    dma_channel_set_int_type(spi_dma,1);
    dma_channel_set_int_type(spi_dma,2);
    dma_channel_set_completed_cbk(spi_dma,int_cb);
    
    dma_channel_enable(spi_dma, 1);
#if 0
    uart_printf("app_voice.dma_handle=%x\r\n",dma_handle);
    uart_printf("DMA0=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x0*4));
    uart_printf("DMA1=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x1*4));
    uart_printf("DMA2=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x2*4));
    uart_printf("DMA3=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x3*4));
    uart_printf("DMA4=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x4*4));
    uart_printf("DMA5=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x5*4));
    uart_printf("DMA6=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x6*4));
    uart_printf("DMA7=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x7*4));
    uart_printf("DMA80=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x80*4));
    uart_printf("DMA90=%x\r\n",REG_READ(BASEADDR_GENER_DMA+0x90*4));
#endif
}
void spi_dma_write(uint32_t *buff,uint32_t len,DMA_DATA_TYPE type,spi_write_cb result_callback)
{ 
    if(len>0xffff)
        len=0xffff;
    spi_param.write_complete_cb = result_callback;
//    spi_waitbusying();
    spi_write_dma_init(buff,len,type,NULL);
    if(type==DMA_DATA_TYPE_SHORT)
        spi_send(len/2);
    else 
        spi_send(len);
}

void spi_dma_read(uint8_t *buffer,uint16_t buffer_len,spi_read_cb result_callback)
{ 
    #if 0
    if(buffer_len>0xfff)
        buffer_len=0xfff;
    
    spi_param.read_complete_cb = result_callback;

    spi_waitbusying(); 

    dma_config_read(0,SPI_REQ,SPI_REG0X3_DAT_ADDR,(uint32_t)buffer,buffer_len,DMA_DW_8B);    

    spi_receiv(buffer_len);
    #endif
}
void spi_dma_stop(void)
{
    if(dma_handle != NULL)
    {
        dma_channel_enable(dma_handle, 0);
        dma_channel_free(dma_handle);
    }
    spi_stop();
}
void spi_dma_write_result_callback(void)
{
    uart_printf("write ok\r\n");
    spi_dma_stop();
}
void spi_dma_read_result_callback(void)
{
    uart_printf("read complete\r\n");
}
void spi_dma_test(void)
{
    static uint8_t buff[200];
    for(int i=0;i<200;i++)
        buff[i]=i+1;
    
    spi_init(SPI_MASTER,2,SPI_8BITS,0);
    spi_dma_write((uint32_t*)buff,20,DMA_DATA_TYPE_CHAR,spi_dma_write_result_callback);
}
#endif
#endif



/// @} SPI DRIVER

