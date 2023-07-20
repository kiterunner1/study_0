#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define RCW 3
#define COL 3

void Initboard(char board[RCW][COL], int rcw, int col);//��ʼ������

void Displayboard(char board[RCW][COL], int rcw, int col);//��ӡ����

void PlayerMove(char board[RCW][COL], int rcw, int col,int*num);//�������

void ComputerMove(char board[RCW][COL], int rcw, int col);//��������


//����*�������Ӯ
//����#�������Ӯ
//����c������Ϸ����
//����f����ƽ��
char is_win(char board[RCW][COL], int rcw, int col);//�ж���Ӯ

int is_full(char board[RCW][COL], int rcw, int col);//�ж���