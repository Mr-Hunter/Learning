#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <string.h>

typedef int DataType;
#define DEFAULE_MAX 3

typedef struct SeqList
{
	DataType* data;
	size_t size;
	size_t capacity;
}SeqList, *pSeqList;

//��ʼ��
void Init(pSeqList pSeq);
//����
void Destory(pSeqList pSeq);
//��ӡ
void PrintSeqList(pSeqList pSeq);

//β��
void PushBack(pSeqList pSeq, DataType d);
//βɾ
void PopBack(pSeqList pSeq);

//ͷ������
void PushFront(pSeqList pSeq, DataType d);
//ͷ��ɾ��
void PopFront(pSeqList pSeq);

//����
int Find(pSeqList pSeq, DataType d);
//ָ���������루�ڼ�����
void Insert(pSeqList pSeq, size_t pos, DataType d);
//ָ���±�ɾ��
void Erase(pSeqList pSeq, size_t pos);
//ɾ��ָ��Ԫ��
void ReMove(pSeqList pSeq, DataType d);
//ɾ������ָ��Ԫ��
void ReMoveAll(pSeqList pSeq, DataType d);
//����˳����С
int Size(pSeqList pSeq);
//�ж�˳����Ƿ�Ϊ��
int IsEmpty(pSeqList pSeq);
//ð������
void BubbleSort(pSeqList pSeq);
//ѡ������
void SelectSort(pSeqList pSeq);
//��������
int BinarySearch(pSeqList pSeq, DataType d);









#endif// __SEQLIST_H__