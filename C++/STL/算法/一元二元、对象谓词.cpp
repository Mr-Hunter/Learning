#include "Algorithm.h"

//��������������һ������������һԪ��������
//�������������ܶ������������Ƕ�Ԫ��������

//����������������ͨ��������һ������������bool������һԪν��
//����������������ͨ�������ܶ�������������bool��������Ԫν��

//һԪ�������� for_each
class print
{
public:
	void operator()(int v)
	{
		cout <<v << endl;
	}

};
void print2(int v)
{
	cout << v << endl;

}
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//����ģ�壬��װ��for ,�����ˡ�()�� ,�������������һ���ص�����
	//for_each(v.begin(),v.end(),print());
	for_each(v.begin(),v.end(),print2);

	cout << endl;

}

//һԪν�� find_if
class compare
{
public:
	bool operator()(int v)
	{
		if (v > 7)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	/*
	template<class _InIt,
	class _Pr> inline
	_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	_DEBUG_RANGE(_First, _Last);
	_DEBUG_POINTER(_Pred);
	return (_Rechecked(_First,
	_Find_if(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}

	template<class _InIt,
	class _Pr> inline
	_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	for (; _First != _Last; ++_First)
	if (_Pred(*_First))
	break;
	return (_First);
	}

	*/
	vector<int>::iterator pos=find_if(v.begin(),v.end(),compare());  //������������
	if (pos == v.end())
	{
		cout << "mei" << endl;
	}
	else
	{
		cout << "zhaodao" << endl;
	}
}
//��Ԫ�������� transform
class func
{
public:
	int operator()(int v,int v1)
	{
		return v1 + v;

	}
};
void test3()
{

	vector<int> v,v1,v2;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i+1);

	}
	/*
	template<class _InIt1,
	class _InIt2,
	class _OutIt,
	class _Fn2> inline
	_OutIt transform(_InIt1 _First1, _InIt1 _Last1,
	_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	// transform [_First1, _Last1) and [_First2, ...) with _Func
	_DEBUG_RANGE(_First1, _Last1);
	_DEBUG_POINTER(_Dest);
	_DEBUG_POINTER(_Func);
	if (_First1 != _Last1)
	return (_Transform2(_Unchecked(_First1), _Unchecked(_Last1),
	_First2, _Dest, _Func,
	_Is_checked(_Dest)));
	return (_Dest);
	}

	template<class _InIt1,
	class _InIt2,
	class _OutIt,
	class _Fn2> inline
	_OutIt _Transform(_InIt1 _First1, _InIt1 _Last1,
	_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	// transform [_First1, _Last1) and [_First2, ...) with _Func
	for (; _First1 != _Last1; ++_First1, ++_First2, ++_Dest)
	*_Dest = _Func(*_First1, *_First2);
	return (_Dest);
	}
	*/
	v2.resize(v.size());

	for_each(v.begin(), v.end(), print2);

	cout << endl;
	for_each(v1.begin(), v1.end(), print2);

	cout << endl;
	for_each(v2.begin(), v2.end(), print2);

	cout << endl;
	transform(v.begin(),v.end(),v1.begin(),v2.begin(),func()); //������������
	cout <<"----------------------"<< endl;

	for_each(v.begin(), v.end(), print2);

	cout << endl;
	for_each(v1.begin(), v1.end(), print2);

	cout << endl;
	for_each(v2.begin(), v2.end(), print2);

	cout << endl;

}
//��Ԫν�� sort
class my
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;

	}
};
void test4()
{
	vector<int> v;
	v.push_back(9);
	v.push_back(33);
	v.push_back(3);
	v.push_back(77);
	sort(v.begin(),v.end(),my());
	for_each(v.begin(), v.end(), print2);

	cout << endl;
	for_each(v.begin(), v.end(), print2);

}