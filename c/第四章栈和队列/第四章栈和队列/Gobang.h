#ifndef GOBANG_H_INCLUDED
#define GOBANG_H_INCLUDED

/**
*       ������ջ�Ͷ���ʾ��
*       ��������ز���
*/


#include<stdio.h>
#include<stdlib.h>
#include"Element.h"
#define BOARD_SIZE 15

/**��������*/
char * ChessBorad[BOARD_SIZE][BOARD_SIZE];

/**��ʼ��/��������*/
void InitChessBoard();

/**��ӡ����*/
void PrintChessBoard();
#endif // GOBANG_H_INCLUDED
