#ifndef __HSAH_H__
#define __HSAH_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//key-valueģ��

typedef int KeyType;
typedef char ValueType;

//��������״̬
typedef enum State
{
	EMPTY,	//����������
	EXIST,	//����
	DELETE  //��ɾ��
}State;

//������������
typedef struct HashData
{
	State  state; //����״̬
	KeyType key;  //������ֵ
	ValueType value;  
}HashData;
typedef struct HashTable
{
	HashData* data;//���ö�̬����ʵ��
	int size;	//��Ч���ݸ���
	int lenth;  //��
	

}HashTable;

//��ʼ��
void HashInit(HashTable* ht,int len);
//����
void HashDestroy(HashTable* ht);

//��������
int HashInsert(HashTable* ht, KeyType key,ValueType value);
//ɾ������
int HashRemove(HashTable* ht,KeyType key);
//��������
HashData* HashFind(HashTable* ht,KeyType key);
//�����Ч����
int HashSize(HashTable* ht);
//�п�
int HashEmpty(HashTable* ht);
//��ӡ
void HashPrint(HashTable* ht);

//����
void testHash();




#endif //__HSAH_H__