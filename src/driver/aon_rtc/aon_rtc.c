#include <stdint.h>        // standard integer definition
#include <string.h>        // string manipulation
#include <stddef.h>        // standard definition
#include "aon_rtc.h"
#include "user_config.h"
#include "BK3437_RegList.h"



#if(AON_RTC_DRIVER)

void aon_rtc_init(void)
{
    setf_rtc_aon_Reg0x0_rtc_clk_en ;  //enable rtc clk
#ifdef __HID_TSET__
    addrtc_aon_Reg0x1 = AON_RTC_8MS;//AON_RTC_1000MS;//AON_RTC_UP_VALUE;// set up_val
    addrtc_aon_Reg0x2 = AON_RTC_8MS;//AON_RTC_1000MS;//set  tick_val
#else
    addrtc_aon_Reg0x1 = AON_RTC_1000MS;//AON_RTC_UP_VALUE;// set up_val
    addrtc_aon_Reg0x2 = AON_RTC_1000MS;//set  tick_val
    
#endif
    setf_rtc_aon_Reg0x0_rtc_aon_int; // clear aon int
    setf_rtc_aon_Reg0x0_rtc_tick_int; //clear tick int
    setf_rtc_aon_Reg0x0_rtc_tick_int_en; //rtc tick_int_enable
    setf_rtc_aon_Reg0x0_rtc_aon_int_en;// rtc aon_int_enable
    setf_SYS_Reg0x10_int_aon_rtc_en; // rtc int enable
}

 

void aon_rtc_isr(void)
{   
    static unsigned int rtc_cnt=0;
    
    setf_rtc_aon_Reg0x0_rtc_tick_int ;
    rtc_cnt++;
    uart_printf("rtc_cnt=%d\n",rtc_cnt);
    
    //uart_printf("rtc_cnt=%d\n",ip_slotclk_sclk_getf());
    //ip_slotclk_sclk_setf(0x10000);   
    //uart_printf("rtc_cnt=%d\n",ip_slotclk_sclk_getf());
}

char get_aon_rtc_cnt(void)
{

    if(AON_RTC_1000MS-addrtc_aon_Reg0x3<AON_RTC_CNT)
    {
        uart_printf("addrtc_aon_Reg0x3=%d\n",addrtc_aon_Reg0x3);
        return 0;
    }
    else
    {    
        return 1;
    }
}

#endif



