#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct DYNAMICARRAY
{
	int* pAddr;                //������ݵĵ�ַ
	int size;                  //��ǰ��Ԫ�ظ���
	int capacity;              //Ԫ������
}Dynamic_Array;

Dynamic_Array* Init_Array(void);                           //��ʼ��
void Push_Back_Array(Dynamic_Array* arr, int value);       //����Ԫ��
void RemoveByPos_Array(Dynamic_Array* arr, int pos);       //����λ��ɾ��
void RemoveByValue_Array(Dynamic_Array* arr, int value);   //������ֵɾ��
void FreeSpace_Array(Dynamic_Array* arr);                  //�ͷſռ�
int Find_Array(Dynamic_Array* arr, int value);             //������ֵ���Ҳ�����λ��
void Print_Array(Dynamic_Array* arr);                      //��ӡ
void Clear_Array(Dynamic_Array* arr);                      //�������               
int Capacity_Array(Dynamic_Array* arr);                    //��õ�ǰ����
int Size_Array(Dynamic_Array* arr);                        //��õ�ǰ����
int At_Array(Dynamic_Array* arr, int pos);				   //����λ��������ĳ��Ԫ��
#endif
