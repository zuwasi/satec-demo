/**
 ****************************************************************************************
 *
 * @file app_dis.c
 *
 * @brief Device Information Application Module Entry point
 *
 * Copyright (C) RivieraWaves 2009-2015
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
#if (BLE_APP_DIS)

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "app.h"                     // Application Manager Definitions
#include "app_dis.h"                 // Device Information Service Application Definitions
#include "diss_msg.h"               // Device Information Profile Functions
#include "prf_types.h"               // Profile Common Types Definitions
#include "ke_task.h"                 // Kernel
#include "gapm_msg.h"               // GAP Manager Task API
#include <string.h>
#include "co_utils.h"

/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */

static int diss_value_req_ind_handler(ke_msg_id_t const msgid,
                                          struct diss_value_req_ind const *param,
                                          ke_task_id_t const dest_id,
                                          ke_task_id_t const src_id)
{
    // Initialize length
    uint8_t len = 0;
    // Pointer to the data
    uint8_t *data = NULL;
    // Check requested value
    switch (param->val_id)
    {
        case DIS_VAL_MANUFACTURER_NAME:
        {
            // Set information
            len = APP_DIS_MANUFACTURER_NAME_LEN;
            data = (uint8_t *)APP_DIS_MANUFACTURER_NAME;
        } break;

        case DIS_VAL_MODEL_NB_STR:
        {
            // Set information
            len = APP_DIS_MODEL_NB_STR_LEN;
            data = (uint8_t *)APP_DIS_MODEL_NB_STR;
        } break;

        case DIS_VAL_SYSTEM_ID:
        {
            // Set information
            len = APP_DIS_SYSTEM_ID_LEN;
            data = (uint8_t *)APP_DIS_SYSTEM_ID;
        } break;

        case DIS_VAL_PNP_ID:
        {
            // Set information
            len = APP_DIS_PNP_ID_LEN;
            data = (uint8_t *)APP_DIS_PNP_ID;
        } break;

        case DIS_VAL_SERIAL_NB_STR:
        {
            // Set information
            len = APP_DIS_SERIAL_NB_STR_LEN;
            data = (uint8_t *)APP_DIS_SERIAL_NB_STR;
        } break;

        case DIS_VAL_HARD_REV_STR:
        {
            // Set information
            len = APP_DIS_HARD_REV_STR_LEN;
            data = (uint8_t *)APP_DIS_HARD_REV_STR;
        } break;

        case DIS_VAL_FIRM_REV_STR:
        {
            // Set information
            len = APP_DIS_FIRM_REV_STR_LEN;
            data = (uint8_t *)APP_DIS_FIRM_REV_STR;
        } break;

        case DIS_VAL_SW_REV_STR:
        {
            // Set information
            len = APP_DIS_SW_REV_STR_LEN;
            data = (uint8_t *)APP_DIS_SW_REV_STR;
        } break;

        case DIS_VAL_IEEE:
        {
            // Set information
            len = APP_DIS_IEEE_LEN;
            data = (uint8_t *)APP_DIS_IEEE;
        } break;

        default:
            ASSERT_ERR(0);
            break;
    }

    // Allocate confirmation to send the value
    struct diss_value_cfm *cfm_value = KE_MSG_ALLOC_DYN(DISS_VALUE_CFM,
            src_id, dest_id,
            diss_value_cfm,
            len);
    // Set parameters
    cfm_value->val_id = param->val_id;
    cfm_value->token = param->token;
    cfm_value->length = len;
    if (len)
    {
        // Copy data
        memcpy(&cfm_value->data[0], data, len);
    }
    // Send message
    ke_msg_send(cfm_value);
    return (KE_MSG_CONSUMED);
}

/*
 * GLOBAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */

void app_dis_init(void)
{
    // Nothing to do
}

void app_dis_add_dis(void)
{
    uart_printf("%s\r\n",__func__);
    struct diss_db_cfg* db_cfg;
    // Allocate the DISS_CREATE_DB_REQ
    struct gapm_profile_task_add_cmd *req = KE_MSG_ALLOC_DYN(GAPM_PROFILE_TASK_ADD_CMD,
                                                  TASK_GAPM, TASK_APP,
                                                  gapm_profile_task_add_cmd, sizeof(struct diss_db_cfg));
    // Fill message
    req->operation = GAPM_PROFILE_TASK_ADD;
    
    req->sec_lvl = GATT_SEC_NOT_ENC;
    req->prf_api_id = TASK_ID_DISS;
    req->app_task = TASK_APP;
    req->start_hdl = 0;

    // Set parameters
    db_cfg = (struct diss_db_cfg* ) req->param;
    db_cfg->features = APP_DIS_FEATURES;

    // Send the message
    ke_msg_send(req);

}

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/// Default State handlers definition
const struct ke_msg_handler app_dis_msg_handler_list[] =
{
    {DISS_VALUE_REQ_IND,     (ke_msg_func_t)diss_value_req_ind_handler},
};

const struct app_subtask_handlers app_dis_handlers = APP_HANDLERS(app_dis);

#endif //BLE_APP_DIS

/// @} APP
