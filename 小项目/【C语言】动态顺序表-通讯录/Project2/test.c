/***********************************************************
*                      �������ƣ�ͨѶ¼����̬˳���     *
*                      ���뻷����VS2013                    *
*                      �������ڣ�2018.5.28                 *
*                                      -----by Hunter	   *
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
void meau()
{
	printf("\t\t\t******         ��ͨѶ¼��       ********\n");
	printf("\t\t\t****************************************\n");
	printf("\t\t\t****** 1.�����Ϣ       2.������Ϣ******\n");
	printf("\t\t\t****** 3.ɾ����Ϣ       4.�޸���Ϣ******\n");
	printf("\t\t\t****** 5.��������       6.��Ϣ�б�******\n");
	printf("\t\t\t****** 7.�����Ϣ       0.�˳�    ******\n");
	printf("\t\t\t****************************************\n");
}

void test()
{
	int input = 0;
	Contact pc;
	InitContact(&pc);
	do
	{
		meau();
		printf("\t\t\t��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&pc);
			break;
		case SEARCH:
			SearchContact(&pc);
			break;
		case DEIETE:
			DeleteContact(&pc);
			break;
		case MODIFY:
			ModifyContact(&pc);
			break;
		case SORT:
			SortContact(&pc);
			break;
		case SHOW:
			ShowContact(&pc);
			break;
		case EMPTY:
			EmptyContact(&pc);
			break;
		case EXIT:
			exit(1);
			break;
		default:
			printf("\t\t\t������������������:>");
			break;
		}

	} while (input);

}

int main()
{
	Contact pc;
	test();
	system("pause");
	//����ͨѶ¼
	DestoryContact(&pc);
	return 0;
}

