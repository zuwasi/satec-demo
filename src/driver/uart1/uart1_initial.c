#include "stdio.h"
#include "string.h"
#include "BK3437_RegList.h"
#include "BK3437_Config.h"
#include "BK_HCI_Protocol.h"
#include "uart0.h"
#include "uart1.h"
#include "user_config.h"
#include "driver_gpio.h"
#include "icu.h"
#include "uart.h"
#include "hci.h"
#include "reg_access.h"


volatile uint8_t uart1_rx_done = FALSE;
volatile uint32_t uart1_rx_index = 0;
extern volatile uint32_t XVR_ANALOG_REG_BAK[32];

uint8_t uart1_rx_buf[UART_RX_FIFO_MAX_COUNT];
uint8_t uart1_tx_buf[UART_TX_FIFO_MAX_COUNT];
void uart1_close(void)
{
    setf_SYS_Reg0x3_uart1_pwd;
}
void uart1_start(void)
{
    clrf_SYS_Reg0x3_uart1_pwd;
}
HCI_COMMAND_PACKET *pHCIrxBuf1 = (HCI_COMMAND_PACKET *)(&uart1_rx_buf[0]);
HCI_EVENT_PACKET   *pHCItxBuf1 = (HCI_EVENT_PACKET *)(&uart1_tx_buf[0]);
void uart1_send(void *buff, uint16_t len);
void uart1_init(unsigned int baud)
{
    uint32_t    uart_clk_div;
    clrf_SYS_Reg0x3_uart1_pwd ;   //open periph
    uart_clk_div = (UART_CLK_FREQ*1000000)/baud - 1;
    addSYS_Reg0x30 = 0x11111100;
    gpio_config(0x2,SC_FUN,PULL_HIGH);
    gpio_config(0x3,SC_FUN,PULL_HIGH);

    addUART1_Reg0x0 = (uart_clk_div << posUART1_Reg0x0_UART_CLK_DIVID) |
                      (0x0          << posUART1_Reg0x0_UART_STOP_LEN ) |
                      (0x0          << posUART1_Reg0x0_UART_PAR_MODE ) |
                      (0x0          << posUART1_Reg0x0_UART_PAR_EN   ) |
                      (0x3          << posUART1_Reg0x0_UART_LEN      ) |
                      (0x0          << posUART1_Reg0x0_UART_IRDA     ) |
                      (0x1          << posUART1_Reg0x0_UART_RX_ENABLE) |
                      (0x1          << posUART1_Reg0x0_UART_TX_ENABLE) ;
    addUART1_Reg0x1 = 0x00001010;
    addUART1_Reg0x4 = 0x42;
    addUART1_Reg0x6 = 0x0;
    addUART1_Reg0x7 = 0x0;

    setf_SYS_Reg0x10_int_uart1_en;

    uart1_rx_done = FALSE;
    uart1_rx_index = 0;
}
void clear_uart1_buffer(void)
{
    uart1_rx_index = 0;
    uart1_rx_done = FALSE;
    memset(uart1_rx_buf, 0, sizeof(uart1_rx_buf)); /**< Clear the RX buffer */
    memset(uart1_tx_buf, 0, sizeof(uart1_tx_buf)); /**< Clear the TX buffer */
    uart_printf("clear_uart1_buffer\r\n");
}
void TRAhcit_UART1_Tx(void)
{
    uint32_t tx_len  = HCI_EVENT_HEAD_LENGTH+pHCItxBuf1->total;
    pHCItxBuf1->code  = TRA_HCIT_EVENT;
    pHCItxBuf1->event = HCI_COMMAND_COMPLETE_EVENT;
    uart1_send(uart1_tx_buf, tx_len);
    
    clear_uart1_buffer();
}
static void uart1_send_byte(unsigned char data)
{
    while (!get_UART1_Reg0x2_FIFO_WR_READY);
    addUART1_Reg0x3 = data;
}
void uart1_send(void *buff, uint16_t len)
{
    uint8_t *tmpbuf = (uint8_t *)buff;
    while (len--)
        uart1_send_byte(*tmpbuf++);
}
void TRAhcit_UART1_Rx(void)
{
    if ((uart1_rx_done != TRUE) || (uart1_rx_index == 0))
        return;
    if ( (pHCIrxBuf1->code != TRA_HCIT_COMMAND)
        || (pHCIrxBuf1->opcode.ogf != VENDOR_SPECIFIC_DEBUG_OGF)
        || (pHCIrxBuf1->opcode.ocf != BEKEN_OCF)
        || (uart1_rx_index != (HCI_COMMAND_HEAD_LENGTH+pHCIrxBuf1->total))
       )
        goto ret;

    switch (pHCIrxBuf1->cmd) 
    {
        case LINK_CHECK_CMD:
            pHCItxBuf1->total = uart1_rx_index;
            memcpy(pHCItxBuf1->param, uart1_rx_buf, pHCItxBuf1->total);
            break;
        case REGISTER_WRITE_CMD: 
        {   // 01e0fc09010028800068000000
            signed   long reg_index;
            REGISTER_PARAM *rx_param        = (REGISTER_PARAM *)pHCIrxBuf1->param;
            REGISTER_PARAM *tx_param        = (REGISTER_PARAM *)&pHCItxBuf1->param[HCI_COMMAND_HEAD_LENGTH];
            pHCItxBuf1->total                = uart1_rx_index-1;
            memcpy(pHCItxBuf1->param, uart1_rx_buf, 3);
            pHCItxBuf1->param[3]             = pHCIrxBuf1->cmd;
            tx_param->addr                  = rx_param->addr;
            tx_param->value                 = rx_param->value;
            *(volatile uint32_t *)rx_param->addr = rx_param->value;
            reg_index                       = (rx_param->addr-BASEADDR_XVR)/4;
            if ((reg_index>=0) && (reg_index<=0x0f))
            {
                XVR_ANALOG_REG_BAK[reg_index] = rx_param->value;
            }else if ((reg_index>=0x1c) && (reg_index<=0x1f))
            {
                XVR_ANALOG_REG_BAK[reg_index] = rx_param->value;
            }
            break;
        }
        case REGISTER_READ_CMD: 
        {   // 01e0fc050300288000
            signed   long reg_index;
            REGISTER_PARAM *rx_param = (REGISTER_PARAM *)pHCIrxBuf1->param;
            REGISTER_PARAM *tx_param = (REGISTER_PARAM *)&pHCItxBuf1->param[HCI_COMMAND_HEAD_LENGTH];
            pHCItxBuf1->total         = uart1_rx_index+3;
            memcpy(pHCItxBuf1->param, uart1_rx_buf, 3);
            pHCItxBuf1->param[3]      = pHCIrxBuf1->cmd;
            tx_param->addr           = rx_param->addr;
            reg_index                = (rx_param->addr-BASEADDR_XVR)/4;
            if ((reg_index>=0) && (reg_index<=0x0f))
            {
                tx_param->value        = XVR_ANALOG_REG_BAK[reg_index];
                printf("reg_index 0\r\n"); 
            }
            else if ((reg_index>=0x1c) && (reg_index<=0x1f))
            {
                tx_param->value        = XVR_ANALOG_REG_BAK[reg_index];
                printf("reg_index 1\r\n"); 
            }
            else
            {
                tx_param->value          = *(volatile uint32_t *)rx_param->addr;
                //printf("reg_index 2,tx_param->value:%x\r\n",REG_BLE_RD(rx_param->addr)); 
            }
            break;
        }
        case CHIP_RST_CMD: 
        {
            // 01e0fc05FE 95 27 95 27
            REGISTER_PARAM *rx_param = (REGISTER_PARAM *)pHCIrxBuf1->param;
            printf("addr:%x\r\n",rx_param->addr); 
            if(rx_param->addr == 0x27952795)
            {
                cpu_reset();
                while (1);
            }
        }break;

         case MODULE_TEST_CMD : 
         {
            //01 E0 FC + 0x3(total_len) +  0xCC + 0x00 (module_cmd)
            //func_test(pHCIrxBuf->param);
            goto ret;
         }
         default:
            goto ret;
    }
    TRAhcit_UART1_Tx();

ret:
    clear_uart1_buffer();
}

void UART1_ISR(void)
{
    unsigned long uart_int_status;
    unsigned char uart_fifo_rdata;

    uart_int_status = addUART1_Reg0x5;
    if (uart_int_status & (bitUART1_Reg0x5_RX_FIFO_NEED_READ | bitUART1_Reg0x5_UART_RX_STOP_END))
    {
        while (get_UART1_Reg0x2_FIFO_RD_READY)
        {
            uart_fifo_rdata = (uint8_t)addUART1_Reg0x3;
            uart1_rx_buf[uart1_rx_index++] = uart_fifo_rdata;
            if (uart1_rx_index == UART_RX_FIFO_MAX_COUNT)
            {
                uart1_rx_index = 0;
            }
       }
        if (uart_int_status & bitUART1_Reg0x5_UART_RX_STOP_END)
            uart1_rx_done = TRUE;  
    }
    if( DUT_FCC_MODE==get_sys_mode() )
    {
        if((uart1_rx_buf[0] == 0x01) && (uart1_rx_buf[1] == 0xE0) && (uart1_rx_buf[2] == 0xFC))
        {
            TRAhcit_UART1_Rx();
        }
        else if(uart1_rx_buf[0] != 0x01)
        {
            clear_uart1_buffer();
        }
    }
    addUART1_Reg0x5 = uart_int_status;
}


