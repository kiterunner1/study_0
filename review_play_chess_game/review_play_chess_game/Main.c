#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//���ڿ���̨�������帴ϰ

void menu()
{
	printf("********************\n");
	printf("****** 1.play ******\n");
	printf("****** 0.exit ******\n");
	printf("********************\n");
}

void game()//��Ϸʵ��
{
	//��������
	char board[RCW][COL] = {0};
	//��ʼ������
	InitBoard(board,RCW,COL);
	//��ӡ����
	DispalyBoard(board,RCW,COL);
	while (1)
	{
		//�������
		PlayerMove(board, RCW, COL);
		//��ӡ����
		DispalyBoard(board, RCW, COL);
		//��Ӯ�ж�
		if (is_win(board, RCW, COL) == '*')
		{
			printf("���Ӯ��\n");
			break;
		}
		if (Is_full(board, RCW, COL))//ƽ���ж�
		{
			printf("ƽ�֣�\n");
			break;
		}
		//��������
		ComputerMove(board, RCW, COL);
		//��ӡ����
		DispalyBoard(board, RCW, COL);
		//��Ӯ�ж�
		if (is_win(board, RCW, COL) == '#')
		{
			printf("����Ӯ��\n");
			break;
		}
	}
	
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//��ʼ�������
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
