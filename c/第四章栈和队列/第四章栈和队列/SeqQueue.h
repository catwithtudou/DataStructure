#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED
/**
*       第四章栈和队列示例
*       循环队列就是队列头尾相接的顺序存储结构
*       数组未满时都可以插入新的队尾元素
*/


#include<stdio.h>
#include<stdlib.h>
#include"Element.h"

#define STATE_OK 1
#define STATE_FALASE -1

typedef int State; //给整型起一个别名,专门用来标识状态


/**循环队列结构*/
typedef struct{
    ElementType data[MAX_SIZE]; //ElementType * base;
    int front;   //队头指针
    int rear;    //队尾指针
    int length;  //队列长度
    //也可以增加标识位,标识当前队列是否已满
}SeqQueue;

/**初始化*/
void InitSeqQueue(SeqQueue * seqQueue);

/**入队*/
State OfferSeqQueue(SeqQueue * seqQueue,ElementType element);

/**出队*/
State PollSeqQueue(SeqQueue * seqQueue,ElementType * element);

/**以TRUE/FALSE的方式返回传入的队列是否为空*/
State IsSeqQueueEmpty(SeqQueue * seqQueue);

/**判断队列是否已满*/
State  IsSeqQueueFull(SeqQueue * seqQueue);
#endif // SEQQUEUE_H_INCLUDED
