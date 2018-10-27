#pragma once

#include<iostream>
#include<Windows.h>
#include<cmath>
 
using namespace std;


//������ʵ�ֲ���������
class Date
{
public:
	 
	// ȫȱʡ�������캯��
	Date(int year = 1997, int month = 11, int day = 4)
		:_year(year)	//��ʼ���б�
		, _month(month)
		, _day(day)
	{
		//���Ϸ�
		if (year >= 0
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			cout <<"��ʼ��ok��"<< endl;
		}
		else
		{
			cout << "Date Invalid" << endl;
			exit(EXIT_FAILURE);
		}
	}
	//��������
	~Date()
	{
		;
	}

	//�������캯����Date d3(d1)���� Date d3 = d1
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ����������
	Date&  operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//ȡ��ַ����������
	Date* operator&()
	{
		return this;
	}

	//��ϵ����������
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	//��ȡ��������
	int GetMonthDay(int year, int month);

	//������������ã�������ʱֵ����
	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	Date& operator++();  
	Date operator++(int);  
	Date& operator--();  
	Date operator--(int);  

	//�������<<
	friend ostream& operator<<(ostream& _cout, const Date& d);

	//��������>>
	friend istream& operator>>(istream& _cin, Date& d);
	
private:
	int _year;
	int _month;
	int _day;
};

 