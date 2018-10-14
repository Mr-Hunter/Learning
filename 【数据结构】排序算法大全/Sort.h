#ifndef __INSERTSORT_H__
#define __INSERTSORT_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/************************************   �Ƚ�����     ********************************/
//��������
//1.ֱ�Ӳ�������
void InsertSort(int* arr, int n);
//2.ϣ������
void ShellSort(int* arr, int n);


//ѡ������
//1.ѡ������
void SelectSort(int* arr, int n);
//2.������
void HeapSort(int* arr, int n);


//��������
//1.ð������
void BubbleSort(int* arr, int n);
//2.��������
void QuickSort(int* arr, int begin, int end);

//�鲢���򣨿��ⲿ����
void MergeSort(int* arr, int n);

/************************************   �ǱȽ�����     ********************************/
//��������
void CountSort(int* arr, int n);


#endif //__INSERTSORT_H__