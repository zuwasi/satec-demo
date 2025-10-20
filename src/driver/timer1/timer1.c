/**
****************************************************************************************
*
* @file timer.c
*
* @brief timer initialization and specific functions
*
* Copyright (C) Beken 2019-2022
*
* $Rev: $
*
****************************************************************************************
*/

/**
****************************************************************************************
* @addtogroup TIME
* @ingroup TIME
* @brief TIME
*
* This is the driver block for TIME
* @{
****************************************************************************************
*/


#include <stddef.h>     // standard definition
#include "BK3437_RegList.h"
#include "timer1.h"
#include "reg_ipcore.h"
#include "icu.h"      // timer definition
#include "driver_gpio.h"
#include "uart1.h"

#if (TIMER1_DRIVER)
TMR1_DRV_DESC tmr1_env;

static void time1_env_init(void)
{
    static uint8_t init_flag = 0;
    if(init_flag == 0)
    {
        memset(&tmr1_env,sizeof(TMR1_DRV_DESC),0);
        init_flag = 1;
    }
}
void timer1_init(uint8_t clk_sel,uint8_t ch, uint8_t clk_div,uint8_t restart,uint32_t timer,void (*p_Int_Handler)(unsigned char ucChannel))//timer uints 1ms
{
    uart_printf("timer1_init[%d],%d \r\n",ch,timer);
    uint32_t timer_val;
        
    timer_val = timer * 16; // 1us
    
    if (ch >= TIMER1_NUMBER_MAX)
    {
        return;
    }
    if (clk_div > 0Xf)
    {
        return;
    }
    
    time1_env_init();
       
    clrf_SYS_Reg0x3_tim1_pwd;
    
    set_SYS_Reg0x4_tim1_sel(clk_sel);
    
    if(!(tmr1_env.init_en & 0x07))
    {
        set_TIMER1_Reg0x3_clk_div(clk_div); 
        tmr1_env.clk_div = clk_div;
    }
    timer_val =  timer_val /(tmr1_env.clk_div + 1); 
      
    tmr1_env.init_en |=(0x01 << ch);   
    tmr1_env.restart[ch] = restart;
    tmr1_env.p_Int_Handler[ch] = p_Int_Handler;
    tmr1_env.timer_set_val[ch] = timer_val;
    tmr1_env.init_en |= (0x01 << (ch + 3));
    switch(ch)
    {
        case 0:
        {
            addTIMER1_Reg0x0 = timer_val;
            setf_TIMER1_Reg0x3_timer0_en;
            
        }break;
        case 1:
        {
             addTIMER1_Reg0x1 = timer_val;
            setf_TIMER1_Reg0x3_timer1_en;
        }break;
        case 2:
        {
            addTIMER1_Reg0x2 = timer_val;
            setf_TIMER1_Reg0x3_timer2_en;
        }break;
        
        default:
            break;
    }
    setf_SYS_Reg0x10_int_timer1_en;  
}

void timer1_deinit(uint8_t ch)//timer uints 1ms
{
    uart_printf("timer1_deinit[%d] \r\n",ch);
   
    if (ch >= TIMER1_NUMBER_MAX)
    {
        return;
    }
    switch(ch)
    {
        case 0:
        {          
            clrf_TIMER1_Reg0x3_timer0_en;           
        }break;
        case 1:
        {      
            clrf_TIMER1_Reg0x3_timer1_en;
        }break;
        case 2:
        {
          
            clrf_TIMER1_Reg0x3_timer2_en;
        }break;
        
        default:
            break;
    }  
    tmr1_env.init_en &= ~(0x01 << ch);
    tmr1_env.init_en &= ~(0x01 << (ch + 3));
    
    if(!(tmr1_env.init_en & 0x07))
    {
        setf_SYS_Reg0x3_tim1_pwd;
        clrf_SYS_Reg0x10_int_timer1_en;  
    }
    
    tmr1_env.p_Int_Handler[ch] = NULL;  
    uart_printf("tmr1_env.init_en:%x\r\n",tmr1_env.init_en);
}


void timer1_set(uint8_t ch,uint8_t restart,uint32_t timer)
{
    uart_printf("timer1_set[%d],%d \r\n",ch,timer);
    if (ch >= TIMER1_NUMBER_MAX)
    {
        return;
    }
    if(!(tmr1_env.init_en & (0x01 << ch)))
    {
        uart_printf("tmr0_[%d] not init\r\n",ch);
        return;
    }
    uint32_t timer_val;
    timer_val = timer * 16;
    timer_val =  timer_val /(tmr1_env.clk_div + 1);  
    uart_printf("timer_val:%d\r\n",timer_val);
    tmr1_env.restart[ch] = restart;
     switch(ch)
    {
        case 0:
        {   
            clrf_TIMER1_Reg0x3_timer0_en; 
            addTIMER1_Reg0x0 = timer_val; 
            setf_TIMER1_Reg0x3_timer0_en;            
        }break;
        case 1:
        {      
            clrf_TIMER1_Reg0x3_timer1_en;
            addTIMER1_Reg0x1 = timer_val;
            setf_TIMER1_Reg0x3_timer1_en;
        }break;
        case 2:
        {
            clrf_TIMER1_Reg0x3_timer2_en;
            addTIMER1_Reg0x2 = timer_val;
            setf_TIMER1_Reg0x3_timer2_en;
        }break;
        
        default:
            break;
    }  

}

void timer1_en(uint8_t ch)
{
    addTIMER1_Reg0x3 &= (0x01 << ch);
}

void timer1_disen(uint8_t ch)
{
    addTIMER1_Reg0x3 &= (0x01 << ch);
}

void timer1_isr(void)
{
    int i;
    unsigned long ulIntStatus;

    ulIntStatus = (addTIMER1_Reg0x3 >> 7)& 0x7;
    for (i=0; i<TIMER1_NUMBER_MAX; i++)
    {
        if (ulIntStatus & (0x01<<i))
        {
            if (!tmr1_env.restart[i])
            {
                addTIMER1_Reg0x3 &= ~(0x01 << i);
            }

            if (tmr1_env.p_Int_Handler[i] != NULL)
            {
                (void)tmr1_env.p_Int_Handler[i]((unsigned char)i);
            }
        }
    }    
    addTIMER1_Reg0x3 |= (ulIntStatus >> 7);
 /*   do
    {
        addTIMER1_Reg0x3 |= (ulIntStatus >> 7);
    } while ((addTIMER1_Reg0x3 >> 7) & ulIntStatus & 0x7);   // delays*/
}

#define DEBUG_GPIO_TIMER1_0          (0x10)
#define DEBUG_GPIO_TIMER1_1          (0x11)
#define DEBUG_GPIO_TIMER1_2          (0x12)

void timer1_0_isr_demo_handler(unsigned char ucChannel)
{
 //   uart_printf("%s\r\n", __func__);   
    
    gpio_set_neg(0x20);
}

void timer1_1_isr_demo_handler(unsigned char ucChannel)
{
 //   uart_printf("%s\r\n", __func__);   
    
    gpio_set_neg(0x21);
}

void timer1_2_isr_demo_handler(unsigned char ucChannel)
{
  //  uart_printf("%s\r\n", __func__);   
    
    gpio_set_neg(0x22);
}

void timer1_test(uint8_t clk_sel)
{
    uart_printf("==============T1_TEST==============\r\n");
    uart_printf("==============T1.0->P0x20==============\r\n");
    uart_printf("==============T1.1->P0x21==============\r\n");
    uart_printf("==============T1.2->P0x22==============\r\n");
    uart_printf("==============clk = %d(0:32K,1:16M)==============\r\n",clk_sel);
    uart_printf("==============32K:2S/400ms/30ms==============\r\n");
    uart_printf("==============16M:1.1S/90ms/15ms==============\r\n");

    gpio_config(0x20, OUTPUT, PULL_HIGH);
    gpio_config(0x21, OUTPUT, PULL_HIGH);
    gpio_config(0x22, OUTPUT, PULL_HIGH);
    if(clk_sel)//16M
    {
        timer1_init(clk_sel,0, 0, 1, 1100000, timer1_0_isr_demo_handler);//units 1us,totoal 1100ms
        timer1_init(clk_sel,1, 0, 1, 90000, timer1_1_isr_demo_handler);//units 1us,totoal 90ms
        timer1_init(clk_sel,2, 0, 1, 15000, timer1_2_isr_demo_handler);//units 1us,totoal 15ms

    }
    else    //32K
    // inter is 16M init,so the count is 1ms
    {
        timer1_init(clk_sel,0, 0, 1, 2000*2, timer1_0_isr_demo_handler);//units 0.5ms,totoal 2000ms
        timer1_init(clk_sel,1, 0, 1, 400*2, timer1_1_isr_demo_handler);//units 0.5ms,totoal 400ms
        timer1_init(clk_sel,2, 0, 1, 30*2, timer1_2_isr_demo_handler);//units 0.5ms,totoal 30ms


    }
       
    clear_uart1_buffer();

    while(1)
    {
        if(uart1_rx_done)
        {
            timer1_disen(0);
            timer1_disen(1);
            timer1_disen(2);
            return;
        }
    }
}

#endif
