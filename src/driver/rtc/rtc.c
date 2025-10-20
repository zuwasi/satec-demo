/**
****************************************************************************************
* @addtogroup RTC
* @ingroup beken corp
* @brief RTC
* @author Alen
*
* This is the driver block for RTC
* @{
****************************************************************************************
*/


#include <stdint.h>        // standard integer definition
#include <string.h>        // string manipulation
#include <stddef.h>        // standard definition
#include "BK3437_RegList.h"
#include "rtc.h"
#include "driver_gpio.h"
#include "user_config.h"

#if (RTC_DRIVER)
static void (*p_RTC_Int_Handler)(void) = NULL;

void rtc_init(RTC_DATE_DESC *p_RTC_date_desc)
{
    if (p_RTC_date_desc == NULL)
    {
        return;
    }

    clrf_SYS_Reg0x3_rtc_pwd ;   //open periph
    set_SYS_Reg0x4_rtc_sel(RTC_CLK_SEL);
    set_SYS_Reg0x11_int_rtc_pri(0); //irq

    //rtc enable    
    addRTC_Reg0x0  = (1 << posRTC_Reg0x0_RTC_ENABLE)
                            | (0 << posRTC_Reg0x0_RTC_CLEAR)
                            | (0 << posRTC_Reg0x0_RTC_ALARM_EN)
                            | (0 << posRTC_Reg0x0_RTC_ALARM_MODE);

    addRTC_Reg0x1 = (RTC_DIV << posRTC_Reg0x1_RTC_DIV)
                            | (RTC_MSUNIT   << posRTC_Reg0x1_RTC_MSUNIT)
                            | (RTC_SUNIT    << posRTC_Reg0x1_RTC_SUNIT);

    addRTC_Reg0x2  = ((p_RTC_date_desc->second   & 0x3F) << posRTC_Reg0x2_RTC_S)
                            | ((p_RTC_date_desc->minute   & 0x3F) << posRTC_Reg0x2_RTC_M)
                            | ((p_RTC_date_desc->hour     & 0x1F) << posRTC_Reg0x2_RTC_H  )
                            | ((p_RTC_date_desc->week_day & 0x07) << posRTC_Reg0x2_RTC_W  );
    
    while (!get_RTC_Reg0x0_RTC_ENABLE);

    //setf_SYS_Reg0x10_int_rtc_en;
}


void rtc_enable(void)
{
    setf_RTC_Reg0x0_RTC_ENABLE;
}

void rtc_disable(void)
{
    clrf_RTC_Reg0x0_RTC_ENABLE;
}


void rtc_alarm_init(unsigned char ucMode, RTC_DATE_DESC *p_RTC_alarm_time, 
                    unsigned long ulMiiliSecond, void (*p_Int_Handler)(void))
{
    clrf_SYS_Reg0x3_rtc_pwd ;   //open periph

    if (ucMode == 0x00)         // clock alarm mode
    {
        if (p_RTC_alarm_time == NULL)
        {
            return;
        }
        
        addRTC_Reg0x3 = ((p_RTC_alarm_time->second   & 0x3F) << posRTC_Reg0x3_RTC_ALARM_S)
                          | ((p_RTC_alarm_time->minute   & 0x3F) << posRTC_Reg0x3_RTC_ALARM_M)
                          | ((p_RTC_alarm_time->hour     & 0x1F) << posRTC_Reg0x3_RTC_ALARM_H);
    }
    else if (ucMode == 0x01)    // millisecond alarm mode
    {
        addRTC_Reg0x3 = (ulMiiliSecond & 0x3FF) << posRTC_Reg0x3_RTC_ALARM_MS;
    }
    else
    {
        return;
    }

    p_RTC_Int_Handler = p_Int_Handler;

    addRTC_Reg0x0 = (addRTC_Reg0x0 & 0x03)
                     | (1 << posRTC_Reg0x0_RTC_ENABLE)
                     | (1 << posRTC_Reg0x0_RTC_ALARM_EN)
                     | ((ucMode & 0x01) << posRTC_Reg0x0_RTC_ALARM_MODE);

    addRTC_Reg0x1 = (RTC_DIV << posRTC_Reg0x1_RTC_DIV)
                            | (RTC_MSUNIT    << posRTC_Reg0x1_RTC_MSUNIT)
                            | (RTC_SUNIT << posRTC_Reg0x1_RTC_SUNIT);

    if (p_Int_Handler != NULL)
    {
        setf_SYS_Reg0x10_int_rtc_en;
    }
}

void rtc_alarm_enable(void)
{
    setf_RTC_Reg0x0_RTC_ALARM_EN;
}

void rtc_alarm_disable(void)
{
    clrf_RTC_Reg0x0_RTC_ALARM_EN;
}


void rtc_set_time(RTC_DATE_DESC *p_RTC_date_desc)
{
    if (p_RTC_date_desc == NULL)
    {
        return;
    }

    addRTC_Reg0x2  = ((p_RTC_date_desc->second   & 0x3F) << posRTC_Reg0x2_RTC_S)
                        | ((p_RTC_date_desc->minute   & 0x3F) << posRTC_Reg0x2_RTC_M)
                        | ((p_RTC_date_desc->hour     & 0x1F) << posRTC_Reg0x2_RTC_H  )
                        | ((p_RTC_date_desc->week_day & 0x07) << posRTC_Reg0x2_RTC_W  );
}

void rtc_get_time(RTC_DATE_DESC *p_RTC_date_desc)
{
    if (p_RTC_date_desc == NULL)
    {
        return;
    }

    p_RTC_date_desc->second   = get_RTC_Reg0x2_RTC_S;
    p_RTC_date_desc->minute   = get_RTC_Reg0x2_RTC_M;
    p_RTC_date_desc->hour     = get_RTC_Reg0x2_RTC_H;
    p_RTC_date_desc->week_day = get_RTC_Reg0x2_RTC_W;
}

void rtc_int_handler_clear(void)
{
    p_RTC_Int_Handler = NULL;
}


void rtc_isr(void)
{
    if (get_RTC_Reg0x4_RTC_ALARM_FLAG)
    {
        if (p_RTC_Int_Handler != NULL)
        {
            (void)p_RTC_Int_Handler();
        }
    }

    setf_RTC_Reg0x4_RTC_ALARM_FLAG;
}

void rtc_alarm_test_handler()
{
    RTC_DATE_DESC rtc_t = {0};
    gpio_set_neg(0x14);
    uart_printf("%s\r\n", __func__);
}

RTC_DATE_DESC rtc_org =
    {
        .second = 55,
        .minute = 15,
        .hour = 15,
        .week_day = 2
    };
RTC_DATE_DESC rtc_alarm =
    {
        .second = 59,
        .minute = 15,
        .hour = 15,
        .week_day = 2
    };
uint16_t millsecond = 1;
void rtc_test(uint8_t mode)
{
    uart_printf("==============RTC_TEST ==============\r\n");
    uart_printf("==============P0x14 will neg,and the uart1  may print  rtc_alarm_test_handler ==============\r\n");
    uart_printf("==============mode = %d (1=millsecond ,0 =clock) ==============\r\n",mode);
    uart_printf("==============millsecond = %d ==============\r\n",millsecond);
    uart_printf("==============org:week=%d,hour=%d,min=%d,sec=%d ==============\r\n",
        rtc_org.week_day,rtc_org.hour,rtc_org.minute,rtc_org.second);
    uart_printf("==============alarm:week=%d,hour=%d,min=%d,sec=%d ==============\r\n",
        rtc_alarm.week_day,rtc_alarm.hour,rtc_alarm.minute,rtc_alarm.second);
    
    gpio_config(0x14, OUTPUT, PULL_HIGH);
    rtc_init(&rtc_org);
  //  rtc_alarm_init(1, &rtc_alarm_t, millsecond*1000000, rtc_alarm_test_handler);
    rtc_alarm_init(mode,& rtc_alarm, millsecond, rtc_alarm_test_handler);
    clear_uart1_buffer();

    while(1)
    {
        if(uart1_rx_done)
        {
            rtc_alarm_disable();
            return;
        }
    }
}

#endif

