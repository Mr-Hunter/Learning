#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h> 
int count_one_bits(int x)
{
	// ���� 1��λ�� 
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((x >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
/*int count_one_bits(int x)
{
	// ���� 1��λ�� 
 
	int count = 0;
	while(x)
	{
		count++;
		n=n&(n-1);
	 } 
 
	return count;
} */
int main()
{
	int ret = count_one_bits(222);

	// ���� 1��λ�� 
	printf("%d", ret);
	system("pause");
	return 0;
}

