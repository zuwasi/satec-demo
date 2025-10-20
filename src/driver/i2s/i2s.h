#ifndef _DRIVER_I2S_H_
#define _DRIVER_I2S_H_

#define I2S_SRC_CLK  16000000
#define I2S_DIV_441K_1PPM   932
#define I2S_DIV_48K_1PPM    1014
#define con_I2S_support_datawidth   16 // 16 24

#define I2S_FIFO_DEPTH_QUARTER          0
#define I2S_FIFO_DEPTH_HALF             1
#define I2S_FIFO_DEPTH_THREE_QUAR       2

enum
{
    I2S_MODE_I2S = 0,
    I2S_MODE_LEFT_JUST = 1,
    I2S_MODE_RIGHT_JUST = 2,
    I2S_MODE_SHORT_SYNC = 4,
    I2S_MODE_LONG_SYNC = 5,
    I2S_MODE_NORMAL_2B_D = 6,
    I2S_MODE_DELAY_2B_D = 7
};
enum
{
    I2S0=0,
    I2S_Unk,
};



#if (con_I2S_support_datawidth== 16)
//27<==>52.29K,30<==>47K,29<==>48K
#define con_I2S_LRC_48000       32    //29
#define con_I2S_LRC_44100       32
#define con_I2S_LRC_48000_44100       32
//#define con_I2S_LRC_44100       35
#define con_I2S_LRC_16000       96
#define con_I2S_LRC_8000        192
#elif (con_I2S_support_datawidth== 24)
#define con_I2S_LRC_48000_44100       21
//#define con_I2S_LRC_44100       23
#define con_I2S_LRC_16000       64
#define con_I2S_LRC_8000        128
#elif (con_I2S_support_datawidth== 32)
#define con_I2S_LRC_48000_44100       16
//#define con_I2S_LRC_44100       17
#define con_I2S_LRC_16000       48
#define con_I2S_LRC_8000        96
#endif

/*
*1.sel:device number:0~2
*2.sr:sample rate
*3.br:bit rate
*4.mode:0=slave,1=master
*/
void i2s_init(int sel,int sr,int br,int mode);

/*
*1、i2s FIFO SIZE IS 32*2=64bytes;
*2、cnt set is 32
*/
int i2s_send(void*dat,int cnt);

/*
*1、i2s FIFO SIZE IS 32*2=64bytes;
*2、cnt set is 64
*/
void i2s_send0(void*dat,int cnt);

/*
*1、i2s FIFO SIZE IS 32*2=64bytes;
*2、cnt set is 32
*/
int i2s_rcv(void*dat,int cnt);

/*
*i2s adjust sample
*1.i_d:1=adjust fast��0=adjust slow
*/
void i2s_adjust_lrclk(int i_d);
void i2s_close(void);
void i2s_isr(void);
void test_i2s(void);
void test_i2s_dma(void);
void i2s_txdma_isr(uint8_t type);
void i2s_rxdma_isr(uint8_t type);

#endif
