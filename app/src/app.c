/**
 ****************************************************************************************
 *
 * @file app.c
 *
 * @brief Application entry point
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APP
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"             // SW configuration

#if (BLE_APP_PRESENT)

#include <string.h>

#include "app_task.h"                // Application task Definition
#include "app.h"                     // Application Definition
#include "gap.h"                     // GAP Definition

#include "gapm_msg.h"            // GAP Manager Task API
#include "gapc_msg.h"            // GAP Controller Task API

#include "co_math.h"                 // Common Maths Definition

#if (BLE_APP_SEC)
#include "app_sec.h"                 // Application security Definition
#endif // (BLE_APP_SEC)

#if (BLE_APP_HT)
#include "app_ht.h"                  // Health Thermometer Application Definitions
#endif //(BLE_APP_HT)

#if (BLE_APP_DIS)
#include "app_dis.h"                 // Device Information Service Application Definitions
#endif //(BLE_APP_DIS)

#if (BLE_APP_BATT)
#include "app_batt.h"                // Battery Application Definitions
#endif //(BLE_APP_DIS)

#if (BLE_APP_HID)
#include "app_hid.h"                 // HID Application Definitions
#endif //(BLE_APP_HID)

#if (DISPLAY_SUPPORT)
#include "app_display.h"             // Application Display Definition
#endif //(DISPLAY_SUPPORT)

#if (BLE_APP_AM0)
#include "app_am0.h"                 // Audio Mode 0 Application
#endif //(BLE_APP_AM0)

#if (BLE_APP_MESH)
#include "app_mesh.h"                 // HID Application Definitions
#endif //(BLE_APP_MESH)

#if (BLE_APP_FEE0S)
#include "app_fee0.h"                 // FEE0 Application Definitions
#endif //(BLE_APP_FEE0S)

#if (BLE_APP_OADS)
#include "app_oads.h"                 // oads Application Definitions
#endif //(BLE_APP_OADS)

#include "user_config.h"
/*
 * DEFINES
 ****************************************************************************************
 */

/// Default Device Name
#if (BLE_APP_HID)
// HID Mouse
#define DEVICE_NAME        "Hid Mouse"
#else
#define DEVICE_NAME        "RW DEVICE"
#endif

#define DEVICE_NAME_SIZE    sizeof(DEVICE_NAME)

/**
 * UUID List part of ADV Data
 * --------------------------------------------------------------------------------------
 * x03 - Length
 * x03 - Complete list of 16-bit UUIDs available
 * x09\x18 - Health Thermometer Service UUID
 *   or
 * x12\x18 - HID Service UUID
 * --------------------------------------------------------------------------------------
 */

#if (BLE_APP_HT)
#define APP_HT_ADV_DATA_UUID        "\x03\x03\x09\x18"
#define APP_HT_ADV_DATA_UUID_LEN    (4)
#endif //(BLE_APP_HT)

#if (BLE_APP_HID)
#define APP_HID_ADV_DATA_UUID       "\x03\x03\x12\x18"
#define APP_HID_ADV_DATA_UUID_LEN   (4)
#endif //(BLE_APP_HID)

/**
 * Appearance part of ADV Data
 * --------------------------------------------------------------------------------------
 * x03 - Length
 * x19 - Appearance
 * x03\x00 - Generic Thermometer
 *   or
 * xC2\x04 - HID Mouse
 * --------------------------------------------------------------------------------------
 */

#if (BLE_APP_HT)
#define APP_HT_ADV_DATA_APPEARANCE    "\x03\x19\xC1\x03"
#endif //(BLE_APP_HT)

#if (BLE_APP_HID)
#define APP_HID_ADV_DATA_APPEARANCE   "\x03\x19\xC1\x03"
#endif //(BLE_APP_HID)

#define APP_ADV_DATA_APPEARANCE_LEN  (4)


#if (BLE_APP_HID)
/// Default Advertising duration - 30s (in multiple of 10ms)
#define APP_DFLT_ADV_DURATION   (3000)
#endif //(BLE_APP_HID)

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

typedef void (*app_add_svc_func_t)(void);

/*
 * ENUMERATIONS
 ****************************************************************************************
 */

/// List of service to add in the database
enum app_svc_list
{
    #if (BLE_APP_HT)
    APP_SVC_HTS,
    #endif //(BLE_APP_HT)
    #if (BLE_APP_DIS)
    APP_SVC_DIS,
    #endif //(BLE_APP_DIS)
     #if (BLE_APP_FEE0S)
    APP_SVC_FEE0S,
    #endif //(BLE_APP_FEE0S)
    #if (BLE_APP_OADS)
    APP_SVC_OADS,
    #endif //(BLE_APP_OADS)

    #if (BLE_APP_BATT)
    APP_SVC_BATT,
    #endif //(BLE_APP_BATT)

    
    #if (BLE_APP_HID)
    APP_SVC_HIDS,
    #endif //(BLE_APP_HID)
    #if (BLE_APP_AM0)
    APP_SVC_AM0_HAS,
    #endif //(BLE_APP_AM0)
    #if (BLE_APP_MESH)
    APP_SVC_MESH,
    #endif //(BLE_APP_MESH)

    APP_SVC_LIST_STOP,
};

/*
 * LOCAL VARIABLES DEFINITIONS
 ****************************************************************************************
 */

/// Application Task Descriptor
extern const struct ke_task_desc TASK_DESC_APP;

/// List of functions used to create the database
static const app_add_svc_func_t app_add_svc_func_list[APP_SVC_LIST_STOP] =
{
    #if (BLE_APP_HT)
    (app_add_svc_func_t)app_ht_add_hts,
    #endif //(BLE_APP_HT)
    #if (BLE_APP_DIS)
    (app_add_svc_func_t)app_dis_add_dis,
    #endif //(BLE_APP_DIS)
    #if (BLE_APP_FEE0S)
    (app_add_svc_func_t)app_fee0_add_fee0s,
    #endif //(BLE_APP_FEE0S)

    #if (BLE_APP_OADS)
    (app_add_svc_func_t)app_oad_add_oads,
    #endif //(BLE_APP_OADS)

    #if (BLE_APP_BATT)
    (app_add_svc_func_t)app_batt_add_bas,
    #endif //(BLE_APP_BATT)

    
    #if (BLE_APP_HID)
    (app_add_svc_func_t)app_hid_add_hids,
    #endif //(BLE_APP_HID)
    #if (BLE_APP_AM0)
    (app_add_svc_func_t)app_am0_add_has,
    #endif //(BLE_APP_AM0)
    #if (BLE_APP_MESH)
    (app_add_svc_func_t)app_mesh_add_svc,
    #endif //(BLE_APP_MESH)
};
 
/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/// Application Environment Structure
struct app_env_tag app_env;

/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */

#if (BLE_APP_PRF)
#if (!BLE_APP_AM0)
static void app_build_adv_data(uint16_t max_length, uint16_t *p_length, uint8_t *p_buf)
{
    // Remaining Length
    uint8_t rem_len = max_length;
    //uint8_t special_data[]={ 0x08,0xFF,0xF0,0x05,0x42,0x45,0x4B,0x45,0x4E};
    #if (BLE_APP_HT)
    // Set list of UUIDs
    memcpy(p_buf, APP_HT_ADV_DATA_UUID, APP_HT_ADV_DATA_UUID_LEN);
    *p_length += APP_HT_ADV_DATA_UUID_LEN;
    p_buf += APP_HT_ADV_DATA_UUID_LEN;

    // Set appearance
    memcpy(p_buf, APP_HT_ADV_DATA_APPEARANCE, APP_ADV_DATA_APPEARANCE_LEN);
    *p_length += APP_ADV_DATA_APPEARANCE_LEN;
    p_buf += APP_ADV_DATA_APPEARANCE_LEN;
    #endif //(BLE_APP_HT)

    #if (BLE_APP_HID)
    // Set list of UUIDs
  //  memcpy(p_buf, APP_HID_ADV_DATA_UUID, APP_HID_ADV_DATA_UUID_LEN);
   // *p_length += APP_HID_ADV_DATA_UUID_LEN;
   // p_buf += APP_HID_ADV_DATA_UUID_LEN;

    // Set appearance
    memcpy(p_buf, APP_HID_ADV_DATA_APPEARANCE, APP_ADV_DATA_APPEARANCE_LEN);
    *p_length += APP_ADV_DATA_APPEARANCE_LEN;
    p_buf += APP_ADV_DATA_APPEARANCE_LEN;
    #endif //(BLE_APP_HID)

    // Sanity check
    ASSERT_ERR(rem_len >= max_length);

    // Get remaining space in the Advertising Data - 2 bytes are used for name length/flag
    rem_len -= *p_length;

    // Check if additional data can be added to the Advertising data - 2 bytes needed for type and length
    if (rem_len > 2)
    {
        uint8_t dev_name_length = co_min(app_env.dev_name_len, (rem_len - 2));

        // Device name length
        *p_buf = dev_name_length + 1;
        // Device name flag (check if device name is complete or not)
        *(p_buf + 1) = (dev_name_length == app_env.dev_name_len) ? '\x09' : '\x08';
        // Copy device name
        memcpy(p_buf + 2, app_env.dev_name, dev_name_length);

        // Update advertising data length
        *p_length += (dev_name_length + 2);
        
        p_buf += (dev_name_length + 2);
    }
    //memcpy(p_buf, special_data, 9);
    //*p_length += 9;
}
#endif //(!BLE_APP_AM0)


void app_start_advertising(void)
{
    uart_printf("%s\r\n",__func__);
    // Prepare the GAPM_ACTIVITY_START_CMD message
    struct gapm_activity_start_cmd *p_cmd = KE_MSG_ALLOC(GAPM_ACTIVITY_START_CMD,
                                                         TASK_GAPM, TASK_APP,
                                                      gapm_activity_start_cmd);

    p_cmd->operation = GAPM_START_ACTIVITY;
    p_cmd->actv_idx = app_env.adv_actv_idx;
    #if (BLE_APP_HID)
    p_cmd->u_param.adv_add_param.duration =0;// APP_DFLT_ADV_DURATION;
    #else //(BLE_APP_HID)
    p_cmd->u_param.adv_add_param.duration = 0;
    #endif //(BLE_APP_HID)
    p_cmd->u_param.adv_add_param.max_adv_evt = 0;

    // Send the message
    ke_msg_send(p_cmd);

    // Keep the current operation
    app_env.adv_state = APP_ADV_STATE_STARTING;
    // And the next expected operation code for the command completed event
    app_env.adv_op = GAPM_START_ACTIVITY;
}


void app_stop_advertising(void)
{
    // Prepare the GAPM_ACTIVITY_STOP_CMD message
    struct gapm_activity_stop_cmd *p_cmd = KE_MSG_ALLOC(GAPM_ACTIVITY_STOP_CMD,
                                                      TASK_GAPM, TASK_APP,
                                                      gapm_activity_stop_cmd);

    // Fill the allocated kernel message
    p_cmd->operation = GAPM_STOP_ACTIVITY;
    p_cmd->actv_idx = app_env.adv_actv_idx;

    // Send the message
    ke_msg_send(p_cmd);

    // Update advertising state
    app_env.adv_state = APP_ADV_STATE_STOPPING;
    // And the next expected operation code for the command completed event
    app_env.adv_op = GAPM_STOP_ACTIVITY;
}


void app_set_adv_data(void)
{
    // Prepare the GAPM_SET_ADV_DATA_CMD message
    struct gapm_set_adv_data_cmd *p_cmd = KE_MSG_ALLOC_DYN(GAPM_SET_ADV_DATA_CMD,
                                                           TASK_GAPM, TASK_APP,
                                                           gapm_set_adv_data_cmd,
                                                           ADV_DATA_LEN);

    // Fill the allocated kernel message
    p_cmd->operation = GAPM_SET_ADV_DATA;
    p_cmd->actv_idx = app_env.adv_actv_idx;

    #if (BLE_APP_AM0)
    app_am0_fill_adv_data(p_cmd);
    #else //(BLE_APP_AM0)
    p_cmd->length = 0;
    // GAP will use 3 bytes for the AD Type
    app_build_adv_data(ADV_DATA_LEN - 3, &p_cmd->length, &p_cmd->data[0]);
    #endif //(BLE_APP_AM0)

    // Send the message
    ke_msg_send(p_cmd);

    // Update advertising state
    app_env.adv_state = APP_ADV_STATE_SETTING_ADV_DATA;
    // And the next expected operation code for the command completed event
    app_env.adv_op = GAPM_SET_ADV_DATA;
}

void app_set_scan_rsp_data(void)
{
    // Prepare the GAPM_SET_ADV_DATA_CMD message
    struct gapm_set_adv_data_cmd *p_cmd = KE_MSG_ALLOC_DYN(GAPM_SET_ADV_DATA_CMD,
                                                           TASK_GAPM, TASK_APP,
                                                           gapm_set_adv_data_cmd,
                                                           ADV_DATA_LEN);

    // Fill the allocated kernel message
    p_cmd->operation = GAPM_SET_SCAN_RSP_DATA;
    p_cmd->actv_idx = app_env.adv_actv_idx;

    #if (BLE_APP_AM0)
    app_am0_fill_scan_rsp_data(p_cmd);
    #else //(BLE_APP_AM0)
    p_cmd->length = APP_SCNRSP_DATA_LEN;
    memcpy(&p_cmd->data[0], APP_SCNRSP_DATA, APP_SCNRSP_DATA_LEN);
    #endif //(BLE_APP_AM0)

    // Send the message
    ke_msg_send(p_cmd);

    // Update advertising state
    app_env.adv_state = APP_ADV_STATE_SETTING_SCAN_RSP_DATA;
    // And the next expected operation code for the command completed event
    app_env.adv_op = GAPM_SET_SCAN_RSP_DATA;
}

#endif //(BLE_APP_PRF)

static void app_send_gapm_reset_cmd(void)
{
    uart_printf("%s\r\n",__func__);
    // Reset the stack
    struct gapm_reset_cmd *p_cmd = KE_MSG_ALLOC(GAPM_RESET_CMD,
                                                TASK_GAPM, TASK_APP,
                                                gapm_reset_cmd);

    p_cmd->operation = GAPM_RESET;

    ke_msg_send(p_cmd);
    
}


/*
 * GLOBAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */



void app_init()
{
    uart_printf("app_init\r\n");
    
    // Reset the application manager environment
    ble_name_addr_env_init();
    // Create APP task
    ke_task_create(TASK_APP, &TASK_DESC_APP);

    // Initialize Task state
    ke_state_set(TASK_APP, APP_INIT);

    #if (BLE_APP_MESH)
    // Get the mesh demo type from NVDS
    #if (NVDS_SUPPORT)
    app_env.demo_type_len = APP_MESH_DEMO_TYPE_LEN;
    if (nvds_get(NVDS_TAG_MESH_DEMO_TYPE, &(app_env.demo_type_len), &(app_env.demo_type)) != NVDS_OK)
    #endif //(NVDS_SUPPORT)
    {
        app_env.demo_type = APP_MESH_DEMO_GENS_ONOFF;
    }
    #endif //(BLE_APP_MESH)

    #if 0
    #if (NVDS_SUPPORT)
    // Get the Device Name to add in the Advertising Data (Default one or NVDS one)
    app_env.dev_name_len = APP_DEVICE_NAME_MAX_LEN;
    if (nvds_get(NVDS_TAG_DEVICE_NAME, &(app_env.dev_name_len), app_env.dev_name) != NVDS_OK)
    #endif //(NVDS_SUPPORT)
    {
        // Get default Device Name (No name if not enough space)
        memcpy(app_env.dev_name, APP_DFLT_DEVICE_NAME, APP_DFLT_DEVICE_NAME_LEN);
        app_env.dev_name_len = APP_DFLT_DEVICE_NAME_LEN;

        // TODO update this value per profiles
    }
    #endif
    /*------------------------------------------------------
     * INITIALIZE ALL MODULES
     *------------------------------------------------------*/

    // load device information:
    #if (DISPLAY_SUPPORT)
    // Pass the device name and mesh demo type to app display initialization function
    app_display_init(app_env.dev_name, app_env.demo_type);
    #endif //(DISPLAY_SUPPORT)

    #if (BLE_APP_SEC)
    // Security Module
    app_sec_init();
    #endif // (BLE_APP_SEC)

    #if (BLE_APP_HT)
    // Health Thermometer Module
    app_ht_init();
    #endif //(BLE_APP_HT)

    #if (BLE_APP_DIS)
    // Device Information Module
   // app_dis_init();
    #endif //(BLE_APP_DIS)

    #if (BLE_APP_HID)
    // HID Module
    app_hid_init();
    #endif //(BLE_APP_HID)

    #if (BLE_APP_BATT)
    // Battery Module
    app_batt_init();
    #endif //(BLE_APP_BATT)

    #if (BLE_APP_AM0)
    // Audio Mode 0 Module
    app_am0_init();
    #endif //(BLE_APP_AM0)

    #if (BLE_APP_MESH)
    // Mesh Module
    app_mesh_init(app_env.demo_type);
    #endif //(BLE_APP_MESH)

    // Reset the stack
    app_send_gapm_reset_cmd();
}

bool app_add_svc(void)
{
    uart_printf("%s\r\n",__func__);
    // Indicate if more services need to be added in the database
    bool more_svc = false;

    // Check if another should be added in the database
    if (app_env.next_svc != APP_SVC_LIST_STOP)
    {
        ASSERT_INFO(app_add_svc_func_list[app_env.next_svc] != NULL, app_env.next_svc, 1);

        // Call the function used to add the required service
        app_add_svc_func_list[app_env.next_svc]();

        // Select following service to add
        app_env.next_svc++;
        more_svc = true;
    }

    return more_svc;
}
//Defines an array to store audio data that has been encoded
uint8_t encode_voice_data[TOTAL_BLOCK_NUM][20];
//reaord index
uint8_t pbuff_write = 0;
//read index
uint8_t pbuff_read = 0;


uint8_t app_get_dev_name(uint8_t* name)
{
    // copy name to provided pointer
    memcpy(name, app_env.dev_name, app_env.dev_name_len);
    // return name length
    return app_env.dev_name_len;
}

#if (BLE_APP_PRF)
void app_disconnect(void)
{
    struct gapc_disconnect_cmd *p_cmd = KE_MSG_ALLOC(GAPC_DISCONNECT_CMD,
                                                   KE_BUILD_ID(TASK_GAPC, app_env.conidx), TASK_APP,
                                                   gapc_disconnect_cmd);

    p_cmd->operation = GAPC_DISCONNECT;
    p_cmd->reason    = CO_ERROR_REMOTE_USER_TERM_CON;

    // Send the message
    ke_msg_send(p_cmd);
}

void app_create_advertising(void)
{
    uart_printf("%s\r\n",__func__);
    if (app_env.adv_state == APP_ADV_STATE_IDLE)
    {
        // Prepare the GAPM_ACTIVITY_CREATE_CMD message
        struct gapm_activity_create_adv_cmd *p_cmd = KE_MSG_ALLOC(GAPM_ACTIVITY_CREATE_CMD,
                                                                  TASK_GAPM, TASK_APP,
                                                                  gapm_activity_create_adv_cmd);

        // Set operation code
        p_cmd->operation = GAPM_CREATE_ADV_ACTIVITY;

        #if (BLE_APP_AM0)
        // Let AM0 application module set advertising parameters
        app_am0_fill_create_adv_actv(p_cmd);
        #else //(BLE_APP_AM0)
        // Fill the allocated kernel message
        p_cmd->own_addr_type = GAPM_STATIC_ADDR;
        p_cmd->adv_param.type = GAPM_ADV_TYPE_LEGACY;
        p_cmd->adv_param.prop = GAPM_ADV_PROP_UNDIR_CONN_MASK;
        p_cmd->adv_param.filter_pol = ADV_ALLOW_SCAN_ANY_CON_ANY;
        p_cmd->adv_param.prim_cfg.chnl_map = APP_ADV_CHMAP;
        p_cmd->adv_param.prim_cfg.phy = GAP_PHY_LE_1MBPS;

        #if (BLE_APP_HID)
        p_cmd->adv_param.disc_mode = GAPM_ADV_MODE_LIM_DISC;

        /*
         * If the peripheral is already bonded with a central device, use the direct advertising
         * procedure (BD Address of the peer device is stored in NVDS.
         */
        if (app_sec_get_bond_status())
        {
//            // BD Address of the peer device
//            struct gap_bdaddr peer_bd_addr;
//            // Length
//            uint8_t length = NVDS_LEN_PEER_BD_ADDRESS;
//
//            // Get the BD Address of the peer device in NVDS
//            if (nvds_get(NVDS_TAG_PEER_BD_ADDRESS, &length, (uint8_t *)&peer_bd_addr) != NVDS_OK)
//            {
//                // The address of the bonded peer device should be present in the database
//                ASSERT_ERR(0);
//            }
//
//            // Set the DIRECT ADVERTISING mode
//            cmd->op.code = GAPM_ADV_DIRECT;
//            // Copy the BD address of the peer device and the type of address
//            memcpy(&cmd->info.direct, &peer_bd_addr, NVDS_LEN_PEER_BD_ADDRESS);

            p_cmd->adv_param.prim_cfg.adv_intv_min = APP_ADV_FAST_INT;
            p_cmd->adv_param.prim_cfg.adv_intv_max = APP_ADV_FAST_INT;
        }
        else
        {
            p_cmd->adv_param.prim_cfg.adv_intv_min = APP_ADV_INT_MIN;
            p_cmd->adv_param.prim_cfg.adv_intv_max = APP_ADV_INT_MAX;
        }
        #else //(BLE_APP_HID)
        p_cmd->adv_param.disc_mode = GAPM_ADV_MODE_GEN_DISC;
        p_cmd->adv_param.prim_cfg.adv_intv_min = APP_ADV_INT_MIN;
        p_cmd->adv_param.prim_cfg.adv_intv_max = APP_ADV_INT_MAX;
        #endif //(BLE_APP_HID)
        #endif //(BLE_APP_AM0)

        // Send the message
        ke_msg_send(p_cmd);
    uart_printf("%s\r\n",__func__);

        // Keep the current operation
        app_env.adv_state = APP_ADV_STATE_CREATING;
        // And the next expected operation code for the command completed event
        app_env.adv_op = GAPM_CREATE_ADV_ACTIVITY;
    }
}

void app_delete_advertising(void)
{
    // Prepare the GAPM_ACTIVITY_CREATE_CMD message
    struct gapm_activity_delete_cmd *p_cmd = KE_MSG_ALLOC(GAPM_ACTIVITY_DELETE_CMD,
                                                              TASK_GAPM, TASK_APP,
                                                              gapm_activity_delete_cmd);

    // Set operation code
    p_cmd->operation = GAPM_DELETE_ALL_ACTIVITIES;

    // Send the message
    ke_msg_send(p_cmd);

    // Keep the current operation
    // And the next expected operation code for the command completed event
    app_env.adv_op = GAPM_DELETE_ALL_ACTIVITIES;
}

void app_update_param(struct gapc_conn_param *p_conn_param)
{
    // Prepare the GAPC_PARAM_UPDATE_CMD message
    struct gapc_param_update_cmd *p_cmd = KE_MSG_ALLOC(GAPC_PARAM_UPDATE_CMD,
                                                     KE_BUILD_ID(TASK_GAPC, app_env.conidx), TASK_APP,
                                                     gapc_param_update_cmd);

    p_cmd->operation  = GAPC_UPDATE_PARAMS;
    p_cmd->intv_min   = p_conn_param->intv_min;
    p_cmd->intv_max   = p_conn_param->intv_max;
    p_cmd->latency    = p_conn_param->latency;
    p_cmd->time_out   = p_conn_param->time_out;

    // not used by a slave device
    p_cmd->ce_len_min = 0xFFFF;
    p_cmd->ce_len_max = 0xFFFF;

    // Send the message
    ke_msg_send(p_cmd);
}

#endif //(BLE_APP_PRF)
#endif //(BLE_APP_PRESENT)

/// @} APP
