#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

extern Minecount;//雷数（指针用））

void Init_Board(char Board[RCWS][COLS], int rcws, int cols, char set)//初始化显示棋盘
{
	for (int i = 0; i < rcws; i++)
	{
		for (int j = 0; j < cols; j++)
			Board[i][j] = set;
	}
}

void Display_Board(char Board[RCWS][COLS], int rcw, int col)//打印棋盘
{
	printf("======= 扫雷 ========\n    ");//游戏标题
	for (int i = 1; i <= rcw; i++)//打印坐标指示（列）
	{
		printf("%d ", i);
	}printf("\n    ");

	for (int i = 1; i <= rcw; i++)//打印分割行
	{
		printf("--");
	}printf("\n");

	for (int i = 1; i <= rcw; i++)//打印显示棋盘
	{
		printf("%2d | ",i);//打印坐标指示（行）
		for (int j = 1; j <= col; j++)
		{
			printf("%c ",Board[i][j]);
		}printf("\n");
	}
}


void SetMine(char Board[RCWS][COLS],int rcw,int col)//布置雷
{
	
	int mines = Minecount;//待埋入雷数
	while (mines)
	{
		int x = rand() % rcw + 1;
		int y = rand() % col + 1;
		if (Board[x][y] == '0')
		{
			Board[x][y] = '1';
			mines--;
		}
	}
}


void Find_mine(char show[RCWS][COLS], char mine[RCWS][COLS], int rcw, int col)//排雷
{
	int x = 0;
	int y = 0;
	int findcount = 0;//统计排雷次数
	int flag = 1;//踩雷标志，为0表示踩雷了
	while (RCW*COL-EASY_MODE-findcount)
	{
		printf("请输入要排的雷的坐标:> ");
		scanf("%d %d", &x, &y);
		if (mine[x][y] == '1')//当前位置是雷
		{
			printf("你踩到雷了，游戏结束！\n");
			flag = 0;
			Display_Board(mine, RCW, COL);//打印棋盘
			break;
		}
		else//当前位置没有雷，统计周围雷数
		{
			int count = Getminecount(mine, x, y);
			show[x][y] = count+48;
			Display_Board(show, RCW, COL);//打印棋盘
			findcount++;
		}
	}
	if(flag)
	printf("你已排出所有的雷，游戏胜利！\n");
}


int Getminecount(char mine[RCWS][COLS],int x,int y)//获取坐标周围雷数
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}