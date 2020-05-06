#include"Gobang.h"

/**初始化/重置棋盘*/
void InitChessBoard()
{
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            ChessBorad[i][j]="十";
        }
    }
}

/**打印棋盘*/
void PrintChessBoard()
{
        for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            printf("%s",ChessBorad[i][j]);
        }
        printf("\n");
    }
}
