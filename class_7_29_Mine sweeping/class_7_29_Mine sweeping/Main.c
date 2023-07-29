#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int Minecount = 10;//雷数（指针用）

void menu()//开始菜单
{
	printf("***********************\n");
	printf("*******  1.play  ******\n");
	printf("*******  2.Set  ******\n");
	printf("*******  0.exit  ******\n");
	printf("***********************\n");
}

void Mode_choice()//修改菜单
{
	printf("***********************\n");
	printf("***** 当前雷数:%d *****\n", Minecount);
	printf("***********************\n");
	printf("请输入雷数:> ");
	scanf("%d", &Minecount);
}

void game()//游戏实现
{
	char mine[RCWS][COLS];//记录布置好的雷
	char show[RCWS][COLS];//记录排查出的雷的信息,显示棋盘
	Init_Board(show, RCWS, COLS, '*');//初始化展示棋盘
	Init_Board(mine, RCWS, COLS, '0');//初始化雷的信息
	SetMine(mine, RCW, COL);//布置雷
	Display_Board(show, RCW, COL);//打印展示棋盘
	Display_Board(mine, RCW, COL);//打印雷棋盘
	Find_mine(show, mine, RCW, COL);//排雷
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏实现
			break;
		case 2:
			Mode_choice();//雷数设置
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择有误，请重新选择\n");
		}
	} while (input);

	return 0;
}