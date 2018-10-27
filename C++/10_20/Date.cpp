#include "Date.h"

//��ȡ��������
int Date::GetMonthDay(int year, int month)
{
	//����һ��ʮ����if��else���
	//��������switch��֧���
	//�˴���������
	 static const int days[13] = {0, 31,28, 31,30, 31,30, 31,31,30, 31,30, 31 };//������¶�һ��
	 //4��һ����겻��400��һ���Ҵ˴����ڶ����й�
	 if ((month == 2)&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	 {
		 return 29;

	 }
	 return days[month];
}

//�������ϵ����������
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d. _month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}
 
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// d1 >= d2
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}


//���������������
// d1 + 100	  
//��+days���ڸ���������ʱ����days��ȥ�����������·�month+1����ֵ��Ϊ���·ݵ�������
//��������ĩ����month = 12ʱ�����year++���·�month��1������month++��
Date Date::operator+(int day)
{
	Date ret(*this);

	/*if (day<0)
		return ret - abs(day);
	ret._day += day;

	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._day -= GetMonthDay(ret._year,ret._month);
		if (12 == ret._month)
		{
			ret._year++;
			_month = 1;

		}
		else
		{
			_month += 1;
		}
	}*/
	//�Ľ���
	ret += day;

	return ret;
}

Date& Date::operator+=(int day)
{
	if (day<0)
	{
		return *this - abs(day);
	}
	
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (12 == _month)
		{
			_year++;
			_month = 1;

		}
		else
		{
			_month += 1;
		}
	}
	return *this;
}
//����+days���ƣ��ø�������-days��
//���ֵ��С��0����������������year--�����·�month=12������month--��
Date Date::operator-(int day)
{
	Date ret(*this);

	/*if (day < 0)
		return ret + abs(day);
	ret._day -= day;
	while (ret._day <= 0)
	{

		if (ret._month == 1)
		{
			ret._year--;
			ret._month = 12;
		}
		else
		{
			ret._month--;
		}
		ret._day += GetMonthDay(ret._year,ret._month);

	}*/
	//�Ľ�:
	ret -= day;

	return ret;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this + abs(day);
	_day -= day;
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
		}
		_day += GetMonthDay(_year,_month);

	}
	return *this;
}
//�������������һ������ķ���������ǰ���󿽱�����ΪMax�����ö��󿽱�����ΪMin��
//���Max<Min�����ÿ⺯������������һ��״̬��flag��ǡ�������whileѭ����
//ֻҪMax��Min����ȣ�Max--��������days++��days��Ϊ���յ����������
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date Max(*this);
	Date Min(d);
	if ((*this) < d)
	{
		std::swap(Max, Min);
		flag = -1;
	}
	int days = 0;
	while (Max != Min)
	{
		--Max;
		++days;
	}
	return days*flag;
}
//�� + 1����Ӧ�ÿ�������Ϊ��ĩ���·�Ϊ��ĩʱ�����������
//ͨ���ж���ĩ����ĩ����ָ�����·� + 1����� + 1���������·� = 1��
Date& Date::operator++()// ++d => d.operator++(&d)
{
	/*_day++;
	if (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}*/
	//�Ľ���
	*this += 1;

	return *this;

}
//������++��ǰ��++���ƣ�����ֵ���в��죬
//���Կ�������һ����ʱ�ĺ���������thisָ�뱣������ݣ����շ�����ʱ�ĺ�����
Date Date::operator++(int)// d++ => d.operator(&d, 0)
{
	Date ret(*this);

	/*_day++;
	if (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}*/
	//�Ľ���
	*this += 1;

	return ret;

}
// ��-1����Ӧ�ÿ�������Ϊ�³����·�Ϊ���ʱ�����������
//ͨ���ж���ĩ����ĩ����ָ�����·�-1�����-1���������·�=12��
Date& Date::operator--() // --d 
{
	/*_day--;
	if (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
		}
		_day += GetMonthDay(_year, _month);
	}*/
	//�Ľ���
	*this -= 1;

	return *this;
}
//����ǰ��--���ƣ�����ʹ�ÿ������캯������һ����ʱ�ĺ��������շ�����ʱ�������ɣ�
Date Date::operator--(int) // d--
{
	Date ret(*this);

	/*_day--;
	if (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
		}
		_day += GetMonthDay(_year, _month);
	}*/
	//�Ľ�
	*this -= 1;

	return ret;
}
// ������� <<
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}
//��������>>
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}