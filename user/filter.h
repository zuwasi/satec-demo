#ifndef _FILTER_H_
#define _FILTER_H_

#include "user_config.h"


typedef struct{
    int32_t tf;
    unsigned int timestamp_prev;
    int32_t y_prev;
}LPF_t_fixed;

int32_t LPF_Handler_q15(LPF_t_fixed *lpf, int32_t x);
void LPF_Init_q15(LPF_t_fixed *lpf,int32_t tf);

#endif