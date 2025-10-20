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
#include "timer0.h"
#include "reg_ipcore.h"
#include "icu.h"      // timer definition
#include "driver_gpio.h"
#include "driver_flash.h"
#include "uart1.h"
#include "wdt.h"
#include "adc.h"

#if (TIMER0_DRIVER)
TMR_DRV_DESC tmr0_env;

static void time0_env_init(void)
{
    static uint8_t init_flag = 0;
    if(init_flag == 0)
    {
        memset(&tmr0_env,sizeof(TMR_DRV_DESC),0);
        init_flag = 1;
    }
}
void timer0_init(uint8_t clk_sel,uint8_t ch, uint8_t clk_div,uint8_t restart,uint32_t timer,void (*p_Int_Handler)(void))//timer uints 1ms
{
    uart_printf("timer0_init[%d],%d \r\n",ch,timer);
    uint32_t timer_val;
        
    timer_val = timer * 16; // 1ms
    
    if (ch >= TIMER_NUMBER_MAX)
    {
        return;
    }
    if (clk_div > 0Xf)
    {
        return;
    }
    
    time0_env_init();
       
    clrf_SYS_Reg0x3_tim0_pwd;
    
    set_SYS_Reg0x4_tim0_sel(clk_sel);
    
    if(!(tmr0_env.init_en & 0x07))
    {
        set_TIMER0_Reg0x3_clk_div(clk_div); 
        tmr0_env.clk_div = clk_div;
    }
    timer_val =  timer_val /(tmr0_env.clk_div + 1); 
      
    tmr0_env.init_en |=(0x01 << ch);   
    tmr0_env.restart[ch] = restart;
    tmr0_env.p_Int_Handler[ch] = p_Int_Handler;
    tmr0_env.timer_set_val[ch] = timer_val;
    tmr0_env.init_en |= (0x01 << (ch + 3));
    switch(ch)
    {
        case 0:
        {
            addTIMER0_Reg0x0 = timer_val;
            setf_TIMER0_Reg0x3_timer0_en;
            
        }break;
        case 1:
        {
             addTIMER0_Reg0x1 = timer_val;
            setf_TIMER0_Reg0x3_timer1_en;
        }break;
        case 2:
        {
            addTIMER0_Reg0x2 = timer_val;
            setf_TIMER0_Reg0x3_timer2_en;
        }break;
        
        default:
            break;
    }
    setf_SYS_Reg0x10_int_timer0_en;  
}

void timer0_deinit(uint8_t ch)//timer uints 1ms
{
    uart_printf("timer0_deinit[%d] \r\n",ch);
   
    if (ch >= TIMER_NUMBER_MAX)
    {
        return;
    }
    switch(ch)
    {
        case 0:
        {          
            clrf_TIMER0_Reg0x3_timer0_en;           
        }break;
        case 1:
        {      
            clrf_TIMER0_Reg0x3_timer1_en;
        }break;
        case 2:
        {
          
            clrf_TIMER0_Reg0x3_timer2_en;
        }break;
        
        default:
            break;
    }  
    tmr0_env.init_en &= ~(0x01 << ch);
    tmr0_env.init_en &= ~(0x01 << (ch + 3));
    if(!(tmr0_env.init_en & 0x07))
    {
        setf_SYS_Reg0x3_tim0_pwd;
        clrf_SYS_Reg0x10_int_timer0_en;  
    }
    tmr0_env.p_Int_Handler[ch] = NULL;  
    uart_printf("tmr0_env.init_en:%x\r\n",tmr0_env.init_en);
}


void timer0_set(uint8_t ch,uint8_t restart,uint32_t timer)
{
    uart_printf("timer0_set[%d],%d \r\n",ch,timer);
    if (ch >= TIMER_NUMBER_MAX)
    {
        return;
    }
    if(!(tmr0_env.init_en & (0x01 << ch)))
    {
        uart_printf("tmr0_[%d] not init\r\n",ch);
        return;
    }
    uint32_t timer_val;
    timer_val = timer * 16;
    timer_val =  timer_val /(tmr0_env.clk_div + 1);  
    uart_printf("timer_val:%d\r\n",timer_val);
    tmr0_env.restart[ch] = restart;
     switch(ch)
    {
        case 0:
        {   
            clrf_TIMER0_Reg0x3_timer0_en; 
            addTIMER0_Reg0x0 = timer_val; 
            setf_TIMER0_Reg0x3_timer0_en;            
        }break;
        case 1:
        {      
            clrf_TIMER0_Reg0x3_timer1_en;
            addTIMER0_Reg0x1 = timer_val;
            setf_TIMER0_Reg0x3_timer1_en;
        }break;
        case 2:
        {
            clrf_TIMER0_Reg0x3_timer2_en;
            addTIMER0_Reg0x2 = timer_val;
            setf_TIMER0_Reg0x3_timer2_en;
        }break;
        
        default:
            break;
    }  

}

void timer0_en(uint8_t ch)
{
    addTIMER0_Reg0x3 &= (0x01 << ch);
}

void timer0_disen(uint8_t ch)
{
    addTIMER0_Reg0x3 &= (0x01 << ch);
}

void timer0_isr(void)
{
    int i;
    unsigned long ulIntStatus;

    ulIntStatus = (addTIMER0_Reg0x3 >> 7)& 0x7;;
   // uart_printf("ulIntStatus:0x%x\r\n",ulIntStatus);
    for (i=0; i<TIMER_NUMBER_MAX; i++)
    {
        if (ulIntStatus & (0x01<<i))
        {        
            if (!tmr0_env.restart[i])
            {
                addTIMER0_Reg0x3 &= ~(0x01 << i);
            }
            
            if (tmr0_env.p_Int_Handler[i] != NULL)
            {
                (void)tmr0_env.p_Int_Handler[i]();
            }
        }
    }    
    addTIMER0_Reg0x3 |= (ulIntStatus >> 7);
 /*   do
    {
        addTIMER0_Reg0x3 |= (ulIntStatus >> 7);
    } while ((addTIMER0_Reg0x3 >> 7) & ulIntStatus & 0x7);   // delays*/
}

#define DEBUG_GPIO_TIMER0_0          (0x20)
#define DEBUG_GPIO_TIMER0_1          (0x21)
#define DEBUG_GPIO_TIMER0_2          (0x22)
/* For POR,when Flash is gatting */
void timer0_0_isr_wdt_handler(void)
{
    uint16_t check_cnt=0;
    while(!check_flash_ID())
    {
        check_cnt++;
        if(check_cnt>3)
        {
            wdt_enable(0x10);
            while(1);
        }
    }
}
#define VBAT_SAMPLE_NUM     4               // >= 4,such as 4,8,16 ...
#define GPIO_SAMPLE_NUM     VBAT_SAMPLE_NUM 
static int16_t s_vbat_volt[VBAT_SAMPLE_NUM];
static int16_t s_gpio_volt[VBAT_SAMPLE_NUM];

#define ADC_MIN(a,b) ((a) > (b) ? (b) : (a))
#define ADC_MAX(a,b) ((a) < (b) ? (b) : (a))


static int8_t s_adc_cnt = 0;
void timer0_0_isr_vbat(void)
{
    int16_t adc_volt,k,adc_sum = 0;
    int16_t adc_max = 0,adc_min = 0;
    adc_volt = get_vbat_data();
    s_vbat_volt[s_adc_cnt] = adc_volt;
    adc_max = adc_min = adc_volt;
    for(k = 0 ; k < VBAT_SAMPLE_NUM ; k++) {
        adc_max = ADC_MAX(adc_max,s_vbat_volt[k]);
        adc_min = ADC_MIN(adc_min,s_vbat_volt[k]);
        adc_sum += s_vbat_volt[k];
    }
    adc_sum -= (adc_max + adc_min);
    adc_sum /= (VBAT_SAMPLE_NUM-2);
    //uart_printf("Vbat(mv):%d\r\n",adc_sum);

    adc_sum = 0;
    adc_volt = get_gpio_chnl_data(ADC_CHL_5);
    s_gpio_volt[s_adc_cnt] = adc_volt;
    adc_max = adc_min = adc_volt;
    for(k = 0 ; k < VBAT_SAMPLE_NUM ; k++) {
        adc_max = ADC_MAX(adc_max,s_gpio_volt[k]);
        adc_min = ADC_MIN(adc_min,s_gpio_volt[k]);
        adc_sum += s_gpio_volt[k];
    }
    adc_sum -= (adc_max + adc_min);
    adc_sum /= (GPIO_SAMPLE_NUM-2);
    //uart_printf("GPIO(mv):%d\r\n",adc_sum);
    s_adc_cnt++;
    s_adc_cnt &= (VBAT_SAMPLE_NUM-1);
}
void timer0_0_isr_demo_handler(void)
{
  //  uart_printf("%s\r\n", __func__);   
    
    gpio_set_neg(DEBUG_GPIO_TIMER0_0);
}

void timer0_1_isr_demo_handler(void)
{
  //  uart_printf("%s\r\n", __func__);   
    
    gpio_set_neg(DEBUG_GPIO_TIMER0_1);
}

void timer0_2_isr_demo_handler(void)
{
  //  uart_printf("%s\r\n", __func__);   
    
    gpio_set_neg(DEBUG_GPIO_TIMER0_2);
}

void timer0_test(uint8_t clk_sel)
{
    uart_printf("==============T0_TEST==============\r\n");
    uart_printf("==============T0.0->P0x20==============\r\n");
    uart_printf("==============T0.1->P0x21==============\r\n");
    uart_printf("==============T0.2->P0x22==============\r\n");
    uart_printf("==============clk = %d(0:32K,1:16M)==============\r\n",clk_sel);
    uart_printf("==============32K:3S/200ms/70ms==============\r\n");
    uart_printf("==============16M:1S/100ms/10ms==============\r\n");

    gpio_config(0x20, OUTPUT, PULL_HIGH);
    gpio_config(0x21, OUTPUT, PULL_HIGH);
    gpio_config(0x22, OUTPUT, PULL_HIGH);
    if(clk_sel)//16M
    {
        timer0_init(clk_sel,0, 0, 1, 1000000, timer0_0_isr_demo_handler);//units 1us,totoal 1000ms
        timer0_init(clk_sel,1, 0, 1, 100000, timer0_1_isr_demo_handler);//units 1us,totoal 100ms
        timer0_init(clk_sel,2, 0, 1, 10000, timer0_2_isr_demo_handler);//units 1us,totoal 10ms

    }
    else    //32K
    // inter is 16M init,so the count is 1ms
    {
        timer0_init(clk_sel,0, 0, 1, 3000*2, timer0_0_isr_demo_handler);//units 0.5ms,totoal 3000ms
        timer0_init(clk_sel,1, 0, 1, 200*2, timer0_1_isr_demo_handler);//units 0.5ms,totoal 200ms
        timer0_init(clk_sel,2, 0, 1, 70*2, timer0_2_isr_demo_handler);//units 0.5ms,totoal 70ms


    }
   
}
#endif
