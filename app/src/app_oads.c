/**
 ****************************************************************************************
 *
 * @file app_braces.c
 *
 * @brief Bracelet Application Module entry point
 *
 * @auth  gang.cheng
 *
 * @date  2016.09.06
 *
 * Copyright (C) Beken 2009-2016
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


/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <string.h>
#include "ke_task.h"                 // Kernel
#include "app_oads.h"              // Battery Application Module Definitions
#include "app.h"                   // Application Definitions
#include "app_task.h"              // application task definitions
#include "co_bt.h"
#include "co_utils.h"
#include "prf_types.h"             // Profile common types definition
#include "prf_utils.h"
#include "arch.h"                  // Platform Definitions
#include "prf.h"
#include "oads.h"
#include "oads_msg.h"            // health thermometer functions
#include "ke_timer.h"
#include "uart.h"



        
/*
 * LOCATION FUN DEFINES
 ****************************************************************************************
 */



/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/// braces Application Module Environment Structure
struct app_oads_env_tag app_oads_env;



/*
 * GLOBAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */

void app_oads_init(void)
{

    // Reset the environment
    memset(&app_oads_env, 0, sizeof(struct app_oads_env_tag));
        
 
}

void app_oad_add_oads(void)
{

    uart_printf("app_oad_add_oads\r\n");
    struct oads_db_cfg *db_cfg;

    struct gapm_profile_task_add_cmd *req = KE_MSG_ALLOC_DYN(GAPM_PROFILE_TASK_ADD_CMD,
                                                  TASK_GAPM, TASK_APP,
                                                  gapm_profile_task_add_cmd, sizeof(struct oads_db_cfg));
    // Fill message
    req->operation = GAPM_PROFILE_TASK_ADD;
    req->sec_lvl = SVC_UUID(128) | SVC_SEC_LVL(NOT_ENC);
    req->prf_api_id = TASK_ID_OADS;
    req->app_task = TASK_APP;
    req->start_hdl = 0; //req->start_hdl = 0; dynamically allocated

     
      // Set parameters
    db_cfg = (struct oads_db_cfg* ) req->param;
     
    // Sending of notifications is supported
    db_cfg->features = OADS_NTF_SUP;
        uart_printf("app_oad_add_oads d = %x,s = %x\r\n",TASK_GAPM,TASK_APP);
    // Send the message
    ke_msg_send(req);
}

void app_oads_enable_prf(uint8_t conidx)
{

    app_oads_env.conidx = conidx;

    // Allocate the message
    struct oads_enable_req * req = KE_MSG_ALLOC(OADS_ENABLE_REQ,
                                                PRF_SRC_TASK(OADS),
                                                PRF_DST_TASK(OADS),
                                                oads_enable_req);

    // Fill in the parameter structure
    req->conidx             = conidx;

    // NTF initial status - Disabled
        req->ffc1_ntf_cfg           = PRF_CLI_STOP_NTFIND;
        req->ffc2_ntf_cfg           = PRF_CLI_STOP_NTFIND;


    // Send the message
    ke_msg_send(req);
}







static int oads_enable_rsp_handler(ke_msg_id_t const msgid,
                                    struct oads_enable_rsp const *param,
                                    ke_task_id_t const dest_id,
                                    ke_task_id_t const src_id)
{
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
static int app_oads_msg_dflt_handler(ke_msg_id_t const msgid,
                                     void const *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    // Drop the message
        uart_printf("%s\r\n",__func__);
        uart_printf("msgid = 0x%04x,destid = 0x%x,srcid = 0x%x\r\n",msgid,dest_id,src_id);
    return (KE_MSG_CONSUMED);
}




static int app_ffc1_writer_req_handler(ke_msg_id_t const msgid,
                                     struct oads_ffc1_writer_ind *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    // Drop the message
    
    uart_printf("%s\r\n",__func__);

  uart_printf("ffc1 conidx:%d,length:%d,param->value = 0x ",param->conidx,param->length);
    
    for(uint16_t i = 0;i < param->length;i++)
    {
        uart_printf("%02x ",param->data[i]);
    }
    
    uart_printf("\r\n");
    if(param->data[0] == 0x44)
    {
        
        app_ffc1_ntf_req();
    }
    if(param->data[0] == 0x33)
    {
        app_ffc2_ntf_req();
    }
    //    oadImgIdentifyWrite(0x0, param->length,param->data );
    


    return (KE_MSG_CONSUMED);
}




static int app_ffc2_writer_req_handler(ke_msg_id_t const msgid,
                                     struct oads_ffc2_writer_ind *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    // Drop the message
    #if 0
    uart_printf("%s\r\n",__func__);
  uart_printf("ffc2 conidx:%d,length:%d,param->value = 0x ",param->conidx,param->length);
    
    for(uint16_t i = 0;i < param->length;i++)
    {
        uart_printf("%02x ",param->data[i]);
    }
    
    uart_printf("\r\n");
    #endif
    //    oadImgBlockWrite(0, param->data);


    return (KE_MSG_CONSUMED);
}


void app_ffc1_ntf_req(void)
{
    // Drop the message
    
      uart_printf("%s\r\n",__func__);
    
        
     struct oads_ffc1_upd_req * req = KE_MSG_ALLOC(OADS_FFC1_UPD_REQ,
                                                        PRF_SRC_TASK(OADS),
                                                        PRF_DST_TASK(OADS),
                                                        oads_ffc1_upd_req);

    // Fill in the parameter structure
        
        req->length = 20;
    req->data[0]   = 100;

    // Send the message
    ke_msg_send(req);
    
}

void app_ffc2_ntf_req(void)
{
    // Drop the message
    
      uart_printf("%s\r\n",__func__);
    
        
     struct oads_ffc2_upd_req * req = KE_MSG_ALLOC(OADS_FFC2_UPD_REQ,
                                                        PRF_SRC_TASK(OADS),
                                                        PRF_DST_TASK(OADS),
                                                        oads_ffc2_upd_req);

    // Fill in the parameter structure
        
        req->length = 20;
    req->data[0]   = 50;

    // Send the message
    ke_msg_send(req);
    
}





static int oads_ffc1_upd_rsp_handler(ke_msg_id_t const msgid,
                                     struct oads_ffc1_upd_rsp *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    
      uart_printf("%s\r\n",__func__);
        if(param->status == GAP_ERR_NO_ERROR)
        {
                
                        
                
        }
        
        
        return (KE_MSG_CONSUMED);
}

static int oads_ffc2_upd_rsp_handler(ke_msg_id_t const msgid,
                                     struct oads_ffc2_upd_rsp *param,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{
    
      uart_printf("%s\r\n",__func__);
        if(param->status == GAP_ERR_NO_ERROR)
        {
                
                        
                
        }
        
        
        return (KE_MSG_CONSUMED);
}


static int app_ffc1_ntf_cfg_ind_handler(ke_msg_id_t const msgid,
                                               struct oads_val_ntf_cfg_ind const *param,
                                               ke_task_id_t const dest_id,
                                               ke_task_id_t const src_id)
{
    uart_printf("ffc1->param->ntf_cfg = %x\r\n",param->ntf_ind_cfg);
    if(param->ntf_ind_cfg == PRF_CLI_STOP_NTFIND)
    {
        //ke_timer_clear(FEE0S_FEE1_LEVEL_PERIOD_NTF,dest_id);
    }else
    {
        //ke_timer_set(FEE0S_FEE1_LEVEL_PERIOD_NTF,dest_id , 100);
    }
    
    return (KE_MSG_CONSUMED);
}

static int app_ffc2_ntf_cfg_ind_handler(ke_msg_id_t const msgid,
                                               struct oads_val_ntf_cfg_ind const *param,
                                               ke_task_id_t const dest_id,
                                               ke_task_id_t const src_id)
{
    uart_printf("ffc2->param->ntf_cfg = %x\r\n",param->ntf_ind_cfg);
    if(param->ntf_ind_cfg == PRF_CLI_STOP_NTFIND)
    {
        //ke_timer_clear(FEE0S_FEE1_LEVEL_PERIOD_NTF,dest_id);
    }else
    {
        //ke_timer_set(FEE0S_FEE1_LEVEL_PERIOD_NTF,dest_id , 100);
    }
    
    return (KE_MSG_CONSUMED);
}


/*
 * LOCAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/// Default State handlers definition
const struct ke_msg_handler app_oads_msg_handler_list[] =
{
    // Note: first message is latest message checked by kernel so default is put on top.
    {KE_MSG_DEFAULT_HANDLER,          (ke_msg_func_t)app_oads_msg_dflt_handler},

    {OADS_ENABLE_RSP,                     (ke_msg_func_t)oads_enable_rsp_handler},

    {OADS_FFC1_WRITER_REQ_IND,      (ke_msg_func_t)app_ffc1_writer_req_handler},

    {OADS_FFC1_NTF_CFG_IND,          (ke_msg_func_t)app_ffc1_ntf_cfg_ind_handler},
  {OADS_FFC2_NTF_CFG_IND,          (ke_msg_func_t)app_ffc2_ntf_cfg_ind_handler},

    {OADS_FFC1_UPD_RSP,                            (ke_msg_func_t)oads_ffc1_upd_rsp_handler},

    {OADS_FFC2_WRITER_REQ_IND,      (ke_msg_func_t)app_ffc2_writer_req_handler},

    {OADS_FFC2_UPD_RSP,                            (ke_msg_func_t)oads_ffc2_upd_rsp_handler},

};

const struct app_subtask_handlers app_oads_handler = APP_HANDLERS(app_oads);    

