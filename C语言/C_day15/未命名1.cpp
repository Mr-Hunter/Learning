�ɱ�������ֵ
#include <stdio.h>    
#include <stdarg.h>    
#include <windows.h>    
int Max(int n, ...)    
{    
    int i = 0;    
    int max = 0;    
    va_list arg;    
    va_start(arg, n);    
    max = va_arg(arg,int);//��ȡ�����б��һ���ɱȽ�ֵ  
    for (i = 1; i < n; i++)    
    {    
        int val = va_arg(arg, int);    
        if (val > max)    
        {    
            max = val;    
        }    
    }    
    va_end(arg);    
    return max;    
}    
int main()    
{    
    int ret = Max(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);    
    printf("%d\n", ret);    
    system("pause");    
    return 0;    
}     
/*ģ��ʵ��printf���������������Ĺ��� 
��������溯���ĵ��á� 
print(��s ccc d.\n��,��hello��,��b��,��i��,��t����100); 
����ԭ�ͣ� 
print(char *format, ��)*/ 
#include<stdio.h>  
#include<assert.h>  
#include<stdarg.h>  
void print(char *fomt, ...)  
{  
    char *ch;  
    assert(*fomt);//����  
    va_list arg;//����arg  
    va_start(arg, fomt);��ʼ��arg ���ѿɱ�����б����׸�������ַ��arg  
    while (*fomt)  
    {  
        switch(*fomt)  
        {  
        case 'c':  
            putchar(va_arg(arg,char));//va_arg ��ȡ�����б�����һ��δ֪����������ͨ��ǰ���ȡ���ַ��ж���һ����������  
            break;  
        case 's':  
            /*puts(va_arg(arg, char*));*/   //�ַ�������ֱ����puts()�������  
            ch = va_arg(arg, char*);//�����Զ���һ��ָ��������ջ�ȡ���ַ����Ӷ���putchar����һ��һ�����  
            while (*ch)  
            {  
                putchar(*ch);  
                ch++;  
            }  
                  
                break;  
        default :  
            putchar(*fomt);  
  
        }  
        fomt++;  
      
    }  
    va_end(arg);//����ͷ�arg  
}  
int main()  
{  
    print("val:s ccccc\n","hello", 'w', 'o', 'r', 'l', 'd');  
    system("pause");  
    return 0;  
}  


ƽ��ֵ
#include<stdio.h>      
#include<stdlib.h>      
#include <stdarg.h>       
int average(int num, ...)//��һ�����������ǲ����ĸ������������������ɱ�����б�      
{    
    int sum = 0;    
    va_list arg;  //����һ��va_list���͵ı���      
    va_start(arg, num); //�� va_start      
    for (int i = 0; i < num; i++)    
    {    
        sum += va_arg(arg, int);  //�� va_arg      
    }    
    va_end(arg); //�� va_end      
    return sum / num;    
}    
    
int main()    
{    
    int aver = 0;    
    aver = average(5,2,4,6,8,10); //��һ����Ϊ����,֮�����Ϊ��ƽ������      
    printf("%d\n", aver);    
    system("pause");    
    return 0;    
}     
