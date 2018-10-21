#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("***** ����������Ϸ��*****\n");
	printf("******   1.play   *******\n");
	printf("******   0.exit   *******\n");
	printf("*************************\n");
	printf("*************************\n");
}

void game()
{
	char ret;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	while (1)
	{
		printf("����ߣ�\n");
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
		printf("�����ߣ�\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
	}
	if (ret == 'X')
	{
		printf(" ��Ӯ�ˣ�\n");
	}
	else if (ret == '0')
	{
		printf(" ������\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}

void test()
{

	int input = 0;
	srand((uint)time(NULL));
	do {
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case START:
			game();
			break;
		case EXIT:
			break;
		default:
			break;
		}

	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}