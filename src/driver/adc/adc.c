#include <stdio.h>
#include "adc.h"
#include "uart0.h"
#include "driver_gpio.h"
#include "icu.h"
#include "user_config.h"
#include "driver_flash.h"

#define SDADC_K        820
#define SDADC_B        (-241)
#define SDADC_K_DIV    365
#define SDADC_B_DIV    (-231)


extern uint32_t XVR_ANALOG_REG_BAK[32];
volatile uint8_t int_flg = 0;
volatile uint32_t cnt = 0;
volatile int16_t data_buff[10] = {0};
volatile uint8_t cic2_bypass=0;

static int16_t  s_sdadc_k = SDADC_K;
static int16_t  s_sdadc_b = SDADC_B;

static int16_t  s_sdadc_k_div = SDADC_K_DIV;
static int16_t  s_sdadc_b_div = SDADC_B_DIV;


//V = (ADC+B)/A
#define ADC_VER_EN      0
#define ADC_BKREG      0
extern uint8_t uart_rx_done ;
extern uint8_t uart_rx_buf[UART_RX_FIFO_MAX_COUNT];
uint8_t adc_en=0;

adc_int_call_back adc_int_cb = NULL; 

void adc_int_cb_register(adc_int_call_back cb)
{
    if(cb)
    {
        adc_int_cb = cb;
    }
}

void adc_get_calibration(void)
{
    uint8_t cali_data[8];
    int8_t ret;
    int16_t cali_1v = 0,cali_0p5v = 0,cali_2v = 0,cali_3v = 0;
    ret = get_flash_otp_calibration(TLV_TAG_CALI_SDADC,cali_data);
    if(ret > 0) {
        cali_0p5v = (cali_data[0] | cali_data[1] << 8);
        cali_1v = (cali_data[2] | cali_data[3] << 8);
        cali_2v = (cali_data[4] | cali_data[5] << 8);
        cali_3v = (cali_data[6] | cali_data[7] << 8);

        s_sdadc_k = 2*(cali_1v - cali_0p5v);
        s_sdadc_b = 2*cali_0p5v - cali_1v;
        s_sdadc_k_div = cali_3v - cali_2v;
        s_sdadc_b_div = 3*cali_2v - 2*cali_3v;
        uart_printf("SDADC cali data read from OTP:%d,%d,%d,%d\r\n",cali_0p5v,cali_1v,cali_2v,cali_3v);
        uart_printf("SDADC K&B read from OTP:%d,%d,%d,%d\r\n",s_sdadc_k,s_sdadc_b,s_sdadc_k_div,s_sdadc_b_div);
    } else {
        // s_sdadc_k and s_sdadc_b use the default value;
        s_sdadc_k = SDADC_K;
        s_sdadc_b = SDADC_B;
        s_sdadc_k_div = SDADC_K_DIV;
        s_sdadc_b_div = SDADC_B_DIV;
        uart_printf("SDADC cali data setting default:%d,%d,%d,%d\r\n",s_sdadc_k,s_sdadc_b,s_sdadc_k_div,s_sdadc_b_div);
    }

}

void adc_power_open(ADC_REF_VADC v_sel)
{
    XVR_ANALOG_REG_BAK[0xd] |= (1<<30) +(1<<25);
    XVR_ANALOG_REG_BAK[0xd] &= ~(0x1<<28);//bit28-> 1:Vadc = 0.4*Vdd ,0 : Vadc=vbg 12
    XVR_ANALOG_REG_BAK[0xd] |= v_sel<<28;
    addXVR_Reg0xd = XVR_ANALOG_REG_BAK[0xd];
}

void adc_power_close(void)
{
    XVR_ANALOG_REG_BAK[0xd] &= ~((1<<30)+(1<<25));
    addXVR_Reg0xd = XVR_ANALOG_REG_BAK[0xd];
}

void adc_divided_enable(void)
{
    XVR_ANALOG_REG_BAK[0xd]  |= (1<<29);
    addXVR_Reg0xd=XVR_ANALOG_REG_BAK[0xd];
}
 
void adc_divided_disable(void)
{
    XVR_ANALOG_REG_BAK[0xd]  &= ~(1<<29);
    addXVR_Reg0xd=XVR_ANALOG_REG_BAK[0xd];
}

void adc_init(void)
{
    set_SYS_Reg0x1e_ahb_clk_gate_disable(0x1);
    set_SDMADC_Reg0x2_soft_rst(1);
    set_SDMADC_Reg0x2_bypass_ckg(1);

    clrf_SYS_Reg0x3_sadc_pwd;
}
void adc_int_enable(void)
{
    setf_SYS_Reg0x10_int_adc_en;
}
void adc_int_disable(void)
{
    clrf_SYS_Reg0x10_int_adc_en;
}
void adc_enable(uint32_t enable)
{
    set_SDMADC_Reg0x4_Sample_Enable(enable);
}

void adc_config(ADC_CHNL chnl, ADC_SMP_MODE mode, ADC_INT_MODE int_mode)
// the adc buf len is  32B
{
    uint32_t smp_num = 0x0;
#ifdef USE_ADC0		
    if(chnl<ADC_CHL_VBAT && chnl>=ADC_CHL_0_TEMPERATURE)
#else
		if(chnl<ADC_CHL_VBAT && chnl>ADC_CHL_0_TEMPERATURE)
#endif			
    {
        gpio_config(chnl+1, SC_FUN, PULL_NONE);
        gpio_scfun_sel(chnl+1, 3);
        //uint32_t gpio_temp = *((volatile unsigned long *) (BASEADDR_SYS + 4 * (0 + 0x30)));
        //uart_printf("GPIO03:%08x,%08x\r\n",addAON_GPIO_Reg0x3,gpio_temp);
    }
    if(mode == ADC_SMP_STEP)
        smp_num = 0x0;
    else
        smp_num = 0x0;
    
    if(chnl == ADC_CHL_MICP)
        cic2_bypass = 0;
    else
        cic2_bypass = 1;
    
    addSDMADC_Reg0x5 = 0x00000000;
    addSDMADC_Reg0x5 |= (mode << posSDMADC_Reg0x5_Sample_Mode)
                        | (smp_num << posSDMADC_Reg0x5_Sample_Numb)
                        | (chnl << posSDMADC_Reg0x5_Sample_Chsel)
                        | (cic2_bypass << posSDMADC_Reg0x5_Cic2_Bypass)
                        | (0x1 << posSDMADC_Reg0x5_Comp_Bypass)
                        | (0x2D << posSDMADC_Reg0x5_Cic2_Gains)
                        | (int_mode << posSDMADC_Reg0x5_Intr_Enable);

    if(chnl == ADC_CHL_MICP)
    {
        addSDMADC_Reg0x6 |= (0xffff << posSDMADC_Reg0x6_Cali_Offset)
                         | (0x1fff << posSDMADC_Reg0x6_Cali_Gain);
    }
    else
    {
        addSDMADC_Reg0x6 |= (0x0000 << posSDMADC_Reg0x6_Cali_Offset)
                         | (0x1000 << posSDMADC_Reg0x6_Cali_Gain);
    }

   // uart_printf("addSDMADC_Reg0x5=%x\r\n",addSDMADC_Reg0x5);
   // uart_printf("addSDMADC_Reg0x6=%x\r\n",addSDMADC_Reg0x6);
                    
}

void adc_ctrl(ADC_CTRL_CMD cmd, uint32_t arg)
{
    switch (cmd)
    {
    case ADC_SMP_MODE_SET:
        set_SDMADC_Reg0x5_Sample_Mode(arg);
        break;
    case ADC_SMP_NUM_SET:
        set_SDMADC_Reg0x5_Sample_Numb(arg);
        break;
    case ADC_SMP_CHNL_SET:
        set_SDMADC_Reg0x5_Sample_Chsel(arg);
        break;
    case ADC_CIC2_BYPASS_SET:
        set_SDMADC_Reg0x5_Cic2_Bypass(arg);
        break;
    case ADC_COMP_BYPASS_SET:
        set_SDMADC_Reg0x5_Comp_Bypass(arg);
        break;
    case ADC_CIC2_GAINS_SET:
        set_SDMADC_Reg0x5_Cic2_Gains(arg);
        break;
    case ADC_INTR_EN_SET:
        set_SDMADC_Reg0x5_Intr_Enable(arg);
        break;
    case ADC_CALI_OFFSET_SET:
        set_SDMADC_Reg0x6_Cali_Offset(arg);
        break;
    case ADC_CALI_GAIN_SET:
        set_SDMADC_Reg0x6_Cali_Gain(arg);
        break;
    default:
        break;
    }
}


void adc_isr(void)
{
    uint32_t state;
    state = get_SDMADC_Reg0x7_Sadc_Status;
    if(cic2_bypass==0)// adc_ audio
    {
        if(adc_int_cb)
        {
            (*adc_int_cb)();
        }
    }
    else
    {
        // adc_gpio
        if(get_SDMADC_Reg0x5_Sample_Mode & 0x1)//signle
        {
            while(!(get_SDMADC_Reg0x7_Sadc_Status & 0x4) )
            {
                data_buff[0] =(int16_t) addSDMADC_Reg0x8;
            }
            int_flg = 1;
            addSDMADC_Reg0x2 = 0x00000000 ;
        }
        else
        {
            while((!((get_SDMADC_Reg0x7_Sadc_Status & 0x4) >> 2)))// continue
            {
                // uart_printf("%d\r\n",(int16_t)addSDMADC_Reg0x8);
                if(cnt < 10)
                {
                    data_buff[cnt++] =(int16_t) addSDMADC_Reg0x8;
                }
                if(cnt == 10)
                {
                    clrf_SDMADC_Reg0x4_Sample_Enable;
                    addSDMADC_Reg0x2 = 0x00000000 ;
                    int_flg = 1;
                }
            }
        }
    }
    addSDMADC_Reg0x7 = state;//clr int
}

int16_t get_temperature_sensor_data(void)
{
    //uart_printf("%s\r\n",__func__);
    addPMU_Reg0x13 &= ~(1<<8);//open temperature_sensor
    adc_init();
   
    adc_config(ADC_CHL_0_TEMPERATURE, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);
    adc_power_open(ADC_VBG);
    adc_divided_enable();
    adc_enable(0x1);
    while(!(get_SDMADC_Reg0x7_Sadc_Status&0x01));
 
    data_buff[0] =(int16_t) addSDMADC_Reg0x8;
    //uart_printf("ADC avg = %d,%x\n", data_buff[0],get_SDMADC_Reg0x7_Sadc_Status);


    set_SDMADC_Reg0x2_soft_rst(0);
    addSDMADC_Reg0x7=get_SDMADC_Reg0x7_Sadc_Status;
    
    adc_enable(0x0);
    addPMU_Reg0x13 |= (1<<8);
    adc_divided_disable();
    adc_power_close();
    return data_buff[0];
}

int16_t get_vbat_data(void)
{
    //uart_printf("%s\r\n",__func__);
    int16_t vbat_volt = 0; // mv
    adc_init();
   
    adc_config(ADC_CHL_VBAT, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);
    adc_power_open(ADC_VBG);
    adc_divided_enable();
    adc_enable(0x1);
    
    while(!(get_SDMADC_Reg0x7_Sadc_Status&0x01));
 
    data_buff[0] =(int16_t) addSDMADC_Reg0x8;
    //vbat(mv)= 1000*(adc/16 - b)/k * 9/4;  b = -241,k = 820; 
    vbat_volt = (((data_buff[0]) - s_sdadc_b_div*16) * 1000) / (s_sdadc_k_div * 16);
    uart_printf("ADC.Vbat = %d,%d(mv),%x\n", data_buff[0],vbat_volt,get_SDMADC_Reg0x7_Sadc_Status);
    set_SDMADC_Reg0x2_soft_rst(0);
    addSDMADC_Reg0x7=get_SDMADC_Reg0x7_Sadc_Status;
    
    adc_enable(0x0);
    
    adc_divided_disable();
    adc_power_close();
    return vbat_volt;//data_buff[0];
}


void prepare_adc(ADC_CHNL chnl)
{
	adc_init();
   
	adc_config(chnl, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);
	adc_power_open(ADC_VBG);
	adc_divided_disable();
}

int16_t get_prepare_data(void)
{
	int16_t vbat_volt = 0; // mv
	
	adc_enable(0x1);
    
	while(!(get_SDMADC_Reg0x7_Sadc_Status&0x01));

	data_buff[0] =(int16_t) addSDMADC_Reg0x8;
	vbat_volt = (((data_buff[0]) - s_sdadc_b*16) * 1000)/(s_sdadc_k*16);
	//uart_printf("ADC.GPIO = %d,%d(mv),%x\n", data_buff[0],vbat_volt,get_SDMADC_Reg0x7_Sadc_Status);
	set_SDMADC_Reg0x2_soft_rst(0);
	addSDMADC_Reg0x7=get_SDMADC_Reg0x7_Sadc_Status;
	
	adc_enable(0x0);
	adc_power_close();
	return vbat_volt;//data_buff[0];
}

int16_t get_gpio_chnl_data(ADC_CHNL chnl)
{
    //uart_printf("%s\r\n",__func__);
    int16_t vbat_volt = 0; // mv
    adc_init();
   
    adc_config(chnl, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);
    adc_power_open(ADC_VBG);
    adc_divided_disable();
    adc_enable(0x1);
    
    while(!(get_SDMADC_Reg0x7_Sadc_Status&0x01));
 
    data_buff[0] =(int16_t) addSDMADC_Reg0x8;
    vbat_volt = (((data_buff[0]) - s_sdadc_b*16) * 1000)/(s_sdadc_k*16);
    //uart_printf("ADC.GPIO = %d,%d(mv),%x\n", data_buff[0],vbat_volt,get_SDMADC_Reg0x7_Sadc_Status);
    set_SDMADC_Reg0x2_soft_rst(0);
    addSDMADC_Reg0x7=get_SDMADC_Reg0x7_Sadc_Status;
    
    adc_enable(0x0);
    adc_power_close();
    return vbat_volt;//data_buff[0];
}
#if(ADC_TEST)
void test_adc_gpio(uint8_t chn,uint8_t sample_mode,uint8_t vref)
{
    uint32_t i,x,y;
    int16_t tmpbuf[8];
    int16_t data_buff_tmp;
    uint8_t cunt,uart_cmd=0;
    adc_en =1;
    //uart0_init(115200);
    //clear_uart1_buffer();
    
    while(1)
    {
        uart_printf("gpio_adc_start__________\r\n");
        //for(cunt=0;cunt<8;cunt++)
        {
            adc_init();
            adc_int_enable();
            cnt = 0;
            int_flg = 0;
            if(sample_mode ==ADC_SMP_STEP )
            {
                adc_config(chn, ADC_SMP_STEP, ADC_SMP_STEP_END_INT);
            }
            else
            {
                adc_config(chn, ADC_SMP_CONTINUOUS, ADC_SMP_FIFO_FULL_SOON_INT);
            }
            adc_power_open(vref);
            adc_enable(0x1);
            while(!int_flg);
            int_flg = 0;
            if(sample_mode ==ADC_SMP_STEP )
            {
                #if (ADC_VER_EN)  //verify the adc
                data_buff_tmp = (data_buff[0]>>4)+ADC_B;

                uart_printf("SETP_ADC_ %d : ADC = %4d, V = %10d\r\n",chn,data_buff[0]>>4,(data_buff_tmp*1000)/ADC_A);   

                #else
                uart_printf("SETP_ADC_ %d = %d\r\n",chn,data_buff[0]>>4/*,data_buff[0]>>4*/);   
                #endif
            }
            else
            {
                uart_printf("CON_ADC_CNT_%x = %d:\r\n",chn,cnt);
                for(i=0;i<1000;i++){
                    uart_printf("%2d,",(int16_t)(data_buff[i]>>4));
                        }
                uart_printf("\r\n");
                for(i=0;i<1000;i++){
                    uart_printf("%2x,",(int16_t)(data_buff[i]>>4));
                }
                uart_printf("\r\n");
                while(1)
                {
                    if(uart1_rx_done)
                    {
                        return;
                    }
                }
            }
        }
     
        #if (ADC_BKREG) 
        while(1)
        {
            if(uart_rx_done)
            {
                uart_rx_done = 0;
                cunt=0;
                do
                {
                    uart_cmd = uart_rx_handler(uart_rx_buf[cunt++]);
                }
                while (uart_cmd);

                clear_uart_buffer();
            }
            if(uart1_rx_done)
            {
                uart1_rx_done =0;
                clear_uart1_buffer();
                int_flg = 0;
                cnt = 0;
                set_SDMADC_Reg0x2_soft_rst(1);
                adc_enable(0x1);
                while(!int_flg);
                int_flg = 0;
                uart_printf("SETP_ADC_ %d = %d,0x%x\r\n",chn,data_buff[0],data_buff[0]); 
            }
        }
        #else
        for( y = 0; y < 300; y ++ )
        {
            for(x = 0; x < 2260; x++)
            {
                if(uart1_rx_done)
                {
                    return;
                }
            }
        }
        #endif
    }
}
void test_sdmadc_audio(void)
{
    uint32_t i,x,y;
    clear_uart1_buffer();
    while(1)
    {
        uart_printf("mic_adc_start__________\r\n");
        adc_init();
        adc_int_enable();
        cnt = 0;
        int_flg = 0;
        adc_config(ADC_CHL_MICP, ADC_SMP_CONTINUOUS, ADC_SMP_FIFO_FULL_SOON_INT);
        adc_power_open(ADC_VBG);
        adc_enable(0x1);
        while(!int_flg);
        int_flg = 0;
        uart_printf("MIC ADC CNT = %d:\r\n",cnt);
        for(i=0;i<1000;i++){
            uart_printf("%4d\r\n",(int16_t)(data_buff[i]));
        }
        uart_printf("\r\n");
        for(i=0;i<1000;i++){
            uart_printf("%4x,",(int16_t)(data_buff[i]));
        }
        uart_printf("\r\n");
        while(1)
        {
            if(uart1_rx_done)
            {
                return;
            }
        }
    }
}

void test_adc(uint8_t chn,uint8_t sample_mode,uint8_t vref)
{
    uart_printf("==============ADC_TEST ==============\r\n");
    uart_printf("==============CHN6 :Vmcu ==============\r\n");
    uart_printf("==============CHN7 :MIC ==============\r\n");

    uart_printf("==============TEST_ADC_CHN is %d ==============\r\n",chn);
    uart_printf("==============TEST_ADC_Vref is %d ==============\r\n",vref);
    uart_printf("       0 : ADC_VBG12     \r\n");
    uart_printf("       1 : ADC_VDD*0.4     \r\n");


    if(sample_mode)
        uart_printf("==========TEST_ADC_MODE is ADC_SMP_STEP ==========\r\n");
    else
        uart_printf("========TEST_ADC_MODE is ADC_SMP_CONTINUOUS ========\r\n");
  

    if(chn<ADC_CHL_MICP)
    {
        test_adc_gpio(chn,sample_mode,vref);
    }
    else
    {
        test_sdmadc_audio();
    }
 //   test_adc_3chn(sample_mode,vref);
}

void test_adc_3chn_cmd(uint8_t vref)
{
    uart_printf("==============ADC_3CHN_TEST ==============\r\n");
    uart_printf("==============CHN3,4,5 ==============\r\n");

    uart_printf("==============TEST_ADC_Vref is %d ==============\r\n",vref);
    uart_printf("       0 : ADC_VBG12     \r\n");
    uart_printf("       1 : ADC_VDD*0.4     \r\n");


    uart_printf("==========TEST_ADC_MODE is ADC_SMP_STEP ==========\r\n");
  

    test_adc_3chn(vref);
}
void adc_config_test(ADC_SMP_MODE mode, ADC_INT_MODE int_mode)
// the adc buf len is  32B
{
    uint32_t smp_num = 0x0;
    uint8_t cic2_bypass=0;
    gpio_config(ADC_CHL_3+1, SC_FUN, PULL_NONE);
    gpio_scfun_sel(ADC_CHL_3+1, 3);
    gpio_config(ADC_CHL_4, SC_FUN, PULL_NONE);
    gpio_scfun_sel(ADC_CHL_4+1, 3);
    gpio_config(ADC_CHL_5, SC_FUN, PULL_NONE);
    gpio_scfun_sel(ADC_CHL_5+1, 3);

    smp_num = 0;//0x3;
    
    cic2_bypass = 1;
    addSDMADC_Reg0x5 = 0x00000000;

    addSDMADC_Reg0x5 |= (mode << posSDMADC_Reg0x5_Sample_Mode)
                        | (smp_num << posSDMADC_Reg0x5_Sample_Numb)
                        | (ADC_CHL_3 << posSDMADC_Reg0x5_Sample_Chsel)
                        | (cic2_bypass << posSDMADC_Reg0x5_Cic2_Bypass)
                        | (0x1 << posSDMADC_Reg0x5_Comp_Bypass)
                        | (0x2D << posSDMADC_Reg0x5_Cic2_Gains)
                        | (int_mode << posSDMADC_Reg0x5_Intr_Enable);

    addSDMADC_Reg0x6 |= (0x0 << posSDMADC_Reg0x6_Cali_Offset)
                        | (0x1000 << posSDMADC_Reg0x6_Cali_Gain);
}
void test_adc_chg_chn(uint8_t chn)
{
    addSDMADC_Reg0x5 &= ~(0xf<<posSDMADC_Reg0x5_Sample_Chsel);
    addSDMADC_Reg0x5 |= chn<<posSDMADC_Reg0x5_Sample_Chsel;
    addSDMADC_Reg0x7 =0xffffffff;
    set_SDMADC_Reg0x4_Sample_Enable(1);

}
void test_adc_3chn(uint8_t vref)
{
    uint32_t i,x,y,j;
    int16_t tmpbuf[8];
    int16_t tmpbuf1[8];
    int32_t adc_sum;
    uint8_t cunt,uart_cmd=0;
    adc_en =1;
    uart0_init(115200);
    clear_uart1_buffer();
    while(1)
    {
    //    uart_printf("gpio_adc_start__________\r\n");
      //  for(cunt=0;cunt<8;cunt++)
        adc_init();
        adc_int_enable();
        // debug IO
        gpio_config(0x20,OUTPUT,PULL_NONE);
        gpio_set(0x20,0);
        // 
        cnt = 0;
        int_flg = 0;
        
        adc_config_test( ADC_SMP_STEP, ADC_SMP_INT_NULL);

        adc_power_open(vref);
         adc_sum = 0;
        while(1)
        {
 //   uart_printf("SETP_ADC00= %d,%d,%d\r\n",ADC_CHL_3,tmpbuf[0],addSDMADC_Reg0x8>>4,addSDMADC_Reg0x8>>4);   
       
        gpio_set(0x20,1);
        test_adc_chg_chn(ADC_CHL_3);
        while(!(get_SDMADC_Reg0x7_Sadc_Status & 0x1));
        gpio_set(0x20,0);
        tmpbuf1[0] = (int16_t) addSDMADC_Reg0x8;
        tmpbuf[0] = tmpbuf1[0]>>4;
     //   tmpbuf[0] = (int16_t) addSDMADC_Reg0x8>>4;
      /*  for(i=1;i<8;i++)
            adc_sum += (int16_t) addSDMADC_Reg0x8>>4;
        tmpbuf[0] = (int16_t)(adc_sum /7);
        adc_sum = 0;*/
    //    
    //    tmpbuf[0] = (int16_t) addSDMADC_Reg0x8>>4;
        gpio_set(0x20,1);
        test_adc_chg_chn(ADC_CHL_4);
        while(!(get_SDMADC_Reg0x7_Sadc_Status & 0x1));
        gpio_set(0x20,0);
        tmpbuf1[1] = (int16_t) addSDMADC_Reg0x8;
        tmpbuf[1] = tmpbuf1[1]>>4;
     //   tmpbuf[1] = (int16_t) addSDMADC_Reg0x8>>4;
      /*  for(i=1;i<8;i++)
            adc_sum += (int16_t) addSDMADC_Reg0x8>>4;
        tmpbuf[1] = (int16_t)(adc_sum /7);
        adc_sum = 0;*/
     //   tmpbuf[1] = (int16_t) addSDMADC_Reg0x8>>4;
    //    tmpbuf[1] = (int16_t) addSDMADC_Reg0x8>>4;
        gpio_set(0x20,1);
        test_adc_chg_chn(ADC_CHL_5);
        while(!(get_SDMADC_Reg0x7_Sadc_Status & 0x1));
        gpio_set(0x20,0);
        tmpbuf1[2] = (int16_t) addSDMADC_Reg0x8;
        tmpbuf[2] = tmpbuf1[2]>>4;
   //     tmpbuf[2] = (int16_t) addSDMADC_Reg0x8>>4;
      /*  for(i=1;i<8;i++)
            adc_sum += (int16_t) addSDMADC_Reg0x8>>4;
        tmpbuf[2] = (int16_t)(adc_sum /7);
        adc_sum = 0;*/
     //   tmpbuf[2] = (int16_t) addSDMADC_Reg0x8>>4;
      //  tmpbuf[2] = (int16_t) addSDMADC_Reg0x8>>4;
        uart_printf("SETP_ADC_ORG= %4d  ,%4d  ,%4d \r\n",tmpbuf1[0],tmpbuf1[1],tmpbuf1[2]); 
        uart_printf("SETP_ADC_ver= %4d  ,%4d  ,%4d \r\n",tmpbuf[0],tmpbuf[1],tmpbuf[2]); 
        uart_printf("SETP_ADC_Vcc= %4d  ,%4d  ,%4d \r\n",(tmpbuf[0]+ADC_B)*1000/ADC_A,(tmpbuf[1]+ADC_B)*1000/ADC_A,(tmpbuf[2]+ADC_B)*1000/ADC_A);   
        uart_printf("===============\r\n");   
        Delay_ms(2000);
 
        for( y = 0; y < 300; y ++ )
        {
            for(x = 0; x < 2260; x++)
            {
                if(uart1_rx_done)
                {
                    return;
                }
            }
        }
        }
    }
  
}
#endif

