#include "DynamicArray.h"

Dynamic_Array* Init_Array(void)
{
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capacity);
	return myArray;
}
void Push_Back_Array(Dynamic_Array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}
	if (arr->size == arr->capacity)                                       //容量不够
	{
		int* newSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);    //申请新的空间
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));        //将旧的空间数据源拷到新的空间
		free(arr->pAddr);                                                 //释放旧空间
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpace;
	}
	arr->pAddr[arr->size] = value;                                    //插入新的数值
	arr->size++;
}
void RemoveByPos_Array(Dynamic_Array* arr, int pos)
{
	if (arr == NULL || pos < 0 || pos >= arr->size)
	{
		return;
	}
	for (int i = pos; i < arr->size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;
}
void RemoveByValue_Array(Dynamic_Array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}
	int pos;
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}
	RemoveByPos_Array(arr, pos);
}
void FreeSpace_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
	}
	free(arr);
}
int Find_Array(Dynamic_Array* arr, int value)
{
	if (arr == NULL)
	{
		return 0;
	}
	int pos = -1;
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}
	return pos;
}
void Print_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ", arr->pAddr[i]);
	}
	printf("\n");
}
void Clear_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	arr->size = 0;
}
int Capacity_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->capacity;
}
int Size_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->size;
}
int At_Array(Dynamic_Array* arr, int pos)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->pAddr[pos];
}