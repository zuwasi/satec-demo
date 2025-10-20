/**
 ****************************************************************************************
 *
 * @file arch_main.c
 *
 * @brief Main loop of the application.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */


/*
 * INCLUDES
 ****************************************************************************************
 */
 
#include "rwip_config.h" // RW SW configuration


#include "arch.h"      // architectural platform definitions
#include <stdlib.h>    // standard lib functions
#include <stddef.h>    // standard definitions
#include <stdint.h>    // standard integer definition
#include <stdbool.h>   // boolean definition
#include "boot.h"      // boot definition
#include "rwip.h"      // RW SW initialization
#include "user_config.h"
#include "intc.h"      // Interrupt initialization
#include "dbg.h"
#include "icu.h"
#if PLF_UART
#include "uart.h"  
#endif
/**
 ****************************************************************************************
 * @addtogroup DRIVERS
 * @{
 *
 *
 * ****************************************************************************************
 */

/*
 * DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINITIONS
 ****************************************************************************************
 */

/// Description of unloaded RAM area content
struct unloaded_area_tag
{
    // status error
    uint32_t error;
};


/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */




#if (PLF_DEBUG)
/// Variable to enable infinite loop on assert
volatile int dbg_assert_block = 1;
#endif //PLF_DEBUG

/// Pointer to access unloaded RAM area
struct unloaded_area_tag* unloaded_area;



uint32_t critical_sec_cnt = 0;
/*
 * LOCAL FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */


/*
 * EXPORTED FUNCTION DEFINITIONS
 ****************************************************************************************
 */

#if (PLF_DEBUG)
void assert_err(const char *condition, const char * file, int line)
{
    TRC_REQ_SW_ASS_ERR(file, line, 0, 0);


    GLOBAL_INT_STOP();

    while(dbg_assert_block);
}

void assert_param(int param0, int param1, const char * file, int line)
{
    TRC_REQ_SW_ASS_ERR(file, line, param0, param1);


    GLOBAL_INT_STOP();
    while(dbg_assert_block);
}

void assert_warn(int param0, int param1, const char * file, int line)
{
    TRC_REQ_SW_ASS_WARN(file, line, param0, param1);

  
}

#endif //PLF_DEBUG


#if (RW_DEBUG_STACK_PROF)
void stack_init(void)
{
   uint8_t* ptr = (uint8_t*)&ptr;
   while ((uint32_t)ptr > (uint32_t)STACK_BASE_SVC)
       *--ptr = BOOT_PATTERN_SVC;
}

uint16_t get_stack_usage(void)
{
    uint8_t *ptr = (uint8_t*)(STACK_BASE_SVC);

    while(*ptr++ == BOOT_PATTERN_SVC);

    return (uint16_t)((uint32_t)STACK_BASE_SVC + (uint32_t)STACK_LEN_SVC - (uint32_t)ptr);
}
#endif //(RW_DEBUG_STACK_PROF)

void platform_reset(uint32_t error)
{
   // void (*pReset)(void);

    // Disable interrupts
    GLOBAL_INT_STOP();

    #if PLF_UART
    // Wait UART transfer finished
    uart_finish_transfers();
    #if !(BLE_EMB_PRESENT) && !(BT_EMB_PRESENT)
    uart2_finish_transfers();
    #endif // !BLE_EMB_PRESENT && !(BT_EMB_PRESENT)
    #endif //PLF_UART

    // Store information in unloaded area
    unloaded_area->error = error;

    if(error == RESET_AND_LOAD_FW || error == RESET_TO_ROM)
    {
        // Not yet supported
    }
    else
    {

        uart_printf("platform_reset :%x\r\n",error);
        cpu_reset();
        while(1);

    }
}




/// @} DRIVERS
