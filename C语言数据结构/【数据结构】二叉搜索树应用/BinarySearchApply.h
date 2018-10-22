#ifndef __APPLY_H__
#define __APPLY_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//1. �ж�һ�������Ƿ�ƴд��ȷ
//2. ��ģ��ʵ��һ���򵥵���Ӣ������ֵ�
/*
typedef char* KeyType;
typedef char* ValueType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	KeyType _key;
	ValueType _value;
}BSTreeNode;

BSTreeNode* BuyBSTreeNode(KeyType key, ValueType value);
int BSTreeInsertR(BSTreeNode** tree, KeyType key, ValueType value);
BSTreeNode* BSTreeFindR(BSTreeNode* tree, KeyType key);
int BSTreeRemoveR(BSTreeNode** tree, KeyType key);
void CheckWord(BSTreeNode** tree, KeyType key);
 */ 



//3. log�ļ���������쳣�ظ���IP��ַ����ͳ�Ƴ�ÿ���쳣IP�����˶��ٴΣ�
typedef char* KeyType;
typedef int ValueType; //����ظ����ֵĴ���

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	KeyType _key;
	ValueType _value;
}BSTreeNode;
BSTreeNode* BuyBSTreeNode(KeyType key);
int BSTreeInsertR(BSTreeNode** tree, KeyType key);
BSTreeNode* BSTreeFindR(BSTreeNode* tree, KeyType key);
int BSTreeRemoveR(BSTreeNode** tree, KeyType key);
#endif  //__APPLY_H__