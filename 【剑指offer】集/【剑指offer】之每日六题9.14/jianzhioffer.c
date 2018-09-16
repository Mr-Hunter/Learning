/*******************************************************************************************
*                                title:����ָoffer��֮ÿ������                                   *
*                                date : 2018.9.14                                                         *
*                                By   : Hunter                                                       *
********************************************************************************************/

//1.��ά����Ĳ���
//����Ŀ����һ����ά�����У�ÿһ��ÿһ�ж��ǰ��յ�����˳������,�����һ������������һ�������һ�����֣��жϸ������Ƿ��и�����
//�������������Ͻǿ�ʼÿ���ж�һ�л�һ�У�ʱ�临�Ӷ�o(m+n),m������n�������ռ临�Ӷ�o(1)
class Solution
{
public:
	bool Find(vector<vector<int>>array, int target)
	{
		int row = array.size();	  //����
		int col = array[0].size(); //����

		if (row == 0) return false;
		if (col == 0) return false;

		int x = 0, y = col - 1;
		while (x < row&&y >= 0)
		{
			if (array[x][y] == target)
				return true;
			else if (arar[x][y] > target)
				++x;
			else
				--y;
		}

		return true;
	}

};

//2.�ո��滻
//����Ŀ����һ���ַ����еĿո��滻��Ϊ��20%��
//��˼·���ȸ��ݿո����жϳ��滻���ܹ���Ҫ�Ŀռ䣬Ȼ��������Ƿֱ�ָ���ַ��������ռ��ĩ�ˣ���ʼ���ַ����ƣ������ո�����滻��ʱ�临�Ӷ�o(n);
 
class Solution
{
public:
	void ReplaceSpace(char* str,int length)
	{
		assert(str&&length>0);

		int i = 0;
		int len = 0;  //�ַ�������
		int count = 0; //�ո����

		while (str[i]!= '\0')
		{
			len++;
			if (str[i] == ' ')
				count++;
			++i;
		}

		if (0 == count) return; //�޿ո�ֱ�ӷ���
		int newlen = count * 2 + len;
		if (newlen > length)
			return;
		int p1 = len;
		int p2 = newlen;

		while (len < newlen&&len >= 0)
		{
			if (str[p1] == ' ')
			{
				str[p2--] = '%';
				str[p2--] = '0';
				str[p2--] = '2';
			}
			else
			{
				str[p2--] = str[p1];
			}
			p1--;
		}

	}
};

//3.�����ӡ������
class Solution
{
private:
	typedef struct ListNode
	{
		int value;
		struct ListNode* pNext;
	}ListNode, pListNode;

public:
	//���ݹ顿
	void PrintListTailToHead(ListNode* plist)
	{
		assert(plist);

		if (plist->pNext != NULL)
		{
			PrintListTailToHead(plist->pNext);
		}
		printf("%d  ", plist->value);

	}

	//���ǵݹ顿
	void PrintListTailToHead(ListNode* plist)
	{
		//�˴����������ջ
		stack<ListNode*> node;

		ListNode* pCur = plist;

		while (pCur)
		{
			node.push(pCur);
			pCur = pCur->pNext;
		}
		while (!node.empty())
		{
			printf("%d  ",node.top()->value);
			node.pop();
		} 

		//�˴�������ֵ��ջ
		/*stack<int> s;

		ListNode* pCur = plist;

		while (pCur)
		{
		s.push(pCur->value);
		pCur = pCur->pNext;
		}
		while (!node.empty())
		{
		printf("%d  ",s.top()) ;
		s.pop();
		}  */

	}

};
//�����ӡ�
//����������һ�����
void AddNodeToTail(pListNode* pplist, int value)
{
	if (pplist == NULL)
		return;

	ListNode* pNewNode = new ListNode();
	pNewNode->value = value;
	pNewNode->pNext = NULL;

	if (*pplist == NULL)
		*pplist = pNewNode;
	else
	{
		ListNode* pCur = (*pplist);
		while (pCur->pNext)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = pNewNode;
	}

}
//ɾ��ֵ����value�Ľ��
void ReMovaValue(pListNode* pplist, int value)
{
	if (pplist == NULL || (*pplist) == NULL)
		return;
	ListNode* pCur = (*pplist);
	ListNode* pPre = NULL;
	while (pCur)
	{			  
		if (pCur->value == value)
		{
			ListNode* pDel = NULL;
			if ((*pplist)->value == value)
			{
				pDel = (*pplist);
				(*pplist) = pDel->pNext;
				free(pDel);
				pDel = NULL;
			}
			else
			{
				pDel = pCur;
				pPre->pNext = pCur->pNext;
				free(pDel);
				pDel = NULL;
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
//ɾ��ֵ����value�����н��
void ReMovaValue(pListNode* pplist, int value)
{
	if (pplist == NULL || (*pplist) == NULL)
		return;
	ListNode* pCur = (*pplist);
	ListNode* pPre = NULL;
	while (pCur)
	{
		if (pCur->value == value)
		{
			 
			if ((*pplist)->value == value)
			{
				(*pplist) = (*pplist)->pNext;
				free(pCur);
				pCur = (*pplist);
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
//4.�ؽ������� 
//����Ŀ����֪ĳ��������ǰ���������ؽ�������
//�����������ҵ������еĸ��ڵ㣬Ȼ����ݶ��������ʵݹ飬ʱ�临�Ӷ�o(nlogn),nΪ�ڵ���
class Solution
{
private:
	typedef struct TreeNode
	{
		int value;
		struct TreeNode* pLeft;
		struct TreeNode* pRight;
	}TreeNode;

public:
	TreeNode* ReBuildBinaryTree(int* pre, int in, int len)
	{
		assert(pre&&in&&len > 0);

		return BuildBinaryTree(pre, pre + len - 1, in, in + len - 1);
	}

	TreeNode* BuildBinaryTree(int* startpre, int* endpre, int* startin, int* endin)
	{
		assert(startpre&&endpre&&startin&&endin);
		//ǰ�������һ���Ǹ�ֵ
		int rootvalue = startpre[0];

		//�������ڵ�
		TreeNode* root = new TreeNode();
		root->value = rootvalue;
		root->pLeft = root->pRight = NULL;

		//���ǰ��������ֻ��һ��ֵ������ֻ��һ�����ڵ�
		if (startpre == endpre)
		{
			if ((startin == endin)&&(*startpre == *startin))
			{
				return root;
			}
			else
			{
				printf("ǰ���������������\n");
				return;
			}
		}

		//������������ҵ��ڵ��ֵ
		int* rootIn = startin;

		while ((rootIn <= endin) && (*rootIn != rootvalue))
		{
			++rootIn;
		}
		//���û�ҵ�����ֹ
		if ((rootIn == endin) && ((*rrotIn) != rootvalue))
		{
			printf("����δ�ҵ����ڵ�\n");
			return;
		}

		//���������������ĳ���
		int leftlenin = rootIn - startin;
		//����ǰ��������λ��
		int* leftlenpre = startpre + leftlenin;

		//����������
		if (leftlenin > 0)
		{
			root->pLeft = BuildBinaryTree(startpre+1,leftlenpre,startin,rootIn-1);
	
		}
		//����������
		if ((endpre - startpre) > leftlenin)
		{
			root->pRight = BuildBinaryTree(leftlenpre+1,endpre,rootIn+1,endin);
		}

	}							  
};
//5.����ջʵ��һ������
class Queue
{
private:
		Stack<int> s1;
		Stack<int> s2;

public:
	void QueueByTwoStackPosh(int key)
	{

		s1.push(key);
	}
	void QueueByTwoStackPop()
	{
		if (s2.empty())
		{
			whlie(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
	int QueueByTwoStackFront()
	{
		if (s2.empty())
		{
			whlie(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();


	}

};
//�����ӡ�
//��������ʵ�а�һ��ջ

class Solution
{
private:
	Queue <int> q1;
	Queue <int> q2;
public:
	void StackByTwoQueuePush(int key)
	{
		if (q1.empty())
		{
			q2.push(key);
		}
		else
			q1.push(key);

	}
	void StackByTwoQueuePop()
	{
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				q1.push(q2.top());
				q2.pop();
			}
			q2.pop();
		}
		else if (q2.empty())
		{
			while (q1.size() > 1)
			{
				q2.push(q1.top());
				q1.pop();
			}
			q1.pop();
			 
		}

	}
	int StackByTwoQueueTop()
	{
		if (q1.empty())
		{
			return q2.back();
		}
		else
			return q1.back();

	}
};
