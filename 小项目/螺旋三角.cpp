#include<stdio.h>
int a[20][20];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,j,circle=1;//circle��¼���е��˵ڼ�Ȧ
        int pos=1;
        while(pos<=n*(n+1)/2)
        {
            for(i=circle,j=circle; j<=n-(circle-1)*2; j++)//�������Ҹ�ֵ
                a[i][j]=pos++;
            for(i=circle+1,j=n-(circle-1)*2-1; i<=n-(circle-1)*2&&j>=circle; i++,j--)//�Խ���������ֵ
                a[i][j]=pos++;
            for(i=n-(circle-1)*2-1,j=circle; i>=circle+1; i--)//�������ϸ�ֵ
                a[i][j]=pos++;
            circle++;
        }
        for(i=1; i<=n; i++)//���������
        {
            for(j=1; j<=n-i+1; j++)
                printf("%4d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

