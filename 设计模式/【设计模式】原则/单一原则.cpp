#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h>
using namespace std;
/*��������޸�hi������
class Cloths
{
public:
	void Shopping()
	{
		cout << "���з�װ" << endl;
	}
	void working()
	{
		cout << "��ʽ��װ" << endl;
	}
};
 */


//�Ľ�
class Clothwork
{
public:
	void style()
	{
		cout << "��ʽ��װ"<< endl;
	}
};
class Clothshopp
{
public:
	void style()
	{
		cout << "���з�װ" << endl;
	}
};
int main()
{
	/*Cloths c1;
	c1.Shopping();

	c1.working();
	*/
	Clothshopp c2;
	c2.style();

	Clothwork c3;
	c3.style();
	system("pause");
	return 0;
}
//�޸�һ����������Ӱ�쵽����������Υ����һְ��ԭ��Ӧ�ý���������
