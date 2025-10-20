/**
 ****************************************************************************************
 *
 * @file uart1.h
 *
 * @brief UART Driver for HCI over UART operation.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

#ifndef _DRIVER_UART1_H_
#define _DRIVER_UART1_H_

/**
 ****************************************************************************************
 * @defgroup UART UART
 * @ingroup DRIVERS
 * @brief UART driver
 *
 * @{
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions
#include "BK3437_Config.h"

//#include "user_config.h"      ////
/*
 * ENUMERATION DEFINITIONS
 *****************************************************************************************
 */

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initializes the UART to default values.
 *****************************************************************************************
 */


#define UART_CLK_FREQ               16
#define NCV_SIM                     0x1
#define UART1_FIFO_MAX_COUNT        128


extern volatile uint8_t  uart1_rx_done ;
extern volatile uint32_t uart1_rx_index ;

//extern uint8_t uart1_rx_buf[UART1_FIFO_MAX_COUNT];
//extern uint8_t uart1_tx_buf[UART1_FIFO_MAX_COUNT];

void uart1_isr(void);

void uart1_init(unsigned int baud);

int uart1_printf(const char *fmt,...);
void uart1_test(void);
void UART1_ISR(void);

void uart1_close(void);
void uart1_start(void);

/// @} UART
#endif /* _UART1_H_ */
