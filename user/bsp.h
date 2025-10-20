#ifndef _BSP_H_

#define _BSP_H_


#define USE_GREEN_AS_DEBUG_PIN	0
#define TEST_ANMO_PLUS	0
#define VOLTAGE_OVER_QUICK_DOWN	0

//io pinmap
#ifdef USE_PWM_DIFF
#ifdef USE_GPIO_PWM
#define boLedGreen	0x07
#define LED_GREEN_PWM	PWM_CHANNEL2
#define boLedOrange 	0x06
#define LED_ORANGE_PWM	PWM_CHANNEL1
#define boVBulk		0x05
#define VOLTAGE_BULK_PWM	PWM_CHANNEL0

#define boPWM3	0x14
#else
#define boLedGreen	0x14

#define boLedOrange 	0x06
#define LED_ORANGE_PWM	PWM_CHANNEL1

#ifdef USE_ADC0
#define boVBulk		0x05
#define VOLTAGE_BULK_PWM	PWM_CHANNEL0
#else
#define boVBulk		0x06
#define VOLTAGE_BULK_PWM	PWM_CHANNEL1
#endif
#endif
#else

#ifdef USE_GPIO_PWM
#define boPWM3	0x01
#endif

#define boLedGreen	0x07
#define LED_GREEN_PWM	PWM_CHANNEL2
#define boLedOrange 	0x06
#define LED_ORANGE_PWM	PWM_CHANNEL1
#define boVBulk		0x11
#define VOLTAGE_BULK_PWM	PWM_CHANNEL4
#endif
#define boBulkAdcGnd 0x15
#define boBatAdcGnd	0x13

#define biChargeDet	0x21

#define biKey	0x23



#define PLUS_OUTPUT1_PWM	PWM_CHANNEL3
#define PLUS_OUTPUT2_PWM	PWM_CHANNEL5

enum
{
	CMD_CHILD_STATUS_REPORT=0,
	
	CMD_CHILD_RET=0x20,
	CMD_SET_WORK_LEVEL,
	CMD_SET_WORK,
	CMD_GET_CHILD_STATUS,
	CMD_GET_CHILD_VOLTAGE
};


enum
{
	TARGET_STATUS_LEAVE,
	TARGET_STATUS_POOR,
	TARGET_STATUS_NORMAL
};

#define BULK_VOLTAGE_MIN		1000/101			//20V
#define BULK_VOLTAGE_MAX		90000/101			//90V
#define BULK_VOLTAGE_NO_TARGET	20000/101

void init_bsp(void);
void adc_proc(void);
void  main_loop(void);
void send_data_proc(unsigned char cmd);
#endif
