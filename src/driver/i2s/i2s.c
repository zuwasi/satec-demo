#include <stddef.h>
#include"BK3437_RegList.h"
#include"driver_gpio.h"
#include"dma.h"
#include"user_config.h"
#include "i2s.h"


#if(I2S_DRIVER)

#define WAV_BUFF_SIZE  320
const int tblSrSup8K[]={ 16000,32000};

#pragma pack(4)
static volatile int16_t tblTestWav[WAV_BUFF_SIZE];
//static volatile int16_t tblTestRxWav[320];
#pragma pack()
static void*tx_dmac=NULL;
static void*rx_dmac=NULL;


void i2s_en_irq(int en_dis)
{
    clrf_SYS_Reg0x11_int_i2s_pri;
    if(en_dis)
    {
        setf_SYS_Reg0x10_int_i2s_en;
    }
    else 
    {
        clrf_SYS_Reg0x10_int_i2s_en;
    }
}
void i2s_en_clock(int en_dis)
{
    if(en_dis)
        clrf_SYS_Reg0x3_i2s_pwd;
    else 
        setf_SYS_Reg0x3_i2s_pwd;
    set_SYS_Reg0x1e_ahb_clk_gate_disable(0x1);
}

void i2s_en_port(int en_dis)
{
    uint8_t bclk,lrck,din,dout;
    uint8_t func=2;
    Dir_Type s=SC_FUN;
    if(en_dis==0)
    {
        func=0;
        s=INPUT;
    }

    bclk=4;lrck=5;din=2;dout=3;
    gpio_config(bclk,s, PULL_NONE);    //BCLK
    gpio_config(lrck,s, PULL_NONE);    //LRCK(WS)
    gpio_config(din,s, PULL_NONE);    //DIN
    gpio_config(dout,s, PULL_NONE);    //DOUT
    gpio_scfun_sel(bclk,func);
    gpio_scfun_sel(lrck,func);
    gpio_scfun_sel(din,func);
    gpio_scfun_sel(dout,func);
}

void i2s_port_init()
{
    i2s_en_clock(1);
    i2s_en_port(1);
}


void i2s_deinit(void)
{
    i2s_en_clock(0);
    i2s_en_port(0);
}
void i2s_close( void )
{
    i2s_en_irq(0);
    clrf_I2S0_Reg0x1_RXINT_EN;
    clrf_I2S0_Reg0x1_RXOVF_EN;
    clrf_I2S0_Reg0x1_TXUDF_EN;
    clrf_I2S0_Reg0x1_TXINT_EN;
    // I2S_REG(REG_I2S2_PCM_CN) &= ~(MSK_I2S2_PCM_CN_TXINT_EN | MSK_I2S2_PCM_CN_TXUDF_EN
    //                     |MSK_I2S2_PCM_CN_RXINT_EN | MSK_I2S2_PCM_CN_RXOVF_EN);
    clrf_I2S0_Reg0x0_I2SPCMEN;
    // I2S_REG(REG_I2S2_PCM_CTRL) &= ~MSK_I2S2_PCM_CTRL_PCMEN;
    i2s_deinit();
}
static int isIn(int a,void*tbl,int cnt)
{
    int*ptbl=(int*)tbl;
    int i;
    for(i=0;i<cnt;i++)
    {
        if(a==ptbl[i])return(i);
    }
    return(-1);
}

void i2s_open( uint32_t freq, uint16_t datawidth,int mod)
{
    uint32_t bitratio;
    int smp;
    if((isIn(freq,(void*)tblSrSup8K,sizeof(tblSrSup8K)/sizeof(tblSrSup8K[0]))<0))
    {
        uart_printf("I2S freq can't Supported\r\n");
        while(1);
    }
    // if( datawidth != 16 && datawidth != 32)return;
    //注意:i2时钟源是apb clk,=16000000
    //因为3437 I2S的16M时钟源按照全bit的方式分不出正好32K的频率，所以需要冗余bit来对齐采样率
    //I2S的基本频率：Fb=(Fsrc/4)=4M，4M/32K=125,16~32之间125的因数只有25，所以用25作为采样率控制因子
    smp=25;
    bitratio=(I2S_SRC_CLK/4)/(smp*freq);

    // bitratio=0x10;//(I2S_SRC_CLK/2)/(freq);
    // if(freq == 8000){
    //     bitratio = con_I2S_LRC_8000;
    // }else if(freq == 16000){
    //     bitratio = con_I2S_LRC_16000;
    // }else if(freq == 44100){
    //     //bitratio = con_I2S_LRC_48000_44100;
    //     bitratio = con_I2S_LRC_44100;
    // }else if(freq == 48000){
    //     //bitratio = con_I2S_LRC_48000_44100;
    //     bitratio = con_I2S_LRC_48000;
    // }
    //关闭I2S
    clrf_I2S0_Reg0x0_I2SPCMEN;

    addI2S0_Reg0x0 = (((mod&0x01) << posI2S0_Reg0x0_MSTEN)
                    | (I2S_MODE_LEFT_JUST<< posI2S0_Reg0x0_MODESEL)
                    | (1 << posI2S0_Reg0x0_LRCKRP)
                    | (((datawidth - 1)&0x1f) << posI2S0_Reg0x0_DATALEN)//配置samp的字宽，bits of per sample
                    | (((smp - 1)&0x1f) << posI2S0_Reg0x0_SMPRATIO)
                    | (bitratio << posI2S0_Reg0x0_BITRATIO));//配置bclk分频数
                    //i2s fifo容量为每声道20bytes，共40bytes
    addI2S0_Reg0x1 |= ((1 << posI2S0_Reg0x1_RXFIFO_CLR)
                    |(1 << posI2S0_Reg0x1_TXFIFO_CLR)
                    | ( 1 << posI2S0_Reg0x1_TXINT_LEVEL)//配置i2s发送剩余sample数小于该值时中断，n*8
                    | ( 1 << posI2S0_Reg0x1_RXINT_LEVEL));//配置i2s接收到sample数大于该值时中断，n*8

    #if I2S_DMA_DRIVER==0
    if(mod&1)setf_I2S0_Reg0x1_TXINT_EN;
    setf_I2S0_Reg0x1_RXINT_EN;
    addI2S0_Reg0x2 = 0x0000FFFF;//清除所有i2s中断标志
    setf_I2S0_Reg0x0_I2SPCMEN;
    uart_printf("i2s0=%x\r\n",addI2S0_Reg0x0);
    i2s_en_irq(1);
    #else
    setf_I2S0_Reg0x0_I2SPCMEN;
    #endif
}

void i2s_adjust_lrclk(int i_d)
{
    uint32_t reg=addI2S0_Reg0x0;//I2S_REG(REG_I2S2_PCM_CTRL);
    uint32_t regt=reg&0xff;
    reg&=0xffffff00;
    if(i_d)
    {//调快i2s
        regt=32;//con_I2S_LRC_48000-1;//48.xK
    }
    else
    {//调慢i2s
        regt=33;//con_I2S_LRC_48000;//47K
    }
    reg|=regt;
    addI2S0_Reg0x0=reg;//I2S_REG(REG_I2S2_PCM_CTRL)=reg;
}

void i2s_init(int sel,int sr,int br,int mode)
{
    i2s_port_init();
    i2s_open(sr, br,mode);
}

void i2s_send0(void*dat,int cnt)
{
    int16_t *p=(int16_t*)dat;
    // int i=0;
    cnt/=sizeof(int16_t);
    while(cnt--)
    {
        //while((REG_I2S2_PCM_STAT&(1<<5))==0);
        addI2S0_Reg0x3=*p++;//I2S_REG(REG_I2S2_PCM_DAT)=*p++;
    }
}

int i2s_send(void*dat,int cnt)
{
    int16_t *p=(int16_t*)dat;
    int i=0;
    cnt/=sizeof(int16_t);
    while(cnt--)
    {
        if(get_I2S0_Reg0x2_TXINT)
        {
            addI2S0_Reg0x3=*p++;
        }
        else 
        {
            // break;
            while(get_I2S0_Reg0x2_TXFIFO_WR_READY==0);
            addI2S0_Reg0x3=*p++;
        }
        i++;
    }
    return i;
}

int i2s_rcv(void*dat,int cnt)
{
    int16_t *p=(int16_t*)dat;
    int i=0;
    cnt/=sizeof(int16_t);
    while(cnt--)
    {
        if(get_I2S0_Reg0x2_RXINT)
        {
            *p++=addI2S0_Reg0x3;
        }
        else 
        {
            // break;
            while(get_I2S0_Reg0x2_RXFIFO_RD_READY==0);//((I2S_REG(REG_I2S2_PCM_STAT)&(1<<4))==0);
            *p++=addI2S0_Reg0x3;
        }
        i++;
    }
    return i;
}

void i2s_isr(void)
{
    uint32_t sts = addI2S0_Reg0x2;//I2S_REG(REG_I2S2_PCM_STAT);
    // uart_printf("%s sta=%x\r\n",__func__,sts);
    if(sts & bitI2S0_Reg0x2_TXUDF)
    {
        setf_I2S0_Reg0x2_TXUDF;
        // I2S_REG(REG_I2S2_PCM_STAT) |= MSK_I2S2_PCM_STAT_TXUDF;
    }
    if(sts & bitI2S0_Reg0x2_RXOVF)
    {
        setf_I2S0_Reg0x2_RXOVF;
        // I2S_REG(REG_I2S2_PCM_STAT) |= MSK_I2S2_PCM_STAT_RXOVF;
    }
    if(sts & (bitI2S0_Reg0x2_RXINT))
    {
        uint8_t buf[64];
        i2s_rcv(buf, sizeof(buf));
        // aud_play_buf(buf,sizeof(buf));
    }
    if(sts & (bitI2S0_Reg0x2_TXINT))
    {
        // spk_dat_out();
        i2s_send((void*)tblTestWav,sizeof(tblTestWav));    
    }
}

int i2s_dma_setup(){
    ///设置tx dma
    tx_dmac=dma_channel_malloc();
    if(tx_dmac==NULL)
        return(-1);
    dma_channel_config(
                    tx_dmac,
                    I2S0_REQ_TX,
                    DMA_MODE_REPEAT,
                    (uint32_t)tblTestWav,
                    (uint32_t)tblTestWav+WAV_BUFF_SIZE*2,
                    DMA_ADDR_AUTO_INCREASE,
                    DMA_DATA_TYPE_LONG,
                    (uint32_t)&addI2S0_Reg0x3,
                    (uint32_t)&addI2S0_Reg0x3,
                    DMA_ADDR_NO_CHANGE,
                    DMA_DATA_TYPE_SHORT,
                    WAV_BUFF_SIZE*2);
    //tx_dmacInd=dma_channel_get_index(tx_dmac);
    //uart_printf("txIdx=%d\r\n",tx_dmacInd);
    dma_channel_src_curr_address_set(tx_dmac,(uint32_t)tblTestWav+WAV_BUFF_SIZE*2);
 
    i2s_en_irq(0);
    clrf_I2S0_Reg0x1_TXINT_EN;
    clrf_I2S0_Reg0x1_RXINT_EN;

    dma_channel_set_int_type(tx_dmac,1);
    dma_channel_set_int_type(tx_dmac,2);
    dma_channel_set_completed_cbk(tx_dmac,i2s_txdma_isr);
 
    //dma_channel_set_completed_cbk(rx_dmac,i2s_rxdma_isr);
    return 1;
}

void i2s_send_dma(void*buf,int len)
{
    //dma_channel_link_src(tx_dmac,(uint32_t)buf,len);
    dma_channel_enable(tx_dmac,1);
}

void i2s_rcv_dma(void*buf,int len)
{
    //dma_channel_link_dst(rx_dmac,(uint32_t)buf,len);
    dma_channel_enable(rx_dmac,1);
}

void test_i2s()
{
    int i;
    for(i=0;i<WAV_BUFF_SIZE;i++)
    {
        tblTestWav[i]=i;
    }
    i2s_send0((void*)tblTestWav,WAV_BUFF_SIZE);
}

void test_i2s_dma()
{
    i2s_dma_setup();

    int i;
    for(i=0;i<WAV_BUFF_SIZE;i++)
    {
        tblTestWav[i]=i;/////test data
    }
    i2s_send_dma((int*)tblTestWav,WAV_BUFF_SIZE);
}

void i2s_txdma_isr(uint8_t type)
{
    uint16_t i;
    if(type==INT_TYPE_HALF)
    {
        for( i=0;i<(WAV_BUFF_SIZE/2);i++)
        {
            tblTestWav[i]=0x6000+i;///test data
        }
    }
    else if(type==INT_TYPE_END)
    {
        for( i=(WAV_BUFF_SIZE/2);i<WAV_BUFF_SIZE;i++)
        {
            tblTestWav[i]=0x1000+i;///test data
        }
    }
}

void i2s_rxdma_isr(uint8_t type)
{
    //i2s接收结束处理
    //i2s_rcv_dma(tblTestRxWav,sizeof(tblTestRxWav));
}


#endif
