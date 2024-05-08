/**
  ******************************************************************************
  * @file           : game.h
  * @author         : wj
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/8
  ******************************************************************************
  */

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_MINE 10 //雷的个数

//初始化棋盘
void InitBoard(char board[ROWS][COLS],int  rows,int cols ,char set);

//打印棋盘
void DisPlayBoard(char board[ROWS][COLS], int row,int col);

//布置雷
void SetMine(char board[ROWS][COLS],int row,int col);

//排雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
#endif //GAME_H
