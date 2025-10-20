/**
 ****************************************************************************************
 *
 * @file fee0s.c
 *
 * @brief fee0 Server Implementation.
 *
 * Copyright (C) beken 2019-2022
 *
 *
 ****************************************************************************************
 */

#include "rwip_config.h"

#if (BLE_FEE0_SERVER)
#include "fee0s.h"
#include "gatt.h"

#include "prf_utils.h"
#include "prf.h"

#include "co_utils.h"
#include "co_endian.h"
#include "co_math.h"
#include "co_buf.h"
#include "ke_mem.h"
#include <string.h>
#include "uart.h"



/*
 * FEE0 ATTRIBUTES DEFINITION
 ****************************************************************************************
 */
 
/// Full FEE0 Database Description - Used to add attributes into the database
const gatt_att16_desc_t fee0_att_db[FEE0S_IDX_NB] =
{
    // FEE0 Service Declaration
    [FEE0S_IDX_SVC]            = { GATT_DECL_PRIMARY_SERVICE,       PROP(RD),          0                },
    // fee1 value Characteristic Declaration
    // fee1 read
    [FEE0S_IDX_FEE1_VAL_CHAR]  =   {GATT_DECL_CHARACTERISTIC,       PROP(RD),          0                }, 
    //  Characteristic Value
    [FEE0S_IDX_FEE1_VAL_VAL]   =   {ATT_USER_SERVER_CHAR_FEE1,      PROP(RD),          OPT(NO_OFFSET)|FEE0_CHAR_DATA_LEN   },

    [FEE0S_IDX_FEE1_USER_DESC] =   {GATT_DESC_CHAR_USER_DESCRIPTION,PROP(RD),          OPT(NO_OFFSET)|FEE0_CHAR_DATA_LEN   },

    
    // fee2 value Characteristic Declaration
    // fee2 write cmd
    [FEE0S_IDX_FEE2_VAL_CHAR]  =   {GATT_DECL_CHARACTERISTIC, PROP(RD), 0},
    // fee2  Characteristic Value
    [FEE0S_IDX_FEE2_VAL_VAL]   =   {ATT_USER_SERVER_CHAR_FEE2, PROP(WC), OPT(NO_OFFSET) |FEE0_CHAR_DATA_LEN},

        // fee2 value Characteristic Declaration
        // fee3 write req
    [FEE0S_IDX_FEE3_VAL_CHAR]  =   {GATT_DECL_CHARACTERISTIC, PROP(RD), 0},
    // fee1 value Characteristic Value
    [FEE0S_IDX_FEE3_VAL_VAL]   =   {ATT_USER_SERVER_CHAR_FEE3, PROP(WR), OPT(NO_OFFSET)|FEE0_CHAR_DATA_LEN},
    
    // fee4 value Characteristic Declaration
    // fee4 ntf
    [FEE0S_IDX_FEE4_VAL_CHAR]  =   {GATT_DECL_CHARACTERISTIC, PROP(RD), 0},
    // fee4 value Characteristic Value
    [FEE0S_IDX_FEE4_VAL_VAL]   =   {ATT_USER_SERVER_CHAR_FEE4, PROP(N), OPT(NO_OFFSET) |FEE0_CHAR_DATA_LEN},

    // fee4 value Characteristic - Client Characteristic Configuration Descriptor
    [FEE0S_IDX_FEE4_VAL_NTF_CFG] = {GATT_DESC_CLIENT_CHAR_CFG,  PROP(WR)|PROP(RD), 0},
    
    // fee5 value Characteristic Declaration
    // fee5 ind
    [FEE0S_IDX_FEE5_VAL_CHAR]  =   {GATT_DECL_CHARACTERISTIC, PROP(RD), 0},
    // fee5 value Characteristic Value
    [FEE0S_IDX_FEE5_VAL_VAL]   =   {ATT_USER_SERVER_CHAR_FEE5, PROP(I), OPT(NO_OFFSET)|FEE0_CHAR_DATA_LEN},

    // fee5 value Characteristic - Client Characteristic Configuration Descriptor
    [FEE0S_IDX_FEE5_VAL_IND_CFG] = {GATT_DESC_CLIENT_CHAR_CFG,  PROP(RD)|PROP(WR),0},
    
    
};/// Macro used to retrieve permission value from access and rights on attribute.


uint16_t fee0s_get_att_handle( uint8_t att_idx)
{

    fee0s_env_t *fee0s_env = PRF_ENV_GET(FEE0S, fee0s);
    uint16_t handle = GATT_INVALID_HDL;
   
    handle = fee0s_env->start_hdl;

    // increment index according to expected index
    if(att_idx <= FEE0S_IDX_FEE5_VAL_IND_CFG)
    {
        handle += att_idx;
    }
    else
    {
        handle = GATT_INVALID_HDL;
    }
    

    return handle;
}
uint8_t fee0s_get_att_idx(uint16_t handle, uint8_t *att_idx)
{
    fee0s_env_t* fee0s_env = PRF_ENV_GET(FEE0S, fee0s);
    uint8_t status = PRF_APP_ERROR;
    
    // PARASOFT FIX: Check for null pointer before dereferencing
    // Original Parasoft violation: "fee0s_env may possibly be null"
    // Root cause: prf_env_get() can return NULL if profile not initialized 
    // or invalid profile ID. Other functions in this file properly check
    // for NULL (lines 137, 285, 378, 466, 509, 549, 798)
    if (fee0s_env == NULL) {
        // Return error status if profile environment not available
        return PRF_APP_ERROR;
    }
    
    uint16_t hdl_cursor1 = fee0s_env->start_hdl;

    // Browse list of services
    // handle must be greater than current index 
    // check if it's a mandatory index
    if(handle <= (hdl_cursor1 + FEE0S_IDX_FEE5_VAL_IND_CFG))
    {
        *att_idx = handle -hdl_cursor1;
        status = GAP_ERR_NO_ERROR;
        
    }
    
    return (status);
}

/**
 ****************************************************************************************
 * @brief  This function fully manage notification FEE0 service
 *         to peer(s) device(s) according to on-going operation requested by application:
 ****************************************************************************************
 */
__STATIC void fee0s_exe_operation(void)
{

    fee0s_env_t* p_fee0s_env = PRF_ENV_GET(FEE0S, fee0s);

    if((p_fee0s_env != NULL) && (!p_fee0s_env->in_exe_op))
    {
        p_fee0s_env->in_exe_op = true;

        while(!co_list_is_empty(&(p_fee0s_env->wait_queue)) && !(p_fee0s_env->op_ongoing))
        {
            uint16_t status = GAP_ERR_NO_ERROR;
            co_buf_t* p_buf = (co_buf_t*) co_list_pop_front(&(p_fee0s_env->wait_queue));
            fee0s_buf_meta_t* p_buf_meta = (fee0s_buf_meta_t*) co_buf_metadata(p_buf);
            uint32_t conidx_bf = 0;

            // check if a connection index must be ignored
            if(p_buf_meta->conidx != GAP_INVALID_CONIDX)
            {
                conidx_bf = CO_BIT(p_buf_meta->conidx);
            }
            else
            {
                uint8_t  conidx;
                // prepare bit field of connection where event must be triggered
                for(conidx = 0 ; conidx < BLE_CONNECTION_MAX ; conidx++)
                {
                    if((p_fee0s_env->ntf_cfg[conidx] & (1 << p_buf_meta->att_idx)) != 0)
                    {
                        conidx_bf |= CO_BIT(conidx);
                    }
                }
            }

            // Send Notification / Indication
            if(conidx_bf != 0)
            {
     
                // Send Multi point event
                status = gatt_srv_event_mtp_send(conidx_bf, p_fee0s_env->user_lid,
                                                 (p_buf_meta->conidx == GAP_INVALID_CONIDX),(p_buf_meta->att_idx == FEE0S_IDX_FEE4_VAL_VAL) ? GATT_NOTIFY :GATT_INDICATE,
                                                 p_buf_meta->handle, p_buf, true);
                if(status == GAP_ERR_NO_ERROR)
                {
                    p_fee0s_env->op_ongoing = true;
                }
            }
            // Consider job done
            if ((!p_fee0s_env->op_ongoing) && (p_buf_meta->conidx != 0))
            {
                const fee0s_cb_t* p_cb = (const fee0s_cb_t*) p_fee0s_env->prf_env.p_cb;
                // Inform application that event has been sent
                p_cb->cb_fee0s_value_upd_cmp(p_buf_meta->conidx,p_fee0s_env->operation_att,status);
            }

            // release buffer
            co_buf_release(p_buf);
        }

        p_fee0s_env->in_exe_op = false;
    }
}

/****************************************************************************************
 * @brief  Trigger fee4 value notification
 *
 * @param p_bass_env profile environment
 * @param conidx     peer destination connection index
 * @param svc_idx    Service index
 ****************************************************************************************
 */
__STATIC uint16_t fee0s_fee4_notification_value(fee0s_env_t *p_fee0s_env, uint8_t conidx, uint8_t att_idx)
{
    co_buf_t* p_buf = NULL;
    uint16_t status = co_buf_alloc(&p_buf, GATT_BUFFER_HEADER_LEN, p_fee0s_env->fee4_val_len, GATT_BUFFER_TAIL_LEN);

    if(status == CO_BUF_ERR_NO_ERROR)
    {
        fee0s_buf_meta_t* p_buf_meta = (fee0s_buf_meta_t*) co_buf_metadata(p_buf);
        p_buf_meta->conidx          = conidx;
        p_buf_meta->att_idx          = att_idx;
        p_buf_meta->handle          = fee0s_get_att_handle(FEE0S_IDX_FEE4_VAL_VAL);

        memcpy(co_buf_data(p_buf),p_fee0s_env->fee4_val,p_fee0s_env->fee4_val_len);

        // put event on wait queue
        co_list_push_back(&(p_fee0s_env->wait_queue), &(p_buf->hdr));
        // execute operation
        fee0s_exe_operation();
    }
    else
    {
        status = GAP_ERR_INSUFF_RESOURCES;
    }
    return (status);
}

/****************************************************************************************
 * @brief  Trigger fee5 value notification
 *
 * @param p_bass_env profile environment
 * @param conidx     peer destination connection index
 * @param svc_idx    Service index
 ****************************************************************************************
 */
__STATIC uint16_t fee0s_fee5_indication_value(fee0s_env_t *p_fee0s_env, uint8_t conidx, uint8_t att_idx)
{
    co_buf_t* p_buf = NULL;
    uint16_t status = co_buf_alloc(&p_buf, GATT_BUFFER_HEADER_LEN, p_fee0s_env->fee5_val_len, GATT_BUFFER_TAIL_LEN);

    if(status == CO_BUF_ERR_NO_ERROR)
    {
        fee0s_buf_meta_t* p_buf_meta = (fee0s_buf_meta_t*) co_buf_metadata(p_buf);
        p_buf_meta->conidx          = conidx;
        p_buf_meta->att_idx         = att_idx;
        p_buf_meta->handle          = fee0s_get_att_handle(FEE0S_IDX_FEE5_VAL_VAL);

        memcpy(co_buf_data(p_buf),p_fee0s_env->fee5_val,p_fee0s_env->fee5_val_len);

        // put event on wait queue
        co_list_push_back(&(p_fee0s_env->wait_queue), &(p_buf->hdr));
        // execute operation
        fee0s_exe_operation();
    }
    else
    {
        status = GAP_ERR_INSUFF_RESOURCES;
    }
    return (status);
}
/**
 ****************************************************************************************
 * @brief This function is called when peer want to read local attribute database value.
 *
 *        @see gatt_srv_att_read_get_cfm shall be called to provide attribute value
 *
 * @param[in] conidx        Connection index
 * @param[in] user_lid      GATT user local identifier
 * @param[in] token         Procedure token that must be returned in confirmation function
 * @param[in] hdl           Attribute handle
 * @param[in] offset        Data offset
 * @param[in] max_length    Maximum data length to return
 ****************************************************************************************
 */
__STATIC void fee0s_cb_att_read_get(uint8_t conidx, uint8_t user_lid, uint16_t token, uint16_t hdl, uint16_t offset,
                                   uint16_t max_length)
{
    fee0s_env_t* p_fee0s_env = PRF_ENV_GET(FEE0S, fee0s);
    co_buf_t*   p_buf      = NULL;
    uint16_t    status     = PRF_APP_ERROR;
    static uint8_t a[20] = {0};
    
    {
        if(p_fee0s_env != NULL)
        {
            uint8_t  att_idx = 0;
            status = fee0s_get_att_idx(hdl,&att_idx);
            if(status == GAP_ERR_NO_ERROR)
            {
                switch(att_idx)
                {
                    case FEE0S_IDX_FEE1_VAL_VAL:
                    {
                        if(co_buf_alloc(&p_buf, GATT_BUFFER_HEADER_LEN, 1,  GATT_BUFFER_TAIL_LEN) != GAP_ERR_NO_ERROR)
                        {
                            status = ATT_ERR_INSUFF_RESOURCE;
                            break;
                        }
                        a[0]++;                     
                        co_buf_data(p_buf)[0] = a[0];
                        
                    } break;

                    case FEE0S_IDX_FEE1_USER_DESC:
                    {
                        if(co_buf_alloc(&p_buf, GATT_BUFFER_HEADER_LEN, p_fee0s_env->fee1_desc_len,  GATT_BUFFER_TAIL_LEN) != GAP_ERR_NO_ERROR)
                        {
                            status = ATT_ERR_INSUFF_RESOURCE;
                            break;
                        }
                        memcpy(co_buf_data(p_buf),p_fee0s_env->fee1_desc,p_fee0s_env->fee1_desc_len);
                        
                    } break;

                    case FEE0S_IDX_FEE4_VAL_NTF_CFG:
                    {

                        if(co_buf_alloc(&p_buf, GATT_BUFFER_HEADER_LEN, 2,  GATT_BUFFER_TAIL_LEN) != GAP_ERR_NO_ERROR)
                        {
                            status = ATT_ERR_INSUFF_RESOURCE;
                            break;
                        }
                        co_write16p(co_buf_data(p_buf), co_htobs(p_fee0s_env->ntf_cfg[conidx]));                      

                    } break;

                    case FEE0S_IDX_FEE5_VAL_IND_CFG:
                    {

                        if(co_buf_alloc(&p_buf, GATT_BUFFER_HEADER_LEN, 2,  GATT_BUFFER_TAIL_LEN) != GAP_ERR_NO_ERROR)
                        {
                            status = ATT_ERR_INSUFF_RESOURCE;
                            break;
                        }
                        co_write16p(co_buf_data(p_buf), co_htobs(p_fee0s_env->ind_cfg[conidx]));                      

                    } break;
                    
                    default: { 
                        uart_printf("PRF_APP_ERROR\r\n");
                        status = PRF_APP_ERROR;
                         } break;
                }
            }
        }
    }

    // Send result to peer device
    gatt_srv_att_read_get_cfm(conidx, user_lid, token, status, co_buf_data_len(p_buf), p_buf);
    if(p_buf != NULL)
    {
        co_buf_release(p_buf);
    }
}

/**
 ****************************************************************************************
 * @brief This function is called during a write procedure to modify attribute handle.
 *
 *        @see gatt_srv_att_val_set_cfm shall be called to accept or reject attribute
 *        update.
 *
 * @param[in] conidx        Connection index
 * @param[in] user_lid      GATT user local identifier
 * @param[in] token         Procedure token that must be returned in confirmation function
 * @param[in] hdl           Attribute handle
 * @param[in] offset        Value offset
 * @param[in] p_data        Pointer to buffer that contains data to write starting from offset
 ****************************************************************************************
 */
__STATIC void fee0s_cb_att_val_set(uint8_t conidx, uint8_t user_lid, uint16_t token, uint16_t hdl, uint16_t offset,
                                  co_buf_t* p_data)
{
    fee0s_env_t *p_fee0s_env = PRF_ENV_GET(FEE0S, fee0s);
    uint16_t status = PRF_APP_ERROR;

    if(p_fee0s_env != NULL)
    {
        if (co_buf_data_len(p_data) > FEE0_CHAR_DATA_LEN)
        {
            status = PRF_ERR_UNEXPECTED_LEN;
        }
        else
        {
            uint8_t att_idx = 0;
            status = fee0s_get_att_idx(hdl, &att_idx);

            if(status == GAP_ERR_NO_ERROR)
            {
                // Extract value
                uint16_t ntf_cfg = co_btohs(co_read16p(co_buf_data(p_data)));
                
                 // Only update configuration if value for stop or notification enable
                if (   (att_idx == FEE0S_IDX_FEE4_VAL_NTF_CFG)
                    && ((ntf_cfg == PRF_CLI_STOP_NTFIND) || (ntf_cfg == PRF_CLI_START_NTF)))
                {
                    const fee0s_cb_t* p_cb  = (const fee0s_cb_t*) p_fee0s_env->prf_env.p_cb;
                    // Conserve information in environment
                    if (ntf_cfg == PRF_CLI_START_NTF)
                    {
                        // Ntf cfg bit set to 1
                        p_fee0s_env->ntf_cfg[conidx] = PRF_CLI_START_NTF;
                    }
                    else
                    {
                        // Ntf cfg bit set to 0
                        p_fee0s_env->ntf_cfg[conidx] = PRF_CLI_STOP_NTFIND;
                    }

                    // Inform application about bond data update
                    p_cb->cb_bond_data_upd(conidx, att_idx,p_fee0s_env->ntf_cfg[conidx]);
                }else if (   (att_idx == FEE0S_IDX_FEE5_VAL_IND_CFG)
                    && ((ntf_cfg == PRF_CLI_STOP_NTFIND) || (ntf_cfg == PRF_CLI_START_IND)))
                {
                    const fee0s_cb_t* p_cb  = (const fee0s_cb_t*) p_fee0s_env->prf_env.p_cb;

                    // Conserve information in environment
                    if (ntf_cfg == PRF_CLI_START_IND)
                    {
                        // Ntf cfg bit set to 1
                        p_fee0s_env->ind_cfg[conidx] = PRF_CLI_START_IND;
                    }
                    else
                    {
                        // Ntf cfg bit set to 0
                        p_fee0s_env->ind_cfg[conidx] = PRF_CLI_STOP_NTFIND;
                    }

                    // Inform application about bond data update
                    p_cb->cb_bond_data_upd(conidx, att_idx,p_fee0s_env->ntf_cfg[conidx]);
                }else if ((att_idx == FEE0S_IDX_FEE2_VAL_VAL)|| (att_idx == FEE0S_IDX_FEE3_VAL_VAL))
                {
                    const fee0s_cb_t* p_cb  = (const fee0s_cb_t*) p_fee0s_env->prf_env.p_cb;
                    // Inform application about bond data update
                    p_cb->cb_att_data_upd(conidx, att_idx,co_buf_data_len(p_data),co_buf_data(p_data));
                }
                else
                {
                    status = PRF_APP_ERROR;
                }
            }
        }
    }

    gatt_srv_att_val_set_cfm(conidx, user_lid, token, status);
}

/**
 ****************************************************************************************
 * @brief This function is called when GATT server user has initiated event send to peer
 *        device or if an error occurs.
 *
 * @param[in] conidx        Connection index
 * @param[in] user_lid      GATT user local identifier
 * @param[in] dummy         Dummy parameter provided by upper layer for command execution
 * @param[in] status        Status of the procedure (@see enum hl_err)
 ****************************************************************************************
 */
__STATIC void fee0s_cb_event_sent(uint8_t conidx, uint8_t user_lid, uint16_t dummy, uint16_t status)
{
    //if(conidx == GAP_INVALID_CONIDX)
    {
        // Consider job done
        fee0s_env_t *p_fee0s_env = PRF_ENV_GET(FEE0S, fee0s);
        if(p_fee0s_env != NULL)
        {
            const fee0s_cb_t* p_cb  = (const fee0s_cb_t*) p_fee0s_env->prf_env.p_cb;
            p_fee0s_env->op_ongoing = false;

            // Inform application that event has been sent
            p_cb->cb_fee0s_value_upd_cmp(conidx,p_fee0s_env->operation_att,status);

            // continue operation execution
            fee0s_exe_operation();
        }
    }
}

/// Service callback hander
__STATIC const gatt_srv_cb_t fee0s_cb =
{
        .cb_event_sent    = fee0s_cb_event_sent,
        .cb_att_read_get  = fee0s_cb_att_read_get,
        .cb_att_event_get = NULL,
        .cb_att_info_get  = NULL,
        .cb_att_val_set   = fee0s_cb_att_val_set,
};



/**
 ****************************************************************************************
 * @brief Update a fee4 value
 *
 * Wait for @see cb_fee4_value_upd_cmp execution before starting a new procedure
 *
 * @param[in] p_temp_meas   Pointer to Temperature Measurement information
 * @param[in] batt_level   Stable or intermediary type of temperature (True stable meas, else false)
 *
 * @return Status of the function execution (@see enum hl_err)
 ****************************************************************************************
 */
uint16_t fee0s_fee4_value_notification_upd(uint8_t conidx,uint16_t len, const uint8_t *data)
{
    fee0s_env_t *p_fee0s_env = PRF_ENV_GET(FEE0S, fee0s);
    uint16_t status = PRF_ERR_REQ_DISALLOWED;

    if(p_fee0s_env != NULL)
    {
        // Parameter sanity check
        if (len < FEE0_CHAR_DATA_LEN)
        {
            // update the fee5  value      
            memcpy(p_fee0s_env->fee4_val,data,len);
            p_fee0s_env->fee4_val_len = len;
            p_fee0s_env->operation_att = FEE0S_IDX_FEE4_VAL_VAL;
            
            status = fee0s_fee4_notification_value(p_fee0s_env, conidx,FEE0S_IDX_FEE4_VAL_VAL);
        }
        else
        {
            status = PRF_ERR_INVALID_PARAM;
        }
    }

    return (status);
}


 
/**
 ****************************************************************************************
 * @brief Update a fee5 value
 *
 * Wait for @see cb_fee5_value_upd_cmp execution before starting a new procedure
 *
 * @param[in] p_temp_meas   Pointer to Temperature Measurement information
 * @param[in] batt_level   Stable or intermediary type of temperature (True stable meas, else false)
 *
 * @return Status of the function execution (@see enum hl_err)
 ****************************************************************************************
 */
uint16_t fee0s_fee5_value_indication_upd(uint8_t conidx,uint16_t len, const uint8_t *data)
{
    fee0s_env_t *p_fee0s_env = PRF_ENV_GET(FEE0S, fee0s);
    uint16_t status = PRF_ERR_REQ_DISALLOWED;

    if(p_fee0s_env != NULL)
    {
        // Parameter sanity check
        if (len < FEE0_CHAR_DATA_LEN)
        {
            // update the fee5  value      
            memcpy(p_fee0s_env->fee5_val,data,len);
            p_fee0s_env->fee5_val_len = len;
            p_fee0s_env->operation_att = FEE0S_IDX_FEE5_VAL_VAL;
            status = fee0s_fee5_indication_value(p_fee0s_env, conidx,FEE0S_IDX_FEE5_VAL_VAL);
        }
        else
        {
            status = PRF_ERR_INVALID_PARAM;
        }
    }

    return (status);
}



__STATIC int fee0s_fee4_value_notification_upd_req_handler(ke_msg_id_t const msgid,
                                            struct fee0s_fee45_val_upd_req const *p_param,
                                            ke_task_id_t const dest_id,
                                            ke_task_id_t const src_id)
{

    uint16_t status = fee0s_fee4_value_notification_upd(p_param->conidx,p_param->length, p_param->value);

    if(status != GAP_ERR_NO_ERROR)
    {
        // an error occurs, trigger it.
        struct fee0s_fee45_val_upd_rsp *p_rsp = KE_MSG_ALLOC(FEE0S_FEE4_VALUE_UPD_RSP, src_id, dest_id,
                                                             fee0s_fee45_val_upd_rsp);
                                                                    
        if(p_rsp != NULL)
        {
            p_rsp->status = status;
            p_rsp->conidx = p_param->conidx;
            ke_msg_send(p_rsp);
        }
    }

    return (KE_MSG_CONSUMED);
}



__STATIC int fee0s_fee5_value_indication_upd_req_handler(ke_msg_id_t const msgid,
                                            struct fee0s_fee45_val_upd_req const *p_param,
                                            ke_task_id_t const dest_id,
                                            ke_task_id_t const src_id)
{
    uint16_t status = fee0s_fee5_value_indication_upd(p_param->conidx,p_param->length, p_param->value);

    if(status != GAP_ERR_NO_ERROR)
    {
        // an error occurs, trigger it.
        struct fee0s_fee45_val_upd_rsp *p_rsp = KE_MSG_ALLOC(FEE0S_FEE5_VALUE_UPD_RSP, src_id, dest_id,
                                                             fee0s_fee45_val_upd_rsp);      
        if(p_rsp != NULL)
        {
            p_rsp->status = status;
            p_rsp->conidx = p_param->conidx;
            ke_msg_send(p_rsp);
        }
    }

    return (KE_MSG_CONSUMED);
}


/// Default State handlers definition
KE_MSG_HANDLER_TAB(fee0s)
{
    {FEE0S_FEE4_VALUE_UPD_REQ,      (ke_msg_func_t) fee0s_fee4_value_notification_upd_req_handler},
    {FEE0S_FEE5_VALUE_UPD_REQ,      (ke_msg_func_t) fee0s_fee5_value_indication_upd_req_handler},
};

/**
 ****************************************************************************************
 * @brief Completion of value update
 *
 * @param[in] status Status of the procedure execution (@see enum hl_err)
 ****************************************************************************************
 */
void fee0s_cb_value_upd_cmp(uint8_t conidx,uint8_t att_idx,uint16_t status)
{
     uint16_t att_idx2msg_id = FEE0S_FEE4_VALUE_UPD_RSP;
    if(att_idx == FEE0S_IDX_FEE4_VAL_VAL)
    {
        att_idx2msg_id = FEE0S_FEE4_VALUE_UPD_RSP;
    }else if(att_idx == FEE0S_IDX_FEE5_VAL_VAL)
    {
        att_idx2msg_id = FEE0S_FEE5_VALUE_UPD_RSP;
    }
    struct fee0s_fee45_val_upd_rsp *p_rsp =
            KE_MSG_ALLOC(att_idx2msg_id, PRF_DST_TASK(FEE0S), PRF_SRC_TASK(FEE0S), fee0s_fee45_val_upd_rsp);

    if(p_rsp)
    {
        p_rsp->status = status;
        p_rsp->conidx = conidx;
        ke_msg_send(p_rsp);
    }
}

/**
 ****************************************************************************************
 * @brief Completion of battery level update
 *
 * @param[in] status Status of the procedure execution (@see enum hl_err)
 ****************************************************************************************
 */
void fee0s_cb_att_data_upd(uint8_t conidx,uint8_t att_idx,uint16_t len, uint8_t *data)
{
    uint16_t att_idx2msg_id = FEE0S_FEE2_WRITER_CMD_IND;

    if(att_idx == FEE0S_IDX_FEE2_VAL_VAL)
    {
        att_idx2msg_id = FEE0S_FEE2_WRITER_CMD_IND;
    }else if(att_idx == FEE0S_IDX_FEE3_VAL_VAL)
    {
        att_idx2msg_id = FEE0S_FEE3_WRITER_REQ_IND;
    }

    struct fee0s_fee23_writer_ind *p_ind =
            KE_MSG_ALLOC(att_idx2msg_id, PRF_DST_TASK(FEE0S), PRF_SRC_TASK(FEE0S), fee0s_fee23_writer_ind);

    if(p_ind)
    {
        p_ind->conidx = conidx;
        p_ind->length = len;
        memcpy(p_ind->value,data,len);
        ke_msg_send(p_ind);
    }
}

/**
 ****************************************************************************************
 * @brief Inform that Bond data updated for the connection.
 *
 * @param[in] conidx        Connection index
 * @param[in] ntf_cfg       Notification Configuration
 ****************************************************************************************
 */
void fee0s_cb_bond_data_upd(uint8_t conidx,uint8_t att_idx, uint8_t ntf_ind_cfg)
{
    uint16_t attidx2msgid = FEE0S_FEE4_VALUE_NTF_CFG_IND;
    if(att_idx == FEE0S_IDX_FEE4_VAL_NTF_CFG)
    {
        attidx2msgid = FEE0S_FEE4_VALUE_NTF_CFG_IND;
    }else if(att_idx == FEE0S_IDX_FEE5_VAL_IND_CFG)
    {
        attidx2msgid = FEE0S_FEE5_VALUE_IND_CFG_IND;
    }
    struct fee0s_fee45_val_ntf_cfg_ind* p_ind =
            KE_MSG_ALLOC(attidx2msgid, PRF_DST_TASK(FEE0S), PRF_SRC_TASK(FEE0S), fee0s_fee45_val_ntf_cfg_ind);

    if(p_ind != NULL)
    {
        p_ind->conidx = conidx;
        p_ind->ntf_ind_cfg = ntf_ind_cfg;

        ke_msg_send(p_ind);
    }
}




/// Default Message handle
__STATIC const fee0s_cb_t fee0s_msg_cb =
{
    .cb_fee0s_value_upd_cmp = fee0s_cb_value_upd_cmp,
    .cb_att_data_upd      = fee0s_cb_att_data_upd,
    .cb_bond_data_upd = fee0s_cb_bond_data_upd
};

/**
 ****************************************************************************************
 * @brief Initialization of the OADS module.
 * This function performs all the initializations of the Profile module.
 *  - Creation of database (if it's a service)
 *  - Allocation of profile required memory
 *  - Initialization of task descriptor to register application
 *      - Task State array
 *      - Number of tasks
 *      - Default task handler
 *
 * @param[out]    p_env        Collector or Service allocated environment data.
 * @param[in|out] p_start_hdl  Service start handle (0 - dynamically allocated), only applies for services.
 * @param[in]     sec_lvl      Security level (@see enum gatt_svc_info_bf)
 * @param[in]     user_prio    GATT User priority
 * @param[in]     p_param      Configuration parameters of profile collector or service (32 bits aligned)
 * @param[in]     p_cb         Callback structure that handles event from profile
 *
 * @return status code to know if profile initialization succeed or not.
 ****************************************************************************************
 */
__STATIC uint8_t fee0s_init (prf_data_t *p_env, uint16_t* p_start_hdl,  uint8_t sec_lvl,uint8_t user_prio, 
                 struct fee0s_db_cfg *p_params, const fee0s_cb_t* p_cb)
{

       // DB Creation Status
    uint16_t status = GAP_ERR_NO_ERROR;
    uint8_t user_lid = GATT_INVALID_USER_LID;
    do
    {
        fee0s_env_t* p_fee0s_env;
        uint16_t shdl;
        uint16_t features = 0;

        #if (BLE_HL_MSG_API)
        if(p_cb == NULL)
        {
            p_cb = &(fee0s_msg_cb);
        }
        #endif // (BLE_HL_MSG_API)

        if((p_params == NULL) || (p_start_hdl == NULL) || (p_cb == NULL) || (p_cb->cb_fee0s_value_upd_cmp == NULL)
           || (p_cb->cb_bond_data_upd == NULL) || (p_cb->cb_att_data_upd == NULL))
        {
            
            status = GAP_ERR_INVALID_PARAM;
            break;
        }

        // register BASS user
        status = gatt_user_srv_register(260, user_prio, &fee0s_cb, &user_lid);
        if(status != GAP_ERR_NO_ERROR) break;

        // Service content flag
        uint32_t cfg_flag = FEE0S_CFG_FLAG_MANDATORY_MASK;
        features |= p_params->features;

       

        shdl = *p_start_hdl;

        // Add GAP service
        status = gatt_db_svc16_add(user_lid, sec_lvl, ATT_USER_SERVER_FEE0, FEE0S_IDX_NB,
                                    (uint8_t *)&cfg_flag, &(fee0_att_db[0]), FEE0S_IDX_NB, &(shdl));
        if(status != GAP_ERR_NO_ERROR) break;

        //-------------------- allocate memory required for the profile  ---------------------
        p_fee0s_env = (fee0s_env_t *) ke_malloc(sizeof(fee0s_env_t), KE_MEM_ATT_DB);

        if(p_fee0s_env != NULL)
        {
            // allocate BASS required environment variable
            p_env->p_env = (prf_hdr_t *) p_fee0s_env;
            p_fee0s_env->start_hdl  = shdl;
            p_fee0s_env->features   = features;
            p_fee0s_env->user_lid   = user_lid;
            p_fee0s_env->nb_svc     = 1;
            p_fee0s_env->op_ongoing = false;
            p_fee0s_env->in_exe_op  = false;

            p_fee0s_env->fee1_desc_len = p_params->fee1_desc_len;
            memcpy(p_fee0s_env->fee1_desc,p_params->fee1_desc,p_params->fee1_desc_len);

            co_list_init(&(p_fee0s_env->wait_queue));
            memset(p_fee0s_env->ntf_cfg, 0, BLE_CONNECTION_MAX);
         
            // initialize profile environment variable
            p_fee0s_env->prf_env.p_cb     = p_cb;
            #if (BLE_HL_MSG_API)
            p_env->desc.msg_handler_tab  = fee0s_msg_handler_tab;
            p_env->desc.msg_cnt          = ARRAY_LEN(fee0s_msg_handler_tab);
            #endif // (BLE_HL_MSG_API)

            *p_start_hdl = shdl;
        }
        else
        {
            status = GAP_ERR_INSUFF_RESOURCES;
        }

    }
    while(0);


    if((status != GAP_ERR_NO_ERROR) && (user_lid != GATT_INVALID_USER_LID))
    {
        gatt_user_unregister(user_lid);
    }

    return (status);
 
}

/**
 ****************************************************************************************
 * @brief Destruction of the profile module - due to a reset or profile remove.
 *
 * This function clean-up allocated memory.
 *
 * @param[in|out]    p_env        Collector or Service allocated environment data.
 * @param[in]        reason       Destroy reason (@see enum prf_destroy_reason)
 *
 * @return status of the destruction, if fails, profile considered not removed.
 ****************************************************************************************
 */
__STATIC uint16_t fee0s_destroy(prf_data_t *p_env, uint8_t reason)
{
    uint16_t status = GAP_ERR_NO_ERROR;
    fee0s_env_t *p_fee0s_env = (fee0s_env_t *) p_env->p_env;

    if(reason != PRF_DESTROY_RESET)
    {
        status = gatt_user_unregister(p_fee0s_env->user_lid);
    }

    if(status == GAP_ERR_NO_ERROR)
    {
        if(reason != PRF_DESTROY_RESET)
        {
            // remove buffer in wait queue
            while(!co_list_is_empty(&p_fee0s_env->wait_queue))
            {
                co_buf_t* p_buf = (co_buf_t*) co_list_pop_front(&p_fee0s_env->wait_queue);
                co_buf_release(p_buf);
            }
        }

        // free profile environment variables
        p_env->p_env = NULL;
        ke_free(p_fee0s_env);
    }

    return (status);
}
/**
 ****************************************************************************************
 * @brief @brief Handles Connection creation
 *
 * @param[in|out]    env          Collector or Service allocated environment data.
 * @param[in]        conidx       Connection index
 * @param[in]        p_con_param  Pointer to connection parameters information
 ****************************************************************************************
 */
__STATIC void fee0s_con_create(prf_data_t *p_env, uint8_t conidx, const gap_con_param_t* p_con_param)
{
    uart_printf("%s\r\n",__func__);
    fee0s_env_t *p_fee0s_env = (fee0s_env_t *) p_env->p_env;
    ASSERT_ERR(conidx < BLE_CONNECTION_MAX);
    // force notification config to zero when peer device is connected
    p_fee0s_env->ntf_cfg[conidx] = 0;
}


/**
 ****************************************************************************************
 * @brief Handles Disconnection
 *
 * @param[in|out]    p_env      Collector or Service allocated environment data.
 * @param[in]        conidx     Connection index
 * @param[in]        reason     Detach reason
 ****************************************************************************************
 */
__STATIC void fee0s_con_cleanup(prf_data_t *p_env, uint8_t conidx, uint16_t reason)
{
    fee0s_env_t *p_fee0s_env = (fee0s_env_t *) p_env->p_env;
    ASSERT_ERR(conidx < BLE_CONNECTION_MAX);
    // force notification config to zero when peer device is disconnected
    p_fee0s_env->ntf_cfg[conidx] = 0;
}



/// FEE0S Task interface required by profile manager
const prf_task_cbs_t fee0s_itf =
{
    .cb_init          = (prf_init_cb) fee0s_init,
    .cb_destroy       = fee0s_destroy,
    .cb_con_create    = fee0s_con_create,
    .cb_con_cleanup   = fee0s_con_cleanup,
    .cb_con_upd       = NULL,
};


/**
 ****************************************************************************************
 * @brief Retrieve service profile interface
 *
 * @return service profile interface
 ****************************************************************************************
 */
const prf_task_cbs_t *fee0s_prf_itf_get(void)
{
    return &fee0s_itf;
}


#endif // (BLE_FEE0_SERVER)


 
