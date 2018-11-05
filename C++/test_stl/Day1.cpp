#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h> 
#include <vector>
#include <algorithm>
using namespace std;

//��ʶSTL
void test01()
{
	//����
	vector<int> v;//����һ����������̬����
	v.push_back(10);//ͨ��vectorͨ����Ա������������β�����Ԫ��
	v.push_back(10);
	v.push_back(5);

			//       ��������ָ�룩
			//����-------------------�㷨

	//������
	vector<int>::iterator pStart = v.begin();//�õ�ָ���һ��Ԫ�صĵ�����
	vector<int>::iterator pEnd = v.end();//����ָ�����һ��Ԫ�ص���һ��λ��


	while (pStart != pEnd)
	{
		cout <<*pStart<< " ";
		pStart++;
	}
	cout << endl;

	//�㷨
	//countͳ��������ĳ��Ԫ�ظ���
	int n= count(v.begin(),v.end(),4);//��ʼ����������Ҫͳ�Ƶ�Ԫ��
	cout << " " << n << endl;

}
//��ϰ����
class Teacher
{
public:
	Teacher(int a, int b)
		:_a(a)
		,_b(b)
	{
	}

	int _a;
	int _b;
};
void test02()
{
	vector<Teacher> v;
	Teacher t1(1, 2), t2(3, 4), t3(5,6);
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);

	vector<Teacher>::iterator pStart = v.begin();
	vector<Teacher>::iterator pEnd = v.end();

	while (pStart!=pEnd)
	{
		Teacher t = *pStart;
		cout << t._a <<" "<< t._b << endl;
		pStart++;
	}
}
//���������Ͷ���ָ��
void test03()
{
	vector<Teacher*> v;//������Teacher����ָ��
	Teacher t1(1, 2), t2(3, 4), t3(5, 6);
	Teacher* p1 = &t1;
	Teacher* p2 = &t2;
	Teacher* p3 = &t3;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	vector<Teacher*>::iterator pStart = v.begin();
	vector<Teacher*>::iterator pEnd = v.end();

	while (pStart != pEnd)
	{
		Teacher* t = *pStart;
		cout << t->_a <<" "<< t->_b << endl;
		pStart++;
	}

}

int mycount(int* pStart, int* pEnd, int value)
{
	int n = 0;
	while (pStart != pEnd)
	{
		if (*pStart == value)
			n++;
		pStart++;
	}
	return n;
}
////STL��������ԭ��
void test04()
{
	int arr[] = { 3, 5, 6, 8 };
	int* pStart = arr;
	int* pEnd = &arr[sizeof(arr) / sizeof(int)];

	int n = mycount(pStart, pEnd, 8);
	cout << n << endl;
}

///////////////////////////����
//string

int main()
{
////STL��ʶ
	//test01();
	//test02();
	//test03();

////STL��������ԭ��
	//test04();


	system("pause");
	return 0;
}

