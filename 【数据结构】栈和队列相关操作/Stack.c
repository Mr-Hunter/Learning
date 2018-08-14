#include "Stack.h"

//��ʼ��
void StackInit(Stack* pStack)
{
	assert(pStack);
	
	pStack->top = 0;
	pStack->data = (DataType*)malloc(sizeof(DataType)*3);
	assert(pStack->data);

	pStack->capacity = 3;

}
//����
void StackDestory(Stack* pStack)
{
	assert(pStack&&pStack->data);
	if (pStack->data)
	{
		free(pStack->data);
		pStack->data = NULL;
		pStack->capacity = 0;
		pStack->top = 0;
	}

}

//��ջ
void StackPush(Stack* pStack, DataType x)
{
	assert(pStack);
	if (pStack->top == pStack->capacity)
	{
		DataType* tmp = NULL;
		tmp = (DataType*)realloc(pStack->data, sizeof(DataType)*(pStack->capacity) + 3);
		assert(pStack->data);
		pStack->data = tmp;
		pStack->capacity += 3;

	}
	pStack->data[pStack->top++] = x;

}
//��ջ
void StackPop(Stack* pStack)
{
	//assert(pStack);
	assert(pStack->data);
	assert(pStack->top > 0);
	pStack->top--;
}
//ȡջ��Ԫ��
DataType StackTop(Stack* pStack)
{
	//assert(pStack);
	assert((pStack->data)&&(pStack->top > 0));
	return pStack->data[pStack->top - 1];
}
//�п�
int StackEmpty(Stack* pStack)
{
	assert(pStack);
	return pStack->top == 0;
}
//ջ�Ĵ�С
int StackSize(Stack* pStack)
{
	assert(pStack);
	return pStack->top;
}



void testStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}

	StackDestory(&s);
}