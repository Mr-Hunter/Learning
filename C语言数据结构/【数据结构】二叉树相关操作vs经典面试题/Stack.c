#include "Stack.h"

//��ʼ��
void StackInit(Stack* pStack)
{
	assert(pStack);
	
	pStack->top = 0;
	pStack->data = (SDataType*)malloc(sizeof(SDataType)*3);
	assert(pStack->data);

	pStack->capacity = 3;

}
//����
void StackDestory(Stack* pStack)
{
	assert(pStack);

	free(pStack->data);
	pStack->data = NULL;
	pStack->capacity = 0;
	pStack->top = 0; 
}

//��ջ
void StackPush(Stack* pStack, SDataType x)
{
	assert(pStack);
	if (pStack->top == pStack->capacity)
	{
		SDataType* tmp = NULL;				    
		tmp = (SDataType*)realloc(pStack->data, sizeof(SDataType)*(pStack->capacity + 3));
		assert(tmp);
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
SDataType StackTop(Stack* pStack)
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

//
// //����
//void testStack()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//
//	printf("ջ�Ĵ�С��%d\n",StackSize(&s));
//	printf("ջ��Ԫ�أ�%d\n", StackTop(&s));
//
//	while(!StackEmpty(&s))
//	{
//		printf("%d ", StackTop(&s));
//		StackPop(&s);
//	}
//	printf("\n");
//	StackDestory(&s);
//}