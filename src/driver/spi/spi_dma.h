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

#ifndef _SPI_DMA_H_
#define _SPI_DMA_H_

/* 
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions
#include "dma.h"
void spi_write_dma_init(uint32_t *buff,uint32_t len,DMA_DATA_TYPE dst_data_type,dma_int_cb_t int_cb);

void spi_dma_write(uint32_t *buff,uint32_t len,uint32_t type,spi_write_cb result_callback);
void spi_dma_read(uint8_t *buffer,uint16_t buffer_len,spi_read_cb result_callback);
void spi_dma_write_result_callback(void);
void spi_dma_read_result_callback(void);
void spi_dma_test(void);
void spi_dma_stop(void);

/// @} UART
#endif /* _UART_H_ */
