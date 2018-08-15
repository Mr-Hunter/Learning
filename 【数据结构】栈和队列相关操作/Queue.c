#include "Queue.h"

//��ͷ���Ķ���
/*//��ʼ��
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pNode = (DataType*)malloc(sizeof(DataType));//ͷ���
	pNode->pNext = NULL;
	pQueue->front = pQueue->rear = pNode;
}
//����
void QueueDestory(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front->pNext;
	while (pCur)
	{
		QueueNode* pDel = pCur;
		pQueue->front->pNext = pDel->pNext;
		free(pDel);
		pDel = NULL;
		pCur = pQueue->front->pNext;
	}
	free(pQueue->front);
	pQueue->front = NULL;

}

QueueNode* BuyNode(DataType x)
{
	QueueNode* ptr = (DataType*)malloc(sizeof(DataType));
	assert(ptr);
	ptr->data = x;
	ptr->pNext = NULL;
	return ptr;
}
//���
void QueuePush(Queue* pQueue, DataType x)
{
	assert(pQueue);
	QueueNode* back = BuyNode(x);
	pQueue->rear->pNext = back;
	pQueue->rear = back;

}
//����
void QueuePop(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pDel = pQueue->front->pNext;
	pQueue->front->pNext = pDel->pNext;
	
	if (pDel == pQueue->rear)
	{
		pQueue->rear = pQueue->front;
	}
	free(pDel);
	pDel = NULL;

}
//ȡ��ͷԪ��
DataType QueueTop(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front->pNext->data;

}
//�п�
int QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front->pNext == NULL;;

}
//�ӵĴ�С
int QueueSize(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front->pNext;
	int len = 0;
	while (pCur)
	{
		len++;
		pCur = pCur->pNext;

	}
	return len;

}*/


///////////////////////////////��ͷ���/////////////////////////////
//��ʼ��
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	pQueue->front = NULL;
	pQueue->rear = NULL;
}

//����
void QueueDestory(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front;
	while (pCur)
	{
		QueueNode* next = pCur->pNext;
		free(pCur);
		pCur = next;
	}
	pQueue->front = pQueue->rear = NULL;
}

QueueNode* BuyNode(DataType x)
{
	QueueNode* ptr = (QueueNode*)malloc(sizeof(QueueNode));
	assert(ptr);
	ptr->data = x;
	ptr->pNext = NULL;
	return ptr;
}

//���
void QueuePush(Queue* pQueue, DataType x)
{
	assert(pQueue);
	if (pQueue->rear == NULL)
	{
		QueueNode* node = BuyNode(x);
		 pQueue->rear = node;
		 pQueue->front = pQueue->rear;
	}
	else
	{
		QueueNode* node = BuyNode(x);
		pQueue->rear->pNext = node;
		pQueue->rear = node;
	}
}

//����
void QueuePop(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front->pNext;
	free(pQueue->front);
	pQueue->front = pCur;

	if (pCur == NULL)
	{
		pQueue->rear = NULL;
	}

}

//ȡ��ͷԪ��
DataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front->data;
}

//ȡ��βԪ��
DataType QueueBack(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->rear->data;

}

//�п�
int QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front == NULL;
}

//�ӵĴ�С
int QueueSize(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front;
	int len = 0;
	while (pCur)
	{
		len++;
		pCur = pCur->pNext;
	}
	return len;
}


//����
void testQueue()
{
	Queue q;

	QueueInit(&q);
	QueuePush(&q, 5);
	QueuePush(&q, 4);
	QueuePush(&q, 3);
	QueuePush(&q, 2);

	printf("���еĴ�С��%d\n",QueueSize(&q));
	printf("����Ԫ�أ�%d\n", QueueFront(&q));


	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestory(&q);
}

