#ifndef _ADC_H_
#define _ADC_H_
#include "BK3437_RegList.h"
#include <stdint.h> 

typedef enum{
    ADC_CHL_0_TEMPERATURE=0,
    ADC_CHL_1=1,
    ADC_CHL_2=2,
    ADC_CHL_3=3,
    ADC_CHL_4=4,
    ADC_CHL_5=5,
    ADC_CHL_VBAT=6,
    ADC_CHL_MICP=7,
}ADC_CHNL;

typedef enum{
    ADC_SMP_CONTINUOUS,
    ADC_SMP_STEP
}ADC_SMP_MODE;

typedef enum{
    ADC_SMP_INT_NULL = 0,
    ADC_SMP_STEP_END_INT = 1,
    ADC_SMP_FIFO_FULL_INT = 2,
    ADC_SMP_FIFO_EMPTY_INT = 4,
    ADC_SMP_FIFO_FULL_SOON_INT = 8,
    ADC_SMP_FIFO_EMPTY_SOON_INT = 16
}ADC_INT_MODE;

typedef enum{
    ADC_SMP_MODE_SET,
    ADC_SMP_NUM_SET,
    ADC_SMP_CHNL_SET,
    ADC_CIC2_BYPASS_SET,
    ADC_COMP_BYPASS_SET,
    ADC_CIC2_GAINS_SET,
    ADC_INTR_EN_SET,
    ADC_CALI_OFFSET_SET,
    ADC_CALI_GAIN_SET
}ADC_CTRL_CMD;

#define ADC_B       235//7883
#define ADC_A       822//8004

typedef enum{ 
    ADC_VBG,
    ADC_VDD,
    ADC_2VBG,
    ADC_2Vdd
}ADC_REF_VADC;

typedef void (*adc_int_call_back)(void);

void adc_int_cb_register(adc_int_call_back cb);
void adc_init(void);
void adc_int_enable(void);
void adc_int_disable(void);
void adc_enable(uint32_t enable);
void adc_config(ADC_CHNL chnl, ADC_SMP_MODE mode, ADC_INT_MODE int_mode);
void adc_ctrl(ADC_CTRL_CMD cmd, uint32_t arg);
void test_sdmadc_audio(void);
void adc_isr(void);
void test_adc(uint8_t chn,uint8_t sample_mode,uint8_t vref);
void adc_power_open(ADC_REF_VADC v_sel);
int16_t get_temperature_sensor_data(void);
int16_t get_vbat_data(void);
void adc_get_calibration(void);
int16_t get_gpio_chnl_data(ADC_CHNL chnl);
#endif

