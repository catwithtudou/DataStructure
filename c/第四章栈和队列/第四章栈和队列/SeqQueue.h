#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED
/**
*       ������ջ�Ͷ���ʾ��
*       ѭ�����о��Ƕ���ͷβ��ӵ�˳��洢�ṹ
*       ����δ��ʱ�����Բ����µĶ�βԪ��
*/


#include<stdio.h>
#include<stdlib.h>
#include"Element.h"

#define STATE_OK 1
#define STATE_FALASE -1

typedef int State; //��������һ������,ר��������ʶ״̬


/**ѭ�����нṹ*/
typedef struct{
    ElementType data[MAX_SIZE]; //ElementType * base;
    int front;   //��ͷָ��
    int rear;    //��βָ��
    int length;  //���г���
    //Ҳ�������ӱ�ʶλ,��ʶ��ǰ�����Ƿ�����
}SeqQueue;

/**��ʼ��*/
void InitSeqQueue(SeqQueue * seqQueue);

/**���*/
State OfferSeqQueue(SeqQueue * seqQueue,ElementType element);

/**����*/
State PollSeqQueue(SeqQueue * seqQueue,ElementType * element);

/**��TRUE/FALSE�ķ�ʽ���ش���Ķ����Ƿ�Ϊ��*/
State IsSeqQueueEmpty(SeqQueue * seqQueue);

/**�ж϶����Ƿ�����*/
State  IsSeqQueueFull(SeqQueue * seqQueue);
#endif // SEQQUEUE_H_INCLUDED
