#ifndef APP_AUTO_TEST_H
#define APP_AUTO_TEST_H

#include "rwip_config.h"             // SW configuration
#if (BLE_APP_PRESENT)

#include <stdint.h>         // Standard Integer
#include "rwip_task.h"      // Task definitions
#include "ke_task.h"        // Kernel Task
//#include "app_sbc.h"
#endif
#include "uart1.h"
#include "uart0.h"

#include "string.h"
#include "stdlib.h"
#include "gapm_msg.h"


#if CONF_AUTO_TEST

#define AT_RX_SIZE 128

#define AT_CONN_MAX 2
#define WRITE_SIZE 240


extern volatile uint8_t g_at_rx_buf[AT_RX_SIZE];
extern volatile uint8_t g_at_rx_len;
extern volatile uint8_t g_at_rx_done;
extern uint8_t g_write_type;

#define CMD_SIZE 20
#define INVAL_AT_CMD 0xFF

#define AT_WRITE_HANDLE 46





typedef enum
{
    NO_OPCOD = 0xFF,
    REBOOT = 0,
    TEST_START,
    AT_OPCOD_MAX
    
}AT_OPCOD_E; 

typedef struct 
{
    AT_OPCOD_E at_opcode;
    char cmd[CMD_SIZE * 2 + 2];
    uint8_t (* handle)(uint8_t *param);
}auto_test_cmd_handle;

typedef struct 
{
    uint16_t error_code;
    char code_str[20];
}error_code_str_t;

void handle_auto_test_data(void);


extern AT_OPCOD_E g_at_opcode;


#endif
#endif

