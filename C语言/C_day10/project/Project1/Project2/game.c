#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitMap(char arr[ROWS][COLS], int row, int col, char set)
{
	memset(arr, set, col*row*sizeof(arr[0][0]));
}

void PrintMap(char arr[ROWS][COLS], int row, int col)
{
		int i = 0;
		int j = 0;
		printf("   ");
		for (i = 1; i<=row ; i++)
		{
			printf("%3d", i);
		}
		printf("\n");
		for (i = 0; i<=row; i++)
		{
			printf("---");
		}
		printf("\n");
		for (i = 1; i <= row; i++)
		{								 
			printf("%2d|", i);
			for (j = 1; j <= col ; j++)
			{
				printf("%3c", arr[i][j]);
			}
			printf("\n");
		}
	 
}
void SetMy(char arr[ROWS][COLS], int row, int col, int count)
{
	
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

void SweepMap(char my_map[ROWS][COLS],char player_map[ROWS][COLS], int row, int col, int sum)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int temp = 0;
	int win = 0;
	
	while (win < (row * col - sum))
	{
		printf("��������ɨ������:>");
		scanf("%d%d", &x, &y);
		temp++;
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{

			while ((my_map[x][y] == '1') && (temp == 1))
			{
				//��֤��ҵ�һ�β���
				MoveLei(my_map, x, y);
				//����Χ���������б���
				GetCount(my_map, player_map, x, y);
			}

			if (my_map[x][y] == '1')
			{
				printf("\n��ϲ�㣬׳������\n");
				PrintMap(my_map, ROW, COL);
				break;
			}
			else
			{
				GetCount(my_map, player_map, x, y);
				printf("\n");
				win++;
			}
			PrintMap(player_map, ROW, COL);
		}
		else
		{
			printf("������������\n");
		}

	}
	if(win == (row * col - sum))
	{
		printf("��ϲ�㣬������\n");
	}
	
}

//��������������ף���Ҫ������Χ��ͳ������  
//����Χ���ף���ݹ������ͳ����Χ����  
void GetCount(char my_map[ROWS][COLS], char player_map[ROWS][COLS], int x, int y)
{


	if ((my_map[x][y] == '0'))
	{
		int count = 0;

		if (my_map[x - 1][y - 1] == '1')
			count++;

		if (my_map[x - 1][y] == '1')
			count++;

		if (my_map[x - 1][y + 1] == '1')
			count++;

		if (my_map[x][y - 1] == '1')
			count++;

		if (my_map[x][y + 1] == '1')
			count++;
		if (my_map[x + 1][y - 1] == '1')
			count++;

		if (my_map[x + 1][y] == '1')
			count++;

		if (my_map[x + 1][y + 1] == '1')
			count++;

		player_map[x][y] = (count + '0');
	}

	if (player_map[x][y] == '0')
	{
		if (player_map[x - 1][y - 1] == ' ')
			GetCount(my_map, player_map, x - 1, y - 1);

		if (player_map[x - 1][y] == ' ')
			GetCount(my_map, player_map, x - 1, y);

		if (player_map[x - 1][y + 1] == ' ')
			GetCount(my_map, player_map, x - 1, y + 1);

		if (player_map[x][y - 1] == ' ')
			GetCount(my_map, player_map, x, y - 1);

		if (player_map[x][y + 1] == ' ')
			GetCount(my_map, player_map, x, y + 1);

		if (player_map[x + 1][y - 1] == ' ')
			GetCount(my_map, player_map, x + 1, y - 1);

		if (player_map[x + 1][y] == ' ')
			GetCount(my_map, player_map, x + 1, y);

		if (player_map[x + 1][y + 1] == ' ')
			GetCount(my_map, player_map, x + 1, y + 1);
	}
}

//Ϊ�����Ϸ���飬������ҵ�һ��������ζ����ᱻը��  
void MoveLei(char my_map[ROWS][COLS], int x, int y)
{
	int ret = 1;
	do
	{
		my_map[x][y] = '0';
		while (ret)
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
			if (my_map[x][y] == '0')
			{
				my_map[x][y] = '1';
			}
			ret--;
		}
	} while (ret);
}


//��Ҷ���ȷ�����׵�λ�ã����Խ��б��
//void Mark1Mine(char player_map[ROWS][COLS])     
//{  		
//  int x = 0;  
//  int y = 0;  
//  printf("��������Ҫ��ǵ�λ�ã�<");  
//  scanf("%d%d", &x, &y);  
//  printf("\n");  
//  if (x == 0 && y == 0)  
//      return 0;  
//  else  
//      show[x][y] = '$';  
//}  