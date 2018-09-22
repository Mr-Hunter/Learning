#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct BitMapNode
{
	char* bit; //ָ��Nλ��ɵĿռ�
	size_t N; //�ܵ�λ��
}BitMap;

void BitMapInit(BitMap* pbm,size_t len);
void BitMapDestroy(BitMap* pbm);

void BitMapSet(BitMap* pbm, int x);
void BitMapReset(BitMap* pbm, int x);
int BitMapTest(BitMap* pbm, int x);
void TestBitMap();






#endif //__BITMAP_H__