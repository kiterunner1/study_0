#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//�������ʵ��
//��ӡ�˵�
//����

void game()//��Ϸʵ��
{
	char winner = 'c';
	int num = 0;
	char board[RCW][COL] = { 0 };//��������
	Initboard(board, RCW, COL);//��ʼ������
	Displayboard(board, RCW, COL);//��ӡ����
	while (winner == 'c')
	{
		PlayerMove(board, RCW, COL,&num);//�������
		Displayboard(board, RCW, COL);//��ӡ����
		char winner=is_win(board, RCW, COL);//�ж���Ӯ
		if (winner == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		else if (num == 5)
		{
			printf("ƽ��\n");
			break;
		}
		ComputerMove(board, RCW, COL);//��������
		Displayboard(board, RCW, COL);//��ӡ����
		winner = is_win(board, RCW, COL);//�ж���Ӯ
		    if (winner == '#')
			{
				printf("����Ӯ\n");
			    break;
		    }
	}
	printf("��Ϸ����\n");
}

void menu()//�˵�
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
		menu();//��ӡ�˵�
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
		}

	} while (input);

	return 0;
}