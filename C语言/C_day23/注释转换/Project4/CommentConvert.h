/***********************************************************
*                      �������ƣ�C/C++ע��ת��             *
*                      ���뻷����VS2013                    *
*                      �������ڣ�2018.6.03                 *
*                                      -----by Hunter	   *
***********************************************************/

#ifndef  __COMMENTCONVERT_H__
#define  __COMMENTCONVERT_H__

#include <stdio.h>
#include <stdlib.h>

enum STATUS
{
	NUL_STATUS, //��ע��״̬
	C_STATUS,   //C����ע��״̬
	CPP_STATUS, //c++ע��״̬
	END_STATUS,	//����ע��״̬
	STR_STATUS	//�ַ���ע��״̬
};


void CommentConvert(FILE* pfIn, FILE* pfOut);
void DoNulStatus(FILE* pfIn, FILE* pfOut);   //��ע��״̬

void DoCStatus(FILE* pfIn, FILE* pfOut);	  //C����ע��״̬
void DoCppStatus(FILE* pfIn, FILE* pfOut );	  //c++ע��״̬
void DoStrStatus(FILE* pfIn, FILE* pfOut);	   //�ַ���ע��״̬


#endif  //__COMMENTCONVERT_H__