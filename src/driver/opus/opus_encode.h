//
// Created by zhaojianxing on 19-01-23.
//

#ifndef _OPUS_ENCODE_H
#define _OPUS_ENCODE_H

#include "opus.h"
#include "stdio.h"
#include "stdarg.h"

/*
  �豸��һ������������̣�
  opus_encode_init-->aivs_opus_encode_stream--->aivs_opus_encode_destroy
*/

int opus_encode_init(void);
/*
  pInputData���������ݡ�������ʽΪS16_LE
  inputDataLen: pInputData ���ݳ���
  pOutputData:��������������.�ڴ��ɵ����߷�����ͷš�
  outputLen:������pOutputData����.�û��ݴ˳��ȷ�������pOutputData,���߻�����pOutputDataһ���͡�
  inputDataLen ���ȳ������һ������ �������Ϊ640 ��ֹ����֡���ݲ�ֵ������Ƶ��������
*/
int opus_encode_stream(const char* pInputData, int inputDataLen, unsigned char* pOutputData, int* outputLen);
void opus_encode_destroy(void);

#endif //_OPUS_ENCODE_H