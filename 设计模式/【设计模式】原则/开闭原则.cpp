#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
/*
class bank
{
public:
	void save()
	{
		cout << "���"<<endl;
	}
	void pay()
	{
		cout << "֧��"<<endl;
	}
	void transfer()
	{
		cout << "ת��"<<endl;
	}

	//���һ����ҵ��
	void jijin()
	{
		cout << "����"<< endl;
	}	 д�겻��д���룬Υ����һԭ������¼��빤�������⣬ϵͳ�ͱ���
};	 */

//���� ҵ��Ա��
class abstractbank
{
public:
	virtual void work() = 0; //������ӿ�

};
//���
class save :public abstractbank
{
public:
	virtual void work()
	{
		cout << "���"<< endl;
	}

};
//֧��
class pay :public abstractbank
{
public:
	virtual void work()
	{
		cout <<"֧��" << endl;
	}

};
//ת��
class transfer :public abstractbank
{
public:
	virtual void work()
	{
		cout << "ת��"<< endl;
	}

};

//��ӻ���
class add : public abstractbank
{
public:
	virtual void work()
	{
		cout << "����" << endl;
	}
	
};
int main()
{
	abstractbank *sb = new save;
	sb->work();

	sb->work();
	delete sb;


	system("pause");
	return 0;
}
//�Ľ����¼ӹ��ܲ���Ӱ��ԭ�й���
