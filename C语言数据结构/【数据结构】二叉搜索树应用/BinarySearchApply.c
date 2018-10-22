#define _CRT_SECURE_NO_WARNINGS 1


#include "BinarySearchApply.h"
/////////////////////////////////////////////////////////////////////////////////////////////

//1. �ж�һ�������Ƿ�ƴд��ȷ
//2. ��ģ��ʵ��һ���򵥵���Ӣ������ֵ�

/*
BSTreeNode* BuyBSTreeNode(KeyType key, ValueType value){
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	assert(node);
	node->_left = NULL;
	node->_right = NULL;
	node->_key = key;
	node->_value = value;
}

int BSTreeInsertR(BSTreeNode** pptree, KeyType key, ValueType value){
	if (*pptree == NULL){
		*pptree = BuyBSTreeNode(key, value); //pptreeָ��ǰ�պ��ӣ�Ϊ�丳һ�ڵ�
		return 0;
	}

	if (strcmp((*pptree)->_key, key)>0){
		return BSTreeInsertR(&(*pptree)->_left, key, value);
	}
	else if (strcmp((*pptree)->_key, key)<0){
		return BSTreeInsertR(&(*pptree)->_right, key, value);
	}
	else
		return -1;
}

BSTreeNode* BSTreeFindR(BSTreeNode* tree, KeyType key){
	if (tree == NULL)
		return NULL;
	if (strcmp(tree->_key, key) == 0){
		return tree;
	}
	else if (strcmp(tree->_key, key)>0){
		return BSTreeFindR(tree->_left, key);
	}
	else{
		return BSTreeFindR(tree->_right, key);
	}
}

int BSTreeRemoveR(BSTreeNode** pptree, KeyType key){
	BSTreeNode* del;
	if (*pptree == NULL){
		return -1;
	}
	if (strcmp((*pptree)->_key, key)>0){
		return BSTreeRemoveR(&(*pptree)->_left, key);
	}
	else if (strcmp((*pptree)->_key, key)<0){
		return BSTreeRemoveR(&(*pptree)->_right, key);
	}
	else{
		//1.left empty
		//2.right empty
		//3.l and r isnt empty
		BSTreeNode* cur = *pptree;
		if ((*pptree)->_left == NULL){
			*pptree = cur->_right;
		}
		else if ((*pptree)->_right == NULL){
			*pptree = cur->_left;
		}
		else{
			BSTreeNode* parent = cur;
			BSTreeNode* sub = cur->_right;
			while (sub->_left){
				sub = sub->_left;
			}

			cur->_key = sub->_key;
			return BSTreeRemoveR(&(cur->_right), sub->_key);
		}
		return 0;
	}
}
     
    void CheckWord(BSTreeNode* tree,KeyType key){
    	if(BSTreeFindR(tree,key))
    		printf("%s ƴд��ȷ\n",key);
    	else
    		printf("%s ƴд����\n",key);
    }
	   */
    
////////////////////////////////////////////////////////////////////////////////////////////
//3. log�ļ���������쳣�ظ���IP��ַ����ͳ�Ƴ�ÿ���쳣IP�����˶��ٴΣ�
	
BSTreeNode* BuyBSTreeNode(KeyType key){
		BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
		assert(node);
		node->_left = NULL;
		node->_right = NULL;
		node->_key = key;
		node->_value = 1;
	}

	int BSTreeInsertR(BSTreeNode** pptree, KeyType key){
		if (*pptree == NULL){
			*pptree = BuyBSTreeNode(key); //pptreeָ��ǰ�պ��ӣ�Ϊ�丳һ�ڵ�
			return 0;
		}

		if (strcmp((*pptree)->_key, key)>0){
			return BSTreeInsertR(&(*pptree)->_left, key);
		}
		else if (strcmp((*pptree)->_key, key)<0){
			return BSTreeInsertR(&(*pptree)->_right, key);
		}
		else {
			(*pptree)->_value++;
			return 1;
		}
	}

	BSTreeNode* BSTreeFindR(BSTreeNode* tree, KeyType key){
		if (tree == NULL)
			return NULL;
		if (strcmp(tree->_key, key) == 0){
			return tree;
		}
		else if (strcmp(tree->_key, key)>0){
			return BSTreeFindR(tree->_left, key);
		}
		else{
			return BSTreeFindR(tree->_right, key);
		}
	}

	int BSTreeRemoveR(BSTreeNode** pptree, KeyType key){
		if (*pptree == NULL){
			return -1;
		}
		if (strcmp((*pptree)->_key, key)>0){
			return BSTreeRemoveR(&(*pptree)->_left, key);
		}
		else if (strcmp((*pptree)->_key, key)<0){
			return BSTreeRemoveR(&(*pptree)->_right, key);
		}
		else{
			//1.left empty
			//2.right empty
			//3.l and r isnt empty
			BSTreeNode* cur = *pptree;
			if ((*pptree)->_left == NULL){
				*pptree = cur->_right;
			}
			else if ((*pptree)->_right == NULL){
				*pptree = cur->_left;
			}
			else{
				BSTreeNode* parent = cur;
				BSTreeNode* sub = cur->_right;
				while (sub->_left){
					sub = sub->_left;
				}

				cur->_key = sub->_key;
				return BSTreeRemoveR(&(cur->_right), sub->_key);
			}
			return 0;
		}
	}

