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
       _________________
RGB 1: |                |_____|== SPI :14hight, 2low+byte interval

      ______
RGB 0:|     |_________________|==SPI:5hight, 11low++byte interval

*******************************************************/


#if(SPI_DRIVER)
#if(SPI_DMA_MODE) 
#if(SPI_TO_RGB_1903) 

#define RGB_DATA_LEN 3000
#define SPI_DMA_BUFF_LEN 3200
extern void spi_dma_write_result_callback(void);
#pragma pack(4)
uint8_t spi_dma_buff[SPI_DMA_BUFF_LEN];
uint8_t rgb_data[RGB_DATA_LEN];

uint16_t encoded_len=0;
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
    SPI_REG0X0_CFG =  (0x02UL << POS_SPI_REG0X0_BYTE_INTLVAL)
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
    SYS_REG0X4_CLK_SEL |= (1<<POS_SYS_REG0X4_SPICLK_SEL);
    spi_param.spi_state=1;
    spi_param.write_complete_cb=NULL;
    spi_param.read_complete_cb=NULL;
}
void spi_to_rgb_1903_init(void)
{
    spi_to_rgb_init(0,SPI_16BITS,0);
}


uint16_t rgb_1903_data_encode(uint8_t* databuffer,uint16_t datalen,uint16_t* spidatabuffer)
{
    char bit;
    uint16_t spidatalen=0;
    uint8_t tampval[8]={0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1};
    
    for(uint16 i=0;i<datalen;i++)
    {
        for(uint8_t j=0;j<8;j++)
        {
            bit=databuffer[i]&tampval[j];
            
            if(bit>=1)
            {
                spidatabuffer[spidatalen++]=0xfffc;
                
            }else
            {
                spidatabuffer[spidatalen++]=0xf800;
            }

        }
    }
    //uart_printf("spidatalen:%d\n",spidatalen);    
    return spidatalen;
}

uint16_t rgb_1903_data_encode1(uint8_t* databuffer,uint16_t datalen,uint16_t* spidatabuffer)
{
    uint16_t spidatalen=0;
    uint32_t *spidata=(uint32_t *)spidatabuffer;
    for(uint16 i=0;i<datalen;i++)
    {
        
        switch(databuffer[i]&0xc0)
        {
            case 0x80:
                spidata[spidatalen++]=0xf800fffc;
                break;
            case 0x40:
                spidata[spidatalen++]=0xfffcf800;
                break;
            case 0xc0:
                spidata[spidatalen++]=0xfffcfffc;
                break;
            case 0x00:
                spidata[spidatalen++]=0xf800f800;
                break;
                        
        }
        switch(databuffer[i]&0x30)
        {
            case 0x10:
                spidata[spidatalen++]=0xfffcf800;
                break;
            case 0x20:
                spidata[spidatalen++]=0xf800fffc;
                break;
            case 0x30:
                spidata[spidatalen++]=0xfffcfffc;
                break;
            case 0x00:
                spidata[spidatalen++]=0xf800f800;
                break;
                        
        }
                    
        switch(databuffer[i]&0xc)
        {
            case 0x8:
                spidata[spidatalen++]=0xf800fffc;
                break;
            case 0x4:
                spidata[spidatalen++]=0xfffcf800;
                break;
            case 0xc:
                spidata[spidatalen++]=0xfffcfffc;
                break;
            case 0x0:
                spidata[spidatalen++]=0xf800f800;
                break;
                        
        }
        switch(databuffer[i]&0x3)    
        {
            case 0:
                spidata[spidatalen++]=0xf800f800;
                break;
            case 1:
                spidata[spidatalen++]=0xfffcf800;
                break;
            case 2:
                spidata[spidatalen++]=0xf800fffc;
                break;
            case 3:
                spidata[spidatalen++]=0xfffcfffc;
                break;
                        
        }

        
    }
    //uart_printf("spidatalen:%d\n",spidatalen);    
    return spidatalen*2;
}
uint8_t wait_last_half_send=0;

void dma_int_cb_1903(uint8_t type)
{
    uint8_t len_one_time;
    //gpio_set(0x21,1);

    if(wait_last_half_send == 1)
    {
        spi_dma_stop();
        wait_last_half_send = 0;
        uart_printf("DMA send ok %d \n",encoded_len);    
        encoded_len = 0;
        return;
    }
    
    if(RGB_DATA_LEN==encoded_len)
    {
        wait_last_half_send = 1;
        if(type==INT_TYPE_HALF)//half finish
        {
            for(int i=0;i<100;i++)
            {
                spi_dma_buff[i]=0;
            }    
        }else if(type==INT_TYPE_END)//finish
        {
            uint8_t *temp=spi_dma_buff+SPI_DMA_BUFF_LEN/2;
            for(int i=0;i<100;i++)
            {
                temp[i]=0;
            }    
        }
    }else
    {
        if(RGB_DATA_LEN>=(encoded_len+100))
        {
            len_one_time = 100;
            if(type==INT_TYPE_HALF)//half finish
            {
                //gpio_set(0x22,1);
                rgb_1903_data_encode1(rgb_data+encoded_len,len_one_time,(uint16_t*)spi_dma_buff);
                //gpio_set(0x22,0);
            }else if(type==INT_TYPE_END)//finish
            {
                //gpio_set(0x22,1);
                rgb_1903_data_encode1(rgb_data+encoded_len,len_one_time,(uint16_t*)(spi_dma_buff+SPI_DMA_BUFF_LEN/2));
                //gpio_set(0x22,0);
            }
            encoded_len = encoded_len+100;
        }    
        else
        {
            len_one_time=RGB_DATA_LEN-encoded_len;
            
            if(type==INT_TYPE_HALF)//half finish
            {
                //gpio_set(0x22,1);
                rgb_1903_data_encode1(rgb_data+encoded_len,len_one_time,(uint16_t*)spi_dma_buff);
                //gpio_set(0x22,0);
            }else if(type==INT_TYPE_END)//finish
            {
                //gpio_set(0x22,1);
                rgb_1903_data_encode1(rgb_data+encoded_len,len_one_time,(uint16_t*)(spi_dma_buff+SPI_DMA_BUFF_LEN/2));
                //gpio_set(0x22,0);
            }
            encoded_len = RGB_DATA_LEN;
        }    
    }
    //gpio_set(0x21,0);
}
void spi_to_rgb_1903_test(void)
{
    for(int i=0;i<RGB_DATA_LEN;i++)
    {
        rgb_data[i]=0;
    }
    rgb_data[0]=0x9a;
    rgb_data[RGB_DATA_LEN-1]=1;
    gpio_config(0x21,OUTPUT,PULL_HIGH);
    gpio_set(0x21,0);
      gpio_config(0x22,OUTPUT,PULL_HIGH);
    gpio_set(0x22,1);
    rgb_1903_data_encode1(rgb_data,200,(uint16_t*)spi_dma_buff);
    gpio_set(0x22,0);
    encoded_len = 200;
    
    //spi_dma_write((uint32_t*)spi_dma_buff,spi_datalen*2,DMA_DATA_TYPE_SHORT,spi_dma_write_result_callback);
    
    spi_param.write_complete_cb = spi_dma_write_result_callback;
    //spi_waitbusying();
    spi_write_dma_init((uint32_t*)spi_dma_buff,SPI_DMA_BUFF_LEN,DMA_DATA_TYPE_SHORT,dma_int_cb_1903);
    spi_send(RGB_DATA_LEN*4);

}
#endif
#endif
#endif


/// @} SPI DRIVER

