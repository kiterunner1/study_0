#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[RCW][COL], int rcw, int col)//初始化棋盘
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

void Displayboard(char board[RCW][COL], int rcw, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rcw; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < rcw - 1)//打印分割行
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}

void PlayerMove(char board[RCW][COL], int rcw, int col,int*num)//玩家下棋
{
	printf("输入坐标 选择您要下的位置:>");
again:
	scanf("%d %d", &rcw, &col);//输入坐标
	while (1)
	{
		if (board[rcw-1][col-1] == ' ')//判断位置合法性
		{
			board[rcw-1][col-1] = '*';
			(*num)++;
			break;
		}
		else
		{
			printf("您选择的位置已经有棋子了，请重新选择:> ");
			goto again;
		}
	}
}


void ComputerMove(char board[RCW][COL], int rcw, int col)//电脑下棋
{
	printf("电脑下棋\n");
	while (1)
	{
		int x = rand() % rcw;
		int y = rand() % col;
		if (board[x][y] == ' ')//判断位置合法性
		{
			board[x][y] = '#';
			break;
		}
	}
}

//行相同 
//列相同
//对角线相同
char is_win(char board[RCW][COL], int rcw, int col)//判断输赢
{
	//判断行相同
	int i = 0;
	int j = 0;
	for (i = 0; i < rcw; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][2];
		}
	}

	//判断列相同
	for (i = 0; i < rcw; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
		{
			return board[2][i];
		}
	}

	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[1][1];
	}

	//判断反对角线
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}


	/*if (is_full(board, RCW, COL)) //判断棋盘是否满
	{
		return 'f';
	}*/

	return 'c';
}

//int is_full(char board[RCW][COL], int rcw, int col)//判断棋盘是否满
//{
//	//判断是否未满   1代表未满   0代表满
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < rcw; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//				return 0;
//		}
//	}
//	return 1;
//}