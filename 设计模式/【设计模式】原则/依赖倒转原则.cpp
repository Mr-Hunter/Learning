#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*class benchi
{
public:
	void run()
	{
		cout << "��������" << endl;
	}
};

class bm
{
public:
	void run()
	{
		cout << "��������" << endl;
	}
};
class zhangsan
{
public:
	void drivebenchi(benchi* b)
	{
		b->run;
	}
	void drivebm(bm* b)
	{
		b->run;
	}
};*/	

//�Ľ�������˶��ˣ������Ͷ࣬��ô�ͻ���ң����ӣ����Կ��Գ�ϲ��ϲcar��˾����
//�����
class Driver
{
public:
	virtual void drive(Car* car) = 0;
};

class Car
{
public:
	virtual void run() = 0;

};

//ʵ�ֲ�

class zhangsan:public Driver
{
public:
	virtual void drive(Car* car)
	{
		cout << "zhangsan" << endl;
		car->run;
	}
};

class lisi:public Driver
{
public:
	virtual void drive(Car* car)
	{
		cout << "lisi" << endl;
		car->run;
	}

};
class benchi :public Car
{
public:
	virtual void run()
	{
		cout << "benchi" << endl;
	}

};
class bm :public Car
{
public:
	virtual void run()
	{
		cout << "bm" << endl;
	}

};
int main()
{
	/*//����������
	benchi *b = new benchi;
	zhangsan *z = new zhangsan;
	z->drivebenchi(b);

	//����������
	bm *m= new bm;
	z->drivebm(m);
	 */

	//�ŵ㣺���õ�����
	//�߼�����ʵ�ֲ�ͨ������������������
	//zhangsan������
	Car	*b = new benchi;
	Driver *d = new zhangsan;
	d->drive(b);
	delete(b);
	delete(d);

	//lisi������
	Car	*b = new bm;
	Driver *d = new lisi;
	delete(b);
	delete(d);

	d->drive(b);
	system("pause");
	return 0;
}
