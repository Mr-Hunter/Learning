#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkPractice.h"



////////////////////////////////////////////������ӿ�/////////////////////////////////////

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
////////////////////////////////////////////������������/////////////////////////////////////// 

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

	while (plist != pTail)
	{
		pCur = plist;
		while (pCur->pNext != pTail)
		{
			pCur = pCur->pNext;
		}
		printf("%d ",pCur->data);
		pTail = pCur;

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
	pNode p3 = NULL;   //Ϊ��ʹ�����ᶪʧ

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
	pNode pCur = NULL;
	pNode pTmp = NULL;	  //Ϊ��ʹ�����ᶪʧ


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
//ð������
void BubbleSort(pList* pplist)
{
	pNode pCur = NULL;
	pNode pTmp = NULL;
	pNode pTail = NULL;
	int flag = 1;

	assert(pplist);
	if ((NULL == (*pplist)) || (NULL == (*pplist)->pNext))
		return;

	while ((*pplist) != pTail)
	{
		pCur = (*pplist);
		pTmp = pCur->pNext;
		while (pCur->pNext != pTail)	//while(pTmp != pTail)
		{
			if (pCur->data > pTmp->data)
			{
				DataType tmp = pCur->data;
				pCur->data = pTmp->data;
				pTmp->data = tmp;
				flag = 0;	 
			}
			pCur = pTmp;
			pTmp = pTmp->pNext;
		}
		if (1 == flag)
			break;
		pTail = pCur;
	}
}
//�ϲ�������������
pNode Merge(pList plist1, pList plist2)
{
	
	pNode pCur = NULL;

	if (NULL == plist1)
		return plist2;
	if (NULL == plist2)
		return plist1;

	if (plist1 == plist2)
		return NULL;

	pNode pNewList = (pNode)malloc(sizeof(Node));
	pCur = pNewList;
	while (plist1&&plist2)
	{
		if (plist1->data > plist2->data)
		{
			pCur->pNext = plist2;
			plist2 = plist2->pNext;
		}
		else
		{
			pCur->pNext = plist1;
			plist1 = plist1->pNext;
		}
		pCur = pCur->pNext;
	}
	if (plist1)
	{
		pCur->pNext = plist1;
	}
	else if (plist2)
	{
		pCur->pNext = plist2;
	}
	return pNewList->pNext;
}

//�ϲ�������������:�ݹ�
pNode Merge_OP(pList plist1, pList plist2)
{
	pNode pNewList = (pNode)malloc(sizeof(Node));

	pNode pCur = pNewList;


	if (NULL == plist1)
		return plist2;
	if (NULL == plist2)
		return plist1;

	if (plist1 == plist2)
		return NULL;

	if (plist1->data > plist2->data)
	{
		 
		pCur->pNext = Merge_OP(plist1, plist2->pNext);
	}
	else
	{
		 
		pCur->pNext = Merge_OP(plist1->pNext, plist2);

	}
	return pNewList->pNext;

}

//Ѱ���м�ڵ�
pNode FindMiddle(pList plist)
{
	pList pSlow = plist;
	pList pFast = plist;
	if ((NULL == plist) || (NULL == plist->pNext))
		return plist;
	while (pFast&&pFast->pNext)
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;

	}
	return pSlow;

}
//Ѱ�ҵ�����k�ڵ�
pNode FindRevers(pList plist, size_t k)
{
	pNode pFast = plist;
	pNode pSlow = plist;
	if (NULL == plist)
		return NULL;
	while (k--)
	{
		if (pFast == NULL)
			return NULL;
		pFast = pFast->pNext;
	}
	while (pFast)
	{
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}
	return pSlow;
}
//�жϵ������Ƿ���������������󳤶�,����ڡ�
pNode IsWithCross(pList plist)
{
	pList pFast = plist;
	pList pSlow = plist;
	assert(plist);
	
	while (pFast&&pFast->pNext)
	{

		pFast = pFast->pNext->pNext;
		pSlow = pSlow = pSlow->pNext;
		if (pFast == pSlow)
		{
			return pSlow;
		}
	}
	return NULL;
}
int GetCrossLenth(pList pMeet)
{
	int len = 0;
	pNode pCur = NULL;
	assert(pMeet);
	
	len = 1;
	pCur = pMeet->pNext;
	while (pCur!=pMeet)
	{
		len++;
		pCur = pCur->pNext;
	}
	return len;
}
pNode CrossIn(pList plist, pList pMeet)
{
	pNode pCur = NULL;
	assert(plist&&pMeet);
	pCur = plist;
	while (pCur != pMeet)
	{
		pCur = pCur->pNext;
		pMeet = pMeet->pNext;
	}
	return pCur;
}
//�ж����������Ƿ��ཻ�����ཻ���󽻵�
int CheckCross(pList plist1, pList plist2)
{
	assert(plist1&&plist2);
	pNode p1 = plist1;
	pNode p2 = plist2;

	while (p1->pNext)
	{
		p1 = p1->pNext;
	}
	while (p2->pNext)
	{
		p1 = p2->pNext;
	}
	/*if (p1 == p2)
	{
		return 1;
	}
	else
	{
		return 0;
	}  */
	return p1 == p2;
}
pNode GetCrossNode(pList plist1, pList plist2)
{
	assert(plist1&&plist2);
	int len1 = 0;
	int len2 = 0;

	pNode p1 = plist1;
	pNode p2 = plist2;
	while (p1)
	{
		len1++;
		p1 = p1->pNext;
	}
	while (p2)
	{
		len2++;
		p2 = p2->pNext;
	}

	//����ȶ̱����ĳ���
	int gap = abs(len1 - len2);
	//Ĭ��pCur1 Ϊ������
	pNode pCur1 = p1;
	pNode pCur2 = p2;
	if (len2 > len1)
	{
		pCur1 = p2;
		pCur2 = p1;

	}
	while (gap--)
	{
		pCur1 = pCur1->pNext;
	}
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->pNext;
		pCur2 = pCur2->pNext;
	}
	return pCur1;

}
//����������

ComplexNode* ComplexListCopy(ComplexNode* head)
{
	ComplexNode* pOldList = NULL;
	ComplexNode* pNewList = NULL;
	ComplexNode* pNewHead = NULL;

	if (head == NULL)
		return NULL;
	pOldList = head;
	//ÿ�����������һ��������һ�µĽ��
	while (pOldList)
	{
		ComplexNode* tmp = (ComplexNode*)malloc(sizeof(ComplexNode));
		tmp->data = pOldList->data;
		tmp->pNext = NULL;
		tmp->pRandom = NULL;

		tmp->pNext = pOldList->pNext;
		pOldList->pNext = tmp;
		pOldList = tmp->pNext;
	}
	//���½�������ֵ
	pOldList = head;
	while (pOldList)
	{
		pNewList = pOldList->pNext;
		
		pNewList->pRandom = (pOldList->pRandom==NULL)?NULL:pOldList->pRandom->pNext;
		pOldList = pNewList->pNext;

	}
	//�������
	pOldList = head;
	pNewHead = pOldList->pNext;
	while (pOldList->pNext)
	{
		pNewList = pOldList->pNext;
		pOldList->pNext = pNewList->pNext;
		pOldList = pNewList;
	}
	return pNewHead;
}
//����������Ľ���
void Union(pList plist1, pList plist2)
{
	pNode p1 = plist1;
	pNode p2 = plist2;
	if (plist1 == NULL || plist2 == NULL)
		return ;
	if (p1->data < p2->data)
	{
		p1 = p1->pNext;
	}
	else if (p1->data>p2->data)
	{
		p2 = p2->pNext;
	}
	else
	{
		printf("%d  ",p1->data);
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	
}


//����������Ĳ���

void Togeter(pList* plist1, pList plist2)
{
	assert(plist1&&plist2);
	//˼·����2��ÿ��Ԫ�ص����ó�����1������Ԫ�رȽϣ�
	//�����1�����궼û����ͬ�ͰѴ�Ԫ������1�󣬿�ʼ��2�е���һ��Ԫ�ؽ�����ͬ������
	//�������ͬ��ֱ���˳��Ƚϣ���ʼ��2�е���һ��Ԫ�ؽ�����ͬ����
}

//����������Ĳ  plsit-plist2(ȥ��)
void Difference(pList* plist1, pList plist2)
{
	assert(plist1&&plist2);
	//˼·����ȡ1��һ��Ԫ�ظ�2���бȽϣ��������ͬɾ���˽ڵ㣬
	//���û����ͬ�ͼ�����һ������2����Ԫ�رȽ�
	pNode pa = (*plist1);
	pNode pb = plist2;
	pNode pre = NULL, pDel = NULL;
	while (pa)
	{
		pb = plist2;
		while (pb&&pa->data != pb->data)
			pb = pb->pNext;
		if (pb)
		{
			if (!pre)
			{
				(*plist1) = pa->pNext;

			}
			else
			{
				pre->pNext = pa->pNext;

			}
			pDel = pa;
			pa = pa->pNext;
			free(pDel);
			pDel = NULL;
		}
		else
		{
			pre = pa;
			pa = pa->pNext;
		}
	}

}