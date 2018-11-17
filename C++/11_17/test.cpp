#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>

//ֻ����ջ�ϴ�������
//ֻ��Ҫ����new delete���ܼ��ɼ����εص�operator new��operator delete���ʽ
void test1()
{
	class StackOnly
	{
	public:
		StackOnly()
		{
			;
		}

	private:
		//���� new delete
		void* operator new(size_t size);
		void  operator delete(void* p);

	};

}
//ֻ���ڶ��ϴ�������
//����˽�л�
void test2()
{
	class HeapOnly
	{
	public:
		static HeapOnly* CreatObj()
		{
			return new HeapOnly;
		}
	private:
		HeapOnly()
		{
			;
		}

		//������
		HeapOnly(const HeapOnly& s);

	};
}

//ǳ��������������������һ������������֮���٣������ã�������������Բ������
//��ͳģ��ʵ��string
void test3()
{
	class String
	{
		String(const char* str="")
		{
			//���Ϊ�գ���Ϊ�Ƿ��������˳�
			if (str == nullptr)
			{
				assert(false);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);

		}
		String(const String& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);

		}
		String& operator=(const String& s)
		{
			//�ͷ���Դ
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
			if (this != &s)
			{
				_str = new char[strlen(s._str)+1];
				strcpy(_str,s._str);
				return *this;
			}
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}


		}
	private:
		char* _str;
	};

}
//�ִ�ģ��ʵ��string
void test4()
{
	class String
	{
		String(const char* str = "")
		{
			//���Ϊ�գ���Ϊ�Ƿ��������˳�
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);

		}
		String(const String& s)
			:_str(nullptr)
		{
			String tmp(s);
			swap(_str,tmp._str);

		}
		String& operator=(const String& s)
		{
			
			if (this != &s)
			{
				String tmp(s);
				swap(_str, tmp._str);
				
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}


		}
	private:
		char* _str;
	};

}
using namespace std;
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();

	system("pause");
	return 0;
}

