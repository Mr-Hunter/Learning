/*#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h> 
using namespace std;

class fruit
{
public:
	fruit(string kind)
	{
		this->kind = kind;
		if (kind == "apple")
		{  //����ƻ��
		}

		else if (this->kind == "banana")
		{
			//�����㽶
		}
	}

	void GetName()
	{
		if (kind == "apple")
			cout << "����ƻ��" << endl;

		else if (this->kind == "banana")
			cout << "�����㽶" << endl;
	}

private:
	string kind;//ˮ������
};
int main()
{
	//����һ��ƻ��
	fruit f("apple");
	f.GetName();

	//main������fruit��Ĺ��캯����϶�̫�ߣ�����ˮ����������ӣ����캯��Խ��Խ����
	system("pause");
	return 0;
}
���ѿ�����fruit����һ���޴���࣬�ڸ��������д������¼������⣺
��1����fruit���а����кܶࡰif...else...������飬�������д����൱�߳�������Խ�����Ķ��Ѷȣ�ά���Ѷȣ������Ѷ�ҲԽ�󣬶��Ҵ����������Ĵ��ڻ���Ӱ��ϵͳ�����ܣ�������ִ�й�������Ҫ�������������ж�
��2��fruit���ְ����أ��������ʼ������ʾ���е�ˮ�����󣬽�����ˮ������ĳ�ʼ������ʾ���뼯����һ������ʵ�֣�Υ���ˡ���һְ��ԭ�򡱣�������������ú�ά��
��3������Ҫ���������͵�ˮ��ʱ�������޸�fruit���Դ���룬Υ���ˡ�����ԭ��


*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h> 
using namespace std;

//����һ��ˮ�������࣬������ˮ��ʹ�ú͹���ʹ��
class fruit
{
public:
	virtual void GetName() = 0;

};

class Apple:public fruit
{
public:
	virtual void GeName()
	{
		cout << "����ƻ��" << endl;
	}
};
class Banana:public fruit
{
public:
	virtual void GeName()
	{
		cout << "�����㽶" << endl;
	}
};

//���һ����Ʒ��
//ֻ��Ҫ�ڴ���һ���༴��
class Pear:public fruit
{
public:
	virtual void GetName()
	{
		cout << "��������" << endl;

	}
};

//����
class factory
{
public:
	fruit* creat(string name)
	{
		if (name == "apple")
		{
			return new Apple;
		}
		else if (name == "banana")
		{
			return new Banana;
		}
		//����������factory�ͻ᲻���Ͽ���ԭ��
		else if (name == "pear")
			return new Pear;
	}
};
int main()
{
	factory* fac = new factory;
	fruit* fru = nullptr;
	/*
	�����ù�������һ�������ˮ���࣬���س�����ָ��
	��ͻᷢ����̬
	��ô��ʱ������ָ��ָ���˾�������࣬��ô���ó��󷽷�
	�ͻ���������ʵ�ַ���
	*/

	fru = fac->creat("apple");
	fru->GetName();
	delete fru;
	fru = nullptr;

	fru = fac->creat("banana");
	fru->GetName();
	delete fru;
	fru = nullptr;

	fru = fac->creat("pear");
	fru->GetName();
	delete fru;
	fru = nullptr;

	delete fac;
	return 0;
}

