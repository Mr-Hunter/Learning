/****************************************************
�ļ����ƣ�2048С��Ϸ
�ļ�������ʵ�ֿ���̨��2048�߼�����
���뻷����VS2013
����޸ģ�Hunter
�޸����ڣ�2018.7.10
���̡̳�����up����down����left����down��

****************************************************/
#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

extern int map[4][4]; //����һ����ά���� ��ʼ��Ϊ0.

void Print();  //��ӡ����
void Add(int);
void Move();
void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();
