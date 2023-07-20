#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//三子棋的实现
//打印菜单
//下棋

void game()//游戏实现
{
	char winner = 'c';
	int num = 0;
	char board[RCW][COL] = { 0 };//创建棋盘
	Initboard(board, RCW, COL);//初始化棋盘
	Displayboard(board, RCW, COL);//打印棋盘
	while (winner == 'c')
	{
		PlayerMove(board, RCW, COL,&num);//玩家下棋
		Displayboard(board, RCW, COL);//打印棋盘
		char winner=is_win(board, RCW, COL);//判断输赢
		if (winner == '*')
		{
			printf("玩家赢\n");
			break;
		}
		else if (num == 5)
		{
			printf("平局\n");
			break;
		}
		ComputerMove(board, RCW, COL);//电脑下棋
		Displayboard(board, RCW, COL);//打印棋盘
		winner = is_win(board, RCW, COL);//判断输赢
		    if (winner == '#')
			{
				printf("电脑赢\n");
			    break;
		    }
	}
	printf("游戏结束\n");
}

void menu()//菜单
{
	printf("****************************\n");
	printf("****** 1.play  0.exit ******\n");
	printf("****************************\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
		}

	} while (input);

	return 0;
}