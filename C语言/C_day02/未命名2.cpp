#include<stdio.h>
int main()
{
	int a = 6;
	int b = 56;
	printf("����ǰa,b��ֵ��%d,%d\n",a,b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("������a,b��ֵ��%d,%d",a,b);
	return 0;
}
