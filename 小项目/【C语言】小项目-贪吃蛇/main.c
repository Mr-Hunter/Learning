#define _CRT_SECURE_NO_WARNINGS 1

#include "Snake.h"

snake *head, *tail;
char name[20];
int score = 0;
char click = 1;
int speed;


int main()
{
	system("color 0A");	  //����color�����0�Ǳ���ɫ���ţ�A��ǰ��ɫ����
	welcome();
	creatgraph();
	creatfood();
	if (ClickControl() == 0) return 0;
	return 0;
}