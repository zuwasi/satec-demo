/**
****************************************************************************************
*
* @file driver_gpio.c
*
* @brief icu initialization and specific functions
*
* Copyright (C) Beken 2009-2016
*
* $Rev: $
*
****************************************************************************************
*/
#include "driver_gpio.h"
#include "BK3437_RegList.h"
#include "uart1.h"
#include <stdio.h>
#include "user_config.h"
#include "icu.h"

static GPIO_INT_CALLBACK_T gpio_int_cb = NULL; 

void gpio_config(uint8_t gpio, Dir_Type dir, Pull_Type pull)
{
    uint32_t gpio_temp=0;
    uint8_t port = ((gpio&0xf0)>>4);
    uint8_t pin = (gpio&0xf);

    switch(dir)
    {
        case OUTPUT:
            gpio_temp &= ~(1<<GPIO_INPUT_EN);
            gpio_temp &= ~(1<<GPIO_OUTPUT_EN);
            break;
        case INPUT:
            gpio_temp |= (1<<GPIO_OUTPUT_EN);
            gpio_temp |= (1<<GPIO_INPUT_EN);
            break;
        case FLOAT:
            gpio_temp &= ~(1<<GPIO_INPUT_EN);
            gpio_temp |= (1<<GPIO_OUTPUT_EN);
            break;
        case SC_FUN:
            gpio_temp |= (1<<GPIO_2FUN_EN);
            gpio_temp |= (1<<GPIO_OUTPUT_EN);
            break;
    }

    switch(pull)
    {
    case PULL_HIGH:        
        gpio_temp |= (1<<GPIO_PULL_EN);
        gpio_temp |= (1<<GPIO_PULL_MODE);
        break;
    case PULL_LOW:
        gpio_temp |= (1<<GPIO_PULL_EN);
        gpio_temp &= ~(1<<GPIO_PULL_MODE);
        break;
    case PULL_NONE:
        gpio_temp &= ~(1<<GPIO_PULL_EN);
        break;
    }
    *((volatile unsigned long *) (BASEADDR_AON_GPIO+4*(port*8+pin)))=gpio_temp;

}

void gpio_scfun_sel(uint8_t gpio, uint8_t function_mode)
{
    uint32_t  gpio_temp=0;
    uint8_t port = ((gpio&0xf0)>>4);
    uint8_t  pin = (gpio&0xf);

    gpio_temp = *((volatile unsigned long *) (BASEADDR_SYS + 4 * (port + 0x30)));

    gpio_temp &= ~(0x0f << (pin * 4));    //clear previous function

    gpio_temp |= function_mode << (pin * 4);

    *((volatile unsigned long *) (BASEADDR_SYS + 4 * (port + 0x30))) = gpio_temp;
}

uint8_t gpio_get_input(uint8_t gpio)
{
    uint32_t temp=0;
    uint8_t port = ((gpio&0xf0)>>4);
    uint8_t  pin = (gpio&0xf);

    temp = *((volatile unsigned long *) (BASEADDR_AON_GPIO+4*(port*8+pin)));

    return (temp&(1<<GPIO_INPUT_VA));
}

void gpio_set(uint8_t gpio, uint8_t val)
{
    uint32_t temp=0;
    uint8_t port = ((gpio&0xf0)>>4);
    uint8_t  pin = (gpio&0xf);

    temp = *((volatile unsigned long *) (BASEADDR_AON_GPIO+4*(port*8+pin)));
    if(val)
    {
        temp |= (1<<GPIO_OUTPUT_VA);
    }
    else
    {
        temp &= ~(1<<GPIO_OUTPUT_VA);
    }
    *((volatile unsigned long *) (BASEADDR_AON_GPIO+4*(port*8+pin))) = temp;

}

void gpio_toggle(uint8_t gpio)
{
    gpio_set(gpio,1);
    gpio_set(gpio,0);
}

void gpio_set_neg(uint8_t gpio)
{
    uint32_t temp=0;
    uint8_t port = ((gpio&0xf0)>>4);
    uint8_t  pin = (gpio&0xf);

    temp = *((volatile unsigned long *) (BASEADDR_AON_GPIO+4*(port*8+pin)));
    temp ^= (1<<GPIO_OUTPUT_VA);
    *((volatile unsigned long *) (BASEADDR_AON_GPIO+4*(port*8+pin))) = temp;

}

void gpio_set_int_mode(uint8_t gpio,uint8_t mode)
{
    uint8_t port = ((gpio&0xf0)>>4);
    uint8_t  pin = (gpio&0xf);
    if((port*8+pin)<16)
    {
        REG_GPIO_WUATOD_TYPE &= ~(3<<(2*(port*8+pin)));
        REG_GPIO_WUATOD_TYPE |= mode<<(2*(port*8+pin));
    }
    else
    {
        REG_GPIO_WUATOD_TYPE1 &= ~(3<<(2*((port*8+pin)-16)));
        REG_GPIO_WUATOD_TYPE1 |= mode<<(2*((port*8+pin)-16));
    }
    REG_GPIO_WUATOD_ENABLE |= 1<<(port*8+pin);
    REG_GPIO_WUATOD_STATUS |= 1<<(port*8+pin);
    addPMU_Reg0x3 |= 1<<(port*8+pin);
}


void set_gpio_isr_wake_up(GPIO_PORT gpio,GPIO_PIN gpio_pins)
{
    addPMU_Reg0x3 = addPMU_Reg0x3 | (gpio_pins << (gpio * 8));  // gpiox-pin deep wake enable
}


#define addAON_GPIO_Int_En   *((volatile unsigned long *) (0x00800A00+0x33*4))
#define addAON_GPIO_Int_Sta  *((volatile unsigned long *) (0x00800A00+0x35*4))
#define addAON_GPIO_Int_Type1   *((volatile unsigned long *) (0x00800A00+0x30*4))
#define addAON_GPIO_Int_Type2   *((volatile unsigned long *) (0x00800A00+0x31*4))

void gpio_isr_enable(GPIO_PORT gpio,GPIO_PIN gpio_pins,int is_enable)
{
    if( is_enable ) {
        addAON_GPIO_Int_En |= (gpio_pins << (gpio * 8));
    }else {
        addAON_GPIO_Int_En &= (~(gpio_pins << (gpio * 8)));
    }
}

void gpio_clear_isr_flag(GPIO_PORT gpio,GPIO_PIN gpio_pins)
{
    addAON_GPIO_Int_Sta = addAON_GPIO_Int_Sta | (gpio_pins << (gpio * 8));
}
void reset_gpio_isr_wake_up(GPIO_PORT gpio,GPIO_PIN gpio_pins)
{
    addPMU_Reg0x3 = addPMU_Reg0x3 & (~(gpio_pins << (gpio * 8)));
}

void gpio_isr_mode(GPIO_PORT gpio,GPIO_PIN gpio_pins,GPIO_ISR_MODE mode)
{
    int i;
    unsigned int gpio_offset;
    unsigned int pin_offset;

    //mode = mode & (GPIO_ISR_MODE)0x03;
    if((gpio == GPIOP1) || (gpio == GPIOP0))
    {
        gpio_offset = gpio - GPIOP0;
        for(i=7;i>0;i--)
        {
            if(gpio_pins & (0x1U << i))
            {
                pin_offset = (i * 2) + 16 * gpio_offset;
                addAON_GPIO_Int_Type1 = (addAON_GPIO_Int_Type1 & (~(0x3U << pin_offset))) | (mode << pin_offset);
            }
        }
    }
    else if((gpio == GPIOP3) || (gpio == GPIOP2))
    {
        gpio_offset = gpio - GPIOP2;
        for(i=7;i>0;i--)
        {
            if(gpio_pins & (0x1U << i))
            {
                pin_offset = (i * 2) + 16 * gpio_offset;
                addAON_GPIO_Int_Type2 = (addAON_GPIO_Int_Type2 & (~(0x3U << pin_offset))) | (mode << pin_offset);
            }
        }
    }
}

void gpio_perial_function_en(GPIO_PORT port,GPIO_PIN pin)
{
    addSYS_Reg0x7 |=pin<<(port*8);
}

void gpio_perial_function_dis(GPIO_PORT port,GPIO_PIN pin)
{
    addSYS_Reg0x7 &=~(pin<<(port*8));
}


struct gpio_isr_item
{
    unsigned char state_ops;
    void (*isr_cb)(void);
};


void gpio_cb_register(GPIO_INT_CALLBACK_T cb)
{
    if(cb)
    {
        gpio_int_cb = cb;
    }
}


void gpio_isr(void)
{
     unsigned int state = addAON_GPIO_Int_Sta;

    clrf_SYS_Reg0x10_int_aon_gpio_en;
    
    if(gpio_int_cb)
    {
        (*gpio_int_cb)(state);
    }

    addAON_GPIO_Int_Sta=state;
    
}

void gpio_init(void)
{
    uint8_t i;
    for(i=0;i<24;i++)
        *((volatile unsigned long *) (BASEADDR_AON_GPIO+i*4))=0x00;
}

void debug_msg_gpio(uint8_t value)
{
#if GPIO_DBG_MSG
    addAON_GPIO_Reg0x9=0x00;
    addAON_GPIO_Reg0x2=(value&0x01)<<1;
    addAON_GPIO_Reg0x3=(value&0x02);
    addAON_GPIO_Reg0x4=(value&0x04)>>1;
    addAON_GPIO_Reg0x5=(value&0x08)>>2;
    addAON_GPIO_Reg0x6=(value&0x10)>>3;
    addAON_GPIO_Reg0x7=(value&0x20)>>4;
    addAON_GPIO_Reg0x8=(value&0x40)>>5;
    addAON_GPIO_Reg0x9=0x02;
#endif
}




