#include "BloomFilter.h"

int HashFunc1(DataType x)
{
	int index = 0;
	int *p = x;
	while (*p)
	{
		index = index * 131 + *p;
		p++;
	}
	return index;
}

int HashFunc2(DataType x)
{
	int index = 0;
	int *p = x;
	while (*p)
	{
		index = index * 1331 + *p;
		p++;
	}
	return index;
}

int HashFunc3(DataType x)
{
	int index = 0;
	int *p = x;
	while (*p)
	{
		index = index * 13322 + *p;
		p++;
	}
	return index;
}




//��¡��������ʼ��
void BloomFilterInit(BloomFilter* bf, size_t len)
{
	assert(bf);
	BitMapInit(&bf->Bloom, len * 5);

}
//��¡����������
void BloomFilterDestroy(BloomFilter* bf)
{
	assert(bf);
	BitMapDestroy(&bf->Bloom);
}


//��¡����������
void BloomFilterSet(BloomFilter* bf, DataType x)
{
	assert(bf);

	int hash1 = HashFunc1(x) % bf->Bloom.N;
	int hash2 = HashFunc2(x) % bf->Bloom.N;
	int hash3 = HashFunc3(x) % bf->Bloom.N;

	BitMapSet(&bf->Bloom, hash1);
	BitMapSet(&bf->Bloom, hash2);
	BitMapSet(&bf->Bloom, hash3);

}
//��¡����������
void BloomFilteReset(BloomFilter* bf, DataType x);	//��֧��
//��¡����������
int BloomFilterTest(BloomFilter* bf, DataType x)
{
	assert(bf);
	int hash1 = HashFunc1(x) % bf->Bloom.N;
	if (BitMapTest(&bf->Bloom, hash1) == 0)
	{
		return 0;
	}
	int hash2 = HashFunc2(x) % bf->Bloom.N;
	if (BitMapTest(&bf->Bloom, hash2) == 0)

	{
		return 0;
	}
	int hash3 = HashFunc3(x) % bf->Bloom.N;
	if (BitMapTest(&bf->Bloom, hash3) == 0)
	{
		return 0;
	}

	return 1;//���ǲ�ȷ���� 
}

//����
void TestBloomFilter()
{
	BloomFilter bf;
	BloomFilterInit(&bf, 10);

	BloomFilterSet(&bf, "scadcascs");
	BloomFilterSet(&bf, "school");
	BloomFilterSet(&bf, "urlur");
	BloomFilterSet(&bf, "sort");

	printf("%d\n", BloomFilterTest(&bf, "sdsd"));
	printf("%d\n", BloomFilterTest(&bf, "school"));
	printf("%d\n", BloomFilterTest(&bf, "sort"));

	BloomFilterDestroy(&bf);
}
