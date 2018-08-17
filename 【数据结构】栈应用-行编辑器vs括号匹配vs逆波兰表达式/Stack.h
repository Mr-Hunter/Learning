#ifndef __STACK_H__
#define __STACK_H__
/**************************************************************
*                         ��̬˳��ջ						  *
***************************************************************/
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>

typedef char DataType;
typedef struct Stack
{
	DataType* data;
	int top;
	int capacity;
}Stack;

//��ʼ��
void StackInit(Stack* pStack);
//����
void StackDestory(Stack* pStack);

//��ջ
void StackPush(Stack* pStack, DataType x);
//��ջ
void StackPop(Stack* pStack);
//ȡջ��Ԫ��
DataType StackTop(Stack* pStack);
//�п�
int StackEmpty(Stack* pStack);
//ջ�Ĵ�С
int StackSize(Stack* pStack);

//void testStack();


#endif //__STACK_H__
