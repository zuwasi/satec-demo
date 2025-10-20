/**
 ****************************************************************************************
 *
 * @file intc.c
 *
 * @brief Definition of the Interrupt Controller (INTCTRL) API.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup INTC
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "rwip_config.h"
#include "compiler.h"        // for inline functions
#include "arch.h"            // arch definition
#include "co_math.h"         // math library definition

#if defined(CFG_BT)
#include "rwip_config.h"     // stack configuration
#include "rwbt.h"            // rwbt core
#endif //CFG_BT

#if defined(CFG_BLE)
#if (BLE_EMB_PRESENT)
#include "rwble.h"           // rwble core
#endif // (BLE_EMB_PRESENT)
#endif //CFG_BLE

#if defined(CFG_BT) && defined(CFG_BLE)
#include "rwip.h"            // rw IP core driver
#endif // #if defined(CFG_BT) && defined(CFG_BLE)

#include "icu.h"            // interrupt controller
#include "intc.h"            // interrupt controller

#if PLF_UART
#include "uart.h"            // uart definitions
#endif //PLF_UART

#include "reg_blecore.h"
#include "reg_ipcore.h"

#if(ADC_DRIVER)
#include "adc.h"
#endif

#if(UART0_DRIVER)
#include "uart0.h"
#endif

#if(UART1_DRIVER)
#include "uart1.h"
#endif

#if(AON_RTC_DRIVER)
#include "aon_rtc.h"
#endif

#if (RTC_DRIVER)
#include "rtc.h"
#endif

#if (GPIO_DRIVER)
#include "driver_gpio.h"
#endif
#if (PWM_DRIVER)
#include "pwm.h"
#endif

#if(TIMER0_DRIVER)
#include "timer0.h"
#endif

#if(TIMER1_DRIVER)
#include "timer1.h"
#endif

#if (I2C_DRIVER)    
#include "i2c.h"
#endif

#if (I2S_DRIVER)    
#include "i2s.h"
#endif
#if (SPI_DRIVER)
#include "spi.h"
#endif

#if (IRDA_DRIVER)
#include "irda.h"
#endif

#if (DMA_DRIVER)
#include "dma.h"
#endif
/*
 * DEFINES
 ****************************************************************************************
 */

#define RWBT_INT      CO_BIT(INTC_BT)
#define RWBTDM_INT    CO_BIT(INTC_BTDM)
#define UART_INT      CO_BIT(INTC_UART)
#define UART_2_INT    CO_BIT(INTC_UART_2)

#define RWBLE_INT     CO_BIT(INTC_BLE)
#define RWCOMMON_INT  CO_BIT(INTC_COMMON)
#define TIMER_INT     CO_BIT(INTC_TIMER)


// enable the supported interrupts
#define PLF_INT     (UART_INT | UART_2_INT | TIMER_INT)

#if defined(CFG_BT)
#define BT_INT      (RWBT_INT)
#else
#define BT_INT       0
#endif // #if defined(CFG_BT)

#if defined(CFG_BLE)
#if (BLE_EMB_PRESENT)
#define BLE_INT     (RWBLE_INT)
#else
#define BLE_INT      0
#endif // (BLE_EMB_PRESENT)
#else
#define BLE_INT      0
#endif // #if defined(CFG_BLE)

#if defined(CFG_BT) && defined(CFG_BLE)
#define BTDM_INT    (RWBTDM_INT)
#else
#define BTDM_INT    0
#endif // #if defined(CFG_BT) && defined(CFG_BLE)




/*
 * FUNCTION DEFINITIONS
 ****************************************************************************************
 */
void intc_spurious(void)
{
    // force error
    //ASSERT_ERR(0);
}

void intc_init(void)
{
 
    addSYS_Reg0x11 = 0; // priority; 0: irq  1:fiq

    setf_SYS_Reg0x10_int_uart0_en; //enable uart_int irq

    //setf_SYS_Reg0x10_int_uart1_en; //enable uart_int irq
    //setf_SYS_Reg0x10_int_timer0_en; //enable timer_int irq
    clrf_SYS_Reg0x10_int_timer0_en; //enable timer_int irq
    setf_SYS_Reg0x10_int_rwble_en; //enable int rwble
    setf_SYS_Reg0x10_int_rwdm_en; //enable int rwdm
    setf_SYS_Reg0x10_int_rwbt_en; //enable  rwbt
    setf_SYS_Reg0x11_int_rwble_pri; // 1:fiq
    setf_SYS_Reg0x11_int_rwdm_pri; // 1:fiq
    setf_SYS_Reg0x11_int_rwbt_pri; // 1:fiq
    setf_SYS_Reg0x11_int_dma_pri;
    setf_SYS_Reg0x10_int_dma_en;
//		setf_SYS_Reg0x10_int_pwm1_en;
//    setf_SYS_Reg0x10_int_audio_en;

    setf_SYS_Reg0x10_int_aon_gpio_en;

}


/*__IRQ */void IRQ_Exception(void)
{

    uint32_t IntStat;
    uint32_t irq_status = 0;

    IntStat = addSYS_Reg0x12;
    if(ble_deepslcntl_deep_sleep_stat_getf())    
    {                      
        //uart_printf("i\r\n");
        setf_PMU_Reg0x1_force_rw_wake;
        __nop();
        __nop();
        __nop();
        clrf_PMU_Reg0x1_force_rw_wake;
    }
    
    
#if(TIMER0_DRIVER)
    if(IntStat & INT_STATUS_TMR0_bit)
    {
        irq_status |= INT_STATUS_TMR0_bit;
        timer0_isr();
    }
#endif
    
#if(TIMER1_DRIVER)
    if(IntStat & INT_STATUS_TMR1_bit)
    {
        irq_status |= INT_STATUS_TMR1_bit;
        timer1_isr();
    }
#endif
#if(UART0_DRIVER )
    // call the function handler
    if(IntStat & INT_STATUS_UART0_bit)
    {
        irq_status |= INT_STATUS_UART0_bit;
        UART0_ISR();
    }
#endif
#if(UART1_DRIVER )
    if(IntStat & INT_STATUS_UART1_bit)
    {
        irq_status |= INT_STATUS_UART1_bit;
        UART1_ISR();
    }
#endif

#if (ADC_DRIVER)
   if(IntStat & INT_STATUS_ADC_bit)
    {
       irq_status |= INT_STATUS_ADC_bit;
       adc_isr();
   }
#endif
#if (AON_RTC_DRIVER)
    if(IntStat & INT_STATUS_AON_RTC_bit)
    {
        irq_status |= INT_STATUS_AON_RTC_bit;
        aon_rtc_isr();
    }
#endif

#if (RTC_DRIVER)
        if(IntStat & INT_STATUS_RTC_bit)
        {
            irq_status |= INT_STATUS_RTC_bit;
            rtc_isr();
        }
#endif

#if (GPIO_DRIVER)
    if(IntStat & INT_STATUS_AON_GPIO_bit)
    {
    //uart_printf("EE\n");
        irq_status |= INT_STATUS_AON_GPIO_bit;
        gpio_isr();
    }
#endif
#if (SPI_DRIVER)
    if(IntStat & INT_STATUS_SPI0_bit)
    {
        irq_status |= INT_STATUS_SPI0_bit;
        if(SPI_REG0X0_CFG&(0x01<<22))   //1:master,0:slave
            spi_isr();
        else
            spi_slave_isr();
    }
#endif
#if (I2C_DRIVER)    
    if(IntStat & INT_STATUS_I2C0_bit)
    {
        irq_status |= INT_STATUS_I2C0_bit;
        i2c_isr();
    }
#endif     
#if(I2S_DRIVER)
        if(IntStat & INT_STATUS_I2S_bit)
        {
            irq_status |= INT_STATUS_I2S_bit;
            i2s_isr();
        }
#endif

#if (PWM_DRIVER)
    if(IntStat & INT_STATUS_PWM0_bit)
    {
        irq_status |= INT_STATUS_PWM0_bit;
        pwm0_isr();
    }
    if(IntStat & INT_STATUS_PWM1_bit)
    {
        irq_status |= INT_STATUS_PWM1_bit;
        pwm1_isr();
    }
    
#endif
#if (IRDA_DRIVER)
    if(IntStat & INT_STATUS_IRDA_bit)
    {
        irq_status |= INT_STATUS_IRDA_bit;
        IRDA_ISR();
    }
#endif
    if(IntStat & INT_STATUSS_ESTI_bit)   
    {        
        irq_status |= INT_STATUSS_ESTI_bit;       
        INT_HANDLER_CLKEST();  
    }
   addSYS_Reg0x12 = irq_status;
   addSYS_Reg0xa = 0;

}

void FIQ_Exception(void)
{
    uint32_t IntStat;
    uint32_t fiq_status=0;

    IntStat = addSYS_Reg0x12;

    if(IntStat & INT_STATUS_RWBLE_bit)
    {
        fiq_status |= INT_STATUS_RWBLE_bit;
        //rwble_isr();
        rwip_isr();
    }
    
    #if (BT_DUAL_MODE || BT_STD_MODE) 
    if(IntStat & INT_STATUS_RWDM_bit)
    {
        fiq_status |= INT_STATUS_RWDM_bit;
        rwip_isr();
    }
    if(IntStat & INT_STATUS_RWBT_bit)
    {
        fiq_status |= INT_STATUS_RWBT_bit;
        rwbt_isr();
    } 
    #endif 
    
    #if (DMA_DRIVER)
    if(IntStat & INT_STATUS_DMA_bit)
    {
        fiq_status |= INT_STATUS_DMA_bit;
        dma_isr();
    }
    #endif
    addSYS_Reg0x12 = fiq_status;
}

 

//#pragma ARM//
__IRQ FAST_IRQ_ENTRY  void SYSirq_IRQ_Handler(void)
{

    IRQ_Exception();
    
}

__FIQ FAST_FIQ_ENTRY  void SYSirq_FIQ_Handler(void)
{
    FIQ_Exception();
}

#if 0
void Undefined_Exception(void)
{
    while(1)
    {
        uart_printf("Undefined_Exception\r\n");
    }
}
void SoftwareInterrupt_Exception(void)
{
    while(1)
    {
        uart_printf("SoftwareInterrupt_Exception\r\n");
    }
}
void PrefetchAbort_Exception(void)
{
    while(1)
    {
        uart_printf("PrefetchAbort_Exception\r\n");
    }
}
void DataAbort_Exception(void)
{
    while(1)
    {
        uart_printf("DataAbort_Exception\r\n");
    }
}

void Reserved_Exception(void)
{
    while(1)
    {
        uart_printf("Reserved_Exception\r\n");
    }
}
#endif


