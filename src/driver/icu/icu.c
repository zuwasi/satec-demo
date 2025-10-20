/**
****************************************************************************************
*
* @file icu.c
*
* @brief icu initialization and specific functions
*
* Copyright (C) Beken 2009-2016
*
* $Rev: $
*
****************************************************************************************
*/
#include <stddef.h>     // standard definition
#include "icu.h"      // timer definition
#include "uart1.h"
#include "BK3437_RegList.h"
#include "rf.h"
#include "driver_gpio.h"
#include "ll.h"
#include "user_config.h"
#include "reg_ipcore.h"
#include "driver_gpio.h"
#include "driver_flash.h"
#include "wdt.h"
#include "rf_xvr.h"

extern volatile uint32_t XVR_ANALOG_REG_BAK[32];
static uint8_t default_sleep_mode = 0;  //0:no idle   1:idle
uint8_t system_clk=0;

void gpio_set_int_mode(uint8_t gpio,uint8_t mode);

void Delay_us(int num)
{
    volatile int x, y;
    for(y = 0; y < num; y ++ )
    {
        for(x = 0; x < 10; x++)
        {
           __nop();
        }
    }
}

void Delay(int num)
{
    volatile int x, y;
    for(y = 0; y < num; y ++ )
    {
        for(x = 0; x < 50; x++)
        {
           __nop();
        }
    }
}

void Delay_ms(unsigned int num) //sync from svn revision 18
{
    volatile uint32_t x, y;
    for(y = 0; y < num; y ++ )
    {
        for(x = 0; x < 3260; x++)
        {
            __nop();       
        }
    }
 
}

void mcu_ldo_power(void)
{
    XVR_ANALOG_REG_BAK[6] &= ~(0x01 << 21);
    addXVR_Reg0x6 = XVR_ANALOG_REG_BAK[6];

    XVR_ANALOG_REG_BAK[0xa] |= (0x01 << 13);

    XVR_ANALOG_REG_BAK[0xa] &= ~(0x01 << 2);
    addXVR_Reg0xa = XVR_ANALOG_REG_BAK[0xa];
    addPMU_Reg0x11 |= (0x01 << 12);
}
void exchange_memery_init(void)
{
    unsigned long *p=(unsigned long *)EM_BASE_ADDR;
    int len=EM_BLE_END/4;
    int i;
    for(i=0;i<len;i++)
    {
        *p++ = 0;    
    }
}
void icu_init(void)
{
    #ifndef CFG_JTAG_DEBUG
    clrf_SYS_Reg0x0_jtag_mode;   ///close JTAG
    #endif
    exchange_memery_init();
    set_SYS_Reg0x2_core_sel(0x01);
    set_SYS_Reg0x2_core_div(0x0);///16M CLK

    //setf_SYS_Reg0xb_pwd_on_boostsel;
    //setf_SYS_Reg0xd_PLL_PWR_sel;
    clrf_SYS_Reg0xd_OSC_en_sel; //wakeup hardware open 16Mxtal
    
    /***********pll enable************/
    addSYS_Reg0x17 = 0xc2;
    Delay_us(2);
    // PMU-0x10<8,4,3> = '1';
    // PMU-0x12<8,4,3> = '0';
    addPMU_Reg0x10 = 0x118;
    addPMU_Reg0x12 = 0xfffffee7;
    Delay_us(50);
    clrf_SYS_Reg0x17_CLK96M_PWD;
    /***********pll enable************/
    
    set_PMU_Reg0x14_voltage_ctrl_work_aon(0xa);
    set_PMU_Reg0x14_voltage_ctrl_sleep_aon(0x9);
    set_PMU_Reg0x14_voltage_ctrl_work_core(0xf);
    set_PMU_Reg0x14_voltage_ctrl_sleep_core(0xf);
    addPMU_Reg0x14 |= 0X20000;

    addSYS_Reg0x1e = 0;
    addPMU_Reg0x13 |= (1<<7);
    addSYS_Reg0x13=0x14100040;
    
    uart_printf("R=%08x\r\n",addPMU_Reg0x15);
    addPMU_Reg0x15=0x323200a9;
    uart_printf("R=%08x,%08x\r\n",addPMU_Reg0x15,addSYS_Reg0x13);
    Delay_us(5000);
    
    #if 1
    clrf_PMU_Reg0x1_direct_wake_enable;

    #else
    //addPMU_Reg0x1 |= ((0x01 << 12));
    //addPMU_Reg0x1 &= ~(0x01 << 18);//flash don't shutdown when sleep
    setf_PMU_Reg0x1_direct_wake_enable;//open rw direct wake,don't change
    //clrf_PMU_Reg0x1_direct_wake_enable;
    //addPMU_Reg0x1 |= (0x01 << 18);
    //addPMU_Reg0x1 |= (0x01 << 20);
    //addPMU_Reg0x1 |= (0x01 << 21);
    //addPMU_Reg0x1 |= (0x01 << 22);
    //setf_PMU_Reg0x15_pll_gate_dis;//bypass 32k anyone
   // addPMU_Reg0x1 |= 0x80000; //gpio b debug bit7 voltage_read,close_clock_now bit6
    #endif

    // for ADC
    addPMU_Reg0x10 |= (1<<8)|(1<<3)|(1<<4);
    addPMU_Reg0x12 &= ~( (1<<8)|(1<<3)|(1<<4));
    // for ADC end
    addSYS_Reg0x29=0XA50A;//powerdown rom
}



void mcu_clk_switch(uint8_t clk)
{
    if(system_clk == clk)
        return;
    
    system_clk = clk;
    switch(clk)
    {
        case MCU_CLK_16M:
        {   
            set_SYS_Reg0x2_core_div(0x0);
            set_SYS_Reg0x2_core_sel(0x01);
            
        }break;
        case MCU_CLK_32M:
        {
            clrf_SYS_Reg0x17_CLK96M_PWD;

            set_SYS_Reg0x2_core_div(0x0);
            set_SYS_Reg0x2_core_sel(0x03);////CLK==48M
        
        }break;

        default:break;
    }
    
}

uint8_t get_sleep_mode(void)
{
    return default_sleep_mode;
}
void set_sleep_mode(uint8_t v)
{
    default_sleep_mode = v;
}

#if 1
void cpu_idle_sleep(void)
{
    __nop();
    __nop();
    __nop();
    WFI();
    __nop();
    __nop();
    __nop();
}
#else
void cpu_idle_sleep(void)
{
    setf_SYS_Reg0x17_HP_LDO_PWD;
    setf_SYS_Reg0x1_CPU_PWD; // Power down MCU
    clrf_SYS_Reg0x17_HP_LDO_PWD;
}
#endif

void cpu_low_power_sleep(void)// @3V addSYS_Reg0x2 7uA
{
    //////load cpu_low_power_sleep fun in cache,,don't del it
    do
    {
        char * buff;
        volatile char temp;
        buff=(char *)cpu_low_power_sleep;
        for(int i=0; i<0x120; i++)
        {
            temp=buff[i];
        }
    }while (0);
    //////load cpu_low_power_sleep fun in cache end

    //clrf_PMU_Reg0x1_force_rw_wake;
    addPMU_Reg0x10 = 0;
    addPMU_Reg0x12 = 0xffffffff;
    
    //addXVR_Reg0x7  = 0x68410500; // reduce 0.3uA
    set_SYS_Reg0x2_core_sel(0x1);//16m sel
    set_SYS_Reg0x2_core_div(0x0);//divide 0
    Delay_us(1);
    set_flash_clk(0x08);
    
    setf_SYS_Reg0x1_gotosleep;
    clrf_SYS_Reg0x1_gotosleep;
    setf_PMU_Reg0x14_sleep_sel;//ENABLE LOW POWER
    set_PMU_Reg0x14_voltage_ctrl_work_aon(0x9);
    Delay_us(2);

    set_SYS_Reg0x2_core_sel(0x0);//rc32k sel

    addSYS_Reg0x17 = 0xCF;//CLOSE 16M
    addSYS_Reg0x1=0x01; // Power down MCU
    
    __nop();
    clrf_PMU_Reg0x14_sleep_sel;
    addSYS_Reg0x17=0xC0;
    __nop();
    set_SYS_Reg0x2_core_sel(0x1);//16m sel
    
    // PMU-0x10<8,4,3> = '1';
    // PMU-0x12<8,4,3> = '0';
    addPMU_Reg0x10 = 0x100;
    addPMU_Reg0x12 = 0xfffffeff;
    set_PMU_Reg0x14_voltage_ctrl_work_aon(0xa);
    cpu_wakeup();
    set_flash_clk(0x00);
}
void cpu_wakeup(void)
{
    switch(system_clk)
    {
        case MCU_CLK_16M:
        {
            //Delay_us(20);
            set_SYS_Reg0x2_core_div(0x0);
            set_SYS_Reg0x2_core_sel(0x01);
        }break;
        case MCU_CLK_32M:
        {
            Delay_us(20);//150us
            set_SYS_Reg0x2_core_div(0x0);
            set_SYS_Reg0x2_core_sel(0x03);
        }break;
        default:
        {
            set_SYS_Reg0x2_core_div(0x0);
            set_SYS_Reg0x2_core_sel(0x01);
        }break;
    }
}

void pll_test(void)
{
    int i;
    uart_printf("========PLL_TEST=====\r\n");
    while(1)
    {
    //2.5us
        uart_printf("set 16M-P04\r\n");
        mcu_clk_switch(MCU_CLK_16M);
        for(i=0;i<0xfff0;i++)
        {
            *((volatile unsigned long *) (0x00800A00+4*(0*8+4))) ^= 0x02;
        }
    //1.3125us
        uart_printf("set 32M-P05\r\n");
        mcu_clk_switch(MCU_CLK_32M);
        for(i=0;i<0xfff0;i++)
        {
            *((volatile unsigned long *) (0x00800A00+4*(0*8+5))) ^= 0x02;
        }
    //1.0625us
        uart_printf("set 64M-P06\r\n");
        mcu_clk_switch(MCU_CLK_64M);
        for(i=0;i<0xfff0;i++)
        {
            *((volatile unsigned long *) (0x00800A00+4*(0*8+6))) ^= 0x02;
        }
    }
}

void deep_sleep(void)// @ 3V , 0.6uA
{
    addSYS_Reg0x10 =0;  // close all int
    setf_PMU_Reg0x1_mchk_bypass;
    addrtc_aon_Reg0x1 = 200000;//up
    addrtc_aon_Reg0x2 = 300000;//tick

    Delay_us(100);

    setf_SYS_Reg0x17_HP_LDO_PWD;     // close LDO high power mode

    XVR_ANALOG_REG_BAK[0x7] |= 1<<21;
    addXVR_Reg0x7  = XVR_ANALOG_REG_BAK[0x7];    
    set_PMU_Reg0x4_gotosleep(0x3437);
    while(1);
}
void cpu_reset(void)
{
    setf_PMU_Reg0x1_reg0_w_en;
    //clrf_PMU_Reg0x1_fast_boot;
    Delay_us(2000);
    //setf_PMU_Reg0x0_digital_reset;
    setf_PMU_Reg0x0_all_reset;
}
uint8_t system_reset_reson(void)
{
    //0:power on
    //2:wdt reset
    //4:deepsleep wakeup
    uart_printf("sys reset reason:%x\r\n",get_PMU_Reg0x0_reset_reason);

    return 0;
}
void deep_sleep_wakeup_set(uint8_t gpio,uint8_t pull_sel)
{
    //setf_PMU_Reg0x5_deep_wake_by_gpio;
    gpio_config(gpio,INPUT,(Pull_Type)pull_sel);
    
    addPMU_Reg0x3 |= 1<<((gpio>>4)*8+(gpio&0x0f));

}
/*****************************************************************************/
/// rc32k_calib funtion start
/*****************************************************************************/
uint32_t esti_32K_count =0;
#define ESTI_32K_DEFAULT             5000
#define ESTI_32K_DEFAULT_MAX         (ESTI_32K_DEFAULT + 2)  //*(1+0.4/1000)
#define ESTI_32K_DEFAULT_MIN         (ESTI_32K_DEFAULT - 2)  //*(1-0.4/1000)
#define ESTI_32K_DEFAULT_AVERAGE     5// ESTI_32K_DEFAULT*0.001
#define ESTI_32K_DEFAULT_VERIFY      10
void clk_esti_initial(uint32 value)
{
    set_CLK_EST_Reg0x1_ckes_config(value);
    setf_CLK_EST_Reg0x2_intr_status ; 
}
void INT_HANDLER_CLKEST(void)
{
    if(get_CLK_EST_Reg0x2_intr_status ) 
    {
        uart_printf("EXT INT\r\n");
        setf_CLK_EST_Reg0x2_intr_status ; 
    }  
}
uint8_t clk32k_estti_check(void)
{
    uint16_t f_32k_data=0,c_32k_data=0;
    uint32_t reg,tmp;

    //uint32_t c_min = 0xfffff,c_max = 0,c_sum = 0;
    reg = addPMU_Reg0x5;
    //for(k = 0 ; k < 4 ; k++)
    {
        clk_esti_initial(10);
        setf_CLK_EST_Reg0x0_ckes_enable;
        while(!get_CLK_EST_Reg0x2_intr_status)
        {
            __nop();
        }
        setf_CLK_EST_Reg0x2_intr_status ; 
        clrf_CLK_EST_Reg0x0_ckes_enable;
        esti_32K_count = get_CLK_EST_Reg0x3_ckes_number;
    }

    f_32k_data = (uint16_t)(reg>>18)&0x7f;
    c_32k_data = (uint16_t)(reg >>9 )&0x1ff;
    tmp = (reg >>9 )&0xffff;
    //uart_printf("s=%d,f=%d , c=%d\r\n",esti_32K_count,f_32k_data,c_32k_data);
    uart_printf("{\"RC32K\": {\"S\":%d,\"F\":%d,\"C\":%d}}\r\n",esti_32K_count,f_32k_data, c_32k_data);

    if(esti_32K_count > ESTI_32K_DEFAULT_MAX)
    {
        uart_printf("est1 = %d\r\n",esti_32K_count);
        esti_32K_count = esti_32K_count - ESTI_32K_DEFAULT;
        while(esti_32K_count>ESTI_32K_DEFAULT_AVERAGE)
        {
            esti_32K_count -= ESTI_32K_DEFAULT_AVERAGE;
            tmp += ESTI_32K_DEFAULT_VERIFY;
        }
        if(esti_32K_count)
            tmp += ESTI_32K_DEFAULT_VERIFY;
        
        c_32k_data = (uint16_t)tmp &0x1ff;
        f_32k_data = (uint16_t)(tmp>>9)&0x7f;
        uart_printf("f0=%d , c0=%d\r\n",f_32k_data,c_32k_data);
        rc32k_calib_manu(c_32k_data,f_32k_data);
        return 1;
        
    }
    else if(esti_32K_count < ESTI_32K_DEFAULT_MIN)
    {
        uart_printf("est2 = %d\r\n",esti_32K_count);
        esti_32K_count = ESTI_32K_DEFAULT - esti_32K_count ;
        while(esti_32K_count>ESTI_32K_DEFAULT_AVERAGE)
        {
            esti_32K_count -=ESTI_32K_DEFAULT_AVERAGE;
            if(tmp >ESTI_32K_DEFAULT_VERIFY)
            {
                tmp -= ESTI_32K_DEFAULT_VERIFY;
            }
        }
        if(esti_32K_count)
        {
            if(tmp >ESTI_32K_DEFAULT_VERIFY)
            {
                tmp -= ESTI_32K_DEFAULT_VERIFY;
            }
        } 
        c_32k_data = (uint16_t)tmp &0x1ff;
        f_32k_data = (uint16_t)(tmp>>9)&0x7f;
        uart_printf("f1=%d , c1=%d\r\n",f_32k_data,c_32k_data);

        rc32k_calib_manu(c_32k_data,f_32k_data);
        return 1;
    }
    return 0;
}

void clk32K_esti(void)
{
    uart_printf("case_clk_esti start!\r\n");
    //8-0 切换点 上9个细调值
    while(1)
    {
        if(clk32k_estti_check())
        {
            Delay_us(4000);
        }
        else
        {
            break;
        }
    }  
    uart_printf("verfu rc32k end = %x\r\n",addPMU_Reg0x5);
}
/*****************************************************************************/
/// rc32k_calib funtion end
/*****************************************************************************/


////test funtion default closed
#if 0
void system_set_reset_reson(unsigned int reson_data)
    // only poweron,wdt(PMU.reg1.bit3=0),force reset all  ,this reg =0
{
    setf_PMU_Reg0x1_wdt_reset_ctrl;
    addPMU_Reg0x3 = reson_data;
    uart_printf("set reset reason=%x\r\n",addPMU_Reg0x3);
}
void test_reset_reason(void)
{
    system_set_reset_reson(C_DEEPSLEEP_RESET);
    //gpio_config(0x31,0,0);
    //deep_sleep_wakeup_set(0x31);
    deep_sleep();
}

#define REG_AHB10_RW_DEEPSLCNTL     (*((volatile unsigned long *)   0x00820030))
#define REG_AHB10_RW_DEEPSLTIME     (*((volatile unsigned long *)   0x00820034))
#define REG_AHB10_RW_DEEPSLDUR     (*((volatile unsigned long *)    0x00820038))
#define REG_AHB10_RW_ENBPRESET     (*((volatile unsigned long *)    0x0082003C))
#define REG_AHB10_RW_FINECNTCORR     (*((volatile unsigned long *)  0x00820040))
#define REG_AHB10_RW_BASETIMECNTCORR    (*((volatile unsigned long *)   0x00820044))

#define RW_ENBPRESET_TWEXT_bit     21
#define RW_ENBPRESET_TWOSC_bit     10
#define RW_ENBPRESET_TWRW_bit     0
void rw_sleep(void)
{
    clrf_SYS_Reg0x3_rwbt_pwd;//open rw clk

    addPMU_Reg0x1 |= (0x01 << 8);
    addPMU_Reg0x1 |= (0x01 << 12);
    //addPMU_Reg0x1 |= (0x01 << 17);
    addPMU_Reg0x1 |= (0x01 << 18);

    REG_AHB10_RW_DEEPSLTIME=0x0000;//sleep time ;finite
    REG_AHB10_RW_ENBPRESET = (0x02<<RW_ENBPRESET_TWEXT_bit)|
    (0x02<<RW_ENBPRESET_TWOSC_bit)|(0x02<<RW_ENBPRESET_TWRW_bit);
    REG_AHB10_RW_DEEPSLCNTL=0x00000007;//BLE sleep
}

void idle_test(void)
{
    uart_printf("==============IDLE_TEST_==============\r\n");
    Delay_ms(20);
    while(1)
    {
       uart_printf("enter in idle mode ,P04 to GND for wakeup\r\n");
       Delay_ms(20);
       gpio_config(0x04,INPUT,PULL_HIGH);
       gpio_set_int_mode(0x04,FALL_EDGE);
       rw_sleep();
    //   while(1);
       cpu_idle_sleep();

       uart_printf("wake up \r\n");
       Delay_ms(20);
    }
}
 
void lvslp_test(void)
{

    uart_printf("==============LVSLP_TEST_==============\r\n");
    Delay_ms(20);
    clrf_PMU_Reg0x14_sleep_sel;

    while(1)
    {
        uart_printf("enter in lvslp mode ,P04 to GND for wakeup\r\n");
        Delay_ms(20);
        gpio_config(0x04,INPUT,PULL_HIGH);
        gpio_set_int_mode(0x04,FALL_EDGE);
   //      setf_PMU_Reg0x14_sleep_sel;
        rw_sleep();
        cpu_low_power_sleep();
  //      clrf_PMU_Reg0x14_sleep_sel;

        uart_printf("wake up \r\n");
        Delay_ms(20);
    }

}

void cpu_deepsleep_test(void)
{
    uart_printf("==============DEEPSLEEP_TEST_==============\r\n");
  //  clrf_PMU_Reg0x14_sleep_sel;
    while(1)
    {
        uart_printf("cpu_deepsleep_test ,P04 to GND for wakeup\r\n");
        Delay_ms(20);

        //XVR_ANALOG_REG_BAK[3] &= (0x1 << 31);
        //addXVR_Reg0x3 = XVR_ANALOG_REG_BAK[3];
        //enable the system ldo,buck
        //XVR_ANALOG_REG_BAK[6] |= 1<<21;
        //addXVR_Reg0x6 = XVR_ANALOG_REG_BAK[6];
        deep_sleep_wakeup_set(0x04,1);
        rw_sleep();
        deep_sleep();
    }

}
#endif

