#include <stdio.h>
#define n 10 //��������
int main()
{
    int arr[n][n] = {0};
    int i = 0;
    int j = 0;
    for(i=0; i<n; i++)
    {
       for(j=1; j<n-i; j++)//���ƿո�
       {
            printf("  ");//��ӡ�ո�
       }
        for(j=0; j<=i; j++)
        {
           if(j==0 || i==j)//��һ�к�i=j�и���1
           {
                arr[i][j] = 1;
           }
           else
           {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
           }
           printf("%4d",arr[i][j]);//���룬��ӡ����
        }
           printf("\n");
    }
    
    return 0;
}
