
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
#include "spi_dma.h"

/*******************************************************
       _________
RGB 1: |        |_____|==SPI :2hight, 1low

      ______
RGB 0:|     |_________|==SPI:1hight ,2low

OR
       _________
RGB 1: |        |_____|==SPI :2hight,byte interval 

      ______
RGB 0:|     |_________|==SPI:1hight, 1low+byte interval 

*******************************************************/
#if(SPI_DRIVER)
#if(SPI_DMA_MODE) 
#if(SPI_TO_RGB_2812) 
#pragma pack(4)
uint8_t spi_dma_buff[9600];
#pragma pack()
extern spi_param_t spi_param; 
void spi_to_rgb_init(uint8_t freq_div,uint8_t bit_wdth,uint8_t gpio_sel)
{
    // SPI clock enable
    SET_SPI_POWER_UP;
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);
    if(gpio_sel==0)
    {
        // Enable GPIO P04, P05, P06, P07 peripheral function for spi
        gpio_config(0x04,SC_FUN,PULL_NONE);
        gpio_config(0x05,SC_FUN,PULL_NONE);
        gpio_config(0x06,SC_FUN,PULL_NONE);
        gpio_config(0x07,SC_FUN,PULL_NONE);
        gpio_scfun_sel(0x04,0);
        gpio_scfun_sel(0x05,0);
        gpio_scfun_sel(0x06,0);
        gpio_scfun_sel(0x07,0);
    }
    else
    {
        // Enable GPIO P1.5, P1.6, P1.7, P2.0 peripheral function for spi
        gpio_config(0x15,SC_FUN,PULL_NONE);
        gpio_config(0x16,SC_FUN,PULL_NONE);
        gpio_config(0x17,SC_FUN,PULL_NONE);
        gpio_config(0x20,SC_FUN,PULL_NONE);
        gpio_scfun_sel(0x15,1);
        gpio_scfun_sel(0x16,1);
        gpio_scfun_sel(0x17,1);
        gpio_scfun_sel(0x20,1);
    }
    SPI_REG0X0_CFG = 0;
    SPI_REG0X0_CFG =  (0x00UL << POS_SPI_REG0X0_BYTE_INTLVAL)
                        | (0x01UL << POS_SPI_REG0X0_SPIEN)
                        | (CKPHA_CLK1 << POS_SPI_REG0X0_CKPHA)
                        | (CKPOL_L << POS_SPI_REG0X0_CKPOL)
                        | (0x00UL << POS_SPI_REG0X0_LSB_FIRST)
                        | (bit_wdth << POS_SPI_REG0X0_BIT_WDTH)
                        | (0x00UL << POS_SPI_REG0X0_WIRE3_EN)
                        | (freq_div << POS_SPI_REG0X0_SPI_CKR)  //clk div
                        | (0x00UL << POS_SPI_REG0X0_RXFIFO_INT_EN)  // enable rxint
                        | (0x00UL << POS_SPI_REG0X0_TXFIFO_INT_EN)
                        | (0x00UL << POS_SPI_REG0X0_RXOVF_EN)
                        | (0x00UL << POS_SPI_REG0X0_TXUDF_EN)
                        | (0x01UL << POS_SPI_REG0X0_RXFIFO_INT_LEVEL)  //rx
                        | (0x01UL << POS_SPI_REG0X0_TXFIFO_INT_LEVEL);
    
    SPI_REG0X1_CN = (1 << POS_SPI_REG0X1_TX_FINISH_INT_EN)
                    |(1 << POS_SPI_REG0X1_RX_FINISH_INT_EN);

    SPI_REG0X0_CFG |= ( 0x01UL << POS_SPI_REG0X0_MSTEN);      
    
    SYS_REG0X4_CLK_SEL &= ~(1<<POS_SYS_REG0X4_SPICLK_SEL);////PLL CLK
    //SYS_REG0X4_CLK_SEL |= (1<<POS_SYS_REG0X4_SPICLK_SEL);
    spi_param.spi_state=1;
    spi_param.write_complete_cb=NULL;
    spi_param.read_complete_cb=NULL;
}
void spi_to_rgb_2812_init(void)
{
    spi_to_rgb_init(5,SPI_8BITS,0);
}

uint16_t rgb_2812_data_encode(uint8_t* databuffer,uint16_t datalen,uint8_t* spidatabuffer)
{
    char bit;
    uint8_t cur_bitmap=0;
    uint8_t cur_bitnum=0;
    uint16_t spidatalen=0;
    uint8_t tampval[8]={0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1};
    for(uint16 i=0;i<datalen;i++)
    {
        for(uint8_t j=0;j<8;j++)
        {
            bit=databuffer[i]&tampval[j];
            
            if(bit>=1)
            {
                
                switch(cur_bitnum)
                {
                    case 0:
                        cur_bitmap = (cur_bitmap<<5)|0x18;
                        cur_bitnum = cur_bitnum+5;
                        break;
                    case 3:
                        cur_bitmap = (cur_bitmap<<5)|0x1c;
                        spidatabuffer[spidatalen++]=cur_bitmap;
                        cur_bitmap = 0;
                        cur_bitnum = 0;
                        break;
                    case 4:    
                        cur_bitmap = (cur_bitmap<<4)|0xc;
                        spidatabuffer[spidatalen++]=cur_bitmap;
                        cur_bitmap = 0;
                        cur_bitnum = 0;
                        break;
                    case 5:    
                        cur_bitmap = (cur_bitmap<<3)|0x6;
                        spidatabuffer[spidatalen++]=cur_bitmap;
                        cur_bitmap = 0;
                        cur_bitnum = 0;
                        break;
                    case 6:
                        cur_bitmap = (cur_bitmap<<2)|0x3;
                        spidatabuffer[spidatalen++]=cur_bitmap;
                        cur_bitmap = 0;
                        cur_bitnum = 1;
                        break;
                    default:
                        cur_bitmap = (cur_bitmap<<4)|0xc;
                        cur_bitnum = cur_bitnum+4;
                        break;
                        
                }
            }else
            {
                switch(cur_bitnum)
                {
                    case 1:
                        cur_bitmap = (cur_bitmap<<4)|0x8;
                        cur_bitnum = cur_bitnum+4;
                        break;
                    case 5:    
                        cur_bitmap = (cur_bitmap<<3)|0x4;
                        spidatabuffer[spidatalen++]=cur_bitmap;
                        cur_bitmap = 0;
                        cur_bitnum = 0;
                        break;
                    case 6:
                        cur_bitmap = (cur_bitmap<<2)|0x2;
                        spidatabuffer[spidatalen++]=cur_bitmap;
                        cur_bitmap = 0;
                        cur_bitnum = 0;
                        break;
                    default:
                        cur_bitmap = (cur_bitmap<<3)|0x4;
                        cur_bitnum = cur_bitnum+3;
                        break;
                        
                }
            }

        }
    }
    if(cur_bitnum !=0)
    {
        spidatabuffer[spidatalen++]=cur_bitmap;
    }
    uart_printf("spidatalen:%d\n",spidatalen);    
    return spidatalen;
}
void spi_to_rgb_2812_test(void)
{
    uint8_t rgbdata[1000];
    uint16_t spi_datalen;
    for(int i=0;i<1000;i++)
        rgbdata[i]=i%255;
    
    rgbdata[0]=0x00;
    rgbdata[1]=0x33;
    rgbdata[2]=0x55;
    rgbdata[3]=0x77;
    rgbdata[4]=0xff;
    spi_datalen  = rgb_2812_data_encode(rgbdata,sizeof(rgbdata),spi_dma_buff);
 
    
    spi_dma_write((uint32_t*)spi_dma_buff,spi_datalen,DMA_DATA_TYPE_CHAR,spi_dma_write_result_callback);


}
#endif
#endif
#endif


/// @} SPI DRIVER

