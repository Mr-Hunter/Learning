#include<stdio.h>
#include<string.h> //memset����
#include<math.h> //sqrt()��ƽ����
#define N 10001 //�ٶ�N���ֵΪ10000
int a[N];
int main() {
 int n;
 scanf("%d", &n);
  
 memset(a, 0, sizeof(a)); //�ٳ�ʼĬ�϶�Ϊ������Ϊ0�������������1��������ɸȥ��
 int i = 1;
 a[1] = 1; //1����������������1
  
 for (i = 2; i < sqrt(n); i++) //iΪ�������ӣ��ڵ�i���ڸ���nʱ����ɸȥ���еķ�������
 {
  if (a[i] == 0) {//iδ��ǣ���i������.
   int j;
   for (j = 2; j * i <= n; j++) {//��i�ı������
    a[j*i] = 1;
   }
  }
 }//�ѽ�a[1]-a[n]�����ɡ�
  
  
 for (i = 1; i <= n; i++) { //���
  if (!a[i]) printf("%d\n", i);
 }
 return 0;
}
