#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
void meau()
{
	printf("****************************************\n");
	printf("**********     1.play         **********\n");
	printf("**********     0.exit         **********\n");
	printf("****************************************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int put = 0;
	while (1)
	{
		printf("������һ����\n");
		scanf("%d",&put);
		if (put > ret)
		{
			printf("�������\n");
		}
		else if (put < ret)
		{
			printf("����С��\n");
		}
		else
		{
			printf("��ϲ�㣬�������Ʊ��\n");
			break;
		}
		 
	}
	

}
int main()
{

	int input = 0;
	srand((unsigned)time(NULL));
	do{
		meau();
		printf("������-��");
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:game();
			break;
		case 0:
			break;
		default:
			printf("��������");
			break;
		}
	} while (input);
	 
	return 0;
}

