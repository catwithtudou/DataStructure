#ifndef GOBANG_H_INCLUDED
#define GOBANG_H_INCLUDED

/**
*       第四章栈和队列示例
*       五子棋相关操作
*/


#include<stdio.h>
#include<stdlib.h>
#include"Element.h"
#define BOARD_SIZE 15

/**棋盘数组*/
char * ChessBorad[BOARD_SIZE][BOARD_SIZE];

/**初始化/重置棋盘*/
void InitChessBoard();

/**打印棋盘*/
void PrintChessBoard();
#endif // GOBANG_H_INCLUDED
