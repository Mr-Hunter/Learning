#include<stdio.h>
int main()
{
	char ch;
	int count = 0; 
	while((ch=getchar()) != '\n')
	{
		if(ch == '{')
		count++;
		else if(ch == '}'&&count == 0)
		{
			printf("���벻ƥ��");
			return 0; 
		}
		else if(ch == '}')
		count--;
	}
	if(count == 0)
	{
		printf("����ƥ��"); 
	}
	else
	{
		printf("��ƥ��");
	}
	return 0;
}
