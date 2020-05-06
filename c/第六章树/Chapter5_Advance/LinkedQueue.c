#include "LinkedQueue.h"

void InitQueue(LinkedQueue * linkedQueue){
    linkedQueue->qFront = (QueueNode *)malloc(sizeof(QueueNode));
    linkedQueue->qFront->next = NULL;
    linkedQueue->qRear = linkedQueue->qFront;
}
//入队
void enQueue(LinkedQueue * linkedQueue, ElemType * data){
    QueueNode * node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    linkedQueue->qRear->next = node;
    linkedQueue->qRear = node;
}
//出队
ElemType * deQueue(LinkedQueue * linkedQueue){
    ElemType * data = NULL;
    if(linkedQueue->qFront == linkedQueue->qRear) return data;
    QueueNode * node = linkedQueue->qFront->next;
    data = node->data;
    linkedQueue->qFront->next = node->next;
    if(linkedQueue->qRear == node){
        linkedQueue->qRear = linkedQueue->qFront;
    }
    free(node);
    return data;
}
//是否为空
int IsEmpty(LinkedQueue * linkedQueue){
    return linkedQueue->qFront == linkedQueue->qRear ? 1 : 0;
}
