/*
1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
#include <stdio.h>

int fib(int n)
{
if(n <= 2)
return 1;
else
return fib(n-1) + fib(n-2);
}

/*int fib(int n)
{
	int f1 = 1;
	int f2 = 1;
	int fn = 0;
	int i = 0;
	if (n <= 2)
		return 1;
	for (i = 3; i <= n; i++)
	{
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}  

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fib(n);
	printf("%d", ret);
	system("pause");
	return 0;
}
 

2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
#include <stdio.h>
int  GetCount(int n, int k)
{
	if ((0 == k) || (1 == n))
		return 1;
	else if (1 == k)
		return n;
	else
		return n*GetCount(n, k - 1);
}

int main()
{
	int n = 7;
	int k = 3;
	int ret = GetCount(n, k);
	printf("%d", ret);
	system("pause");
	return 0;
} 

3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ����磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19 
#include<stdio.h>  
int DigSum(int n)
{
	if (n <= 10)
		return 1;
	else
		return n % 10 + DigSum(n / 10);
}
int main()
{
	printf("%d\n", DigSum(1729));
	return 0;
}
4. ��дһ������reverse_string(char * string)���ݹ�ʵ�֣� 
ʵ�֣��������ַ����е��ַ��������С� 
Ҫ�󣺲���ʹ��C�������� 
���ַ������������� 
 #include<stdio.h>
void reverse_string(char* string)
{
    if (*string == '\0')
    {
        return;
    }
    reverse_string(string + 1);
    printf("%c", *string);
}
int main()
{
    char string[] = "abcdefghijk";
    reverse_string(string);
    printf("\n");
    
    return 0;
}
5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
#include <stdio.h>
#include <assert.h>

//int my_strlen(const char *str)
//{
//	assert(str);
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
int my_strlen(const char *str)
{
	assert(str);
	int count = 0;
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen(str + 1);
}

int main()
{
	char arr[] = "abdbakjnfls";
	int len = my_strlen(arr);
	printf("%d ", len);
	system("pause");
	return 0;
}
6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 
#include <stdio.h>

//int fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
int fac(int n)
{
	int i = 0;
	int result = 1;
	for (i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", fac(n));
	system("pause");
	return 0;
}
7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
#include <stdio.h>
void getadd(int n)
{
	if (n > 9)
	{
		getadd(n / 10);
	}
	printf("%d  ", n % 10);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	getadd(n);

	system("pause");
	return 0; 
} */ 
 
 
