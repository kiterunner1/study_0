#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("**********************\n");
	printf("******��������Ϸ******\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");

}

void game()
{
	//���������
	int random_num = rand()%100+1;
	int input = 0;
	while (1) {
		printf("������Ҫ�µ�����>��\n");
		scanf("%d", &input);
		if (input == random_num)
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
		else if (input > random_num)
		{
			printf("�´���\n");
		}
		else if (input < random_num)
		{
			printf("��С��\n");
		}
	}
	
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��>��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	printf("exit\n");
	return 0;

}