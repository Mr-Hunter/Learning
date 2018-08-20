#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/**************************************************************
*						    ��ʽ����						  *
***************************************************************/
typedef struct BinaryTreeNode* DataType;

typedef struct QueueNode
{
	DataType* data;
	struct QueueNode* pNext;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

//��ʼ��
void QueueInit(Queue* pQueue);
//����
void QueueDestory(Queue* pQueue);

QueueNode* BuyNode(DataType x);
//���
void QueuePush(Queue* pQueue, DataType x);
//����
void QueuePop(Queue* pQueue);
//ȡ��ͷԪ��
DataType QueueTop(Queue* pQueue);
//ȡ��βԪ��
DataType QueueBack(Queue* pQueue);
//�п�
int QueueEmpty(Queue* pQueue);
//�ӵĴ�С
int QueueSize(Queue* pQueue);
//����
void testQueue();



#endif//__QUEUE_H__
