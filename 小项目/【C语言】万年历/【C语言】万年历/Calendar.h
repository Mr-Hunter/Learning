#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define KEYUP 72   //�궨����̵ļ�ֵ��
#define KEYDOWN 80  //�궨����̵ļ�ֵ��
#define KEYLEFT 75   //�궨����̵ļ�ֵ��
#define KEYRIGHT 77  //�궨����̵ļ�ֵ��
const int isleap(int year);	//�ж�����
const int GetMonthDays(int year, int month);//����year��month�µ�����
const int YearDays(int year);//����year�������
const int isWeek(int year, int month, int day);//����year��month��day��Ϊ���ڼ�
void PrintCalendar(int year, int month);	//��ӡĳ��ĳ�µ�����
