/**
 ****************************************************************************************
 *
 * @file app_task.h
 *
 * @brief Header file - APPTASK.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

#ifndef APP_TASK_H_
#define APP_TASK_H_

/**
 ****************************************************************************************
 * @addtogroup APPTASK Task
 * @ingroup APP
 * @brief Routes ALL messages to/from APP block.
 *
 * The APPTASK is the block responsible for bridging the final application with the
 * RWBLE software host stack. It communicates with the different modules of the BLE host,
 * i.e. @ref SMP, @ref GAP and @ref GATT.
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"             // SW configuration

#if (BLE_APP_PRESENT)

#include <stdint.h>         // Standard Integer
#include "rwip_task.h"      // Task definitions
#include "ke_task.h"        // Kernel Task
#include "app_sbc.h"
/*
 * DEFINES
 ****************************************************************************************
 */

/// Number of APP Task Instances
#define APP_IDX_MAX                 (1)

/*
 * ENUMERATIONS
 ****************************************************************************************
 */

/// States of APP task
enum app_state
{
    /// Initialization state
    APP_INIT,
    /// Database create state
    APP_CREATE_DB,
    /// Ready State
    APP_READY,
    /// Connected state
    APP_CONNECTED,

    /// Number of defined states.
    APP_STATE_MAX
};


/// APP Task messages
/*@TRACE*/
enum app_msg_id
{
    APP_DUMMY_MSG = TASK_FIRST_MSG(TASK_ID_APP),

    #if (BLE_APP_PRF)
    #if (BLE_APP_HT)
    /// Timer used to refresh the temperature measurement value
    APP_HT_MEAS_INTV_TIMER,
    #endif //(BLE_APP_HT)

    #if (BLE_APP_HID)
    /// Timer used to disconnect the moue if no activity is detecter
    APP_HID_MOUSE_TIMEOUT_TIMER,
    #endif //(BLE_APP_HID)
    #endif //(BLE_APP_PRF)

    #if (BLE_APP_MESH)
    /// Timer used to wait the hide attention state screen
    APP_MESH_ATTENTION_TIMER,
    /// Timer used to wait the save configuration ready screen
    APP_MESH_SAVING_TIMER,
    /// Timer used to wait the remove mesh specific storage ready screen
    APP_MESH_REMOVING_TIMER,
    /// Timer used to wait transition time to toggle the on off state.
    APP_MESH_TRANSITION_TIMER,
    #endif //(BLE_APP_MESH)
    APP_PERIOD_TIMER,
    APP_PERIOD_UPDATE_PARAM_TIMER,
    APP_PERIOD_UPDATE_PHY_TIMER,
    APP_MTU_CHANGE_TIMER,
    APP_GET_HOST_DEVICE_NAME,

};
extern uint8_t send_buf[20];



/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/// @} APPTASK

#endif //(BLE_APP_PRESENT)

#endif // APP_TASK_H_
