#ifndef __PRACTICE_H__
#define __PRACTICE_H__

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>




typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* pNext;
}Node, *pNode,*pList;


//�����ӡ�������ݹ飩
void ReversPrintLinkList(pList plist);
//�����ӡ�������ǵݹ飩
void ReversPrintLinkList_OP(pList pist);
//ɾ����������ͷ��β�ڵ�
void EraseWithoutHeadNotTail(pNode pos);
//����ͷ����ĳ�ڵ�ǰ�����һ���ڵ�
void InsertNodeToFront(pNode pos,DataType d);
//Լɪ�����⣺��ӡ���α�ɾ�����кŲ��������һ��
void JosephusCycle(pNode* pplist,size_t k);
//���õ�����
void ReversSingleLinkList(pList* pplist);









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
//����
pNode Find(pList pplist, DataType d);



#endif //__PRACTICE_H__