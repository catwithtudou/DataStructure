#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: ������ - ���ڶ�������Ĳ������
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include "TreeNode.h"
#include "BrotherTree.h"

//typedef TreeNode ElemType;
typedef CBNode ElemType;

typedef struct queueNode{
    ElemType * data;        //�����Ľ������Ϊ����Ԫ��
    struct queueNode * next;
}QueueNode;

typedef struct {
    QueueNode * qFront;     //��ͷָ��
    QueueNode * qRear;      //��βָ��
}LinkedQueue;

void InitQueue(LinkedQueue * linkedQueue);
//���
void enQueue(LinkedQueue * linkedQueue, ElemType * data);
//����
ElemType * deQueue(LinkedQueue * linkedQueue);
//�Ƿ�Ϊ��
int IsEmpty(LinkedQueue * linkedQueue);
#endif // LINKEDQUEUE_H_INCLUDED
