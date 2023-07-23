#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define RCW 3
#define COL 3

void InitBoard(char board[RCW][COL],int rcw,int col);

void DispalyBoard(char board[RCW][COL], int rcw, int col);

void PlayerMove(char board[RCW][COL], int rcw, int col);

void ComputerMove(char board[RCW][COL], int rcw,int col);

char is_win(char board[RCW][COL], int rcw, int col);

int Is_full(char board[RCW][COL], int rcw, int col);





