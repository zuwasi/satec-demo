/**
 ****************************************************************************************
 *
 * @file uart.c
 *
 * @brief UART driver
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup UART
 * @{
 ****************************************************************************************
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stddef.h>     // standard definition
#include "uart.h"       // uart definition
#ifndef CFG_ROM
#include "rwip.h"       // SW interface
#if (PLF_NVDS)
#include "nvds.h"       // NVDS
#endif // (PLF_NVDS)
#endif // CFG_ROM

#include "dbg.h"
#include "arch.h"
#include "user_config.h"
#include "BK3437_RegList.h"
#include "BK3437_Config.h"
#include <string.h>
 
extern int DbgPrintf(const char *fmt,...);

extern void uart0_send(void *buff, uint16_t len);
/*
 * DEFINES
 *****************************************************************************************
 */

/// Max baudrate supported by this UART (in bps)
#define UART_BAUD_MAX      3500000
/// Min baudrate supported by this UART (in bps)
#define UART_BAUD_MIN      9600

/// Duration of 1 byte transfer over UART (10 bits) in us (for 921600 default baudrate)
#define UART_CHAR_DURATION        11

#if (VIRTUAL_UART_H4TL == 1)

    ////
    ////#define UART_TXRX_BUF_SIZE        128
    #define HCI_DATA_BUF_SIZE        128//256            ////256        ////128
    #define HCI_DATA_TYPE_CMD        0x01
    #define HCI_DATA_TYPE_EVENT        0x02
#endif
/*
 * ENUMERATION DEFINITIONS
 *****************************************************************************************
 */

///UART Character format
enum UART_CHARFORMAT
{
    UART_CHARFORMAT_8 = 0,
    UART_CHARFORMAT_7 = 1
};

///UART Stop bit
enum UART_STOPBITS
{
    UART_STOPBITS_1 = 0,
    UART_STOPBITS_2 = 1 /* Note: The number of stop bits is 1.5 if a character format
                                 with 5 bit is chosen*/
};

///UART Parity enable
enum UART_PARITY
{
    UART_PARITY_DISABLED = 0,
    UART_PARITY_ENABLED  = 1
};

///UART Parity type
enum UART_PARITYBIT
{
    UART_PARITYBIT_EVEN  = 0,
    UART_PARITYBIT_ODD   = 1,
    UART_PARITYBIT_SPACE = 2, // The parity bit is always 0.
    UART_PARITYBIT_MARK  = 3  // The parity bit is always 1.
};

///UART HW flow control
enum UART_HW_FLOW_CNTL
{
    UART_HW_FLOW_CNTL_DISABLED = 0,
    UART_HW_FLOW_CNTL_ENABLED = 1
};

///UART Input clock select
enum UART_INPUT_CLK_SEL
{
    UART_INPUT_CLK_SEL_0 = 0,
    UART_INPUT_CLK_SEL_1 = 1,
    UART_INPUT_CLK_SEL_2 = 2,
    UART_INPUT_CLK_SEL_3 = 3
};

///UART Interrupt enable/disable
enum UART_INT
{
    UART_INT_DISABLE = 0,
    UART_INT_ENABLE = 1
};

///UART Error detection
enum UART_ERROR_DETECT
{
    UART_ERROR_DETECT_DISABLED = 0,
    UART_ERROR_DETECT_ENABLED  = 1
};

/*
 * STRUCT DEFINITIONS
 *****************************************************************************************
 */
/* TX and RX channel class holding data used for asynchronous read and write data
 * transactions
 */
/// UART TX RX Channel
struct uart_txrxchannel
{
    /// call back function pointer
    void (*callback) (void*, uint8_t);
    /// Dummy data pointer returned to callback when operation is over.
    void* dummy;
};

/// UART environment structure
struct uart_env_tag
{
    /// tx channel
    struct uart_txrxchannel tx;
    /// rx channel
    struct uart_txrxchannel rx;
    /// error detect
    uint8_t errordetect;
    /// external wakeup
    bool ext_wakeup;
    //// Modified
    uint8_t *uart_tx_buf;
    uint8_t *uart_rx_buf;
    uint32_t uart_tx_length;
    uint32_t uart_rx_length;
    uint8_t uart_tx_enable;        ////Maybe no need
    uint8_t uart_rx_enable;        ////Maybe no need
};
#if (VIRTUAL_UART_H4TL == 1)

    //// HCI CMD, Event
    struct hci_cmd_event_data
    {
        /// call back function pointer
        void (*callback) (void*, uint16_t);
        /// Dummy data pointer returned to callback when operation is over.
        uint8_t data_buf[HCI_DATA_BUF_SIZE];
        uint32_t data_len;
    };
#endif

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */
/// uart environment structure
#if (1)
    volatile static struct uart_env_tag uart_env;
#endif
#if (VIRTUAL_UART_H4TL == 1)
    volatile struct hci_cmd_event_data host_cmd_data;
    volatile struct hci_cmd_event_data host_event_data;
#endif
/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */
#if (VIRTUAL_UART_H4TL == 1)
    uint8_t app_role = 'N';
    void set_app_role(uint8_t rol)
    {
        app_role = rol;
    }

void hci_data_init(uint8_t type)
{    ////type: 0x01-Clear host cmd data; 0x02-Clear host event data
  //  uart_printf("%s,type:%x\r\n",__func__,type);
    if(type & HCI_DATA_TYPE_CMD)
    {
        host_cmd_data.callback = NULL;
        memset((void *)&host_cmd_data.data_buf[0], 0, HCI_DATA_BUF_SIZE);
        host_cmd_data.data_len = 0;
    }
    if(type & HCI_DATA_TYPE_EVENT)
    {
    ////    host_event_data.callback = NULL;        ////Will clear callback func
        memset((void *)&host_event_data.data_buf[0], 0, HCI_DATA_BUF_SIZE);
        host_event_data.data_len = 0;
    }
}

void host_send_cmd(uint8_t *bufptr, uint16_t length)
{
    uart_printf("%s,len:%d\r\n",__func__,length);
    uint16_t tmpCnt = 0;
//    ASSERT_ERR(length >= HCI_DATA_BUF_SIZE)
    host_cmd_data.callback = NULL;        ////Test Only
    memcpy((void *)&host_cmd_data.data_buf[0], bufptr, length);
    host_cmd_data.data_len = length;

   // uart_printf("host_send_cmd(%C):", app_role);
    if(length >= 20)
        length = 20;
    ////for(tmpCnt = 0; tmpCnt < host_cmd_data.data_len; tmpCnt++)
    uart_printf("0x");
    for(tmpCnt = 0; tmpCnt < length - 1; tmpCnt++)
    {
        
        uart_printf("%02X:", host_cmd_data.data_buf[tmpCnt]);
        
    }
    uart_printf("%02X", host_cmd_data.data_buf[tmpCnt]);
    uart_printf("\r\n");
}

void host_get_event(void)
{
    uint8_t tmpLen = host_event_data.data_len;
//    printf("GetEvent(%C):", app_role);
 //   uart_printf("host_get_event\r\n");
    if(tmpLen >= 20)
        tmpLen = 20;
    
  /*  uart_printf("0x");
    for(tmpCnt = 0; tmpCnt < tmpLen - 1; tmpCnt++)
    {
        
        uart_printf("%02X:", host_event_data.data_buf[tmpCnt]);
        
    }
    uart_printf("%02X", host_event_data.data_buf[tmpCnt]);
    uart_printf("\r\n");*/
    if(host_event_data.callback != NULL)
    {
        host_event_data.callback((void *)host_event_data.data_buf, host_event_data.data_len);
    }
    hci_data_init(HCI_DATA_TYPE_EVENT);
}

void host_get_event_cbReg(void (*callback) (void*, uint16_t))
{
    host_event_data.callback = callback;
}

    const uint8_t poki_test_cmd[] =
    #if 1
        ////{ 0x01, 0x0E, 0x08};
        { 0x01, 0x13, 0x0C, 248, 0x30, 0x31, 0x32, 0x33, 0x34, 0x00, 0, 0,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
    #else
        { 0x01, 0x0B, 0X04, 0X16, 0X77, 0X89, 0X39, 0X98, 0X22,            ////HCI_Link_Key_Request_Reply
          0X00, 0X54, 0X0B, 0X3F, 0X42, 0XF8, 0X38, 0XEE, 0X90,
          0X09, 0XBC, 0X1D, 0X1C, 0X1E, 0XD1, 0XE2, 0X61        };
    #endif
    const uint8_t poki_test_cmd2[] =
        {
            0x01, 0x14, 0x0C, 0x00        ////Read Local Name
        ////0x01, 0x0E, 0x08, 0x00        ////Read Link Policy
        };

    extern uint8_t HCI_CMD_CREATE_CONN[17];
    extern uint8_t HCI_CMD_READ_BD_ADDR[4];
#endif

/*
 * EXPORTED FUNCTION DEFINITIONS
 ****************************************************************************************
 */

void uart_init(void)
{
#if (VIRTUAL_UART_H4TL == 1)        ////

    //// Initialize RX and TX transfer callbacks
    uart_env.rx.callback = NULL;
    uart_env.tx.callback = NULL;
    uart_env.uart_tx_buf = NULL;
    uart_env.uart_rx_buf = NULL;
    uart_env.uart_tx_length = 0;
    uart_env.uart_rx_length = 0;
    uart_env.uart_tx_enable = 0;
    uart_env.uart_rx_enable = 0;

    hci_data_init((HCI_DATA_TYPE_CMD | HCI_DATA_TYPE_EVENT));
    host_get_event_cbReg(uart0_send);
#endif

}

void uart_flow_on(void)
{
#if 0        ////
    // Configure modem (HW flow control enable)
    uart_force_rts_setf(0);
#endif
}

bool uart_flow_off(void)
{
    bool flow_off = true;

    return flow_off;
}

void uart_finish_transfers(void)
{

}

void uart_read(uint8_t *bufptr, uint32_t size, void (*callback) (void*, uint8_t), void* dummy)
{    ////Register Read callback func, write buf ptr, data size
#if (VIRTUAL_UART_H4TL == 1)        ////
    
    ASSERT_ERR(bufptr != NULL);
    ASSERT_ERR(size != 0);
    ASSERT_ERR(callback != NULL);
    uart_env.rx.callback = callback;
    uart_env.rx.dummy    = dummy;

    uart_env.uart_rx_buf = bufptr;    
    uart_env.uart_rx_length = size; 
    uart_env.uart_rx_enable = 1;    
#endif 

}

void uart_write(uint8_t *bufptr, uint32_t size, void (*callback) (void*, uint8_t), void* dummy)
{    ////Register Read callback func, write buf ptr, data size
 //   uart_printf("%s\r\n",__func__);
#if (VIRTUAL_UART_H4TL == 1)        ////
    // Sanity check
    ASSERT_ERR(bufptr != NULL);
    ASSERT_ERR(size != 0);
    ASSERT_ERR(callback != NULL);
    uart_env.tx.callback = callback;
    uart_env.tx.dummy    = dummy;

    uart_env.uart_tx_buf = bufptr;
    uart_env.uart_tx_length = size;
    uart_env.uart_tx_enable = 1;

#endif
}

#if (VIRTUAL_UART_H4TL == 1)
void uart_h4tl_data_switch(void)
{
        
    void (*callback) (void*, uint8_t) = NULL;
    void* data =NULL;
    uint16_t data_len = 0;
    while(uart_env.uart_tx_enable == 1)
    {
    //printf("uart_h4tl_data_switch tx_enable\r\n");
        // Retrieve callback pointer
        callback = uart_env.tx.callback;
        data     = uart_env.tx.dummy;

        uart_env.uart_tx_enable = 0;
        memcpy((void *)&host_event_data.data_buf[data_len], uart_env.uart_tx_buf, uart_env.uart_tx_length);
        data_len += uart_env.uart_tx_length;
        host_event_data.data_len += uart_env.uart_tx_length;
        if(callback != NULL)
        {
            // Clear callback pointer
            uart_env.tx.callback = NULL;
            uart_env.tx.dummy    = NULL;

            // Call handler
            callback(data, RWIP_EIF_STATUS_OK);
        }
        else
        {
            ASSERT_ERR(0);
        }
    }
    if(host_event_data.data_len != 0)
    {    ////New Event
        host_get_event();           
    }

    data_len = 0;
    
    if(host_cmd_data.data_len > 0)
    {
        uart_printf("host_cmd_data.data_len:%d\r\n",host_cmd_data.data_len);
            
        while(uart_env.uart_rx_enable == 1)
        {
            uart_printf("uart_rx_length:%d data_len:%d\r\n",uart_env.uart_rx_length,data_len);
            // Retrieve callback pointer
            callback = uart_env.rx.callback;
            data     = uart_env.rx.dummy;

            uart_env.uart_rx_enable = 0;
            
            
            memcpy((void *)uart_env.uart_rx_buf, (void *)&host_cmd_data.data_buf[data_len], uart_env.uart_rx_length);
                for(int i = 0; i < uart_env.uart_rx_length;i++)
            {
                uart_printf("%02x ",uart_env.uart_rx_buf[i]);
            }
            uart_printf("\r\n");
   
            data_len += uart_env.uart_rx_length;
            
            if(callback != NULL)
            {
                // Clear callback pointer
                uart_env.rx.callback = NULL;
                uart_env.rx.dummy    = NULL;

                // Call handler
                callback(data, RWIP_EIF_STATUS_OK);
            }
            else
            {
                ASSERT_ERR(0);
            }
            if(data_len >= host_cmd_data.data_len)
                break;
        }////while(uart_env.uart_rx_enable == 1)
        if(data_len != host_cmd_data.data_len)
        {
            uart_printf("HCI_CMD_WriteErr,data_len:%d,%d\r\n,",data_len,host_cmd_data.data_len);
        }
        ////else
        {    ////Clear HCI Cmd data
            hci_data_init(HCI_DATA_TYPE_CMD);
        }

    }////if(host_cmd_data.data_len > 0)

}
#endif

extern    volatile uint32_t uart_rx_index;
extern uint8_t uart_rx_buf[UART_RX_FIFO_MAX_COUNT];
extern uint8_t uart_tx_buf[UART_TX_FIFO_MAX_COUNT];

void uart_isr(void)
{

    if((uart_rx_buf[0] == 0x01) && ((uart_rx_buf[3] + 4) == uart_rx_index))
    {
        uart_printf("cmd len:%d,uart_rx_index:%d,\r\n",uart_rx_buf[3],uart_rx_index);
        host_send_cmd(uart_rx_buf, uart_rx_index);
        uart_rx_index = 0;
    }           

}
/// @} UART
