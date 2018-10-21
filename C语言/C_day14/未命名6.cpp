#include<stdio.h>  
#include<string.h>
#include<assert.h>  

void reverse(char *left,char*right)//����  
{  
    assert(left&&right);
    while (left < right)  
    {  
        char tmp;  
        tmp = *left;  
        *left = *right;  
        *right = tmp;  
        left++, 
		right--;  
    }  
}  
void reverse_left(char *str,int k)  
{  
    int len = 0; 
	assert(str);
    len = strlen(str);  
    k=k%len;
    reverse(str, (str + k-1));//Ҫ��ת��k���ַ�����  
    reverse((str + k ), (str + len-1));//֮����ַ�����  
    reverse(str, (str + len-1));//���е��ַ�����  
}  
int main()  
{  
    int k = 0;  
    char str[] = "abcdefgh"; 
	scanf("%d",&k); 
    reverse_left(str, k);  
    printf("%s", str);  
    return 0;  
}  

