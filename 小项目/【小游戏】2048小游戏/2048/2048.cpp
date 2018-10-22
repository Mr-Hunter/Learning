#include "2048.h"

//��ӡ
void Print()
{
	printf("\n\t\t    ******��ӭ����2048С��Ϸ******\n");
	printf("\n\t\t\t�����������ש��������ש��������ש���������\n");
	printf("\t\t\t�� %2d �� %2d �� %2d �� %2d ��\n", map[0][0], map[0][1], map[0][2], map[0][3]);
	printf("\t\t\t�ǩ��������贈�������贈�������贈��������\n");
	printf("\t\t\t�� %2d �� %2d �� %2d �� %2d ��\n", map[1][0], map[1][1], map[1][2], map[1][3]);
	printf("\t\t\t�ǩ��������贈�������贈�������贈��������\n");
	printf("\t\t\t�� %2d �� %2d �� %2d �� %2d ��\n", map[2][0], map[2][1], map[2][2], map[2][3]);
	printf("\t\t\t�ǩ��������贈�������贈�������贈��������\n");
	printf("\t\t\t�� %2d �� %2d �� %2d �� %2d ��\n", map[3][0], map[3][1], map[3][2], map[3][3]);
	printf("\t\t\t�����������ߩ��������ߩ��������ߩ���������\n");

}

//������ֵ�ĺ���
//������ֵ�ĺ���  dir=0��һ�ν������ dir=1���� dir=2����  dir=3���� dir=4���� 
void Add(int dir)
{
	srand((unsigned int)time(NULL)); //�����
	int num, flag; //2 4
	int row, col;
	row = rand() % 4; //0-3
	col = rand() % 4; //0-3
	flag = rand() % 2; //flag 0 1
	if (flag == 0)
		num = 2;
	else
		num = 4;
	switch (dir)
	{
	case 0:
		map[row][col] = num;
		break;
	case 1: //��
		if (map[3][col] == 0) //�����һ��  �ж�һ���ǲ���0
		{
			map[3][col] = num;
		}
		else
		{
			for (col = 0; col < 4; col++)
			{
				if (map[3][col] == 0)
				{
					map[3][col] = num;
					break;
				}
			}
		}
		break;
	case 2: //��
		if (map[0][col] == 0)
		{
			map[0][col] = num;
		}
		else
		{
			for (col = 0; col < 4; col++)
			{
				if (map[0][col] == 0)
				{
					map[0][col] = num;
					break;
				}
			}
		}

		break;
	case 3: //��
		if (map[row][3] == 0)
		{
			map[row][3] = num;
		}
		else
		{
			for (row = 0; row < 4; row++)
			{
				if (map[row][3] == 0)
				{
					map[row][3] = num;
					break;
				}
			}
		}
		break;


	case 4: //��
		if (map[row][0] == 0)
		{
			map[row][0] = num;
		}
		else
		{
			for (row = 0; row < 4; row++)
			{
				if (map[row][0] == 0)
				{
					map[row][0] = num;
					break;
				}
			}
		}
		break;
	}
}

//���ƺ��� ���ط���
void Move()
{
	char ch; //�ַ�
	ch = _getch();//getchar()��Ҫ��ʾ���� ����enter֮����� getch()����ʾ ֱ�ӽ���
	switch (ch)
	{
	case 72://��
		MoveUp();
		break;

	case 80://��
		MoveDown();
		break;

	case 75:  //��
		MoveLeft();
		break;

	case 77:  //��
		MoveRight();
		break;
	}
	//return dir;
}


void MoveUp()
{
	int row, col, tep;

	for (col = 0; col < 4; col++)
	{
		//ʵ��һ�� �����ƶ�
		int n = 4;
		while (n--)
		{
			for (row = 0; row < 3; row++) //��0�� ÿһ�е���ֵ
			{
				if (map[row][col] == 0)
				{
					for (tep = row; tep < 3; tep++)
					{
						map[tep][col] = map[tep + 1][col];
						map[tep + 1][col] = 0;
					}
				}
			}
		}

		//ʵ�ּӷ�
		for (row = 0; row < 3; row++)
		{
			if (map[row][col] == map[row + 1][col])
			{
				map[row][col] *= 2;
				//map[row + 1][col] = 0; //��Ҫ�ɲ�Ҫ
				for (tep = row + 1; tep < 3; tep++)
				{
					map[tep][col] = map[tep + 1][col];
					map[tep + 1][col] = 0;
				}
			}
		}
	}
	Add(1);
}

void MoveDown()
{
	int row, col, tep;

	for (col = 0; col < 4; col++)
	{
		int n = 4;
		while (n--)
		{
			for (row = 3; row>0; row--)
			{
				if (map[row][col] == 0)
				{
					for (tep = row; tep > 0; tep--)
					{
						map[tep][col] = map[tep - 1][col];
						map[tep - 1][col] = 0;
					}
				}
			}
		}

		for (row = 3; row > 0; row--)
		{
			if (map[row][col] == map[row - 1][col])
			{
				map[row][col] *= 2;

				for (tep = row - 1; tep > 0; tep--)
				{
					map[tep][col] = map[tep - 1][col];
					map[tep - 1][col] = 0;
				}
			}
		}
	}
	Add(2);
}

void MoveLeft()
{
	int row, col, tep;

	for (row = 0; row < 4; row++)
	{
		int n = 4;
		while (n--)
		{
			for (col = 0; col < 3; col++)
			{
				if (map[row][col] == 0)
				{
					for (tep = col; tep <3; tep++)
					{
						map[row][tep] = map[row][tep + 1];
						map[row][tep + 1] = 0;
					}
				}
			}
		}

		for (col = 0; col < 3; col++)
		{
			if (map[row][col] == map[row][col + 1])
			{
				map[row][col] *= 2;

				for (tep = col + 1; tep <3; tep++)
				{
					map[row][tep] = map[row][tep + 1];
					map[row][tep + 1] = 0;
				}
			}
		}
	}
	Add(3);
}

void MoveRight()
{

	int row, col, tep;

	for (row = 0; row < 4; row++)
	{
		int n = 4;
		while (n--)
		{
			for (col = 3; col >0; col--)
			{
				if (map[row][col] == 0)
				{
					for (tep = col; tep >0; tep--)
					{
						map[row][tep] = map[row][tep - 1];
						map[row][tep - 1] = 0;
					}
				}
			}
		}

		for (col = 3; col >0; col--)
		{
			if (map[row][col] == map[row][col - 1])
			{
				map[row][col] *= 2;

				for (tep = col - 1; tep >0; tep--)
				{
					map[row][tep] = map[row][tep - 1];
					map[row][tep - 1] = 0;
				}
			}
		}
	}
	Add(4);
}
