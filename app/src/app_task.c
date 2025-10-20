/**
 ****************************************************************************************
 *
 * @file app_task.c
 *
 * @brief RW APP Task implementation
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APPTASK
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"          // SW configuration

#if (BLE_APP_PRESENT)
#include "rwapp_config.h"
#include "app_task.h"             // Application Manager Task API
#include "app.h"                  // Application Manager Definition
#include "gapm_msg.h"            // GAP Manager Task API
#include "gapc_msg.h"            // GAP Manager Task API
#include <string.h>
#include "co_utils.h"
#include "ke_timer.h"             // Kernel timer
#include "gatt_int.h"
#if (BLE_APP_SEC)
#include "app_sec.h"              // Security Module Definition
#endif //(BLE_APP_SEC)

#if (BLE_APP_HT)
#include "app_ht.h"               // Health Thermometer Module Definition
#include "htpt_task.h"
#endif //(BLE_APP_HT)

#if (BLE_APP_DIS)
#include "app_dis.h"              // Device Information Module Definition
#include "diss_msg.h"
#endif //(BLE_APP_DIS)

#if (BLE_APP_BATT)
#include "app_batt.h"             // Battery Module Definition
#include "bass_msg.h"
#endif //(BLE_APP_BATT)

#if (BLE_APP_FEE0S)
#include "app_fee0.h"             // FEE0S Module Definition
#include "fee0s_msg.h"
#endif //(BLE_APP_FEE0S)

#if (BLE_APP_OADS)
#include "app_oads.h"             // OADS Module Definition
#include "oads_msg.h"
#endif //(BLE_APP_OADS)

#if (BLE_APP_HID)
#include "app_hid.h"              // HID Module Definition
#include "hogpd_msg.h"
#endif //(BLE_APP_HID)

#if (BLE_APP_AM0)
#include "app_am0.h"              // Audio Mode 0 Application
#endif //(BLE_APP_AM0)

#if (DISPLAY_SUPPORT)
#include "app_display.h"          // Application Display Definition
#endif //(DISPLAY_SUPPORT)

#if (BLE_APP_MESH)
#include "app_mesh.h"                // Mesh Module Definition
#if (DISPLAY_SUPPORT)
#include "app_display_mesh.h"     // Mesh Display Definition
#endif //(DISPLAY_SUPPORT)
#endif //(BLE_APP_MESH)
#include "driver_gpio.h"  
#include "bsp.h"

extern uint8_t bMasterReady;
extern uint8_t bBleWakeup;
extern uint8_t bWorking;
extern uint16_t	showBatLevelTime;

static uint8_t app_get_handler(const struct app_subtask_handlers *handler_list_desc,
                               ke_msg_id_t msgid,
                               void *p_param,
                               ke_task_id_t src_id)
{
    // Counter
    uint8_t counter;

    // Get the message handler function by parsing the message table
    for (counter = handler_list_desc->msg_cnt; 0 < counter; counter--)
    {
        struct ke_msg_handler handler
                = (struct ke_msg_handler)(*(handler_list_desc->p_msg_handler_tab + counter - 1));

        if ((handler.id == msgid) ||
            (handler.id == KE_MSG_DEFAULT_HANDLER))
        {
            // If handler is NULL, message should not have been received in this state
            ASSERT_ERR(handler.func);

            return (uint8_t)(handler.func(msgid, p_param, TASK_APP, src_id));
        }
    }

    // If we are here no handler has been found, drop the message
    return (KE_MSG_CONSUMED);
}


/*
 * MESSAGE HANDLERS
 ****************************************************************************************
 */
#if (BLE_APP_PRF)
/**
 ****************************************************************************************
 * @brief Handles GAPM_ACTIVITY_CREATED_IND event
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance.
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapm_activity_created_ind_handler(ke_msg_id_t const msgid,
                                             struct gapm_activity_created_ind const *p_param,
                                             ke_task_id_t const dest_id,
                                             ke_task_id_t const src_id)
{
    if (app_env.adv_state == APP_ADV_STATE_CREATING)
    {
        // Store the advertising activity index
        app_env.adv_actv_idx = p_param->actv_idx;
    }

    return (KE_MSG_CONSUMED);
}

/**
 ****************************************************************************************
 * @brief Handles GAPM_ACTIVITY_STOPPED_IND event.
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] param     Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance.
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapm_activity_stopped_ind_handler(ke_msg_id_t const msgid,
                                             struct gapm_activity_stopped_ind const *p_param,
                                             ke_task_id_t const dest_id,
                                             ke_task_id_t const src_id)
{
    if (app_env.adv_state == APP_ADV_STATE_STARTED)
    {
        // Perform next operation
        // Go created state
        app_env.adv_state = APP_ADV_STATE_CREATED;  
    }

    return (KE_MSG_CONSUMED);
}
#endif //(BLE_APP_PRF)

/**
 ****************************************************************************************
 * @brief Handles GAPM_PROFILE_ADDED_IND event
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] param     Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance.
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapm_profile_added_ind_handler(ke_msg_id_t const msgid,
                                          struct gapm_profile_added_ind *p_param,
                                          ke_task_id_t const dest_id,
                                          ke_task_id_t const src_id)
{
    // Current State
    ke_state_t state = ke_state_get(dest_id);
    uart_printf("app %s,prf_task_id:0x%x,prf_task_nb:0x%x,start_hdl:%d\r\n",__func__,p_param->prf_task_id,p_param->prf_task_nb ,p_param->start_hdl);
    if (state == APP_CREATE_DB)
    {
        switch (p_param->prf_task_id)
        {
            #if (BLE_APP_AM0)
            case (TASK_ID_AM0_HAS):
            {
                app_am0_set_prf_task(p_param->prf_task_nb);
            } break;
            #endif //(BLE_APP_AM0)

            #if (BLE_APP_MESH)
            case (TASK_ID_MESH):
            {
                app_mesh_set_prf_task(p_param->prf_task_nb);
            } break;
            #endif //(BLE_APP_MESH)

            default: /* Nothing to do */ break;
        }
    }
    else
    {
        ASSERT_INFO(0, state, src_id);
    }
    return (KE_MSG_CONSUMED);
}

void app_get_con_rssi(void)
{
    struct gapc_get_info_cmd *p_cmd = KE_MSG_ALLOC(GAPC_GET_INFO_CMD,
                                                               KE_BUILD_ID(TASK_GAPC, 0), TASK_APP,
                                                               gapc_get_info_cmd);

     // request peer device name.
     p_cmd->operation = GAPC_GET_CON_RSSI;

    // send command
     ke_msg_send(p_cmd);
}                                          

/**
 ****************************************************************************************
 * @brief Handles GAP manager command complete events.
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance (TASK_GAP).
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
 
static int gapm_cmp_evt_handler(ke_msg_id_t const msgid,
                                struct gapm_cmp_evt const *p_param,
                                ke_task_id_t const dest_id,
                                ke_task_id_t const src_id)
{
    #if (NVDS_SUPPORT)
    //uint8_t key_len = KEY_LEN;
    #endif //(NVDS_SUPPORT)
    uart_printf("app gapm_cmp_evt_handler operation:0x%x,stu:%x,actv_idx:%x\r\n",p_param->operation,p_param->status,p_param->actv_idx);
    switch(p_param->operation)
    {
        // Reset completed
        case (GAPM_RESET):
        {
            uart_printf("GAPM_RESET\r\n");
            if(p_param->status == GAP_ERR_NO_ERROR)
            {
                #if (BLE_APP_HID)
                app_hid_start_mouse();
                #endif //(BLE_APP_HID)

                // Set Device configuration
                struct gapm_set_dev_config_cmd* p_cmd = KE_MSG_ALLOC(GAPM_SET_DEV_CONFIG_CMD,
                                                                   TASK_GAPM, TASK_APP,
                                                                   gapm_set_dev_config_cmd);
                // Set the operation
                p_cmd->operation = GAPM_SET_DEV_CONFIG;
                #if (BLE_APP_PRF)
                // Set the device role - Peripheral
                p_cmd->role = GAP_ROLE_PERIPHERAL;
                #elif (BLE_APP_MESH)
                p_cmd->role = GAP_ROLE_ALL;
                #endif //(BLE_APP_PRF)

                #if (BLE_APP_SEC_CON)
                // The Max MTU is increased to support the Public Key exchange
                // HOWEVER, with secure connections enabled you cannot sniff the 
                // LEAP and LEAS protocols
                p_cmd->max_mtu = 160;
                p_cmd->pairing_mode = GAPM_PAIRING_SEC_CON | GAPM_PAIRING_LEGACY;
                #else // !(BLE_APP_SEC_CON)
                // Do not support secure connections
                p_cmd->pairing_mode = GAPM_PAIRING_LEGACY;
                #endif //(BLE_APP_SEC_CON)
                
                // Set Data length parameters
                p_cmd->sugg_max_tx_octets = BLE_MAX_OCTETS;
                p_cmd->sugg_max_tx_time   = LE_MAX_TIME;
                 
                #if (BLE_APP_HID)
                // Enable Slave Preferred Connection Parameters present
                p_cmd->att_cfg = 0;
                SETF(p_cmd->att_cfg, GAPM_ATT_SLV_PREF_CON_PAR_EN, 1);
                #endif //(BLE_APP_HID)

                // Host privacy enabled by default
                p_cmd->privacy_cfg = 0;
                
                #if (BLE_APP_AM0)
                p_cmd->audio_cfg   = GAPM_MASK_AUDIO_AM0_SUP;
                #endif //(BLE_APP_AM0)

                #if 0//(NVDS_SUPPORT)
                nvds_tag_len_t len;
                if (nvds_get(NVDS_TAG_BD_ADDRESS, &len, &p_cmd->addr.addr[0]) == NVDS_OK)
                {
                    // Check if address is a static random address
                    if (p_cmd->addr.addr[5] & 0xC0)
                    {
                        // Host privacy enabled by default
                        p_cmd->privacy_cfg |= GAPM_PRIV_CFG_PRIV_ADDR_BIT;
                    }
                }
                #endif //(NVDS_SUPPORT)

                #if (NVDS_SUPPORT)
                #if (BLE_APP_PRF)
                if(0) //((app_sec_get_bond_status()==true) &&
              //      (nvds_get(NVDS_TAG_LOC_IRK, &key_len, app_env.loc_irk) == NVDS_OK))
                {
                    memcpy(p_cmd->irk.key, app_env.loc_irk, 16);
                }
                else
                #elif (BLE_APP_MESH)
                if (nvds_get(NVDS_TAG_LOC_IRK, &key_len, app_env.loc_irk) == NVDS_OK)
                {
                    memcpy(p_cmd->irk.key, app_env.loc_irk, 16);
                }
                #endif // (BLE_APP_PRF)
                #endif //(NVDS_SUPPORT)
                {
                    memset((void *)&p_cmd->irk.key[0], 0x00, KEY_LEN);
                }

                #if (BLE_APP_MESH)
                // Set the duration before regenerate device address. - in seconds
                p_cmd->renew_dur = 0x0096;
                p_cmd->gap_start_hdl = 0;
                p_cmd->gatt_start_hdl = 0;
                p_cmd->att_cfg = 0x0080;
                p_cmd->max_mtu = 0x02A0;
                p_cmd->max_mps = 0x02A0;
                p_cmd->max_nb_lecb = 0x0A;
                //p_cmd->Pad = 0x00;
                p_cmd->tx_pref_phy = 0;
                p_cmd->rx_pref_phy = 0;
                p_cmd->tx_path_comp = 0;
                p_cmd->rx_path_comp = 0;
                #endif //(BLE_APP_MESH)

                // Send message
                ke_msg_send(p_cmd);
            }
            else
            {
                ASSERT_ERR(0);
            }
        }
        break;

        case (GAPM_PROFILE_TASK_ADD):
        {
            uart_printf("GAPM_PROFILE_TASK_ADD\r\n");
           // Add the next requested service
            if (!app_add_svc())
            {
                // Go to the ready state
                ke_state_set(TASK_APP, APP_READY);

                #if (BLE_PERIPHERAL) 
                // No more service to add, create advertising                
                if(app_env.adv_state==APP_ADV_STATE_IDLE)
                {
                    // appm_adv_fsm_next();
                    app_create_advertising();
                }
                #endif
            }
        }
        break;

        #if (BLE_APP_PRF)
        case (GAPM_GEN_RAND_NB) :
        {
            uart_printf("GAPM_GEN_RAND_NB\r\n");
            if (app_env.rand_cnt == 1)
            {
                // Generate a second random number
                app_env.rand_cnt++;
                struct gapm_gen_rand_nb_cmd *p_cmd = KE_MSG_ALLOC(GAPM_GEN_RAND_NB_CMD,
                                                                TASK_GAPM, TASK_APP,
                                                                gapm_gen_rand_nb_cmd);
                p_cmd->operation = GAPM_GEN_RAND_NB;
                ke_msg_send(p_cmd);
            }
            else
            {
                struct gapm_set_irk_cmd *p_cmd = KE_MSG_ALLOC(GAPM_SET_IRK_CMD,
                                                        TASK_GAPM, TASK_APP,
                                                        gapm_set_irk_cmd);
                app_env.rand_cnt=0;
                ///  - GAPM_SET_IRK
                p_cmd->operation = GAPM_SET_IRK;
                memcpy(&p_cmd->irk.key[0], &app_env.loc_irk[0], KEY_LEN);
                ke_msg_send(p_cmd);
            }
        }
        break;
        #endif //(BLE_APP_PRF)

        #if (BLE_APP_PRF)
       // case (GAPM_SET_IRK):
       case (GAPM_SET_DEV_CONFIG):
        {
           // uart_printf("GAPM_SET_IRK\r\n");
            // ASSERT_INFO(p_param->status == GAP_ERR_NO_ERROR, p_param->operation, p_param->status);
            // If not Bonded already store the generated value in NVDS
         //   if (app_sec_get_bond_status()==false)
              if (0)
            {
                #if (NVDS_SUPPORT)
                if (nvds_put(NVDS_TAG_LOC_IRK, KEY_LEN, (uint8_t *)&app_env.loc_irk) != NVDS_OK)
                #endif //(NVDS_SUPPORT)
                {
                    ASSERT_INFO(0, 0, 0);
                }
            }

            app_env.rand_cnt = 0;

              // Go to the create db state
            ke_state_set(TASK_APP, APP_CREATE_DB);

            // Add the first required service in the database
            // and wait for the PROFILE_ADDED_IND
            app_add_svc();
            
        }
        break;
        #endif //(BLE_APP_PRF)
        
        #if (BLE_APP_PRF)
        case (GAPM_CREATE_ADV_ACTIVITY):
        {
            #if (BLE_PERIPHERAL) 
            // Sanity checks
            ASSERT_INFO(app_env.adv_op == p_param->operation, app_env.adv_op, p_param->operation);
            ASSERT_INFO(p_param->status == GAP_ERR_NO_ERROR, p_param->status, app_env.adv_op);
            if((app_env.adv_op == p_param->operation) && (p_param->status == GAP_ERR_NO_ERROR))
            {
                //advertising creating,to set adv data                 
                if(app_env.adv_state == APP_ADV_STATE_CREATING)
                {
                    // appm_adv_fsm_next();
                    app_set_adv_data();
                }
            }
            
            #endif

        }break;

        case (GAPM_STOP_ACTIVITY):
        {        
            #if (BLE_PERIPHERAL)// Go created state
            if((app_env.adv_op == p_param->operation) && (p_param->status == GAP_ERR_NO_ERROR))
            {
                app_env.adv_state = APP_ADV_STATE_CREATED;    
            }
            
            #endif
        }break;

        case (GAPM_START_ACTIVITY):
        {
            #if (BLE_PERIPHERAL) 
                                    // Sanity checks
            ASSERT_INFO(app_env.adv_op == p_param->operation, app_env.adv_op, p_param->operation);
            ASSERT_INFO(p_param->status == GAP_ERR_NO_ERROR, p_param->status, app_env.adv_op);
            // No more service to add, create advertising    
            if((app_env.adv_op == p_param->operation) && (p_param->status == GAP_ERR_NO_ERROR))
            {
                // Go to started state
                app_env.adv_state = APP_ADV_STATE_STARTED;
            }            
            
            #endif
        }break;

        case (GAPM_DELETE_ACTIVITY):
        {
            #if (BLE_PERIPHERAL)
            if((app_env.adv_op == p_param->operation) && (p_param->status == GAP_ERR_NO_ERROR))
            {
                // Re-Invoke Advertising
                app_env.adv_state = APP_ADV_STATE_IDLE;
            }
            #endif
        }break;

        case (GAPM_SET_ADV_DATA):
        {
            #if (BLE_PERIPHERAL) 
            // Sanity checks
            ASSERT_INFO(app_env.adv_op == p_param->operation, app_env.adv_op, p_param->operation);
            ASSERT_INFO(p_param->status == GAP_ERR_NO_ERROR, p_param->status, app_env.adv_op);
            if((app_env.adv_op == p_param->operation) && (p_param->status == GAP_ERR_NO_ERROR))
            {
                // //advertising  data set,next set scan rsp data              
                if(app_env.adv_state == APP_ADV_STATE_SETTING_ADV_DATA)
                {
                    app_set_scan_rsp_data();
                }
            }
            
            #endif

        }break;

        case (GAPM_SET_SCAN_RSP_DATA):
        {
            #if (BLE_PERIPHERAL) 
            // Sanity checks
            ASSERT_INFO(app_env.adv_op == p_param->operation, app_env.adv_op, p_param->operation);
            ASSERT_INFO(p_param->status == GAP_ERR_NO_ERROR, p_param->status, app_env.adv_op);

            if(app_env.adv_state == APP_ADV_STATE_SETTING_SCAN_RSP_DATA)
            {
                // Start advertising activity
                app_start_advertising();
            }
            #endif

        } break;

        case (GAPM_DELETE_ALL_ACTIVITIES) :
        {
            #if (BLE_PERIPHERAL)
            // Re-Invoke Advertising
            app_env.adv_state = APP_ADV_STATE_IDLE;
            #endif

        } break;
        #endif //(BLE_APP_PRF)

        default:
        {
            // Drop the message
        }
        break;
    }

    return (KE_MSG_CONSUMED);
}

static int gapc_get_dev_info_req_ind_handler(ke_msg_id_t const msgid,
        struct gapc_get_dev_info_req_ind const *p_param,
        ke_task_id_t const dest_id,
        ke_task_id_t const src_id)
{ 
    switch(p_param->req)
    {
        case GAPC_DEV_NAME:
        {
            struct gapc_get_dev_info_cfm * cfm = KE_MSG_ALLOC_DYN(GAPC_GET_DEV_INFO_CFM,
                                                    src_id, dest_id,
                                                    gapc_get_dev_info_cfm, APP_DEVICE_NAME_MAX_LEN);

            cfm->req = p_param->req;
            cfm->token = p_param->token;
            cfm->info.name.value_length = app_get_dev_name(cfm->info.name.value);
            cfm->complete_length = cfm->info.name.value_length;
            // Send message
            ke_msg_send(cfm);
        } break;

        case GAPC_DEV_APPEARANCE:
        {
            // Allocate message
            struct gapc_get_dev_info_cfm *cfm = KE_MSG_ALLOC(GAPC_GET_DEV_INFO_CFM,
                                                             src_id, dest_id,
                                                             gapc_get_dev_info_cfm);
            cfm->req = p_param->req;
            cfm->token = p_param->token;
            // Set the device appearance
            #if (BLE_APP_HT)
            // Generic Thermometer - TODO: Use a flag
            cfm->info.appearance = 728;
            #elif (BLE_APP_HID)
            // HID Mouse
            cfm->info.appearance = 962;
            #elif (BLE_APP_MESH)
            cfm->info.appearance = 800;
            #else
            // No appearance
            cfm->info.appearance = 0;
            #endif

            // Send message
            ke_msg_send(cfm);
        } break;

        case GAPC_DEV_SLV_PREF_PARAMS:
        {
            // Allocate message
            struct gapc_get_dev_info_cfm *cfm = KE_MSG_ALLOC(GAPC_GET_DEV_INFO_CFM,
                    src_id, dest_id,
                                                            gapc_get_dev_info_cfm);
            cfm->req = p_param->req;
            cfm->token = p_param->token;
            // Slave preferred Connection interval Min
            cfm->info.slv_pref_params.con_intv_min = 8;
            // Slave preferred Connection interval Max
            cfm->info.slv_pref_params.con_intv_max = 10;
            // Slave preferred Connection latency
            cfm->info.slv_pref_params.slave_latency  = 0;
            // Slave preferred Link supervision timeout
            cfm->info.slv_pref_params.conn_timeout    = 200;  // 2s (500*10ms)

            // Send message
            ke_msg_send(cfm);
        } break;

        default: /* Do Nothing */ break;
    }
    return (KE_MSG_CONSUMED);
}

#if (BLE_APP_PRF)
/**
 ****************************************************************************************
 * @brief Handles GAPC_SET_DEV_INFO_REQ_IND message.
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance (TASK_GAP).
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapc_set_dev_info_req_ind_handler(ke_msg_id_t const msgid,
        struct gapc_set_dev_info_req_ind const *p_param,
        ke_task_id_t const dest_id,
        ke_task_id_t const src_id)
{
    // Set Device configuration
    struct gapc_set_dev_info_cfm* cfm = KE_MSG_ALLOC(GAPC_SET_DEV_INFO_CFM, src_id, dest_id,
                                                     gapc_set_dev_info_cfm);
    // Reject to change parameters
    cfm->status = GAP_ERR_REJECTED;
    cfm->req = p_param->req;
    // Send message
    ke_msg_send(cfm);

    return (KE_MSG_CONSUMED);
}

#endif //(BLE_APP_PRF)

/**
 ****************************************************************************************
 * @brief Handles connection complete event from the GAP. Enable all required profiles
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance (TASK_GAP).
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapc_connection_req_ind_handler(ke_msg_id_t const msgid,
                                           struct gapc_connection_req_ind const *p_param,
                                           ke_task_id_t const dest_id,
                                           ke_task_id_t const src_id)
{
    app_env.conidx = KE_IDX_GET(src_id);
    // Check if the received connection index is valid
    if (app_env.conidx != GAP_INVALID_CONIDX)
    {
        // Allocate connection confirmation
        struct gapc_connection_cfm *cfm = KE_MSG_ALLOC(GAPC_CONNECTION_CFM,
                KE_BUILD_ID(TASK_GAPC, app_env.conidx), TASK_APP,
                gapc_connection_cfm);

        // Store received connection handle
        app_env.conhdl = p_param->conhdl;
        app_env.con_interval = p_param->con_interval;
        app_env.con_latency = p_param->con_latency;
        app_env.sup_to = p_param->sup_to;

        #if(BLE_APP_SEC)
        // TODO [FBE] restore valid data
        cfm->pairing_lvl      = GAP_AUTH_REQ_NO_MITM_BOND;//app_sec_get_bond_status() ? GAP_AUTH_REQ_NO_MITM_BOND : GAP_AUTH_REQ_NO_MITM_NO_BOND;
        #else // !(BLE_APP_SEC)
        cfm->pairing_lvl      = GAP_PAIRING_UNAUTH;
        #endif // (BLE_APP_SEC)

        // Send the message
        ke_msg_send(cfm);
        uart_printf("app %s,app_env.conhdl:%d\r\n",__func__,p_param->conhdl);
        uart_printf("con_interval:%d (1.25 ms)\r\n",p_param->con_interval);
        uart_printf("con_latency:%d ms\r\n",p_param->con_latency );
        uart_printf("sup_to:%d ms\r\n",p_param->sup_to * 10);
        uart_printf("role:%s\r\n",p_param->role ? "Slave":"Master");
        uart_printf("peer_addr_type:%x\r\n",p_param->peer_addr_type);
        uart_printf("peer_addr:%02x %02x %02x %02x %02x %02x\r\n",p_param->peer_addr.addr[0],p_param->peer_addr.addr[1],p_param->peer_addr.addr[2],\
        p_param->peer_addr.addr[3],p_param->peer_addr.addr[4],p_param->peer_addr.addr[5]);


      
        

        #if DISPLAY_SUPPORT
        #if (BLE_APP_PRF)
        // Update displayed information
        app_display_set_adv(false);
        app_display_set_con(true);

        #elif (BLE_APP_MESH)
        app_display_mesh_set_con(true);
        #endif //(BLE_APP_PRF)
        #endif //(DISPLAY_SUPPORT)

        /*--------------------------------------------------------------
         * ENABLE REQUIRED PROFILES
         *--------------------------------------------------------------*/

        #if (BLE_APP_BATT)
        // Enable Battery Service
        app_batt_enable_prf(app_env.conidx);
        #endif //(BLE_APP_BATT)

        #if (BLE_APP_HID)
        // Enable HID Service
        app_hid_enable_prf(app_env.conidx);
        #endif //(BLE_APP_HID)

        #if (BLE_APP_OADS)
        // Enable OAD Service
        app_oads_enable_prf(app_env.conidx);
        #endif //(BLE_APP_OADS)
        
        // We are now in connected State
        ke_state_set(dest_id, APP_CONNECTED);
       // ke_timer_set(APP_PERIOD_TIMER,TASK_APP,2000);
        uart_printf("state:%d\r\n", ke_state_get(TASK_APP));
				bBleWakeup = true;
				
        #if (BLE_APP_SEC && !(BLE_APP_AM0))
       // uart_printf("ask app_sec_send_security_req\r\n");
       // if (app_sec_get_bond_status())
        {
            // Ask for the peer device to either start encryption
          //  app_sec_send_security_req(app_env.conidx);
        }
        #endif // (BLE_APP_SEC && !defined(BLE_APP_AM0))
        
        #if(ENABLE_PHY_2M_LE_CODE) 
        ke_timer_set(APP_PERIOD_UPDATE_PHY_TIMER,TASK_APP,30);
        #endif
        ke_timer_set(APP_MTU_CHANGE_TIMER,TASK_APP,30);
        ke_timer_set(APP_PERIOD_UPDATE_PARAM_TIMER,TASK_APP,3000);

    }
    else
    {
        #if (BLE_APP_PRF)
        // No connection has been established, restart advertising
        app_start_advertising();

        #endif //(BLE_APP_PRF)
    }
    return (KE_MSG_CONSUMED);
}
/**
 ****************************************************************************************
 * @brief Handles connection complete event from the GAP. Enable all required profiles
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance (TASK_GAP).
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapc_param_update_req_ind_handler(ke_msg_id_t const msgid,
                                           struct gapc_param_update_req_ind const *p_param,
                                           ke_task_id_t const dest_id,
                                           ke_task_id_t const src_id)
{
    app_env.conidx = KE_IDX_GET(src_id);
    uart_printf("%s,%d,%d\n",__FUNCTION__,__LINE__,app_env.conidx);
    // Check if the received Connection Handle was valid
    if (app_env.conidx != GAP_INVALID_CONIDX)
    {
        // Send connection confirmation
        struct gapc_param_update_cfm *cfm = KE_MSG_ALLOC(GAPC_PARAM_UPDATE_CFM,
                KE_BUILD_ID(TASK_GAPC, app_env.conidx), TASK_APP,
                gapc_param_update_cfm);

        cfm->accept = true;
        cfm->ce_len_min = 2;
        cfm->ce_len_max = 4;

        // Send message
        ke_msg_send(cfm);
    }
    else
    {
#if (BLE_APP_PRF)
        // No connection has been established, restart advertising
       app_start_advertising();
#endif // (BLE_APP_PRF)
    }
    return (KE_MSG_CONSUMED);
}

#if (BLE_APP_PRF)
/**
 ****************************************************************************************
 * @brief Handles GAP controller command complete events.
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance (TASK_GAP).
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapc_cmp_evt_handler(ke_msg_id_t const msgid,
                                struct gapc_cmp_evt const *p_param,
                                ke_task_id_t const dest_id,
                                ke_task_id_t const src_id)
{

    uart_printf("%s,operation:%x,status:0x%x\r\n",__func__,p_param->operation,p_param->status);
    switch(p_param->operation)
    {
        case (GAPC_UPDATE_PARAMS):
        {
            if (p_param->status != GAP_ERR_NO_ERROR)
            {
//              app_disconnect();
            }
        }
        break;

        default:
        {
        }
        break;
    }

    return (KE_MSG_CONSUMED);
}
#endif //(BLE_APP_PRF)

/**
 ****************************************************************************************
 * @brief Handles disconnection complete event from the GAP.
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance (TASK_GAP).
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */

static int gapc_disconnect_ind_handler(ke_msg_id_t const msgid,
                                      struct gapc_disconnect_ind const *p_param,
                                      ke_task_id_t const dest_id,
                                      ke_task_id_t const src_id)
{

    uart_printf("app %s,reason:0x%x\r\n",__func__,p_param->reason);
		bMasterReady = false;
		bBleWakeup = true;
	//			showBatLevelTime = 100;
    // Go to the ready state
    ke_state_set(TASK_APP, APP_READY);
    #if (DISPLAY_SUPPORT)
    #if (BLE_APP_MESH)
    // Update Connection State screen
    app_display_mesh_set_con(false);
    #elif (BLE_APP_PRF)
    app_display_set_con(false);
    #endif //(BLE_APP_MESH)
    #endif //(DISPLAY_SUPPORT)

    #if (BLE_APP_PRF)
    #if (BLE_APP_HT)
    // Stop interval timer
    app_stop_timer();
    #endif //(BLE_APP_HT)

    #if (BLE_ISO_MODE_0_PROFILE)
    app_env.adv_state = APP_ADV_STATE_CREATING;
    #endif //(BLE_ISO_MODE_0_PROFILE)


    #if 1// (!BLE_APP_HID)
    // Restart Advertising
		/*if(bWorking) */app_start_advertising();
    #endif //(!BLE_APP_HID)
    #endif //(BLE_APP_PRF)
    return (KE_MSG_CONSUMED);
}

 
/**
 ****************************************************************************************
 * @brief Handles reception of all messages sent from the lower layers to the application
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int app_msg_handler(ke_msg_id_t const msgid,
                            void *p_param,
                            ke_task_id_t const dest_id,
                            ke_task_id_t const src_id)
{
    // Retrieve identifier of the task from received message
    ke_task_id_t src_task_id = MSG_T(msgid);
    // Message policy
    uint8_t msg_pol = KE_MSG_CONSUMED;
    //uart_printf("app_msg_handler src_task_id:%d,%d\r\n",src_task_id,msgid);
    //    uart_printf("app_msg_handler src_task_id:%d,%d\r\n",src_task_id,msgid);
    //uart_printf("app_msg_handler src_task_id:%d,%d\r\n",src_task_id,msgid);

    switch (src_task_id)
    {
        case (TASK_ID_GAPC):
        {
            #if (BLE_APP_SEC)
         //   if ((msgid >= GAPC_BOND_CMD) &&
         //       (msgid <= GAPC_SECURITY_IND))
            {
                // Call the Security Module
                msg_pol = app_get_handler(&app_sec_handlers, msgid, p_param, src_id);
            }
            #endif //(BLE_APP_SEC)
            // else drop the message
        } break;

        case (TASK_ID_GATTC):
        {
            // Service Changed - Drop
        } break;

        #if (BLE_APP_HT)
        case (TASK_ID_HTPT):
        {
            // Call the Health Thermometer Module
            msg_pol = app_get_handler(&app_ht_handlers, msgid, p_param, src_id);
        } break;
        #endif //(BLE_APP_HT)

        #if (BLE_APP_DIS)
        case (TASK_ID_DISS):
        {
            // Call the Device Information Module
            msg_pol = app_get_handler(&app_dis_handlers, msgid, p_param, src_id);
        } break;
        #endif //(BLE_APP_DIS)

        #if (BLE_APP_HID)
        case (TASK_ID_HOGPD):
        {
            // Call the HID Module
            msg_pol = app_get_handler(&app_hid_handlers, msgid, p_param, src_id);
        } break;
        #endif //(BLE_APP_HID)

        #if (BLE_APP_MESH)
        case (TASK_ID_MESH) :
        {
            // Call the mesh module
            msg_pol = app_get_handler(&app_mesh_handlers, msgid, p_param, src_id);
        }break;
        #endif //(BLE_APP_MESH)

        #if (BLE_APP_BATT)
        case (TASK_ID_BASS):
        {
            // Call the Battery Module
            msg_pol = app_get_handler(&app_batt_handlers, msgid, p_param, src_id);
        } break;
        #endif //(BLE_APP_BATT)


        #if (BLE_APP_FEE0S)
        case (TASK_ID_FEE0S):
        {
            // Call the Fee0s Module
            msg_pol = app_get_handler(&app_fee0_handlers, msgid, p_param, src_id);
        } break;
        #endif //(BLE_APP_FEE0S)

        
          #if (BLE_APP_OADS)
        case (TASK_ID_OADS):
        {
            // Call the Fee0s Module
            msg_pol = app_get_handler(&app_oads_handler, msgid, p_param, src_id);
        } break;
        #endif //(BLE_APP_BATT)

        #if (BLE_APP_AM0)
        case (TASK_ID_AM0):
        {
            // Call the Audio Mode 0 Module
            msg_pol = app_get_handler(&app_am0_handlers, msgid, p_param, src_id);
        } break;

        case (TASK_ID_AM0_HAS):
        {
            // Call the Audio Mode 0 Module
            msg_pol = app_get_handler(&app_am0_has_handlers, msgid, p_param, src_id);
        } break;
        #endif //(BLE_APP_AM0)

        default:
        {
            #if (BLE_APP_HT)
            if (msgid == APP_HT_MEAS_INTV_TIMER)
            {
                msg_pol = app_get_handler(&app_ht_handlers, msgid, p_param, src_id);
            }
            #endif //(BLE_APP_HT)

            #if (BLE_APP_HID)
            if (msgid == APP_HID_MOUSE_TIMEOUT_TIMER)
            {
                msg_pol = app_get_handler(&app_hid_handlers, msgid, p_param, src_id);
            }
            #endif //(BLE_APP_HID)

            #if (BLE_APP_MESH)
            #if (DISPLAY_SUPPORT)
            if (msgid == APP_MESH_ATTENTION_TIMER
                    || msgid == APP_MESH_SAVING_TIMER
                    || msgid == APP_MESH_REMOVING_TIMER)
            {
                // Call the mesh display module
                msg_pol = app_get_handler(&app_display_mesh_handlers, msgid, p_param, src_id);
            }

            // Timer used to wait transition time to toggle the on off state.
            if (msgid == APP_MESH_TRANSITION_TIMER)
            {
                // Call the mesh display module
                msg_pol = app_get_handler(&app_display_mesh_handlers, msgid, p_param, src_id);
            }
            
            #endif //(DISPLAY_SUPPORT)
            #endif //(BLE_APP_MESH)

        } break;
    }

    return (msg_pol);
}

#if (BLE_APP_PRF)
/**
 ****************************************************************************************
 * @brief Handles reception of random number generated message
 *
 * @param[in] msgid     Id of the message received.
 * @param[in] p_param   Pointer to the parameters of the message.
 * @param[in] dest_id   ID of the receiving task instance
 * @param[in] src_id    ID of the sending task instance.
 *
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
static int gapm_gen_rand_nb_ind_handler(ke_msg_id_t const msgid, struct gapm_gen_rand_nb_ind *p_param,
                                        ke_task_id_t const dest_id, ke_task_id_t const src_id)
{
    if (app_env.rand_cnt==1)      // First part of IRK
    {
        memcpy(&app_env.loc_irk[0], &p_param->randnb.nb[0], 8);
    }
    else if (app_env.rand_cnt==2) // Second part of IRK
    {
        memcpy(&app_env.loc_irk[8], &p_param->randnb.nb[0], 8);
    }
    return (KE_MSG_CONSUMED);
}

#endif //(BLE_APP_PRF)

static int gapc_param_updated_ind_handler(ke_msg_id_t const msgid,
                             struct gapc_param_updated_ind *p_param,
                                         ke_task_id_t const dest_id,
                                          ke_task_id_t const src_id)
{
    uart_printf("gapc_param_updated_ind_handler \r\n");
    uart_printf("con_interval:%d \r\n",p_param->con_interval);
    uart_printf("con_latency :%d\r\n",p_param->con_latency);
    uart_printf("sup_to:%d \r\n",p_param->sup_to);

    return (KE_MSG_CONSUMED);
}

static int gapc_le_pkt_size_ind_handler(ke_msg_id_t const msgid,
                             struct gapc_le_pkt_size_ind *p_param,
                                       ke_task_id_t const dest_id,
                                        ke_task_id_t const src_id)
{
    uint8_t conidx = KE_IDX_GET(src_id);
   // uart_printf("gapc_le_pkt_size_ind_handler \r\n");
    uart_printf("max_rx_octets:%d \r\n",p_param->max_rx_octets);
    uart_printf("max_rx_time :%d\r\n",p_param->max_rx_time);
    uart_printf("max_tx_octets:%d \r\n",p_param->max_tx_octets);
    uart_printf("MTU SIZE :%d\r\n",gatt_mtu_get(conidx));
    return (KE_MSG_CONSUMED);
}


static int gapc_con_rssi_ind_handler(ke_msg_id_t const msgid,
                                      struct gapc_con_rssi_ind const *p_param,
                                      ke_task_id_t const dest_id,
                                      ke_task_id_t const src_id)
{
    static char time=0;
    int rssi_s=0;
    time++;
    rssi_s = p_param->rssi+rssi_s;
    if(time>=6)
    {
        rssi_s = rssi_s/6;
        uart_printf("app %s,reason:%d\r\n",__func__,rssi_s);
        rssi_s = 0;
        time=0;
    }
    return (KE_MSG_CONSUMED);
}


/*******************************************************************************
 * Function: app_period_timer_handler
 * Description: app period timer process
 * Input: msgid -Id of the message received.
 *          param -Pointer to the parameters of the message.
 *          dest_id -ID of the receiving task instance (TASK_GAP).
 *          ID of the sending task instance.
 * Return: If the message was consumed or not.
 * Others: void
*******************************************************************************/
static int app_period_timer_handler(ke_msg_id_t const msgid,
                                          void *param,
                                          ke_task_id_t const dest_id,
                                          ke_task_id_t const src_id)
{
	
		
    return KE_MSG_CONSUMED;

}
static int app_get_host_name_req_handler( ke_msg_id_t const msgid,
                                                      void *param,
                                                      ke_task_id_t const dest_id,
                                                      ke_task_id_t const src_id)
{
    struct gapc_get_info_cmd *p_cmd = KE_MSG_ALLOC(GAPC_GET_INFO_CMD,
                                           KE_BUILD_ID(TASK_GAPC, 0), TASK_GAPM,
                                           gapc_get_info_cmd);

    // request peer device name.
    p_cmd->operation = GAPC_GET_PEER_NAME;

    // send command
    ke_msg_send(p_cmd);
    return KE_MSG_CONSUMED;
}
static int gapc_get_host_name_ind_handler(ke_msg_id_t const msgid,
                                                struct gapc_peer_att_info_ind const *p_param,
                                                ke_task_id_t const dest_id,
                                                ke_task_id_t const src_id)
{ 
    uart_printf(" %s\r\n",__func__);
    uart_printf(" name:%s,len=%d \r\n",&p_param->info.name.value,p_param->info.name.value_length);

    return KE_MSG_CONSUMED;
}
static int app_mtu_change_req_handler(ke_msg_id_t const msgid,
                                              void *param,
                                              ke_task_id_t const dest_id,
                                              ke_task_id_t const src_id)
{
    struct gatt_cli_mtu_update_cmd *p_cmd = KE_MSG_ALLOC(GATT_CMD,TASK_GATT,
                                                                TASK_APP,
                                                                gatt_cli_mtu_update_cmd);
    p_cmd->cmd_code = GATT_CLI_MTU_UPDATE;
    p_cmd->dummy = 0;
    p_cmd->user_lid = 0;
    p_cmd->conidx = 0;

    ke_msg_send(p_cmd);
    uart_printf(" %s \n",__func__);

    return KE_MSG_CONSUMED;
}


static int app_update_param_timer_handler(ke_msg_id_t const msgid,
                                          void *param,
                                          ke_task_id_t const dest_id,
                                          ke_task_id_t const src_id)
{
    struct gapc_conn_param p_conn_param;
    
    uart_printf("app_update_param_timer_handler \r\n");
    
    p_conn_param.intv_max = BLE_UAPDATA_MAX_INTVALUE ;
    p_conn_param.intv_min = BLE_UAPDATA_MIN_INTVALUE;
    p_conn_param.latency  = BLE_UAPDATA_LATENCY;
    p_conn_param.time_out = BLE_UAPDATA_TIMEOUT;
    
    app_update_param(&p_conn_param);
    
	//send_data_proc(CMD_CHILD_RET);
    return KE_MSG_CONSUMED;

}
#if(ENABLE_PHY_2M_LE_CODE) 
void appm_update_phy_param(uint8_t tx_phy,uint8_t rx_phy,uint8_t phy_opt)      
{
    /// Supported LE PHY for data reception (@see enum gap_phy) 
    /// PHY options (@see enum gapc_phy_option)
    
    uart_printf("%s,%d,%d \r\n",__func__,KE_BUILD_ID(TASK_GAPC, app_env.conidx),TASK_APP);
    // Prepare the GAPC_PARAM_UPDATE_CMD message
    struct gapc_set_phy_cmd *cmd = KE_MSG_ALLOC(GAPC_SET_PHY_CMD,
                                                     KE_BUILD_ID(TASK_GAPC, app_env.conidx), TASK_APP,
                                                     gapc_set_phy_cmd);

    cmd->operation  = GAPC_SET_PHY;
    /// Supported LE PHY for data transmission (@see enum gap_phy)
    cmd->tx_phy = tx_phy;//GAP_PHY_LE_CODED;//GAP_PHY_LE_1MBPS;//GAP_PHY_LE_2MBPS;
    /// Supported LE PHY for data reception (@see enum gap_phy)
    cmd->rx_phy = rx_phy;//GAP_PHY_LE_CODED;//GAP_PHY_LE_1MBPS;//GAP_PHY_LE_2MBPS;
    /// PHY options (@see enum gapc_phy_option)
    cmd->phy_opt = phy_opt;//GAPC_PHY_OPT_LE_CODED_125K_RATE;//GAPC_PHY_OPT_LE_CODED_500K_RATE;//GAPC_PHY_OPT_LE_CODED_ALL_RATES;//conn_param->phy_opt;
   
    // Send the message
    ke_msg_send(cmd);
   
}
 
static int app_update_phy_timer_handler(ke_msg_id_t const msgid,
                                          void *param,
                                          ke_task_id_t const dest_id,
                                          ke_task_id_t const src_id)
{
    
    uart_printf("app_update_phy_timer_handler \r\n");
    
	appm_update_phy_param(GAP_PHY_LE_CODED,GAP_PHY_LE_CODED,GAPC_PHY_OPT_LE_CODED_125K_RATE);
  //  appm_update_phy_param(GAP_PHY_LE_2MBPS,GAP_PHY_LE_2MBPS,GAPC_PHY_OPT_LE_CODED_ALL_RATES);
    
    return KE_MSG_CONSUMED;

}

static int gapc_le_phy_ind_handler(ke_msg_id_t const msgid,
                                     struct gapc_le_phy_ind const *ind,
                                     ke_task_id_t const dest_id,
                                     ke_task_id_t const src_id)
{   
    uart_printf("%s\r\n",__func__); 

    uart_printf("tx_phy:%x,rx_phy:%x\r\n",ind->tx_phy,ind->rx_phy);    
    
    return (KE_MSG_CONSUMED);
}
#endif
/*
 * GLOBAL VARIABLES DEFINITION
 ****************************************************************************************
 */

/* Default State handlers definition. */
KE_MSG_HANDLER_TAB(app)
{
    // Note: all messages must be sorted in ID ascending order
    {GAPM_CMP_EVT,              (ke_msg_func_t)gapm_cmp_evt_handler},

    // GAPM messages
    #if (BLE_APP_PRF)
    {GAPM_GEN_RAND_NB_IND,      (ke_msg_func_t)gapm_gen_rand_nb_ind_handler},
    {GAPM_ACTIVITY_CREATED_IND, (ke_msg_func_t)gapm_activity_created_ind_handler},
    {GAPM_ACTIVITY_STOPPED_IND, (ke_msg_func_t)gapm_activity_stopped_ind_handler},
    #endif //(BLE_APP_PRF)

    {GAPM_PROFILE_ADDED_IND,    (ke_msg_func_t)gapm_profile_added_ind_handler},

    #if (BLE_APP_PRF)
    {GAPC_CMP_EVT,              (ke_msg_func_t)gapc_cmp_evt_handler},
    #endif //(BLE_APP_PRF)

    // GAPC messages
    {GAPC_CONNECTION_REQ_IND,   (ke_msg_func_t)gapc_connection_req_ind_handler},
    {GAPC_DISCONNECT_IND,       (ke_msg_func_t)gapc_disconnect_ind_handler},
    { GAPC_PEER_ATT_INFO_IND,   (ke_msg_func_t) gapc_get_host_name_ind_handler },
    {GAPC_CON_RSSI_IND,         (ke_msg_func_t)gapc_con_rssi_ind_handler},
    {GAPC_GET_DEV_INFO_REQ_IND,  (ke_msg_func_t)gapc_get_dev_info_req_ind_handler},
    

    #if (BLE_APP_PRF)
    {GAPC_SET_DEV_INFO_REQ_IND, (ke_msg_func_t)gapc_set_dev_info_req_ind_handler},
    #endif //(BLE_APP_PRF)
    

    {GAPC_PARAM_UPDATE_REQ_IND, (ke_msg_func_t)gapc_param_update_req_ind_handler},
    {GAPC_PARAM_UPDATED_IND,    (ke_msg_func_t)gapc_param_updated_ind_handler},
    {GAPC_LE_PKT_SIZE_IND,      (ke_msg_func_t)gapc_le_pkt_size_ind_handler},
    
    #if(ENABLE_PHY_2M_LE_CODE) 
    {GAPC_LE_PHY_IND,           (ke_msg_func_t)gapc_le_phy_ind_handler},
    #endif
    
    {APP_PERIOD_TIMER,            (ke_msg_func_t)app_period_timer_handler},
    {APP_PERIOD_UPDATE_PARAM_TIMER, (ke_msg_func_t)app_update_param_timer_handler},
    
    #if(ENABLE_PHY_2M_LE_CODE) 
    {APP_PERIOD_UPDATE_PHY_TIMER,(ke_msg_func_t)app_update_phy_timer_handler},
    #endif
    {APP_MTU_CHANGE_TIMER , (ke_msg_func_t)app_mtu_change_req_handler},
    {APP_GET_HOST_DEVICE_NAME , (ke_msg_func_t)app_get_host_name_req_handler},
    
    {KE_MSG_DEFAULT_HANDLER,    (ke_msg_func_t)app_msg_handler},
};

/* Defines the place holder for the states of all the task instances. */
ke_state_t app_state[APP_IDX_MAX];

// Application task descriptor
const struct ke_task_desc TASK_DESC_APP = {app_msg_handler_tab, app_state, APP_IDX_MAX, ARRAY_LEN(app_msg_handler_tab)};

#endif //(BLE_APP_PRESENT)

/// @} APPTASK
