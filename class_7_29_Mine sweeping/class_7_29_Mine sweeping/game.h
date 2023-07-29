#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_MODE 10
#define RCW 9
#define COL 9
#define RCWS RCW+2
#define COLS COL+2

//函数声明

void Init_Board(char Board[RCWS][COLS], int rcw,int col,char set);//初始化棋盘

void Display_Board(char Board[RCWS][COLS],int rcw,int col);//打印棋盘

void SetMine(char mine[RCWS][COLS],int rcw,int col);//布置雷

void Find_mine(char show[RCWS][COLS], char mine[RCWS][COLS], int rcw,int col);//排雷




