#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;

//����ͷ��㵥����
typedef struct Node
{
	DataType data;
	struct Node* pNext;
}Node,List,*pNode,*pList;

//��ʼ��
void InitList(pList* pplist);
//��ӡ
void PrintList(pList pplist);
//��������
void DestoryList(pList* pplist);

//β��
void  PushBack(pList* pplist, DataType d);
//βɾ
void PopBack(pList* pplist);
//ͷ��
void  PushFront(pList* pplist, DataType d);
//ͷɾ
void PopFront(pList* pplist);

//�����
void Insert(pList* pplist,pNode pos, DataType d);
//����ɾ��
void Erase(pList* pplist,pNode pos);

//ɾ��ָ��Ԫ��
void ReMove(pList* pplist, DataType d);
//ɾ��ָ��Ԫ�� (����)
void ReMove_OP(pList* pplist, DataType d);
//ɾ��ָ������Ԫ��
void ReMoveAll(pList* pplist, DataType d);


//����
pNode Find(pList pplist,DataType d);
//���
void Clear(pList* pplist);
//�����С
int Size(pList pplist);

 




#endif//__LIST_H__