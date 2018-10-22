#include "Heap.h"


//��������
static Swap(HDataType* x, HDataType* y)
{
	HDataType* tmp = *x;
	*x = *y;
	*y = tmp;
}

//��Ϊ�������һ����֧��ʼ���Ե�ǰ���Ϊ���ڵ����µ����������Խ������µ���
static AdjustDown(HDataType* hhp, int size, int i) //�������ѵĵ�ַ����С����ǰ��֧�ڵ�
{
	assert(hhp);
	int parent = i;
	int leftchild = parent * 2 + 1;
	while (leftchild<size)
	{
		//ѡ�����Һ��Ӵ��,ǰ���Һ��Ӵ���
		if (((leftchild + 1) < size) && (hhp[leftchild] < hhp[leftchild + 1]))
			leftchild++;
		if (hhp[parent] < hhp[leftchild])
		{
			Swap(&hhp[parent], &hhp[leftchild]);
			//������̽
			parent = leftchild;
			leftchild = parent * 2 + 1;
		}
		else
			break;
	}

}
//������ ���ѵĵ�һ���±�Ϊ0��  �������Ӷ�O(N)
void HeapInit(Heap* hp, HDataType* arr, int n)
{
	assert(hp&&arr);

	hp->data = (HDataType*)malloc(sizeof(HDataType)*n);
	hp->size = n;			
	hp->capacity = n;

	int i = 0;

	//�������Ĳ�α�������[����]
	for (i = 0; i < n; i++)
	{
		hp->data[i] = arr[i];
	}

	//���ѷ�Ϊ���С�ѣ��˴�ʵ�ֵĴ�ѡ�

	/*���ѣ�nΪԪ�ظ������ȼ�1�����Ҷ�ӽڵ���±꣬�ڼ�1��2�����һ����֧�ڵ㣨�����Ҷ�ӽڵ��˫�׽�㣩
	�������һ����֧��ʼ���Ե�ǰ���Ϊ���ڵ����µ�������������Ϻ��ٵ���ǰһ����֧�ڵ㣬
	 �����˴�ͷ��β�����Ĳ���Ҫ�鷳��ÿ���ڵ���ܻᱻ�����ö�Σ�*/
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		//��Ϊ�������һ����֧��ʼ���Ե�ǰ���Ϊ���ڵ����µ����������Խ������µ���
		//hp->data����Ϊʵ�ʶѣ�������Ϊ�ѵĵ�ַ
		AdjustDown(hp->data, hp->size, i); //�������ѵĵ�ַ����С����ǰ��֧�ڵ�
	}


}
//����
void HeapDestory(Heap* hp)
{
	assert(hp);
	hp->capacity = hp->size = 0;
	free(hp->data);
	hp->data = NULL;
	printf("���ٳɹ�\n");
}

//��Ϊ���ӽ�㡾��˫�ױȽϴ�С�����������ϵ���   0(log n)
static AdjustUp(HDataType* hhp, int size, int i)//�������ѵĵ�ַ����С����ǰ�ڵ�(���Ϊ���һ��Ҷ�ӽڵ�)
{
	assert(hhp);
	int parent = (i - 1) / 2;
	int child = i;
	while (child>0)
	{
		if (hhp[child]>hhp[parent])
		{
			Swap(&hhp[parent], &hhp[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}

}

//��������
void HeapPush(Heap* hp, HDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		HDataType* tmp = (HDataType*)realloc(hp->data,sizeof(HDataType)*(hp->capacity + 5));
		assert(tmp);
		hp->data = tmp;
		hp->capacity += 5;
		printf("���ݳɹ� ��ǰ����%d  \n",hp->capacity);
	}
	hp->data[hp->size++] = x;
	
	//��Ϊ���ӽ�㡾��˫�ױȽϴ�С�����������ϵ���
	AdjustUp(hp->data, hp->size, hp->size - 1);//�������ѵĵ�ַ����С����ǰ�ڵ�(���Ϊ���һ��Ҷ�ӽڵ�)
}
//ɾ������
void HeapPop(Heap* hp)
{
	assert(hp);
	//ֱ��ɾͷ��ͽ���������β��ͷ�������Ƚ�ͷ��β������β�����飬�ڶ�ͷ�������µ���
	//������β
	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->data, hp->size, 0);

}
//�Ѷ�Ԫ��
HDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->data[0];
}
//�п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
//�ѵĴ�С
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

//��ӡ
void HeapPrint(Heap* hp)
{
	int i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d  ",hp->data[i]);
	}
	printf("\n");
}
//����
void testHeap()
{
	Heap heap;
	HDataType arr[] = { 43, 56, 2, 78, 9, 14, 52, 65, 87, 23 };
	HeapInit(&heap, arr, sizeof(arr) / sizeof(HDataType));

	HeapPrint(&heap);

	printf("�ѵĴ�С��%d\n",HeapSize(&heap));
	printf("�Ѷ�Ԫ�أ�%d\n", HeapTop(&heap));
	printf("�Ƿ�Ϊ�գ� %d\n",HeapEmpty(&heap));

	HeapPush(&heap,99);
	HeapPrint(&heap);

	printf("�ѵĴ�С��%d\n", HeapSize(&heap));
	printf("�Ѷ�Ԫ�أ�%d\n", HeapTop(&heap));
	printf("�Ƿ�Ϊ�գ� %d\n", HeapEmpty(&heap));

	HeapPop(&heap);
	HeapPrint(&heap);
	printf("�ѵĴ�С��%d\n", HeapSize(&heap));
	printf("�Ѷ�Ԫ�أ�%d\n", HeapTop(&heap));
	printf("�Ƿ�Ϊ�գ� %d\n", HeapEmpty(&heap));

	HeapDestory(&heap);

}