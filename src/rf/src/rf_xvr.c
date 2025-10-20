#if 1
#include <string.h>             // for memcpy
#include "rf_xvr.h"                 // RF interface
#include "reg_ipcore.h"        // DM core registers
#if (BLE_EMB_PRESENT)
#include "reg_em_ble_cs.h"      // control structure definitions
#endif
#if (BT_EMB_PRESENT)
#include "reg_btcore.h"         // bt core registers
#include "reg_em_bt_cs.h"       // control structure definitions
#endif 
#include "BK3437_RegList.h"        //// added
#include "icu.h"
#include "stdbool.h"
#include "reg_blecore.h"        // ble core registers
#include "adc.h"
#include "user_config.h"
#include "rwip.h"      // RW SW initialization
extern uint8_t reip_hz32000;
#define RPL_GAIN_TBL_SIZE           0x0F
// EM RF SPI address
#define RF_EM_SPI_ADRESS        (EM_BASE_ADDR + EM_RF_SW_SPI_OFFSET)
#define RPL_SPIRD                   0x00
#define RPL_SPIWR                   0x80
#define RPL_RFPLL_TBL_SIZE          0x50
#define RPL_PWR_TBL_SIZE            0x0F

/* The offset value given below is the offset to add to the frequency table index to
   get the value to be programmed in the radio for each channel                      */
#define RPL_FREQTAB_OFFSET          0   // Offset for Ripple radio

/// Radio skew compensation (round trip delay)
#define RPL_RADIO_SKEW              12L

#define RFLOIF                      0x00

#define RPL_RSSI_20dB_THRHLD        -20
#define RPL_RSSI_45dB_THRHLD        -45
#define RPL_RSSI_48dB_THRHLD        -48
#define RPL_RSSI_55dB_THRHLD        -55
#define RPL_RSSI_60dB_THRHLD        -60
#define RPL_RSSI_70dB_THRHLD        -70

// EDR Control value
#define RPL_EDRCNTL                 18 // Default value is set to 18us
#define RPL_POWER_MAX               0x0c    //// ????
#define RPL_POWER_MIN               0x01    //// ????
#define RPL_POWER_MSK               0x07    //// ????
// Generic RSSI Threshold
#define RF_RPL_RSSI_THR             0x29

extern volatile uint32_t XVR_ANALOG_REG_BAK[32];
uint32_t value_kcal_result_1M;
uint32_t value_kcal_result_2M;
struct temp_map_t temp_map;
// Power table
static const int8_t RF_RPL_TX_PW_CONV_TBL[RPL_PWR_TBL_SIZE] = 
{
    [0] = -23,
    [1] = -20,
    [2] = -17,
    [3] = -14,
    [4] = -11,
    [5] = -8,
    [6] = -5,
    [7] = -2
};
struct temp_map_t map[]=
{
    {325, 0x1D, 4, 0x15, 120},
    {620, 0x1C, 4, 0x35, 110},
    {903, 0x1C, 4, 0x48, 100},
    {1200, 0x1C, 4, 0x50, 90},
    {1490, 0x16, 4, 0x56, 80},
    {1780, 0x16, 4, 0x58, 70},
    {2085, 0x16, 4, 0x59, 60},
    {2410, 0x14, 4, 0x58, 50},
    {2730, 0x12, 4, 0x57, 40},
    {3070, 0x10, 4, 0x55, 30},
    {3370, 0xE, 4, 0x55, 20},
    {3705, 0xC, 4, 0x55, 10},
    {3982, 0xA, 5, 0x55, 0},
    {4284, 0x8, 5, 0x55, -10},
    {4555, 0x6, 5, 0x57, -20},
    {4775, 0x4, 5, 0x5A, -30},
    {4955, 0x2, 5, 0x62, -40},
};

void CLK32K_AutoCali_init(void);
void kmod_calibration_1M(void) ;
void kmod_calibration_2M(void) ;
/**
 *****************************************************************************************
 * @brief Init RF sequence after reset.
 *****************************************************************************************
 */

static void rf_reset(void)
{
  uart_printf("rf_reset\r\n");
}

/**
 *****************************************************************************************
 * @brief Get the TX power as control structure TX power field from a value in dBm.
 *
 * @param[in] txpwr_dbm   TX power in dBm
 * @param[in] high        If true, return index equal to or higher than requested
 *                        If false, return index equal to or lower than requested
 *
 * @return The index of the TX power
 *
 *****************************************************************************************
 */
static uint8_t rf_txpwr_cs_get (int8_t txpwr_dbm, bool high)
{
    uint8_t i;

    for (i = RPL_POWER_MIN; i <= RPL_POWER_MAX; i++)
    {
        // Loop until we find a power just higher or equal to the requested one
        if (RF_RPL_TX_PW_CONV_TBL[i] >= txpwr_dbm)
            break;
    }

    // If equal to value requested, do nothing
    // Else if 'high' is false and index higher than the minimum one, decrement by one
    if ((RF_RPL_TX_PW_CONV_TBL[i] != txpwr_dbm) && (!high) && (i > RPL_POWER_MIN))
    {
        i--;
    }

    return(i);
}





/**
 *****************************************************************************************
 * @brief Get TX power in dBm from the index in the control structure
 *
 * @param[in] txpwr_idx  Index of the TX power in the control structure
 * @param[in] modulation Modulation: 1 or 2 or 3 MBPS
 *
 * @return The TX power in dBm
 *
 *****************************************************************************************
 */

static int8_t rf_txpwr_dbm_get(uint8_t txpwr_idx, uint8_t modulation)
{
    // Power table should be provided
    return(0);
}

/**
 *****************************************************************************************
 * @brief Sleep function for  RF.
 *****************************************************************************************
 */

static void rf_sleep(void)
{
//extern uint16_t test_wakeup_int;
    ip_deepslcntl_set(ip_deepslcntl_get() |0x07);//IP_DEEP_SLEEP_ON_BIT | IP_RADIO_SLEEP_EN_BIT | IP_OSC_SLEEP_EN_BIT
    //uart_printf("r\n");
  //   test_wakeup_int=0;
}


/**
 *****************************************************************************************
 * @brief Convert RSSI to dBm
 *
 * @param[in] rssi_reg RSSI read from the HW registers
 *
 * @return The converted RSSI
 *
 *****************************************************************************************
 */
static int8_t rf_rssi_convert (uint8_t rssi_reg)
{
    uint8_t RssidBm = 0;

     RssidBm = ((rssi_reg) >> 1) - 118;
   // RssidBm = ((rssi_reg) >> 1) - 164;

    return(RssidBm);
}


static uint32_t rf_rpl_reg_rd (uint32_t addr)
{
    uint32_t ret;

    ret = REG_PL_RD(addr);

    return ret;
}

static void rf_rpl_reg_wr (uint32_t addr, uint32_t value)
{
    REG_PL_WR(addr, value);
}


/**
 ****************************************************************************************
 * RADIO FUNCTION INTERFACE
 ****************************************************************************************
 **/

#if defined(CFG_BT)
/**
 *****************************************************************************************
 * @brief Decrease the TX power by one step
 *
 * @param[in] link_id Link ID for which the TX power has to be decreased
 *
 * @return true when minimum power is reached, false otherwise
 *****************************************************************************************
 */
static bool rf_txpwr_dec(uint8_t link_id)
{
    bool boMinpow = true;
    uint8_t tx_pwr = em_bt_pwrcntl_txpwr_getf(EM_BT_CS_ACL_INDEX(link_id)) & RPL_POWER_MSK;

    if (tx_pwr > RPL_POWER_MIN)
    {
        //Increase the TX power value
        em_bt_pwrcntl_txpwr_setf(EM_BT_CS_ACL_INDEX(link_id), tx_pwr-1);
        boMinpow = false;
    }

    return(boMinpow);
}

/**
 *****************************************************************************************
 * @brief Increase the TX power by one step
 *
 * @param[in] link_id Link ID for which the TX power has to be increased
 *
 * @return true when maximum power is reached, false otherwise
 *****************************************************************************************
 */
static bool rf_txpwr_inc(uint8_t link_id)
{
    bool boMaxpow = true;
    uint8_t tx_pwr = em_bt_pwrcntl_txpwr_getf(EM_BT_CS_ACL_INDEX(link_id)) & RPL_POWER_MSK;

    if (tx_pwr < RPL_POWER_MAX)
    {
        //Increase the TX power value
        em_bt_pwrcntl_txpwr_setf(EM_BT_CS_ACL_INDEX(link_id), tx_pwr+1);
        boMaxpow = false;
    }

    return(boMaxpow);
}

/**
 ****************************************************************************************
 * @brief Set the TX power to max
 *
 * @param[in] link_id     Link Identifier
 ****************************************************************************************
 */
static void txpwr_max_set(uint8_t link_id)
{
    //Increase the TX power value
    em_bt_pwrcntl_txpwr_setf(EM_BT_CS_ACL_INDEX(link_id), RPL_POWER_MAX);
}
#endif // CFG_BT


static void rf_force_agc_enable(bool en)
{
    #if defined(CFG_BLE)
    #if defined(CFG_BT)
    ip_radiocntl1_forceagc_en_setf(en);
    #else
    ip_radiocntl1_forceagc_en_setf(en);
    #endif //CFG_BLE

    //ble_forceagc_en_setf(en);
    ble_radiocntl1_forceagc_en_setf(en);
    #endif 
}

void rf_debug_gpio_init(uint8_t mode)
{
    #if (CONFIG_RF_GPIO_DEBUG==1)

    switch(mode)
    {
        case 0:
        {
            // Enable the analog signal, but it will affect the dut program.
            addSYS_Reg0xc = 0x1 << 4 | 0x1 << 3 | 0x7;                     //0xc[17:0]    debug_set

            addSYS_Reg0x31 = 0x00555000;
            addSYS_Reg0x32 = 0x0055;
            addAON_GPIO_Reg0xb |= 0x40 ;   //p13   TX Bit
            addAON_GPIO_Reg0xc |= 0x40 ;   //p14   Rx Bit
            addAON_GPIO_Reg0xd |= 0x40 ;   //p15   Reference clock
            //addAON_GPIO_Reg0xe |= 0x40 ;   //p16   Slot Control
            //addAON_GPIO_Reg0xf |= 0x40 ;   //p17   Ready On
            addAON_GPIO_Reg0x10 |= 0x40 ;   //p20  TRX Mode
            addAON_GPIO_Reg0x11 |= 0x40 ;   //p21  Sync
        }break;
        
        case 1:
        {
            uart_printf("%s %d \n", __func__, __LINE__);

            // //Enables digital signals
            addSYS_Reg0xc = 0x1 << 4;                     //0xc[17:0]    debug_set

            addSYS_Reg0x31 = 0x55555555;
            addSYS_Reg0x32 = 0x55555555;
            addAON_GPIO_Reg0xa |= 0x40 ;   //p12
            addAON_GPIO_Reg0xb |= 0x40 ;   //p13
            addAON_GPIO_Reg0xc |= 0x40 ;   //p14
            addAON_GPIO_Reg0xd |= 0x40 ;   //p15
            addAON_GPIO_Reg0xe |= 0x40 ;   //p16
            addAON_GPIO_Reg0xf |= 0x40 ;   //p17
            addAON_GPIO_Reg0x10 |= 0x40 ;   //p20
            addAON_GPIO_Reg0x11 |= 0x40 ;   //p21
        }break;
    }
    #endif
}

void rf_debug_gpio_32k()
{
    addAON_GPIO_Reg0xb |= 0x40 ;   //p14
    addSYS_Reg0xc = 0x1 << 4;                     //0xc[17:0]    debug_set

    // addSYS_Reg0x31 = 0x55555555;
    addSYS_Reg0x31 = 0x55525555;
    addSYS_Reg0x32 = 0x55555555;
    addAON_GPIO_Reg0xa |= 0x40 ;   //p13
    addAON_GPIO_Reg0xb |= 0x40 ;   //p14
    addAON_GPIO_Reg0xc |= 0x40 ;   //p15
    addAON_GPIO_Reg0xd |= 0x40 ;   //p16
    addAON_GPIO_Reg0xe |= 0x40 ;   //p17
    addAON_GPIO_Reg0xf |= 0x40 ;   //p20
    addAON_GPIO_Reg0x10 |= 0x40 ;   //p21
    addAON_GPIO_Reg0x11 |= 0x40 ;   //p22
}


void xvr_analog_reg_write(unsigned int xvr_idx,unsigned int value)
{
    #if CFG_XVR_BACKUP_EN
    if(xvr_idx < 32)
    {
        XVR_ANALOG_REG_BAK[xvr_idx] = value;
    }
    #endif
    *((volatile unsigned long *) (0x00806E00+ (xvr_idx*4))) = value;
}

//======================================

void delay()
{
  //Delay_ms(1);
}
void xvr_temp_sensor_open(void)
{
    uint32_t tmp = XVR_ANALOG_REG_BAK[0xc];
    tmp |= (0x1 << 15);
    addXVR_Reg0xc  = tmp; XVR_ANALOG_REG_BAK[0xc] = tmp;//chose the GADC input
}
void xvr_set_ldo(uint8_t adjv)
{

    uint32_t tmp = XVR_ANALOG_REG_BAK[0x8];
    if((tmp>>15 & 0x1F) == adjv)
    {
        return;
    }
    
    tmp = XVR_ANALOG_REG_BAK[0xa];    // open clk
    tmp |= (0x1 << 12);
    addXVR_Reg0xa  = tmp;    XVR_ANALOG_REG_BAK[0xa] = tmp;

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp &= ~(0x1f<<15);
    tmp |= (adjv<<15);
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp &= ~(0x1<<20);
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;
    Delay_ms(1);

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp |= (0x1<<20);
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;

    tmp = XVR_ANALOG_REG_BAK[0xa];    // close clk
    tmp &= ~(0x1 << 12);
    addXVR_Reg0xa  = tmp;    XVR_ANALOG_REG_BAK[0xa] = tmp;
}

uint8_t xvr_ldo_auto_cali(void)
{
    uint8_t val;
    uint32_t tmp = XVR_ANALOG_REG_BAK[0xa];    // open clk
    tmp |= (0x1 << 12);
    addXVR_Reg0xa  = tmp;    XVR_ANALOG_REG_BAK[0xa] = tmp;

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp &= ~((0x1<<22) | (0x1<<21) | (0x1<<20));
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp |= (1<<20);
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp &= ~(1<<15);
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;
    Delay_ms(1);

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp |= (1<<15);
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;

    Delay_ms(1);

    val = (uint8_t)((addPMU_Reg0x5>>1) & 0xF);

    tmp = XVR_ANALOG_REG_BAK[0x8];
    tmp |= (1<<22);
    addXVR_Reg0x8  = tmp;    XVR_ANALOG_REG_BAK[0x8] = tmp;

    tmp = XVR_ANALOG_REG_BAK[0xa];    // close clk
    tmp &= ~(0x1 << 12);
    addXVR_Reg0xa  = tmp;    XVR_ANALOG_REG_BAK[0xa] = tmp;

    return val;
}

void xvr_set_voltage(uint8_t volt)
{
    uint32_t tmp = XVR_ANALOG_REG_BAK[0x9];
    if((tmp>>7 & 0x7) == volt)
    {
        return;
    }
    tmp &= ~(0x7<<7);
    tmp |= (volt<<7);
    addXVR_Reg0x9  = tmp;
    XVR_ANALOG_REG_BAK[0x9] = tmp;
}
void xtal_set_cal(uint8_t cal_data)
{
    if(cal_data>0x7f)
        cal_data=0x7f;
    XVR_ANALOG_REG_BAK[0xc] = XVR_ANALOG_REG_BAK[0xc]&(~0x7f);
    XVR_ANALOG_REG_BAK[0xc] |=cal_data;
    addXVR_Reg0xc = XVR_ANALOG_REG_BAK[0xc] ;
}
void set_power(uint8_t power_level)
{
    uint32_t val = 0;
    uint32_t reg = XVR_ANALOG_REG_BAK[0x04];

    addXVR_Reg0x24 &= ~(0x1 << 20);
    addXVR_Reg0x4 = reg | (0x1 << 29);
    val |= (power_level << 7);
    addXVR_Reg0x24 &= ~(0xf << 7);
    addXVR_Reg0x24 |= val;
}
void filter_triger(void)
{
    uint32_t tmp = XVR_ANALOG_REG_BAK[0x5];
    tmp &= ~(0x1<<26);
    addXVR_Reg0x5  = tmp;    XVR_ANALOG_REG_BAK[0x5] = tmp;
    Delay_ms(10);

    tmp = XVR_ANALOG_REG_BAK[0x5];
    tmp |= (0x1<<26);
    addXVR_Reg0x5  = tmp;    XVR_ANALOG_REG_BAK[0x5] = tmp;
    Delay_ms(50);

    tmp = XVR_ANALOG_REG_BAK[0x5];
    tmp &= ~(0x1<<26);
    addXVR_Reg0x5  = tmp;    XVR_ANALOG_REG_BAK[0x5] = tmp;
}

bool adc_code_to_adj(int16_t code, struct temp_map_t *code_adj)
{
    static int16_t this_temp = 0;
    static int16_t last_temp = 0;
    
    if(code < CODE_MIN)
    {
        code_adj->adj_ldo = map[0].adj_ldo;
        code_adj->crystal = map[0].crystal;
        code_adj->volt = map[0].volt;
        this_temp = map[0].temp;
        uart_printf("3. code = %d, map[0].code = %d, thie_temp = %d\r\n", code, map[0].code, this_temp);
        
    }
    else if(code > CODE_MAX)
    {
        code_adj->adj_ldo = map[sizeof(map)/sizeof(map[0])-1].adj_ldo;
        code_adj->crystal = map[sizeof(map)/sizeof(map[0])-1].crystal;
        code_adj->volt = map[sizeof(map)/sizeof(map[0])-1].volt;
        this_temp = map[sizeof(map)/sizeof(map[0])-1].temp;
        uart_printf("4. code = %d, map[0].code = %d, thie_temp = %d\r\n", code, map[sizeof(map)/sizeof(map[0])-1].code, this_temp);
    }
    for(int i=0; i < sizeof(map)/sizeof(map[0]); i++)
    {
        if (code >= map[i].code && code <= (int16_t)((map[i].code + map[i+1].code) / 2))
        {
            code_adj->adj_ldo = map[i].adj_ldo;
            code_adj->crystal = map[i].crystal;
            code_adj->volt = map[i].volt;
            this_temp = map[i].temp;
            break;
        }
        else if(code >(int16_t)((map[i].code + map[i+1].code) / 2) && code <= map[i+1].code)
        {
            code_adj->adj_ldo = map[i+1].adj_ldo;
            code_adj->crystal = map[i+1].crystal;
            code_adj->volt = map[i+1].volt;
            this_temp = map[i+1].temp;
            break;
        }
    }

    //uart_printf("firstsample = %d, last_temp = %d, this_temp = %d\n", firstsample, last_temp, this_temp);
    if((((last_temp - this_temp) >= 0? (last_temp - this_temp) : (this_temp - last_temp)) < 10))
        return false;    
    else
    {
        last_temp = this_temp;
        //uart_printf("ldo = %d, crystal = %d, volt = %d\n", code_adj->adj_ldo, code_adj->crystal, code_adj->volt);
        uart_printf("{\"Tempe\": {\"T\":%d,\"LDO\":%X,\"X\":%X,\"V\":%X}}\r\n",this_temp,code_adj->adj_ldo, code_adj->crystal, code_adj->volt);
        return true;
    }
}
extern uint8_t RF_CHANNEL_TABLE[80];
void fcc_hopping(uint8_t freq)
    // only pn9 mode
{
	/************************************************************/
	//!!!!!!!!!!!!!!!!!! note !!!!!!!!!!!!!!!!!!!!!!!!
	//verify each chn data,and set each demo!!!!!!!!!!!!!!!!!!
	XVR_ANALOG_REG_BAK[0x1] |= 1<<14;
	XVR_ANALOG_REG_BAK[0x1] &= ~(0xff<<15);
	if(freq<42)
		XVR_ANALOG_REG_BAK[0x1]  |= 0xa0<<15;
	else
		XVR_ANALOG_REG_BAK[0x1]  |= 0xac<<15;
	addXVR_Reg0x1 = XVR_ANALOG_REG_BAK[0x1];
//	rom_env.stack_printf("f=%x\n",freq);
	//!!!!!!!!!!!!!!!!!! note end !!!!!!!!!!!!!!!!!!!!!!!!
	/************************************************************/

}

void xvr_reg_initial(void) 
{
    set_PMU_Reg0x14_voltage_ctrl_work_aon(0xa);
    // addXVR_Reg0x0  = 0x1731B140;    XVR_ANALOG_REG_BAK[0x0] = 0x1731B140;delay( );
    addXVR_Reg0x0  = 0x1331B140;    XVR_ANALOG_REG_BAK[0x0] = 0x1331B140;delay( );  // 231116 3437B
    addXVR_Reg0x1  = 0x4C561007;    XVR_ANALOG_REG_BAK[0x1] = 0x4C561007;delay( );
    // addXVR_Reg0x2  = 0x6FFAFFE4;    XVR_ANALOG_REG_BAK[0x2] = 0x6FFAFFE4;delay( );
    addXVR_Reg0x2  = 0x2DEADFE4;    XVR_ANALOG_REG_BAK[0x2] = 0x2DEADFE4;delay( );    // 231116 3437B
    addXVR_Reg0x3  = 0x00000000;    XVR_ANALOG_REG_BAK[0x3] = 0x00000000;delay( );

    addXVR_Reg0x4  = 0x8FDFBEBC;    XVR_ANALOG_REG_BAK[0x4] = 0x8FDFBEBC;delay( );

    addXVR_Reg0x5  = 0x4A2F08C8;    XVR_ANALOG_REG_BAK[0x5] = 0x4A2F08C8;delay( );

    addXVR_Reg0x6  = 0x8DBA45A0;    XVR_ANALOG_REG_BAK[0x6] = 0x8DBA45A0;delay( );    // 202312222 for agc
    addXVR_Reg0x7  = 0x68410500;    XVR_ANALOG_REG_BAK[0x7] = 0x68410500;delay( );
    addXVR_Reg0x8  = 0x1FE804AF;    XVR_ANALOG_REG_BAK[0x8] = 0x1FE804AF;delay( );
    //addXVR_Reg0x9  = 0x4E57F250;    XVR_ANALOG_REG_BAK[0x9] = 0x4E57F250;delay( );      // kmod modify  0x4E57F0D0
    addXVR_Reg0x9  = 0x4E57F0D8;    XVR_ANALOG_REG_BAK[0x9] = 0x4E57F0D8;delay( ); 
#if (HZ32000)
    addXVR_Reg0xa  = 0x70844A2D;    XVR_ANALOG_REG_BAK[0xa] = 0x70844A2D;delay( ); //RC32k
    reip_hz32000 = TRUE;
#else
    addXVR_Reg0xa  = 0x74844A2D;  XVR_ANALOG_REG_BAK[0xa] = 0x74844A2D;delay( ); //xtal
    reip_hz32000 = FALSE;
#endif
    addXVR_Reg0xb  = 0x1F40C568;    XVR_ANALOG_REG_BAK[0xb] = 0x1F40C568;delay( ); //1s

    addXVR_Reg0xc  = 0x73B0323F;    XVR_ANALOG_REG_BAK[0xc] = 0x73B0323F;delay( );
    addXVR_Reg0xd  = 0x00000000;    XVR_ANALOG_REG_BAK[0xd] = 0x00000000;delay( );
    addXVR_Reg0xe  = 0x94018030;    XVR_ANALOG_REG_BAK[0xe] = 0x94018030;delay( );
    addXVR_Reg0xf  = 0x00000000;    XVR_ANALOG_REG_BAK[0xf] = 0x00000000;delay( );
    addXVR_Reg0x10 = 0x00003437;    XVR_ANALOG_REG_BAK[0x10] = 0x00003437;delay( );
    addXVR_Reg0x11 = 0x22610A20;    XVR_ANALOG_REG_BAK[0x11] = 0x22610A20;delay( );
    addXVR_Reg0x12 = 0x40002953;    XVR_ANALOG_REG_BAK[0x12] = 0x40002953;delay( );
    addXVR_Reg0x13 = 0x62020019;    XVR_ANALOG_REG_BAK[0x13] = 0x62020019;delay( );
    addXVR_Reg0x14 = 0x04080000;    XVR_ANALOG_REG_BAK[0x14] = 0x04080000;delay( );
    addXVR_Reg0x15 = 0x010FF18A;    XVR_ANALOG_REG_BAK[0x15] = 0x010FF18A;delay( );
    addXVR_Reg0x16 = 0x000767F6;    XVR_ANALOG_REG_BAK[0x16] = 0x000767F6;delay( );
    addXVR_Reg0x17 = 0x00617420;    XVR_ANALOG_REG_BAK[0x17] = 0x00617420;delay( );
    addXVR_Reg0x18 = 0x000001FF;    XVR_ANALOG_REG_BAK[0x18] = 0x000001FF;delay( );
    addXVR_Reg0x19 = 0x00000000;    XVR_ANALOG_REG_BAK[0x19] = 0x00000000;delay( );
    addXVR_Reg0x1a = 0x00000000;    XVR_ANALOG_REG_BAK[0x1a] = 0x00000000;delay( );
    addXVR_Reg0x1b = 0x0000314B;    XVR_ANALOG_REG_BAK[0x1b] = 0x0000314B;delay( );
    addXVR_Reg0x1c = 0x00000000;    XVR_ANALOG_REG_BAK[0x1c] = 0x00000000;delay( );
    addXVR_Reg0x1d = 0x00000000;    XVR_ANALOG_REG_BAK[0x1d] = 0x00000000;delay( );
    addXVR_Reg0x1e = 0x00000000;    XVR_ANALOG_REG_BAK[0x1e] = 0x00000000;delay( );
    addXVR_Reg0x1f = 0x00000000;    XVR_ANALOG_REG_BAK[0x1f] = 0x00000000;delay( );
    xtal_set_cal(0x46);

    addXVR_Reg0x20 = 0x0295E5DC;        delay( );
    addXVR_Reg0x21 = 0x96000000;        delay( );
    addXVR_Reg0x22 = 0x96000000;        delay( );
    addXVR_Reg0x23 = 0x00000000;        delay( );
    addXVR_Reg0x24 = 0x400007A0;        delay( );
    addXVR_Reg0x25 = 0x00000000;        delay( );
    // addXVR_Reg0x26 = 0x10200557;        delay( );
  // addXVR_Reg0x26 = 0x10200526;        delay( );
    addXVR_Reg0x26 = 0x10200703;        delay( );   // 231115 3437B
    addXVR_Reg0x27 = 0x00000001;        delay( );
    addXVR_Reg0x28 = 0x01014363;        delay( );
    addXVR_Reg0x29 = 0x001B7C00;        delay( );
    addXVR_Reg0x2a = 0x00102828;        delay( );
    addXVR_Reg0x2b = 0x00000000;        delay( );
    addXVR_Reg0x2c = 0x00000000;        delay( );
    addXVR_Reg0x2d = 0x0838D441;        delay( );
    addXVR_Reg0x2e = 0x00000100;        delay( );
    addXVR_Reg0x2f = 0x00000000;        delay( );
    addXVR_Reg0x30 = 0x1000E311;        delay( );

    addXVR_Reg0x31 = 0x00000000;        delay( );
    addXVR_Reg0x32 = 0x00000000;        delay( );
    addXVR_Reg0x33 = 0x00000000;        delay( );
    addXVR_Reg0x34 = 0x00000000;        delay( );
    addXVR_Reg0x35 = 0x00000000;        delay( );
    //addXVR_Reg0x36 = 0x00000000;        delay( );
    //addXVR_Reg0x37 = 0x00000000;        delay( );
    //addXVR_Reg0x38 = 0x00000000;        delay( );
    addXVR_Reg0x39 = 0x00000000;        delay( );
    addXVR_Reg0x3a = 0x00120000;        delay( );
    // addXVR_Reg0x3b = 0x36241048;        delay( );
    //addXVR_Reg0x3b = 0x3624104C;        delay( );
  
    // addXVR_Reg0x3c = 0x97FF021E;        delay( );
    // addXVR_Reg0x3c = 0x17FF021E;        delay( );

    //agc config.
    // addXVR_Reg0x38 = 0x9501F0F8;        delay( );
    addXVR_Reg0x38 = 0x80007E3F;        delay( );    // 0x95003E1F;// 202312222 for agc
  
    // addXVR_Reg0x39 = 0x300CE000;        delay( );
    addXVR_Reg0x39 = 0x500C0E00;        delay( );
  
    // addXVR_Reg0x3c = 0x13FDF0F8;        delay( );
    //addXVR_Reg0x3c = 0x17FC7E3F;        delay( );//0x17FC3E1F;        delay( );// 202312222 for agc

    //update for rssi 
    addXVR_Reg0x38 = 0x95007e3f;        delay( );  
    addXVR_Reg0x3c = 0x17FC7E3F;        delay( );    
    addXVR_Reg0x36 = 0x05047776;        delay( );
    addXVR_Reg0x37 = 0x00000000;        delay( );
    addXVR_Reg0x3b = 0x3624144C;        delay( );
   

    addXVR_Reg0x3d = 0x00000000;        delay( );
    addXVR_Reg0x3e = 0x00000000;        delay( );
    addXVR_Reg0x3f = 0x00000000;        delay( );
    addXVR_Reg0x40 = 0x01000000;        delay( );
    addXVR_Reg0x41 = 0x07050402;        delay( );
    addXVR_Reg0x42 = 0x120F0C0A;        delay( );
    addXVR_Reg0x43 = 0x221E1A16;        delay( );
    addXVR_Reg0x44 = 0x35302B26;        delay( );
    addXVR_Reg0x45 = 0x4B45403A;        delay( );
    addXVR_Reg0x46 = 0x635D5751;        delay( );
    addXVR_Reg0x47 = 0x7C767069;        delay( );
    addXVR_Reg0x48 = 0x968F8983;        delay( );
    addXVR_Reg0x49 = 0xAEA8A29C;        delay( );
    addXVR_Reg0x4a = 0xC5BFBAB4;        delay( );
    addXVR_Reg0x4b = 0xD9D4CFCA;        delay( );
    addXVR_Reg0x4c = 0xE9E5E1DD;        delay( );
    addXVR_Reg0x4d = 0xF5F3F0ED;        delay( );
    addXVR_Reg0x4e = 0xFDFBFAF8;        delay( );
    addXVR_Reg0x4f = 0xFFFFFFFE;        delay( );

    addXVR_Reg0x24 = 0x000A0782;        delay( );
    addXVR_Reg0x8 = 0x1FC804AF;    XVR_ANALOG_REG_BAK[0x8] = 0x1FC804AF;delay( );
  
    #if CONFIG_LDO_XTAL_COMP
    {
        static uint8_t firstsample = 1;
        int16_t tempe_smpl;
        uint8_t ldo_cali_val;
        xvr_temp_sensor_open();
        Delay_ms(10);
        tempe_smpl = get_temperature_sensor_data();
        if(firstsample)
        {
            adc_code_to_adj(tempe_smpl, &temp_map);
            // xvr_set_ldo(temp_map.adj_ldo);
            ldo_cali_val = xvr_ldo_auto_cali();
            xvr_set_voltage(temp_map.volt);
            xtal_set_cal(temp_map.crystal);
            firstsample = 0;
            uart_printf("Init(Tempe/LDO/Volt/Xtal):%d,%x,%x,%x",tempe_smpl,ldo_cali_val,temp_map.volt,temp_map.crystal);
        }
        filter_triger();
    }
    #endif
    
    rc32k_calib_soft();
    Delay_ms(10);
    kmod_calibration_1M();
    kmod_calibration_2M();
    addXVR_Reg0x30 = value_kcal_result_1M;
    IF_filter_cali();
#if CONFIG_RC32K_CALIBRATION
    clk32K_esti();
#endif

	//	single_wave_config(0,0x0f);
		
  //  single_wave_config(0x20,0x0f);
}

/* GPIO P16设置成高阻;
PMU reg10 bit<23> bit<18>设置成1
PMU reg12 bit<23> bit<18>设置成0
XVR regA bit<24>设置成1
XVR regC bit<19>设置成1
XVR regC bit<11>设置成1 */
void open_rc32k_debug_pin()
{
    addAON_GPIO_Reg0xe = 0x8;
    
    addPMU_Reg0x10 |=  (1<<23);
    addPMU_Reg0x10 |=  (1<<18);
    addPMU_Reg0x12 &=  ~(1<<23);
    addPMU_Reg0x12 &=  ~(1<<18);

    uint32_t reg = XVR_ANALOG_REG_BAK[0xa];
    reg |= (1<<24);
    addXVR_Reg0xa  = reg;    XVR_ANALOG_REG_BAK[0xa] = reg;

    reg = XVR_ANALOG_REG_BAK[0xc];
    reg |= (1<<19);
    reg |= (1<<11);
    addXVR_Reg0xc  = reg;    XVR_ANALOG_REG_BAK[0xc] = reg;

}

/* 
GPIO P17设置成高阻;
PMU reg10  bit<18>设置成1
PMU reg12  bit<18>设置成0
XVR regA bit<6>设置成1
XVR regC bit<19>设置成1
XVR regC bit<11>设置成1 
XVR regC bit<10>设置成1 
*/
void open_32m_debug_pin()
{
    addAON_GPIO_Reg0xf = 0x8;
    
    addPMU_Reg0x10 |=  (1<<23);
    addPMU_Reg0x10 |=  (1<<18);
    addPMU_Reg0x12 &=  ~(1<<23);
    addPMU_Reg0x12 &=  ~(1<<18);

    uint32_t reg = XVR_ANALOG_REG_BAK[0xa];
    reg |= (1<<6);
    addXVR_Reg0xa  = reg;
    XVR_ANALOG_REG_BAK[0xa] = reg;

    reg = XVR_ANALOG_REG_BAK[0xc];
    reg |= (1<<19);
    reg |= (1<<11);
    reg |= (1<<10);
    addXVR_Reg0xc  = reg;
    XVR_ANALOG_REG_BAK[0xc] = reg;

}

#if 0
void rc32k_calib(void)
{
    #if (HZ32000)// Due to the influence of ambient temperature, it is necessary to calibrate every 5s.
    #define CALIBRATION_TIME   (16025)  //5s
    static uint32_t calib_time = 0;
    uint32_t cur_time = rwip_time_get().hs;
    if(cur_time > calib_time)
    {
        if(cur_time - calib_time > CALIBRATION_TIME)
        {
            rc32k_calib_software();
            calib_time = cur_time;
        }
    }
    else
    {
        calib_time = cur_time;
    }
    #endif
}
#endif
//Hardware auto-calibration, for example, 1s calibration once, there will be 7ms error in 300ms, and the error exists a calibration interval.
void rc32k_calib_hw(void)
{
#if 1
    uint32_t reg = XVR_ANALOG_REG_BAK[0xb];
    reg |= (1<<14);
    addXVR_Reg0xb  = reg;    XVR_ANALOG_REG_BAK[0xb] = reg;

    reg |= (1<<15);
    addXVR_Reg0xb  = reg;    XVR_ANALOG_REG_BAK[0xb] = reg;
#else
    uint32_t reg = XVR_ANALOG_REG_BAK[0xb];  //  
/*    reg |= (1<<13);  //  
    addXVR_Reg0xb  = reg;    
    XVR_ANALOG_REG_BAK[0xb] = reg;  */
//  Delay_ms(50);      
    reg &= ~(0x07<<13);    
    addXVR_Reg0xb  = reg;    
    XVR_ANALOG_REG_BAK[0xb] = reg; //   
    Delay_ms(50);    reg |= (1<<15);    
    addXVR_Reg0xb  = reg;    
    XVR_ANALOG_REG_BAK[0xb] = reg;
 #endif   
}
//Software auto-calibration, for example, 1s calibration once, there will be 7ms error in 300ms, and the error exists a calibration interval.void 

void open_if()
{
  addPMU_Reg0x10 = addPMU_Reg0x10 | (1<<23);
  addPMU_Reg0x10 = addPMU_Reg0x10 | (1<<18);

  addPMU_Reg0x12 = addPMU_Reg0x12  & (~(1<<23));
  addPMU_Reg0x12 = addPMU_Reg0x12  & (~(1<<18));

  addAON_GPIO_Reg0xf = 8;
  addAON_GPIO_Reg0xe = 8;
  uint32_t tmp =     XVR_ANALOG_REG_BAK[0xc];
  tmp = tmp | (1<<19);
  tmp = tmp & (~(7<<12));
  tmp = tmp | (3<<12);
  addXVR_Reg0xc  = tmp;    XVR_ANALOG_REG_BAK[0xc] = tmp;delay( );
}


void kmod_calibration_1M(void) 
{
    uart_printf("%s\r\n",__func__);
    uint32_t value;
    uint32_t value_kcal_result;

// start
    //step 1
  /*  addXVR_Reg0x30 |= (0x1 << 3);
    addXVR_Reg0x30 &= ~(0x3 << 0);  
    addXVR_Reg0x30 &= ~(0x1FF << 8);  
    addXVR_Reg0x30 |= (0x100 << 8);
    addXVR_Reg0x30 &= ~(0x1FF << 20);  
    addXVR_Reg0x30 |= (0x100 << 20);*/

    addXVR_Reg0x30 &= ~((0x3 << 0)|(0x1FF << 8)|(0x1FF << 20));  
    addXVR_Reg0x30 |= (0x100 << 8)| (0x1 << 3)|(0x100 << 20);

    //step 2
    addXVR_Reg0x24 |= (0x1<< 30); // 1M MODE
    addXVR_Reg0x24 &= ~((0x1U<< 31)|(0x1 << 17)|(0x7f));

    // step 3
  /*  addXVR_Reg0x24 &= ~(0x1 << 17);
    addXVR_Reg0x24 &= ~(0x7f);*/

    //step 4
    addXVR_Reg0x25 |= (0x07<<11);
 /*   Delay_ms(10);
    addXVR_Reg0x25 |= (1<<12);
    Delay_ms(10);
    addXVR_Reg0x25 |= (1<<13);
    Delay_ms(10);
    addXVR_Reg0x25 |= (1<<11);*/
 //   Delay_ms(10);

    // XVR_ANALOG_REG_BAK[3] |= (0x1 << 7);
    // addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];

    // Delay_ms(10);
    // XVR_ANALOG_REG_BAK[3] &= ~(0x1 << 6);
    // addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];

    //reg0 bit4:1
    // XVR_ANALOG_REG_BAK[0] |= (0x1 << 4);
    // addXVR_Reg0x0 = XVR_ANALOG_REG_BAK[0];

    //setp 5
    // reg0 bit4:1
    XVR_ANALOG_REG_BAK[0] |= (0x1 << 4);
    addXVR_Reg0x0 = XVR_ANALOG_REG_BAK[0];

    //step 6
    Delay_ms(10);
    addXVR_Reg0x25 |= (1<<16);

    //step 7
    ///////////////////////////start end
    Delay_ms(30);       //@16M ,<90ms
    value = addXVR_Reg0x12;
    uart_printf("read xvr_reg0x12:0x%x\r\n",value);
    value = ((value >> 16) & 0x1fff) /2;
    if(value<250){
   //   uart_printf("cal value:0x%x\r\n",value);
      // uart_printf("cal value:0x%x\r\n",value);
      value_kcal_result =  0x100 ; 
    }else{
   //   uart_printf("cal value:0x%x\r\n",value);
      // uart_printf("cal value:0x%x\r\n",value);
      value_kcal_result =  ((250*256/value)&0x1ff) ; 
    }
    addXVR_Reg0x30 &= ~(0x1ff<<8);
    addXVR_Reg0x30 |= (value_kcal_result<<8);
    uart_printf("value_kcal_resulte:0x%x\r\n",value_kcal_result);
 //   value_kcal_result_1M = value_kcal_result;

    //step 8
    addXVR_Reg0x25 &= ~((1<<16)|(0X7 <<11));
  /*  addXVR_Reg0x25 &= ~(1<<16);

    addXVR_Reg0x25 &= ~(0X7 <<11);*/
    
    // XVR_ANALOG_REG_BAK[3] &= ~(0x1 << 7);
    // addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];

    // XVR_ANALOG_REG_BAK[3] |= (0x1 << 6);
    // addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];

    // XVR_ANALOG_REG_BAK[0] &= ~(0x1 << 4);
    // addXVR_Reg0x0 = XVR_ANALOG_REG_BAK[0];
    ////////////////////////

    XVR_ANALOG_REG_BAK[0] &= ~(0x1 << 4);
    addXVR_Reg0x0 = XVR_ANALOG_REG_BAK[0];

    addXVR_Reg0x30 &= ~((0x1 <<3)|(0x3 << 0));
    
  //  addXVR_Reg0x30  &= ~(0x3 << 0);  
    addXVR_Reg0x30  |= (0x1<< 0);
      
    
    addXVR_Reg0x24 &= ~((0x1<< 30)|(0x1U<< 31));
    
 //   addXVR_Reg0x24 &= ~(0x1U<< 31);
    addXVR_Reg0x24 |= (0x1<< 17);
    value_kcal_result_1M = addXVR_Reg0x30;
}
void kmod_calibration_2M(void) 
{
    uart_printf("%s\r\n",__func__);
    uint32_t value;
    uint32_t value_kcal_result;

// start
    //setp 1
  /*  addXVR_Reg0x30 |= (0x1 << 3);
    addXVR_Reg0x30 &= ~(0x3 << 0);  
    addXVR_Reg0x30 &= ~(0x1FF << 8);  
    addXVR_Reg0x30 |= (0x100 << 8);
    addXVR_Reg0x30 &= ~(0x1FF << 20);  
    addXVR_Reg0x30 |= (0x100 << 20);*/

    addXVR_Reg0x30 &= ~((0x3 << 0)|(0x1FF << 8)|(0x1FF << 20));  
    addXVR_Reg0x30 |= (0x100 << 8)| (0x1 << 3)|(0x100 << 20);

    //step 2
    addXVR_Reg0x24 |= (0x1<< 30); // 2M MODE
    addXVR_Reg0x24 |= (0x1U<< 31);

    //step 3
    addXVR_Reg0x24 &= ~((0x1 << 17)|(0x7f));

  /*  addXVR_Reg0x24 &= ~(0x1 << 17);
    
    addXVR_Reg0x24 &= ~(0x7f);*/
   
    //step 4
    addXVR_Reg0x25 |= (0x07<<11);
 /*   Delay_ms(10);
    addXVR_Reg0x25 |= (1<<12);
    Delay_ms(10);
    addXVR_Reg0x25 |= (1<<13);
    Delay_ms(10);
    addXVR_Reg0x25 |= (1<<11);*/

    //step 5
    XVR_ANALOG_REG_BAK[3] |= (0x1 << 7);
    XVR_ANALOG_REG_BAK[3] &= ~(0x1 << 6);
    addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];
    
 /*   Delay_ms(10);

    XVR_ANALOG_REG_BAK[3] |= (0x1 << 7);
    addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];

    Delay_ms(10);
    XVR_ANALOG_REG_BAK[3] &= ~(0x1 << 6);
    addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];*/

    //step 6
    Delay_ms(10);
    addXVR_Reg0x25 |= (1<<16);

    //step 7
    ///////////////////////////start end
    Delay_ms(30);           //@16M ,<90ms
    value = addXVR_Reg0x12;
    uart_printf("read xvr_reg0x12:0x%x\r\n",value);
    value = ((value >> 16) & 0x1fff)/2;
    uart_printf("2M_cal value:0x%x\r\n",value);
    value_kcal_result =  ((500*256/value)&0x1ff) ; 
    addXVR_Reg0x30 &= ~(0x1ff<<8);
    addXVR_Reg0x30 |= (value_kcal_result<<8);
    uart_printf("value_kcal_resulte:0x%x\r\n",value_kcal_result);
  //  value_kcal_result_2M = value_kcal_result;
  
    /// end   

    //step 8
    addXVR_Reg0x25 &= ~((1<<16)|(0X7 <<11));
  /*  addXVR_Reg0x25 &= ~(1<<16);

    addXVR_Reg0x25 &= ~(0X7 <<11); */

    XVR_ANALOG_REG_BAK[3] &= ~(0x1 << 7);
    XVR_ANALOG_REG_BAK[3] |= (0x1 << 6);
    addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];
  /*  XVR_ANALOG_REG_BAK[3] &= ~(0x1 << 7);
    addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];

    XVR_ANALOG_REG_BAK[3] |= (0x1 << 6);
    addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];*/
    
    ////////////////////////

    addXVR_Reg0x30 &= ~((0x1 <<3)|(0x3 << 0));
  /*  addXVR_Reg0x30 &= ~(0x1 <<3);
    
    addXVR_Reg0x30  &= ~(0x3 << 0);  */
    addXVR_Reg0x30  |= (0x1<< 0);
      
    addXVR_Reg0x24 &= ~((0x1<< 30)|(0x1U<< 31));
   /* addXVR_Reg0x24 &= ~(0x1<< 30);
    
    addXVR_Reg0x24 &= ~(0x1U<< 31);*/
    addXVR_Reg0x24 |= (0x1<< 17);
    value_kcal_result_2M = addXVR_Reg0x30;

}

void XVR_Initial_PN9_Function(void)
{
//    addXVR_Reg0x0 = 0xC4B0323F;
//    addXVR_Reg0x1 = 0x8295C200;
//    addXVR_Reg0x2 = 0x2F22A000;
//    addXVR_Reg0x3 = 0x02D28442;
//    addXVR_Reg0x4 = 0x5F1EAECB;
//    addXVR_Reg0x5 = 0x4820D213;
//    addXVR_Reg0x6 = 0xE8AF4E00;
//    addXVR_Reg0x7 = 0xAA022084;
//    addXVR_Reg0x8 = 0x27F8800F;
//    addXVR_Reg0x9 = 0x70203C08;
//    addXVR_Reg0xa = 0x9827585F;
//    addXVR_Reg0xb = 0x0FD93F23;
//    addXVR_Reg0xc = 0x8000D008;
//    addXVR_Reg0xd = 0x00000000;
//    addXVR_Reg0xe = 0x00000000;
//    addXVR_Reg0xf = 0x7AE147AE;
    addXVR_Reg0x10 = 0x000A3437;
    addXVR_Reg0x11 = 0x20A10020;
    addXVR_Reg0x12 = 0x00000C50;
    addXVR_Reg0x13 = 0x52020002;
    addXVR_Reg0x14 = 0x05080000;
    addXVR_Reg0x15 = 0x00030D97;
    addXVR_Reg0x16 = 0x000000AA;
    addXVR_Reg0x17 = 0x01516414;
    addXVR_Reg0x18 = 0x000001FF;
    addXVR_Reg0x19 = 0x00380000;
    addXVR_Reg0x1a = 0x80005970;
    addXVR_Reg0x1b = 0x00000000;  
//    addXVR_Reg0x1c = 0x0FD3F3F9;
//    addXVR_Reg0x1d = 0x00000000;
//    addXVR_Reg0x1e = 0x00000000;
//    addXVR_Reg0x1f = 0x00000000;
    addXVR_Reg0x20 = 0x0295E5DC;
    addXVR_Reg0x21 = 0x96000000;
    addXVR_Reg0x22 = 0x78000000;
    addXVR_Reg0x23 = 0xA0000000;
    addXVR_Reg0x24 = 0x40000785;
    addXVR_Reg0x25 = 0x00002600;
    addXVR_Reg0x26 = 0x14A40500;
    addXVR_Reg0x27 = 0x0008C900;
    addXVR_Reg0x28 = 0x0F1F1010;
    addXVR_Reg0x29 = 0x7C104E00;
    addXVR_Reg0x2a = 0x1208404D;
    addXVR_Reg0x2b = 0x00000408;
    addXVR_Reg0x2c = 0x0A6A5C71;
    addXVR_Reg0x2d = 0x082AC441;
    addXVR_Reg0x2e = 0x00000100;
    addXVR_Reg0x2f = 0x00000000;
    addXVR_Reg0x30 = 0x10010001;
    addXVR_Reg0x31 = 0x00000000;
    addXVR_Reg0x32 = 0x00000000;
    addXVR_Reg0x33 = 0x00000000;
    addXVR_Reg0x34 = 0x00000000;
    addXVR_Reg0x35 = 0x00000000;
    addXVR_Reg0x36 = 0x00000000;
    addXVR_Reg0x37 = 0x00000000;
    addXVR_Reg0x38 = 0x00000000;
    addXVR_Reg0x39 = 0x00000000;
    addXVR_Reg0x3a = 0x00028000;
    addXVR_Reg0x3b = 0x362434C8;
    addXVR_Reg0x3c = 0x01FF1C80;
    
    
    addXVR_Reg0x38 = 0X0000ff7f;// REG_38
    addXVR_Reg0x39 = 0X30000000;// REG_39
    addXVR_Reg0x3c = 0x00FF3f7f;// REG_3C

    addXVR_Reg0x3d = 0x00000000;
    addXVR_Reg0x3e = 0x143CD940;
    addXVR_Reg0x3f = 0x00000000;
    addXVR_Reg0x40 = 0x01000000;
    addXVR_Reg0x41 = 0x07050402;
    addXVR_Reg0x42 = 0x120F0C0A;
    addXVR_Reg0x43 = 0x221E1A16;
    addXVR_Reg0x44 = 0x35302B26;
    addXVR_Reg0x45 = 0x4B45403A;
    addXVR_Reg0x46 = 0x635D5751;
    addXVR_Reg0x47 = 0x7C767069;
    addXVR_Reg0x48 = 0x968F8983;
    addXVR_Reg0x49 = 0xAEA8A29C;
    addXVR_Reg0x4a = 0xC5BFBAB4;
    addXVR_Reg0x4b = 0xD9D4CFCA;
    addXVR_Reg0x4c = 0xE9E5E1DD;
    addXVR_Reg0x4d = 0xF5F3F0ED;
    addXVR_Reg0x4e = 0xFDFBFAF8;
    addXVR_Reg0x4f = 0xFFFFFFFE;


}


///freq:0~80,power_level:0~16
void single_wave_config(uint8_t freq, uint8_t power_level)
{
    uint32_t val = 0;
    uint32_t reg = XVR_ANALOG_REG_BAK[0x04];

    addXVR_Reg0x24 &= ~(0x1 << 20);
    addXVR_Reg0x4 = reg | (0x1 << 29);

    val |= freq;
    val |= (power_level<< 7);
    addXVR_Reg0x24 = val;
    addXVR_Reg0x25 |= (0x1<<12) |(0x1<<13);

    while(1);
}

void kmod_fm_gain_set_1M(void)
{
    //addXVR_Reg0x30 &= ~(0x1ff<<8);
    //addXVR_Reg0x30 |= (value_kcal_result_1M<<8);
    addXVR_Reg0x30 = value_kcal_result_1M;

}
void kmod_fm_gain_set_2M(void)
{
    //addXVR_Reg0x30 &= ~(0x1ff<<8);
    //addXVR_Reg0x30 |= (value_kcal_result_2M<<8);
    addXVR_Reg0x30 = value_kcal_result_2M;
}


#if defined(CFG_BT)
/**
 *****************************************************************************************
 * @brief Decrease the TX power by one step
 *
 * @param[in] link_id Link ID for which the TX power has to be decreased
 *
 * @return true when minimum power is reached, false otherwise
 *****************************************************************************************
 */
static bool rf_txpwr_dec(uint8_t link_id)
{
    bool boMinpow = true;
    uint8_t tx_pwr = em_bt_pwrcntl_txpwr_getf(EM_BT_CS_ACL_INDEX(link_id)) & RPL_POWER_MSK;

    if (tx_pwr > RPL_POWER_MIN)
    {
        //Increase the TX power value
        em_bt_pwrcntl_txpwr_setf(EM_BT_CS_ACL_INDEX(link_id), tx_pwr-1);
        boMinpow = false;
    }

    return(boMinpow);
}

/**
 *****************************************************************************************
 * @brief Increase the TX power by one step
 *
 * @param[in] link_id Link ID for which the TX power has to be increased
 *
 * @return true when maximum power is reached, false otherwise
 *****************************************************************************************
 */
static bool rf_txpwr_inc(uint8_t link_id)
{
    bool boMaxpow = true;
    uint8_t tx_pwr = em_bt_pwrcntl_txpwr_getf(EM_BT_CS_ACL_INDEX(link_id)) & RPL_POWER_MSK;

    if (tx_pwr < RPL_POWER_MAX)
    {
        //Increase the TX power value
        em_bt_pwrcntl_txpwr_setf(EM_BT_CS_ACL_INDEX(link_id), tx_pwr+1);
        boMaxpow = false;
    }

    return(boMaxpow);
}

/**
 ****************************************************************************************
 * @brief Set the TX power to max
 *
 * @param[in] link_id     Link Identifier
 ****************************************************************************************
 */
static void txpwr_max_set(uint8_t link_id)
{
    //Increase the TX power value
    em_bt_pwrcntl_txpwr_setf(EM_BT_CS_ACL_INDEX(link_id), RPL_POWER_MAX);
}
#endif // CFG_BT



void rf_init(struct rwip_rf_api *api)
{
    ////IP
      #if defined(CFG_BT)
        uint8_t length = PARAM_LEN_RSSI_THR;
    #endif //CFG_BT
        // Initialize the RF driver API structure
        api->reg_rd = rf_rpl_reg_rd;
        api->reg_wr = rf_rpl_reg_wr;
        api->txpwr_dbm_get = rf_txpwr_dbm_get;
        api->txpwr_min = RPL_POWER_MIN;
        api->txpwr_max = RPL_POWER_MAX;
        api->sleep = rf_sleep;
        api->reset = rf_reset;

    #if defined(CFG_BLE)
            api->force_agc_enable = rf_force_agc_enable;
    #endif //CFG_BLE

         api->rssi_convert = rf_rssi_convert;
        api->txpwr_cs_get = rf_txpwr_cs_get;

    #if defined(CFG_BT)
        api->txpwr_dec = rf_txpwr_dec;
        api->txpwr_inc = rf_txpwr_inc;
        api->txpwr_max_set = txpwr_max_set;
        // Initialize the RSSI thresholds (high, low, interference)
        // These are 'real' signed values in dBm
        if (   (rwip_param.get(PARAM_ID_RSSI_HIGH_THR, &length, (uint8_t*)&api->rssi_high_thr) != PARAM_OK)
            || (rwip_param.get(PARAM_ID_RSSI_LOW_THR, &length, (uint8_t*)&api->rssi_low_thr) != PARAM_OK)
            || (rwip_param.get(PARAM_ID_RSSI_INTERF_THR, &length, (uint8_t*)&api->rssi_interf_thr) != PARAM_OK) )
        {
            api->rssi_high_thr = (int8_t)RPL_RSSI_20dB_THRHLD;
            api->rssi_low_thr = (int8_t)RPL_RSSI_60dB_THRHLD;
            api->rssi_interf_thr = (int8_t)RPL_RSSI_70dB_THRHLD;
        }
    #endif //CFG_BT
#if 1

        /* ip RADIOCNTL1 */
      clrf_SYS_Reg0x3_rwbt_pwd;
//      ip_radiocntl1_set(0x00000020);
      //uart_printf("ip RADIOCNTL1 addr:0x%08x,val:0x%08x\r\n",IP_RADIOCNTL1_ADDR,ip_radiocntl1_get());
//      ip_timgencntl_set(0x01df0120);        
      //uart_printf("ip_TIMGENCNTL addr:0x%08x,val:0x%08x\r\n",IP_TIMGENCNTL_ADDR,ip_timgencntl_get());



   
    #if defined(CFG_BLE)
    
        //uart_printf("RW BLE reg init\r\n");
        /* BLE RADIOCNTL2 */       
      ble_radiocntl2_set(0x00C000C0);
      //uart_printf("BLE_RADIOCNTL2 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOCNTL2_ADDR,ble_radiocntl2_get());

        /* BLE RADIOCNTL3 */
  #if 0
  ble_radiocntl3_pack(/*uint8_t rxrate3cfg*/      0x1, // map on 1 Mbps
            /*uint8_t rxrate2cfg*/      0x1, // map on 1 Mbps
            /*uint8_t rxrate1cfg*/      0x0,
            /*uint8_t rxrate0cfg*/      0x1,
            /*uint8_t rxsyncrouting*/ 0x0,
            /*uint8_t rxvalidbeh*/      0x0,
            /*uint8_t txrate3cfg*/      0x1, // map on 1 Mbps
            /*uint8_t txrate2cfg*/      0x1, // map on 1 Mbps
            /*uint8_t txrate1cfg*/      0x0,
            /*uint8_t txrate0cfg*/      0x1,
            /*uint8_t txvalidbeh*/      0x0);
      ble_radiocntl3_set(ble_radiocntl2_get());                    
      printf("BLE_RADIOCNTL3 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOCNTL2_ADDR,ble_radiocntl2_get());
      #endif

        /* BLE RADIOPWRUPDN0 */
        ble_radiopwrupdn0_pack(/*uint8_t syncposition0*/ 0,
                               /*uint8_t rxpwrup0*/      0x50,
                               /*uint8_t txpwrdn0*/      0x07,
                               /*uint8_t txpwrup0*/      0x55);
        ble_radiopwrupdn0_set(0x00650065);
        //uart_printf("BLE_RADIOPWRUPDN0 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOPWRUPDN0_ADDR,ble_radiopwrupdn0_get());
        
        /* BLE RADIOPWRUPDN1 */
        ble_radiopwrupdn1_pack(/*uint8_t syncposition1*/ 0,
                               /*uint8_t rxpwrup1*/      0x70,
                               /*uint8_t txpwrdn0*/      0x00,
                               /*uint8_t txpwrup1*/      0x65);
        ble_radiopwrupdn1_set(0x00700065);
        //uart_printf("BLE_RADIOPWRUPDN1 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOPWRUPDN1_ADDR,ble_radiopwrupdn1_get());
        
        /* BLE RADIOPWRUPDN2 */      
        ble_radiopwrupdn2_pack(/*uint8_t syncposition2*/ 0,
                               /*uint8_t rxpwrup2*/      0x50, // 50
                               /*uint8_t txpwrdn2*/      0x07,
                               /*uint8_t txpwrup2*/      0x55);
        ble_radiopwrupdn2_set(0x00650065);
        //uart_printf("BLE_RADIOPWRUPDN2 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOPWRUPDN2_ADDR,ble_radiopwrupdn2_get());
        
        
        /* BLE RADIOPWRUPDN3 */
        ble_radiopwrupdn3_pack(/*uint8_t txpwrdn3*/      0x07,
                               /*uint8_t txpwrup3*/      0x55);
        ble_radiopwrupdn3_set(0x00000065);
        //uart_printf("BLE_RADIOPWRUPDN3 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOPWRUPDN3_ADDR,ble_radiopwrupdn3_get());
#if 1        
        /* BLE RADIOTXRXTIM0 */
        ble_radiotxrxtim0_pack(/*uint8_t rfrxtmda0*/   0xa,
                               /*uint8_t rxpathdly0*/  0x8,
                               /*uint8_t txpathdly0*/  0x3);
        ble_radiotxrxtim0_set(0x00100707);  //0x00001007 0x00000503
        //uart_printf("BLE_RADIOTXRXTIM0 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOTXRXTIM0_ADDR,ble_radiotxrxtim0_get());

        
        /* BLE RADIOTXRXTIM1 */
        ble_radiotxrxtim1_pack(/*uint8_t rfrxtmda1*/ 0x00,
                               /*uint8_t rxpathdly1*/       0x04,
                               /*uint8_t txpathdly1*/       0x04);
        ble_radiotxrxtim1_set(0x00100404);
        //uart_printf("BLE_RADIOTXRXTIM1 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOTXRXTIM1_ADDR,ble_radiotxrxtim1_get());


        /* BLE RADIOTXRXTIM2 */
        //uart_printf("# 09\r\n");
        ble_radiotxrxtim2_pack(/*uint8_t rxflushpathdly2*/ 0x10,
                               /*uint8_t rfrxtmda2*/       0x00,
                               /*uint8_t rxpathdly2*/       0x49,
                               /*uint8_t txpathdly2*/       0x03);
        ble_radiotxrxtim2_set(0x00202020);
        //uart_printf("BLE_RADIOTXRXTIM2 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOTXRXTIM2_ADDR,ble_radiotxrxtim2_get());
#endif
        /* BLE RADIOTXRXTIM3 */
        ble_radiotxrxtim3_pack(/*uint8_t rxflushpathdly3*/ 0x10,
                               /*uint8_t rfrxtmda3*/       0x00,
                               /*uint8_t txpathdly3*/       0x03);
        ble_radiotxrxtim3_set(0x00200020);                       
        //uart_printf("BLE_RADIOTXRXTIM3 addr:0x%08x,val:0x%08x\r\n",BLE_RADIOTXRXTIM3_ADDR,ble_radiotxrxtim3_get());
        
      #if (BLE_CON_CTE_REQ | BLE_CONLESS_CTE_RX)
        // Init the DF CNTL
        ble_dfcntl0_1us_pack(/*uint8_t rxsampstinst01us*/ 0x08, /*uint8_t rxswstinst01us*/ 0x18, /*uint8_t txswstinst01us*/ 0x19);
        ble_dfcntl0_2us_pack(/*uint8_t rxsampstinst02us*/ 0x08, /*uint8_t rxswstinst02us*/ 0x18, /*uint8_t txswstinst02us*/ 0x19);
        ble_dfcntl1_1us_pack(/*uint8_t rxsampstinst11us*/ 0x08, /*uint8_t rxswstinst11us*/ 0x18, /*uint8_t txswstinst11us*/ 0x19);
        ble_dfcntl1_2us_pack(/*uint8_t rxsampstinst12us*/ 0x08, /*uint8_t rxswstinst12us*/ 0x18, /*uint8_t txswstinst12us*/ 0x19);
        ble_dfantcntl_pack(/*uint8_t rxprimidcntlen*/ 1, /*uint8_t rxprimantid*/ 0, /*uint8_t txprimidcntlen*/ 1, /*uint8_t txprimantid*/ 0);
      #endif // (BLE_CON_CTE_REQ | BLE_CONLESS_CTE_RX)
    #endif // defined CFG_BLE

    #if defined(CFG_BT)
    
        /* EDRCNTL */
      #if 1        ////BEKEN
        bt_rwbtcntl_set(0x0000010A);
      #else
        bt_rwbtcntl_nwinsize_setf(0);
      #endif
        bt_edrcntl_rxgrd_timeout_setf(RPL_EDRCNTL);

        /* BT RADIOPWRUPDN */
        #if 1        //// BEKEN
        bt_radiopwrupdn_set(0x00710271);
    //bt_radiopwrupdn_set(0x00650065);
        #else
        bt_radiopwrupdn_rxpwrupct_setf(0x42);
        bt_radiopwrupdn_txpwrdnct_setf(0x07);
        bt_radiopwrupdn_txpwrupct_setf(0x56);
        #endif
        /* BT RADIOCNTL 2 */
        #if 1        ////BEKEN
        //uart_printf("# 14\r\n");
        bt_radiocntl2_set(0x04070100);
        #else
        bt_radiocntl2_freqtable_ptr_setf((EM_FT_OFFSET >> 2));
        bt_radiocntl2_syncerr_setf(0x7);
        #endif
        /* BT RADIOTXRXTIM */
        #define PRL_TX_PATH_DLY 4
        #define PRL_RX_PATH_DLY (RPL_RADIO_SKEW - PRL_TX_PATH_DLY)
        #if 1        ////BEKEN
        //uart_printf("# 15\r\n");
            bt_radiotxrxtim_set(0x00000403);
      //bt_radiotxrxtim_set(0x00000707);
        #else
            bt_radiotxrxtim_rxpathdly_setf(PRL_RX_PATH_DLY);
            bt_radiotxrxtim_txpathdly_setf(PRL_TX_PATH_DLY);
            bt_radiotxrxtim_sync_position_setf(0x38); // Default is 0x10
        #endif
        /* BT RADIOCNTL 3*/
        #if 1        ////BEKEN
        //uart_printf("# 16\r\n");
        bt_radiocntl3_set(0x39003900);
        #else
        bt_radiocntl3_pack( /*uint8_t rxrate2cfg*/      3,
                            /*uint8_t rxrate1cfg*/      2,
                            /*uint8_t rxrate0cfg*/      1,
                            /*uint8_t rxserparif*/      0,
                            /*uint8_t rxsyncrouting*/ 0,
                            /*uint8_t rxvalidbeh*/      0,
                            /*uint8_t txrate2cfg*/      3,
                            /*uint8_t txrate1cfg*/      2,
                            /*uint8_t txrate0cfg*/      1,
                            /*uint8_t txserparif*/      0,
                            /*uint8_t txvalidbeh*/      0);
        #endif
    #endif //CFG_BT


        // Settings for proper reception
    #if defined(CFG_BLE)
//        ip_radiocntl1_forceiq_setf(1);
//        ip_radiocntl1_dpcorr_en_setf(0x0);
//        ASSERT_ERR(ip_radiocntl1_dpcorr_en_getf() == 0x0);
    #endif // CFG_BLE

    #if defined(CFG_BT)
        ip_radiocntl1_dpcorr_en_setf(0x1);
        ASSERT_ERR(ip_radiocntl1_dpcorr_en_getf() == 0x1);
    #endif // CFG_BT

    #if defined(CFG_BLE)
    // Force IQ mode for BLE only
    //ip_radiocntl1_forceiq_setf(1);
    #endif //CFG_BLE
#endif 
//		set_power(0xf);
    set_power(0x4);
}



#if 0
void Test_XVR_PN9_Rx_Ena(uint8_t channel)
{
    uint32_t wdata_temp;

//    p_APB_XVER_ADDR[0x20] = 0x0295E5DC ;
    
    wdata_temp = (0xF<<7) + channel ;    // Disable auto-chnn/syncwin/syncwrd, Default TxPower=0xF
    addXVR_Reg0x24 = wdata_temp; 
//    p_APB_XVER_ADDR[0x3B]  = 0x00003050; // Sync-word should be reversed-order for PN9 Rx

    // XVR-Reg0x25: [10]-pn9_recv_en, [11]-pn9_send_en, [12]-test_tmode, [13]-test_radio
 //   p_APB_XVER_ADDR[0x25]  = 0x0 ;
//    Delay_ms(1);
    addXVR_Reg0x25  = (0x1<<13) ;
//    Delay(300);
        Delay_ms(1);
    addXVR_Reg0x25  = 0x0 ;
 //   Delay(100);
        Delay_ms(1);
    addXVR_Reg0x25  = (0x1<<13) + (0x1<<10);
    
    Delay_ms(100);
    addXVR_Reg0x25 |= (1<<9);
    {
            volatile unsigned long ulTemp;
      ulTemp = addXVR_Reg0x15;
            addUART0_Reg0x3 = (ulTemp >> 24) & 0x00FF;
            addUART0_Reg0x3 = (ulTemp >> 16) & 0x00FF;
            addUART0_Reg0x3 = (ulTemp >> 8)  & 0x00FF;
            addUART0_Reg0x3 = (ulTemp        )  & 0x00FF;
            ulTemp = addXVR_Reg0x16;
            addUART0_Reg0x3 = (ulTemp >> 24) & 0x00FF;
            addUART0_Reg0x3 = (ulTemp >> 16) & 0x00FF;
            addUART0_Reg0x3 = (ulTemp >> 8)  & 0x00FF;
            addUART0_Reg0x3 = (ulTemp        )  & 0x00FF;
        }
}

void Test_XVR_Single_Carrier_Tx_Ena(uint8_t channel, uint8_t tx_power)
{
    uint32_t wdata_temp;
    // Disable auto-chnn, auto-syncwin, auto-syncwrd
    wdata_temp = (tx_power<<7) + channel ;
    addXVR_Reg0x24  = wdata_temp ; 
    addXVR_Reg0x26 &=~(0x1<<11);  // Clear to configure the close-loop Tx for Sinc-Wave
    // XVR-Reg0x25: [10]-pn9_recv_en, [11]-pn9_send_en, [12]-test_tmode, [13]-test_radio
    addXVR_Reg0x25  = (0x1<<13) ;
    Delay(300);
    addXVR_Reg0x25  = 0x0 ;
    Delay(100);
    addXVR_Reg0x25  = (0x1<<13) + (0x1<<12) ;
}

void Test_XVR_Single_Carrier_Tx_Ena1(uint8_t channel, uint8_t tx_power)
{
    uint32_t wdata_temp;

    // Disable auto-chnn, auto-syncwin, auto-syncwrd
    wdata_temp = (tx_power<<7) + channel ;
    addXVR_Reg0x24  = wdata_temp ; 

//    p_APB_XVER_ADDR[0x26] &=~(0x1<<11);  // Clear to configure the close-loop Tx for Sinc-Wave

    // XVR-Reg0x25: [10]-pn9_recv_en, [11]-pn9_send_en, [12]-test_tmode, [13]-test_radio
 /*   p_APB_XVER_ADDR[0x25]  = (0x1<<13) ;
    Delay(300);
    p_APB_XVER_ADDR[0x25]  = 0x0 ;
    Delay(100);*/
    addXVR_Reg0x25  = (0x1<<12) ;
    Delay(300);
    addXVR_Reg0x25  = (0x1<<13) + (0x1<<12) ;
}

#endif
void rc32k_calib_soft(void)
{
    uint32_t reg = XVR_ANALOG_REG_BAK[0xb];
  //  reg |= (1<<13);
  //  addXVR_Reg0xb  = reg;    XVR_ANALOG_REG_BAK[0xb] = reg;
  //  Delay_ms(50);
  
    reg &= ~(0x07<<13);
    addXVR_Reg0xb  = reg;    XVR_ANALOG_REG_BAK[0xb] = reg;
 //   Delay_ms(50);
    reg |= (1<<15);
    addXVR_Reg0xb  = reg;    XVR_ANALOG_REG_BAK[0xb] = reg;

}

//Software auto-calibration, for example, 1s calibration once, there will be 7ms error in 300ms, and the error exists a calibration interval.
void rc32k_calib_manu(uint16_t c_data, uint16_t f_data)
{
    uint32_t reg = XVR_ANALOG_REG_BAK[0xb];
    uint32_t reg1 = XVR_ANALOG_REG_BAK[0xa];
    reg &=~(1<<15);
    addXVR_Reg0xb = reg; XVR_ANALOG_REG_BAK[0xb] = reg;
    reg1 &= ~(0x07<<3);
    reg1 &= ~0X01;
    reg1 |=(( f_data>>4) &0x07) <<3;
    addXVR_Reg0xa  = reg1; XVR_ANALOG_REG_BAK[0xa] = reg1;
    
    reg &= ~0x1fff;
    reg |=( c_data <<4) + (f_data & 0x0f);

    reg |= (1<<13);
    addXVR_Reg0xb = reg; XVR_ANALOG_REG_BAK[0xb] = reg;
    reg |=(1<<15);
    addXVR_Reg0xb = reg; XVR_ANALOG_REG_BAK[0xb] = reg;

    addXVR_Reg0xa = reg1|0X01; XVR_ANALOG_REG_BAK[0xa] = reg1|0X01;
}
  
void xtal_tempe_compensation(void)
{
    if(adc_code_to_adj(get_temperature_sensor_data(), &temp_map))
    {
        xvr_ldo_auto_cali();
        xvr_set_voltage(temp_map.volt);
        xtal_set_cal(temp_map.crystal);
        filter_triger();
    }    
    
}
 
void IF_filter_cali(void)
{
    uint32_t tmp_reg;

    // turn to PN9 RX
    addXVR_Reg0x25 = 0x00002400;

    filter_triger();
    // read XVR0x10[20,16]    
    tmp_reg = (addXVR_Reg0x10>>16)&0x1f;
    // data + 11
    tmp_reg += 11;
    // xvr0x05.25=1

    XVR_ANALOG_REG_BAK[0x5] |= 1<<25;
    addXVR_Reg0x5 = XVR_ANALOG_REG_BAK[0x5];

    XVR_ANALOG_REG_BAK[0x5] &= ~(0x1ff<<16);
    XVR_ANALOG_REG_BAK[0x5] |= tmp_reg<<16;

    addXVR_Reg0x5 = XVR_ANALOG_REG_BAK[0x5];
    // XVR0x5.[24,16] =     data;

    addXVR_Reg0x25 = 0x00000000;

    uart_printf("read xvr_reg0x04:0x%x\r\n",XVR_ANALOG_REG_BAK[0x4]);
    uart_printf("read xvr_reg0x06:0x%x\r\n",XVR_ANALOG_REG_BAK[0x6]);
    uart_printf("read xvr_reg0x3c:0x%x\r\n",addXVR_Reg0x3c);
    uart_printf("read xvr_reg0x38:0x%x\r\n",addXVR_Reg0x38);
    uart_printf("read xvr_reg0x05:0x%x\r\n",XVR_ANALOG_REG_BAK[0x5]);

}


#endif
