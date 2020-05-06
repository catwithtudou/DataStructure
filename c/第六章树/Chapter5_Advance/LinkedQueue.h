#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: 链队列 - 用于二叉链表的层序遍历
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include "TreeNode.h"
#include "BrotherTree.h"

//typedef TreeNode ElemType;
typedef CBNode ElemType;

typedef struct queueNode{
    ElemType * data;        //将树的结点设置为队列元素
    struct queueNode * next;
}QueueNode;

typedef struct {
    QueueNode * qFront;     //队头指针
    QueueNode * qRear;      //队尾指针
}LinkedQueue;

void InitQueue(LinkedQueue * linkedQueue);
//入队
void enQueue(LinkedQueue * linkedQueue, ElemType * data);
//出队
ElemType * deQueue(LinkedQueue * linkedQueue);
//是否为空
int IsEmpty(LinkedQueue * linkedQueue);
#endif // LINKEDQUEUE_H_INCLUDED
