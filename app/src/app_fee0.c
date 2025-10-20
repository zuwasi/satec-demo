/**
 ****************************************************************************************
 *
 * @file app_fee0.c
 *
 * @brief fee0 Application Module entry point
 *
 * @auth  gang.cheng
 *
 * @date  2020.03.17
 *
 * Copyright (C) Beken 2019-2022
 *
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APP
 * @{
 ****************************************************************************************
 */

#include "rwip_config.h"     // SW configuration
#include "rwapp_config.h"
#if (BLE_APP_FEE0S)
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <string.h>
#include "ke_task.h"                 // Kernel
#include "app_fee0.h"              // Battery Application Module Definitions
#include "app.h"                   // Application Definitions
#include "app_task.h"              // application task definitions
#include "fee0s_msg.h"            // health thermometer functions
#include "co_bt.h"
#include "co_utils.h"
#include "prf_types.h"             // Profile common types definition
#include "prf_utils.h"
#include "arch.h"                  // Platform Definitions
#include "prf.h"
#include "fee0s.h"
#include "ke_timer.h"
#include "uart.h"



/*
 * DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/// fff0 Application Module Environment Structure
struct app_fee0_env_tag app_fee0_env;

/*
 * GLOBAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */


void app_fee0_init(void)
{

    // Reset the environment
    memset(&app_fee0_env, 0, sizeof(struct app_fee0_env_tag));
}

void app_fee0_add_fee0s(void)
{

  uart_printf("app_fee0_add_fee0s\r\n");
  struct fee0s_db_cfg *db_cfg;
        
   struct gapm_profile_task_add_cmd *req = KE_MSG_ALLOC_DYN(GAPM_PROFILE_TASK_ADD_CMD,
                                                  TASK_GAPM, TASK_APP,
                                                  gapm_profile_task_add_cmd, sizeof(struct fee0s_db_cfg));
    // Fill message
    req->operation = GAPM_PROFILE_TASK_ADD;
    req->sec_lvl =   GATT_SEC_NOT_ENC;
    req->prf_api_id = TASK_ID_FEE0S;
    req->app_task = TASK_APP;
    req->start_hdl = 0; //req->start_hdl = 0; dynamically allocated

     
    // Set parameters
    db_cfg = (struct fee0s_db_cfg* ) req->param;
   
    db_cfg->fee1_desc_len = strlen("fee1_only_read");
   
    memcpy(db_cfg->fee1_desc,"fee1_only_read",strlen("fee1_only_read"));
     
    // Sending of notifications is supported
    // Send the message
    ke_msg_send(req);
}


void app_fee4_send_ntf(uint8_t conidx,uint16_t len,uint8_t* buf)
{
    // Allocate the message
    if(app_fee0_env.state == FEE0S_IDLE)
    {
        struct fee0s_fee45_val_upd_req * req = KE_MSG_ALLOC(FEE0S_FEE4_VALUE_UPD_REQ,
                                                            PRF_SRC_TASK(FEE0S),
                                                            PRF_DST_TASK(FEE0S),
                                                            fee0s_fee45_val_upd_req);
        // Fill in the parameter structure    
        req->length = len;
        memcpy(req->value, buf, len);

        // Send the message
        ke_msg_send(req);
        
        app_fee0_env.state = FEE0S_BUSY;
    }
}

void app_fee5_send_ind(uint8_t conidx,uint16_t len,uint8_t* buf)
{
    // Allocate the message
    if(app_fee0_env.state == FEE0S_IDLE)
    {
        struct fee0s_fee45_val_upd_req * req = KE_MSG_ALLOC(FEE0S_FEE5_VALUE_UPD_REQ,
                                                            PRF_SRC_TASK(FEE0S),
                                                            PRF_DST_TASK(FEE0S),
                                                            fee0s_fee45_val_upd_req);
        // Fill in the parameter structure    
        req->length = len;
        memcpy(req->value, buf, len);

        // Send the message
        ke_msg_send(req);
        app_fee0_env.state = FEE0S_BUSY;
    }
}



static int fee0s_fee4_val_ntf_cfg_ind_handler(ke_msg_id_t const msgid,
                                               struct fee0s_fee45_val_ntf_cfg_ind const *param,
                                               ke_task_id_t const dest_id,
                                               ke_task_id_t const src_id)
{
    uart_printf("fee4->param->ntf_cfg = %x\r\n",param->ntf_ind_cfg);
    if(param->ntf_ind_cfg == PRF_CLI_STOP_NTFIND)
    {
        //ke_timer_clear(FEE0S_FEE1_LEVEL_PERIOD_NTF,dest_id);
    }else
    {
        //ke_timer_set(FEE0S_FEE1_LEVEL_PERIOD_NTF,dest_id , 100);
    }
    
    return (KE_MSG_CONSUMED);
}

static int fee0s_fee5_val_ind_cfg_ind_handler(ke_msg_id_t const msgid,
                                               struct fee0s_fee45_val_ntf_cfg_ind const *param,
                                               ke_task_id_t const dest_id,
                                               ke_task_id_t const src_id)
{
    uart_printf("fee5->param->ind_cfg = %x\r\n",param->ntf_ind_cfg);
    if(param->ntf_ind_cfg == PRF_CLI_STOP_NTFIND)
    {
        //ke_timer_clear(FEE0S_FEE3_LEVEL_PERIOD_NTF,dest_id);
    }else
    {
        //ke_timer_set(FEE0S_FEE3_LEVEL_PERIOD_NTF,dest_id , 100);
    }
    
    return (KE_MSG_CONSUMED);
}
static int fee4_val_upd_rsp_handler(ke_msg_id_t const msgid,
                                      struct fee0s_fee45_val_upd_rsp const *param,
                                      ke_task_id_t const dest_id,
                                      ke_task_id_t const src_id)
{
    uart_printf("%s,status:%x,conidx=%x\r\n", __func__,param->status,param->conidx);

    if(param->status == GAP_ERR_NO_ERROR)
    {
        app_fee0_env.state = FEE0S_IDLE;
    }

    return (KE_MSG_CONSUMED);
}

static int fee5_val_upd_rsp_handler(ke_msg_id_t const msgid,
                                      struct fee0s_fee45_val_upd_rsp const *param,
                                      ke_task_id_t const dest_id,
                                      ke_task_id_t const src_id)
{
    uart_printf("%s,status:%x\r\n", __func__,param->status);
    
    if(param->status == GAP_ERR_NO_ERROR)
    {
        app_fee0_env.state = FEE0S_IDLE;
    }
    
    return (KE_MSG_CONSUMED);
}


/**
 ****************************************************************************************
 * @brief
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] param     Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance (TASK_GAP).
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int app_fee0_msg_dflt_handler(ke_msg_id_t const msgid,
                                     void const *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    uart_printf("%s\r\n", __func__);
    
    // Drop the message
    return (KE_MSG_CONSUMED);
}

void analyse_ble_data(uint8_t *pData,uint8_t length);
static int fee2_writer_cmd_handler(ke_msg_id_t const msgid,
                                     struct fee0s_fee23_writer_ind *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    // Drop the message
    uart_printf("FEE2 conidx:%d,length:%d,param->value = 0x ",param->conidx,param->length);

    for(uint16_t i = 0;i < param->length;i++)
    {
        uart_printf("%02x ",param->value[i]);
    }
    uart_printf("\r\n");
    analyse_ble_data(param->value,param->length);
    #if 0//CONF_AUTO_TEST///for test
    uint8_t buf[20];
    for(uint8_t i = 0;i < 20;i++)
    {
        buf[i] = i;
    }
    if(param->value[0] == 0x55&&param->value[1] == 0x66&&
      param->value[2] == 0x77&&param->value[3] == 0x88)
    {
        app_fee4_send_ntf(param->conidx,param->length,param->value);
    }
    if(param->value[0] == 0x55&&param->value[1] == 0x66&&
      param->value[2] == 0x77&&param->value[3] == 0x99)
    {
        app_fee5_send_ind(param->conidx,20,buf);
    }
    if(param->value[0] == 0x55&&param->value[1] == 0x66&&
      param->value[2] == 0x77&&param->value[3] == 0xaa)
    {
        struct gapc_conn_param conn_param;
        conn_param.intv_min = param->value[4];
        conn_param.intv_max = param->value[4] + 8;
        conn_param.latency = 0;
        conn_param.time_out = 600;

        app_update_param(&conn_param);
    }
    #endif
    return (KE_MSG_CONSUMED);
}

static int fee3_writer_req_handler(ke_msg_id_t const msgid,
                                     struct fee0s_fee23_writer_ind *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    // Drop the message
    uart_printf("FEE3 conidx:%d,length:%d,param->value = 0x ",param->conidx,param->length);
    
    for(uint16_t i = 0;i < param->length;i++)
    {
        uart_printf("%02x ",param->value[i]);
    }
    uart_printf("\r\n");
        
    return (KE_MSG_CONSUMED);
}



/*
 * LOCAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/// Default State handlers definition
const struct ke_msg_handler app_fee0_msg_handler_list[] =
{
    // Note: first message is latest message checked by kernel so default is put on top.
    {KE_MSG_DEFAULT_HANDLER,        (ke_msg_func_t)app_fee0_msg_dflt_handler},
    {FEE0S_FEE4_VALUE_NTF_CFG_IND,  (ke_msg_func_t)fee0s_fee4_val_ntf_cfg_ind_handler},
    {FEE0S_FEE5_VALUE_IND_CFG_IND,  (ke_msg_func_t)fee0s_fee5_val_ind_cfg_ind_handler},
    {FEE0S_FEE4_VALUE_UPD_RSP,      (ke_msg_func_t)fee4_val_upd_rsp_handler},
    {FEE0S_FEE5_VALUE_UPD_RSP,      (ke_msg_func_t)fee5_val_upd_rsp_handler},
    {FEE0S_FEE2_WRITER_CMD_IND,        (ke_msg_func_t)fee2_writer_cmd_handler},
    {FEE0S_FEE3_WRITER_REQ_IND,        (ke_msg_func_t)fee3_writer_req_handler},
    
};

const struct app_subtask_handlers app_fee0_handlers = APP_HANDLERS(app_fee0);


#endif// (BLE_APP_FEE0)

