#ifndef __BINARY_H__
#define __BINARY_H__

#include "Queue.h"
#include "Stack.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* pLeft;
	struct BinaryTreeNode* pRight;
}BTNode,*pBTNode;


///////////////////////////////������������ز����뾭��������////////////////////////////////

//����������
pBTNode BinaryTreeCreat(char* arr,int n,int* p);
//���ٶ�����
void BinaryTreeDestory(pBTNode* root);

//ǰ�к�ݹ����
void BinaryTreePrevSearch(pBTNode root);
void BinaryTreeMiddleSearch(pBTNode root);
void BinaryTreeLastSearch(pBTNode root);
void BinaryTreeLavelSearch(pBTNode root);

//ǰ�к�ǵݹ����
void BinaryTreePrevSearch_OP(pBTNode root);
void BinaryTreeMiddleSearch_OP(pBTNode root);
void BinaryTreeLastSearch_OP(pBTNode root);

//�������Ľ�����
int BinaryTreeNodeSize(pBTNode root);
//Ҷ�ӽ�����
int BinaryTreeNodeLeaf(pBTNode root);
//���������
int BinaryTreeDepth(pBTNode root);
//��������k�������
int BinaryTreeNodeKLevel(pBTNode root,int k);
//�ж�һ������Ƿ��ڶ�������
pBTNode BinaryTreeFind(pBTNode root,BTDataType x);
//�ж�һ�ö��������Ƿ�����ȫ������
bool BinaryTreeComplete(pBTNode root);


//��ȡһ�����˫�׽��
pBTNode GetBinaryTreeNodeParent(pBTNode root);
//��ȡһ���������ӽ��
pBTNode GetBinaryTreeNodeLeftChild(pBTNode root);
//��ȡһ�������Һ��ӽ��
pBTNode GetBinaryTreeNodeRightChild(pBTNode root);

//��������ľ���(�ݹ�&�ǵݹ�)
void BinaryTreeMirror(pBTNode root);
void BinaryTreeMirror_OP(pBTNode root)


void testBinaryTreeNode();

#endif //__BINARY_H__




