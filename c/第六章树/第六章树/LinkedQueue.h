#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

/**
*    ����������ʾ��
*    ������-���ڶ�������Ĳ������
*/

#include "TreeNode.h"
#include <string.h>

/** ���ӽ�� */
typedef struct qNode{
    TreeNode * data;      //������
    struct qNode * next;  //ָ����
}QueueNode;

/** ������ */
typedef struct {
    QueueNode * qFront;   //��ͷָ��
    QueueNode * qRear;    //��βָ��
}LinkedQueue;

void InitLinkedQueue(LinkedQueue * linkedQueue);

void InQueue(LinkedQueue * linkedQueue,TreeNode * data);

TreeNode * OutQueue(LinkedQueue * linkedQueue);

int IsLinkedQueue(LinkedQueue * linkedQueue);
#endif // LINKEDQUEUE_H_INCLUDED
