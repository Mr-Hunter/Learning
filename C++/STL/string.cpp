#include "STL.h"

//////////////////////////////////����
/////////////////////////////string
void test1()
{
	//stringתchar*
	string s = "abc";
	const char* str = s.c_str();
	//char*תstring
	char* str2 = "casc";
	string s2(str2);

}
//string ��ʼ��
void test2()
{
	string s;//Ĭ�Ϲ���
	string s1 = "cscsd";
	string s2(s1);
	string s4(10, 'o');

	cout << s << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s4 << endl;

}

//string��ֵ��ȡ
void test3()
{
	//��ֵ
	string s;
	s = "abcd";

	string s2;
	s2.assign("pppp");

	//��ȡ
	string s3 = "csdcsd";
	//Խ��ҵ�
	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3[i] << " ";
	}
	cout << endl;

	//Խ�����쳣
	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3.at(i) << " ";
	}
	cout << endl;


	//�쳣����
	try
	{
		//cout << s3[300] << endl;  //����
		cout << s3.at(200) << endl;	//����ִ�У����쳣
	}
	catch (...)
	{
		cout << "����Խ��" << endl;

	}

}

//stringƴ��
void test4()
{
	string s = "aaa";
	string s2 = "bbbb";
	string s3 = s + s2;
	cout << s3 << endl;

	s += s2;
	cout << s << endl;

	//c��Ա���� append
	s.append(s2);
	cout << s;
}

//string ���� �滻 
void test5()
{
	string s = "cdscca";
	//����
	string yy = "cd";
	int pos = s.find(yy);

	char* pp = "cadssd";
	int pos1 = s.find(pp);

	int pos4 = s.rfind(yy);	 //�������
	cout << pos << " " << pos1 << pos4 << endl;

	string s5 = "pppppp";
	//�滻
	s.replace(0, 2, s5);
	cout << s;

}

//�Ƚ�  �Ӵ� ����ɾ��
void test6()
{
	//�Ƚ�
	string s1 = "casc";
	string s2 = "svdvsd";
	int ret = s1.compare(s2);
	if (ret == 1)
	{
		cout << "s1>s2";
	}
	else if (ret == -1)
	{
		cout << "s1<s2";
	}
	else
	{
		cout << "xiangdeng";
	}

	//�Ӵ�
	string s3 = "csdcnskns";
	string  s4 = s3.substr(0, 2);
	cout << s4.size();
	cout << endl << s4 << endl;
	//����ɾ��
	s3.insert(0, "dsd");
	cout << s3 << endl;

	s3.insert(s3.size() - 1, s3);
	cout << s3 << endl;

	s3.erase(0, 4);//ǰ�պ�
	cout << s3 << endl;

}
//string ����	
//��������Ƿ���ڣ��ȼ���Ƿ�Ϸ���
void test7()
{
	string email = "acaccd56@email.com";

	int pos = email.find('@');
	int pos1 = email.find('.');

	if (pos == -1 || pos1 == -1)
	{
		cout << "���Ϸ�" << endl;
		system("pause");
		return;
	}
	if (pos > pos1)
	{
		cout << "���Ϸ�" << endl;
		system("pause");
		return;

	}

	//�ж�usrname
	string usrname = email.substr(0, pos);
	string::iterator pStart = usrname.begin();
	string::iterator pEnd = usrname.end();

	while (pStart != pEnd)
	{
		if (*pStart<97 && *pStart >122)
		{
			cout << "���Ϸ�" << endl;
			system("pause");
			return;
		}
		cout << *pStart << " ";
		pStart++;
	}
	cout << endl;

	//�жϴ���
	string remail = "zhaosi@itcast.cn";
	int ret = email.compare(remail);
	if (ret != 0)
	{
		cout << "������" << endl;

	}
	else
	{
		cout << "�Ϸ�" << endl;
	}
}