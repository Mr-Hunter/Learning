#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>

enum OPPTION
{
	EXIT,
	ADD,
	SEARCH,
	DEIETE,
	MODIFY,
	SORT,
	SHOW,
	EMPTY
};

typedef char datatype;

#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TEL 11
#define MAX_ADDR 30
#define MAX_SIZE 1000

typedef struct PeoInfo
{
	datatype Name[MAX_NAME];
	datatype Sex[MAX_SEX];
	int age;
	datatype Tel[MAX_TEL];
	datatype Addr[MAX_ADDR];
}PeoInfo, *pPeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX_SIZE];
	int size;
}Contact,*pContact;

//��ʼ��ͨѶ¼
void InitContact(pContact pc);
//�����ϵ��
void AddContact(pContact pc);
//ɾ����ϵ��
void DeleteContact(pContact pc);
//�޸���ϵ��
void ModifyContact(pContact pc);
//������ϵ��
int SearchContact(pContact pc);
//��������
void SortContact(pContact pc);
//�б���ϵ��
void ShowContact(pContact pc);
//�����ϵ��
void EmptyContact(pContact pc);
 


#endif //__CONTACT_H__