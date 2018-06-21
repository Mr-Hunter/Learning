#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <string.h >
#include <malloc.h>

#define MAX 100
typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	size_t size;
}SeqList, *pSeqList;

//��ʼ��
void InitSeqList(pSeqList pSeq);
//��ӡ��̬˳���
void PrintSeqList(pSeqList pSeq);
//β������
void PushBack(pSeqList pSeq, DataType d);
//β��ɾ��
void PopBack(pSeqList seq);
//ͷ������
void PushFront(pSeqList pSeq, DataType d);
//ͷ��ɾ��
void PoPFront(pSeqList pSeq);
//����
int Find(pSeqList pSeq, DataType d);
//ָ���������루�ڼ�����
void Insert(pSeqList pSeq, size_t pos, DataType d);
//ָ���±�ɾ��
void Erase(pSeqList pSeq,size_t pos);
//ɾ��ָ��Ԫ��
void ReMove(pSeqList pSeq,DataType d);
//ɾ������ָ��Ԫ��
void ReMoveAll(pSeqList pSeq, DataType d);
//����˳����С
int Size(pSeqList pSeq);
//�ж�˳����Ƿ�Ϊ��
int Empty(pSeqList pSeq);
//ð������
void BubbleSort(pSeqList pSeq);
//ѡ������
void SelectSort(pSeqList pSeq);
//��������
int BinarySearch(pSeqList pSeq, DataType d);



#endif  //__SEQLIST_H__