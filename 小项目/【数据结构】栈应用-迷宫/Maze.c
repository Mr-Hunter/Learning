#include "Maze.h"

//�򵥰�
/*static int CheckAccess(pos next)
{
	if ((maze[next.row][next.col] == 1)
		&& next.col >= 0 && next.col < N
		&& next.row >= 0 && next.row < N)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
int GetMazePath(pos entry, pos exit)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, entry);


	while (!StackEmpty(&s))
	{
		pos pCur = StackTop(&s);
		pos next;
		maze[pCur.row][pCur.col] = 2;

		if ((pCur.col == exit.col)&&(pCur.row == exit.row))
		{
			printf("�ҵ�ͨ·�ˣ�\n");
			StackDestory(&s);
			return 1;
		}
		//��
		next = pCur;
		next.row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&s, next);
			continue;

		}
		//��
		next = pCur;
		next.row += 1;
		if (CheckAccess(next))
		{
			StackPush(&s, next);
			continue;

		}
		//��
		next = pCur;
		next.col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&s, next);
			continue;

		}//��
		next = pCur;
		next.col += 1;
		if (CheckAccess(next))
		{
			StackPush(&s, next);
			continue;

		}
		//����
		StackPop(&s);

	}


}
void PrintMaze()
{
	size_t i = 0;
	for (i=0; i < N; i++)
	{
		size_t j = 0;
		for (j=0; j < N; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void test()
{
	pos entry, exit;
	entry.col = 2;
	entry.row = 5;
	exit.col = 5;
	exit.row = 4;
	PrintMaze(maze[N][N]);

	printf("%d \n", GetMazePath(entry, exit));
	PrintMaze(maze[N][N]);

} */

////���װ�-������
//static int CheckAccess(pos next)
//{
//	if ((maze[next.row][next.col] == 1)
//		&& next.col >= 0 && next.col < N
//		&& next.row >= 0 && next.row < N)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int GetMazePath(pos entry)
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, entry);
//
//	int ShortPath = 0;
//
//	while (!StackEmpty(&s))
//	{
//		pos pCur = StackTop(&s);
//		pos next;
//		maze[pCur.row][pCur.col] = 2;
//
//		if (pCur.col==5)
//		{
//			if ((ShortPath == 0) || (StackSize(&s) < ShortPath))
//				ShortPath = StackSize(&s);
//		}
//		//��
//		next = pCur;
//		next.row -= 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&s, next);
//			continue;
//
//		}
//		//��
//		next = pCur;
//		next.row += 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&s, next);
//			continue;
//
//		}
//		//��
//		next = pCur;
//		next.col -= 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&s, next);
//			continue;
//
//		}//��
//		next = pCur;
//		next.col += 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&s, next);
//			continue;
//
//		}
//		//����
//		StackPop(&s);
//
//	}
//
//	StackDestory(&s);
//	return ShortPath;
//}
//void PrintMaze()
//{
//	size_t i = 0;
//	for (i = 0; i < N; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < N; j++)
//		{
//			printf("%d ", maze[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//void test()
//{
//	pos entry;
//	entry.col = 2;
//	entry.row = 5;
//	PrintMaze(maze[N][N]);
//
//	printf("���·�� ��%d \n", GetMazePath(entry));
//	PrintMaze(maze[N][N]);
//
//}

//���װ�-����
static int CheckAccess(pos pCur,pos next)
{
	if (((maze[next.row][next.col] == 1)
		||(maze[next.row][next.col]>maze[pCur.row][pCur.col]+1))
		&& next.col >= 0 && next.col < N 
		&& next.row >= 0 && next.row < N)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
int GetMazePath(pos entry)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, entry);
	maze[entry.row][entry.col] = 2;


	int ShortPath = 0;

	while (!StackEmpty(&s))
	{
		pos pCur = StackTop(&s);
		pos next;

		if (pCur.col == 5)
		{
			if ((ShortPath == 0) || (StackSize(&s) < ShortPath))
				ShortPath = StackSize(&s);
		}
		//��
		next = pCur;
		next.row -= 1;
		if (CheckAccess(pCur,next))
		{
			maze[next.row][next.col] = maze[pCur.row][pCur.col] + 1;
			StackPush(&s, next);
			continue;

		}
		//��
		next = pCur;
		next.row += 1;
		if (CheckAccess(pCur, next))
		{
			maze[next.row][next.col] = maze[pCur.row][pCur.col] + 1;
			StackPush(&s, next);
			continue;

		}
		//��
		next = pCur;
		next.col -= 1;
		if (CheckAccess(pCur, next))
		{
			maze[next.row][next.col] = maze[pCur.row][pCur.col] + 1;

			StackPush(&s, next);
			continue;

		}//��
		next = pCur;
		next.col += 1;
		if (CheckAccess(pCur, next))
		{
			maze[next.row][next.col] = maze[pCur.row][pCur.col] + 1;

			StackPush(&s, next);
			continue;

		}
		//����
		StackPop(&s);

	}

	StackDestory(&s);
	return ShortPath;
}
void PrintMaze()
{
	size_t i = 0;
	for (i = 0; i < N; i++)
	{
		size_t j = 0;
		for (j = 0; j < N; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void test()
{
	pos entry;
	entry.col = 2;
	entry.row = 5;
	PrintMaze(maze[N][N]);

	printf("���·�� ��%d \n", GetMazePath(entry));
	PrintMaze(maze[N][N]);

}