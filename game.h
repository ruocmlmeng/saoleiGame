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

#define EASY_MINE 10 //�׵ĸ���

//��ʼ������
void InitBoard(char board[ROWS][COLS],int  rows,int cols ,char set);

//��ӡ����
void DisPlayBoard(char board[ROWS][COLS], int row,int col);

//������
void SetMine(char board[ROWS][COLS],int row,int col);

//����
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
#endif //GAME_H
