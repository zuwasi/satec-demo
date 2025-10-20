/**
 ****************************************************************************************
 *
 * @file uart0.h
 *
 * @brief UART0 Driver for HCI over UART operation.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

#ifndef _UART0_H_
#define _UART0_H_

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
void uart0_init(uint32_t baud_rate);



/**
 ****************************************************************************************
 * @brief Serves the data transfer interrupt requests.
 *
 * It clears the requests and executes the appropriate callback function.
 *****************************************************************************************
 */
void UART0_ISR(void);


void uart0_send(void *buff, uint16_t len);

int uart0_printf(const char *fmt,...);
int uart_printf_null(const char *fmt,...);

void TRAhcit_UART_Rx(void);

/// @} UART
#endif /* _UART_H_ */
