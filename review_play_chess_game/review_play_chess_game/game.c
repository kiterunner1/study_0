#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[RCW][COL], int rcw, int col)//��ʼ������
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

void DispalyBoard(char board[RCW][COL], int rcw, int col)//��ӡ����
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
		//��ӡ�ָ���
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

void PlayerMove(char board[RCW][COL], int rcw, int col)//�������
{
	int x = 0;
	int y = 0;
	printf("����������:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = '*';
			break;
		}
		else
			printf("��ǰλ���������ӻ�λ�÷Ƿ�����ѡ������λ��:> ");
	}
}


void ComputerMove(char board[RCW][COL], int rcw, int col)//��������
{
	printf("��������\n");
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
	

//����*���Ӯ
//����#����Ӯ
//����c��Ϸ����
char is_win(char board[RCW][COL], int rcw, int col)//��Ӯ�ж�
{
	//�ж���
	int i = 0;
	for (i = 0; i < rcw; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	//�ж���
	int j = 0;
	for (j = 0; j < rcw; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	//�ж����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	//�жϷ��Խ���
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	return 'c';
}

int Is_full(char board[RCW][COL], int rcw, int col)//�����ж���
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

