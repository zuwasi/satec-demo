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


#ifndef __RTC_H__
#define __RTC_H__


#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

//----------------------------------------------
// RTC driver description
//----------------------------------------------
typedef struct
{
    unsigned char       second;     // second, 0~59
    unsigned char       minute;     // minute, 0~59
    unsigned char       hour;       // hour,   0~23
    unsigned char       week_day;   // week_day, 0~6
} RTC_DATE_DESC;

typedef enum
{
    RTC_CLK_SEL_32K = 0,
}rtc_clk_sel_t;

#define RTC_CLK_32K_EN          0
#define RTC_CLK_16M_EN          1

#define RTC_CLK_SEL             RTC_CLK_32K_EN

#define RTC_DIV                 0
#define RTC_MSUNIT              32-1
#define RTC_SUNIT               32000-1

extern RTC_DATE_DESC rtc_org ;
extern RTC_DATE_DESC rtc_alarm ;
extern uint16_t millsecond ;

void rtc_init(RTC_DATE_DESC *p_RTC_date_desc);
void rtc_enable(void);
void rtc_disable(void);
void rtc_alarm_init(unsigned char ucMode, RTC_DATE_DESC *p_RTC_alarm_time, 
                           unsigned long ulMiiliSecond, void (*p_Int_Handler)(void));
void rtc_alarm_enable(void);
void rtc_alarm_disable(void);
void rtc_set_time(RTC_DATE_DESC *p_RTC_date_desc);
void rtc_get_time(RTC_DATE_DESC *p_RTC_date_desc);
void rtc_int_handler_clear(void);

void rtc_isr(void);
void rtc_test(uint8_t mode);


#ifdef __cplusplus
}
#endif  /* __cplusplus */


#endif      /* __RTC_H__ */

