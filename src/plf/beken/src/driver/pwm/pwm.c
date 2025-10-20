/**
****************************************************************************************
*
* @file pwm.c
*
* @brief pwm initialization and specific functions
*
* Copyright (C) Beken 2019-2022
*
* $Rev: $
*
****************************************************************************************
*/

/**
****************************************************************************************
* @addtogroup PWM
* @ingroup PWM
* @brief PWM
*
* This is the driver block for PWM
* PWM0 control channel 0/2/4, and 1/3/5 output the same or complementary respectively
* PWM1 control channel 1/3/5
* @{
****************************************************************************************
*/
#include "user_config.h"

#if (PWM_DRIVER)
#include <stddef.h>     // standard definition
#include "uart1.h"
#include "driver_gpio.h"
#include "BK3437_RegList.h"
#include "pwm.h"

void (*p_PWM0_Int_Handler[PWM_CHANNEL_NUMBER_MAX])(unsigned char ucPWM_channel);
void (*p_PWM1_Int_Handler[PWM_CHANNEL_NUMBER_MAX])(unsigned char ucPWM_channel);

const uint8_t pwm_channel_io_map[] = {GPIO5, GPIO6, GPIO7, GPIO8, GPIO9, GPIO10};
/*
void pwm0_sys_ctrl(pwm_channel_t channel,uint8_t clk_en,uint8_t int_en,uint8_t diff_sel,uint8_t diff_polarity)
{
    uint8_t pwm_gpio = pwm_channel_io_map[channel];

    uart_printf("%s channel %x\r\n", __func__, channel);
    set_SYS_Reg0x4_pwm0_sel(1);
    gpio_config(pwm_gpio, SC_FUN, PULL_NONE);
    gpio_scfun_sel(pwm_gpio, 1);
     if(diff_sel)
    {
        gpio_config(pwm_channel_io_map[channel+1], SC_FUN, PULL_NONE);
        gpio_scfun_sel(pwm_channel_io_map[channel+1], 1);
        switch(channel)
        {
         case PWM_CHANNEL0:
            set_PWM_0_Reg0xa_CH2P(diff_polarity) ;
            break;
         case PWM_CHANNEL2:
            set_PWM_0_Reg0xa_CH4P(diff_polarity) ;
            break;
         case PWM_CHANNEL4:
            set_PWM_0_Reg0xa_CH6P(diff_polarity) ;
            break;
        }
            
    }
    clrf_SYS_Reg0x11_int_pwm0_pri;        //IRQ
    
    if(clk_en)
    {
        clrf_SYS_Reg0x3_pwm0_pwd;
    }
    else
    {
        setf_SYS_Reg0x3_pwm0_pwd;
    }
    
    if(int_en)
    {
        setf_SYS_Reg0x10_int_pwm0_en;
    }
    else
    {
        clrf_SYS_Reg0x10_int_pwm0_en;
    }
    
    clrf_SYS_Reg0xc_pwm_ctrl0 ; //1:set PWM 0,1  Simultaneously output
    clrf_SYS_Reg0xc_pwm_ctrl1 ; //1:set PWM 2,3  Simultaneously output
    clrf_SYS_Reg0xc_pwm_ctrl2 ; //1:set PWM 4,5  Simultaneously output
}

void pwm1_sys_ctrl(pwm_channel_t channel, uint8_t clk_en,uint8_t int_en)
{
    uint8_t pwm_gpio = pwm_channel_io_map[channel];

    gpio_config(pwm_gpio, SC_FUN, PULL_NONE);
    gpio_scfun_sel(pwm_gpio, 1);
    
    clrf_SYS_Reg0x11_int_pwm1_pri;        //IRQ
    set_SYS_Reg0x4_pwm1_sel(3);

    if(clk_en)
    {
        clrf_SYS_Reg0x3_pwm1_pwd;
    }
    else
    {
        setf_SYS_Reg0x3_pwm1_pwd;
    }
    
    if(int_en)
    {
        setf_SYS_Reg0x10_int_pwm1_en;
    }
    else
    {
        clrf_SYS_Reg0x10_int_pwm1_en;
    }

    setf_SYS_Reg0xc_pwm_ctrl0 ;
    setf_SYS_Reg0xc_pwm_ctrl1 ;
    setf_SYS_Reg0xc_pwm_ctrl2 ;
}
*/
static void pwm0_output_mode_config(uint8_t diff_sel,pwm_channel_t channel, int end_val, int psc, int cycle_val, int ddt)
{
   // uart_printf("%s, channel %x\r\n", __func__, channel);

    switch(channel)
    {
        case PWM_CHANNEL0:
            setf_PWM_0_Reg0x4_ARPE1 ;             //enable arr1 preload
            addPWM_0_Reg0xf = end_val ;                 //end value arr1 0x60
            set_PWM_0_Reg0xe_PSC1(psc) ;          //prescale is 5 
            addPWM_0_Reg0x15 = cycle_val ;             //ccr1 is 0x20
            set_PWM_0_Reg0xa_OC1M(0x3) ;             //toggle at ccr1 and arr1
         //   setf_PWM_0_Reg0x7_CC1IE ;             //enable ccr1 int
            setf_PWM_0_Reg0xa_CH1E ;              //enable pwm_o[0]
            if(diff_sel)
            {
#ifdef USE_PWM_DIFF							
							set_PWM_0_Reg0x9_DTM(1);
#endif							
                setf_PWM_0_Reg0xa_CH2E ;              //enable pwm_o[1]
                set_PWM_0_Reg0x1e_DT1(ddt) ;                 //set deadtime as 5 cycle
            }
            set_PWM_0_Reg0xa_CH1P(0x01) ;             //set pwm_o[1] as complementary of pwm_o[0] 
            setf_PWM_0_Reg0x9_UG1 ;                 //update ccr1 and arr1
#ifndef USE_PWM0            
            setf_PWM_0_Reg0x4_CEN1 ;                 //enable counter
#endif						
            break;
        case PWM_CHANNEL2:
            setf_PWM_0_Reg0x4_ARPE2 ;             //enable arr2 preload
            addPWM_0_Reg0x10 = end_val ;                 //end value arr2 0x60
            set_PWM_0_Reg0xe_PSC2(psc) ;          //prescale is 5 
            addPWM_0_Reg0x18 = cycle_val ;             //ccr4 is 0x20
            set_PWM_0_Reg0xa_OC2M(0x3) ;             //toggle at ccr1 and arr1
#if 1			
            setf_PWM_0_Reg0x7_CC4IE ;             //enable ccr4 int
						setf_PWM_0_Reg0x8_CC4IF ;
#endif				
            setf_PWM_0_Reg0xa_CH3E ;              //enable pwm_o[2]
            
            if(diff_sel)
            {
#ifdef USE_PWM_DIFF							
							set_PWM_2_Reg0x9_DTM(3);
#endif							
                setf_PWM_0_Reg0xa_CH4E ;              //enable pwm_o[3]
                set_PWM_0_Reg0x1e_DT2(ddt) ;                 //set deadtime as 5 cycle
            }
            set_PWM_0_Reg0xa_CH3P(0x01) ;             //set pwm_o[3] as complementary of pwm_o[4] 
#if 0						
            setf_PWM_0_Reg0x9_UG2 ;                 //update ccr4 and arr2        
#endif						
#ifndef USE_PWM_DIFF            
            setf_PWM_0_Reg0x4_CEN2 ;                 //enable counter
#else
						setf_PWM_0_Reg0x7_UIE2;
#endif						
            break;
        case PWM_CHANNEL4:
            setf_PWM_0_Reg0x4_ARPE3 ;             //enable arr3 preload
            addPWM_0_Reg0x11 = end_val ;             //end value arr3 0x60
            set_PWM_0_Reg0xe_PSC3(psc) ;          //prescale is 5 
            addPWM_0_Reg0x1b = cycle_val ;               //ccr4 is 0x20
            set_PWM_0_Reg0xa_OC3M(0x3) ;             //toggle at ccr4 and arr2
					//	setf_PWM_0_Reg0x7_CC7IE ;             //enable ccr1 int
            setf_PWM_0_Reg0xa_CH5E ;              //enable pwm_o[4]
         //   setf_PWM_0_Reg0x4_OC3PE;
            if(diff_sel)
            {
#ifdef USE_PWM_DIFF						
//#ifdef USE_GPIO_PWM							
								set_PWM_4_Reg0x9_DTM(3);
//#else
//								set_PWM_4_Reg0x9_DTM(1);
//#endif							
#endif							
                setf_PWM_0_Reg0xa_CH6E ;              //enable pwm_o[5]
                set_PWM_0_Reg0x1e_DT3(ddt) ;             //set deadtime as 5 cycle
            }
            set_PWM_0_Reg0xa_CH5P(0x01) ;             //set pwm_o[5] as complementary of pwm_o[4] 
            setf_PWM_0_Reg0x9_UG3 ;                 //update ccr7 and arr3
						setf_PWM_0_Reg0x8_UIF3;
#ifndef USE_PWM_DIFF               
            setf_PWM_0_Reg0x4_CEN3 ;                 //enable counter
#else
						setf_PWM_0_Reg0x7_UIE3;
#endif						
            break;
        default:
            uart_printf("pwm0 channel select error!!!\r\n");
            break;
    }
}

void pwm1_output_mode_config(pwm_channel_t channel, int end_val, int psc, int cycle_val, int ddt)
{
    //uart_printf("%s, channel %x\r\n", __func__, channel);
    switch(channel)
    {
        case PWM_CHANNEL1:
            setf_PWM_1_Reg0x4_ARPE1 ;             //enable arr1 preload
            addPWM_1_Reg0xf = end_val ;             //end value arr1 0x60
            set_PWM_1_Reg0xe_PSC1(psc) ;          //prescale is 5 
            addPWM_1_Reg0x15 = cycle_val ;             //ccr1 is 0x20
            set_PWM_1_Reg0xa_OC1M(0x3) ;             //toggle at ccr1 and arr1
         //   setf_PWM_1_Reg0x7_CC1IE ;             //enable ccr1 int
            setf_PWM_1_Reg0xa_CH2E ;              //enable pwm_o[1]
            set_PWM_1_Reg0xa_CH2P(0x01) ;             //set pwm2_o as complementary of PWM_1_o 
            setf_PWM_1_Reg0x9_UG1 ;                 //update ccr1 and arr1
            
            setf_PWM_1_Reg0x4_CEN1 ;                 //enable counter
            break;
        case PWM_CHANNEL3:
            setf_PWM_1_Reg0x4_ARPE2 ;             //enable arr1 preload
            addPWM_1_Reg0x10 = end_val ;                 //end value arr1 0x60
            set_PWM_1_Reg0xe_PSC2(psc) ;          //prescale is 5 
            addPWM_1_Reg0x18 = cycle_val ;             //ccr1 is 0x20
            set_PWM_1_Reg0xa_OC2M(0x3) ;             //toggle at ccr1 and arr1
#ifdef USE_GPIO_PWM				
            setf_PWM_1_Reg0x7_CC4IE ;             //enable ccr1 int
#endif				
            setf_PWM_1_Reg0xa_CH4E ;              //enable pwm_o[1]
            set_PWM_1_Reg0xa_CH4P(0x01) ;             //set pwm2_o as complementary of PWM_1_o 
            setf_PWM_1_Reg0x9_UG2 ;                 //update ccr1 and arr1
            setf_PWM_1_Reg0x7_UIE2;
        //    setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
            break;
   
        case PWM_CHANNEL5:
            setf_PWM_1_Reg0x4_ARPE3 ;             //enable arr1 preload
            addPWM_1_Reg0x11 = end_val ;                 //end value arr1 0x60
            set_PWM_1_Reg0xe_PSC3(psc) ;          //prescale is 5 
            addPWM_1_Reg0x1b = cycle_val ;             //ccr1 is 0x20
            set_PWM_1_Reg0xa_OC3M(0x3) ;             //toggle at ccr1 and arr1
#ifdef USE_GPIO_PWM				
            setf_PWM_1_Reg0x7_CC7IE ;             //enable ccr1 int
#endif				
            setf_PWM_1_Reg0xa_CH6E ;              //enable pwm_o[1]
            set_PWM_1_Reg0xa_CH6P(0x01) ;             //set pwm2_o as complementary of PWM_1_o 
            setf_PWM_1_Reg0x9_UG3 ;                 //update ccr1 and arr1        
            setf_PWM_1_Reg0x7_UIE3;
          //  setf_PWM_1_Reg0x4_CEN3 ;                 //enable counter
				
				uart_printf("addPWM_1_Reg0x4 %x\r\n", addPWM_1_Reg0x4);
				uart_printf("addPWM_1_Reg0x5 %x\r\n", addPWM_1_Reg0x5);
				uart_printf("addPWM_1_Reg0x6 %x\r\n", addPWM_1_Reg0x6);
				uart_printf("addPWM_1_Reg0x7 %x\r\n", addPWM_1_Reg0x7);
				uart_printf("addPWM_1_Reg0x8 %x\r\n", addPWM_1_Reg0x8);
				uart_printf("addPWM_1_Reg0xa %x\r\n", addPWM_1_Reg0xa);
//				uart1_printf("addPWM_1_Reg0xe %x\r\n", addPWM_1_Reg0xe);
//				uart1_printf("addPWM_1_Reg0x10 %x\r\n", addPWM_1_Reg0x10);
            break;
        default:
            uart_printf("pwm1 channel select error!!!\r\n");
            break;
    }

}

void pwm_output_mode_init(pwm_dev_sel_t dev_sel,uint8_t diff_sel    , pwm_channel_t channel, int end_val, int psc, int cycle_val, int ddt )
{
    switch(dev_sel)
    {
        case DEV_PWM0:     
            pwm0_output_mode_config(diff_sel,channel, end_val, psc, cycle_val, ddt);
            break;
        case DEV_PWM1:          
            pwm1_output_mode_config(channel, end_val, psc, cycle_val, ddt);
            break;    
        default:
            uart_printf("pwm device select error!\r\n");
            break;
    }
}

static void pwm0_cap_mode_config(pwm_channel_t channel, int psc)
{
    switch(channel)
    {
        case PWM_CHANNEL0:  //trigger constantly
            setf_PWM_0_Reg0x4_URS1 ;
            addPWM_0_Reg0xf = 0xffffffff ;         //end value arr1 0x60
            set_PWM_0_Reg0xe_PSC1(psc) ;          //prescale is 5 
            setf_PWM_0_Reg0x7_CC1IE ;             //enable ccr1 int
            setf_PWM_0_Reg0xa_CH1E ;              //enable pwm_o[0]
            setf_PWM_0_Reg0xa_TIM1CCM ;             //CAPTURE mode
            set_PWM_0_Reg0x6_SMS1(0x5)    ;             //clear timer every capture
            set_PWM_0_Reg0x6_TS1(0x0) ;        
            
            setf_PWM_0_Reg0x4_CEN1 ;                 //enable COUNTER
            break;
        case PWM_CHANNEL2:  //trigger 4 times
            setf_PWM_0_Reg0x4_URS2 ;
            addPWM_0_Reg0x10 = 0xffffffff ;         //end value arr1 0x60
            set_PWM_0_Reg0xe_PSC2(psc) ;          //prescale is 5 
            setf_PWM_0_Reg0x7_CC4IE ;             //enable ccr4 int
            setf_PWM_0_Reg0xa_CH3E ;              //enable pwm_o[2]
            setf_PWM_0_Reg0xa_TIM2CCM ;             //CAPTURE mode
            set_PWM_0_Reg0x6_SMS2(0x5)    ;         //clear timer every capture
            set_PWM_0_Reg0x6_TS2(0x0) ;        
            
            setf_PWM_0_Reg0x4_CEN2 ;                 //enable counter
            break;
        case PWM_CHANNEL4:  //trigger 1 time 
            setf_PWM_0_Reg0x4_URS3 ;
            addPWM_0_Reg0x11 = 0xffffffff ;         //end value arr1 0x60
            set_PWM_0_Reg0xe_PSC3(psc) ;          //prescale is 5 
            setf_PWM_0_Reg0x7_CC7IE ;             //enable ccr7 int
            setf_PWM_0_Reg0xa_CH5E ;              //enable pwm_o[4]
            setf_PWM_0_Reg0xa_TIM3CCM ;             //CAPTURE mode
            set_PWM_0_Reg0x6_SMS3(0x5)    ;             //clear timer every capture
            set_PWM_0_Reg0x6_TS3(0x0) ;    
            
            setf_PWM_0_Reg0x4_CEN3 ;                 //enable counter
            break;
    }
 /*   uart1_printf("addPWM_0_Reg0x4 %x\r\n", addPWM_0_Reg0x4);
    uart1_printf("addPWM_0_Reg0x6 %x\r\n", addPWM_0_Reg0x6);
    uart1_printf("addPWM_0_Reg0x7 %x\r\n", addPWM_0_Reg0x7);
    uart1_printf("addPWM_0_Reg0xa %x\r\n", addPWM_0_Reg0xa);
    uart1_printf("addPWM_0_Reg0xe %x\r\n", addPWM_0_Reg0xe);
    uart1_printf("addPWM_0_Reg0x10 %x\r\n", addPWM_0_Reg0x10);*/
}

static void pwm1_cap_mode_config(pwm_channel_t channel, int psc)
{
    switch(channel)
    {
        case PWM_CHANNEL1:
            setf_PWM_1_Reg0x4_URS1 ;
            addPWM_1_Reg0xf = 0xffffffff ;         //end value arr1 0x60
            set_PWM_1_Reg0xe_PSC1(psc) ;          //prescale is 5 
            setf_PWM_1_Reg0x7_CC2IE ;             //enable ccr1 int
            //setf_PWM_1_Reg0xa_CH1E ;              //enable pwm_o[0]
            setf_PWM_1_Reg0xa_CH2E ;              //enable pwm_o[1]
            setf_PWM_1_Reg0xa_TIM1CCM ;             //CAPTURE mode
            set_PWM_1_Reg0x6_SMS1(0x5)    ;             //clear timer every capture
            set_PWM_1_Reg0x6_TS1(0x1) ;
            
            setf_PWM_1_Reg0x4_CEN1 ;                 //enable counter
            break;
        case PWM_CHANNEL3:
            setf_PWM_1_Reg0x4_URS2 ;
            addPWM_1_Reg0x10 = 0xffffffff ;         //end value arr1 0x60
            set_PWM_1_Reg0xe_PSC2(psc) ;          //prescale is 5 
            setf_PWM_1_Reg0x7_CC5IE ;             //enable ccr1 int
            //setf_PWM_1_Reg0xa_CH1E ;              //enable pwm_o[0]
            setf_PWM_1_Reg0xa_CH4E ;              //enable pwm_o[1]
            setf_PWM_1_Reg0xa_TIM2CCM ;             //CAPTURE mode
            set_PWM_1_Reg0x6_SMS2(0x5)    ;             //clear timer every capture
            set_PWM_1_Reg0x6_TS2(0x1) ;
            
            setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
            break;
        case PWM_CHANNEL5:
            setf_PWM_1_Reg0x4_URS3 ;
            addPWM_1_Reg0x11 = 0xffffffff ;         //end value arr1 0x60
            set_PWM_1_Reg0xe_PSC3(psc) ;          //prescale is 5 
            setf_PWM_1_Reg0x7_CC8IE ;             //enable ccr1 int
            //setf_PWM_1_Reg0xa_CH1E ;              //enable pwm_o[0]
            setf_PWM_1_Reg0xa_CH6E ;              //enable pwm_o[1]
            setf_PWM_1_Reg0xa_TIM3CCM ;             //CAPTURE mode
            set_PWM_1_Reg0x6_SMS3(0x5)    ;             //clear timer every capture
            set_PWM_1_Reg0x6_TS3(0x1) ;
            
            setf_PWM_1_Reg0x4_CEN3 ;                 //enable counter
            break;
    }
}


void pwm_cap_mode_init(int dev_sel, pwm_channel_t channel, int psc)
{
    switch(dev_sel)
    {
        case DEV_PWM0:     
            pwm0_cap_mode_config(channel, psc);
            break;    
        case DEV_PWM1:     
            pwm1_cap_mode_config(channel, psc);
            break;    
        default: 
            uart_printf("pwm sel erro!\r\n");
            break;
    }
}
/*
void pwm0_init(PWM_DRV_DESC *pwm_drv_desc)
{
    if(pwm_drv_desc == NULL)
    {
        return;
    }
    
    if (pwm_drv_desc->channel > PWM_CHANNEL_NUMBER_MAX)
    {
        uart_printf("pwm0 channel error!!!\r\n");
        return;
    }
    
    if (pwm_drv_desc->duty_cycle > pwm_drv_desc->end_value)
    {
        uart_printf("pwm0 duty_cycle and end_value error!!!\r\n");
        return;
    }

    if(NULL != pwm_drv_desc->p_Int_Handler)
    {
        p_PWM0_Int_Handler[pwm_drv_desc->channel] = pwm_drv_desc->p_Int_Handler;
    }
    
    switch(pwm_drv_desc->mode)
    {
        case PWM_MODE_PWM:
            pwm0_sys_ctrl(pwm_drv_desc->channel, pwm_drv_desc->en, pwm_drv_desc->int_en,pwm_drv_desc->differential_output \
                                    ,pwm_drv_desc->differential_polarity);  

            setf_PWM_0_Reg0x2_Soft_Reset;        //release soft reset

            pwm_output_mode_init(DEV_PWM0, pwm_drv_desc->channel, pwm_drv_desc->end_value, pwm_drv_desc->pre_divid, \
                                    pwm_drv_desc->duty_cycle, pwm_drv_desc->deadtime);

            setf_PWM_0_Reg0x4_CEN1 ;                 //enable counter
            setf_PWM_0_Reg0x4_CEN2 ;                 //enable counter
            setf_PWM_0_Reg0x4_CEN3 ;                 //enable counter
            uart_printf("pwm0 PWM_MODE init success!!!\r\n");
            break;
        case PWM_MODE_CAPTUR:
            pwm0_sys_ctrl(pwm_drv_desc->channel, pwm_drv_desc->en,pwm_drv_desc->int_en,pwm_drv_desc->differential_output\
                                    ,pwm_drv_desc->differential_polarity);  
            
            setf_PWM_0_Reg0x2_Soft_Reset ;        //release soft reset
            
            pwm_cap_mode_init(DEV_PWM0, pwm_drv_desc->channel, 0x20) ; 
            
            uart_printf("pwm0 CAPTURE_MODE init success!!!\r\n");
            break;
        default:
            uart_printf("pwm0 mode error!!!\r\n");
            break;
    }
}

void pwm1_init(PWM_DRV_DESC *pwm_drv_desc)
{
    if(pwm_drv_desc == NULL)
    {
        return;
    }
    
    if (pwm_drv_desc->channel > PWM_CHANNEL_NUMBER_MAX)
    {
        uart_printf("pwm1 channel error!!!\r\n");
        return;
    }
    
    if (pwm_drv_desc->duty_cycle > pwm_drv_desc->end_value)
    {
        uart_printf("pwm1 duty_cycle and end_value error!!!\r\n");
        return;
    }
    
    if(NULL != pwm_drv_desc->p_Int_Handler)
    {
        p_PWM1_Int_Handler[pwm_drv_desc->channel] = pwm_drv_desc->p_Int_Handler;
    }
        
    switch(pwm_drv_desc->mode)
    {
        case PWM_MODE_PWM:
            pwm1_sys_ctrl(pwm_drv_desc->channel, pwm_drv_desc->en, pwm_drv_desc->int_en);  
            
            setf_PWM_1_Reg0x2_Soft_Reset;        //release soft reset
            
            pwm_output_mode_init(DEV_PWM1, pwm_drv_desc->channel, pwm_drv_desc->end_value, pwm_drv_desc->pre_divid, \
                                pwm_drv_desc->duty_cycle, pwm_drv_desc->deadtime);
            
            setf_PWM_1_Reg0x4_CEN1 ;                 //enable counter
            setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
            setf_PWM_1_Reg0x4_CEN3 ;                 //enable counter
            uart_printf("pwm1 PWM_MODE init success!!!\r\n");
            break;
        case PWM_MODE_CAPTUR:
             pwm1_sys_ctrl(pwm_drv_desc->channel, pwm_drv_desc->en, pwm_drv_desc->int_en);  
             
             setf_PWM_1_Reg0x2_Soft_Reset ;        //release soft reset
             
             pwm_cap_mode_init(DEV_PWM1, pwm_drv_desc->channel, 0x20) ; 
             
             setf_PWM_1_Reg0x4_CEN1 ;                 //enable COUNTER
             setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
             setf_PWM_1_Reg0x4_CEN3 ;                 //enable counter
             uart_printf("pwm1 CAPTURE_MODE init success!!!\r\n");
             break;
        default:
            uart_printf("pwm1 mode error!!!\r\n");
            break;
    }
}


void pwm1_end_value_duty_cycle_set(uint8_t ucChannel,uint32_t end_value,uint32_t duty_cycle)
{
    switch(ucChannel)
    {
        case 0:
        {                      
            addPWM1_Reg0x2 = end_value;
            addPWM1_Reg0x3 = duty_cycle;                         
        }break;
        
        case 1:
        {           
            addPWM1_Reg0x5 = end_value;
            addPWM1_Reg0x6 = duty_cycle;       
        }break;
        
        case 2:
        {           
            addPWM1_Reg0x8 = end_value;
            addPWM1_Reg0x9 = duty_cycle;       
        }break;
        
        default:break;
        
    }
}
*/
int pwm0_ccr_1;
int pwm0_ccr_4;
int pwm0_ccr_7;
int pwm1_ccr_2;
int pwm1_ccr_5;
int pwm1_ccr_8;
void pwm0_isr(void)
{
    unsigned char int_trigger = 0;

    uart_printf("addPWM_0_Reg0x8 %x\r\n", addPWM_0_Reg0x8);

    if(get_PWM_0_Reg0xa_TIM1CCM || get_PWM_0_Reg0xa_TIM2CCM || get_PWM_0_Reg0xa_TIM3CCM)    //capgture mode
    {
        if(get_PWM_0_Reg0x8_CC1IF)
        {
            setf_PWM_0_Reg0x8_CC1IF ;             //clear int flag

            int_trigger = 0x10;
            pwm0_ccr_1 = addPWM_0_Reg0x25 ;      //capture cycle between 2 posedge
            uart_printf("pwm0_ccr_1 is %x.\r\n", pwm0_ccr_1);
        }   
        
        if(get_PWM_0_Reg0x8_CC4IF)
        {
            setf_PWM_0_Reg0x8_CC4IF ;             //clear int flag

            int_trigger = 0x12;
            pwm0_ccr_4 = addPWM_0_Reg0x28 ;      //capture cycle between 2 posedge
            uart_printf("pwm0_ccr_4 is %x.\r\n", pwm0_ccr_4);
        }  
        
        if(get_PWM_0_Reg0x8_CC7IF)
        {
            setf_PWM_0_Reg0x8_CC7IF ;             //clear int flag

            int_trigger = 0x14;
            pwm0_ccr_7 = addPWM_0_Reg0x2b ;      //capture cycle between 2 posedge
            uart_printf("pwm0_ccr_7 is %x.\r\n", pwm0_ccr_7);
        }       

        if(int_trigger)
        {
            if (p_PWM0_Int_Handler[int_trigger & 0x0f] != NULL)
            {
                (void)p_PWM0_Int_Handler[int_trigger & 0x0f](int_trigger & 0x0f);
            }
        }
        
        clrf_PWM_0_Reg0x7_CC2IE ;            //disable ccr2 int
        clrf_PWM_0_Reg0x7_CC5IE ;            //disable ccr5 int
        clrf_PWM_0_Reg0x7_CC8IE ;            //disable ccr8 int     
    }
    else
    {
        if(get_PWM_0_Reg0x8_CC1IF)
        {
            setf_PWM_0_Reg0x8_CC1IF ;             //clear int ccr1 flag            
        }
        
        clrf_PWM_0_Reg0x2_Soft_Reset ;        //soft reset pwm0
        clrf_PWM_0_Reg0x7_CC1IE ;             //disable ccr1 int
    }
    
    #if 0
    for (i=0; i<PWM_CHANNEL_NUMBER_MAX; i++)
    {
        if (ulIntStatus & (0x01<<i))
        {
            if (p_PWM0_Int_Handler[i] != NULL)
            {
                (void)p_PWM0_Int_Handler[i]((unsigned char)i);
            }
        }
    }
    do
    {
        addPWM_0_Reg0x1 = ulIntStatus;
    } while (addPWM_0_Reg0x1 & ulIntStatus & 0x7);   // delays
    #endif
}


void pwm1_isr(void)
{
    unsigned char int_trigger = 0;

    uart_printf("addPWM_1_Reg0x8 %x\r\n", addPWM_1_Reg0x8);

    if(get_PWM_1_Reg0xa_TIM1CCM || get_PWM_1_Reg0xa_TIM2CCM || get_PWM_1_Reg0xa_TIM3CCM)    //capgture mode
    {
        if(get_PWM_1_Reg0x8_CC2IF)
        {
            setf_PWM_1_Reg0x8_CC2IF ;             //clear int flag

            int_trigger = 0x11;
            pwm1_ccr_2 = addPWM_1_Reg0x26 ;      //capture cycle between 2 posedge
            uart_printf("pwm1_ccr_2 is %x.\r\n", pwm1_ccr_2);
        }   
        
        if(get_PWM_1_Reg0x8_CC5IF)
        {
            setf_PWM_1_Reg0x8_CC5IF ;             //clear int flag

            int_trigger = 0x13;
            pwm1_ccr_5 = addPWM_1_Reg0x29 ;      //capture cycle between 2 posedge
            uart_printf("pwm1_ccr_5 is %x.\r\n", pwm1_ccr_5);
        }  
        
        if(get_PWM_1_Reg0x8_CC8IF)
        {
            setf_PWM_1_Reg0x8_CC8IF ;             //clear int flag

            int_trigger = 0x15;
            pwm1_ccr_8 = addPWM_1_Reg0x2c ;      //capture cycle between 2 posedge
            uart_printf("pwm1_ccr_8 is %x.\r\n", pwm1_ccr_8);
        }       

        if(int_trigger)
        {
            if (p_PWM1_Int_Handler[int_trigger & 0x0f] != NULL)
            {
                (void)p_PWM1_Int_Handler[int_trigger & 0x0f](int_trigger & 0x0f);
            }
        }
        //clrf_PWM_0_Reg0x7_CC2IE ;            //disable ccr2 int
        //clrf_PWM_0_Reg0x7_CC5IE ;            //disable ccr5 int
        //clrf_PWM_0_Reg0x7_CC8IE ;            //disable ccr8 int     
    }
    else
    {
        if(get_PWM_1_Reg0x8_CC1IF)
        {
            setf_PWM_1_Reg0x8_CC1IF ;             //clear int ccr1 flag      
						
        }
        clrf_PWM_1_Reg0x2_Soft_Reset ;        //soft reset pwm0
						clrf_PWM_1_Reg0x7_CC1IE ;             //disable ccr1 int
//        if(get_PWM_1_Reg0x8_UIF2)
//				{
//					clrf_PWM_1_Reg0x8_UIF2;
//				}
//				
//				if(get_PWM_1_Reg0x8_CC4IF)
//				{
//					setf_PWM_1_Reg0x8_CC4IF ;             //clear int ccr1 flag            
//				}
    }
}

void pwm_change_duty_isr_handler(unsigned char ucChannel)
{
    
    
}

void pwm_timer_demo_handler(unsigned char ucChannel)
{   
    uart_printf("%s, ucChannel %x\r\n", __func__, ucChannel);
}

/*
void pwm0_mode_pwm_demo(void) // t: period 100ms, 50% duty
{
    PWM_DRV_DESC pwm_drv_desc;
    uart_printf("%s\r\n", __func__);
    
    pwm_drv_desc.channel = PWM_CHANNEL0;
    pwm_drv_desc.duty_cycle = 0x20;
    pwm_drv_desc.end_value = 0x60;; 
    pwm_drv_desc.deadtime = 0x05;; 
    pwm_drv_desc.int_en = 1;
    pwm_drv_desc.en = 1;
    pwm_drv_desc.mode = PWM_MODE_PWM;
    pwm_drv_desc.pre_divid = 0x04;
    pwm_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm_drv_desc);
}


void pwm0_4_mode_pwm_demo(void) // t: period 100ms, 50% duty
{
    PWM_DRV_DESC pwm_drv_desc;
    uart_printf("%s\r\n", __func__);
    
    pwm_drv_desc.channel = PWM_CHANNEL4;
    pwm_drv_desc.duty_cycle = 0x20;
    pwm_drv_desc.end_value = 0x60;; 
    pwm_drv_desc.deadtime = 0x05;; 
    pwm_drv_desc.int_en = 1;
    pwm_drv_desc.en = 1;
    pwm_drv_desc.mode = PWM_MODE_PWM;
    pwm_drv_desc.pre_divid = 0x04;
    pwm_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm_drv_desc);
}


void pwm1_mode_pwm_demo(void) // t: period 100ms, 50% duty
{
    PWM_DRV_DESC pwm_drv_desc;
    uart_printf("%s\r\n", __func__);
    
    pwm_drv_desc.channel = PWM_CHANNEL1;
    pwm_drv_desc.duty_cycle = 0x30;
    pwm_drv_desc.end_value = 0x50;; 
    pwm_drv_desc.deadtime = 0x02;; 
    pwm_drv_desc.int_en = 1;
    pwm_drv_desc.en = 1;
    pwm_drv_desc.mode = PWM_MODE_PWM;
    pwm_drv_desc.pre_divid = 0x04;
    pwm_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm1_init(&pwm_drv_desc);
}


void test_pwm_single(void)
{
    PWM_DRV_DESC pwm0_drv_desc,pwm1_drv_desc;
    uart_printf("==============PWM_SIGNLE_TEST ==============\r\n");
    uart_printf("==============chn1 : end = 10ms, duty = 2ms==============\r\n");
    uart_printf("==============chn3 : end = 30ms,duty = 10ms==============\r\n");
    uart_printf("==============chn5 : end = 40ms,duty = 37.5ms==============\r\n");
    uart_printf("==============chn2 : end = 5ms, duty = 1ms==============\r\n");
    uart_printf("==============chn4 : end = 15ms,duty = 5ms==============\r\n");
    uart_printf("==============chn6 : end = 18ms,duty = 12ms==============\r\n");
    
    pwm0_drv_desc.channel = PWM_CHANNEL0;
    pwm0_drv_desc.duty_cycle = 1;//10000;//200;
    pwm0_drv_desc.end_value =2-1;
    //160000-1;//1000;          // 10ms
    pwm0_drv_desc.deadtime = 0;
    pwm0_drv_desc.int_en = 0;
    pwm0_drv_desc.en = 1;
    pwm0_drv_desc.mode = PWM_MODE_PWM;
    pwm0_drv_desc.pre_divid = 0;//160-1;     
    pwm0_drv_desc.differential_output = 0;
    pwm0_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm0_drv_desc);

    pwm0_drv_desc.channel = PWM_CHANNEL2;
    pwm0_drv_desc.duty_cycle = 1000;
    pwm0_drv_desc.end_value = 3000;          // 30ms
    pwm0_drv_desc.deadtime = 0;
    pwm0_drv_desc.int_en = 0;
    pwm0_drv_desc.en = 1;
    pwm0_drv_desc.mode = PWM_MODE_PWM;
    pwm0_drv_desc.pre_divid =  160-1;
    pwm0_drv_desc.differential_output = 0;
    pwm0_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm0_drv_desc);

    pwm0_drv_desc.channel = PWM_CHANNEL4;
    pwm0_drv_desc.duty_cycle = 7500;
    pwm0_drv_desc.end_value = 8000;          // 40ms
    pwm0_drv_desc.deadtime = 0;
    pwm0_drv_desc.int_en = 0;
    pwm0_drv_desc.en = 1;
    pwm0_drv_desc.mode = PWM_MODE_PWM;
    pwm0_drv_desc.pre_divid = 80-1;   
    pwm0_drv_desc.differential_output = 0;
    pwm0_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm0_drv_desc);

    
    pwm1_drv_desc.channel = PWM_CHANNEL1;
    pwm1_drv_desc.duty_cycle = 1;//200;
    pwm1_drv_desc.end_value = 2-1;//1000-1;          // 5ms
    pwm1_drv_desc.deadtime = 0;
    pwm1_drv_desc.int_en = 0;
    pwm1_drv_desc.en = 1;
    pwm1_drv_desc.mode = PWM_MODE_PWM;
    pwm1_drv_desc.pre_divid = 0;//80-1;
    pwm1_drv_desc.differential_output = 0;
    pwm1_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm1_init(&pwm1_drv_desc);
    
    pwm1_drv_desc.channel = PWM_CHANNEL3;
    pwm1_drv_desc.duty_cycle = 1000;
    pwm1_drv_desc.end_value = 3000-1;          // 15ms
    pwm1_drv_desc.deadtime = 0;
    pwm1_drv_desc.int_en = 0;
    pwm1_drv_desc.en = 1;
    pwm1_drv_desc.mode = PWM_MODE_PWM;
    pwm1_drv_desc.pre_divid = 80-1;
    pwm1_drv_desc.differential_output = 0;
    pwm1_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    
    pwm1_init(&pwm1_drv_desc);
    pwm1_drv_desc.channel = PWM_CHANNEL5;
    pwm1_drv_desc.duty_cycle = 1200;
    pwm1_drv_desc.end_value = 1800-1;          // 18ms
    pwm1_drv_desc.deadtime = 0x02;
    pwm1_drv_desc.int_en = 0;
    pwm1_drv_desc.en = 1;
    pwm1_drv_desc.mode = PWM_MODE_PWM;
    pwm1_drv_desc.pre_divid = 160-1;
    pwm1_drv_desc.differential_output = 0;
    pwm1_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm1_init(&pwm1_drv_desc);
    uart_printf("pwm0_p=%x,\r\n",addSYS_Reg0x4);
    
//while(1);
}
void test_pwm_sync(void)
{
    PWM_DRV_DESC pwm0_drv_desc,pwm1_drv_desc;

    uart_printf("==============PWM_SYNC_TEST ==============\r\n");
    uart_printf("==============chn1,2 sync ,end = 10ms, duty = 2ms==============\r\n");
    uart_printf("==============chn3,4 differential,end = 15ms,duty = 2ms==============\r\n");
    uart_printf("==============chn5,6 sync,end = 40ms,duty = 37.5ms==============\r\n");

    pwm0_drv_desc.channel = PWM_CHANNEL0;   //chn 1,2
    pwm0_drv_desc.duty_cycle = 200;
    pwm0_drv_desc.end_value = 1000;          // 10ms
    pwm0_drv_desc.deadtime = 0;
    pwm0_drv_desc.int_en = 0;
    pwm0_drv_desc.en = 1;
    pwm0_drv_desc.mode = PWM_MODE_PWM;
    pwm0_drv_desc.pre_divid = 160-1;     
    pwm0_drv_desc.differential_output = 1;
    pwm0_drv_desc.differential_polarity = 1;
    pwm0_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm0_drv_desc);

    pwm0_drv_desc.channel = PWM_CHANNEL2;   //chn 3,4
    pwm0_drv_desc.duty_cycle = 200;
    pwm0_drv_desc.end_value = 1500;          // 15ms
    pwm0_drv_desc.deadtime = 0;
    pwm0_drv_desc.int_en = 0;
    pwm0_drv_desc.en = 1;
    pwm0_drv_desc.mode = PWM_MODE_PWM;
    pwm0_drv_desc.pre_divid = 160-1;     
    pwm0_drv_desc.differential_output = 1;
    pwm0_drv_desc.differential_polarity = 0;
    pwm0_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm0_drv_desc);
    pwm0_drv_desc.channel = PWM_CHANNEL4;   //chn 5,6
    pwm0_drv_desc.duty_cycle = 7500;
    pwm0_drv_desc.end_value = 8000;          // 40ms
    pwm0_drv_desc.deadtime = 0;
    pwm0_drv_desc.int_en = 0;
    pwm0_drv_desc.en = 1;
    pwm0_drv_desc.mode = PWM_MODE_PWM;
    pwm0_drv_desc.pre_divid = 80-1;   
    pwm0_drv_desc.differential_output = 1;
    pwm0_drv_desc.differential_polarity = 1;
    pwm0_drv_desc.p_Int_Handler = pwm_timer_demo_handler;
    pwm0_init(&pwm0_drv_desc);
   
}
void test_pwm(uint8_t pwm_mode)
{
    if(pwm_mode == PWM_SINGLE)
    {
        test_pwm_single();
    }
    else 
    {
        test_pwm_sync();
    }
    clear_uart1_buffer();
    while(1)
    {
        if(uart1_rx_done)
        {
            return;
        }
    }

}
*/


void pwm0_init(uint8_t int_en)
{

    set_SYS_Reg0x4_pwm0_sel(1);
    clrf_SYS_Reg0x11_int_pwm0_pri;        //IRQ
    clrf_SYS_Reg0x3_pwm0_pwd;
    if(int_en)
    {
        setf_SYS_Reg0x10_int_pwm0_en;
    }
    else
    {
        clrf_SYS_Reg0x10_int_pwm0_en;
    }
    
    setf_PWM_0_Reg0x2_Soft_Reset;         //release soft reset

}

void pwm1_init(uint8_t int_en)
{

    set_SYS_Reg0x4_pwm1_sel(1);
    clrf_SYS_Reg0x11_int_pwm1_pri;        //IRQ
    clrf_SYS_Reg0x3_pwm1_pwd;
    if(int_en)
    {
        setf_SYS_Reg0x10_int_pwm1_en;
    }
    else
    {
        clrf_SYS_Reg0x10_int_pwm1_en;
    }
    
    setf_PWM_1_Reg0x2_Soft_Reset;         //release soft reset

}



void pwm_dis_chn(uint8_t diff_sel,uint8_t channel)
{
    if(!(channel&0x01))    // pwm0
    {    
        addPWM_0_Reg0xa &= ~(1<<(12+channel));
        gpio_config(pwm_channel_io_map[channel], INPUT, PULL_LOW);
        gpio_scfun_sel(pwm_channel_io_map[channel], 0);
        if(diff_sel)
        {
            addPWM_0_Reg0xa &= ~(1<<(12+channel+1));
            gpio_config(pwm_channel_io_map[channel+1], INPUT, PULL_LOW);
            gpio_scfun_sel(pwm_channel_io_map[channel+1], 0);
        }
    }
    else
    {    
    addPWM_1_Reg0xa &= ~(1<<(12+channel));
    gpio_config(pwm_channel_io_map[channel], INPUT, PULL_LOW);
    gpio_scfun_sel(pwm_channel_io_map[channel], 0);
}
        
}
void start_pwm(uint8_t mode,uint8_t diff_sel,uint8_t diff_polarity,uint8_t channel,uint32_t end_value,uint8_t pre_divid,uint32_t duty_cycle,uint32_t deadtime)
{
    uint32_t tmp_reg;
    pwm_dev_sel_t dev_sel=DEV_PWM0;
    // mode : PWM_MODE_PWM/PWM_MODE_CAPTUR
    // diff_sel: 1: 0,1 / 2,3 / 4,5 ,in this mode,channel = 0,2,4

    if(diff_sel)
    {
        if((channel&0x01)&&(channel>PWM_CHANNEL5))
        {
            uart_printf("pwm_diff channel error!!!\r\n");
            return;
        }
        
    // set 2 pwms fun
    
        gpio_config(pwm_channel_io_map[channel], SC_FUN, PULL_NONE);
        gpio_scfun_sel(pwm_channel_io_map[channel], 1);
        gpio_config(pwm_channel_io_map[(channel)+1], SC_FUN, PULL_NONE);
        gpio_scfun_sel(pwm_channel_io_map[(channel)+1], 1);

    // set diff_polarity
        tmp_reg = addPWM_0_Reg0xa & (~(0x0f<<((channel<<1))));
        tmp_reg |= diff_polarity<<((channel<<1));
        addPWM_0_Reg0xa = tmp_reg;
    // set Simultaneously
    /*    clrf_SYS_Reg0xc_pwm_ctrl0 ; //1:set PWM 0,1  Simultaneously output
        clrf_SYS_Reg0xc_pwm_ctrl1 ; //1:set PWM 2,3  Simultaneously output
        clrf_SYS_Reg0xc_pwm_ctrl2 ; //1:set PWM 4,5  Simultaneously output*/
        addSYS_Reg0xc &= ~(1<<(20+channel));// set Simultaneously output
    }
    else
    {
        if(channel>PWM_CHANNEL5)
        {
            uart_printf("pwm_sync channel error!!!\r\n");
            return;
        }
        if(channel&0x01)    // pwm1
        {
            dev_sel=DEV_PWM1;
        }
        gpio_config(pwm_channel_io_map[channel], SC_FUN, PULL_NONE);
        #if P23_PWM_ENABLE
        if(pwm_channel_io_map[channel] == 0x23)
        {
            //uart_printf("pin0x%x ,set func 0+++++++++++\n", pwm_channel_io_map[channel]);
            gpio_scfun_sel(pwm_channel_io_map[channel], 0);
        }
        else
        #endif /* P23_PWM_ENABLE */
        {
            //uart_printf("pin0x%x,set func 1+++++++++++\n", pwm_channel_io_map[channel]);
            gpio_scfun_sel(pwm_channel_io_map[channel], 1);
        }
        addSYS_Reg0xc |= (1<<(20+(channel>>1)));// set Simultaneously output
    }
    
//    setf_PWM_0_Reg0x2_Soft_Reset; 
///        setf_PWM_1_Reg0x2_Soft_Reset; 
    switch(mode)
    {
        case PWM_MODE_PWM:

            pwm_output_mode_init(dev_sel,diff_sel, channel, end_value, pre_divid, duty_cycle, deadtime);

         //   uart_printf("pwm_%x PWM_MODE init success!!!\r\n",dev_sel);
            break;
        case PWM_MODE_CAPTUR:
            
            pwm_cap_mode_init(dev_sel, channel, 0x20) ; 
            
            uart_printf("pwm_%x CAPTURE_MODE init success!!!\r\n",dev_sel);
            break;
        default:
            uart_printf("pwm_%x mode error!!!\r\n",dev_sel);
            break;
    }

//    
}

void start_pwm1(uint8_t mode,uint8_t diff_sel,uint8_t diff_polarity,uint8_t channel,uint32_t end_value,uint8_t pre_divid,uint32_t duty_cycle,uint32_t deadtime)
{
    uint32_t tmp_reg;
    pwm_dev_sel_t dev_sel=DEV_PWM0;
    // mode : PWM_MODE_PWM/PWM_MODE_CAPTUR
    // diff_sel: 1: 0,1 / 2,3 / 4,5 ,in this mode,channel = 0,2,4

    if(diff_sel)
    {
        if((channel&0x01)&&(channel>PWM_CHANNEL5))
        {
            uart_printf("pwm_diff channel error!!!\r\n");
            return;
        }
        
    // set 2 pwms fun
        gpio_config(pwm_channel_io_map[channel], SC_FUN, PULL_NONE);
        gpio_scfun_sel(pwm_channel_io_map[channel], 1);
        gpio_config(pwm_channel_io_map[(channel)+1], SC_FUN, PULL_NONE);
        gpio_scfun_sel(pwm_channel_io_map[(channel)+1], 1);
    // set diff_polarity
        tmp_reg = addPWM_0_Reg0xa & (~(0x03<<((channel<<1)+2)));
        tmp_reg |= diff_polarity<<((channel<<1)+2);
        addPWM_0_Reg0xa = tmp_reg;
        
#if 0
    // set Simultaneously
    /*    clrf_SYS_Reg0xc_pwm_ctrl0 ; //1:set PWM 0,1  Simultaneously output
        clrf_SYS_Reg0xc_pwm_ctrl1 ; //1:set PWM 2,3  Simultaneously output
        clrf_SYS_Reg0xc_pwm_ctrl2 ; //1:set PWM 4,5  Simultaneously output*/
        addSYS_Reg0xc &= ~(1<<(20+channel));// set Simultaneously output
        #endif
    }
    else
    {
        if(channel>PWM_CHANNEL5)
        {
            uart_printf("pwm_sync channel error!!!\r\n");
            return;
        }
        if(channel&0x01)    // pwm1
        {
            dev_sel=DEV_PWM1;
        }
        gpio_config(pwm_channel_io_map[channel], SC_FUN, PULL_NONE);
        gpio_scfun_sel(pwm_channel_io_map[channel], 1);
        addSYS_Reg0xc |= (1<<(20+(channel>>1)));// set Simultaneously output
    }
#if 0    
    setf_PWM_0_Reg0x2_Soft_Reset; 
        setf_PWM_1_Reg0x2_Soft_Reset; 
    switch(mode)
    {
        case PWM_MODE_PWM:

            pwm_output_mode_init(dev_sel,diff_sel, channel, end_value, pre_divid, duty_cycle, deadtime);

            uart_printf("pwm_%x PWM_MODE init success!!!\r\n",dev_sel);
            break;
        case PWM_MODE_CAPTUR:
            
            pwm_cap_mode_init(dev_sel, channel, 0x20) ; 
            
            uart_printf("pwm_%x CAPTURE_MODE init success!!!\r\n",dev_sel);
            break;
        default:
            uart_printf("pwm_%x mode error!!!\r\n",dev_sel);
            break;
    }
                setf_PWM_0_Reg0x4_CEN1 ;                 //enable counter
            setf_PWM_0_Reg0x4_CEN2 ;                 //enable counter
            setf_PWM_0_Reg0x4_CEN3 ;                 //enable counter
setf_PWM_1_Reg0x4_CEN1 ;                 //enable counter
setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
setf_PWM_1_Reg0x4_CEN3 ;                 //enable counter
#endif
//    
}

void pwm_end_value_duty_cycle_set(uint8_t diff_sel,uint8_t ucChannel,uint32_t end_value,uint32_t duty_cycle)
{
    // Early validation ensures ucChannel is in range [0-5]
    if(ucChannel>5)
    {
        uart_printf("pwm_channel error!!!\r\n");
        return;
    }
    
    // Switch handles all valid channel values (0-5) explicitly
    // Removed unreachable default case to fix static analysis warning
    switch(ucChannel)
    {
        case PWM_CHANNEL0:
        {                      
            addPWM_0_Reg0xf = end_value;
            addPWM_0_Reg0x15 = duty_cycle;                         
        }break;
        
        case PWM_CHANNEL1:
        {                      
            addPWM_1_Reg0xf = end_value;
            addPWM_1_Reg0x15 = duty_cycle;                         
        }break;
        
        case PWM_CHANNEL2:
        {           
            addPWM_0_Reg0x10 = end_value;
            addPWM_0_Reg0x18 = duty_cycle;       
        }break;
        
        case PWM_CHANNEL3:
        {           
            addPWM_1_Reg0x10 = end_value;
            addPWM_1_Reg0x18 = duty_cycle;       
        }break;
        
        case PWM_CHANNEL4:
        {           
            addPWM_0_Reg0x11 = end_value;
            addPWM_0_Reg0x1b = duty_cycle;       
        }break;
                    
        case PWM_CHANNEL5:
        {           
            addPWM_1_Reg0x11 = end_value;
            addPWM_1_Reg0x1b = duty_cycle;       
        }break;
        
        default:
        {
            // This default case is unreachable because:
            // 1. Early validation catches ucChannel > 5
            // 2. All valid channels (0-5) are handled explicitly above
            uart_printf("Unreachable: Invalid PWM channel!!!\r\n");
        }break;
    }
    
}

void pwm_test(void)
{
    gpio_config(0x20,INPUT,PULL_HIGH);
    gpio_config(0x21,INPUT,PULL_HIGH);
    gpio_config(0x22,INPUT,PULL_HIGH);
    //gpio_config(0x23,INPUT,PULL_HIGH);

    pwm0_init(0);
    pwm1_init(0);
    uart_printf("start_pwm_test \r\n");
    uint8_t key_vaild=0,change_duty=0;
    uint32_t pwm_test_count=0,end_value1,cyale_value1,end_value2,cyale_value2;
    while(1)
    {
        if(!key_vaild)
        {
            if(!gpio_get_input(0x20))
            {
                key_vaild = 1;
                uart_printf("step1:pwm_test_Simultaneously_all \r\n");
                uart_printf("pwm_chn : 0,2,4 \r\n");

                start_pwm(PWM_MODE_PWM,1,1,0,1000,160-1,200,0);    //10ms 
                start_pwm(PWM_MODE_PWM,1,0,2,1500,160-1,200,0);    //15ms
                start_pwm(PWM_MODE_PWM,1,1,4,8000,160-1,750,0);    //80ms
            
                change_duty = 0;
            }
            if(!gpio_get_input(0x21))
            {
                key_vaild = 1;
                uart_printf("step2:pwm_test_single_all \r\n");
                uart_printf("pwm_chn : 0,1,2,3,4,5 \r\n");

                //start_pwm(PWM_MODE_PWM,0,0,0,2-1,160-1,1,0);    //20us
                start_pwm(PWM_MODE_PWM,0,0,0, 4,160-1, 2,0);    //20us

                start_pwm(PWM_MODE_PWM,0,0,1,3000,160-1,1000,0);    //30ms
                start_pwm(PWM_MODE_PWM,0,0,2,8000,160-1,750,0);    //80ms
                //start_pwm(PWM_MODE_PWM,0,0,3,1000,160-1,550,0); //10ms    

                start_pwm(PWM_MODE_PWM,0,0,3,1000*2,160-1,550*2,0); //10ms        

                start_pwm(PWM_MODE_PWM,0,0,4,1800,160-1,1200,0); //18ms                    
                start_pwm(PWM_MODE_PWM,0,0,5,3000,160-1,1000,0); //30ms
                change_duty = 0;
                Delay_ms(100);
            }

            if(!gpio_get_input(0x22))
            {
                key_vaild = 1;
                uart_printf("step3:chn_0 sim,chn_2,3 single\r\n");
                uart_printf("pwm_chn : 0,1,2,3 \r\n");
                uart_printf("pwm_chn0,1,3 can change duty \r\n");
                end_value1=1000;
                cyale_value1=200;
                end_value2=3000;
                cyale_value2=1000;

                start_pwm(PWM_MODE_PWM,1,0,0,end_value1,160-1,cyale_value1,0);    //10ms
                start_pwm(PWM_MODE_PWM,0,0,2,8000,160-1,750,0);    //80ms
                start_pwm(PWM_MODE_PWM,0,0,3,end_value2,160-1,cyale_value2,0); //10ms        
                change_duty = 1;        
            }
            
            #if 0
            if(!gpio_get_input(0x23))
            {
                key_vaild = 1;
                uart_printf("step4:pwm_test_close 0,1,3@step3\r\n");
                uart_printf("pwm_chn : 2 \r\n");

                pwm_dis_chn(1,0);
                pwm_dis_chn(0,3);
                change_duty = 1;
            }
            #endif            
        }
        else
        {
            if((gpio_get_input(0x20))&&(gpio_get_input(0x21))&&(gpio_get_input(0x22))
            //&&(gpio_get_input(0x23))
            )
            {
                key_vaild = 0;
                Delay_ms(10);
            }
        }
        if(change_duty)
        {
            pwm_test_count++;
            if(pwm_test_count>10000)
            {
                pwm_test_count = 0;
                cyale_value1+=10;
                if(cyale_value1>end_value1)
                {
                    cyale_value1 = 10;
                }
                cyale_value2+=10;
                if(cyale_value2>end_value2)
                {
                    cyale_value2 = 10;
                }
                pwm_end_value_duty_cycle_set(1,0,end_value1,cyale_value1);
                pwm_end_value_duty_cycle_set(0,3,end_value2,cyale_value2);
            }
        }
        wdt_feed();
    }
}

#endif /* PWM_DRIVER */

