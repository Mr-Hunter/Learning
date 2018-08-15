#ifndef __TOPIC_H__
#define __TOPIC_H__

#include "Stack.h"
#include "Queue.h"

/******************************************************************************
*                           ջ��������������                               *
*******************************************************************************/

///////////////////////////////////////////////////////////////////////
//1.ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��pop(��ջ)��Min(������Сֵ)��ʱ�临�Ӷ�ΪO(1)


typedef int MDataType;
//�ṹ�壬��һ��Ԫ�ط�ֵ���ڶ���Ԫ�ط���Сֵ
typedef struct SElem
{
	MDataType data;
	MDataType mindata;
}SElem;//ջ��ŵ�Ԫ��Ϊ�ṹ��SElem

typedef struct MinStack
{
	Stack s;
}MinStack;

//��ʼ��
void MStackInit(MinStack* ms);
//��ջ
void MStackPush(MinStack* ms, MDataType data);
//��ջ
void MStackpop(MinStack* ms);
//�ж�ջ�Ƿ�Ϊ��
int MStackEmpty(MinStack* ms);
//ȡջ��Ԫ��
MDataType MStackTop(MinStack* ms);
//ȡ����С��Ԫ��
MDataType GetMinData(MinStack* ms);
//ջ�Ĵ�С
MDataType MStackSize(MinStack* ms);


///////////////////////////////////////////////////////////////////////
//2.����ջʵ��һ������
typedef struct  QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);
void QueueByTwoStackDestory(QueueByTwoStack* qts);

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x);
void QueueByTwoStackPop(QueueByTwoStack* qts);
DataType QueueByTwoStackFront(QueueByTwoStack* qts);
int QueueByTwoStackEmpty(QueueByTwoStack* qts);
int QueueByTwoStackSize(QueueByTwoStack* qts);
void testQueueByTwoStack();

///////////////////////////////////////////////////////////////////////
//3.��������ʵ��һ��ջ
typedef struct  StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x);
void StackByTwoQueuePop(StackByTwoQueue* stq);
DataType StackByTwoQueueFront(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);

void testStackByTwoQueue();


///////////////////////////////////////////////////////////////////////
// 4.Ԫ�س�ջ����ջ�ĺϷ��ԡ�����ջ�����У�1,2,3,4,5������ջ����Ϊ��4,5,3,2,1��
int Check(int *stack_in, int *stack_out, int len_in, int len_out);
void testInWithOut();

 
///////////////////////////////////////////////////////////////////////
// 5.һ������ʵ������ջ������ջ��

#define MAXSIZE 10
//��������ʵ��һ������ջ����һ��ջ�Ǵ�ǰ������ջ���ڶ�ջ��Ԫ�شӺ���ǰ��
typedef struct SharedStack
{
	int data[MAXSIZE];
	int top1;	  //��ջ��
	int top2;	  //��ջ��
}SharedStack;

//flagΪ�ж���������ջ ���涨1Ϊ��ջ��0Ϊ��ջ

void SharedStackInit(SharedStack* s);

// ��ջ 
void SharedStackPush(SharedStack* s, int data, int flag);
// ��ջ 
void SharedStackPop(SharedStack* s, int flag);
// ��ȡջ��Ԫ�� 
int SharedStackTop(SharedStack* s, int flag);
// ��ЧԪ�صĸ��� 
int SharedStackSize(SharedStack* s, int flag);
// ���ջ�Ƿ�Ϊ�� 
int SharedStackEmpty(SharedStack* s, int flag);

#endif // __TOPIC_H__