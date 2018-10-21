#include <stdio.h>
#include <assert.h>

int my_strlen(const char *str)
{
	int count = 0;
	assert(str);
	while(*str++)
	{
		count++;
	}
	return count;
}

void reverse_str(char *left,char *right)
{
	assert(left);
	assert(right);
	while(left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

void reverse(char *str)
{
	assert(str);
	char *left = str;
	char *right = str + my_strlen(str) - 1;
	reverse_str(left,right);	
}

int main()
{

	char arr[] = "student a am i";
	printf("\n����תÿ������:\n%s\n\n",arr);
	char *pcur = arr; 
	//�����ַ��� 
	reverse(arr);
	//���򵥴�
	while(*pcur)
	{
		char *start = pcur;
		while(*pcur != ' '&&*pcur != '\0')
		{
		    pcur++;
		}
		reverse_str(start,pcur-1);
		if(*pcur == ' ')
		    pcur++;	    
	}
	printf("��ת��Ľ����\n");	
	puts(arr);
	return 0;
 } 
