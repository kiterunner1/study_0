#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int Minecount = 10;//������ָ���ã�

void menu()//��ʼ�˵�
{
	printf("***********************\n");
	printf("*******  1.play  ******\n");
	printf("*******  2.Set  ******\n");
	printf("*******  0.exit  ******\n");
	printf("***********************\n");
}

void Mode_choice()//�޸Ĳ˵�
{
	printf("***********************\n");
	printf("***** ��ǰ����:%d *****\n", Minecount);
	printf("***********************\n");
	printf("����������:> ");
	scanf("%d", &Minecount);
}

void game()//��Ϸʵ��
{
	char mine[RCWS][COLS];//��¼���úõ���
	char show[RCWS][COLS];//��¼�Ų�����׵���Ϣ,��ʾ����
	Init_Board(show, RCWS, COLS, '*');//��ʼ��չʾ����
	Init_Board(mine, RCWS, COLS, '0');//��ʼ���׵���Ϣ
	SetMine(mine, RCW, COL);//������
	Display_Board(show, RCW, COL);//��ӡչʾ����
	Display_Board(mine, RCW, COL);//��ӡ������
	Find_mine(show, mine, RCW, COL);//����
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸʵ��
			break;
		case 2:
			Mode_choice();//��������
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ������������ѡ��\n");
		}
	} while (input);

	return 0;
}