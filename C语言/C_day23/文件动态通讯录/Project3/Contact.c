#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


//�������
void CheckCapacity(pContact pc)
{
	assert(pc);
	pPeoInfo *p = NULL;
	if (pc->size == pc->capacity)
	{
		p = (pPeoInfo)realloc(pc->data, (pc->capacity + 2)*sizeof(PeoInfo));
		if (p != NULL)
		{
			pc->data = p;

		}
		else
		{
			printf("\t\t\t����ʧ��");
			exit(EXIT_FAILURE);
		}

		pc->capacity += 2;
		printf("\t\t\t���ݳɹ�\n");
	}
}
//����
void LoadContact(pContact pc)
{   
	int i = 0;
	FILE* pfRead = fopen("contact.dat", "rb");
	PeoInfo tmp = { 0 };   //������ʱ��������ÿ�ζ�ȡ����Ϣ
	assert(pc);
	if (pfRead == NULL)
	{
		perror("the file to read");
		exit(EXIT_FAILURE);
	}

	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
			CheckCapacity(pc);
			pc->data[i] = tmp;
			i++;
			pc->size++;
	}
	
	fclose(pfRead);
	pfRead = NULL;

}
//����
void SaveContact(pContact pc)
{
	assert(pc);
	FILE *pfwrite = fopen("contact.dat", "wb");
    int i = 0;
	if (pfwrite == NULL)
	{
		perror("the file to write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i<pc->size; i++)
	{
		fwrite(pc->data+ i, sizeof(PeoInfo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
 	 
}

//��ʼ��ͨѶ¼
void InitContact(pContact pc)
{
	assert(pc);
	pc->size = 0;
	pc->capacity = 3;
	pc->data = (pPeoInfo)malloc((pc->capacity)*sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("\t\t\t�ڴ����ʧ��");
		exit(EXIT_FAILURE);
	}
	memset(pc->data, 0, sizeof(pc->data));
	LoadContact(pc);
}

//�����ϵ��
void AddContact(pContact pc)
{
	assert(pc);
	if (pc->size == MAX_SIZE)
	{
		printf("\t\t\t�ռ䲻��");
		return;
	}
	CheckCapacity(pc);
	printf("\t\t\t����������:>");
	scanf("%s", pc->data[pc->size].Name);
	printf("\t\t\t�������Ա�:>");
	scanf("%s", pc->data[pc->size].Sex);
	printf("\t\t\t����������:>");
	scanf("%d", &pc->data[pc->size].age);
	printf("\t\t\t������绰��:>");
	scanf("%s", pc->data[pc->size].Tel);
	printf("\t\t\t�������ַ:>");
	scanf("%s", pc->data[pc->size].Addr);
	pc->size++;
	printf("\t\t\t��ӳɹ�\n");
}
//������ϵ��
int SearchContact(pContact pc)
{
	char name[MAX_NAME];
	int i = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t�޴���ϵ��\n");
		return -1;
	}
	printf("\t\t\t");
	scanf("%s", name);
	printf("\t\t\tName\tSex\tAge\tTel\t\tAddr\n");
	for (i = 0; i < pc->size; i++)
	{
		if (0 == strcmp(pc->data[i].Name, name))
		{

			printf("\t\t\t%-5s\t%-5s\t%-5d\t%-12s\t%-15s\n",
				pc->data[i].Name,
				pc->data[i].Sex,
				pc->data[i].age,
				pc->data[i].Tel,
				pc->data[i].Addr);
			return i;
		}
	}
	printf("\t\t\t�޴���ϵ��\n");
	return -1;

}
//ɾ����ϵ��
void DeleteContact(pContact pc)
{
	int i = 0;
	int num = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t����ϵ��\n");
		return;
	}
	num = SearchContact(pc);
	if (num != -1)
	{
		int n = 0;
		printf("\t\t\tȷ��ɾ����  1.yes,  2.no:>");
		printf("\t\t\t");
		scanf("%d", &n);
		if (1 == n)
		{
			for (i = num; i < (pc->size) - 1; i++)
			{
				pc->data[i] = pc->data[i + 1];

			}
			pc->size--;
			printf("\t\t\tɾ���ɹ�\n");
		}
		else
		{
			return;
		}
	}

}

//����
void Swap(pPeoInfo *a, pPeoInfo *b)
{
	pPeoInfo *Tmp;
	Tmp = *a;
	*a = *b;
	*b = Tmp;

}


//�޸���ϵ��
void ModifyContact(pContact pc)
{
	int modify = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t����ϵ��\n");
		return;
	}
	modify = SearchContact(pc);
	if (modify != -1)
	{
		int n = 0;
		printf("\t\t\tȷ���޸ģ�1.yes  2.no:>");
		printf("\t\t\t");
		scanf("%d", &n);
		if (1 == n)
		{
			printf("\t\t\t����������:>");
			scanf("%s", pc->data[modify].Name);
			printf("\t\t\t�������Ա�:>");
			scanf("%s", pc->data[modify].Sex);
			printf("\t\t\t����������:>");
			scanf("%d", &pc->data[modify].age);
			printf("\t\t\t������绰��:>");
			scanf("%s", pc->data[modify].Tel);
			printf("\t\t\t�������ַ:>");
			scanf("%s", pc->data[modify].Addr);
			printf("\t\t\t�޸ĳɹ�\n");


		}
		else
		{
			return;
		}
	}


}
//��������
void SortContact(pContact pc)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t����ϵ��\n");
		return;
	}
	// ð�ݴ���
	for (i = 0; i < pc->size - 1; i++)
	{
		//ð������
		for (j = 0; j < pc->size - i - 1; j++)
		{
			if (strcmp(pc->data[j].Name, pc->data[j + 1].Name)>0)
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
	printf("����ɹ�\n");
}
//�б���ϵ��
void ShowContact(pContact pc)
{
	int i = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t����ϵ��\n");
		return;
	}
	printf("\t\t\tName\tSex\tAge\tTel\t\tAddr\n");
	for (i = 0; i < pc->size; i++)
	{
		printf("\t\t\t%-5s\t%-5s\t%-5d\t%-12s\t%-15s\n",
			pc->data[i].Name,
			pc->data[i].Sex,
			pc->data[i].age,
			pc->data[i].Tel,
			pc->data[i].Addr);

	}

}
//�����ϵ��
void EmptyContact(pContact pc)
{
	assert(pc);
	pc->size = 0;
	printf("\t\t\t��ճɹ�");
}
//����ͨѶ¼
void DestoryContact(pContact pc)
{
	assert(pc);
	SaveContact(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->size = 0;
	printf("\t\t\t���ٳɹ�");
}