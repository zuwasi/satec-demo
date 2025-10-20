/**
 ****************************************************************************************
 *
 * @file driver_gpio.h
 *
 * @brief gpio Driver for gpio operation.
 *
 * Copyright (C) Beken 2009-2015
 *
 *
 ****************************************************************************************
 */
#ifndef _DRIVER_GPIO_H_
#define _DRIVER_GPIO_H_
#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions
#define GPIO_INPUT_VA   0
#define GPIO_OUTPUT_VA  1
#define GPIO_INPUT_EN   2
#define GPIO_OUTPUT_EN  3
#define GPIO_PULL_MODE  4
#define GPIO_PULL_EN    5
#define GPIO_2FUN_EN    6
#define BASEADDR_GPIO                                           0x00800A00
#define REG_GPIO_WUATOD_TYPE            *((volatile unsigned long*)(BASEADDR_GPIO+0x30*4))
#define REG_GPIO_WUATOD_TYPE1           *((volatile unsigned long*)(BASEADDR_GPIO+0x31*4))
#define REG_GPIO_WUATOD_ENABLE          *((volatile unsigned long*)(BASEADDR_GPIO+0x33*4))
#define REG_GPIO_WUATOD_STATUS          *((volatile unsigned long*)(BASEADDR_GPIO+0x35*4))

enum{
    GPIO_General_Function,
    GPIO_Special_Function,
};

 typedef enum
{
    INPUT,
    OUTPUT,
    FLOAT,
    SC_FUN,
}Dir_Type;

typedef enum
{
    PULL_LOW=0,
    PULL_HIGH=1,
    PULL_NONE
}Pull_Type;
 
typedef enum
{
    VOLTAGE_LOW,
    VOLTAGE_HIGHT,   
    RISE_EDGE,
    FALL_EDGE,
}int_mode;


/* GPIOx */
typedef enum{
    GPIOA        =            0,
    GPIOB        =            1,
    GPIOC        =            2,
    GPIOD        =            3,

    GPIOP0        =            0,
    GPIOP1        =            1,
    GPIOP2         =                    2,
    GPIOP3        =            3,
}GPIO_PORT;

/* GPIO_Pinx */
typedef enum{
    GPIO_Pin_0 = 0x01,
    GPIO_Pin_1 = 0x02,
    GPIO_Pin_2 = 0x04,
    GPIO_Pin_3 = 0x08,
    GPIO_Pin_4 = 0x10,
    GPIO_Pin_5 = 0x20,
    GPIO_Pin_6 = 0x40,
    GPIO_Pin_7 = 0x80,
  
}GPIO_PIN;

/* GPIO_Pinx */
typedef enum{

    GPIO0_PIN0 = (GPIOP0<<4)|0,
    GPIO0_PIN1 = (GPIOP0<<4)|1,
    GPIO0_PIN2 = (GPIOP0<<4)|2,
    GPIO0_PIN3 = (GPIOP0<<4)|3,
    GPIO0_PIN4 = (GPIOP0<<4)|4,
    GPIO0_PIN5 = (GPIOP0<<4)|5,
    GPIO0_PIN6 = (GPIOP0<<4)|6,
    GPIO0_PIN7 = (GPIOP0<<4)|7,

    GPIO1_PIN0 = (GPIOP1<<4)|0,
    GPIO1_PIN1 = (GPIOP1<<4)|1,
    GPIO1_PIN2 = (GPIOP1<<4)|2,
    GPIO1_PIN3 = (GPIOP1<<4)|3,
    GPIO1_PIN4 = (GPIOP1<<4)|4,
    GPIO1_PIN5 = (GPIOP1<<4)|5,
    GPIO1_PIN6 = (GPIOP1<<4)|6,
    GPIO1_PIN7 = (GPIOP1<<4)|7,

    GPIO2_PIN0 = (GPIOP2<<4)|0,
    GPIO2_PIN1 = (GPIOP2<<4)|1,
    GPIO2_PIN2 = (GPIOP2<<4)|2,
    GPIO2_PIN3 = (GPIOP2<<4)|3,
    GPIO2_PIN4 = (GPIOP2<<4)|4,
    GPIO2_PIN5 = (GPIOP2<<4)|5,
    GPIO2_PIN6 = (GPIOP2<<4)|6,
    GPIO2_PIN7 = (GPIOP2<<4)|7,

    GPIO3_PIN0 = (GPIOP3<<4)|0,
    GPIO3_PIN1 = (GPIOP3<<4)|1,
    GPIO3_PIN2 = (GPIOP3<<4)|2,
    GPIO3_PIN3 = (GPIOP3<<4)|3,
    GPIO3_PIN4 = (GPIOP3<<4)|4,
    GPIO3_PIN5 = (GPIOP3<<4)|5,
    GPIO3_PIN6 = (GPIOP3<<4)|6,
    GPIO3_PIN7 = (GPIOP3<<4)|7,
}GPIO_PORT_PIN;

typedef enum{
    Low_level_Trigging = 0,
    High_level_Tringging =1,
    Rising_edge_Trigging = 2,
    falling_edge_Tringging = 3, 
}GPIO_ISR_MODE;

enum{
    _DPULSE = 1,
    _SPULSE = 0,
};

typedef void (*GPIO_INT_CALLBACK_T)(unsigned int ch);   
void gpio_cb_register(GPIO_INT_CALLBACK_T cb);


void gpio_init(void);
void gpio_config(uint8_t gpio, Dir_Type dir, Pull_Type pull);
uint8_t gpio_get_input(uint8_t gpio);
void gpio_set(uint8_t gpio, uint8_t val);
void gpio_target(uint8_t gpio);
void gpio_isr(void);
void gpio_sleep(void);
void gpio_wakeup(void);
void gpio_triger(uint8_t gpio);
void DEBUG_MSG(uint8_t x);
void gpio_set_neg(uint8_t gpio);
void gpio_input_hi_test(void);
void gpio_input_lo_test(void);
void gpio_toggle(uint8_t gpio);

void gpio_isr_enable(GPIO_PORT gpio,GPIO_PIN gpio_pins,int is_enable);
void gpio_clear_isr_flag(GPIO_PORT gpio,GPIO_PIN gpio_pins);
void gpio_scfun_sel(uint8_t gpio, uint8_t function_mode);
void gpio_set_int_mode(uint8_t gpio,uint8_t mode);
void debug_msg_gpio(uint8_t value);
#endif
