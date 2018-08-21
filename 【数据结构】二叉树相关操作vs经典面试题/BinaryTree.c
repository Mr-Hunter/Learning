
#include "BinaryTree.h"

///////////////////////////////������������ز���////////////////////////////////

static pBTNode BBuyNode(BTDataType x)
{
	pBTNode node = (pBTNode)malloc(sizeof(BTNode));
	assert(node);
	node->pLeft = NULL;
	node->data = x;
	node->pRight = NULL;
	return node;
}
//����������
pBTNode BinaryTreeCreat(char* arr, int n, int* p)
{
	if ((arr[*p] != '#') && ((*p) < n))
	{
		pBTNode root = BBuyNode(arr[(*p)]);
		++(*p);
		root->pLeft = BinaryTreeCreat(arr, n, p);
		++(*p);									 
		root->pRight = BinaryTreeCreat(arr, n, p);
		return root;
	}
	else
	{
		return NULL;
	}
}
//���ٶ�����
void BinaryTreeDestory(pBTNode* root)
{
	pBTNode pCur = (*root);
	
	if (pCur)
	{
		BinaryTreeDestory(&pCur->pLeft);
		BinaryTreeDestory(&pCur->pRight);
		free(pCur);
		pCur = NULL;
	}

}

//ǰ�к�ݹ����
void BinaryTreePrevSearch(pBTNode root)
{
	if (root == NULL)
		return;
	printf("%c  ",root->data);
	BinaryTreePrevSearch(root->pLeft);
	BinaryTreePrevSearch(root->pRight);
}
void BinaryTreeMiddleSearch(pBTNode root)
{
	if (root == NULL)
		return;
	BinaryTreePrevSearch(root->pLeft);
	printf("%c  ", root->data);
	BinaryTreePrevSearch(root->pRight);
}
void BinaryTreeLastSearch(pBTNode root)
{
	if (root == NULL)
		return;
	BinaryTreePrevSearch(root->pLeft);
	BinaryTreePrevSearch(root->pRight);
	printf("%c  ", root->data);

}

//�������
void BinaryTreeLevelSearch(pBTNode root)
{
	Queue q;
	if (root == NULL)
	{
		return;
	}
	QueueInit(&q);
	
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		pBTNode front = QueueFront(&q);
		printf("%c ",front->data);
		QueuePop(&q);
		if (front->pLeft)
		{
			QueuePush(&q,front->pLeft);
		}
		if (front->pRight)
		{
			QueuePush(&q,front->pRight);
		}
	}
	printf("\n");
}

//ǰ�к�ǵݹ����
//�ȷ���ÿ����㣨pCur&&pCur->pLeft����ѹջ����Ȼ������������С�Ͷ�����������ͬ����
void BinaryTreePrevSearch_OP(pBTNode root)
{
	Stack s;
	BTNode* pCur = root;
	StackInit(&s);

	if (root == NULL)
		return;
	//��ǰָ�벻Ϊ�ջ���ջ��Ϊ�վ�Ӧ�ü���
	while (pCur||!StackEmpty(&s))
	{
		while (pCur)
		{
			printf("%c ",pCur->data);
			StackPush(&s,pCur);
			pCur = pCur->pLeft;
		}
		pBTNode top = StackTop(&s);
		StackPop(&s);
		pCur = top->pRight;

	}
	
}
//ÿ����㣨pCur&&pCur->pLeft����ѹջ�ٷ��ʣ�Ȼ������������С�Ͷ�����������ͬ����
void BinaryTreeMiddleSearch_OP(pBTNode root)
{
	Stack s;
	SatckInit(&s);

	pBTNode pCur = root;
	if (root == NULL)
		return;
	//��ǰָ�벻Ϊ�ջ���ջ��Ϊ�վ�Ӧ�ü���
	while (pCur || !StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->pLeft;
		}
		pBTNode top = StackTop(&s);
		printf("%c   ",top->data);
		StackPop(&s);
		pCur = top->pRight;
	}
}
//�����ڵ���ڣ���ʹ���ڵ���ջ����������������ʹ��������ջ��ֱ����������������Ϊ��ֹͣ��
//��ʱȡջ��topԪ�أ��ж�ջ��Ԫ�ص�������top->right�Ƿ�Ϊ�գ���Ϊ��ֱ�Ӵ�ӡջ��Ԫ�أ�
//����Ϊ��,����������Ϊ���ڵ���������ж�(��ջ��ȡջ����)��
//���˴�����top->right��������������ô�˽ڵ������ջ��
//��ջ��Ϻ��֪����������Ϊ�գ��������ж���������������Ϊ�գ���ӡջ��Ԫ�أ���ջ��
//��ʱ����ջ��top������ӡtop������Ӧ�ü�һ����ӡ�ж�����(top->right == ?),���������top��������
//���ϣ���ÿ�δ�ӡ��Ϻ󣬽��˽ڵ���pre���������������top->tight == pre���ɣ�����
//�����ĵ�pre��¼�ϴ�ջ����λ�ã�
void BinaryTreeLastSearch_OP(pBTNode root)
{
	Stack s;
	pBTNode pCur = root;
	StackInit(&s);
	if (root == NULL)
		return;
	//��ǰָ�벻Ϊ�ջ���ջ��Ϊ�վ�Ӧ�ü���
	while (pCur || !StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->pLeft;
		}

		pBTNode tmp = StackTop(&s);
		pBTNode pre = NULL;

		if (tmp->pRight == NULL||tmp->pRight == pre)
		{
			printf("%c ",tmp);
			StackPop(&s);
			pre = tmp;
		}
		else
		{
			pCur = tmp->pRight;

		}
	}
}

//�������Ľ�����
int BinaryTreeNodeSize(pBTNode root)
{
	if (root == NULL)
		return 0;
	return	BinaryTreeNodeSize(root->pLeft)
		+ BinaryTreeNodeSize(root->pRight) + 1;
}
//Ҷ�ӽ�����
int BinaryTreeNodeLeaf(pBTNode root)
{
	if (root == NULL)
	{
		return 0;
	}
	if ((root->pLeft == NULL) && (root->pRight == NULL))
		return 1;
	return BinaryTreeNodeLeaf(root->pLeft)
		+ BinaryTreeNodeLeaf(root->pRight);
}
//���������
int BinaryTreeDepth(pBTNode root)
{
	if (root == NULL)
		return 0;
	int left = BinaryTreeDepth(root->pLeft);
	int right = BinaryTreeDepth(root->pRight);

	return (left>right) ? (left+1) : (right+1);
}
//��������k�������
int BinaryTreeNodeKLevel(pBTNode root, int k)
{												 
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeNodeKLevel(root->pLeft, k - 1)
		+ BinaryTreeNodeKLevel(root->pRight, k - 1);
}
//�ж�һ������Ƿ��ڶ�������
pBTNode BinaryTreeFind(pBTNode root, BTDataType x)
{
	pBTNode ret;
	if (root == NULL || root->data == x)
		return root;
	ret = BinaryTreeFind(root->pLeft,x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->pRight,x);
	if (ret)
		return ret;
	return NULL;

}

//�ж�һ�ö��������Ƿ�����ȫ������
bool BinaryTreeComplete(pBTNode root)
{
	
	Queue q;

	if (root == NULL)
		return true;
	QueueInit(&q);

	QueuePush(&q,root);
	while (!QueueEmpty(&q))
	{
		pBTNode tmp = QueueFront(&q);
		QueuePop(&q);
		if (tmp == NULL)
		{
			while (!QueueEmpty(&q))
			{
				QueuePop(&q);
				if (QueueFront(&q))
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			QueuePush(&q,tmp->pLeft);
			QueuePush(&q, tmp->pRight);
		}
	}
}
//��ȡһ�����˫�׽��
pBTNode GetBinaryTreeNodeParent(pBTNode root,BTDataType x)
{
	pBTNode ret;
	if (root == NULL)
		return NULL;
	if (root->pLeft)
	{
		if (root->pLeft->data == x)
			return root;

	}
	if (root->pRight)
	{
		if (root->pRight->data == x)
			return root;

	}
	ret = GetBinaryTreeNodeParent(root->pLeft, x);
	if (ret)
		return ret;
	ret = GetBinaryTreeNodeParent(root->pRight, x);
	if (ret)
		return ret;
	return NULL;
	
}
//��ȡһ���������ӽ��
pBTNode GetBinaryTreeNodeLeftChild(pBTNode root, BTDataType x)
{
	pBTNode ret = NULL;

	if (root == NULL)
	{
		return NULL;
	}
	ret = BinaryTreeFind(root,x);
	if (ret->pLeft)
		return ret->pLeft;
}
//��ȡһ�������Һ��ӽ��
pBTNode GetBinaryTreeNodeRightChild(pBTNode root, BTDataType x)
{

	pBTNode ret = NULL;

	if (root == NULL)
	{
		return NULL;
	}
	ret = BinaryTreeFind(root, x);
	if (ret->pRight)
		return ret->pRight;
}

//��������ľ���(�ݹ�&�ǵݹ�)
void BinaryTreeMirror(pBTNode root)
{
	if (NULL == root)
		return;
	if (root->pLeft == NULL&&root->pRight == NULL)
		return;
	pBTNode tmp = root->pLeft;
	root->pLeft = root->pRight;
	root->pRight = tmp;

	if (root->pLeft)
		BinaryTreeMirror(root->pLeft);
	if (root->pRight)
		BinaryTreeMirror(root->pRight);
}
void BinaryTreeMirror_OP(pBTNode root)
{

}
void testBinaryTreeNode()
{
	int i = 0;
	char arr[] = { 'A', 'B', 'D', '#', '#', '#', 'C', 'E', '#','#', 'O', '#', '#' };
	//��ֹ����һ��ջ������ʱ���ַ��������ƶ���ĳ���ַ����ظ��½���㣬����Ӧ����ַ����&i
	pBTNode root = BinaryTreeCreat(arr, sizeof(arr) / sizeof(char), &i);
	pBTNode tmp = NULL,Pret=NULL;
	bool ret;

	//�ݹ����
	BinaryTreePrevSearch(root);
	printf("\n");
	BinaryTreeMiddleSearch(root);
	printf("\n");
	BinaryTreeLastSearch(root);
	printf("\n");
	BinaryTreeLevelSearch(root);
	printf("\n");


	printf("��������������%d\n",BinaryTreeNodeSize(root));
	printf("������Ҷ�ӽڵ������%d\n", BinaryTreeNodeLeaf(root));
	printf("��������k��������%d\n", BinaryTreeNodeKLevel(root,3));
	printf("��������ȣ�%d\n", BinaryTreeDepth(root));

	tmp = BinaryTreeFind(root, 'A');
	if (tmp)
		printf("%c\n ", tmp->data);
	else
		printf("������\n");
	
	ret = BinaryTreeComplete(root);
	if (ret == false)
		printf("no Complete!\n");
	else
		printf("yes ��\n");

	Pret = GetBinaryTreeNodeParent(root, 'B');
	if (Pret)
		printf("˫�׽�� %c \n", Pret->data);
	else
		printf("������\n");

	Pret = GetBinaryTreeNodeParent(root, 'A');
	if (Pret)
		printf("˫�׽��  %c \n", Pret->data);
	else
		printf("������\n");

	Pret = GetBinaryTreeNodeParent(root, 'E');
	if (Pret)
		printf("˫�׽��  %c \n", Pret->data);
	else
		printf("������\n");

	Pret = GetBinaryTreeNodeRightChild(root,'C');
	if (Pret)
		printf("�ҽ��  %c \n", Pret->data);
	else
		printf("������\n");

	//�������в��ң�����Ӧ��ֵ����
	//�������иı�Ӧ��ַ����
	BinaryTreeDestory(&root);
}