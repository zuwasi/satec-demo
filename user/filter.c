#include "filter.h"

void LPF_Init_q15(LPF_t_fixed *lpf,int32_t tf){
	lpf->tf=tf;
	lpf->y_prev=0;
    lpf->timestamp_prev = Systick_GetTick();
}

int32_t LPF_Handler_q15(LPF_t_fixed *lpf, int32_t x){
	int32_t y,a,b;

    a=FIXED_POINT_MULT(FLOAT_TO_FIXED(0.9f), lpf->y_prev);
    b=FIXED_POINT_MULT(FLOAT_TO_FIXED(0.1f), x);
    y = FIXED_POINT_MULT(FLOAT_TO_FIXED(0.9f), lpf->y_prev) + FIXED_POINT_MULT(FLOAT_TO_FIXED(0.1f), x);
#if DEBUG_MOTOR
    //logn("%s: x=%d,lpf->y_prev=%d,y=%d,a=%d,b=%d",__func__,x,lpf->y_prev,y,a,b);
#endif
    lpf->y_prev = y;
    return y;
}

int32_t LPF_Handler_q15_old(LPF_t_fixed *lpf, int32_t x){
    unsigned long timestamp = Systick_GetTick();
    int32_t dt;
	int32_t alpha;
	int32_t y;

#if OVERFLOW_DETECT
    logn("%s: FLOAT_TO_FIXED,%d",__func__,FLOAT_TO_FIXED(Systick_TickDiff(timestamp,lpf->timestamp_prev) *SYSTICK_ONE_CLK_TS * 1e-6f));
#endif
	dt=FLOAT_TO_FIXED(Systick_TickDiff(timestamp,lpf->timestamp_prev) *SYSTICK_ONE_CLK_TS * 1e-6f);	
#if DEBUG_MOTOR
    dt=FLOAT_TO_FIXED(0.00002f);
#endif
    if (dt < 0 ){ 
		dt = FLOAT_TO_FIXED(0.0003);
    }else if(dt > FLOAT_TO_FIXED(0.2)) {
        lpf->y_prev = x;
        lpf->timestamp_prev = timestamp;
        return x;
    }

#if USE_FIXED_DIV
    alpha = fixed_point_div(lpf->tf, (lpf->tf + dt));
#else
    alpha = FLOAT_TO_FIXED(lpf->tf / (lpf->tf + dt));
#endif
#if OVERFLOW_DETECT
    logn("%s: %d,%d",__func__,FIXED_POINT_MULT(alpha, lpf->y_prev),FIXED_POINT_MULT(FLOAT_TO_FIXED(1.0f) - alpha, x));
#endif
    y = FIXED_POINT_MULT(alpha, lpf->y_prev) + FIXED_POINT_MULT(FLOAT_TO_FIXED(1.0f) - alpha, x);
#if DEBUG_MOTOR
    logn("%s: lpf->tf=%d,dt=%d,alpha=%d,x=%d,lpf->y_prev=%d,y=%d",__func__,lpf->tf,dt,alpha,x,lpf->y_prev,y);
#endif
    lpf->y_prev = y;
    lpf->timestamp_prev = timestamp;
    //logn("%d,%d,%d",lpf->tf,alpha,y);
    return y;
}
