 
//A˵�������ҡ� 
//B˵����C�� 
////C˵����D�� 
//D˵��C�ں�˵ 
//��֪3����˵���滰��1����˵���Ǽٻ��� 
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡� 
#include <stdio.h>
int main()
{
	int killer = 0;
	for(killer = 65; killer<68;killer++)
	{
    	if(3 == ((killer != 65)+(killer == 67)+(killer == 68)+(killer != 68)))
    	{
		    printf("%C",killer);
    	}
	}

	return 0;
}
