#ifndef BROTHERLINKEDQUEUE_H_INCLUDED
#define BROTHERLINKEDQUEUE_H_INCLUDED
#include <string.h>
#include "ElementType.h"


/** �����ֵܽ�� */
typedef struct cbNode{
    ElementType data;
    struct cbNode * firstChild;  //���ӽ��
    struct cbNode * nextSibling; //�ֵܽ��
}CBNode,*CBTree;


/** ���ӽ�� */
typedef struct qNode1{
    CBNode * data;      //������
    struct qNode * next;  //ָ����
}QueueNode1;

/** ������ */
typedef struct {
    QueueNode1 * qFront;   //��ͷָ��
    QueueNode1 * qRear;    //��βָ��
}LinkedQueue1;

void InitLinkedQueue1(LinkedQueue1 * linkedQueue);

void InQueue1(LinkedQueue1 * linkedQueue,CBNode * data);

CBNode * OutQueue1(LinkedQueue1 * linkedQueue);

int IsLinkedQueue1(LinkedQueue1 * linkedQueue);

#endif // BROTHERLINKEDQUEUE_H_INCLUDED
