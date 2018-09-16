
/*******************************************************************************************
*                                title:����ָoffer��֮ÿ������								*
*                                date : 2018.9.15                                           *
*                                By   : Hunter												*
********************************************************************************************/
//1.��˾��������
//�����������ø����ռ�����ÿ������ε�������Ȼ������ԭ��������

void AgeSort(int* age,int len)
{
	assert(age&&len>0);
	const int oldAge = 100;
	int ageTmp[oldAge+1];
	memset(ageTmp,0,sizeof(ageTmp));

	for (int i = 0; i < len; ++i)
	{
		if (age[i]<0 || age[i]>oldAge)
		{
			printf("��������\n");
			exit(1);
		}
		++ageTmp[age[i]];
	}

	int index = 0;
	for (int i = 0; i <= oldAge; ++i)
	{
		for (int j = 0; j < ageTmp[i]; ++j)
		{
			age[index] = i;
			index++;

		}
	}

}
//2.��ת��������С����
//����Ŀ������{3,4,5,1,2}��{1,2,3,4,5}��һ����ת���󷵻�ֵΪ1
//����������һ���������ʼ�ļ���Ԫ�ذᵽ����β�������ǳ�֮Ϊ�������ת��
//�������ǽ�������������Ϳ����ҵ���С���֣����Ӷ�Ϊo��n����û��������ת��������ԣ���Ȼ�ǲ�����Ҫ��ģ�
// ����ѡ�ö��ַ�����p1��p2�ֱ�ָ����β���ж��м���֮�Ĺ�ϵ������ֻ��˳�����

int Min(int* number, int len)
{
	assert(number&&len>0);
	int p1 = 0;
	int p2 = len - 1;
	int mid = p1;
	while (number[p1] >= number[p2])
	{
		if (p2 - p1 == 1)
		{
			mid = p2;
			break;
		}
		mid = p1 + ((p2 - p1) >> 1);
		//���p1,p2,mid��Ӧ��������ȣ������˳�����
		if (number[p1] == number[p2]
			&& number[p2] == number[mid])
			return OrderSearch(number, p1,p2);
		if (number[mid] >= number[p1])
			p1 = mid;
		else if (number[mid] <= number[p2])
			p2 = mid;

	}
	return number[mid];
}

int OrderSearch(int* number, int p1, int p2)
{
	int result = number[p1];
	for (int i = p1 + 1; i <= p2; ++i)
	{
		if (number[i] < result)
		{
			result = number[i];
		}

	}
	return result;
}

//3.쳲���������
//�ݹ飺Ч�ʵ���

long long fib(size_t n)
{
	return n < 2 ? n : (fib(n - 1) + fib(n - 2));
}
//β�ݹ�
long long fib(long long first, long long second, size_t n)
{
	if (n < 2)
		return n;
	if (n == 2)
		return 1;
	return fib(second, first + second, n - 1);
}


//����
long long fib(size_t n)
{
	/*if (n < 2)
		return n;
	int fibone = 0;
	int fibtwo = 1;
	int fib = 0;
	for (size_t i = 2; i <= n; ++i)
	{
		fib = fibone + fibtwo;
		fibone = fibtwo;
		fibtwo = fib;

	}*/
	if (n == 0)
		return 0;
	int fib = 0;
	int tmp = 1;
	for (size_t i = 1; i <= n; ++i)
	{
		fib += tmp;
		tmp = fib - tmp;
	}
	return fib;
}
//��ѽⷨ��o(nlogn)�ⷨ������˷��ӿ����ݼ��ɣ���

//Ӧ��1��С���θ��Ǿ���

//Ӧ��2��������̨�ױ���1�����ܿ�����һ�ڣ����������ڣ�������ܵ�n�ܹ�����
//�ⷨͬ쳲��������У�

//Ӧ��3��������̨�ӱ���2�����ܿ�����һ�ڣ�Ҳ���������ڻ�n�ڣ���n���ܹ�����
//��ѧ���ɷ�Ϊ 2^(n-1),��f(n) = f(n-1)+f(n-2)...+f��1��+1,Ϊ�˸��÷��ӵ��ƣ���f(0) = 1;
//���У�	f(n) = f(n-1)+f(n-2)...+f��1��+f(0);
long long fib(size_t n)
{	 
	if (n == 0)
		return 0;
	int fib = 0;
	int tmp = 1;
	for (size_t i = 1; i <= n; ++i)
	{
		fib += tmp;
		tmp = fib;
	}
	return fib;
}

//4.һ������������1�ĸ���
int NumberOf1(int n)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (((1 << i)&n) == 1)
			count++;
	}
	return count;
}
//�Ż�
//����һ������λ���������һ�����ý���Ὣ����������ұߵ�һ��Ϊ�㣬Ҳ����ÿ����һ�Σ�1�ĸ�����1
int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n&(n - 1);
	}
	return count;
}

//����
class Solution
{
private:
	typedef struct ListNode
	{
		int value;
		struct ListNode* pNext;
	}ListNode;
	
public:
	//5.O(1)ɾ������ڵ�
	void DeleteNode(ListNode** pplist, ListNode* pos)
	{
		assert(pplist && (*pplist) && pos)

		//��β���
		if (pos->pNext != NULL)
		{
			ListNode* pDel = pos->pNext;
			pos->value = pDel->value;
			pos->pNext = pDel->pNext;
			free(pDel);
			pDel = NULL;
		}
		//β�ڵ�
		//1.����һ�����
		else if ((*pplist) == pos)
		{
			free((*pplist));
			(*pplist) == NULL;
			pos = NULL;
		}
		//2.����ڵ�
		else
		{
			ListNode* pDel = (*pplist);
			while (pDel->pNext != pos)
			{
				pDel = pDel->pNext;
			}
			pDel->pNext = NULL;
			free(pos);
			pos = NULL;
		}
	}

	//6.�����е�k���ڵ�
	ListNode* FindKthNode(ListNode* plist, size_t k)
	{
		assert(plist);
		ListNode* pFast = plist;
		ListNode* pSlow = plist;
		while (k--)	 //while(--k)
		{
			pFast = pFast->pNext;
			//���k>�����ȣ��˳�
			if (pFast == NULL)
				return NULL;
		}

		while (pFast) //while(pFast->pNext)
		{
			pFast = pFast->pNext;
			pSlow = pSlow->pNext;
		}
		return pSlow;
	}

};
