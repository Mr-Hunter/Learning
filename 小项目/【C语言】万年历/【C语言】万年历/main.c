#define _CRT_SECURE_NO_WARNINGS 1
#include "Calendar.h"
void main()
{
	int year = 0;
	int month = 0;
	int action = 0;//��ȡ��ǰ������·�
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	year = p->tm_year + 1900;//��ȡ���ص�ǰ���
	month = p->tm_mon + 1;//��ȡ���ص�ǰ���·�
	while (1)
	{
		printf("\n             \t\t %d �� %d ��\n\n", year, month);
		PrintCalendar(year, month);
		action = _getch();
		system("cls");//windows����
		switch (action)
		{
		case KEYUP:
			year--;
			break;
		case KEYDOWN:
			year++;
			break;
		case KEYLEFT:
			if (month == 1)
			{
				month = 12;
				year--;

				break;
			}
			month--;
			break;
		case KEYRIGHT:
			if (month ==12)
			{
				year++;
				month = 1;
				break;
			}
			month++;
			break;
		}
	}
}