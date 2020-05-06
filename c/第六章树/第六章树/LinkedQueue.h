#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

/**
*    第六章树的示例
*    链队列-用于二叉链表的层序遍历
*/

#include "TreeNode.h"
#include <string.h>

/** 链队结点 */
typedef struct qNode{
    TreeNode * data;      //数据域
    struct qNode * next;  //指针域
}QueueNode;

/** 链队列 */
typedef struct {
    QueueNode * qFront;   //队头指针
    QueueNode * qRear;    //队尾指针
}LinkedQueue;

void InitLinkedQueue(LinkedQueue * linkedQueue);

void InQueue(LinkedQueue * linkedQueue,TreeNode * data);

TreeNode * OutQueue(LinkedQueue * linkedQueue);

int IsLinkedQueue(LinkedQueue * linkedQueue);
#endif // LINKEDQUEUE_H_INCLUDED
