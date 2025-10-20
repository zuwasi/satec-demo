
#include "rwip_config.h"     // SW configuration
#include "rwapp_config.h"

#include "app.h"
#include "gapm.h"
#include "app_task.h"
#include "app_fee0.h"
#include "fee0s_msg.h"
#include "rwip.h"
#include "user_config.h"
#include "app_auto_test.h"
#include "wdt.h"
#if CONF_AUTO_TEST

extern auto_test_cmd_handle g_auto_test_cmd_list[AT_OPCOD_MAX];
extern error_code_str_t error_str_list[1];

volatile uint8_t g_at_rx_buf[AT_RX_SIZE];
volatile uint8_t g_at_rx_len = 0;
volatile uint8_t g_at_rx_done = false;


AT_OPCOD_E g_at_opcode = NO_OPCOD;

void handle_auto_test_cmd(void)
{
    uint16_t i ;

    uint8_t cmd_name_len;

    uint16_t error_code = 0xFFFF;

    if(g_at_rx_len == 0)
    {
        return;
    }
    //uart_printf("len:%d\n", g_at_rx_len);
    //for(i=0;i<g_at_rx_len;i++)
    //    uart_printf("%c",g_at_rx_buf[i]);
    //uart_printf("\n");
    
    for(i = 0; i < AT_OPCOD_MAX; i++)
    {
        cmd_name_len = strlen(g_auto_test_cmd_list[i].cmd);
        
        if(cmd_name_len > g_at_rx_len)
        {
            continue;
        }
        
        if((memcmp((const void*)g_auto_test_cmd_list[i].cmd, (const void*)g_at_rx_buf, cmd_name_len) == 0)
                && (g_at_rx_buf[cmd_name_len] == ' ' 
                    || g_at_rx_buf[cmd_name_len] == '\n' 
                    || (g_at_rx_buf[cmd_name_len] == '\r' && g_at_rx_buf[cmd_name_len + 1] == '\n')))
            
        {
            
            uart_printf("cmd: %s OK\n", g_auto_test_cmd_list[i].cmd);

            g_at_opcode = g_auto_test_cmd_list[i].at_opcode;
            
            if(g_at_rx_buf[cmd_name_len] != ' ') // has not param
            {
                error_code = g_auto_test_cmd_list[i].handle(NULL);
            }
            else
            {
                error_code = g_auto_test_cmd_list[i].handle((uint8_t *)&g_at_rx_buf[cmd_name_len + 1]);
            }        
            break;
        }
    }

}

void handle_auto_test_data(void)
{
    
    if(g_at_rx_done)
    {
        uart_printf("handle_auto_test_data\n");
        
        handle_auto_test_cmd();
        g_at_rx_len = 0;
        memset((void *)g_at_rx_buf, 0, AT_RX_SIZE);
        g_at_rx_done = false;
    }
}

uint8_t reboot_cmd_handle(uint8_t *param)
{
    wdt_disable();
    wdt_enable(0xff); 
    for(int i = 0 ;i < 10;i++)
    {
        uart_printf("wait for reset!!!\r\n");
    }    
    while(1);

    
}


uint8_t test_start_cmd_handle(uint8_t *param)
{
    char str[20]="test_start ok\n";
    //uart_printf("test start\n");
    uart0_send(str,strlen(str));
    uart0_send(str,strlen(str));
    uart0_send(str,strlen(str));
    uart0_send(str,strlen(str));
    return 0;
}





error_code_str_t error_str_list[1] = 
{    
    {0xFFFF, "unknown cmd !"}
};
    
auto_test_cmd_handle g_auto_test_cmd_list[AT_OPCOD_MAX] = 
{
    {REBOOT, "reboot", reboot_cmd_handle},
    
    {TEST_START,"test_start",test_start_cmd_handle},
    
    
};


#endif

