#include<stdio.h>
int main()
{
	int i = 25;
	int j = 2;
	printf("����ǰi,j��ֵ��%d,%d\n",i,j);
	int temp = 0;
	temp = i;
	i = j;
	j = temp;
	printf("������i,j��ֵ��%d,%d\nn",i,j);
	return 0;
	
 } 
