#include "STL.h"
////////////////////////////vector
//��ʼ��
void test8()
{
	vector<int> v;	//Ĭ��
	vector<int> v2(10, 5);//���������죬10��5
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);//��������

	int arr[] = { 2, 4, 5, 6 };
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(int));

	for (int i = 0; i < v5.size(); ++i)
	{
		cout << v5[i] << " ";
	}
	cout << endl;

}
//Demo(����)
void print(vector<int>& a)
{
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test9()
{
	vector<int> v;
	vector<int> v1;

	for (int i = 0; i < 5; ++i)
	{
		v.push_back(i);
	}

	for (int i = 6; i < 10; ++i)
	{
		v1.push_back(i);
	}
	print(v);
	print(v1);
	v.swap(v1);
	cout << " ������" << endl;
	print(v);
	print(v1);

	//swapС����
	vector<int> v3;
	v3.resize(100);

	v3.clear();	//���Ԫ��
	v3.push_back(2);
	v3.push_back(2);


	cout << "����" << v3.capacity() << endl;
	cout << "��С" << v3.size() << endl;  //��ЧԪ��

	//��Լ�ռ䣬��ʱ������Ҫ���ڴ�
	//�ֽ⣺vector<int> v2(v3);v2.swap(v3);����v2�������ڳ�
	//������������һ��
	vector<int>(v3).swap(v3);

	cout << "����" << v3.capacity() << endl;
	cout << "��С" << v3.size() << endl;  //��ЧԪ��

}
//��ֵ
void test10()
{
	vector<int> v;
	v.assign(5, 1);//5��1

	vector<int> v1;
	v1.assign(v.begin(), v.end());

	vector<int> v2;
	v2 = v1;
}
//��С
void test11()
{
	int arr[] = { 2, 45, 6, 7, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	cout << "size" << v.size() << endl;
	cout << "���� " << v.capacity() << endl;

	if (v.empty())
	{
		cout << "kong" << endl;
	}
	else
	{
		cout << "feikong" << endl;
	}

}
//��ȡ
void test12()
{
	int arr[] = { 2, 45, 6, 7, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	try
	{
		//cout << v[100]<< endl; //����
		cout << v.at(300);	//�쳣
	}
	catch (...)//���������쳣
	{
		cout << "Խ��" << endl;
	}

	cout << "first" << v.front() << endl;
	cout << "back" << v.back() << endl;

}
//���� ɾ��
void test13()
{
	int arr[] = { 2, 45, 6, 7, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	v.insert(v.begin(), 100);
	v.push_back(89);
	cout << v.back() << endl;

	vector<int>::iterator pStart = v.begin();
	vector<int>::iterator pEnd = v.end();

	while (pStart != pEnd)
	{
		cout << *pStart << " ";
		pStart++;
	}
	cout << endl;

	v.pop_back();
	v.erase(v.begin());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	v.erase(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << v.size();
	cout << v.capacity();
	cout << endl;

}
//vector ����ԭ��
void test14()
{
	int count = 0;
	vector<int> v;
	int* p = NULL;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}

	}
	cout << count << endl;;	//30
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
//reserve Ԥ���ռ�
void test15()
{
	int count = 0;
	vector<int> v;
	//ֱ�����������룬���ٿ��٣��������ͷŵĿ���
	//������Ч��
	v.reserve(100000);

	int* p = NULL;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}

	}
	cout << count << endl;;	//1
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}