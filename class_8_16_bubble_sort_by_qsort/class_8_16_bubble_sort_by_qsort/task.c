#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//模仿qsort的功能实现一个通用的冒泡排序
int int_cmp(const void* e1,const void* e2)
{
	return *((int*)e1) - *((int*)e2);
}

swap(void* e1, void* e2, int size)
{
	for (int i = 0; i < size; i++)
	{
		char temp = *((char*)e1+i);
		*((char*)e1+i) = *((char*)e2+i);
		*((char*)e2+i) = temp;
	}
}

void bubble(int* base, int count, int size, int (*cmp)(void*, void*))
{
	for (int i = 0; i < count-1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

int main()
{
	int arr[] = { 1,6,3,9,4,0,5,7,2,8 };
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}