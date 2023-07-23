#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//基于控制台的三子棋复习

void menu()
{
	printf("********************\n");
	printf("****** 1.play ******\n");
	printf("****** 0.exit ******\n");
	printf("********************\n");
}

void game()//游戏实现
{
	//创建棋盘
	char board[RCW][COL] = {0};
	//初始化棋盘
	InitBoard(board,RCW,COL);
	//打印棋盘
	DispalyBoard(board,RCW,COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, RCW, COL);
		//打印棋盘
		DispalyBoard(board, RCW, COL);
		//输赢判断
		if (is_win(board, RCW, COL) == '*')
		{
			printf("玩家赢！\n");
			break;
		}
		if (Is_full(board, RCW, COL))//平局判断
		{
			printf("平局！\n");
			break;
		}
		//电脑下棋
		ComputerMove(board, RCW, COL);
		//打印棋盘
		DispalyBoard(board, RCW, COL);
		//输赢判断
		if (is_win(board, RCW, COL) == '#')
		{
			printf("电脑赢！\n");
			break;
		}
	}
	
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//初始化随机数
	do
	{
		menu();//打印菜单
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
