#include<stdio.h>
int main()
{
	int m = 0,n = 0,k = 0;
	scanf("%d%d",&m,&n);
	int ji = m * n; 
	//���Լ������С������ 
    k = m>n? n: m;
	for(;m%k||n%k;)
    {
		k--;
	} 
	printf("���Լ��%d����С������%d ",k,ji/k);
	return 0;  
}
