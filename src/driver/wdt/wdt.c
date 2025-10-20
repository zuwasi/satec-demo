#include <stdint.h>        // standard integer definition
#include <string.h>        // string manipulation
#include <stddef.h>        // standard definition
#include "BK3437_RegList.h"
#include "wdt.h"
void wdt_disable(void)
{
    addAON_WDT_Reg0x2 = 0;
    addAON_WDT_Reg0x1=WDKEY_ENABLE1;
    addAON_WDT_Reg0x1=WDKEY_ENABLE2;
}
/**
 * @brief wdt reset,clk: rc32k,
 * @param[in] wdt_cnt,1 = 1/32000S,Ex:wdt_cnt = ffff,wdt period = 65535/32000 = 2S;
*/
void wdt_enable(uint32_t wdt_cnt)
{
    addAON_WDT_Reg0x0=0x01;
    addAON_WDT_Reg0x1=0x00;
    
    addAON_WDT_Reg0x2  = wdt_cnt;
    addAON_WDT_Reg0x1=WDKEY_ENABLE1;
    addAON_WDT_Reg0x1=WDKEY_ENABLE2;
    clrf_PMU_Reg0x1_wdt_reset_ctrl;
}
void wdt_feed(void)
{
    addAON_WDT_Reg0x1=WDKEY_ENABLE1;
    addAON_WDT_Reg0x1=WDKEY_ENABLE2;
}

#define posWDT_Reg0x0_WDKEY                                     16
#define bitWDT_Reg0x0_WDKEY                                     0xFF0000
#define set_WDT_Reg0x0_WDKEY(val)                               addWDT_Reg0x0 = ((addWDT_Reg0x0 & (~0xFF0000)) | ((val) << 16))
#define get_WDT_Reg0x0_WDKEY                                    ((addWDT_Reg0x0 & 0xFF0000) >> 16)

#define posWDT_Reg0x0_WD_PERIOD                                 0
#define bitWDT_Reg0x0_WD_PERIOD                                 0xFFFF
#define set_WDT_Reg0x0_WD_PERIOD(val)                           addWDT_Reg0x0 = ((addWDT_Reg0x0 & (~0xFFFF)) | ((val) << 0))
#define get_WDT_Reg0x0_WD_PERIOD                                (addWDT_Reg0x0 & 0xFFFF)

void wdt1_disable(void)
{
  //  WDT_REG0X0=WDKEY_ENABLE1 << 16;
  //  WDT_REG0X0=WDKEY_ENABLE2 << 16;
  //  setf_SYS_Reg0x3_wdt_pwd;

    set_WDT_Reg0x0_WD_PERIOD(0) ;
    set_WDT_Reg0x0_WDKEY(0x5a);
    set_WDT_Reg0x0_WDKEY(0xa5);

}
//ÿ����λ250us�����0xffff��Լ25s
void wdt1_enable(uint32_t wdt_cnt)
{

    clrf_SYS_Reg0x3_wdt_pwd;
    set_WDT_Reg0x0_WD_PERIOD(wdt_cnt) ;
    set_WDT_Reg0x0_WDKEY(0x5a);
    set_WDT_Reg0x0_WDKEY(0xa5);


}
void wdt1_feed(void)
{
    set_WDT_Reg0x0_WDKEY(0x5a);
    set_WDT_Reg0x0_WDKEY(0xa5);

}
