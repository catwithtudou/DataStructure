#ifndef BROTHERLINKEDQUEUE_H_INCLUDED
#define BROTHERLINKEDQUEUE_H_INCLUDED
#include <string.h>
#include "ElementType.h"


/** 孩子兄弟结点 */
typedef struct cbNode{
    ElementType data;
    struct cbNode * firstChild;  //长子结点
    struct cbNode * nextSibling; //兄弟结点
}CBNode,*CBTree;


/** 链队结点 */
typedef struct qNode1{
    CBNode * data;      //数据域
    struct qNode * next;  //指针域
}QueueNode1;

/** 链队列 */
typedef struct {
    QueueNode1 * qFront;   //队头指针
    QueueNode1 * qRear;    //队尾指针
}LinkedQueue1;

void InitLinkedQueue1(LinkedQueue1 * linkedQueue);

void InQueue1(LinkedQueue1 * linkedQueue,CBNode * data);

CBNode * OutQueue1(LinkedQueue1 * linkedQueue);

int IsLinkedQueue1(LinkedQueue1 * linkedQueue);

#endif // BROTHERLINKEDQUEUE_H_INCLUDED
