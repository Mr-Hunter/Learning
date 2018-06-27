#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkPractice.h"

//�����ӡ�������ݹ飩
void ReversPrintLinkList(pList plist)
{
	if (plist == NULL)
	{
		return;
	}
	if (plist->pNext == NULL)
	{
		printf("%d ",plist->data);
		return;
	}
	ReversPrintLinkList(plist->pNext);
	printf("%d ", plist->data);


}
//�����ӡ�������ǵݹ飩
void ReversPrintLinkList_OP(pList plist)
{
	pNode pCur = NULL;
	pNode pTail = NULL;
	if (plist == NULL)
	{
		return;
	}
	if (plist->pNext == NULL)
	{
		printf("%d ", plist->data);
		return;
	}

	pCur = plist;
	while (pCur != pTail)
	{
		while (pCur->pNext != pTail)
		{
			pCur = pCur->pNext;
		}
		printf("%d ",pCur->data);
		pTail = pCur;
		pCur = plist;

	}
	
}

//ɾ����������ͷ��β�ڵ�
void EraseWithoutHeadNotTail(pNode pos)
{
	pNode pDel = NULL;
	assert(pos && pos->pNext);

	pDel = pos->pNext;
	pos->data = pDel->data;
	pos->pNext = pDel->pNext;
	free(pDel);
	pDel = NULL;

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
//����ͷ����ĳ�ڵ�ǰ�����һ���ڵ�
void InsertNodeToFront(pNode pos,DataType d)
{
	pNode pNewNode = NULL;
	assert(pos);

	pNewNode = BuyNode(pos->data);
	pNewNode->pNext = pos->pNext;
	pos->pNext = pNewNode;
	pos->data = d;

}

//Լɪ�����⣺��ӡ���α�ɾ�����кŲ��������һ��
void JosephusCycle(pNode* pplist,size_t k)
{
	pNode pCur = NULL;
	assert(pplist);
	pCur = *pplist;

	while (pCur != pCur->pNext)
	{
		pNode pDel = NULL;
		int count = k;
		while (--count)
		{
			pCur = pCur->pNext;
		}
		printf("ɾ�����ǣ�%d\n",pCur->data);
		pDel = pCur->pNext;
		pCur->data = pDel->data;
		pCur->pNext = pDel->pNext;
		free(pDel);
		pDel = NULL;
	}
	printf("����Ҵ���ǣ�%d\n", pCur->data);

}

//���õ�������һ����ָ����	
void ReversSingleLinkList(pList* pplist)
{
	pNode p1 = NULL;
	pNode p2 = NULL;
	pNode p3 = NULL;

	assert(pplist);

	if ((*pplist == NULL) || ((*pplist)->pNext == NULL))
	{
		return;
	}

	p1 = (*pplist);
	p2 = p1->pNext;
	p3 = p2->pNext;

	while (p2)
	{
		p2->pNext = p1;
		p1 = p2;
		p2 = p3;
		if (p3)
		{
			p3 = p3->pNext;
		}

	}
	(*pplist)->pNext = NULL;	//��������
	(*pplist) = p1;
	
}

//���õ������Ż�
void ReversSingleLinkList_OP(pList* pplist)
{
	pNode pHead = NULL;
	pNode pTmp = NULL;
	pNode pCur = NULL;

	assert(pplist);

	pCur = (*pplist);
	pTmp = pCur->pNext;

	while (pCur)
	{  
		pCur->pNext = pHead;
		pHead = pCur;
		pCur = pTmp;
		if (pTmp)
		{
			pTmp = pTmp->pNext;
		}
	}
	(*pplist) = pHead;
}






















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
		printf("%d ", pCur->data);
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
//����
pNode Find(pList pplist, DataType d)
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
