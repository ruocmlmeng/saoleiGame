/**
  ******************************************************************************
  * @file           : game.c
  * @author         : wj
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/8
  ******************************************************************************
  */

#include "game.h"


//初始化棋盘
void InitBoard(char board[ROWS][COLS],int  rows,int cols ,char set)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < rows ; i++)
  {
    for (j = 0; j < cols ; j++)
    {
      board[i][j] = set;
    }
  }
}

//打印棋盘
void DisPlayBoard(char board[ROWS][COLS], int row,int col)
{
  int i = 0;
  int j = 0;
  printf("---------扫雷游戏--------\n");
  for (j = 0 ; j <= col  ; j++)
  {
    printf("%d ",j);
  }
  printf("\n");
  for (i = 1 ;i <= row ;i++)
  {
    printf("%d ",i);
    for (j = 1 ; j <= col ;j++)
    {
      printf("%c ",board[i][j]);
    }
    printf("\n");
  }
  printf("---------扫雷游戏--------\n");
}

//布置雷
void SetMine(char board[ROWS][COLS],int row,int col)
{
  //设置雷的个数
  int count = EASY_MINE;
  while (count)
  {
    int x = rand() % row + 1;//1 ~ 9
    int y = rand() % col + 1;//1 ~ 9
    if(board[x][y] == '0')
    {
      board[x][y] = '1';
      count--;
    }
  }
}

//计算周围雷的个数
int get_mine_count(char board[ROWS][COLS],int x,int y)
{
  return (board[x - 1][y] +
          board[x - 1][y - 1] +
            board[x][y - 1] +
              board[x + 1][y - 1] +
                board[x + 1][y] +
                  board[x + 1][y + 1] +
                    board[x][y + 1] +
                      board[x - 1][y + 1] - 8 * '0');
}
//排雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
  int x = 0;
  int y = 0;
  int win = 0;//判断胜利的条件
  while (win < row * col - EASY_MINE)
  {
    printf("请输入你要排雷的坐标:>");
    scanf("%d %d",&x,&y);
    if( x >= 1 && x <= row && y >= 1 && y <=col)
    {
      if (show[x][y] != '*')
      {
        printf("该坐标被排查过了,请重新输入坐标!\n");
      }
      else
      {
        //如果是雷
        if(mine[x][y] == '1')
        {
          printf("很遗憾你被炸死了!\n");
          DisPlayBoard(mine,ROW,COL);
          break;
        }
        else//如果不是雷
        {
          win++;
          //统计mine数组中,x,y坐标周围有几个雷
          int count = get_mine_count(mine,x,y);
          //将排查到的雷放到show函数中去
          show[x][y] = count + '0';
          DisPlayBoard(show,ROW,COL);
        }
      }
    }
    else
    {
      printf("输入不合法,请重新输入!\n");
    }
  }
  if( win == row * col - EASY_MINE)
  {
    printf("恭喜你排雷成功!\n");
    DisPlayBoard(mine,ROW,COL);
  }
}

//以上实现的是基本功能
//可以扩展
//1.标记雷的功能
//2.展开一片的功能
//  排查x,y坐标的时候:
//  1.该坐标不是雷
//  2.该坐标周围没有雷
//  3.该坐标没用被排查过