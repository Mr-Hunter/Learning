#ifndef __STACK_H__
#define __STACK_H__
/**************************************************************
*                         ��̬˳��ջ						  *
***************************************************************/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTreeNode* SDataType;
typedef struct Stack
{
	SDataType* data;
	int top;
	int capacity;
}Stack;

//��ʼ��
void StackInit(Stack* pStack);
//����
void StackDestory(Stack* pStack);

//��ջ
void StackPush(Stack* pStack, SDataType x);
//��ջ
void StackPop(Stack* pStack);
//ȡջ��Ԫ��
SDataType StackTop(Stack* pStack);
//�п�
int StackEmpty(Stack* pStack);
//ջ�Ĵ�С
int StackSize(Stack* pStack);
//����
void testStack();
 

#endif //__STACK_H__
