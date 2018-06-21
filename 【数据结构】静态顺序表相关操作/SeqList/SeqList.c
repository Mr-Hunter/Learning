#define _CRT_SECURE_NO_WARNINGS 1
#include  "SeqList.h"

//��ʼ��
void InitSeqList(pSeqList pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}

//��ӡ��̬˳���
void PrintSeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
}

//β������
void PushBack(pSeqList pSeq, DataType d)
{	//����
	assert(pSeq);
	//����
	if (pSeq->size == MAX)
	{
		printf("Ϊ���޷�����\n");
		return;
	}
	//�洢
	pSeq->data[pSeq->size] = d;
	pSeq->size++;

}

//β��ɾ��
void PopBack(pSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("Ϊ�ղ���ɾ\n");
		return;
	}
	pSeq->size--;
}

//ͷ������
void PushFront(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == MAX)
	{
		printf("Ϊ���޷�����\n");
		return;
	}
	for (i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = d;
	pSeq->size++;

}

//ͷ��ɾ��
void PoPFront(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("Ϊ�ղ���ɾ\n");
		return;
	}
	for (i = 0; i < pSeq->size-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;

}

//����
int Find(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}

//ָ���������루�ڼ�����
void Insert(pSeqList pSeq, size_t pos, DataType d)
{
	int i = 0;
	assert(pSeq);
	assert(pos >= 0&& pos <= pSeq->size);
	if (pSeq->size == MAX)
	{
		printf("Ϊ���޷�����\n");
		return;
	}
	 
	//i>pos ���������
	//i>=pos ����������
	for (i = pSeq->size - 1; i >= pos; i--) 
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[i + 1] = pSeq->data[i];
	pSeq->data[i] = d;
	pSeq->size++;
}

//ָ���±�ɾ��
void Erase(pSeqList pSeq, size_t pos)
{
	int i = 0;
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);
	if (pSeq->size == 0)
	{
		printf("Ϊ�ղ���ɾ\n");
		return;
	}
	for (i = pos; i < pSeq->size; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;

}
//ɾ��ָ��Ԫ��
void ReMove(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("Ϊ�ղ���ɾ\n");
		return;
	}
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			break;
		}
	}
	if (i == pSeq->size)
	{
		printf("ɾ��Ԫ�ز�����");
		return;
	}
	for (; i < pSeq->size; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
}
//ɾ������ָ��Ԫ��
void ReMoveAll(pSeqList pSeq, DataType d)
{
	int i = 0;
	int count = 0;
	//DataType* tmp = (DataType*)malloc(sizeof(DataType)*pSeq->size);
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("Ϊ�ղ���ɾ\n");
		return;
	}

#if 0
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			int j = 0;
			for (j = i; j < pSeq->size; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->size--;
			i--;
		}
	}
#endif

#if	0
	
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] != d)
		{
			tmp[count++] = pSeq->data[i];
		}
	}
	memcpy(pSeq->data, tmp, count*sizeof(DataType));
	pSeq->size = count;
	free(tmp);
	tmp = NULL;

#endif

#if 1
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] != d)
		{
			pSeq->data[count++] = pSeq->data[i];
		}
	}
	pSeq->size = count;
#endif

}
//����˳����С
int Size(pSeqList pSeq)
{
	assert(pSeq);
	return pSeq->size;

}
//�ж�˳����Ƿ�Ϊ��
int Empty(pSeqList pSeq)
{
	assert(pSeq);
	return pSeq->size = 0;

}
//��������
static void Swap(DataType* a, DataType* b)
{
	DataType* tmp = NULL;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//ð������
void BubbleSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	int flag = 0;
	for (i = 0; i < pSeq->size - 1; i++)
	{
		for (j = 0; j < pSeq->size - i - 1; j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				//Swap(&pSeq->data[j], &pSeq->data[j + 1]);
				Swap(pSeq->data + j, pSeq->data + j + 1);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}

}
//ѡ������������Ƶ�����λ��
#if 0
void SelectSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size - 1; i++)
	{
		int max = 0;   //Ĭ������±�
		for (j = 1; j < pSeq->size-i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}
		if (max != pSeq->size - 1 - i)
		{
			Swap(pSeq->data + max, pSeq->data + pSeq->size - 1 - i);
		}
	}

}
#endif
//ѡ�������Ż���������������С
#if 1
void SelectSort(pSeqList pSeq)
{
	
	int start = 0;
	int end = pSeq->size - 1;
	assert(pSeq);

	while (start < end)
	{
		int max = start;
		int min = start;
		int i = 0;
		for (i = start; i <= end; i++)
		{
			if (pSeq->data[i] > pSeq->data[max])
			{
				max = i;
			}
			if (pSeq->data[i] < pSeq->data[min])
			{
				min = i;
			}
		}
		if (max != end)
		{
			Swap(pSeq->data + max, pSeq->data + end);
		}
		if (max == start)
		{
			max = min;
		}
		if (min != start)
		{
			Swap(pSeq->data + min, pSeq->data + start);
		}
			
		start++;
		end--;
		
	}

}
#endif

//��������ǵݹ�
#if 0
int BinarySearch(pSeqList pSeq, DataType d)
{
	int left = 0;
	int right = pSeq->size - 1;
	while (left <= right)
	{
		//...
		int mid = left + ((right - left)>>1);
		if (pSeq->data[mid] == d)
		{
			return mid;
		}
		else if (d < pSeq->data[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		 
	}
	return -1;
}
#endif

//���ֵݹ�
#if 0
int BinarySearch(pSeqList pSeq, int left, int right, DataType d)
{
	int mid = 0;
	if (left > right)
		return -1;
	mid = left + ((right - left) >> 1);
	if (pSeq->data[mid] == d)
	{
		return mid;
	}
	else if (pSeq->data[mid] > d)
		return BinarySearch(pSeq, left, mid - 1, d);
	else
		return BinarySearch(pSeq, mid + 1, right, d);

}
#endif
 


 