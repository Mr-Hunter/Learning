#include "Topic.h"

///////////////////////////////����ջʵ�ֶ���////////////////////////////////
void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	assert(qts);
	StackInit(&qts->s1);
	StackInit(&qts->s2);
}
void QueueByTwoStackDestory(QueueByTwoStack* qts)
{
	assert(qts);
	StackDestory(&qts->s1);
	StackDestory(&qts->s2);

}

// ջs1�����ݣ�s2�����ݣ�
void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x)
{
	assert(qts);
	StackPush(&qts->s1, x);

}
//s2�����ݣ����������ֱ�ӳ������û�оʹ�s1�а����ݵ�����
void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEmpty(&qts->s2))
	{
		while (!StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackPop(&qts->s1);
		}
	}
	StackPop(&qts->s2);

}
DataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEmpty(&qts->s2))
	{
		while (!StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackPop(&qts->s1);
		}
	}
	return StackTop(&qts->s2);
}
int QueueByTwoStackEmpty(QueueByTwoStack* qts)
{
	assert(qts);
	return StackEmpty(&qts->s1)&StackEmpty(&qts->s2);
}
int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	assert(qts);
	return StackSize(&qts->s1) + StackSize(&qts->s2);
}

void testQueueByTwoStack()
{
	QueueByTwoStack stq;
	QueueByTwoStackInit(&stq);
	QueueByTwoStackPush(&stq, 1);
	QueueByTwoStackPush(&stq, 2);
	QueueByTwoStackPush(&stq, 3);
	QueueByTwoStackPush(&stq, 4);
	QueueByTwoStackPop(&stq);

	QueueByTwoStackPush(&stq, 5);
	QueueByTwoStackPush(&stq, 6);
	QueueByTwoStackPush(&stq, 7);
	QueueByTwoStackPush(&stq, 8);

	printf("%d", QueueByTwoStackSize(&stq));

	while (!QueueByTwoStackEmpty(&stq))
	{
		printf("%d ", QueueByTwoStackFront(&stq));
		QueueByTwoStackPop(&stq);
	}
	QueueByTwoStackDestory(&stq);
}

///////////////////////////////��������ʵ��ջ////////////////////////////////

void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);
	QueueInit(&stq->q1);
	QueueInit(&stq->q2);
}
void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	assert(stq);
	QueueDestory(&stq->q1);
	QueueDestory(&stq->q2);

}
//��������ʵ��ջ����ʼ���ʱ��q1����q2��q2����q1���ǿն��ϲ������ݣ���һ���ӵ���ջʱ�Ļ�����
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{
	assert(stq);
	if (QueueEmpty(&stq->q1))
	{
		QueuePush(&stq->q2, x);
	}
	else
	{
		QueuePush(&stq->q1, x);
	}

}
//��ջʱ�����ǿն���ǰn-1���ݵ���նӣ���ԭ�ǿն��е�n�����ݳ���
void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	assert(stq);
	Queue *empty = &stq->q1, *noempty = &stq->q2;
	if (!QueueEmpty(&stq->q1))
	{
		empty = &stq->q2;
		noempty = &stq->q1;
	}
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	QueuePop(noempty);

}
DataType StackByTwoQueueFront(StackByTwoQueue* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->q1))
	{
		return QueueBack(&stq->q2);
	}
	else
		return QueueBack(&stq->q1);
}
int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueEmpty(&stq->q1)&QueueEmpty(&stq->q2);
}
int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueSize(&stq->q1) + QueueSize(&stq->q2);
}

void testStackByTwoQueue()
{
	StackByTwoQueue stq;
	StackByTwoQueueInit(&stq);
	StackByTwoQueuePush(&stq, 1);
	StackByTwoQueuePush(&stq, 2);
	StackByTwoQueuePush(&stq, 3);
	StackByTwoQueuePush(&stq, 4);
	StackByTwoQueuePop(&stq);

	StackByTwoQueuePush(&stq, 5);
	StackByTwoQueuePush(&stq, 6);
	StackByTwoQueuePush(&stq, 7);
	StackByTwoQueuePush(&stq, 8);

	printf("%d     ", StackByTwoQueueSize(&stq));

	while (!StackByTwoQueueEmpty(&stq))
	{
		printf("%d ", StackByTwoQueueFront(&stq));
		StackByTwoQueuePop(&stq);
	}
	StackByTwoQueueDestory(&stq);


}