#include "Calendar.h"
const int isLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	return 0;
}
const int GetMonthDays(int year, int month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (isLeap(year))
			return 29;
		return 28;
		break;
	default:
		return 0;
		break;
	}
}
const int YearDays(int year)
{
	if (isLeap)
		return 366;
	return 365;
}
const int isWeek(int year, int month, int day)
{
	int days = 0;
	int i = 0;
	for (i = 1; i < year; i++)
		days += YearDays(i); //����ǰyear���ж�����
	for (i = 1; i < month; i++)
		days += GetMonthDays(year, i);//����ǰmonth�����ж�����
	days += day;
	return days % 7;
}
void PrintCalendar(int year, int month)
{
	int i = 0;
	int rows = 0;
	const char* week[] = { "��", "һ", "��", "��", "��", "��", "��" };
	for (i = 0; i < 7; i++)
		printf("%5s\t", week[i]);
	printf("\n\n");
	//�ж�month�µĵ�һ��Ϊ���ڼ�
	for (i = 0; i < isWeek(year, month, 1); i++)
		printf("\t");
	for (i = 0; i < GetMonthDays(year, month); i++)
	{
		printf("%5d\t", i + 1);
		//������������ͻ��д�ӡ
		if (isWeek(year, month, i + 1) == 6)
		{
			rows++;
			if (rows == 1)
				printf("      ��:year - 1");
			if (rows == 2)
				printf("      ��:year + 1");
			if (rows == 3)
				printf("      ��:month - 1");
			if (rows == 4)
				printf("      ��:month + 1");

			printf("\n");
			printf("\n");
		}
	}
	printf("\n");
}