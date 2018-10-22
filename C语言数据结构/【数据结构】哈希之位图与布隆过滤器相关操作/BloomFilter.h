#ifndef __BLOOMFILTER_H__

#define __BLOOMFILTER_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BitMap.h"


typedef char* DataType;
typedef struct BloomFilterNode
{
	BitMap Bloom;
}BloomFilter;


//��¡��������ʼ��
void BloomFilterInit(BloomFilter* bf,size_t len);
//��¡����������
void BloomFilterDestroy(BloomFilter* bf);


//��¡����������
void BloomFilterSet(BloomFilter* bf, DataType x);
//��¡����������
void BloomFilteReset(BloomFilter* bf, DataType x);	//��֧��
//��¡����������
int BloomFilterTest(BloomFilter* bf, DataType x);

 //����
void TestBloomFilter();



#endif //__BLOOMFILTER_H__