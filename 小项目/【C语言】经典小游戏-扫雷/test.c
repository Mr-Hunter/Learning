#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

void GotoXY(int x, int y) //�趨���λ��
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void meau()
{
	GotoXY(10, 5); printf("��ʼ��Ϸ\n         Let's Go!");
	Sleep(1500);
	system("cls");
	printf("        ��ɨ�ס�        \n");
	printf("                        \n");
	printf("         1.play         \n");
	printf("         0.exit         \n");
	printf("                        \n");
}

void game()
{
	int input = 0;
	int sum = 0;
	char my_map[ROWS][COLS];
	char player_map[ROWS][COLS];

	InitMap(my_map,ROWS,COLS,'0');
	InitMap(player_map, ROWS, COLS, ' ');

	printf("     1.Easy 0.Hard      \n");
	scanf("%d", &input);
	switch (input)
	{
		case PLAY:
			sum = EASY;
			break;
		case EXIT:
			sum = HARD;
			break;
		default:
			printf("��������\n");
			break;
	}
	printf("\n���������%d���ס�\n", sum);
	SetMy(my_map,ROW,COL,sum);

	PrintMap(player_map, ROW, COL);
	PrintMap(my_map, ROW, COL);
	SweepMap(my_map,player_map ,ROW, COL, sum);
	system("pause");
}



void test()
{	 
	int input = 0;
	do
	{
		meau();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("�������\n");
			break;
		}

	} while (input);
}

int main()
{
	srand((unsigned)time(NULL));
	test();
	system("pause");
	return 0;
}