#define _CRT_SECURE_NO_DEPRECATE
#include "DynamicArray.h"

void test01(void)
{
	Dynamic_Array* myArray = Init_Array();
	printf("容量：%d\n", myArray->capacity);
	printf("个数：%d\n", myArray->size);
	printf("===========================\n");
	for (int i = 0; i < 30; i++)
	{
		Push_Back_Array(myArray, i);
	}
	printf("容量：%d\n", myArray->capacity);
	printf("个数：%d\n", myArray->size);
	Print_Array(myArray);
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 27);
	Print_Array(myArray);
	int pos = Find_Array(myArray, 5);
	int value = At_Array(myArray, pos);
	printf("pos=%d\n", pos);
	printf("value=%d\n", value);
	FreeSpace_Array(myArray);
}
int main(void)
{
	test01();
	return 0;
}