#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h> 
using namespace std;

class Cat
{
public:
	void sleep()
	{
		cout << "˯��"<< endl;
	}
};

//����һ���µ�è��������һ�����ܣ�����˯�����ܳԶ���
//���Cat�кุܶ�࣬cat�ĸ�����AddCat����ϣ����Ӷȸ�
//ͨ���̳����
class AddCat:public Cat
{
public:
	void eat()
	{
		cout << "�Է�"<< endl;
		sleep();
	}
};

//ʹ����Ϸ�ʽ��ӳԶ���
//ʹ����Ͻ���Add2Cat��Cat��ϣ���Cat����û���κι�ϵ��
//ֻ��Cat��slepp�й�ϵ
class Add2Cat
{
public:
	Add2Cat(Cat* cat)
	{
		this->cat = cat;
	}
	void eat(Cat* cat)
	{
		cout <<"�Է�" << endl;
		cat->sleep();
	}
private:
	Cat* cat;
};
int main()
{
	Cat c;
	c.sleep();

	AddCat ac;
	ac.eat();

	Add2Cat ac(&c);
	ac.eat();

	system("pause");
	return 0;
}

