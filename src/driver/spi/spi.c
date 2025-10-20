
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

spi_param_t spi_param; 

#if(SPI_DRIVER)
unsigned char    *p_spi_txdata;
unsigned char    *p_spi_rxdata;

spi_read_cb read_cb_test(void);
/*********************************************************************
//mode: 0->master,1->slave
//SPI CLK = PLL clk/(freq_div*2)  
//bit_wdth: 0:8bit,1:16bit
**********************************************************************/
void spi_init(uint8_t mode,uint8_t freq_div,uint8_t bit_wdth,uint8_t gpio_sel)
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


    if(mode == SPI_MASTER)   //master
    {
        SPI_REG0X0_CFG |= ( 0x01UL << POS_SPI_REG0X0_MSTEN);
    }
    else        //slave
    {
        SPI_REG0X0_CFG &= ~( 0x01UL << POS_SPI_REG0X0_MSTEN);
        SPI_REG0X0_CFG |= ( 0x01UL << POS_SPI_REG0X0_SLV_RELEASE_INTEN);
    }
        
    SYS_REG0X4_CLK_SEL &= ~(1<<POS_SYS_REG0X4_SPICLK_SEL);////PLL CLK
    
    spi_param.spi_state=1;
    spi_param.write_complete_cb=NULL;
    spi_param.read_complete_cb=NULL;
    
}    

void spi_uninit(uint8_t gpio_sel)
{
    // SPI clock enable
    SET_SPI_POWER_DOWN;
    SYS_REG0X10_INT_EN &= ~(0x01 << POS_SYS_REG0X10_INT_EN_SPI);
    if(gpio_sel==0)
    {
        // Enable GPIO P04, P05, P06, P07 peripheral function for spi
        gpio_config(0x04,OUTPUT,PULL_NONE);
        gpio_config(0x05,OUTPUT,PULL_NONE);
        gpio_config(0x06,OUTPUT,PULL_NONE);
        gpio_config(0x07,OUTPUT,PULL_NONE);
    }
    else
    {
        // Enable GPIO P1.5, P1.6, P1.7, P2.0 peripheral function for spi
        gpio_config(0x15,OUTPUT,PULL_NONE);
        gpio_config(0x16,OUTPUT,PULL_NONE);
        gpio_config(0x17,OUTPUT,PULL_NONE);
        gpio_config(0x20,OUTPUT,PULL_NONE);
    }
    SPI_REG0X0_CFG = 0;
    SPI_REG0X1_CN = 0;
}

void spi_read_flash_uid(uint8_t *wbuf, uint32_t w_size, uint8_t *rbuf, uint32_t r_size)
{
    uint32_t max_len;
        
    max_len = (w_size > r_size ) ? w_size : r_size;
    
    if(max_len>64)
        return;
    
    //spi_waitbusying();
    
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_TX_FINISH_INT);
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_RX_FINISH_INT);
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);
    
    SPI_REG0X1_CN = (max_len<<POS_SPI_REG0X1_RX_TRANS_LEN)|(max_len<<POS_SPI_REG0X1_TX_TRANS_LEN);

    while((SPI_REG0X2_STAT &(1<<POS_SPI_REG0X2_TXFIFO_WR_READY))==0);
    
    while(max_len--)
    {
        if(w_size > 0)
        {
            SPI_REG0X3_DAT=*wbuf;
            wbuf++;
            w_size--;
        }
        else
            SPI_REG0X3_DAT=0;

    }
    
    SPI_REG0X1_CN |= (1<<POS_SPI_REG0X1_TX_EN)
                    |(1<<POS_SPI_REG0X1_RX_EN)
                    |(1<<POS_SPI_REG0X1_TX_FINISH_INT_EN)
                    |(1<<POS_SPI_REG0X1_RX_FINISH_INT_EN);
     
    if(r_size>0)
    {
        //while(0==(spi_send_state_get()));
        while((SPI_REG0X2_STAT&(1<<POS_SPI_REG0X2_RX_FINISH_INT))==0);
        while(r_size--)
        {
            *rbuf = (SPI_REG0X3_DAT & 0xff);
            rbuf++;
        }
    }   
}

void spi_write_read(uint8_t *wbuf, uint32_t w_size, uint8_t *rbuf, uint32_t r_size)
{
    uint32_t max_len;
        
    max_len = (w_size > r_size ) ? w_size : r_size;
    
    if(max_len>64)
        return;
    
    spi_waitbusying();
    
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_TX_FINISH_INT);
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_RX_FINISH_INT);
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);
    
    SPI_REG0X1_CN = (max_len<<POS_SPI_REG0X1_RX_TRANS_LEN)|(max_len<<POS_SPI_REG0X1_TX_TRANS_LEN);

    while((SPI_REG0X2_STAT &(1<<POS_SPI_REG0X2_TXFIFO_WR_READY))==0);
    
    while(max_len--)
    {
        if(w_size > 0)
        {
            SPI_REG0X3_DAT=*wbuf;
            wbuf++;
            w_size--;
        }
        else
            SPI_REG0X3_DAT=0;

    }
    
    SPI_REG0X1_CN |= (1<<POS_SPI_REG0X1_TX_EN)
                    |(1<<POS_SPI_REG0X1_RX_EN)
                    |(1<<POS_SPI_REG0X1_TX_FINISH_INT_EN)
                    |(1<<POS_SPI_REG0X1_RX_FINISH_INT_EN);
                    
    if(r_size>0)
    {
        while(0==(spi_send_state_get()));
        
        while(r_size)
        {
            if( SPI_REG0X2_STAT & (1<<POS_SPI_REG0X2_RXFIFO_RD_READY) ) // because spi_rx need more time to get buf at the first time.
            {
                *rbuf = (SPI_REG0X3_DAT & 0xff);
                rbuf++;
                r_size--;
            }
        }
    }   
}

void spi_write(uint8_t *wbuf, uint32_t w_size)
{
    if(w_size <= 0)
    {
        return;    
    }
    if(w_size > 64)
    {
        w_size = 64;
    }
    spi_waitbusying();
    
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_TX_FINISH_INT);
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);  
    
    SPI_REG0X1_CN = (w_size<<POS_SPI_REG0X1_TX_TRANS_LEN);

    while((SPI_REG0X2_STAT &(1<<POS_SPI_REG0X2_TXFIFO_WR_READY))==0);
    
    while(w_size)
    {
        SPI_REG0X3_DAT=*wbuf;
        wbuf++;
        w_size--;

    }
    
    SPI_REG0X1_CN |= (1<<POS_SPI_REG0X1_TX_EN) |(1<<POS_SPI_REG0X1_TX_FINISH_INT_EN); 
}

void spi_read( uint8_t *rbuf, uint32_t r_size)
{
    uint16_t tempdata;

    if(r_size <= 0)
    {
        return;
    }
    if(r_size > 4095)
    {
        uart_printf("r_size over \r\n");    
        r_size = 4095;
    }
    spi_waitbusying();
    
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_TX_FINISH_INT);
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);

    while(SPI_REG0X2_STAT&0x4)
    {
        tempdata = SPI_REG0X3_DAT;
        uart_printf("clear rx fifo \r\n");    
    }
    
    SPI_REG0X1_CN = (r_size<<POS_SPI_REG0X1_RX_TRANS_LEN)|(1<<POS_SPI_REG0X1_RX_EN)|(1<<POS_SPI_REG0X1_RX_FINISH_INT_EN);  //开始接收

    tempdata=0;
    
    while(1)
    {
        if(SPI_REG0X2_STAT&0x4)  //fifo 有数据
        {
            *rbuf = (SPI_REG0X3_DAT & 0xff);
            r_size--;
            if(r_size == 0)
            {
                break;
            }
            rbuf++;
        }
        else
        {
            tempdata++;
            if(tempdata>30000)
            {
                uart_printf("rx error:r_size=%d\r\n",r_size);    
                break;
            }
        }
    }    
}


void spi_send(uint16_t w_size)
{
    if(w_size>0xfff)
        w_size=0;
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_TX_FINISH_INT);
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);

    SPI_REG0X1_CN = (w_size<<POS_SPI_REG0X1_TX_TRANS_LEN);
    SPI_REG0X1_CN |= (1<<POS_SPI_REG0X1_TX_EN)
                        |(0<<POS_SPI_REG0X1_RX_EN)
                        |(1<<POS_SPI_REG0X1_TX_FINISH_INT_EN)
                        |(0<<POS_SPI_REG0X1_RX_FINISH_INT_EN);

}
void spi_stop(void)
{
    SPI_REG0X1_CN |= (0<<POS_SPI_REG0X1_TX_EN)
                        |(0<<POS_SPI_REG0X1_RX_EN)
                        |(0<<POS_SPI_REG0X1_TX_FINISH_INT_EN)
                        |(0<<POS_SPI_REG0X1_RX_FINISH_INT_EN);

}
void spi_receiv(uint16_t r_size)
{
    if(r_size>0xfff)
        r_size=0;
    SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_TX_FINISH_INT);
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);
    
    SPI_REG0X1_CN = (r_size<<POS_SPI_REG0X1_RX_TRANS_LEN);
    SPI_REG0X1_CN |= (0<<POS_SPI_REG0X1_TX_EN)
                        |(1<<POS_SPI_REG0X1_RX_EN)
                        |(0<<POS_SPI_REG0X1_TX_FINISH_INT_EN)
                        |(1<<POS_SPI_REG0X1_RX_FINISH_INT_EN);


}

void spi_isr(void)
{
    SYS_REG0X10_INT_EN &= ~(0x01 << POS_SYS_REG0X10_INT_EN_SPI);
    spi_param.spi_state=1;

    uart_printf("SPI_REG0X2_STAT = %x\r\n", SPI_REG0X2_STAT);

    if(SPI_REG0X2_STAT&(1<<POS_SPI_REG0X2_TX_FINISH_INT))
    {
        
        SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_TX_FINISH_INT);
        
        if(spi_param.write_complete_cb!=NULL)
            spi_param.write_complete_cb();
    }
    if(SPI_REG0X2_STAT&(1<<POS_SPI_REG0X2_RX_FINISH_INT))
    {
        SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_RX_FINISH_INT);
        //if(spi_param.read_complete_cb!=NULL)
        //    spi_param.read_complete_cb();
        
    }
    if(SPI_REG0X2_STAT&(1<<POS_SPI_REG0X2_RXOVF))
    {
        SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_RXOVF);
    }
    if(SPI_REG0X2_STAT&(1<<POS_SPI_REG0X2_RXFIFO_INT))
    {
        SPI_REG0X2_STAT |= (1<<POS_SPI_REG0X2_RXFIFO_INT);
    }
    
}
void spi_waitbusying(void)
{
    while(spi_param.spi_state==0)
    {
       uart_printf("spi_waitbusying\n");
    }
    spi_param.spi_state=0;
}

uint8_t spi_send_state_get(void)
{
#if(SPI_DRIVER) 
    return spi_param.spi_state;
#else
    return 1;
#endif
}


/*************************************************************************
**函数名称:void spi_master_test(void)
**功能描述:直接调用，可进行做主测试,可以把mosi 与miso接到一起进行测试
*************************************************************************/
void spi_master_test(void)
{
    int i;
    uint8_t spi_wbuf[64];
    uint8_t spi_rbuf[64];
    static uint8_t debug_cnt=0;
    uart_printf("==============SPI_MASTER_TEST ==============\r\n");
    uart_printf("==============spi send 64Bytes,2M bitrate ==============\r\n");

    spi_init(SPI_MASTER,2,SPI_8BITS,1);
    //clear_uart1_buffer();
    while(1)
    {
        debug_cnt++;
        for(i=0;i<64;i++)
        {
            spi_wbuf[i]=i+debug_cnt;
            spi_rbuf[i]=0;
        }
        
        spi_write_read(&spi_wbuf[0],64,&spi_rbuf[0],64);
        
        uart_printf("spi_master_read:\r\n");
        for(i=0;i<64;i++)
        {
            uart_printf("%2x,",spi_rbuf[i]);
        }
        
        memset(spi_rbuf,0,64);
        Delay_ms(30);
        if(uart1_rx_done)
        {
            return;
        }
    }
    
}

#define SPI_SLAVE_BUFFER_SIZE 80
uint8_t spi_buf[SPI_SLAVE_BUFFER_SIZE],spi_rxbuf[SPI_SLAVE_BUFFER_SIZE];
uint8_t spi_slave_status = 0;


/*************************************************************************
below SPI Slave code
*************************************************************************/
void spi_slave_init(void)
//note:the first tx dta is :0x72 (8bites),0x7232(16bites)
{
    int i;

    addSYS_Reg0x30 &= ~(0x11110000);
    SET_SPI_POWER_UP;
    SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);

    // Enable GPIO P0.4, P0.5, P0.6, P0.7 peripheral function for spi
    gpio_config(0x04,SC_FUN,PULL_NONE);
    gpio_config(0x05,SC_FUN,PULL_NONE);
    gpio_config(0x06,SC_FUN,PULL_NONE);
    gpio_config(0x07,SC_FUN,PULL_NONE);
    
    SPI_REG0X0_CFG = 0;
    SPI_REG0X0_CFG =  (0x02UL << POS_SPI_REG0X0_BYTE_INTLVAL)
                    | (0x00UL << POS_SPI_REG0X0_SPIEN)
                    | (0x00UL << POS_SPI_REG0X0_MSTEN)           //master mode //set slave mode
                    | (CKPHA_CLK1 << POS_SPI_REG0X0_CKPHA)
                    | (CKPOL_L << POS_SPI_REG0X0_CKPOL)
                    | (0x00UL << POS_SPI_REG0X0_LSB_FIRST)
                    | (SPI_CHARFORMAT_8BIT << POS_SPI_REG0X0_BIT_WDTH)
                    | (0x00UL << POS_SPI_REG0X0_WIRE3_EN)
                    | (0x01UL << POS_SPI_REG0X0_SLV_RELEASE_INTEN)
                    | (0xc8 << POS_SPI_REG0X0_SPI_CKR)  //clk div
                    | (0x01UL << POS_SPI_REG0X0_RXFIFO_INT_EN)  // enable rxint
                    | (0x00UL << POS_SPI_REG0X0_TXFIFO_INT_EN)
                    | (0x00UL << POS_SPI_REG0X0_RXOVF_EN)
                    | (0x00UL << POS_SPI_REG0X0_TXUDF_EN)
                    | (0x01UL << POS_SPI_REG0X0_RXFIFO_INT_LEVEL)  //rx
                    | (0x01UL << POS_SPI_REG0X0_TXFIFO_INT_LEVEL);
    
    SPI_REG0X1_CN =  (1 << POS_SPI_REG0X1_TX_EN)
                    |(1 << POS_SPI_REG0X1_RX_EN)
                    |(1 << POS_SPI_REG0X1_TX_FINISH_INT_EN)
                    |(1 << POS_SPI_REG0X1_RX_FINISH_INT_EN)
                    |(64 << POS_SPI_REG0X1_TX_TRANS_LEN)
                    |(64 << POS_SPI_REG0X1_RX_TRANS_LEN);


    //SYS_REG0X4_CLK_SEL |= (1<<POS_SYS_REG0X4_SPICLK_SEL);////PLL 96M CLK
    SPI_REG0X0_CFG |= (0x01UL << POS_SPI_REG0X0_SPIEN);

      SPI_REG0X2_STAT |= (0x03UL << POS_SPI_REG0X2_TXFIFO_CLR);
    
    for(i = 0;i < 63; i++)
    {
        SPI_REG0X3_DAT = *p_spi_txdata;
        p_spi_txdata ++;
    }

    uart_printf("SPI_CTRL 1 slave = %x,%x,%x\r\n",SPI_REG0X0_CFG,SPI_REG0X1_CN,SPI_REG0X2_STAT);

}

void spi_slave_start(void)
{
    SPI_REG0X0_CFG |= 0x20;  //open rxint_en
}

void spi_slave_stop()
{
    SPI_REG0X0_CFG = 0;
    setf_SYS_Reg0x3_spi_pwd;
    SYS_REG0X10_INT_EN &= ~(0x01 << POS_SYS_REG0X10_INT_EN_SPI);

    //REG_AHB0_ICU_SPICLKCON    = 0x1 ;                     //SPI clock enable
    //    REG_AHB0_ICU_INT_ENABLE  &= ~INT_STATUS_SPI_bit;      //IRQ UART interrupt enable
    SPI_REG0X2_STAT = 0;
}

unsigned char spi_slave_rx_len=0;;


//after cs high，init REG_APB2_SPI_DAT(10byte)
void spi_slave_done_data(void)
{
    int i;
    if( spi_slave_status == 1) //cs inactinve
    {
        uart_printf("slave spi len=%x:\r\n",spi_slave_rx_len);
        for(i=0;i<spi_slave_rx_len;i++)
        {
            uart_printf("%x,",spi_rxbuf[i]);
        }
        uart_printf("\r\n");
        SPI_REG0X1_CN = 0;
        
        #if 1
        if(spi_slave_rx_len!=0)
            {
            for(i = 0;i < 63; i++)
            {
                spi_buf[i]++;
                SPI_REG0X3_DAT = spi_buf[i];
            }
        }
        spi_slave_rx_len = 0;
        p_spi_txdata =spi_buf;
           p_spi_rxdata = spi_rxbuf;
        #endif
        // restar spi rx
        SPI_REG0X1_CN =  (1 << POS_SPI_REG0X1_TX_EN)
                    |(1 << POS_SPI_REG0X1_RX_EN)
                    |(1 << POS_SPI_REG0X1_TX_FINISH_INT_EN)
                    |(1 << POS_SPI_REG0X1_RX_FINISH_INT_EN)
                    |(64 << POS_SPI_REG0X1_TX_TRANS_LEN)
                    |(64 << POS_SPI_REG0X1_RX_TRANS_LEN);
        spi_slave_status = 0;
     //   uart_printf("SPI_CTRL 2 slave = %x,%x,%x\r\n",SPI_REG0X0_CFG,SPI_REG0X1_CN,SPI_REG0X2_STAT);

    }
}

void spi_slave_isr(void)
{
    unsigned int            rxint,rxint1;
    //unsigned char           rxfifo_en = 0;

    rxint = SPI_REG0X2_STAT & 0x0600;
    gpio_set_neg(0x20);
    if(rxint)
    {   
        
        while(get_SPI0_Reg0x2_RXFIFO_RD_READY)
        {
        gpio_set_neg(0x21);
            *p_spi_rxdata = SPI_REG0X3_DAT;
            ///uart_printf("%d\r\n",SPI_REG0X3_DAT);
            p_spi_rxdata ++;
            spi_slave_rx_len++;
            //break;
        }
        rxint1 = SPI_REG0X2_STAT & 0x0600;
        if(rxint1&0x400)
        {
        gpio_set_neg(0x22);
            spi_slave_status=1;
        }


        SPI_REG0X2_STAT |= rxint|rxint1; //clear rxint
    }
}

/*************************************************************************
**函数名称:void spi_slave_test(void)
**功能描述:直接调用，可进行做从测试
*************************************************************************/
void spi_slave_test(void)
{
    /****************************************************
    **SPI slave test
    ****************************************************/
    int i;
    uart_printf("==============SPI_SLAVE_TEST ==============\r\n");
    uart_printf("==============the first of miso data is 0x72  ==============\r\n");
    //clear_uart1_buffer();
    for(i=0;i<80;i++)
    {
        spi_buf[i]=i+0x51;//+0x56;
        spi_rxbuf[i]=i+0x20;//0x78;
    }
    
    p_spi_txdata =spi_buf;
    p_spi_rxdata = spi_rxbuf;
    gpio_config(0x20, OUTPUT, PULL_HIGH);
    gpio_config(0x21, OUTPUT, PULL_HIGH);
    gpio_config(0x22, OUTPUT, PULL_HIGH);
    spi_slave_init();
    //clear_uart1_buffer();
    //spi_init(1,2,0);

    //SYS_REG0X10_INT_EN |= (0x01 << POS_SYS_REG0X10_INT_EN_SPI);

    //spi_slave_start();
    while(1)
    {
        spi_slave_done_data();
        if(uart1_rx_done)
        {
            return;
        }
    }
}
extern uint8_t uart_rx_done ;

void spi_gd25q32_test(void)
{
    uart_printf("==============SPI_GD25Q32_TEST ==============\r\n");
    //int i;
    uint8_t spi_wbuf[64];
    uint8_t spi_rbuf[64];
    //static uint8_t debug_cnt=0;
    uart_printf("==============SPI_MASTER_TEST ==============\r\n");
    uart_printf("==============spi send 64Bytes,2M bitrate ==============\r\n");
    //clear_uart1_buffer();
 //   mcu_clk_switch(MCU_CLK_48M);
    spi_init(SPI_MASTER,0,SPI_8BITS,1);

    // read flash ID
    spi_wbuf[0] = 0x9f;
    spi_wbuf[1] = 0;
    spi_wbuf[2] = 0;
    spi_wbuf[3] = 0;
    while(1)
    {
        spi_write_read(&spi_wbuf[0],4,&spi_rbuf[0],4);
        uart_printf("flash ID = %x,%x,%x,%x\r\n",spi_rbuf[0],spi_rbuf[1],spi_rbuf[2],spi_rbuf[3]);
        Delay_ms(100);
        if(uart1_rx_done)
        {
            return;
        }
    }

   


}



#endif

/// @} SPI DRIVER

