#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_MODE 10
#define RCW 9
#define COL 9
#define RCWS RCW+2
#define COLS COL+2

//��������

void Init_Board(char Board[RCWS][COLS], int rcw,int col,char set);//��ʼ������

void Display_Board(char Board[RCWS][COLS],int rcw,int col);//��ӡ����

void SetMine(char mine[RCWS][COLS],int rcw,int col);//������

void Find_mine(char show[RCWS][COLS], char mine[RCWS][COLS], int rcw,int col);//����




