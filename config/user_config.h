/**
 ****************************************************************************************
 *
 * @file user_config.h
 *
 * @brief Configuration of the BT function
 *
 * Copyright (C) Beken 2019
 *
 ****************************************************************************************
 */
#ifndef USER_CONFIG_H_
#define USER_CONFIG_H_
#include "uart0.h"
#include "uart1.h"
#include "bk_printf.h"


/******************************* ble config **************************************/
//rwip config  all code
#define CFG_BLE
#define CFG_HOST
#define CFG_APP
#define CFG_EMB
#define CFG_HCITL
#define CFG_CON 1
#define CFG_PERIPHERAL

//#define CFG_CENTRAL
//#define CFG_ALLROLES
#define CFG_ACT   2
// hl_config
#define CFG_HL_MSG_API
//#define CFG_GATT_CLI
#define CFG_NVDS


//rwprf_config 
#define CFG_PRF
#define CFG_NB_PRF  7

#define CFG_PRF_DISS
#define CFG_PRF_BASS
#define CFG_PRF_FEE0S
//#define CFG_PRF_HOGPD
#define CFG_PRF_OADS



//rwapp_config 
#define BLE_APP_PRF 1
#define CFG_APP_DIS
#define CFG_APP_BATT
//#define CFG_APP_HID

#define CFG_APP_OADS
#define CFG_APP_SEC

#define CFG_APP_FEE0S
//#define CFG_APP_FCC0S
//#define CFG_APP_ANCS
//#define CFG_APP_OADS


//#define CFG_ISOGEN
//#define CFG_ISO_CON 2
//#define CFG_ISO_MODE_0
//#define CFG_CIS
//#define CFG_ISO_MODE_0_DEVICE

/****************************************************************************/
/****************************************************************************/


#define VIRTUAL_UART_H4TL          1

#define CONFIG_RF_GPIO_DEBUG       0///RF debugpin enable
#define GPIO_DBG_MSG               0///msg output gpio
#define DEBUG_BKREG                1///used bkreg
#define CONFIG_LDO_XTAL_COMP       0/// LDO & xtal & Voltage temperature compensation
#define SDADC_CALI_DATA_AT_OTP     1/// SDADC calibration data read from OTP



//DRIVER CONFIG
#define UART0_DRIVER                1
#define UART1_DRIVER                1
#define GPIO_DRIVER                 1
#define ADC_DRIVER                  1
#define I2C_DRIVER                  0
#define I2S_DRIVER                  0
#define PWM_DRIVER                  1
#define TIMER0_DRIVER               0 
#define TIMER1_DRIVER               0 
#define RTC_DRIVER                  0
#define USB_DRIVER                  0 
#define SPI_DRIVER                  0 
#define SPI_DMA_MODE                0
#define AUDIO_DRIVER                0 
#define AON_RTC_DRIVER              0

#if(I2S_DRIVER)
#undef DMA_DRIVER
#define DMA_DRIVER                   1 
#undef I2S_DMA_DRIVER
#define I2S_DMA_DRIVER               1 
#endif 


#define ADC_CALIB                   0
#define ENABLE_PHY_2M_LE_CODE       1 
#define ENABLE_EXT_ADV              0 
/******************************************************/
#define PRINT2UART               0   // 0:UART0,1:UART1,2:UART2
#define uart_printf              bk_printf //uart0_printf
#define uart_printf_func         uart_printf("%s\r\n",__func__);



/**
 * Advertising Parameters
 */
#define SYSTEM_SLEEP         1
/// Default Device Name
#define APP_DFLT_DEVICE_NAME            ("BK3437_GATT")
#define APP_DFLT_DEVICE_NAME_LEN        (sizeof(APP_DFLT_DEVICE_NAME))-1

/**
 * Default Scan response data
 * --------------------------------------------------------------------------------------
 * x09                             - Length
 * xFF                             - Vendor specific advertising type
 * x00\x60\x52\x57\x2D\x42\x4C\x45 - "RW-BLE"
 * --------------------------------------------------------------------------------------
 */
#define APP_SCNRSP_DATA         "\x09\xFF\x00\x60\x42\x4B\x2D\x42\x4C\x45"
#define APP_SCNRSP_DATA_LEN     (10)



/// Advertising channel map - 37, 38, 39
#define APP_ADV_CHMAP           (0x07)
/// Advertising minimum interval - 40ms (64*0.625ms)
#define APP_ADV_INT_MIN         (160 )
/// Advertising maximum interval - 40ms (64*0.625ms)
#define APP_ADV_INT_MAX         (160)
/// Fast advertising interval
#define APP_ADV_FAST_INT        (32)



#define BLE_UAPDATA_MIN_INTVALUE    160
#define BLE_UAPDATA_MAX_INTVALUE    160
#define BLE_UAPDATA_LATENCY         4
#define BLE_UAPDATA_TIMEOUT         600

#define CODE_SANITY_CHECK_ENABLE     0
#if CODE_SANITY_CHECK_ENABLE
#undef SPI_DRIVER
#define SPI_DRIVER                   1 
#endif


#define SPI_TO_RGB_1903              0
#define SPI_TO_RGB_2812              0
#if(SPI_TO_RGB_1903||SPI_TO_RGB_2812)
#undef SPI_DRIVER
#define SPI_DRIVER                   1 

#undef SPI_DMA_MODE
#define SPI_DMA_MODE                 1 
#endif // USER_CONFIG_H_

#endif

