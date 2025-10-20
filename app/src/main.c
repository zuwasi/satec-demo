/**
 ****************************************************************************************
 *
 * @file main.c
 *
 * @brief Main loop of the application.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */
#include "rwip_config.h" // RW SW configuration
#include "arch.h"      // architectural platform definitions
#include <stdlib.h>    // standard lib functions
#include <stddef.h>    // standard definitions
#include <stdint.h>    // standard integer definition
#include <stdbool.h>   // boolean definition
#include <string.h>   // boolean definition
#include "rwip.h"      // RW SW initialization
#include "prf.h"      // RW SW initialization
#include "prf_utils.h"      // RW SW initialization
#include "rwble.h"
#include "BK3437_RegList.h"
#include "bsp.h"
#include "intc.h"      // Interrupt initialization
#if PLF_UART
#include "uart.h"      // UART initialization
#endif 
#include "driver_flash.h"     // Flash initialization
//#include "led.h"       // Led initialization
#if (BLE_EMB_PRESENT || BT_EMB_PRESENT)
#include "rf.h"        // RF initialization
#endif 

#if (BLE_APP_PRESENT)
#include "app.h"       // application functions
#endif
#if(AON_RTC_DRIVER)
#include "aon_rtc.h"
#endif
#if (NVDS_SUPPORT)
#include "nvds.h"         // NVDS definitions
#endif
#include "reg_access.h"
#include "dbg.h"
#include "user_config.h"
#include "co_utils.h" 
#include "wdt.h"
#include "uart0.h"
#include "uart1.h"
#include "rf.h"
#include "driver_gpio.h"
#include "adc.h"
#include "icu.h"
#include "app_task.h"
#include "rwip.h"
#include "boot.h"
#include "rf_xvr.h"
#include "hci.h"
#include "oads_common.h"
#include "spi_to_rgb_tc1903.h"
#include "spi_to_rgb_ws2812.h"
#if (TIMER0_DRIVER)
#include "timer0.h"
#endif
#if(SPI_DRIVER)
#include "spi.h"
#if(SPI_DMA_MODE) 
#include "spi_dma.h"
#endif
#endif
#if (I2S_DRIVER)
#include "i2s.h"
#endif

 
static void stack_integrity_check(void)
{
    if ((REG_PL_RD(STACK_BASE_UNUSED)!= BOOT_PATTERN_UNUSED))
    {
        while(1)
        {
            uart_printf("Stack_Integrity_Check STACK_BASE_UNUSED fail!\r\n");
        }
    }

    if ((REG_PL_RD(STACK_BASE_SVC)!= BOOT_PATTERN_SVC))
    {
        while(1)
        {
            uart_printf("Stack_Integrity_Check STACK_BASE_SVC fail!\r\n");
        }
    }

    if ((REG_PL_RD(STACK_BASE_FIQ)!= BOOT_PATTERN_FIQ))
    {
        while(1)
        {
            uart_printf("Stack_Integrity_Check STACK_BASE_FIQ fail!\r\n");
        }
    }

    if ((REG_PL_RD(STACK_BASE_IRQ)!= BOOT_PATTERN_IRQ))
    {
        while(1)
        {
            uart_printf("Stack_Integrity_Check STACK_BASE_IRQ fail!\r\n");
        }
    }

}

static void rom_env_init(struct rom_env_tag *api)
{
    extern void IRQ_Exception(void);
    extern void FIQ_Exception(void);

    //void(*assert_err) (const char *condition, const char * file, int line);
    //void(*assert_param)(int param0, int param1, const char * file, int line);
    //void (*assert_warn)(int param0, int param1, const char * file, int line);

    //uint8_t (*Read_Uart_Buf)(void);    
    //void (*uart_clear_rxfifo)(void);

    uart_printf("rom_env_init\r\n");
    memset(&rom_env,0,sizeof(struct rom_env_tag));
    rom_env.prf_msg_api_init = prf_msg_api_init;
    rom_env.prf_con_param_upd = prf_con_param_upd;
    rom_env.prf_init = prf_init;
    rom_env.prf_con_create = prf_con_create;
    rom_env.prf_con_cleanup = prf_con_cleanup;
    rom_env.prf_add_profile = prf_add_profile;

    rom_env.rwip_reset = rwip_reset;
    rom_env.platform_reset = platform_reset;
    //rom_env.assert_err = assert_err;
    //rom_env.assert_param = assert_param;
    //rom_env.Read_Uart_Buf = Read_Uart_Buf;
    //rom_env.uart_clear_rxfifo = uart_clear_rxfifo;
    rom_env.stack_printf = uart_printf;
    rom_env.kmod_fm_gain_set_1M = kmod_fm_gain_set_1M;
    rom_env.kmod_fm_gain_set_2M = kmod_fm_gain_set_2M;
    rom_env.gpio_toggle = gpio_toggle;	
    rom_env.fcc_hopping = fcc_hopping;
  //  rom_env.FIQ_Exception = FIQ_Exception;
  //  rom_env.IRQ_Exception = IRQ_Exception;
    //rom_env.gpio_set_neg = gpio_set_neg;
}   
             
/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */
#if PLF_UART        ////Added
// Creation of uart external interface api
const struct rwip_eif_api uart_api =
{
    uart_read,
    uart_write,
    uart_flow_on,
    uart_flow_off,
};
#endif

void ble_name_addr_env_init(void)
{
    struct bd_addr co_bdaddr;
    uint8_t ble_name[30];
    uint8_t i;
    
    co_default_bdaddr.addr[0]=0x32;
    co_default_bdaddr.addr[1]=0x53;
    co_default_bdaddr.addr[2]=0x74;
    co_default_bdaddr.addr[3]=0x56;
    co_default_bdaddr.addr[4]=0x78;
    co_default_bdaddr.addr[5]=0x9a;
    
    flash_read(0xff8,6,&co_bdaddr.addr[0]);
    if(co_bdaddr.addr[0]!=0xff ||co_bdaddr.addr[1]!=0xff||
    co_bdaddr.addr[2]!=0xff||co_bdaddr.addr[3]!=0xff||
    co_bdaddr.addr[4]!=0xff||co_bdaddr.addr[5]!=0xff )
    {
        memcpy(&co_default_bdaddr,&co_bdaddr,6);
    }      
    uart_printf("default_bdaddr:");
    for( i = 0; i < 6 ; i++)
    {
        uart_printf("%02x ",co_default_bdaddr.addr[i]);
    }
    uart_printf("\r\n");

    flash_read(0xfd0,30,&ble_name[0]);
    for(i=0;i<APP_DEVICE_NAME_MAX_LEN;)
    {
        if(ble_name[i]!=0xff)
            i++;
        else
            break;
    }
    // Reset the application manager environment
    memset(&app_env, 0, sizeof(app_env));

    if(i != 0)
    {
        app_env.dev_name_len = i;
        memcpy(app_env.dev_name, ble_name, i);
    }
    else
    {
        memcpy(app_env.dev_name, APP_DFLT_DEVICE_NAME, APP_DFLT_DEVICE_NAME_LEN);
        app_env.dev_name_len = APP_DFLT_DEVICE_NAME_LEN;
    }
    uart_printf("ble_name:%s,name_len=%d\r\n",app_env.dev_name,i);
} 
  

#if (PLF_DEBUG)
void assert_err(const char *condition, const char * file, int line)
{
    uart_printf("%s,condition %s,file %s,line = %d\r\n",__func__,condition,file,line);
}

void assert_param(int param0, int param1, const char * file, int line)
{
    uart_printf("%s,param0 = %d,param1 = %d,file = %s,line = %d\r\n",__func__,param0,param1,file,line);
}

void assert_warn(int param0, int param1, const char * file, int line)
{
    uart_printf("%s,param0 = %d,param1 = %d,file = %s,line = %d\r\n",__func__,param0,param1,file,line);
}

void dump_data(uint8_t* data, uint16_t length)
{
    uart_printf("%s,data = %d,length = %d,file = %s,line = %d\r\n",__func__,data,length);
}

#endif //PLF_DEBUG

 
extern uint8_t system_mode;
void sys_mode_init(uint8_t mode)
{
    system_mode = mode;
}
uint8_t get_sys_mode(void)
{
    return system_mode;
}
void enter_dut_fcc_mode(void)
{
    while(1)
    {
        // schedule all pending events
        rwip_schedule();
        #if (VIRTUAL_UART_H4TL == 1)
        uart_h4tl_data_switch();
        #endif
    }
}

int main(void)
{ 
    clrf_SYS_Reg0x0_jtag_mode;
    wdt_disable();
    wdt1_disable();
    uart_printf("sys reset reason:%x\r\n",get_PMU_Reg0x0_reset_reason);
    /**
     * @brief print the RWIP Firmware Info;
     */
    #if 1
    {
        extern uint8_t uart1_rx_buf[UART_RX_FIFO_MAX_COUNT];
        extern uint8_t get_stack_FW_version(char *fw_ver);
        get_stack_FW_version((char*)uart1_rx_buf);
        uart_printf("+------------------------+\r\n");
        uart_printf("| %s |\r\n",uart1_rx_buf);
        uart_printf("+------------------------+\r\n");
    }
    #endif
    icu_init();
    xvr_reg_initial();
    
    
    sys_mode_init(NORMAL_MODE);
//    sys_mode_init(DUT_FCC_MODE);
		
    mcu_clk_switch(MCU_CLK_16M);
    gpio_init(); 

    uart0_init(1000000);
    //uart1_init(1000000);
//		while(1);
    flash_init();
    uart_printf("gpio_init: dut mod= %d \r\n", get_sys_mode()); 

		init_bsp();
    #if (PLF_NVDS) 
    // Initialize NVDS module
    nvds_init();
    #endif // PLF_NVDS

    ble_name_addr_env_init(); 
    #if SDADC_CALI_DATA_AT_OTP 
    adc_get_calibration();
    #endif
    rom_env_init(&rom_env);

    uart_printf("rw_main start EM_BLE_END = 0x%x \r\n",EM_BLE_END);
    clrf_SYS_Reg0x3_rwbt_pwd;

    // Initialize the Interrupt Controller
    intc_init();
    // Initialize UART component
    #if PLF_UART
    uart_init();
    #endif //PLF_UART

    #if(AON_RTC_DRIVER)
    aon_rtc_init();
    #endif
   
    rwip_init(0);
    uart_printf("rwip_init\r\n");
    
    #if (I2S_DRIVER)
    i2s_init(0,32000,16,1);
    #endif

    // finally start interrupt handling
    GLOBAL_INT_START();

    #if (DEBUG_BKREG == 1)
    set_sleep_mode(MCU_NO_SLEEP);
    #else
    set_sleep_mode(MCU_LOW_POWER_SLEEP);
    #endif

    if((system_mode & DUT_FCC_MODE) == DUT_FCC_MODE) //dut mode
    {
        uart_printf("enter_dut_fcc_mode \r\n");
        GLOBAL_INT_START();
        set_power(0x07);
        uart0_init(115200);
        mcu_clk_switch(MCU_CLK_32M);
        enter_dut_fcc_mode();
    }
    else 
    {
        #if (CONFIG_RF_GPIO_DEBUG==1)
        rf_debug_gpio_init(0);
        #endif
        #if (TIMER0_DRIVER)
        timer0_init(TIMER_CLK_32K,0, 0, 1, 2000, timer0_0_isr_vbat);//units 0.5ms,totoal 3000ms
        #endif
        wdt_enable(0xffff);//2s
        
        #if (SPI_TO_RGB_1903)
        spi_to_rgb_1903_init();
        spi_to_rgb_1903_test();
        #elif(SPI_TO_RGB_2812)
        spi_to_rgb_2812_init();
        spi_to_rgb_2812_test();
        #endif
        
        #if (I2S_DMA_DRIVER)
        test_i2s_dma();
        set_sleep_mode(MCU_NO_SLEEP);
        #endif

        while(1)
        {
            rwip_schedule();
            oad_updating_user_section_pro();
						main_loop();
            if( NORMAL_MODE==get_sys_mode() )
            {
                // Checks for sleep have to be done with interrupt disabled
                GLOBAL_INT_DISABLE();
                
                // Check if the processor clock can be gated
                switch(rwip_sleep())
                {
                    case RWIP_LOW_POWER_SLEEP:
                    {                      
                        if(MCU_LOW_POWER_SLEEP==get_sleep_mode())
                        {
                            cpu_low_power_sleep();
                        }
                        else if(MCU_IDLE_SLEEP==get_sleep_mode())
                        {
                            cpu_idle_sleep();
                        }
                        else if(MCU_DEEP_SLEEP==get_sleep_mode())
                        {
                            deep_sleep();
                        }                                                  
                    }
                    break;
                    case RWIP_CPU_IDLE:
                    {                        
                        cpu_idle_sleep();                       
                    }
                    break;
                    case RWIP_DEEP_SLEEP:
                    {
                        deep_sleep();
                    }
                    break;
                    default:
                    break;
                }
                
                // Checks for sleep have to be done with interrupt disabled
                GLOBAL_INT_RESTORE();
                
                stack_integrity_check();
            }
            //wdt_feed();

            #if (CONF_AUTO_TEST)
            extern void handle_auto_test_data(void);
            sys_mode_init(AUTO_TEST_MODE);
            handle_auto_test_data();
            #endif
        }
    }
}

const struct rwip_eif_api* rwip_eif_get(uint8_t idx)
{
    const struct rwip_eif_api* ret = NULL;
    switch(idx)
    {
        #if PLF_UART
        case 0:
        {
            ret = &uart_api;
        }
        break;
        #endif
        default:
        {
            ASSERT_INFO(0, idx, 0);
        }
        break;
    }
    return ret;
}

 

