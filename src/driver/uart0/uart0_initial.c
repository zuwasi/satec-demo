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
#if (CONF_AUTO_TEST)
#include "app_auto_test.h"
#endif


extern volatile uint32_t XVR_ANALOG_REG_BAK[32];
extern uint8_t uart_rx_en;
volatile uint8_t uart_rx_done = FALSE;
volatile uint32_t uart_rx_index = 0;
uint8_t uart_rx_buf[UART_RX_FIFO_MAX_COUNT];
uint8_t uart_tx_buf[UART_TX_FIFO_MAX_COUNT];

HCI_COMMAND_PACKET *pHCIrxBuf = (HCI_COMMAND_PACKET *)(&uart_rx_buf[0]);
HCI_EVENT_PACKET   *pHCItxBuf = (HCI_EVENT_PACKET *)(&uart_tx_buf[0]);

void uart0_init(uint32_t baud_rate)
{
    uint32_t uart_clk_div;
    clrf_SYS_Reg0x3_uart0_pwd ;   //open periph
    uart_clk_div = (UART_CLK_FREQ*1000000)/baud_rate - 1;

    gpio_config(0x00,SC_FUN,PULL_HIGH);
#ifndef USE_ADC0	
    gpio_config(0x01,SC_FUN,PULL_HIGH);
#endif
    addUART0_Reg0x0 = (uart_clk_div << posUART0_Reg0x0_UART_CLK_DIVID) |
                      (0x0          << posUART0_Reg0x0_UART_STOP_LEN ) |
                      (0x0          << posUART0_Reg0x0_UART_PAR_MODE ) |
                      (0x0          << posUART0_Reg0x0_UART_PAR_EN   ) |
                      (0x3          << posUART0_Reg0x0_UART_LEN      ) |
                      (0x0          << posUART0_Reg0x0_UART_IRDA     ) |
#ifdef USE_ADC0	
                      (0x0          << posUART0_Reg0x0_UART_RX_ENABLE) |
#else
											(0x1          << posUART0_Reg0x0_UART_RX_ENABLE) |
#endif	
                      (0x1          << posUART0_Reg0x0_UART_TX_ENABLE) ;


    addUART0_Reg0x1 = 0x00004010;
    addUART0_Reg0x4 = 0x42;
    addUART0_Reg0x6 = 0x0;
    addUART0_Reg0x7 = 0x700401;

    setf_SYS_Reg0x10_int_uart0_en; //enable uart_int irq

    uart_rx_done = FALSE;
    uart_rx_index = 0;
}

void uart0_send_byte(unsigned char data)
{
    while (!get_UART0_Reg0x2_FIFO_WR_READY);
    addUART0_Reg0x3 = data;
}

void uart0_send(void *buff, uint16_t len)
{
    uint8_t *tmpbuf = (uint8_t *)buff;
    while (len--)
        uart0_send_byte(*tmpbuf++);
}

void clear_uart_buffer(void)
{
    uart_rx_index = 0;
    uart_rx_done = FALSE;
    memset(uart_rx_buf, 0, sizeof(uart_rx_buf)); /**< Clear the RX buffer */
    memset(uart_tx_buf, 0, sizeof(uart_tx_buf)); /**< Clear the TX buffer */
    //uart_printf("clear_uart_buffer\r\n");
}
void TRAhcit_UART_Tx(void)
{
    uint32_t tx_len  = HCI_EVENT_HEAD_LENGTH+pHCItxBuf->total;
    pHCItxBuf->code  = TRA_HCIT_EVENT;
    pHCItxBuf->event = HCI_COMMAND_COMPLETE_EVENT;
    uart0_send(uart_tx_buf, tx_len);
    
    clear_uart_buffer();
}
int uart_printf_null(const char *fmt,...)
{
    return 0;
}
void TRAhcit_UART_Rx(void)
{
    if ((uart_rx_done != TRUE) || (uart_rx_index == 0))
        return;
    
    if ( (pHCIrxBuf->code != TRA_HCIT_COMMAND)
        || (pHCIrxBuf->opcode.ogf != VENDOR_SPECIFIC_DEBUG_OGF)
        || (pHCIrxBuf->opcode.ocf != BEKEN_OCF)
        || (uart_rx_index != (HCI_COMMAND_HEAD_LENGTH+pHCIrxBuf->total))
       )
        goto ret;

    switch (pHCIrxBuf->cmd) 
    {
        #if (DEBUG_BKREG == 1)
        case LINK_CHECK_CMD:
            pHCItxBuf->total = uart_rx_index;
            memcpy(pHCItxBuf->param, uart_rx_buf, pHCItxBuf->total);
            break;

        case REGISTER_WRITE_CMD: 
        {   
            // 01e0fc09010028800068000000
            signed   long reg_index;
            REGISTER_PARAM *rx_param        = (REGISTER_PARAM *)pHCIrxBuf->param;
            REGISTER_PARAM *tx_param        = (REGISTER_PARAM *)&pHCItxBuf->param[HCI_COMMAND_HEAD_LENGTH];
            pHCItxBuf->total                = uart_rx_index-1;
            memcpy(pHCItxBuf->param, uart_rx_buf, 3);
            pHCItxBuf->param[3]             = pHCIrxBuf->cmd;
            tx_param->addr                  = rx_param->addr;
            tx_param->value                 = rx_param->value;
            *(volatile uint32_t *)rx_param->addr = rx_param->value;
            reg_index                       = (rx_param->addr-BASEADDR_XVR)/4;
            if ((reg_index>=0) && (reg_index<=0x1f))       
            {
                XVR_ANALOG_REG_BAK[reg_index] = rx_param->value;
                *(volatile uint32_t *)rx_param->addr = rx_param->value;
            }
            else 
            {
                *(volatile uint32_t *)rx_param->addr = tx_param->value;
            }
            //printf("reg_index =%d,rx_addr:0x%x,value:0x%x\r\n",reg_index,rx_param->addr,rx_param->value); 
            break;
        }
        case REGISTER_READ_CMD: 
        {   // 01e0fc050300288000
            signed   long reg_index;
            REGISTER_PARAM *rx_param = (REGISTER_PARAM *)pHCIrxBuf->param;
            REGISTER_PARAM *tx_param = (REGISTER_PARAM *)&pHCItxBuf->param[HCI_COMMAND_HEAD_LENGTH];
            pHCItxBuf->total         = uart_rx_index+3;
            memcpy(pHCItxBuf->param, uart_rx_buf, 3);
            pHCItxBuf->param[3]      = pHCIrxBuf->cmd;
            tx_param->addr           = rx_param->addr;
            reg_index                = (rx_param->addr-BASEADDR_XVR)/4;
            if ((reg_index>=0) && (reg_index<=0x1f))       
            {          
                tx_param->value        = XVR_ANALOG_REG_BAK[reg_index];          
            }       
            else
            {   
                tx_param->value          = *(volatile uint32_t *)rx_param->addr;       
            }
            break;
        }
        #endif
        case CHIP_RST_CMD: 
        {
            // 01e0fc05FE 95 27 95 27
            REGISTER_PARAM *rx_param = (REGISTER_PARAM *)pHCIrxBuf->param;
            if(rx_param->addr == 0x27952795)
            {
                cpu_reset();
                while (1);
            }
        }break;
        case MODULE_TEST_CMD : 
        {       
            //01 E0 FC + 0x3(total_len) + 0xCC + 0x00 (module_cmd)
            //func_test(pHCIrxBuf->param);
            goto ret;
        }
        default:
            goto ret;
    }
    
    #if (DEBUG_BKREG == 1)
    TRAhcit_UART_Tx();
    #endif
ret:
    clear_uart_buffer();
}

void UART0_ISR(void)
{
    unsigned long uart_int_status;
    unsigned char uart_fifo_rdata;

    uart_int_status = addUART0_Reg0x5;
    if (uart_int_status & (bitUART0_Reg0x5_RX_FIFO_NEED_READ | bitUART0_Reg0x5_UART_RX_STOP_END))
    {
        uart_rx_en = 1;
        while (get_UART0_Reg0x2_FIFO_RD_READY)
        {
            uart_fifo_rdata = (uint8_t)addUART0_Reg0x3;
            uart_rx_buf[uart_rx_index++] = uart_fifo_rdata;
            if (uart_rx_index == UART_RX_FIFO_MAX_COUNT)
            {
                uart_rx_index = 0;
            }
            #if(CONF_AUTO_TEST )
            g_at_rx_buf[g_at_rx_len] = uart_fifo_rdata;
            g_at_rx_len++;
            #endif 
        }
        if (uart_int_status & bitUART0_Reg0x5_UART_RX_STOP_END)
        {
            uart_rx_done = TRUE;
            #if(CONF_AUTO_TEST) 
            g_at_rx_done = true;
            #endif 
        }
    }
    
    if((uart_rx_buf[0] == 0x01) && (uart_rx_buf[1] == 0xE0) && (uart_rx_buf[2] == 0xFC))
    {
        TRAhcit_UART_Rx();
    }
    else if(uart_rx_buf[0] != 0x01)
    {
        clear_uart_buffer();
    }
    else
    {
        if( DUT_FCC_MODE==get_sys_mode() )
        {
            ///create send command message
            void *cmd_data = ke_msg_alloc(HCI_COMMAND, 0, uart_rx_buf[2]<<8 | uart_rx_buf[1], 4);
            if(cmd_data) 
            {
                memcpy(cmd_data, &uart_rx_buf[4], uart_rx_index-3);
                hci_send_2_controller(cmd_data);
            }
            for (int i=0; i<uart_rx_index; i++)
            {
                uart_rx_buf[i] = 0;
            }
            uart_rx_index = 0;
            uart_rx_done = false;
        }
    }
    addUART0_Reg0x5 = uart_int_status;
}



