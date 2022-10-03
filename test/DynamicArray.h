#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct DYNAMICARRAY
{
	int* pAddr;                //存放数据的地址
	int size;                  //当前的元素个数
	int capacity;              //元素容量
}Dynamic_Array;

Dynamic_Array* Init_Array(void);                           //初始化
void Push_Back_Array(Dynamic_Array* arr, int value);       //插入元素
void RemoveByPos_Array(Dynamic_Array* arr, int pos);       //根据位置删除
void RemoveByValue_Array(Dynamic_Array* arr, int value);   //根据数值删除
void FreeSpace_Array(Dynamic_Array* arr);                  //释放空间
int Find_Array(Dynamic_Array* arr, int value);             //根据数值查找并返回位置
void Print_Array(Dynamic_Array* arr);                      //打印
void Clear_Array(Dynamic_Array* arr);                      //清空数组               
int Capacity_Array(Dynamic_Array* arr);                    //获得当前容量
int Size_Array(Dynamic_Array* arr);                        //获得当前个数
int At_Array(Dynamic_Array* arr, int pos);				   //根据位置来查找某个元素
#endif
