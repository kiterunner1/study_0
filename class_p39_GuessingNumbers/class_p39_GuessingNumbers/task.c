#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("**********************\n");
	printf("******猜数字游戏******\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");

}

void game()
{
	//生成随机数
	int random_num = rand()%100+1;
	int input = 0;
	while (1) {
		printf("请输入要猜的数字>：\n");
		scanf("%d", &input);
		if (input == random_num)
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
		else if (input > random_num)
		{
			printf("猜大了\n");
		}
		else if (input < random_num)
		{
			printf("猜小了\n");
		}
	}
	
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择>：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新选择！\n");
			break;
		}
	} while (input);
	printf("exit\n");
	return 0;

}