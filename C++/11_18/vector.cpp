#define _CRT_SECURE_NO_WARNINGS 1
# include "vector.h"

//capacity�仯
void test1()	
{
	vector<int> foo;
	int size = foo.size();
	for (int i = 0; i < 1000; ++i)
	{
		foo.push_back(i);
		if (size != foo.capacity())
		{
			size = foo.capacity();
			cout << "The size is variers :" << size << endl;

		}
		
	}

}
//find/insert/erase
void test2()
{
	int a[] = { 1, 2, 4, 6, 9,2, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//find ����3 ���ڵ�������λ��
	vector<int>::iterator pos = find(v.begin(),v.end(),4);

	//��posλ�ò���333
	v.insert(pos, 333);
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.begin(), v.end(),4);
	//ɾ��pos��λ��
	v.erase(pos);
	auto cit = v.begin();
	while (cit != v.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}
//operator[]+index֧�ֵı�����c++11������֧�ֵı�����ʽ
void test3()
{
	int a[] = { 1, 2, 4, 6, 9, 2, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	v[0] = 99;
	cout << v[0] << endl;

	//��������һ
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//����������
	//auto it = v.begin();
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;

	//����������
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}
//������ʧЧ���� 
//insert/erase���µ�����ʧЧ
void test4()
{
	int a[] = { 1, 2, 4, 6, 9, 99, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//�������൱��ָ�룬ָ��ǰλ��
	vector<int>::iterator pos = find(v.begin(), v.end(), 99);
	v.erase(pos);
	//�˴��ᵼ�·Ƿ�����
	cout << *pos << endl;

	//��posλ�ò��룬���µ�����ʧЧ��
	//insertʧЧ������Ϊ�������ݿ��ܻᵼ�����ݣ�
	//���ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��� ��
	pos = find(v.begin(), v.end(), 99);
	v.insert(pos, 30);
	//���·Ƿ�����
	cout << *pos << endl;
	
}

//����������ʧЧ����������������
void test5()
{
	int a[] = { 1, 2, 4, 6, 9, 2, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//ʵ��ɾ������ż��
	//��������������������ż����erase�ᵼ��itʧЧ
	//��ʧЧ��it�������ᵼ�³������
	vector<int>::iterator it = v.begin();
	while (it != v.begin())
	{
		if (*it % 2 == 0)//�˷������ã�Ӧ�Ľ� ��*it&0x1��
		{
			v.erase(it);
		}
		++it;  //׼ȷ˵��Խ����ɵĳ������
		//���ڵ�����ʧЧ��g++�����ǽ������ȷ���߱���vs��ɳ������

	}

	//���淽��Ӧ�øĽ�Ϊ
	vector<int>::iterator it = v.begin();
	while (it != v.begin())
	{
		if (*it % 2 == 0)//�˷������ã�Ӧ�Ľ� ��*it&0x1��
		{
			it = v.erase(it);
		}
		else
		{
			++it;

		}
	}

}
int main()
{
	 
	//test1();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}

