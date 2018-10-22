#ifndef __PRACTICE_H__
#define __PRACTICE_H__

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>


typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* pNext;
}Node, *pNode,*pList;

typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* pNext;
	struct ComplexNode* pRandom;
}ComplexNode;

///////////////////////////////����ӿ�ʵ��/////////////////////////////////////////

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

////////////////////////////////������������////////////////////////////////////////

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
//ð������
void BubbleSort(pList* pplist);
//�ϲ�������������
pNode Merge(pList plist1,pList plist2);
pNode Merge_OP(pList plist1, pList plist2);
//Ѱ���м�ڵ�
pNode FindMiddle(pList plist);
//Ѱ�ҵ�����k�ڵ�
pNode FindRevers(pList plist, size_t k);
//�жϵ������Ƿ���������������󳤶�,����ڡ�
pNode IsWithCross(pList plist);
int GetCrossLenth(pList pMeet);
pNode CrossIn(pList plist, pList pMeet);
//�ж����������Ƿ��ཻ�����ཻ���󽻵�
int CheckCross(pList plist1, pList plist2);
pNode GetCrossNode(pList plist1, pList plist2);
//����������
ComplexNode* ComplexListCopy(ComplexNode head);

//����������Ľ���
void Union(pList plist1, pList plist2);
//����������Ĳ
void Difference(pList* plist1, pList plist2);
//����������Ĳ���
void Togeter(pList* plist1, pList plist2);









//


#endif //__PRACTICE_H__