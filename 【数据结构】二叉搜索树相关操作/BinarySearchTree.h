#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct BinarySearchTreeNode
{
	DataType data;
	struct BinarySearchTreeNode* pLeft;
	struct BinarySearchTreeNode* pRight;
}BSTNode;

////////////////////////////////////////////////�ǵݹ�/////////////////////////////////////
//����
void BinarySearchTreeInsert(BSTNode** ppTree,DataType x);
//����
BSTNode* BinarySearchTreeFind(BSTNode** ppTree,DataType x);
//ɾ��
int BinarySearchTreeRemove(BSTNode** ppTree, DataType x);

// ����
void Destroy(BSTNode** ppTree);

////////////////////////////////////////////////�ݹ�/////////////////////////////////////
//����
void BinarySearchTreeInsert_OP(BSTNode** ppTree, DataType x);
//����
BSTNode* BinarySearchTreeFind_OP(BSTNode** ppTree, DataType x);
//ɾ��
int BinarySearchTreeRemove_OP(BSTNode** ppTree, DataType x);

//��ȱ�
void Level(BSTNode** ppTree);
//����
void testBinarySearchTree();
//////////////////////////////////// //////����Ӧ��/////////////////////////////////////
//keyģ��
//key/valueģ��
#endif //__BST_H__