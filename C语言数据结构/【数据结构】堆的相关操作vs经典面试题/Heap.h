#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//////////////////////////////////////////����ز�������̬˳���ṹ��////////////////////////////////////////

typedef int HDataType;
typedef struct HeapNode
{
	HDataType* data;
	int size;
	int capacity;

}Heap;

//������
void HeapInit(Heap* hp, HDataType* arr, int size);
//����
void HeapDestory(Heap* hp);

//��������
void HeapPush(Heap* hp, HDataType x);
//ɾ������
void HeapPop(Heap* hp);
//�Ѷ�Ԫ��
HDataType HeapTop(Heap* hp);
//�п�
int HeapEmpty(Heap* hp);
//�ѵĴ�С
int HeapSize(Heap* hp);

//��ӡ
void HeapPrint(Heap* hp);
//����
void testHeap();


//////////////////////////////////////////�Ѿ���������////////////////////////////////////////

#endif //__HEAP_H__