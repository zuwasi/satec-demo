/**
 ****************************************************************************************
 *
 * @file fee0s.h
 *
 * @brief Header file - FEE0 Service Server Role
 *
 * Copyright (C) beken 2019-2022
 *
 *
 ****************************************************************************************
 */
#ifndef _FEE0S_H_
#define _FEE0S_H_

/**
 ****************************************************************************************
 * @addtogroup  FFF0 'Profile' Server
 * @ingroup FFF0
 * @brief FFF0 'Profile' Server
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"
#include "rwprf_config.h"

#if (BLE_FEE0_SERVER)
#include "gatt.h"
#include "fee0s_msg.h"
#include "prf_types.h"
#include "prf.h"
#include "prf_utils.h"
/// FEE0S Service Attributes Indexes
enum
{        
        ATT_USER_SERVER_FEE0                         = GATT_UUID_16_LSB(0xFEE0),    // service 
        ATT_USER_SERVER_CHAR_FEE1                   = GATT_UUID_16_LSB(0xFEE1), // read        
        ATT_USER_SERVER_CHAR_FEE2                    = GATT_UUID_16_LSB(0xFEE2),// write cmd
        ATT_USER_SERVER_CHAR_FEE3                    = GATT_UUID_16_LSB(0xFEE3),// write req
        ATT_USER_SERVER_CHAR_FEE4                    = GATT_UUID_16_LSB(0xFEE4), // ntf
        ATT_USER_SERVER_CHAR_FEE5                    = GATT_UUID_16_LSB(0xFEE5), // ind
        
};
/*
 * DEFINES
 ****************************************************************************************
 */

/// FEE0S Service Attributes Indexes
enum
{
    FEE0S_IDX_SVC,

    FEE0S_IDX_FEE1_VAL_CHAR,
    FEE0S_IDX_FEE1_VAL_VAL,
    FEE0S_IDX_FEE1_USER_DESC,
    
    FEE0S_IDX_FEE2_VAL_CHAR,
    FEE0S_IDX_FEE2_VAL_VAL,

    FEE0S_IDX_FEE3_VAL_CHAR,
    FEE0S_IDX_FEE3_VAL_VAL,
    
    FEE0S_IDX_FEE4_VAL_CHAR,
    FEE0S_IDX_FEE4_VAL_VAL,
    FEE0S_IDX_FEE4_VAL_NTF_CFG,

    FEE0S_IDX_FEE5_VAL_CHAR,
    FEE0S_IDX_FEE5_VAL_VAL,
    FEE0S_IDX_FEE5_VAL_IND_CFG,

    FEE0S_IDX_NB,
};


#define FEE0S_CFG_FLAG_MANDATORY_MASK       (0x3FFF)
/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */


/// FEE0 'Profile' Server environment variable
typedef struct fee0s_env
{
   /// profile environment
    prf_hdr_t           prf_env;
    /// Operation Event TX wait queue
    co_list_t           wait_queue;
   
    /// On-going operation
    uint8_t operation_att; 
    /// List of values set by application
    struct co_list values;
    /// FFF0 Services Start Handle
    uint16_t start_hdl;
     uint8_t fee1_val_len; 
     uint8_t fee2_val_len;
    uint8_t fee3_val_len;
    uint8_t fee4_val_len;
    uint8_t fee5_val_len;
    uint8_t fee1_val[FEE0_CHAR_DATA_LEN];
    uint8_t fee2_val[FEE0_CHAR_DATA_LEN];
    uint8_t fee3_val[FEE0_CHAR_DATA_LEN];
    uint8_t fee4_val[FEE0_CHAR_DATA_LEN];
    
    uint8_t fee5_val[FEE0_CHAR_DATA_LEN];
    uint8_t fee1_desc[FEE0_CHAR_DATA_LEN];
    uint8_t fee1_desc_len;
    /// Notification configuration of peer devices.
    uint16_t ntf_cfg[BLE_CONNECTION_MAX];
    /// Notification configuration of peer devices.
    uint16_t ind_cfg[BLE_CONNECTION_MAX];

    /// Number of FEE0S
    uint8_t             nb_svc;
    /// Services features
    uint16_t            features;
    /// GATT user local identifier
    uint8_t             user_lid;
    /// Operation On-going
    bool                op_ongoing;
    /// Prevent recursion in execute_operation function
    bool                in_exe_op;

}fee0s_env_t;

/// ongoing operation information
typedef struct fee0s_buf_meta
{
     /// Handle of the attribute to indicate/notify
     uint16_t handle;
     /// used to know on which device interval update has been requested, and to prevent
     /// indication to be triggered on this connection index
     uint8_t  conidx;
     /// Service att index
     uint8_t  att_idx;
} fee0s_buf_meta_t;

/// FEE0 Service server callback set
typedef struct fee0s_cb
{
    /**
     ****************************************************************************************
     * @brief Completion of value update
     *
     * @param[in] status Status of the procedure execution (@see enum hl_err)
     ****************************************************************************************
     */
    void (*cb_fee0s_value_upd_cmp)(uint8_t conidx,uint8_t att_idx,uint16_t status);

     /**
     ****************************************************************************************
     * @brief Inform that data updated for the connection.
     *
     * @param[in] conidx        Connection index
     * @param[in] att_idx       Attributes index
     * @param[in] len           Attributes value len
     * @param[in] data          Notification value data
     ****************************************************************************************
     */
    void (*cb_att_data_upd)(uint8_t conidx,uint8_t att_idx,uint16_t len, uint8_t *data);
    /**
     ****************************************************************************************
     * @brief Inform that Bond data updated for the connection.
     *
     * @param[in] conidx        Connection index
     * @param[in] ntf_cfg       Notification Configuration
     ****************************************************************************************
     */
    void (*cb_bond_data_upd)(uint8_t conidx,uint8_t att_idx, uint8_t ntf_ind_cfg);
} fee0s_cb_t;



uint16_t fee0s_enable(uint8_t conidx);


#endif /* #if (BLE_FEE0_SERVERs) */

#endif /*  _FEE0_H_ */



