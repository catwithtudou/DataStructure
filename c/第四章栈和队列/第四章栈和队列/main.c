#include <stdio.h>
#include <stdlib.h>
#include "SeStack.h"
#include "Element.h"
#include "LinkStack.h"
#include "Gobang.h"
#include "SeqQueue.h"
ElementType datas[]={
{1,"唐小"},
{2,"周小"},
{3,"郑小"},
{4,"苏小"}
};

ChessMan chessArray[]={
    {7,7,BLACK},
    {8,8,WHITE},
    {6,8,BLACK},
    {8,6,WHITE},
    {6,7,BLACK}
};

void TestLinkedStack();

void TestSeqStack();

void TestSeqQueue();

int main()
{
    printf("Hello world!\n");
   // TestSeqStack();
    //TestLinkedStack();
    TestSeqQueue();
    return 0;
}

void TestSeqQueue()
{
    SeqQueue seqQueue;
    InitSeqQueue(&seqQueue);
    int flag1=OfferSeqQueue(&seqQueue,datas[0]);
    int flag2=OfferSeqQueue(&seqQueue,datas[1]);
    int flag3=OfferSeqQueue(&seqQueue,datas[2]);
    int flag4=OfferSeqQueue(&seqQueue,datas[3]);
    for(int i=0;i<seqQueue.length;i++){
        printf("%d\t%s\n",seqQueue.data[i].id,seqQueue.data[i].name);
    }
    ElementType * element=(ElementType *)malloc(sizeof(ElementType));
    int flag5=PollSeqQueue(&seqQueue,element);
    printf("当前出队元素: \n");
    printf("%d\t%s\n",element->id,element->name);
    printf("出队操作后的队列元素: \n");
        for(int i=seqQueue.front;i<seqQueue.rear;i++){
        printf("%d\t%s\n",seqQueue.data[i].id,seqQueue.data[i].name);
    }
}



void TestLinkedStack()
{
    InitChessBoard();
    PrintChessBoard();
    LinkedStack * linkedStack=(LinkedStack *)malloc(sizeof(LinkedStack));
    //模拟落子的过程
    for(int i=0;i<5;i++){
        //记录下每次的落子情况
        PushLinkedStack(linkedStack,chessArray[i]);
        //根据棋子类型修改棋盘
        if(chessArray[i].type==BLACK){
            ChessBorad[chessArray[i].y-1][chessArray[i].x-1]="○";
        }else{
            ChessBorad[chessArray[i].y-1][chessArray[i].x-1]="●";
        }
    }
    printf("\n落子后\n");
    PrintChessBoard();
    //自动悔棋
    while(linkedStack->top){
        printf("按任意键悔棋: \n");
        getchar();
        ChessMan currChess;
        //出栈-返回悔的这步棋
        PopLinkedStack(linkedStack,&currChess);
        ChessBorad[currChess.y-1][currChess.x-1]="十";
        PrintChessBoard();
    }
}
void TestSeqStack()
{
    SeqStack * stack=(SeqStack *)malloc(sizeof(SeqStack));
    ElementType * element=(ElementType *)malloc(sizeof(ElementType));
    InitSeqStack(stack);
    for(int i=0;i<4;i++){
        printf("当前入栈:%d\t%s\n",datas[i].id,datas[i].name);
        PushSeqStack(stack,datas[i]);
    }
    PopSeqStack(stack,element);
    printf("当前出栈元素:%d\t%s\n",element->id,element->name);
    for(int i=0;i<stack->length;i++){
        printf("当前栈内元素:%d\t%s\n",stack->elements[i].id,stack->elements[i].name);
    }
    free(stack);
}
