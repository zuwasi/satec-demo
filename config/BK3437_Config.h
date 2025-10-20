#ifndef _BK3437_CONFIG_H_
#define _BK3437_CONFIG_H_

#include "BK3437_RegList.h"

#if defined(__CC_ARM)

typedef unsigned char               uint8;
typedef unsigned short int          uint16;
typedef unsigned int                uint32;
typedef unsigned long long          uint64;
typedef unsigned char               uint8_t;
typedef unsigned int                uint32_t;
typedef unsigned long long          uint64_t;
#endif
typedef unsigned short int          uint16_t;
typedef short int                   int16_t;



#define NCV_SIM                     0x1
#define TEST_ID_MAX                 100
#define TRUE                        0x1
#define FALSE                       0x0
#define TX                          0x0
#define RX                          0x1

#define UART_RX_FIFO_MAX_COUNT      18
#define UART_TX_FIFO_MAX_COUNT      18


void uart_wait_tx_finish(void);
void cpu_delay( volatile unsigned int times);

#define printf                   uart_printf
#define WaitUartTx               uart_wait_tx_finish
typedef struct DbgPrtBuf
{
    uint16_t    pos_sta ;
    uint16_t    pos_end ;
    char        buf[12]   ;
} DbgPrtBuf_t;


#define REG_READ(addr)          *((volatile uint32_t *)(addr))
#define REG_WRITE(addr, _data)  (*((volatile uint32_t *)(addr)) = (_data))



#endif
