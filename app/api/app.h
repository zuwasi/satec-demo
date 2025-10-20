/**
 ****************************************************************************************
 *
 * @file app.h
 *
 * @brief Application entry point
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 ****************************************************************************************
 */

#ifndef APP_H_
#define APP_H_

/**
 ****************************************************************************************
 * @addtogroup APP
 * @ingroup RICOW
 *
 * @brief Application entry point.
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"     // SW configuration

#if (BLE_APP_PRESENT)

#include <stdint.h>          // Standard Integer Definition
#include "arch.h"            // Platform Definitions
#include <co_bt.h>           // Common BT Definitions


//#include "gattc_task.h"       // GATTC Definitions
#include "gapm_msg.h"            // GAP Manager Task API
#include "gapc_msg.h"            // GAP Controller Task API

#if (NVDS_SUPPORT)
#include "nvds.h"
#endif // (NVDS_SUPPORT)

/*
 * DEFINES
 ****************************************************************************************
 */

/// Maximal length of the Device Name value
#define APP_DEVICE_NAME_MAX_LEN      (18)
#define APP_MESH_DEMO_TYPE_LEN        (1)
#define  TOTAL_BLOCK_NUM               (160)

/*
 * MACROS
 ****************************************************************************************
 */

#define APP_HANDLERS(subtask)    {&subtask##_msg_handler_list[0], ARRAY_LEN(subtask##_msg_handler_list)}

/*
 * ENUMERATIONS
 ****************************************************************************************
 */

#if (NVDS_SUPPORT)
/// List of Application NVDS TAG identifiers
enum app_nvds_tag
{
    /// Device Name
    NVDS_TAG_DEVICE_NAME                = 0x02,
    NVDS_LEN_DEVICE_NAME                = 62,

    /// BD Address
    NVDS_TAG_BD_ADDRESS                 = 0x01,
    NVDS_LEN_BD_ADDRESS                 = 6,

    /// Local device Identity resolving key
    NVDS_TAG_LOC_IRK                    = 0xA0,
    NVDS_LEN_LOC_IRK                    = KEY_LEN,

    #if (BLE_APP_MESH)
    /// Mesh task
    NVDS_TAG_APP_MESH                   = 0xAA,
    NVDS_LEN_APP_MESH                   = 64,

    /// Mesh demo type
    NVDS_TAG_MESH_DEMO_TYPE             = 0xA8,
    NVDS_LEN_MESH_DEMO_TYPE             = 1,

    #endif //(BLE_APP_MESH)

    #if (BLE_APP_PRF)
    /// BLE Application Advertising data
    NVDS_TAG_APP_BLE_ADV_DATA           = 0x0B,
    NVDS_LEN_APP_BLE_ADV_DATA           = 32,

    /// BLE Application Scan response data
    NVDS_TAG_APP_BLE_SCAN_RESP_DATA     = 0x0C,
    NVDS_LEN_APP_BLE_SCAN_RESP_DATA     = 32,

    /// Mouse Sample Rate
    NVDS_TAG_MOUSE_SAMPLE_RATE          = 0x38,
    NVDS_LEN_MOUSE_SAMPLE_RATE          = 1,

    /// Peripheral Bonded
    NVDS_TAG_PERIPH_BONDED              = 0x39,
    NVDS_LEN_PERIPH_BONDED              = 1,

    /// Mouse NTF Cfg
    NVDS_TAG_MOUSE_NTF_CFG              = 0x3A,
    NVDS_LEN_MOUSE_NTF_CFG              = 2,

    /// Mouse Timeout value
    NVDS_TAG_MOUSE_TIMEOUT              = 0x3B,
    NVDS_LEN_MOUSE_TIMEOUT              = 2,

    /// Peer Device BD Address
    NVDS_TAG_PEER_BD_ADDRESS            = 0x3C,
    NVDS_LEN_PEER_BD_ADDRESS            = 7,

    /// Mouse Energy Safe
    NVDS_TAG_MOUSE_ENERGY_SAFE          = 0x3D,
    NVDS_LEN_MOUSE_SAFE_ENERGY          = 2,

    /// EDIV (2bytes), RAND NB (8bytes),  LTK (16 bytes), Key Size (1 byte)
    NVDS_TAG_LTK                        = 0x3E,
    NVDS_LEN_LTK                        = 28,

    /// PAIRING
    NVDS_TAG_PAIRING                    = 0x3F,
    NVDS_LEN_PAIRING                    = 54,

    /// Audio mode 0 task
    NVDS_TAG_AM0_FIRST                  = 0x90,
    NVDS_TAG_AM0_LAST                   = 0x9F,

    /// Peer device Resolving identity key (+identity address)
    NVDS_TAG_PEER_IRK                   = 0xA1,
    NVDS_LEN_PEER_IRK                   = sizeof(struct gapc_irk),
    
    //TODO
#endif //(BLE_APP_PRF)
};
#endif // (NVDS_SUPPORT)


/// Advertising state machine
enum app_adv_state
{
    /// Advertising activity does not exists
    APP_ADV_STATE_IDLE = 0,
    #if BLE_APP_PRF
    /// Creating advertising activity
    APP_ADV_STATE_CREATING,
    /// Setting advertising data
    APP_ADV_STATE_SETTING_ADV_DATA,
    /// Setting scan response data
    APP_ADV_STATE_SETTING_SCAN_RSP_DATA,

    /// Advertising activity created
    APP_ADV_STATE_CREATED,
    /// Starting advertising activity
    APP_ADV_STATE_STARTING,
    /// Advertising activity started
    APP_ADV_STATE_STARTED,
    /// Stopping advertising activity
    APP_ADV_STATE_STOPPING,
    #endif //(BLE_APP_PRF)
};


/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

/// Structure containing information about the handlers for an application subtask
struct app_subtask_handlers
{
    /// Pointer to the message handler table
    const struct ke_msg_handler *p_msg_handler_tab;
    /// Number of messages handled
    uint16_t msg_cnt;
};

/// Application environment structure
struct app_env_tag
{
    /// Connection handle
    uint16_t conhdl;
    /// Connection Index
    uint8_t  conidx;

    /// Advertising activity index
    uint8_t adv_actv_idx;
    /// Current advertising state (@see enum app_adv_state)
    uint8_t adv_state;
    /// Next expected operation completed event
    uint8_t adv_op;

    /// Last initialized profile
    uint8_t next_svc;

    /// Bonding status
    bool bonded;

    /// Device Name length
    uint8_t dev_name_len;
    /// Device Name
    uint8_t dev_name[APP_DEVICE_NAME_MAX_LEN];

    /// Local device IRK
    uint8_t loc_irk[KEY_LEN];

    /// Secure Connections on current link
    bool sec_con_enabled;

    /// Counter used to generate IRK
    uint8_t rand_cnt;

    /// Demonstration type length
    uint8_t demo_type_len;
    /// Demonstration type
    uint8_t demo_type;

    uint16_t con_interval;
    ///Connection latency value
    uint16_t con_latency;
    ///Supervision timeout
    uint16_t sup_to;
};

/*
 * GLOBAL VARIABLE DECLARATION
 ****************************************************************************************
 */

/// Application environment
extern struct app_env_tag app_env;

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initialize the BLE demo application.
 ****************************************************************************************
 */
void app_init(void);

/**
 ****************************************************************************************
 * @brief Add a required service in the database
 ****************************************************************************************
 */
bool app_add_svc(void);

/**
 ****************************************************************************************
 * @brief Retrieve device name
 *
 * @param[out] Pointer at which device name will be returned
 *
 * @return Name length
 ****************************************************************************************
 */
uint8_t app_get_dev_name(uint8_t* p_name);

#if (BLE_APP_PRF)
/**
 ****************************************************************************************
 * @brief
 ****************************************************************************************
 */
void app_adv_fsm_next(void);

/**
 ****************************************************************************************
 * @brief create a advertising
 ****************************************************************************************
 */
void app_create_advertising(void);

/**
 ****************************************************************************************
 * @brief set  advertising data
 ****************************************************************************************
 */
void app_set_adv_data(void);

/**
 ****************************************************************************************
 * @brief set scan rsp data
 ****************************************************************************************
 */
void app_set_scan_rsp_data(void);

/**
 ****************************************************************************************
 * @brief start_advertising
 ****************************************************************************************
 */
void app_start_advertising(void);


/**
 ****************************************************************************************
 * @brief stop_advertising
 ****************************************************************************************
 */
void app_stop_advertising(void);



/**
 ****************************************************************************************
 * @brief Send to request to update the connection parameters
 ****************************************************************************************
 */
void app_update_param(struct gapc_conn_param *conn_param);

/**
 ****************************************************************************************
 * @brief Send a disconnection request
 ****************************************************************************************
 */
void app_disconnect(void);


/**
 ****************************************************************************************
 * @brief delete advertising
 *
 * @param[in] none
 ****************************************************************************************
 */

void app_delete_advertising(void);
/**
 ****************************************************************************************
 * @brief Return if the device is currently bonded
 ****************************************************************************************
 */
bool app_sec_get_bond_status(void);
void ble_name_addr_env_init(void);
void app_vbat_lowpower_reset_mcu(void);
/// @} APP
///
#endif //(BLE_APP_PRF)
#endif //(BLE_APP_PRESENT)

#endif // APP_H_
