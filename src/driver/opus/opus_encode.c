#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//#include <unistd.h>
#include <time.h>
#include "opus_encode.h"

#include "Rwip_config.h"

/* support audio encode mode */
#define DEFAULT_PACKET_LOSS_PERC       0
#define DEFAULT_SAMPLING_RATE          (16*1000)
#define DEFAULT_SUPPORT_CHANNEL        1
#define DEFAULT_SAMPLE_BYTES           2
#define MAX_FRAME_SIZE                 1024
#define DEFAULT_MAX_PAYLOAD_BYTES      MAX_FRAME_SIZE
#define DEFAULT_FRAME_SIZE             320
#define NFRAME_HEAER                   5

static OpusEncoder *gOpusEncoder;
static int bitRates = 16000;

int os_printf(const char *fmt, ...);
void *jmalloc_s(unsigned int  size, unsigned short flags);
void jfree_s(void *item);

extern void *ke_malloc(uint32_t size, uint8_t type);
extern void ke_free(void* mem_ptr);

void* my_malloc(unsigned int size)
{
   // return 0;//jmalloc_s(size, 0);
     return ke_malloc(size, KE_MEM_NON_RETENTION);
}

void my_free(void* ptr)
{
    //jfree_s(ptr);
    ke_free(ptr);
}

int opus_encode_init(void)
{
    int err = 0;
    
    gOpusEncoder = (OpusEncoder *)opus_encoder_create(DEFAULT_SAMPLING_RATE, DEFAULT_SUPPORT_CHANNEL, OPUS_APPLICATION_RESTRICTED_LOWDELAY, &err);

    if ((NULL == gOpusEncoder) || (err != OPUS_OK))
    {
        //os_printf("opus_encode_init failed!\r\n");
        return -1;
    }
    
    opus_encoder_ctl(gOpusEncoder, OPUS_SET_VBR_REQUEST, 0);
    opus_encoder_ctl(gOpusEncoder, OPUS_SET_BITRATE_REQUEST, bitRates);
    opus_encoder_ctl(gOpusEncoder, OPUS_SET_SIGNAL_REQUEST, OPUS_SIGNAL_VOICE);
    opus_encoder_ctl(gOpusEncoder, OPUS_SET_COMPLEXITY_REQUEST, 0);
    
    return 0;
}

void opus_encode_destroy(void)
{
    if(gOpusEncoder)
    {
        opus_encoder_destroy(gOpusEncoder);
        gOpusEncoder = NULL;
    }
}

/*
  pInputData：编码数据。采样格式为S16_LE
  inputDataLen: pInputData 数据长度
  pOutputData:编码输出结果数据.内存由调用者分配和释放。
  outputLen:编码结果pOutputData长度.用户据此长度发送内容pOutputData,或者缓存多个pOutputData一起发送。
  inputDataLen 长度除非最后一个报文 否则必须为640 防止不满帧数据插值导致音频数据杂音 
*/
int opus_encode_stream(const char* pInputData, int inputDataLen, unsigned char* pOutputData, int* outputLen)
{
   if (NULL == pInputData || inputDataLen <= 0 || pOutputData == NULL || outputLen == NULL)
   // if (NULL == pInputData || inputDataLen <= 0 || pOutputData == NULL )
    {
        //os_printf("opus_encode_stream Error: param is invalid!\n");
        uart1printf("opus_encode_stream Error: param is invalid!\n");
        return -1;
    }
   
    *outputLen = opus_encode(gOpusEncoder, (opus_int16*)pInputData, DEFAULT_FRAME_SIZE, pOutputData, DEFAULT_MAX_PAYLOAD_BYTES);

    if(*outputLen < 0)
    {
        //os_printf("encode failed ###########");
        uart1printf("encode failed ###########");
        return -1;
    }
    
    return 0;
}
