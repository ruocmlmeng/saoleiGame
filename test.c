

#include "game.h"

void menu()
{
    printf("**************************\n");
    printf("*******  1.play **********\n");
    printf("*******  0.exit **********\n");
    printf("**************************\n");
}
void game()
{
    char mine[ROWS][COLS] = {0}; // 存放布置好的雷的信息
    char show[ROWS][COLS] = {0};// 存放排查出的雷的信息
    //初始化的内容为指定的内容
    //mine数组在没有布置雷的时候都是'0'
    InitBoard(mine,ROWS,COLS,'0');
    //show数组在没用排查雷的时候都是'*'
    InitBoard(show,ROWS,COLS,'*');

    //布置雷
    SetMine(mine,ROW,COL);
    //打印棋盘
    DisPlayBoard(mine,ROW,COL);
    DisPlayBoard(show,ROW,COL);

    //排雷
    FindMine(mine,show,ROWS,COL);
}
int main(void)
{
    //生成随机数的开端
    srand((unsigned int )time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("请输入选择项：>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误,请重新输入\n");
                break;
        }
    } while (input);
    return 0;
}
