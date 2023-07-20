#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define RCW 3
#define COL 3

void Initboard(char board[RCW][COL], int rcw, int col);//初始化棋盘

void Displayboard(char board[RCW][COL], int rcw, int col);//打印棋盘

void PlayerMove(char board[RCW][COL], int rcw, int col,int*num);//玩家下棋

void ComputerMove(char board[RCW][COL], int rcw, int col);//电脑下棋


//返回*代表玩家赢
//返回#代表电脑赢
//返回c代表游戏继续
//返回f代表平局
char is_win(char board[RCW][COL], int rcw, int col);//判断输赢

int is_full(char board[RCW][COL], int rcw, int col);//判断满