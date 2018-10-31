#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h>
using namespace std;

//�����
class CPU
{
public:
	virtual void caculate() = 0;
};
class Card
{
public:
	virtual void dispaly() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};

//�ܹ��� ���������г����ࣩ
class computer
{
public:
	computer(CPU* cpu, Card* card, Memory* mermory)
	{
		this->cpu = cpu;
		this->card = card;
		this->memory = memory;

	}
	void work()
	{
		cpu->caculate();
		card->dispaly();
		memory->storage();
	}
private:
	CPU* cpu;
	Card* card;
	Memory* memory;
};

//ʵ�ֲ� ���Ǹ�����������
class interCPU:public CPU
{
public:
	void caculate()
	{
		cout <<"caculaet"<<endl;

	}
};
class interCard:public Card
{
public:
	void display()
	{
		cout << "display" << endl;

	}
};
class interMemory:public Memory
{
public:
	void storage()
	{
		cout << "storage" << endl;

	}
};
//��ҵ���
int main()
{
	CPU* cpu = new interCPU;
	Card* card = new interCard;
	Memory* mem = new interMemory;

	computer* com = new computer(cpu,card,mem);

	com->work();
	delete(cpu);
	delete(card);
	delete(mem);
	delete(com);

	system("pause");
	return 0;
}
