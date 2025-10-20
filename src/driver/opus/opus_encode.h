//
// Created by zhaojianxing on 19-01-23.
//

#ifndef _OPUS_ENCODE_H
#define _OPUS_ENCODE_H

#include "opus.h"
#include "stdio.h"
#include "stdarg.h"

/*
  设备端一次请求编码流程：
  opus_encode_init-->aivs_opus_encode_stream--->aivs_opus_encode_destroy
*/

int opus_encode_init(void);
/*
  pInputData：编码数据。采样格式为S16_LE
  inputDataLen: pInputData 数据长度
  pOutputData:编码输出结果数据.内存由调用者分配和释放。
  outputLen:编码结果pOutputData长度.用户据此长度发送内容pOutputData,或者缓存多个pOutputData一起发送。
  inputDataLen 长度除非最后一个报文 否则必须为640 防止不满帧数据插值导致音频数据杂音
*/
int opus_encode_stream(const char* pInputData, int inputDataLen, unsigned char* pOutputData, int* outputLen);
void opus_encode_destroy(void);

#endif //_OPUS_ENCODE_H