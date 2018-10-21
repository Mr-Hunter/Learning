#include "CommentConvert.h"

static enum STATUS status = NUL_STATUS;

void CommentConvert(FILE *pfIn, FILE *pfOut)
{
	while (status != END_STATUS)
	{
		switch (status)
		{
		case NUL_STATUS:
			DoNulStatus(pfIn, pfOut);
			break;
		case C_STATUS:
			DoCStatus(pfIn, pfOut);
			break;
		case CPP_STATUS:
			DoCppStatus(pfIn, pfOut);
			break;
		case STR_STATUS:
			DoStrStatus(pfIn, pfOut);
			break;
		case END_STATUS:
			break;
		default:
			break;
		}
	}
}

void DoNulStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '/':
		second = fgetc(pfIn);
		if (second == '/')
		{
			fputc('/', pfOut);
			fputc('/', pfOut);
			status = CPP_STATUS;   //����״̬������//ֱ�ӽ�//д��ȥ��������cpp״̬  
		}
		else if (second == '*')
		{
			fputc(first, pfOut);
			fputc('/', pfOut);
			status = C_STATUS;//����״̬������/*Ҫ��/*���//д��ȥ��������c״̬  
		}
		else
		{
			fputc(first, pfOut);
			fputc(second, pfOut);//������������ַ���ֱ��д��ȥ��״̬���ı䡣  
		}
		break;
	case EOF:
		status = END_STATUS;//�������EOF���������״̬  
		break;
	case '"':
		fputc(first, pfOut);
		status = STR_STATUS;//�������"�������ַ���״̬  
		break;
	default:
		fputc(first, pfOut);//����������ַ���ֱ��д��ȥ����  
		break;
	}
}

void DoStrStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '"':
		fputc(first, pfOut);
		status = NUL_STATUS;//���ַ���״̬������������ţ���������д�룬��������״̬  
		break;
	default:
		fputc(first, pfOut);//����������ַ���ֱ��д��ȥ����  
		break;
	}
}

void DoCStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '*':
		second = fgetc(pfIn);
		if (second == '/')  // ����*/ ˵��c��ע�ͽ������л�����״̬  
		{
			status = NUL_STATUS;
			third = fgetc(pfIn);
			if (third != '\n')
			{
				fputc('\n', pfOut);    //���/��ߵ��ַ����ǻس�����Ҫд��ȥ�س���Ȼ���ٰѶ������ַ��Ż�  
				ungetc(third, pfIn);
			}
			else
			{
				ungetc(third, pfIn);//����ǻس����ѻس��Ż�  
			}
		}
		else
		{
			fputc(first, pfOut);
			//�������*�����Ǻ�߲���/����*�Ž�ȥ��*��ߵ��ַ��Żأ����磬/***/,����c״̬�Ժ�  
			//����*����ߵ��ַ�Ҳ��*�����������*��д��ȥ����߾�ֻʣ��/���Ͳ����ҵ�c״̬�����ı�־��  
			//���ԣ���Ҫ�ѵڶ����ַ�ԭ��д��  
			/*fputc(second, pfOut);*/
			ungetc(second, pfIn);    //�Ż�  
		}
		break;
	case '\n':
		fputc(first, pfOut);//�����Ҫ�س����ɻس�д�룬��д��//��״̬���䡣  
		fputc('/', pfOut);
		fputc('/', pfOut);
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}

void DoCppStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
		fputc(first, pfOut);//cpp״̬����������س���cpp״̬������������״̬  
		status = NUL_STATUS;
		break;
	default:
		if (first == EOF)
		{
			status = END_STATUS;
		}
		else
		{
			fputc(first, pfOut);
		}
		break;
	}
}