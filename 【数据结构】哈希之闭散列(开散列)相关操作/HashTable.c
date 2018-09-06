#include "HashTable.h"


//��ʼ��
void HashInit(HashTable* ht, int len)
{
	int i = 0;
	assert(ht&&len > 0);

	len = GetNextPrime(len);

	ht->data = (HashData*)malloc(sizeof(HashData)*len);
	if (ht->data == NULL)
	{
		perror("creat table");

	}
	//��ʼ������״̬
	ht->lenth = len;
	ht->size = 0;
	for (; i < ht->lenth; i++)
	{
		ht->data[i].state = EMPTY;
	}
}
//����
void HashDestroy(HashTable* ht)
{		
	assert(ht);
	ht->lenth = ht->size = 0;
	free(ht->data);
	ht->data = NULL;
}


//��ò���λ��
int  GetPosition(KeyType key,int lenth)
{
	return key%lenth;

	//�ַ���
	/*return StrHash(key)%lenth*/
}
//����
static void CheckCapacity(HashTable* ht)
{
	assert(ht);
	//˼�룺�½�һ����ԭ������������飬�������Ƶ��±����پɱ�,����ָ��
	
	
	//�Ƚϸ������ӣ�һ��Ҫ�����0.7-0.8֮�䣬�˴�����0.7֮��
	if (ht->size * 10 / ht->lenth > 7)
	{
		HashTable hht;
		int len = ht->lenth * 2;
		int j = 0;
		HashInit(&hht, len);
		for (j = 0; j < ht->lenth; j++)
		{
			if (ht->data[j].state == EXIST)
			{
				HashInsert(&hht, ht->data[j].key, ht->data[j].value);

			}
		}

		//���ٱ�����ָ��
		free(ht->data);
		ht->data = hht.data;
		ht->lenth = hht.lenth;
		ht->size = hht.size;
		printf("�ɹ�����\n");
	}
}
//��������
int HashInsert(HashTable* ht, KeyType key, ValueType value)
{
	assert(ht);
	//�������
	int i = 0;
	CheckCapacity(ht);
	////ֱ�Ӷ�ַ������ò���λ��
	int start = GetPosition(key, ht->lenth);
	int pos = start;

	//Ϊ�գ���ɾλ��ֱ�Ӳ壬������λ���г�ͻ��������Ҫ��ɢ�д����ͻ
	while (ht->data[pos].state == EXIST)
	{
		//�������ͬ���ݾͲ��ò���
		if (ht->data[pos].key == key)
			return 0;
		//��ɢ������̽�⣬����һ������λ��
		else

		{
			++pos;
			if (pos == ht->lenth){
			pos = 0;
			}
			//����̽��
			/*
			++i;
			pos = start + i*i;
			pos %= ht->lenth;*/
			
		}
	}
	//�ҵ�λ��ֱ�Ӳ���
	ht->data[pos].key = key;
	ht->data[pos].value = value;
	ht->data[pos].state = EXIST;
	ht->size++;
	return 1;
	
}
int HashRemove(HashTable* ht, KeyType key)
{
	assert(ht);
	////ֱ�Ӷ�ַ������ò���λ��
	HashData* tmp = HashFind(ht, key);
	if (tmp)
	{
		ht->size--;
		tmp->state= DELETE;
		return 1;
	}
	return 0;



}
//��������
HashData* HashFind(HashTable* ht, KeyType key)
{
	assert(ht);
	////ֱ�Ӷ�ַ������ò���λ��
	int pos = GetPosition(key, ht->lenth);;
	//���״̬Ϊ�գ���ɾֱ�ӷ���NULL�����ڵĻ����ж��Ƿ��ͻ�����Ҵ����ͻ��ֱ����λ�ú�Ϊ��״̬����
	while (ht->data[pos].state != EMPTY)
	{
		if (ht->data[pos].key == key)
		{
			if (ht->data[pos].state == EXIST)
			{
				return &ht->data[pos];
			}
			else
			{	 //״̬Ϊɾ��״̬��˵��Ҫ�ҵ������Ѿ���ɾ����ֱ�ӷ���
				return NULL;
			}

		}
		else
		{
			pos++;	
			if (pos == ht->lenth)
			{
				pos = 0;
			}
		}
	}
	return NULL;
}
//�����Ч����
int HashSize(HashTable* ht)
{
	assert(ht);
	return ht->size;
}
//�п�
int HashEmpty(HashTable* ht)
{
	assert(ht);
	return ht->size ==0;
}
//��ӡ
void HashPrint(HashTable* ht)
{
	assert(ht);
	int i = 0;
	char* a[3] = { "empty", "exist", "delete" };
	for (i = 0; i < ht->lenth; i++)
	{
		if (ht->data[i].state == EXIST)
		{
			printf("%s->ht->data[%d]->(%d:%d)\n",a[ht->data[i].state],i ,ht->data[i].key,ht->data[i].value);
		}
	}
	printf("\n");
}

//����
void testHashTable()
{
	HashTable ht;
	HashInit(&ht, 6);
	HashInsert(&ht,56,'e');
	HashInsert(&ht, 1, 't');
	HashInsert(&ht, 57, 'y');
	HashInsert(&ht, 88, 'u');
	HashInsert(&ht, 3, 'o');
	HashInsert(&ht, 4, 'e');
	HashInsert(&ht, 2, 'x');

	printf("changdu : %d��\n", HashSize(&ht));
	printf("weikong? : %d��\n", HashEmpty(&ht));

	HashPrint(&ht);

	HashData* tmp  = HashFind(&ht, 88);
	if (tmp)
	{
		printf("�ҵ�\n");
	}
	else
	{
		printf("����ʧ�ܡ�\n");
	}
	tmp = HashFind(&ht, 99);
	if (tmp)
	{
		printf("�ҵ�\n");
	}
	else
	{
		printf("����ʧ�ܡ�\n");
	}

	int o = HashRemove(&ht, 88);
	if (o)
	{
		HashPrint(&ht);

	}
	else
	{
		printf("ɾ��sha/ibai\n");
	}
	o = HashRemove(&ht, 22);
	if (o)
	{
		HashPrint(&ht);

	}
	else
	{
		printf("ɾ��sha/ibai\n");
	}
	printf("changdu : %d��\n",HashSize(&ht));
	printf("weikong? : %d��\n", HashEmpty(&ht));
	 


	HashDestroy(&ht);



}

