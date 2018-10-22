#ifndef __MAZE_H__
#define __MAZE_H__

#include "Stack.h"

#define N 6

//�򵥰�
//static int maze[N][N] = {
//	{ 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 },
//};
//int GetMazePath(pos entry, pos exit);

////���װ�-������
//static int maze[N][N] = {
//	{ 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 },
//};

//���װ�-����
static int maze[N][N] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
};


int GetMazePath(pos entry);
void PrintMaze();
void test();

#endif //__MAZE_H__