#include "Topic.h"

//////////////// 1.Ҫ��ʵ��Min(������Сֵ)��ʱ�临�Ӷ�ΪO(1)////////////////////
/*ͨ����װһ���ṹ�壬�ṹ���е�һ��Ԫ�ط�ֵ���ڶ���Ԫ�ط���Сֵ��
���ṹ����뵽ջ�У�����������Сֵ��ʱ���ջ��ȡ�ṹ�壬�ٴӽṹ����ȡ����Сֵ*/


//ջ�ĳ�ʼ��
void MStackInit(MinStack* ms)
{
	assert(ms);
	StackInit(&ms->s);
}
//��ջ
void MStackPush(MinStack* ms, MDataType data)
{
	assert(ms);
	SElem elem;
	//�Ȱ�Ԫ�ص�ֵ����Сֵ��data�����
	elem.data = elem.mindata = data;
	if (!StackEmpty(&ms->s))
	{
		//ȡջ�������Сֵ
		MDataType minData = GetMinData(ms);
		//����Сֵ�ȷ��������С���и���
		if (minData < data)
		{
			elem.mindata = minData;
		}
	}
	//��elemѹջ
	StackPush(&ms->s, elem);
}

//��ջ
void MStackpop(MinStack* ms)
{
	assert(ms);
	assert(!MStackEmpty(ms));
	StackPop(&ms->s);
}
//�ж�ջ�Ƿ�Ϊ��
int MStackEmpty(MinStack* ms)
{
	assert(ms);
	return StackEmpty(&ms->s);
}
//ȡջ��Ԫ��
MDataType MStackTop(MinStack* ms)
{
	assert(ms);
	return StackTop(&ms->s).data;
}
//ȡջ�Ĵ�С
MDataType MStackSize(MinStack* ms)
{
	assert(ms);
	return StackSize(&ms->s);
}
//ȡ��Сֵ
MDataType GetMinData(MinStack* ms)
{
	assert(ms);
	return StackTop(&ms->s).mindata;
}

///////////////////////////////2.����ջʵ�ֶ���////////////////////////////////
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

///////////////////////////////3.��������ʵ��ջ////////////////////////////////

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

////////////////////////4.Ԫ�س�ջ����ջ�ĺϷ��ԡ�//////////////////////////
//����ջ�����У�1,2,3,4,5������ջ����Ϊ��4,5,3,2,1�� 
/*�����������飬һ���ǽ���ջ��������һ���ǳ�ջ˳�򣬴���һ��ջ��������ջ����������
ѹ��ջ��,���������кͳ�ջ���еĵ�һ��Ԫ����ͬʱ���������Ԫ�أ�ͬʱ��ջ���У����
�ߣ���Ԫ���Ѿ��ɹ���ջ����ʱ����ջ���л���Ԫ�ؼ����ظ�����������ֱ�������һ��Ԫ��
Ҳ��ջ,��ʱջ��ʣ�µ�Ԫ��λ���Ѿ��̶���ֻ�ܴ�ջ�����ε�����ÿ�ε���ǰջ��Ԫ�غ͵�������Ԫ
�رȽ�����������������ͬʱ������������ƶ���һ��ջ��Ԫ�غ͵������в���ȣ�˵��
��������Ҫ������Ԫ�ز���ջ��,�����޷����������Ծ��ǷǷ���������������ظ�
����������ֱ��ջ�е�Ԫ����ĿΪ0����ջ�գ�֤���������кϷ�*/

int Check(int *stack_in, int *stack_out, int len_in, int len_out)
{
	Stack s;
	StackInit(&s);
	assert(stack_in && stack_out);
	//�������г��Ȳ���ȣ����Ϸ�  
	if (len_in != len_out)
		return 0;
	
	int j = 0;
	int i = 0;
	for (; i < len_in; i++)
	{
		StackPush(&s, stack_in[i]);
		//��ջ����ջ��Ԫ���뵱ǰ��ջ����Ԫ�ز���ȣ����Ϸ�  
		while (StackSize(&s) > 0 && StackTop(&s) == stack_out[j])
		{
			StackPop(&s);
			j++;
		}
	}

	//�����г�ջ����Ԫ�ض�ƥ����֮��ջ��Ϊ�գ����Ϸ�
	return (StackSize(&s)>0) ? 0 : 1;
}


void testInWithOut()
{
	int stack_in[] = { 1, 2, 3, 4, 5 };       //��ջ����  
	int stack_out[] = { 4, 5, 3, 2, 1 };      //��ջ����  
	int len_in = sizeof(stack_in) / sizeof(stack_in[0]);      //��ջ���г���  
	int len_out = sizeof(stack_out) / sizeof(stack_out[0]);   //��ջ���г���  
	int ret = Check(stack_in, stack_out, len_in, len_out);
	if (ret == 1)
		printf("�Ϸ�\n");
	else
		printf("���Ϸ�\n");

}


/////////////////////////5.һ������ʵ������ջ������ջ��/////////////////////////////

void SharedStackInit(SharedStack* s)
{
	s->top1 = 0;
	s->top2 = MAXSIZE - 1;
}

// ��ջ 
void SharedStackPush(SharedStack* s, int data, int flag)
{
	if (s->top2 <= s->top1)
		return;

	if (1 == flag)
		s->data[s->top1++] = data;
	else
		s->data[s->top2--] = data;
}

// ��ջ 
void SharedStackPop(SharedStack* s, int flag)
{
	if (SharedStackEmpty(s, flag))
		return;

	if (1 == flag)
		s->top1--;
	else
		s->top2++;
}

// ��ȡջ��Ԫ�� 
int SharedStackTop(SharedStack* s, int flag)
{
	assert(!SharedStackEmpty(s, flag));
	if (1 == flag)
		return s->data[s->top1 - 1];
	else
		return s->data[s->top2 + 1];
}

// ��ЧԪ�صĸ��� 
int SharedStackSize(SharedStack* s, int flag)
{
	if (1 == flag)
		return s->top1;
	else
		return MAXSIZE - s->top2 - 1;
}

// ���ջ�Ƿ�Ϊ�� 
int SharedStackEmpty(SharedStack* s, int flag)
{
	if (1 == flag)
		return 0 == s->top1;
	else
		return MAXSIZE - 1 == s->top2;
}