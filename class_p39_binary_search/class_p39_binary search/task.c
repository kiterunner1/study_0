#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//��������
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int low = 0;
	int high = sizeof(arr) / sizeof(arr[0])-1;
	int key = 18;
	int mid = 0;

	//��������
	while (low<=high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] > key)
		{
			high=mid-1;
		}
		else if (arr[mid] < key)
		{
			low=mid+1;
		}
		else if (arr[mid] == key)
		{
			printf("�ҵ��ˣ��±��ǣ�%d", mid);
			break;
		}
	}
	if (low > high)
	{
		printf("�Ҳ���\n");
	}
}


