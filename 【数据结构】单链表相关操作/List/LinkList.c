#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkList.h"

//��ʼ��
//�ı䴫��ַ�����ı䴫ֵ
void InitList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}
//��ӡ
//�ı䴫��ַ�����ı䴫ֵ
void PrintList(pList pplist)
{
	//ֵ���ݲ���Ҫ����
	pNode pCur = pplist;
	while (pCur)
	{			    
		printf("%d ",pCur->data);
		pCur = pCur->pNext;
	}
	printf("\n");
	
}
//��������
void DestoryList(pList* pplist)
{
	pNode pDel = NULL;
	assert(pplist);
	while (*pplist)
	{
		pDel = *pplist;
		*pplist = pDel->pNext;
		free(pDel);
		pDel = NULL;
	}
	*pplist = NULL;
	printf("���ٳɹ�\n");
}
//�����½ڵ�
static pNode BuyNode(DataType d)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	if (NULL == tmp)
	{
		perror("malloc faile");
		return NULL;
	}
	tmp->data = d;
	tmp->pNext = NULL;
	return tmp;

}
//β�� (1.��������Ƿ����
//		2.����Ϊ��ֱ�Ӳ���
//		3.���ڲ�Ϊ�����ҵ����ڵ㣩
void  PushBack(pList* pplist, DataType d)
{
	pNode pNewNode = NULL;
	//�ж��Ƿ����
	assert(pplist);

	pNewNode = BuyNode(d);
	if (NULL == pNewNode)
	{
		exit(EXIT_FAILURE);
	}
	//Ϊ��ֱ�Ӳ���
	if (NULL == *pplist)
	{
		*pplist = pNewNode;
	}
	//���ڲ�Ϊ���ҵ����ڵ�
	else
	{
		pNode pCur = *pplist;
		while (pCur->pNext)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = pNewNode;

	}

}
//βɾ��1.��������
//		2.ֻ��һ��ֱ��ɾ
//		3.����ҵ����һ��ɾ�� ��
void PopBack(pList* pplist)
{
	//�ж������Ƿ����
	assert(pplist);
	// 1.��������
	if (NULL == *pplist)
	{
		return;
	}
	// 2.ֻ��һ��ֱ��ɾ
	else if (NULL == (*pplist)->pNext)
	{
		free(*pplist);
		*pplist = NULL;
		
	}
	// 3.����ҵ������ڶ���ɾ��
	else
	{
		pNode pCur = *pplist;
		while (pCur->pNext->pNext)
		{
			pCur = pCur->pNext;
		}
		free(pCur->pNext);
		pCur->pNext = NULL;
	}
}
//ͷ��
void  PushFront(pList* pplist, DataType d)
{
	pNode pNewNode = NULL;
	assert(pplist);
	pNewNode = BuyNode(d);

	if (NULL == pNewNode)
	{
		return;
	}

	pNewNode->pNext = *pplist;
	*pplist = pNewNode;
}
//ͷɾ
void PopFront(pList* pplist)
{
	pNode pDel = NULL;
	assert(pplist);

	if (NULL == *pplist)
	{
		return;
	}

	pDel = *pplist;
	*pplist = pDel->pNext;
	free(pDel);
	pDel = NULL;
}


//�����
void Insert(pList* pplist,pNode pos, DataType d)
{
	pNode pCur = NULL;
	pNode pNewNode = NULL;
	assert(pplist);

	if ((NULL == *pplist) || (pos == NULL))
	{
		return;
	}

	pNewNode = BuyNode(d);
	if (NULL == pNewNode)
	{
		return;
	}
	////����ڵ����
	//pNewNode->pNext = pos->pNext;
	//pos->pNext = pNewNode;

	//����ڵ�ǰ��
	//��һ���ڵ�
	if (pos == (*pplist))
	{
		pNewNode->pNext = pos;
		(*pplist) = pNewNode;
	}
	else  //��ڵ�
	{
		pCur = *pplist;
		while (pCur && pCur->pNext != pos)
		{
			pCur = pCur->pNext;
		}
		if (pCur)
		{
			pNewNode->pNext = pCur->pNext;
			pCur->pNext = pNewNode;

		}
	}

}
//����ɾ��
void Erase(pList* pplist, pNode pos)
{
	pNode pCur = NULL;
	assert(pplist);
	if ((NULL == *pplist) || (pos == NULL))
	{
		return;
	}
	if (pos == *pplist)
	{
		PopFront(pplist);
	}
	else
	{
		pNode pCur = *pplist;
		while (pCur && pCur->pNext != pos)
		{
			pCur = pCur->pNext;
		}
		if (pCur)
		{
			pCur->pNext = pos->pNext;
			free(pos);
			pos = NULL;
		}
	}

}

//ɾ��ָ��Ԫ�� (��һ)
void ReMove(pList* pplist, DataType d)
{
	pNode pPre = NULL;
	pNode pCur = NULL;
	assert(pplist);

	if (*pplist == NULL)
	{
		return;
	}

	pCur = *pplist;
	while (pCur)
	{
		if (pCur->data == d)
		{
			if (pCur == (*pplist))
			{
				PopFront(pplist);
			}
			else
			{
				pPre->pNext = pCur->pNext;
				free(pCur);
				pCur = NULL;

			}
			return;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
	}

}

//ɾ��ָ��Ԫ�� (����)
void ReMove_OP(pList* pplist, DataType d)
{
	pNode pos = NULL;
	assert(pplist);

	if (*pplist == NULL)
	{
		return;
	}

	//ֵ����
	pos = Find(*pplist, d);

	if (pos)
	{
		//ַ����
		Erase(pplist,pos);
	}
}



//ɾ��ָ������Ԫ��
void ReMoveAll(pList* pplist, DataType d)
{
	pNode pPre = NULL;
	pNode pCur = NULL;
	assert(pplist);

	if (*pplist == NULL)
	{
		return;
	}

	pCur = *pplist;
	while (pCur)
	{
		if (pCur->data == d)
		{
			if (pCur == (*pplist))
			{
				PopFront(pplist);
				pCur = *pplist;
			}
			else
			{
				pPre->pNext = pCur->pNext;
				free(pCur);
				pCur = pPre->pNext;

			}
		}
		else
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
	}

}

//����
pNode Find(pList pplist,DataType d)
{
	pNode pCur = NULL;
	assert(pplist);

	pCur = pplist;
	while (pCur)
	{
		if (d == pCur->data)
		{
			return pCur;
		}
		pCur = pCur->pNext;
	}
	return NULL;


}
//���
void Clear(pList* pplist)
{
	pNode pDel = NULL;
	assert(pplist);
	while (*pplist)
	{
		pDel = *pplist;
		*pplist = pDel->pNext;
		free(pDel);
		pDel = NULL;
	}
	printf("��ճɹ�");

}
//�����С
int Size(pList pplist)
{
	pNode pCur = NULL;
	int count = 0;
	assert(pplist);

	pCur = pplist;
	while (pCur)
	{
		count++;
		pCur = pCur->pNext;
	}
	return count;


}
