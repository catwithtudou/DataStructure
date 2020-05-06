#include "BrotherLinkedQueue.h"
void InitLinkedQueue1(LinkedQueue1 * linkedQueue)
{
    linkedQueue->qFront=(QueueNode1 *)malloc(sizeof(QueueNode1));
    linkedQueue->qFront->next=NULL;
    linkedQueue->qRear=linkedQueue->qFront;
}

void InQueue1(LinkedQueue1 * linkedQueue,CBNode * data)
{
   QueueNode1 * node=(QueueNode1 *)malloc(sizeof(QueueNode1));
    node->data=data;
    node->next=NULL;
    linkedQueue->qRear->next=node;
    linkedQueue->qRear=node;
}

CBNode * OutQueue1(LinkedQueue1 * linkedQueue)
{
    CBNode * data=NULL;//ÓÃÀ´·µ»Ø
    if(linkedQueue->qFront==linkedQueue->qRear)return data;
    QueueNode1 * node=linkedQueue->qFront->next;
    data=node->data;
    linkedQueue->qFront->next=node->next;
    if(linkedQueue->qRear==node){
        linkedQueue->qRear=linkedQueue->qFront;
    }
    free(node);
    return data;
}

int IsLinkedQueue1(LinkedQueue1 * linkedQueue)
{
    if(linkedQueue->qFront==linkedQueue->qRear){
        return 1;
    }
    return 0;
}
