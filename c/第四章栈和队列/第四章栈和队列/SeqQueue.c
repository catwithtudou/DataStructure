#include "SeqQueue.h"

/**初始化*/
void InitSeqQueue(SeqQueue * seqQueue)
{
    if(seqQueue==NULL){
        seqQueue=(SeqQueue *)malloc(sizeof(SeqQueue));
    }
    seqQueue->length=0;
    seqQueue->front=0;
    seqQueue->rear=0;
}

/**以TRUE/FALSE的方式返回传入的队列是否为空*/
State IsSeqQueueEmpty(SeqQueue * seqQueue)
{
    //队头指针若与队尾指针相同则队列为空
    return seqQueue->front==seqQueue->rear ? TRUE:FALSE;
}

/**判断队列是否已满*/
State  IsSeqQueueFull(SeqQueue * seqQueue)
{
    if((seqQueue->rear+1)%MAX_SIZE==seqQueue->front){
        return TRUE;
    }
    return FALSE;
}

/**入队*/
State OfferSeqQueue(SeqQueue * seqQueue,ElementType element)
{
    if(IsSeqQueueFull(seqQueue)){
        printf("队列已满,无法入队!\n");
        return STATE_FALASE;
    }
    seqQueue->data[seqQueue->rear]=element;
    seqQueue->rear=(seqQueue->rear+1)%MAX_SIZE;
    seqQueue->length++;
    return STATE_OK;
}

/**出队*/
State PollSeqQueue(SeqQueue * seqQueue,ElementType * element)
{
    if(IsSeqQueueEmpty(seqQueue)){
        return STATE_FALASE;
    }
    //取出队头元素
    *element=seqQueue->data[seqQueue->front];
    seqQueue->front=(seqQueue->front+1)%MAX_SIZE;
    seqQueue->length--;
    return STATE_OK;
}
