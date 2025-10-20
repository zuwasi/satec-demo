#ifndef _RF_XVR_H_
#define _RF_XVR_H_
#include <stdbool.h>
#include <string.h>
#include "icu.h"

#define TEMP_MIN    -40
#define TEMP_MAX    130
#define CODE_MIN    325
#define CODE_MAX    4955
struct temp_map_t
{
    int16_t code;
    uint8_t adj_ldo;
    uint8_t volt;
    uint8_t crystal;
    int16_t temp;
};
void rc32k_calib_software(void);
void xtal_set_cal(uint8_t cal_data);
void rc32k_calib(void);
void rc32k_calib_hw(void);
void rf_debug_gpio_init(uint8_t mode);
void single_wave_config(uint8_t freq, uint8_t power_level);
void rc32k_calib_soft(void);
void rc32k_calib_manu(uint16_t c_data, uint16_t f_data);
void set_power(uint8_t power_level);
void xtal_tempe_compensation(void);
void IF_filter_cali(void);
void fcc_hopping(uint8_t freq);

#endif

