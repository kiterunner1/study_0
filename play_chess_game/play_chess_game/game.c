#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[RCW][COL], int rcw, int col)//��ʼ������
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

void Displayboard(char board[RCW][COL], int rcw, int col)//��ӡ����
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
		if (i < rcw - 1)//��ӡ�ָ���
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

void PlayerMove(char board[RCW][COL], int rcw, int col,int*num)//�������
{
	printf("�������� ѡ����Ҫ�µ�λ��:>");
again:
	scanf("%d %d", &rcw, &col);//��������
	while (1)
	{
		if (board[rcw-1][col-1] == ' ')//�ж�λ�úϷ���
		{
			board[rcw-1][col-1] = '*';
			(*num)++;
			break;
		}
		else
		{
			printf("��ѡ���λ���Ѿ��������ˣ�������ѡ��:> ");
			goto again;
		}
	}
}


void ComputerMove(char board[RCW][COL], int rcw, int col)//��������
{
	printf("��������\n");
	while (1)
	{
		int x = rand() % rcw;
		int y = rand() % col;
		if (board[x][y] == ' ')//�ж�λ�úϷ���
		{
			board[x][y] = '#';
			break;
		}
	}
}

//����ͬ 
//����ͬ
//�Խ�����ͬ
char is_win(char board[RCW][COL], int rcw, int col)//�ж���Ӯ
{
	//�ж�����ͬ
	int i = 0;
	int j = 0;
	for (i = 0; i < rcw; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][2];
		}
	}

	//�ж�����ͬ
	for (i = 0; i < rcw; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
		{
			return board[2][i];
		}
	}

	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[1][1];
	}

	//�жϷ��Խ���
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}


	/*if (is_full(board, RCW, COL)) //�ж������Ƿ���
	{
		return 'f';
	}*/

	return 'c';
}

//int is_full(char board[RCW][COL], int rcw, int col)//�ж������Ƿ���
//{
//	//�ж��Ƿ�δ��   1����δ��   0������
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