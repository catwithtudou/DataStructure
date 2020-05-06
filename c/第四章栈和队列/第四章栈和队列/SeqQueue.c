#include "SeqQueue.h"

/**��ʼ��*/
void InitSeqQueue(SeqQueue * seqQueue)
{
    if(seqQueue==NULL){
        seqQueue=(SeqQueue *)malloc(sizeof(SeqQueue));
    }
    seqQueue->length=0;
    seqQueue->front=0;
    seqQueue->rear=0;
}

/**��TRUE/FALSE�ķ�ʽ���ش���Ķ����Ƿ�Ϊ��*/
State IsSeqQueueEmpty(SeqQueue * seqQueue)
{
    //��ͷָ�������βָ����ͬ�����Ϊ��
    return seqQueue->front==seqQueue->rear ? TRUE:FALSE;
}

/**�ж϶����Ƿ�����*/
State  IsSeqQueueFull(SeqQueue * seqQueue)
{
    if((seqQueue->rear+1)%MAX_SIZE==seqQueue->front){
        return TRUE;
    }
    return FALSE;
}

/**���*/
State OfferSeqQueue(SeqQueue * seqQueue,ElementType element)
{
    if(IsSeqQueueFull(seqQueue)){
        printf("��������,�޷����!\n");
        return STATE_FALASE;
    }
    seqQueue->data[seqQueue->rear]=element;
    seqQueue->rear=(seqQueue->rear+1)%MAX_SIZE;
    seqQueue->length++;
    return STATE_OK;
}

/**����*/
State PollSeqQueue(SeqQueue * seqQueue,ElementType * element)
{
    if(IsSeqQueueEmpty(seqQueue)){
        return STATE_FALASE;
    }
    //ȡ����ͷԪ��
    *element=seqQueue->data[seqQueue->front];
    seqQueue->front=(seqQueue->front+1)%MAX_SIZE;
    seqQueue->length--;
    return STATE_OK;
}
