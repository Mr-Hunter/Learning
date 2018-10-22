
#include "Sort.h"



//��������
//1.ֱ�Ӳ�������
void InsertSort(int* arr, int n)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < n - 1; ++i)
	{
		int end = i;
		int temp = arr[end + 1];
		while (end >= 0 && temp < arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end] = temp;

	}

	
}
//2.ϣ������
void ShellSort(int* arr, int n)
{
	//1.Ԥ���򣨽ӽ�����gapԽСԽ���򣬵��ǱȽϴ���Խ��Խ�ӽ���������gap����1��������
	//2.��������
	assert(arr);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int i = 0;
		for (i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0 && tmp < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}

}



//ѡ������
//1.ѡ������,��ֻ��һ��ѡһ�����˴��Ż�һ��ѡ����
void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;

}
void SelectSort(int* arr, int n)
{
	assert(arr);
	int begin = 0;
	int end = n - 1;

	int max = begin;
	int min = begin;

	while (begin < end)
	{
		int i = 0;
		for (i = begin; i <= end; ++i)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}

		if (min != begin)
		{
			Swap(&arr[min], &arr[begin]);
		}
		if (max == min)
		{
			max = min;
		}
		if (max != end)
		{
			Swap(&arr[max], &arr[end]);
		}

		end--;
		begin++;

	}

}
//2.������(���򽨴��)

void AdjustDown(int *arr,int size, int i)
{
	assert(arr);
	int parent = i;
	int child = i * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size&&arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}
void HeapSort(int* arr, int n)
{
	assert(arr);

	int i = 0;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(arr,n,i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(arr+0,arr+end);
		
		AdjustDown(arr,end,0);
		--end;

	}
}


//��������
//1.ð������

void BubbleSort(int* arr, int n)
{
	int flag = 0;
	int begin = 0;
	int end = n - 1;
	while (end > 0)
	{
		for (int i = 1; i <= end; ++i)
		{
			if (arr[i]<arr[i - 1])
			{
				Swap(arr+i,arr+i-1);
				flag = 1;
			}
		}
		if (0 == flag)
			break;
		--end;
	}

}


//2.��������
//����һ��
int PartSort1(int* arr, int begin, int end)
{
	assert(arr);
	int key = arr[end];
	int index = end;
	while (begin < end)
	{
		while (begin<end&&arr[begin] <= key)
		{
			begin++;
		}
		while (begin<end&&arr[end] >= key)
		{
			end--;
		}
		if (begin<end)
			Swap(&arr[begin],&arr[end]);
	}
	Swap(&arr[begin],&arr[index]);
	return begin;

}
//�������� �ڿӷ�
int PartSort2(int* arr, int begin, int end)
{
	assert(arr);

	int key = arr[end];
	while (begin < end)
	{
		while (begin < end&&arr[begin]<=key)
		{
			++begin;

		}
		arr[end] = arr[begin];
		while (begin<end&&arr[end]>=key)
		{
			--end;
		}
		arr[begin] = arr[end];

	}
	arr[begin] = key;
	return begin;

}
//������������ָ�뷨
int PartSort3(int* arr, int begin, int end)
{
	assert(arr);
	int key = arr[end];

	int pCur = begin;
	int pPre = begin - 1;
	while (pCur < end)
	{
		if (arr[pCur] <= key&&++pPre != pCur)
		{
			Swap(arr+pCur,arr+pPre);
		}

		++pCur;

	}
	Swap(&arr[++pPre], &arr[end]);
	return pPre;
	
}

//�ݹ�
void QuickSort(int* arr, int begin, int end)
{
	assert(arr);
	if (begin < end)
	{
		int ret = PartSort2(arr,begin,end);
		QuickSort(arr,begin,ret-1);
		QuickSort(arr,ret+1,end);

	}
}

/*//�ǵݹ�
void QuickSort(int* arr, int left, int right)
{
	assert(arr);

	stack<int> s;
	s.push(left);
	s.push(right);

	if (!s.empty())
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();

		int ret = PartSort(arr,begin,end);

		if (begin<ret-1)
		{
			s.push(begin);
			s.push(ret-1);

		}
		if (end>ret + 1)
		{
			s.push(ret+1);
			s.push(end);
		}

	}
}
	*/


//�鲢����
void Merge(int* arr, int begin1, int end1, int begin2, int end2, int*tmp)
{
	assert(arr&&tmp);
	int index = begin1;
	int start = begin1;
	int ret = end2 - begin1;

	while (begin1 < end1&&begin2 < end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];

	}

	while (begin1 < end1)
		tmp[index++] = arr[begin1++];
	while (begin2 < end2)
		tmp[index++] = arr[begin2++];
	memcpy(arr+start,tmp+start,sizeof(int)*(ret+1));
}
void _MergeSort(int* arr,int begin,int end,int* tmp)
{
	assert(arr&&tmp);

	if (begin >= end) return;

	int mid = begin + ((end-begin)>>1);

	_MergeSort(arr,begin,mid,tmp);
	_MergeSort(arr,mid+1,end,tmp);

	Merge(arr, begin, mid, mid + 1, end, tmp);

}
void MergeSort(int* arr, int n)
{
	assert(arr);

	int* tmp = (int*)malloc((sizeof(int))*n);
	assert(tmp);
	_MergeSort(arr,0,n-1,tmp);

	free(tmp);
	tmp = NULL;
}



void Print(int* arr, int n)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}								    

	printf("\n");
}

//��������
void CountSort(int* arr, int n)
{
	assert(arr);
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i]>max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int count = 0;
	count = max - min + 1;

	int* tmp = (int*)malloc(count*sizeof(int));
	assert(tmp);
	memset(tmp, 0, count*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		tmp[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < tmp[i]; j++)
		{
			arr[index++] = i + min;
		}
	}
}
