#include"Gobang.h"

/**��ʼ��/��������*/
void InitChessBoard()
{
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            ChessBorad[i][j]="ʮ";
        }
    }
}

/**��ӡ����*/
void PrintChessBoard()
{
        for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            printf("%s",ChessBorad[i][j]);
        }
        printf("\n");
    }
}
