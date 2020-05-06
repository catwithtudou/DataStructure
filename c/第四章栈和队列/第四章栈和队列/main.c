#include <stdio.h>
#include <stdlib.h>
#include "SeStack.h"
#include "Element.h"
#include "LinkStack.h"
#include "Gobang.h"
#include "SeqQueue.h"
ElementType datas[]={
{1,"��С"},
{2,"��С"},
{3,"֣С"},
{4,"��С"}
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
    printf("��ǰ����Ԫ��: \n");
    printf("%d\t%s\n",element->id,element->name);
    printf("���Ӳ�����Ķ���Ԫ��: \n");
        for(int i=seqQueue.front;i<seqQueue.rear;i++){
        printf("%d\t%s\n",seqQueue.data[i].id,seqQueue.data[i].name);
    }
}



void TestLinkedStack()
{
    InitChessBoard();
    PrintChessBoard();
    LinkedStack * linkedStack=(LinkedStack *)malloc(sizeof(LinkedStack));
    //ģ�����ӵĹ���
    for(int i=0;i<5;i++){
        //��¼��ÿ�ε��������
        PushLinkedStack(linkedStack,chessArray[i]);
        //�������������޸�����
        if(chessArray[i].type==BLACK){
            ChessBorad[chessArray[i].y-1][chessArray[i].x-1]="��";
        }else{
            ChessBorad[chessArray[i].y-1][chessArray[i].x-1]="��";
        }
    }
    printf("\n���Ӻ�\n");
    PrintChessBoard();
    //�Զ�����
    while(linkedStack->top){
        printf("�����������: \n");
        getchar();
        ChessMan currChess;
        //��ջ-���ػڵ��ⲽ��
        PopLinkedStack(linkedStack,&currChess);
        ChessBorad[currChess.y-1][currChess.x-1]="ʮ";
        PrintChessBoard();
    }
}
void TestSeqStack()
{
    SeqStack * stack=(SeqStack *)malloc(sizeof(SeqStack));
    ElementType * element=(ElementType *)malloc(sizeof(ElementType));
    InitSeqStack(stack);
    for(int i=0;i<4;i++){
        printf("��ǰ��ջ:%d\t%s\n",datas[i].id,datas[i].name);
        PushSeqStack(stack,datas[i]);
    }
    PopSeqStack(stack,element);
    printf("��ǰ��ջԪ��:%d\t%s\n",element->id,element->name);
    for(int i=0;i<stack->length;i++){
        printf("��ǰջ��Ԫ��:%d\t%s\n",stack->elements[i].id,stack->elements[i].name);
    }
    free(stack);
}
