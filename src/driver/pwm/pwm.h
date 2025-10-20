/**
 ****************************************************************************************
 *
 * @file pwm.h
 *
 * @brief pwm Driver for pwm operation.
 *
 * Copyright (C) Beken 2019-2021
 *
 *
 ****************************************************************************************
 */

#ifndef _PWM_H_
#define _PWM_H_



#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions
/**
 ****************************************************************************************
 * @defgroup PWM 
 * @ingroup DRIVERS
 * @brief pwm driver
 *
 * @{
 *
 ****************************************************************************************
 */
#define PWM_CHANNEL_NUMBER_MAX               5
#define P23_PWM_ENABLE                      0
typedef enum
{
    PWM_MODE_IDLE = 0,
    PWM_MODE_PWM  = 1,
    PWM_MODE_CAPTUR = 2,
}pwm_mode_t;

enum{
    PWM_CLK_ROSC32K = 0,
    PWM_CLK_XTAL16M  = 1,
    PWM_CLK_DPLL = 2,
};

typedef enum
{
    #if P23_PWM_ENABLE
    GPIO5 = 0x23,   
    #else
    GPIO5 = 0x05,
    #endif /* P23_PWM_ENABLE */
    GPIO6 = 0x06, 
    GPIO7 = 0x07, 
    GPIO8 = 0x10, 
    GPIO9 = 0x11, 
    GPIO10 = 0x12, 
}pwm_gpio_t;

typedef enum
{
    PWM_CHANNEL0,   //GPIO5
    PWM_CHANNEL1,   //GPIO6
    PWM_CHANNEL2,   //GPIO7
    PWM_CHANNEL3,   //GPIO8
    PWM_CHANNEL4,   //GPIO9
    PWM_CHANNEL5   //GPIO10
}pwm_channel_t;

typedef enum
{
    DEV_PWM0,
    DEV_PWM1,
}pwm_dev_sel_t;
 //----------------------------------------------
// PWM driver description
//----------------------------------------------
typedef struct
{
    pwm_channel_t     channel;        // PWM 0~5, GPIO5 ~ GPIO10

   /* mode:   PWM mode
    * bit[0]:  PWM enable
    *          0: PWM disable
    *          1: PWM enable
    * bit[1]:   PWM interrupt enable
    *          0: PWM interrupt disable
    *          1: PWM interrupt enable
    * bit[4:2]: PWM mode selection
    *          000: IDLE
    *          001: PWM Mode
    *          010: TIMER Mode
    *          100:Captur
    *          101:Counter
    */
    unsigned char       en;
    unsigned char       int_en;
    pwm_mode_t          mode;         //000: IDLE    001: PWM Mode   02: Capture 
    //unsigned char     cpedg_sel;    //00:both edge  01:posedge  10:negedge
    //unsigned char     contiu_mode;  //0:not in continue mode  1:continue mode
    //unsigned char       clk_src;      // 01:xtal16m   00:rosc32k  1x:DP11
    unsigned char       pre_divid;    // PWM pre-divide clk
    unsigned int        end_value;    // PWM counter end value
    unsigned int        duty_cycle;   // PWM counter duty cycle, 
    unsigned int        deadtime;
    unsigned int        differential_output;    // PWM 2 chns differentialoutput
    unsigned int        differential_polarity;  // PWM 2 chns differential: 0:2 chns sync, 1:2 chns differential
                                    // this value must smaller or equal to end value
    void (*p_Int_Handler)(unsigned char ucChannel);     // PWM channel Interrupt Handler
} PWM_DRV_DESC;

typedef enum{
    PWM_SINGLE,
    PWMM_DIFF,
};
extern void (*p_PWM0_Int_Handler[PWM_CHANNEL_NUMBER_MAX])(unsigned char ucPWM_channel);
extern void (*p_PWM1_Int_Handler[PWM_CHANNEL_NUMBER_MAX])(unsigned char ucPWM_channel);

//void pwm0_init(PWM_DRV_DESC *pwm_drv_desc);
//void pwm1_init(PWM_DRV_DESC *pwm_drv_desc);
//void pwm1_end_value_duty_cycle_set(uint8_t  ucChannel,uint32_t end_value,uint32_t duty_cycle);

void pwm0_isr(void);
void pwm1_isr(void);
void test_pwm_single(void);
void test_pwm_sync(void);
void test_pwm(uint8_t pwm_mode);


void pwm0_init(uint8_t int_en);
void pwm1_init(uint8_t int_en);
void pwm0_dis(uint8_t channel);
void pwm1_dis(uint8_t channel);
void start_pwm(uint8_t mode,uint8_t diff_sel,uint8_t diff_polarity,uint8_t channel,uint32_t end_value,uint8_t pre_divid,uint32_t duty_cycle,uint32_t deadtime);
void pwm_end_value_duty_cycle_set(uint8_t diff_sel,uint8_t ucChannel,uint32_t end_value,uint32_t duty_cycle);
void pwm_dis_chn(uint8_t diff_sel,uint8_t channel);
void start_pwm1(uint8_t mode,uint8_t diff_sel,uint8_t diff_polarity,uint8_t channel,uint32_t end_value,uint8_t pre_divid,uint32_t duty_cycle,uint32_t deadtime);
void pwm_test(void);

#endif //  _PWM_H_

