
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
#include "irda.h"       // uart definition
#include "uart1.h"
#include "driver_gpio.h"
#include "BK3437_RegList.h"
#include "user_config.h"
#include "icu.h"
#include "app_task.h"

#if(IRDA_DRIVER)
//uint16_t  send_para[]={500,200,100,400 ,200,400,200,100};
//{9020, 4410, 570, 1670 ,570, 1670, 570, 1670, 570,580 ,1670, 570, 1670 ,570 ,570, 580 ,570 ,1670, 570, 1670, 580 ,1650 ,580, 570 ,570, 570, 580 ,570 ,580, 1670, 570 ,1670 ,570, 570, 580, 10938};    
//uint16_t  send_para2[]={100,500, 200, 100, 400 ,400,200,400, 200, 100, 300 ,500,100,500, 200, 100};
//{9020, 4410, 570, 1670 ,570, 1670, 570, 1670, 570,580 ,1670, 570, 1670 ,570 ,580, 1670, 570 ,1670 ,570, 570, 580, 10938};
uint16_t  send_para3[]={9020, 4410, 570, 1670 ,570, 1670, 1670, 570,580 ,1670, 570, 1670 ,570 ,580, 1670, 570 ,1670 ,570, 570, 580, 10938};
//{200,400,200,100,300,500};
uint8_t rx_done_flag=1;
uint8_t tx_done_flag=1;
uint8_t irda_power_on=0;
/*********************************************************************
//mode: 0->master,1->slave
//SPI CLK = PLL clk/(freq_div*2)  
//bit_wdth: 0:8bit,1:16bit
**********************************************************************/
extern volatile uint32_t XVR_ANALOG_REG_BAK[32] ;

void tx_irda_intial(uint8_t clk,uint8_t duty,uint8_t period)
// 16,10,26
{
    //addAON_GPIO_Reg0x19 |= 0x40;//gpio func
    addIRDA_Reg0x0 = 0;
    addIRDA_Reg0x1 = 0;
    addIRDA_Reg0x3 = 0;
    addIRDA_Reg0x4 = 0;
    addIRDA_Reg0x5 = 0;
    addIRDA_Reg0x6 = 0;
    addIRDA_Reg0x7 = 0;
    
    clrf_SYS_Reg0x3_irda_pwd;
    setf_IRDA_Reg0x0_irda_pwr;
    
    set_IRDA_Reg0x0_clk_freq_in(clk);
    set_IRDA_Reg0x6_carrier_duty((duty));
    set_IRDA_Reg0x6_carrier_period(period);
    //set ir rx & tx power
    XVR_ANALOG_REG_BAK[0x3] &= ~(0x7f<<4);
    XVR_ANALOG_REG_BAK[0x3] |= (0<<9) |(1<<6)|(3<<4);
    addXVR_Reg0x3  = XVR_ANALOG_REG_BAK[0x3];    
    setf_IRDA_Reg0x6_carrier_enable;//
    //clrf_IRDA_Reg0x0_tx_initial_level;
    setf_IRDA_Reg0x0_txenable;
    setf_IRDA_Reg0x4_tx_done_mask;
    setf_IRDA_Reg0x4_rx_timeout_mask;
    setf_SYS_Reg0x10_int_irda_en ;  //enable irda_int
    
};


uint16_t  ir_data_buf[IRDA_BUFFER_COUNT];
uint16_t ir_cnt= 0;
void rx_irda_intial(uint8_t clk,uint16_t timeout,uint16_t thr,uint8_t glitch,uint8_t fifo_count)
    // 16, 8000,1000,41,20
{
    //addAON_GPIO_Reg0x19 |= 0x40;//gpio func
    //set ir rx & tx power

     XVR_ANALOG_REG_BAK[0x3] &= ~(0x7f<<4);
    XVR_ANALOG_REG_BAK[0x3] |= (0<<9) |(1<<6)|(3<<4);
    addXVR_Reg0x3  = XVR_ANALOG_REG_BAK[0x3];    

    set_IRDA_Reg0x0_clk_freq_in(clk);
    set_IRDA_Reg0x1_rx_timeout_cnt(timeout);   // uint : us
    set_IRDA_Reg0x6_rx_start_thr(thr); // uint: us
    setf_IRDA_Reg0x7_glitch_enable;//gltch
    set_IRDA_Reg0x7_glitch_enable(glitch);
    //clrf_IRDA_Reg0x0_rx_initial_level;
    set_IRDA_Reg0x1_RX_FIFO_THRESHOLD(fifo_count);
    setf_IRDA_Reg0x0_rx_initial_level;
    clrf_SYS_Reg0x3_irda_pwd;
    setf_IRDA_Reg0x0_irda_pwr;

    setf_IRDA_Reg0x0_rxenable;
    setf_IRDA_Reg0x4_tx_done_mask;//FOR THR TEST
    setf_IRDA_Reg0x4_rx_need_rd_mask;//FOR THR TEST
    setf_IRDA_Reg0x4_rx_timeout_mask;
    setf_SYS_Reg0x10_int_irda_en ;  //enable irda_int

//////////////// IR_RX debug ,P15,pullup 50K
#ifdef __IR_DEBUG__
// P07
    addAON_GPIO_Reg0x5 |= 0x40;//gpio func
    addAON_GPIO_Reg0x6 |= 0x40;//gpio func
    addAON_GPIO_Reg0x7 |= 0x40;//gpio func
    addSYS_Reg0x30= 0x44440000;
    set_SYS_Reg0xc_debug_set(0x8012);
// P17
    gpio_config(0x17,FLOAT,PULL_NONE);
    addPMU_Reg0x12 &= ~(1<<18);
    addPMU_Reg0x10 |= 1<<18;
    XVR_ANALOG_REG_BAK[0x3] |=1<<11;
    addXVR_Reg0x3  = XVR_ANALOG_REG_BAK[0x3];    
    XVR_ANALOG_REG_BAK[0x0c] &= ~(0x0f<<11);
    XVR_ANALOG_REG_BAK[0x0c] |= (4<<12)+(1<<19);
    addXVR_Reg0xc = XVR_ANALOG_REG_BAK[0x0c];
#endif
  //  uart_printf("gpio17=%x ..\r\n",addAON_GPIO_Reg0xf);
    ir_cnt =0;
/////////////// debug set end    
};
#define ir_38K  27
void start_tx_irda(void)
{
    clrf_IRDA_Reg0x0_tx_start;
    setf_IRDA_Reg0x0_tx_start;
};
void irda_power_down(void)
{
    setf_SYS_Reg0x3_irda_pwd;
    clrf_IRDA_Reg0x0_irda_pwr;
    tx_done_flag = 1;
    rx_done_flag = 1;
    irda_power_on=0;
}
void irda_init(void)
{
    gpio_config(0x02,FLOAT,PULL_NONE);
    gpio_config(0x04,FLOAT,PULL_NONE);
    gpio_config(0x20,FLOAT,PULL_NONE);
    irda_power_down();
}
//INrT
//uint8_t need_rd_flag=0;
uint16_t  ir_1_count=0;
uint8_t     rx_error=0;
void IRDA_ISR (void)
{
    unsigned long irda_int_status;
    uint16_t ir_tmp=0;
    uint8_t i;
    
    //unsigned char irda_fifo_rdata;


    irda_int_status = addIRDA_Reg0x5;
//    uart_printf("irda int now=%x ..\r\n",irda_int_status);
    if (irda_int_status & bitIRDA_Reg0x5_tx_done)
    {
        tx_done_flag = 1;
        //tx_times += 1;
        //uart_printf("irda tx done ..\r\n");
        set_sleep_mode(MCU_LOW_POWER_SLEEP);
        //irda_power_down();
    }


    if (irda_int_status & bitIRDA_Reg0x5_rx_need_rd_state)
    {
    //    uart_printf("fifo=%x ,%x..\r\n",get_IRDA_Reg0x2_RX_FIFO_EMPTY,get_IRDA_Reg0x2_rxdata_num);

        while (get_IRDA_Reg0x2_RX_FIFO_EMPTY==0)
        {   
            ir_tmp = get_IRDA_Reg0x3_fifo_data_rx;
            if(ir_tmp<20)
                {
                //gpio_set_neg(0x20);
                ir_1_count++;
                }
            else
            {
                if(ir_cnt >= IRDA_BUFFER_COUNT-2)
                {
                    ir_cnt = 0;
                    rx_error = 1;
                }
                ir_data_buf[ir_cnt++]=(ir_1_count>>1)*ir_38K;
                ir_data_buf[ir_cnt++]=ir_tmp;
                ir_1_count = 0;
            }        
        }
      
        setf_IRDA_Reg0x4_rx_need_rd_mask;
         //need_rd_flag=1;
    //    uart_printf("irda rx need rd now ..\r\n");
    }
    if (irda_int_status & bitIRDA_Reg0x5_rx_done_status)
    {
        while (get_IRDA_Reg0x2_RX_FIFO_EMPTY==0)
        {   
    //    uart_printf("fifo1=%x ,%x..\r\n",get_IRDA_Reg0x2_RX_FIFO_EMPTY,get_IRDA_Reg0x2_rxdata_num);
            ir_tmp = get_IRDA_Reg0x3_fifo_data_rx;
            if(ir_tmp<20)
            {
                //gpio_set_neg(0x20);
                ir_1_count++;
            }
            else
            {
                if(ir_cnt >= IRDA_BUFFER_COUNT-2)
                {
                    ir_cnt = 0;
                    rx_error = 1;
                }
                ir_data_buf[ir_cnt++]=(ir_1_count>>1)*ir_38K;
                ir_data_buf[ir_cnt++]=ir_tmp;
                ir_1_count = 0;
            }
          //  ir_data_buf[ir_cnt++]=get_IRDA_Reg0x3_fifo_data_rx;
        //    gpio_set_neg(0x20);
     //       Delay(1000);
        }
        // the last 4 data need read!!!!!!!!!!!!!!!!!!!!!
        for(i=0;i<4;i++)
            {
                ir_tmp = get_IRDA_Reg0x3_fifo_data_rx;
                if(ir_tmp<20)
                    {
                    //gpio_set_neg(0x20);
                    ir_1_count++;
                    }
                else
                {
                    if(ir_cnt >= IRDA_BUFFER_COUNT-2)
                    {
                        ir_cnt = 0;
                        rx_error = 1;
                    }
                    ir_data_buf[ir_cnt++]=(ir_1_count>>1)*ir_38K;
                    ir_data_buf[ir_cnt++]=ir_tmp;
                    ir_1_count = 0;
                }
      //        gpio_set_neg(0x20);
            }
        if(ir_cnt >= (IRDA_BUFFER_COUNT-1))
        {
              ir_cnt = 0;
              rx_error = 1;
        }
        if(ir_1_count)
        {    
            ir_data_buf[ir_cnt++]=(ir_1_count>>1)*ir_38K;
        }
        rx_done_flag = 1;
        ir_1_count = 0;
        //rx_times += 1;
        if(rx_error ==0)
        {
            ke_msg_send_basic(APP_IRDA_DATA_HANDLER,TASK_APP,TASK_APP);
        }else
        {
            ir_cnt = 0;
            rx_error=0;
        }
        
        
        //uart_printf("irda rx done ..\r\n");
    }
    addIRDA_Reg0x5 = irda_int_status;
}

void IRDA_TEST(uint8_t mode ) 
{

    uint16_t i;
    uint16_t tx_num;
    //uint16_t rx_data;
    //uint16_t irda_tx_data=0;


    uint16_t* p_send_para;
    uart_printf("==============IRDA_TEST ==============\r\n");
    uart_printf("==============P0_2 ==============\r\n");

    uart_printf("==============MODE:%2x ==============\r\n",mode);
    uart_printf("       0 : Tx     \r\n");
    uart_printf("       1 : Rx     \r\n");
    uart_printf("       CHG TO UART0     \r\n");
    uart0_init(1000000);
Delay_ms(10);
    //initial value or not
    gpio_config(0x02,FLOAT,PULL_NONE);
    gpio_config(0x20,OUTPUT,PULL_NONE);
#if 0
    setf_IRDA_Reg0x0_tx_initial_level;
    setf_IRDA_Reg0x0_rx_initial_level;
    setf_IRDA_Reg0x6_carrier_polarity;
#else
    clrf_IRDA_Reg0x0_tx_initial_level;
    clrf_IRDA_Reg0x0_rx_initial_level;
    clrf_IRDA_Reg0x6_carrier_polarity;
#endif

    //erro_flag=0;
    if(mode == 0) 
    {

        if(tx_done_flag==0)
        {
            return;
        }
        tx_irda_intial(16,10,26);
        uart_printf("Test irda tx ..\r\n");
        
            tx_num = sizeof(send_para3)/sizeof(uint16_t);
            p_send_para = send_para3;

            for (i=0; i<tx_num;i++)
            {
                set_IRDA_Reg0x3_fifo_data_tx(p_send_para[i]);
            }
            set_IRDA_Reg0x0_txdata_num(tx_num);
            //enable tx
            start_tx_irda();
            tx_done_flag=0;
    }
    else if(mode == 1) 
    {
        rx_irda_intial(16,8000,5,2,64);
        uart_printf("Test irda rx ..\r\n");
        rx_done_flag = 0;
        while(1)
        {

            while(rx_done_flag==0)
            {
                Delay_us(20000);
           //     uart_printf(" irda rxing now..\r\n");

            }
            if(rx_done_flag)
            {
                uart_printf("irda data id ..\r\n");
                for(i=0;i<ir_cnt;i++)
                {
                    uart_printf("%4d\r\n",ir_data_buf[i]);
                    
                    
                }
                uart_printf("\r\n====================\r\n");
                ir_cnt =0;
                rx_done_flag = 0;
                break;

            }

        }

    }
}
void irda_send(uint16_t *databuffer,uint8_t bufferlen)
{
    if(tx_done_flag == 0)
    {
        return;//busying
    }
    gpio_config(0x02,FLOAT,PULL_NONE);
    //gpio_config(0x20,OUTPUT,PULL_NONE);
    clrf_IRDA_Reg0x0_tx_initial_level;
    clrf_IRDA_Reg0x0_rx_initial_level;
    clrf_IRDA_Reg0x6_carrier_polarity;
    tx_irda_intial(16,10,26);
    
    uart_printf("send len:%d\r\n",bufferlen);
    for (uint8_t i=0; i<bufferlen;i++)
    {
        set_IRDA_Reg0x3_fifo_data_tx(databuffer[i]);
     }
     set_IRDA_Reg0x0_txdata_num(bufferlen);
            //enable tx
     start_tx_irda();
     tx_done_flag = 0;
     irda_power_on=1;  
}
void irda_receive(void)
{
    if(rx_done_flag == 0)
    {
        return;//busying
    }
    gpio_config(0x02,FLOAT,PULL_NONE);
   // gpio_config(0x20,OUTPUT,PULL_NONE);
#if 0
    setf_IRDA_Reg0x0_tx_initial_level;
    setf_IRDA_Reg0x0_rx_initial_level;
    setf_IRDA_Reg0x6_carrier_polarity;
#else
    clrf_IRDA_Reg0x0_tx_initial_level;
    clrf_IRDA_Reg0x0_rx_initial_level;
    clrf_IRDA_Reg0x6_carrier_polarity;
#endif
    rx_irda_intial(16,8000,5,2,120);
    rx_done_flag = 0;
    irda_power_on=1;
}

#endif

/// @} SPI DRIVER

