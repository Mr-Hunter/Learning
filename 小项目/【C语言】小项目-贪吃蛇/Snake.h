#ifndef __SANKE_H__
#define __SANKE_H__

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>


#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define stop 'p'

/*ȫ�ֱ��� + Ԥ����*/
typedef struct Snakes
{
	int x;
	int y;
	struct Snakes *next;
}snake;



struct Food
{
	int x;
	int y;
}food;

extern snake *head, *tail;
extern char name[20];
extern int score ;
extern char click;
extern int speed;



void welcome();               //��ʼ����
void Finish();                //��������
void creatgraph();            //Χǽ��ӡ
void gotoxy(int x, int y);    //�����ת����ΪX 0,1,2..
void gotoprint(int x, int y); //��ת��ӡ
void gotodelete(int x, int y);//��תɾ��
void creatfood();             //ʳ�����
int ClickControl();           //��ȡ�����ź�
int Judge();                  //��Ϸ�����ж�
void MovingBody();			  //�ߵ��ƶ� 
void Eating();                //�߳Ե�������Ĳ������쳤��
void ChangeBody(int a, int b); //�ߵ�����任,��һ������ǰһ��STRUCT,a,bΪhead֮ǰ���� 





#endif //__SANKE_H__