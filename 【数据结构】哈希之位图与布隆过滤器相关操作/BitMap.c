
#include "BitMap.h"

//λͼ��ʼ��
void BitMapInit(BitMap* pbm, size_t len)
{
	assert(pbm);
	//��һΪ��ʹ����Ϊĳ��Ѱַʱ��ͳһ��������ȡ��
	// ����lenΪ25,25/8=4������Ҫ5���ֽڲ��ܴ����
	pbm->bit = (char*)malloc(((len>>3)+1));
	assert(pbm->bit);
	memset(pbm->bit,0, (len>>3)+1);
	pbm->N = len;

}
//λͼ����
void BitMapDestroy(BitMap* pbm)
{
	assert(pbm);
	free(pbm->bit);
	pbm->bit = NULL;
	pbm->N = 0;

}

//λͼ
void BitMapSet(BitMap* pbm, size_t x)
{
	assert(pbm);
	int index = x >> 3;
	int num = x % 8;
	pbm->bit[index] |= (1<<num);
}
void BitMapReset(BitMap* pbm, size_t x)
{
	assert(pbm);
	int index = x >> 3;
	int num = x % 8;
	pbm->bit[index] &= ~(1<<num);
}

int BitMapTest(BitMap* pbm, size_t x)
{
	assert(pbm);
	int index = x >> 3;
	int num = x % 8;
	return pbm->bit[index]&(1<<num) == 1;
}
void TestBitMap()
{
	BitMap bm;
	BitMapInit(&bm,10);
	BitMapSet(&bm,78);
	BitMapSet(&bm, 99);
	BitMapSet(&bm, 55);
	BitMapSet(&bm, 76);

	BitMapSet(&bm,12);
	printf("  %d    ",BitMapTest(&bm,99));

	BitMapReset(&bm,78);
	printf("   %d    ",BitMapTest(&bm,78));



	BitMapDestroy(&bm);
}