/**
 ****************************************************************************************
 *
 * @file spi.h
 *
 * @brief SPI Driver for SPI operation.
 *
 * Copyright (C) Beken 2009-2015
 *
 *
 ****************************************************************************************
 */

#ifndef _IRDA_H_
#define _IRDA_H_

/* 
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions

#define IRDA_BUFFER_COUNT 100
extern uint8_t irda_power_on;
void tx_irda_intial(uint8_t clk,uint8_t duty,uint8_t period);
void rx_irda_intial(uint8_t clk,uint16_t timeout,uint16_t thr,uint8_t glitch,uint8_t fifo_count);
void start_tx_irda(void);
void IRDA_ISR(void);
void irda_power_down(void);
void irda_init(void);

void IRDA_TEST(uint8_t mode );
void irda_send(uint16_t *databuffer,uint8_t bufferlen);
void irda_receive(void);

/// @} UART
#endif /* _UART_H_ */
