#include "bsp.h"
#include "user_config.h"
#include "driver_gpio.h"
#include "adc.h"
#include "pwm.h"
#include "icu.h"
#include "rwip.h"
#include "app_fee0.h"
#include "app_task.h"
#include "app.h"
#include "wdt.h"
#define  BULK_DUTY_MAX  8

//void Delay_us(int num);
uint8_t bBulkDutyChanged;
uint8_t bLedChanged;
uint8_t bKeyDou,bKeyDown;
uint8_t bNeedWork;
uint8_t bWorking;
uint8_t bKeyLong;
uint8_t bCharging;
uint8_t bCurrentCaptrue;
uint8_t bFlashOn;
uint8_t bGetCurrent;
uint8_t bBreathUp;
uint8_t bChildReturn;
uint8_t bMasterReady=false;
uint8_t buzzerType=false;
uint8_t bGetChargeVoltage;
uint8_t bChargeFull;
uint8_t bBleWakeup;
uint8_t bLedGreenOn;
uint8_t bJustPowerOn;

uint8_t flashBatLedCount;
uint8_t currentOverCount;
uint8_t flashCount;
uint8_t targetStatus;
uint8_t poorContactCount;
uint8_t targetLeaveCount;
uint8_t targetNormalCount;
uint8_t ledFlashTime;
uint8_t workLevel;
uint16_t showBatLevelTime;
uint8_t orangeDuty;
uint8_t greenDuty;
uint8_t keyTime;
uint8_t adcIndex;
uint8_t timer10msCounter;
uint16_t bulkDutyStep;
uint8_t batLevel;
uint8_t resistanceChange;
uint8_t getChargeVoltageCount;
uint8_t noChargeTime;
#if VOLTAGE_OVER_QUICK_DOWN
uint8_t overVoltageDou;
#endif
uint16_t currentR;
uint8_t rIndex=6;
uint16_t currentVoltage;
uint16_t loseTargetTime;
uint16_t bulkVoltage;
uint16_t targetBulkVoltage;
uint16_t batVoltage;
uint16_t bulkDuty;
uint16_t bulkCycle;
uint16_t anmoTime;
uint16_t delaySleep;
uint8_t workLedShowTime;
extern uint16_t data_buff[];

extern uint8_t int_flg;

extern struct app_env_tag app_env;


void set_bulk_voltage(void)
{
	static uint8_t pwmStarted;
	if(bBulkDutyChanged)
	{
		bBulkDutyChanged = false;
		if(bulkDuty)	
		{
			if(pwmStarted) pwm_end_value_duty_cycle_set(0,VOLTAGE_BULK_PWM,bulkCycle,bulkDuty);
			else
			{
				start_pwm(PWM_MODE_PWM,0,1,VOLTAGE_BULK_PWM,bulkCycle,16-1,bulkDuty,0); 				
				pwmStarted = true;
			}
		}
		else
		{
			gpio_config(boVBulk,OUTPUT,PULL_NONE);
			gpio_set(boVBulk,0);
			pwmStarted = false;
		}
		//uart_printf("current bulk pwm duty:%d,cycle:%d\n",bulkDuty,bulkCycle);
	}
}

void smart_led_proc(void)
{
	if(!bWorking && !flashCount && (/*bCharging || */showBatLevelTime) && batLevel<=1 )
	{
		if(bCharging)
		{
			if(batLevel==1)
			{
			//	uart_printf("greenDuty:%d\n",greenDuty);		
				if(bBreathUp)
				{
					if(greenDuty>=100) bBreathUp = false;
					greenDuty++;		
				}
				else
				{
					if(greenDuty==0) bBreathUp = true;
					else greenDuty--;		
				}
				orangeDuty = 0;			
			}
			else
			{
			//	uart_printf("orangeDuty:%d\n",greenDuty);
				if(bBreathUp)
				{
					if(orangeDuty>=100) bBreathUp = false;
					orangeDuty++;		
				}
				else
				{
					if(orangeDuty==0) bBreathUp = true;
					else orangeDuty--;		
				}
				greenDuty = 0;
			}
			bLedChanged = true;
		}
		else if(!bCharging && batLevel == 0)
		{
			if(bBreathUp)
			{
				if(orangeDuty>=100) bBreathUp = false;
				orangeDuty += 2;		
			}
			else
			{
				if(orangeDuty==0) bBreathUp = true;
				else if(orangeDuty >= 2) orangeDuty -= 2;		
				else orangeDuty = 0;
			}
			greenDuty = 0;
			bLedChanged = true;
		}
		
	}
}

void led_proc(void)	//100ms
{
	if(bWorking)
	{
		if(workLedShowTime)
		{
			workLedShowTime--;
			if(workLedShowTime == 0)
			{
				bFlashOn = 0;
				bLedChanged = true;
			}
			else
			{
				ledFlashTime++;		
				if(targetStatus == TARGET_STATUS_NORMAL)	
				{	
#if 1			//200msoff 200msoff 200mson		2scycle
					if(batLevel>1)
					{
						greenDuty  = 100;
						orangeDuty = 0;
					}
					else
					{
						greenDuty  = 0;
						orangeDuty = 100;
					}
					if(ledFlashTime == 2)
					{
						bFlashOn = 0;						
						bLedChanged = true;
					}
					else if(ledFlashTime == 4)
					{
						bFlashOn = 1;						
						bLedChanged = true;
					}
					else if(ledFlashTime == 6)
					{
						bFlashOn =0;						
						bLedChanged = true;
					}
					else if(ledFlashTime == 20)
					{
						ledFlashTime = 0;
						bFlashOn = 1;						
						bLedChanged = true;
					}
#else				//��������ʱ������	
					if(ledFlashTime >= 10)
					{
						ledFlashTime = 0;
						bFlashOn = !bFlashOn;
						greenDuty  = 100;
						orangeDuty = 0;
						bLedChanged = true;
					}	
#endif					
				}
				else	//������ʱ��û�нӴ��û����뿪Ƥ����������˸
				{			
					if(ledFlashTime >= 20)
					{
						bFlashOn =  true;
						greenDuty = 100;
						orangeDuty = 0;
						ledFlashTime = 0;
						bLedChanged = true;
					}
					else if(ledFlashTime == 10)
					{
						bFlashOn =  true;
						orangeDuty = 100;
						greenDuty = 0;
						bLedChanged = true;
					}
				}
			}
		}
	}
	else if(flashBatLedCount)
	{
		ledFlashTime++;
		if(ledFlashTime == 1)
		{
			greenDuty = 100;
			orangeDuty = 0;
			bLedChanged = true;
		}
		else if(ledFlashTime == 6)
		{
			greenDuty = 0;
			orangeDuty = 100;
			bLedChanged = true;
		}
		else if(ledFlashTime>=10)
		{
			ledFlashTime = 0;
			flashBatLedCount--;
		}
	}
	else if(flashCount)	//�̵ƿ���
	{
		ledFlashTime++;
		if(ledFlashTime >= 2)
		{
			ledFlashTime = 0;
			bFlashOn = !bFlashOn;
			uart_printf("led flash,%d\n",bCharging);
			greenDuty  = 100;
			orangeDuty = 0;
			bLedChanged = true;
			if(flashCount && bFlashOn)
			{
				flashCount--;
				if(flashCount ==0)
				{
					bFlashOn = false;
					
					send_data_proc(CMD_CHILD_STATUS_REPORT);
					//��ʾ��ص���,֮����ݵ�ص������õ�
					if(batLevel >= 1)
					{
						orangeDuty = 0;
						greenDuty = 100;
					}
					else 
					{
						orangeDuty = 100;
						greenDuty = 0;
					}
				}
			}
		}		
	}
	else if(showBatLevelTime /*|| bCharging*/)
	{
		if((orangeDuty != 0 || greenDuty != 100)  && batLevel == 2)
		{			
			orangeDuty = 0;
			greenDuty = 100;			
			bLedChanged = true;
		}
		else if(!bCharging && batLevel == 1 && (orangeDuty != 100 || greenDuty != 0))
		{
			orangeDuty = 100;
			greenDuty = 0;			
			bLedChanged = true;
		}
	}
	else if(orangeDuty || greenDuty)
	{
		orangeDuty = 0;
		greenDuty = 0;
		bLedChanged = true;
	}
}

void set_led(void)
{
	uint8_t tempChar;
	if(bLedChanged)
	{
		bLedChanged = false;
		if(((showBatLevelTime /*|| bCharging*/) && !flashCount && !bWorking) || bFlashOn)
		{
#ifdef USE_PWM_DIFF
#ifdef USE_GPIO_PWM
			tempChar = 100-orangeDuty;			
			if(tempChar == 100)
			{
				gpio_config(boLedOrange,OUTPUT,PULL_NONE);
				gpio_set(boLedOrange,1);
			}
			else if(tempChar) start_pwm(PWM_MODE_PWM,0,1,LED_ORANGE_PWM,100,16-1,tempChar,0); 
			else
			{
				gpio_config(boLedOrange,OUTPUT,PULL_NONE);
				gpio_set(boLedOrange,0);
			}
#if USE_GREEN_AS_DEBUG_PIN==0			
			tempChar = 100-greenDuty;
			if(tempChar == 100)
			{
				gpio_config(boLedGreen,OUTPUT,PULL_NONE);
				gpio_set(boLedGreen,1);
			}
			else if(tempChar) start_pwm(PWM_MODE_PWM,0,1,LED_GREEN_PWM,100,16-1,tempChar,0);
			else
			{
				gpio_config(boLedGreen,OUTPUT,PULL_NONE);
				gpio_set(boLedGreen,0);
			}
#endif
#else			
			tempChar = 100-orangeDuty;			
			if(tempChar >= 50)
			{
				gpio_config(boLedOrange,OUTPUT,PULL_NONE);
				gpio_set(boLedOrange,1);
			}
			//else if(tempChar) start_pwm(PWM_MODE_PWM,0,1,LED_ORANGE_PWM,100,16-1,tempChar,0); 
			else
			{
				gpio_config(boLedOrange,OUTPUT,PULL_NONE);
				gpio_set(boLedOrange,0);
			}
			
			if(greenDuty >= 50)
			{
				if(!bLedGreenOn) {uart_printf("ledGreen on \n");bLedGreenOn = 1;}
#if USE_GREEN_AS_DEBUG_PIN == 0						
				gpio_set(boLedGreen,0);
#endif				
			}
			else
			{
				if(bLedGreenOn) {uart_printf("ledGreen off \n");bLedGreenOn = 0;}
#if USE_GREEN_AS_DEBUG_PIN == 0				
				gpio_set(boLedGreen,1);
#endif	
			}
#endif			
#else			
			tempChar = 100-orangeDuty;			
			if(tempChar == 100)
			{
				gpio_config(boLedOrange,OUTPUT,PULL_NONE);
				gpio_set(boLedOrange,1);
			}
			else if(tempChar) start_pwm(PWM_MODE_PWM,0,1,LED_ORANGE_PWM,100,16-1,tempChar,0); 
			else
			{
				gpio_config(boLedOrange,OUTPUT,PULL_NONE);
				gpio_set(boLedOrange,0);
			}
#if USE_GREEN_AS_DEBUG_PIN==0			
			tempChar = 100-greenDuty;
			if(tempChar == 100)
			{
				gpio_config(boLedGreen,OUTPUT,PULL_NONE);
				gpio_set(boLedGreen,1);
			}
			else if(tempChar) start_pwm(PWM_MODE_PWM,0,1,LED_GREEN_PWM,100,16-1,tempChar,0);
			else
			{
				gpio_config(boLedGreen,OUTPUT,PULL_NONE);
				gpio_set(boLedGreen,0);
			}
#endif	
#endif
		}
		else
		{
#if USE_GREEN_AS_DEBUG_PIN == 0
			gpio_config(boLedGreen,OUTPUT,PULL_NONE);
			gpio_set(boLedGreen,1);
#endif			
			gpio_config(boLedOrange,OUTPUT,PULL_NONE);
			gpio_set(boLedOrange,1);
		}
	}
}
extern const uint8_t pwm_channel_io_map[];
#ifdef USE_PWM_DIFF
#ifdef USE_GPIO_PWM
void start_anmo(uint8_t bStart)
{
	if(bStart)
	{	
    start_pwm(PWM_MODE_PWM,0,1,3,6666,80-1,16,0); 	// 30HZ
		//Delay_us(9);
		start_pwm(PWM_MODE_PWM,1,4,4,6666,80-1,30,30+21); 	// 30HZ
		GLOBAL_INT_DISABLE();
		setf_PWM_0_Reg0x4_CEN3 ;
		//Delay_us(35);
		Delay_us(21);
    setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
		GLOBAL_INT_RESTORE();
	}
	else
	{
		clrf_PWM_1_Reg0x4_CEN2;
		clrf_PWM_0_Reg0x4_CEN3;
//		gpio_config(pwm_channel_io_map[2], OUTPUT, PULL_NONE);
//		gpio_set(pwm_channel_io_map[2],0);
		gpio_config(pwm_channel_io_map[3], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[3],0);
		gpio_config(pwm_channel_io_map[4], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[4],0);
		gpio_config(pwm_channel_io_map[5], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[5],0);
	}		
}
#else
void start_anmo(uint8_t bStart)
{
	static uint8_t bFirstStart=  true;
	if(bStart)
	{
		if(bFirstStart)
		{
    //start_pwm(PWM_MODE_PWM,1,4,2,6666,80-1,32,4); 	// 30HZ
		start_pwm(PWM_MODE_PWM,1,4,2,6666,80-1,16,30+21); 	// 30HZ
		//Delay_us(9);
		//start_pwm(PWM_MODE_PWM,1,4,4,6666,80-1,32,4); 	// 30HZ
		start_pwm(PWM_MODE_PWM,1,4,4,6666,80-1,30,30+21); 	// 30HZ
		GLOBAL_INT_DISABLE();
		setf_PWM_0_Reg0x4_CEN3 ;
		//Delay_us(35);
		Delay_us(22);
    setf_PWM_0_Reg0x4_CEN2 ;                 //enable counter
		GLOBAL_INT_RESTORE();
			bFirstStart = false;
		}
		else
		{
			gpio_config(pwm_channel_io_map[2], SC_FUN, PULL_NONE);
			gpio_config(pwm_channel_io_map[3], SC_FUN, PULL_NONE);
			gpio_config(pwm_channel_io_map[4], SC_FUN, PULL_NONE);
			gpio_config(pwm_channel_io_map[5], SC_FUN, PULL_NONE);
		}
	}
	else
	{
	//	clrf_PWM_0_Reg0x4_CEN2;
	//	clrf_PWM_0_Reg0x4_CEN3;
		gpio_config(pwm_channel_io_map[2], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[2],0);
		gpio_config(pwm_channel_io_map[3], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[3],0);
		gpio_config(pwm_channel_io_map[4], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[4],0);
		gpio_config(pwm_channel_io_map[5], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[5],0);
	}		
}
#endif
#elif defined USE_GPIO_PWM
void start_anmo(uint8_t bStart)
{

	if(bStart)
	{
    start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT1_PWM,6666,80-1,30,0); 	// 30HZ
		//Delay_us(9);
		start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT2_PWM,6666,80-1,30,0); 	// 30HZ
	//	start_pwm(PWM_MODE_PWM,0,1,PWM_CHANNEL0,6666,80-1,18,0); 	// 30HZ
		GLOBAL_INT_DISABLE();
		setf_PWM_1_Reg0x4_CEN3 ;
		
		Delay_us(22);
		gpio_set(0x11,1);
	//	setf_PWM_0_Reg0x4_CEN1 ;
		Delay_us(10);
		gpio_set(0x11,0);
    setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
		GLOBAL_INT_RESTORE();
	}
	else
	{
	//	clrf_PWM_0_Reg0x4_CEN1;
		gpio_set(0x11,0);
		clrf_PWM_1_Reg0x4_CEN2;
		clrf_PWM_1_Reg0x4_CEN3;
	}
	
		
}
#elif defined USE_PWM0
void start_anmo(uint8_t bStart)
{
	if(bStart)
	{
    start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT1_PWM,6666,80-1,30,0); 	// 30HZ
		//Delay_us(9);
		start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT2_PWM,6666,80-1,30,0); 	// 30HZ
		start_pwm(PWM_MODE_PWM,0,1,PWM_CHANNEL0,6666,80-1,18,0); 	// 30HZ
		GLOBAL_INT_DISABLE();
		setf_PWM_1_Reg0x4_CEN3 ;
		Delay_us(24);
		setf_PWM_0_Reg0x4_CEN1 ;
		Delay_us(15);
    setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
		GLOBAL_INT_RESTORE();
	}
	else
	{
		clrf_PWM_0_Reg0x4_CEN1;
		clrf_PWM_1_Reg0x4_CEN2;
		clrf_PWM_1_Reg0x4_CEN3;
	}
}
#else
void start_anmo(uint8_t bStart)
{
	if(bStart)
	{
    start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT1_PWM,3333,160-1,15,0); 	// 30HZ
		//Delay_us(9);
		start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT2_PWM,3333,160-1,15,0); 	// 30HZ
		GLOBAL_INT_DISABLE();

		setf_PWM_1_Reg0x4_CEN3 ;
		Delay_us(35);
    setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter

		GLOBAL_INT_RESTORE();
	}
	else
	{
		
		clrf_PWM_1_Reg0x4_CEN2;
		clrf_PWM_1_Reg0x4_CEN3;
	}
		
		
}
#endif
#if TEST_ANMO_PLUS
#ifdef USE_PWM_DIFF

void start_anmo2(uint8_t bStart)
{
	static uint8_t bFirstStart=true;
	if(bStart)
	{
		if(bFirstStart)
		{
#if 0
		start_pwm(PWM_MODE_PWM,0,1,3,6666,80-1,16,0); 	// 30HZ
#else			
    start_pwm(PWM_MODE_PWM,1,4,2,6666,80-1,16,30+21); 	// 30HZ
#endif		
		//Delay_us(9);
		start_pwm(PWM_MODE_PWM,1,4,4,6666,80-1,30,30+21); 	// 30HZ
			bFirstStart = false;
		
		GLOBAL_INT_DISABLE();
		setf_PWM_0_Reg0x4_CEN3 ;
		Delay_us(22);
#if 0
		setf_PWM_1_Reg0x4_CEN2 ; 
#else		
    setf_PWM_0_Reg0x4_CEN2 ;                 //enable counter
#endif		
		GLOBAL_INT_RESTORE();
			}
		else
		{
			gpio_config(pwm_channel_io_map[2], SC_FUN, PULL_NONE);
			gpio_config(pwm_channel_io_map[3], SC_FUN, PULL_NONE);
			gpio_config(pwm_channel_io_map[4], SC_FUN, PULL_NONE);
			gpio_config(pwm_channel_io_map[5], SC_FUN, PULL_NONE);
		}
	}
	else
	{
//		clrf_PWM_0_Reg0x4_CEN3;
//		clrf_PWM_0_Reg0x4_CEN2;
		gpio_config(pwm_channel_io_map[2], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[2],0);
		gpio_config(pwm_channel_io_map[3], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[3],0);
		gpio_config(pwm_channel_io_map[4], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[4],0);
		gpio_config(pwm_channel_io_map[5], OUTPUT, PULL_NONE);
		gpio_set(pwm_channel_io_map[5],0);
	}
		
		
		
}
#else
void start_anmo2(uint8_t bStart)
{
	if(bStart)
	{
    start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT1_PWM,6666,80-1,30,0); 	// 30HZ
		//Delay_us(9);
		start_pwm(PWM_MODE_PWM,0,1,PLUS_OUTPUT2_PWM,6666,80-1,30,0); 	// 30HZ
	//	start_pwm(PWM_MODE_PWM,0,1,PWM_CHANNEL0,6666,80-1,18,0); 	// 30HZ
		GLOBAL_INT_DISABLE();
		setf_PWM_1_Reg0x4_CEN3 ;
		
		Delay_us(22);
		gpio_set(0x11,1);
	//	setf_PWM_0_Reg0x4_CEN1 ;
		Delay_us(10);
		gpio_set(0x11,0);
    setf_PWM_1_Reg0x4_CEN2 ;                 //enable counter
		GLOBAL_INT_RESTORE();
	}
	else
	{
	//	clrf_PWM_0_Reg0x4_CEN1;
		gpio_set(0x11,0);
		clrf_PWM_1_Reg0x4_CEN2;
		clrf_PWM_1_Reg0x4_CEN3;
	}
		
		
}

#endif
#endif

void init_adc(void)
{
	;
}
/*
				current 1:9.9ma		2:11mA		3:12.1ma		4:13.2ma		5:14.3ma
				R:68.1��
				voltage	1:674mv   2:749mv 	3:824mV 		4:899mv  		5:974mv			
*/
const uint16_t LEVEL_CURRENT_TBL[]={674,749,824,899,974};

int16_t get_prepare_data(void);
void prepare_adc(ADC_CHNL chnl);

void Delay_myus(int num)
{
    volatile int  y;
    for(y = 0; y < num; y ++ )
    {
        
           __nop();
       
    }
}
uint8_t bGetValidR;
uint16_t targetRArray[10];
uint8_t targetRIndex;
uint16_t targetRMax,targetRMin;
uint32_t targetR;
void debug_info_print(void)
{
	static uint8_t printPeriod=0;
	uint8_t i;
	
	printPeriod++;
	if(printPeriod>=10)
	{
		printPeriod = 0;
		if(bWorking)
		{
			uart_printf("current:%d(mV),targetBulkVoltage:%d(mV)\n",currentVoltage,targetBulkVoltage*101);
		
			uart_printf("bulkCycle:%d,bulkDuty:%d,bulkVoltage:%d(mV)\n",bulkCycle,bulkDuty,bulkVoltage*101);
		
		
			uart_printf("target res:%d\n",targetR);
		//
//			for(i=0;i<10;i++) uart_printf("%d ",targetRArray[i]);
//			uart_printf("target resMax:%d,Min:%d\n",targetRMax,targetRMin);
		}
		else			
		{
			uart_printf("bulkStep:%d,targetBulkVoltageAdc:%d(mV)\n",bulkDutyStep,targetBulkVoltage);
		}
		uart_printf("batVoltage:%d(mV)\n",batVoltage);
	}
}
uint16_t bulkVoltageArray[10];
uint16_t bulkVoltageMax;
uint16_t bulkVoltageMin;
uint8_t bulkVIndex;
uint8_t bGetValidV;

void init_target(void)
{
	targetRIndex = 0;
	
	bGetValidR = false;
	
	bulkVIndex = 0;
	
	bGetValidV = false;
}

uint16_t get_targetr(uint16_t curR)
{
	uint8_t i;
	uint32_t sum=0;
	targetRArray[targetRIndex++] = curR;
	
	if(targetRIndex>=10)
	{
		targetRIndex = 0;
		bGetValidR = true;
	}
	targetRMax = 0;
	targetRMin = 0xffff;
	
	/*if(curR > 20000) return curR;
	else */if(bGetValidR)
	{
		for(i=0;i<10;i++)
		{
			sum += targetRArray[i];
			if(targetRMax<targetRArray[i]) targetRMax = targetRArray[i];
			if(targetRMin>targetRArray[i]) targetRMin = targetRArray[i];
		}
		sum -= targetRMax;
		sum -= targetRMin;
		sum >>= 3;
		
		return sum;
	}
	else return curR;
}
#ifdef USE_PWM_DIFF
#define CURRENT_VOLTAGE_MAX	1300	
#else
#define CURRENT_VOLTAGE_MAX 1000
#endif
void get_bulk_voltage(void);
void target_det(void)	//30Hz
{
	
	if(bGetCurrent)
	{
		bGetCurrent = false;
		
	//	get_bulk_voltage();
		targetR = (bulkVoltage*101-currentVoltage)*68/currentVoltage;	//68.1
		
		
		targetR = get_targetr(targetR);
		
		//uart_printf("currentV:%d,targetR:%d\n",currentVoltage,targetR);
		
		//if(targetR>20500 || (targetStatus==TARGET_STATUS_LEAVE && targetR > 20000))		//ʵ��25.5K  20.5K����
		if(targetR>25500 || (targetStatus==TARGET_STATUS_LEAVE && targetR > 24500) || currentVoltage < 30)	//�뿪Ƥ��
		{
			targetNormalCount = 0;
			poorContactCount = 0;
			if(targetStatus != TARGET_STATUS_LEAVE)
			{
				targetLeaveCount++;
				if(targetLeaveCount>=30)	//1S
				{	
					targetLeaveCount = 0;
					loseTargetTime = 0;
					targetStatus = TARGET_STATUS_LEAVE;
					targetBulkVoltage = BULK_VOLTAGE_NO_TARGET;
					send_data_proc(CMD_CHILD_STATUS_REPORT);
					uart_printf("target leave\n");
				}
			}
			else
			{
				loseTargetTime++;
				if(loseTargetTime >= 30*30)	//30S
				{
					loseTargetTime = 0;
					bNeedWork = false;
					buzzerType = 2;
					delaySleep = 10*600;
					uart_printf("target leave stop work\n");
				}
			}
		}
		else
		{
			targetLeaveCount = 0;
			if((targetR>7500 && targetStatus == TARGET_STATUS_LEAVE) || (targetR>7500 && targetStatus == TARGET_STATUS_NORMAL) || (targetR>7500 && targetStatus == TARGET_STATUS_POOR))	//û�нӴ���Ƥ��
			{
				targetNormalCount = 0;
				if(targetStatus != TARGET_STATUS_POOR)
				{
					poorContactCount++;
					if(poorContactCount>=30)
					{
						targetStatus = TARGET_STATUS_POOR;
						poorContactCount = 0;
						send_data_proc(CMD_CHILD_STATUS_REPORT);
						uart_printf("target poor contact\n");
					}				
				}
				else
				{
					if(currentVoltage > CURRENT_VOLTAGE_MAX)
					{
						currentOverCount++;
						if(currentOverCount>=3)
						{
							currentOverCount = 3;
							if(targetBulkVoltage > bulkVoltage) targetBulkVoltage = bulkVoltage;
							else targetBulkVoltage--;
						}
					}
					else
					{
						currentOverCount = 0;
						if(currentVoltage < LEVEL_CURRENT_TBL[workLevel])
						{
							if(targetBulkVoltage<BULK_VOLTAGE_MAX) targetBulkVoltage++;
						}
						else if(currentVoltage > LEVEL_CURRENT_TBL[workLevel])
						{
							if(targetBulkVoltage>BULK_VOLTAGE_MIN) targetBulkVoltage--;
						}
					}
				}
			}
			else	if(targetStatus == TARGET_STATUS_NORMAL)//����
			{
				poorContactCount = 0;
				
				if(currentVoltage > CURRENT_VOLTAGE_MAX)
				{
					currentOverCount++;
					if(currentOverCount>=3)
					{
						currentOverCount = 3;
						if(targetBulkVoltage > bulkVoltage) targetBulkVoltage = bulkVoltage;
						else targetBulkVoltage--;
						uart_printf("set targetBulk:%d,bulkVoltage:%d\n",targetBulkVoltage,bulkVoltage);
					}
				}
				else
				{
					currentOverCount = 0;
					if(currentVoltage < LEVEL_CURRENT_TBL[workLevel])
					{
						if(targetBulkVoltage<BULK_VOLTAGE_MAX) 
						{
							if(targetBulkVoltage<(bulkVoltage+100))
								targetBulkVoltage++;
						}
					}
					else if(currentVoltage > LEVEL_CURRENT_TBL[workLevel])
					{
						if(targetBulkVoltage>BULK_VOLTAGE_MIN) targetBulkVoltage--;
					}
				}
				uart_printf("current = %d(mV),target vbulk=%d\r\n",currentVoltage,targetBulkVoltage); 

			}
			else	//�սӴ�����1s���պ����ڵȴ�VBULK������20V
			{
				poorContactCount = 0;
				targetNormalCount++;
				if(targetNormalCount >= 30)
				{
					targetNormalCount = 0;
					targetStatus = TARGET_STATUS_NORMAL;
					uart_printf("target touch normal\n");
					send_data_proc(CMD_CHILD_STATUS_REPORT);
				}
			}
		}
			
	}
}


#ifdef USE_PWM_DIFF
#ifdef USE_GPIO_PWM
void current_detect(void)
{
	uint16_t tempADC;
	if(bWorking)
	{
		if(get_PWM_0_Reg0x8_UIF3)
		{
			setf_PWM_0_Reg0x8_UIF3;
			prepare_adc(ADC_CHL_3);
			bCurrentCaptrue = true;		
		}
		GLOBAL_INT_DISABLE();
		
		while(bCurrentCaptrue)
		{
			if(get_PWM_1_Reg0x8_CC4IF)
			{
				setf_PWM_1_Reg0x8_CC4IF;
				Delay_myus(20);
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,1);
#endif
				currentVoltage = get_prepare_data();
				
				bCurrentCaptrue = false;
				bGetCurrent = true;
			
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,0);
#endif		
			}
		}
		if(bGetCurrent)
		{
			//Delay_myus(90);
			Delay_myus(130);
			gpio_set(boPWM3,1);
			Delay_myus(145);
			gpio_set(boPWM3,0);
#if TEST_ANMO_PLUS				
			bGetCurrent = false;
#endif			
		}
		
		GLOBAL_INT_RESTORE();
	}
}
#else
void current_detect(void)
{
	uint16_t tempADC;
	if(bWorking)
	{
		if(get_PWM_0_Reg0x8_UIF3)
		{
			setf_PWM_0_Reg0x8_UIF3;
			prepare_adc(ADC_CHL_3);
			bCurrentCaptrue = true;		
		}
		GLOBAL_INT_DISABLE();
		
		while(bCurrentCaptrue)
		{
			if(get_PWM_0_Reg0x8_CC4IF)
			{
				setf_PWM_0_Reg0x8_CC4IF;
				Delay_myus(20);
				//Delay_myus(120);
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,1);
#endif
				currentVoltage = get_prepare_data();
				
				bCurrentCaptrue = false;
				bGetCurrent = true;
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,0);
#endif		
			}
		}
		GLOBAL_INT_RESTORE();
	}
}
#endif
#elif defined USE_GPIO_PWM

void current_detect(void)
{
	uint16_t tempADC;
	uint8_t tempDelay;
	uint8_t bDelayInc=0;
	if(bWorking)
	{
		if(get_PWM_1_Reg0x8_UIF3)
		{
			setf_PWM_1_Reg0x8_UIF3;
			prepare_adc(ADC_CHL_3);
			bCurrentCaptrue = true;				
			tempDelay = 0;
		}
		GLOBAL_INT_DISABLE();
		
		while(bCurrentCaptrue)
		{
			if(get_PWM_1_Reg0x8_CC7IF)
			{
				setf_PWM_1_Reg0x8_CC7IF;
				bDelayInc = 1;
			}
			else if(get_PWM_1_Reg0x8_CC4IF)
			{
				setf_PWM_1_Reg0x8_CC4IF;
				bDelayInc = 1;
			}
			if(get_PWM_1_Reg0x8_UIF2)
			{
				setf_PWM_1_Reg0x8_UIF2;
				if(bDelayInc)
				{
					gpio_set(boPWM3,0);
					bDelayInc = 0;
					tempDelay = 0;
				}
				Delay_myus(20);
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,1);
#endif
				currentVoltage = get_prepare_data();
				bGetCurrent = true;				
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,0);
#endif		
			}
			else if(bDelayInc)
			{
				tempDelay++;
				if(tempDelay == 2)
				{
					gpio_set(boPWM3,1);
				}
				else if(tempDelay == 24)
				{
					gpio_set(boPWM3,0);
					bDelayInc = 0;
					tempDelay = 0;
					if(bGetCurrent) bCurrentCaptrue = false;
				}				
			}
		}
		GLOBAL_INT_RESTORE();
#if TEST_ANMO_PLUS	
		bGetCurrent =false;
#endif		
	}
}

#else

void current_detect(void)
{
	uint16_t tempADC;
	if(bWorking)
	{
		if(get_PWM_1_Reg0x8_UIF3)
		{
			setf_PWM_1_Reg0x8_UIF3;
			prepare_adc(ADC_CHL_3);
			bCurrentCaptrue = true;		
		}
		GLOBAL_INT_DISABLE();
		
		while(bCurrentCaptrue)
		{
			if(get_PWM_1_Reg0x8_UIF2)
			{
				setf_PWM_1_Reg0x8_UIF2;
				Delay_myus(20);
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,1);
#endif
				currentVoltage = get_prepare_data();
				
				bCurrentCaptrue = false;
				bGetCurrent = true;
#if USE_GREEN_AS_DEBUG_PIN				
				gpio_set(boLedGreen,0);
#endif		
			}
		}
		GLOBAL_INT_RESTORE();
	}
}
#endif

void init_bulk(void)
{
	bulkVIndex = 0;
	
	bGetValidV = false;
}


uint16_t get_bulk_avg(uint16_t curV)
{
	uint8_t i;
	uint32_t sum=0;
	bulkVoltageArray[bulkVIndex++] = curV;
	
	if(bulkVIndex>=10)
	{
		bulkVIndex = 0;
		bGetValidV = true;
	}
	bulkVoltageMax = 0;
	bulkVoltageMin = 0xffff;
	//printf("bulkVoltage:%d\n",curV);
	/*if(curR > 20000) return curR;
	else */if(bGetValidR)
	{
		for(i=0;i<10;i++)
		{
			sum += bulkVoltageArray[i];
			if(bulkVoltageMax<bulkVoltageArray[i]) bulkVoltageMax = bulkVoltageArray[i];
			if(bulkVoltageMin>bulkVoltageArray[i]) bulkVoltageMin = bulkVoltageArray[i];
		}
		sum -= bulkVoltageMax;
		sum -= bulkVoltageMin;
		sum >>= 3;
		
		return sum;
	}
	else return curV;
}
void get_bulk_voltage(void)
{	
	if(bWorking)
	{		
		//bulkVoltage = get_bulk_avg(get_gpio_chnl_data(ADC_CHL_2));
		bulkVoltage = get_gpio_chnl_data(ADC_CHL_2);
		if(bulkVoltage < (targetBulkVoltage+10))
		{
			if(bulkCycle == 65535 && bulkDuty<BULK_DUTY_MAX)
			{
				bulkDuty++;
			}
			else
			{
				if(bulkVoltage < (targetBulkVoltage - 50)) 
				{
					if(bulkCycle>10000)	bulkDutyStep = 100;	//����С�Ļ����仯̫��Ļ���ѹ������̫��
					else if(bulkCycle>7000)	bulkDutyStep = 50;
					else if(bulkCycle>4000)	bulkDutyStep = 25;
					else if(bulkCycle>2500)	bulkDutyStep = 10;
					else if(bulkCycle>1600)	bulkDutyStep = 5;
					else bulkDutyStep = 2;
				}
				else if(bulkVoltage <(targetBulkVoltage-10)) bulkDutyStep = 1;
				else bulkDutyStep = 0;
				if(bulkCycle > 100) bulkCycle -= bulkDutyStep;
				if(bulkCycle < 100) bulkCycle = 100;
			}
			
			
			bBulkDutyChanged = true;
		}
		else if(bulkVoltage > (targetBulkVoltage-10))
		{
			if(bulkCycle == 65535)
			{
				if(bulkDuty) bulkDuty--;
			}
			else
			{
#if VOLTAGE_OVER_QUICK_DOWN				
				if(bulkVoltage > (BULK_VOLTAGE_MAX+5000/101)) 
				{
					if(overVoltageDou>=5)
					{
						bulkDuty = 100;
					}
					else overVoltageDou++;					
				}
				else 
				{
					overVoltageDou = 0;
#endif				
					if(bulkVoltage > (targetBulkVoltage +50)) 
					{						
						if(targetBulkVoltage == 0) bulkDutyStep = 100;
						else if(bulkCycle>10000)	bulkDutyStep = 100;	//����С�Ļ����仯̫��Ļ���ѹ������̫��
						else if(bulkCycle>7000)	bulkDutyStep = 50;
						else if(bulkCycle>4000)	bulkDutyStep = 25;
						else if(bulkCycle>2500)	bulkDutyStep = 10;
						else if(bulkCycle>1600)	bulkDutyStep = 5;
						else bulkDutyStep = 2;					
					}
					else if(bulkVoltage >(targetBulkVoltage + 10)) bulkDutyStep = 1;
					else bulkVoltage = 0;
#if VOLTAGE_OVER_QUICK_DOWN					
				}
#endif				
				if(bulkCycle < (65535-bulkDutyStep)) bulkCycle += bulkDutyStep;
				else bulkCycle = 65535;
			}
			bBulkDutyChanged = true;
		}
		
	}
}

void adc_proc(void)
{
	uint16_t tempADC;
	//uart_printf(" %s \n",__func__);
	//if(int_flg || !adcIndex)
	{
            
            
		//int_flg = 0;

		
		adcIndex++;
		//if(adcIndex)
		{
			#if (ADC_VER_EN)  //verify the adc
			data_buff_tmp = (data_buff[0]>>4)+ADC_B;

			uart_printf("SETP_ADC_ %d : ADC = %4d, V = %10d\r\n",chn,data_buff[0]>>4,(data_buff_tmp*1000)/ADC_A);   

			#else
			  
			
			if(adcIndex%2)//20ms(adcIndex == 20)	//VBulk
			{
				get_bulk_voltage();
			//	adcIndex = 0;
			//	uart_printf("Vbulk=%d(mV)\n",bulkVoltage/*,batVoltage*/);
			}
			else if(adcIndex == 10)	//100ms
			{
//const uint8_t VOLTAGE_THR_LOW[]={132,140,162};//3V  3.3V   3.8V
//const uint8_t VOLTAGE_THR_HIGH[]={136,146,166};//3.2V  3.4V   3.9V
//charging 		level1		3.6V   level2   3.8v   Level3
//no charge	  level1		3.3V   level2		3.6v	 level3
				batVoltage = get_gpio_chnl_data(ADC_CHL_1);
				batVoltage *= 6;
				//if(batVoltage >= 3900 || (batLevel==2 && batVoltage>=3800))
				if((bCharging && (batVoltage >= 3800 || (batLevel==2 && batVoltage>=3700))) || 
					 (!bCharging && (batVoltage >= 3600 || (batLevel==2 && batVoltage>=3500))))
				{
					if(batLevel != 2)
					{
						batLevel = 2;
					  send_data_proc(CMD_CHILD_STATUS_REPORT);
					}
				}
				//else if(batVoltage >= 3400 || (batLevel==1 && batVoltage>=3300))
				else if((bCharging && (batVoltage >= 3600 || (batLevel==1 && batVoltage>=3500))) || 
					 (!bCharging && (batVoltage >= 3300 || (batLevel==1 && batVoltage>=3200))))
				{
					if(batLevel != 1)
					{
						batLevel = 1;
					  send_data_proc(CMD_CHILD_STATUS_REPORT);
					}
				}
				else if(batLevel)
				{
					batLevel = 0;
				  send_data_proc(CMD_CHILD_STATUS_REPORT);
				}
				adcIndex = 0;
			}
		
			else if(adcIndex == 4)	//��ּ�� //100ms
			{
				if(targetBulkVoltage == 0)	//û�г���ѹ,û�й���������£�����͹���
				{
#ifdef USE_ADC0		
					tempADC = get_gpio_chnl_data(ADC_CHL_0_TEMPERATURE);
#else										
					tempADC = get_gpio_chnl_data(ADC_CHL_4);
#endif					
					if(tempADC<50)	//5V
					{
						getChargeVoltageCount = 0;
						if(bGetChargeVoltage)						
						{
							noChargeTime++;
							if(noChargeTime >= 50)
							{
								noChargeTime = 0;
								bGetChargeVoltage = false;
								bChargeFull = false;
								bCharging = false;
								uart_printf("lose charge voltage\n");
							}
						}
						if(!bGetChargeVoltage && get_sleep_mode()<MCU_LOW_POWER_SLEEP && showBatLevelTime==0 && flashCount==0 && !bKeyDown && keyTime>=250 && flashBatLedCount==0)
						{
							//set_sleep_mode(MCU_DEEP_SLEEP);
							if(delaySleep == 0)
							{
							/*	if(app_env.adv_state == APP_ADV_STATE_STARTED || ke_state_get(TASK_APP)==APP_CONNECTED)
								{
									uart_printf("low power\n");
								
									set_sleep_mode(MCU_LOW_POWER_SLEEP);
								}
								else*/
								{
									uart_printf("deep sleep,targetBulkVoltage:%d\n",targetBulkVoltage);
									set_sleep_mode(MCU_DEEP_SLEEP);
								}
							}
						}
					}
					else 
					{
						if(!bGetChargeVoltage)
						{
							getChargeVoltageCount++;
							if(getChargeVoltageCount >= 5)
							{
								getChargeVoltageCount = 0;
								bGetChargeVoltage = true;
								//if(bWorking) bNeedWork = false;
								uart_printf("get charge voltage\n");
							}
						}
						if(get_sleep_mode() && bGetChargeVoltage) 
						{						
							uart_printf("wakeup C\n");
							
							set_sleep_mode(MCU_NO_SLEEP);							
						}
					}
					//uart_printf("ru cang = %d(mV),bat=%d(mV)\r\n",tempADC,batVoltage/*,data_buff[0]>>4*/); 
				}
				
				
			}
			
			
			#endif
		}
		//else adcIndex++;
		
		
//		adc_init();
//		adc_int_enable();
//		if(adcIndex == 1) 
//		{
//			gpio_set(boBulkAdcGnd,0);
//			adc_config(ADC_CHL_2, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);	
//		}
//		else if(adcIndex == 2) adc_config(ADC_CHL_3, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);	
//		else if(adcIndex == 3) adc_config(ADC_CHL_4, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);
//		
//		adc_power_open(ADC_VDD);
//		adc_enable(0x1);
	}
}


void work_proc(void)
{
	if(bWorking)
	{
		if(!bNeedWork)
		{
			bWorking = false;
			targetBulkVoltage = 0;
			bulkDuty = 0;	
			orangeDuty = 0;
			bLedChanged = true;
			bBulkDutyChanged = true;
			start_anmo(false);	
			send_data_proc(CMD_CHILD_STATUS_REPORT);
			uart_printf("stop work\n");
		}
	}
	else if(bNeedWork)
	{		
		bWorking = true;
		targetBulkVoltage = BULK_VOLTAGE_NO_TARGET;	
		bulkDutyStep = 100;
		bulkDuty = BULK_DUTY_MAX;
		bulkCycle = 58823;	//17hz
		orangeDuty = 100;
		workLedShowTime = 10000/100;
		loseTargetTime = 0;
		flashBatLedCount = 0;
		start_anmo(true);
		init_target();
		rIndex = 6;
		showBatLevelTime = 0;
		anmoTime = 30*600;
		delaySleep = 0;
#if VOLTAGE_OVER_QUICK_DOWN		
		overVoltageDou = 0;
#endif		
		send_data_proc(CMD_CHILD_STATUS_REPORT);
		uart_printf("start work\n");
	}	
}

uint8_t loseChargeCount;
void charge_det_proc(void)
{
	if(!bWorking)
	{
		if(gpio_get_input(biChargeDet))
		{
			if(bCharging)
			{				
				loseChargeCount++;
				if(loseChargeCount>=10)
				{
					if(bGetChargeVoltage)
					{
						bChargeFull = true;	
						bCharging = false;
						send_data_proc(CMD_CHILD_STATUS_REPORT);
						//���߳���
					}
					else 
					{
						bCharging = false;
						bChargeFull = false;
					}
					uart_printf("stop charge\n");
				}
			}
//			else if(bChargeFull)
//			{
//				if(!bGetChargeVoltage)
//				{
//					bChargeFull = false;
//					bCharging = false;
//				}
//			}
		}
		else
		{
			loseChargeCount = 0;
			if(!bCharging)
			{
				bCharging = true;
				bChargeFull = false;
				send_data_proc(CMD_CHILD_STATUS_REPORT);
				uart_printf("start charge\n");
			}
		}
	}
	else if(!gpio_get_input(biChargeDet))
	{
		bNeedWork = true;
	}
}

void init_bsp(void)
{
	PWM_DRV_DESC pwm0_drv_desc;
	
	//gpio_config(biKey,INPUT,PULL_HIGH);
	deep_sleep_wakeup_set(biKey,PULL_HIGH);
	//gpio_config(biChargeDet,INPUT,PULL_NONE);
	deep_sleep_wakeup_set(biChargeDet,PULL_NONE);
	gpio_config(boBatAdcGnd,OUTPUT,PULL_NONE);
	gpio_config(boBulkAdcGnd,OUTPUT,PULL_NONE);
	gpio_set(boBatAdcGnd,0);
	gpio_set(boBulkAdcGnd,0);
#if USE_GREEN_AS_DEBUG_PIN	
	gpio_config(boLedGreen,OUTPUT,PULL_NONE);
#endif	
#if USE_GPIO_PWM
	gpio_config(boPWM3,OUTPUT,PULL_NONE);
	gpio_set(boPWM3,0);
#elif defined USE_PWM_DIFF
	gpio_config(boLedGreen,OUTPUT,PULL_NONE);
	//gpio_config(boLedOrange,OUTPUT,PULL_NONE);
#endif	
#if TEST_ANMO_PLUS
	pwm0_init(0);
  pwm1_init(0);	
	start_anmo2(false);	
	start_anmo2(true);
	bWorking = 1;
#else	
//adc	
	//batVoltage = get_vbat_data();	
	adcIndex = 0;
//pwm		
	pwm0_init(0);
  pwm1_init(0);
	//bulk
	bulkDuty = 0;
	bBulkDutyChanged = true;
	//led	
  orangeDuty = 0;
	greenDuty = 0;	
	showBatLevelTime = 0;//10000/100;
	bLedChanged = true;
	bJustPowerOn = true;
	flashBatLedCount = 0;
	//anmo
	bWorking = false;
	bNeedWork = false;
	start_anmo(false);
	delaySleep = 10*600;
#endif	
}


void analyse_ble_data(uint8_t *pData,uint8_t length)
{	
	switch(pData[0])
	{
		case CMD_CHILD_RET:
			if(bChildReturn)
			{
				if(!pData[1])
				{
					bChildReturn = false;
					delaySleep = 10*600;
					showBatLevelTime = 30000/100;
					send_data_proc(CMD_CHILD_STATUS_REPORT);
				}
			}
			else if(pData[1])
			{
				bChildReturn = true;
				bNeedWork = false;
				delaySleep = 10*600;
				showBatLevelTime = 30000/100;
				send_data_proc(CMD_CHILD_STATUS_REPORT);
			}			
			workLevel = pData[2];
			if(get_sleep_mode())
			{				
				set_sleep_mode(MCU_NO_SLEEP);
				uart_printf("wakeup2\n");				
			}
			break;
		case CMD_SET_WORK_LEVEL:
			workLevel = pData[1];
			break;
		case CMD_SET_WORK:
			bNeedWork = pData[1];
			if(get_sleep_mode() && bNeedWork)
			{
				set_sleep_mode(MCU_NO_SLEEP);
				delaySleep = 10*600;
			}
			if(bWorking) 
			{
				workLedShowTime = 10000/100;
				if(bNeedWork == false)
				{
					delaySleep = 10*600;
				}
			}
			break;
		case CMD_GET_CHILD_STATUS:
			send_data_proc(CMD_CHILD_STATUS_REPORT);
			break;
		case CMD_GET_CHILD_VOLTAGE:	
			if(!bWorking)
			{
				showBatLevelTime = pData[1];
				showBatLevelTime <<= 8;
				showBatLevelTime |= pData[2];
				//if(bChildReturn) showBatLevelTime = 10000/100;
				//else showBatLevelTime = 60000/100;
				if(pData[3])
				{
					flashBatLedCount = 2;
					send_data_proc(CMD_CHILD_STATUS_REPORT);
				}
				else
				{
					flashCount = 3;
					greenDuty = 100;
				}
			}
			break;
	}
	if(!bMasterReady)
	{
		bMasterReady = true;
		if(bJustPowerOn) 
		{
			showBatLevelTime = 10000/100;
			flashBatLedCount = 2;
			bJustPowerOn = false;
		}
		send_data_proc(CMD_CHILD_STATUS_REPORT);
	}
}

void send_data_proc(uint8_t cmd)
{
	
	uint8_t sendBuffer[20];
	uint8_t len = 0;
	if(ke_state_get(TASK_APP)==APP_CONNECTED && bMasterReady)
	{
		sendBuffer[0] = cmd;
		switch(cmd)
		{
			case CMD_CHILD_STATUS_REPORT:				
				sendBuffer[1] = bWorking;		
				sendBuffer[2] = targetStatus;
				sendBuffer[3] = batLevel;
				if(bWorking)
				{
					sendBuffer[4] = workLedShowTime>>8;
					sendBuffer[5] = workLedShowTime&0xff;
				}
				else
				{
					sendBuffer[4] = showBatLevelTime>>8;
					sendBuffer[5] = showBatLevelTime&0xff;
				}
				sendBuffer[6] = buzzerType;
				sendBuffer[7] = bCharging;
				if(bChargeFull) sendBuffer[7] |= 0x02;
				sendBuffer[7] |= (flashBatLedCount<<2);
				buzzerType = false;
				len = 8;
				break;
		}
		app_fee4_send_ntf(0,len,sendBuffer);
  } 
}



void key_proc(void)
{
	if(gpio_get_input(biKey))
	{
		if(bKeyDown)
		{
			if(bKeyDou)
			{
				bKeyDou = false;
				bKeyDown = false;
				keyTime = 0;
				if(bKeyLong) bKeyLong = false;
				else if(bChildReturn)
				{
					flashCount = 3;
					greenDuty = 100;
					showBatLevelTime = 30000/100;				
				//	buzzerType = 2;
				}
				else if(!bWorking)
				{
					if(batLevel)
					{
						bNeedWork = true;
						buzzerType = 1;
					}
					else 
					{
						send_data_proc(CMD_CHILD_STATUS_REPORT);
						buzzerType = 2;
					}
				}
				else
				{
					workLedShowTime = 10000/100;
					send_data_proc(CMD_CHILD_STATUS_REPORT);
				}
			}
			else bKeyDou = true;
		}
		else
		{
			if(keyTime<250) keyTime++;
		}
	}
	else if(bKeyDown)
	{
		bKeyDou = false;
		
		if(keyTime<=250) keyTime++;
		if(keyTime == 200 && !bChildReturn && bNeedWork)
		{
			bKeyLong = true;
			bNeedWork = false;
			delaySleep = 10*600;
			showBatLevelTime = 0;
			buzzerType = 2;
		}
	}
	else if(bKeyDou)
	{
		bKeyDown = true;
		bKeyLong = false;
		keyTime = 0;
		delaySleep = 10*600;
//		if(app_env.adv_state != APP_ADV_STATE_STARTED && ke_state_get(TASK_APP)!=APP_CONNECTED)
//		{
//			app_start_advertising();
//		}
	}
	else bKeyDou = true;
}

void user_delay_proc(void)
{
	if(showBatLevelTime && flashBatLedCount==0)
	{
		showBatLevelTime--;
		if(showBatLevelTime == 0)
		{
		//	if(!bCharging)
			{
				bLedChanged = true;
				orangeDuty = 0;
				greenDuty = 0;				
			}
			
		}
	}
	
	if(anmoTime && bWorking)
	{
		anmoTime--;
		if(anmoTime == 0)
		{
			bNeedWork = false;
		}
	}
	
	if(delaySleep && !bCharging && !bWorking)
	{
		delaySleep--;
	}
}

void  main_loop(void)
{
#if TEST_ANMO_PLUS
	static  rwip_time_t cur_time;
  static rwip_time_t pre_time;
  uint32_t diff_tmr;
	cur_time = rwip_time_get();
	if(cur_time.hs>pre_time.hs)
  diff_tmr = (cur_time.hs - pre_time.hs) * 3125 /10000;	
  else diff_tmr=10;
	
	
	wdt_feed();
	current_detect();
	if(diff_tmr >= 10000)
	{
		pre_time = cur_time;
		bWorking = !bWorking;
		start_anmo2(bWorking);
	}
#else	
	static  rwip_time_t cur_time;
  static rwip_time_t pre_time;
  uint32_t diff_tmr;
	cur_time = rwip_time_get();
	if(cur_time.hs>pre_time.hs)
  diff_tmr = (cur_time.hs - pre_time.hs) * 3125 /10000;	
  else diff_tmr=10;
 
	current_detect();
	target_det();
	if(diff_tmr>=10 /*&& !bCurrentCaptrue*/)		//10ms
	{
//		do{
			wdt_feed();
			pre_time = cur_time;
			//uart_printf("difftime=%d\n",diff_tmr); 	
			
			work_proc();		
			set_bulk_voltage();		
			smart_led_proc();			
			set_led();			
			key_proc();		
			timer10msCounter++;
			adc_proc();		
			if(timer10msCounter>=10)
			{
				timer10msCounter = 0;			
				led_proc();				
				user_delay_proc();				
				debug_info_print();			
				charge_det_proc();				
			//	uart_printf("adv state:%d,app state:%d\n",app_env.adv_state,ke_state_get(TASK_APP));
			}	
//		}while(0);
	}
	
	
	if(get_sleep_mode())
	{
		if(!gpio_get_input(biKey) || !gpio_get_input(biChargeDet) || bBleWakeup)  
		{
			set_sleep_mode(MCU_NO_SLEEP);
			if(bBleWakeup) {bBleWakeup = false;delaySleep=10000/100;uart_printf("wakeupB\n");}
			else if(!gpio_get_input(biKey)) uart_printf("wakeup\n");
			else uart_printf("wakeup1\n");
		}
	}
	else if(bBleWakeup) bBleWakeup = false;
#endif	
}