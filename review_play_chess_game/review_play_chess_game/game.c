#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[RCW][COL], int rcw, int col)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rcw; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DispalyBoard(char board[RCW][COL], int rcw, int col)//打印棋盘
{
	int i = 0;
	for (i = 0; i < rcw; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < rcw - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if(j<col-1)
				    printf("|");
			}
			printf("\n");
		}
			
	}
}

void PlayerMove(char board[RCW][COL], int rcw, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	printf("请输入坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = '*';
			break;
		}
		else
			printf("当前位置已有棋子或位置非法，请选择其他位置:> ");
	}
}


void ComputerMove(char board[RCW][COL], int rcw, int col)//电脑下棋
{
	printf("电脑下棋\n");
	Sleep(300);
	while (1)
	{
		int x = rand() % rcw;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
	

//返回*玩家赢
//返回#电脑赢
//返回c游戏继续
char is_win(char board[RCW][COL], int rcw, int col)//输赢判断
{
	//判断行
	int i = 0;
	for (i = 0; i < rcw; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	//判断列
	int j = 0;
	for (j = 0; j < rcw; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	//判断正对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	//判断反对角线
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	return 'c';
}

int Is_full(char board[RCW][COL], int rcw, int col)//棋盘判断满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rcw; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

