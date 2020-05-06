#include "SeStack.h"

/**��ʼ��ջ*/
void InitSeqStack(SeqStack * seqStack)
{
    seqStack->top=-1;//ջ��ָ��-1���±�
    seqStack->length=0;
}

/**��ջ��ѹ��Ԫ��,����ѹ��Ľṹ(True1,False0)*/
int PushSeqStack(SeqStack * seqStack,ElementType element)
{
    if(seqStack->top==MAX_SIZE-1){
        printf("��ջ,ѹջ����ʧ��!\n");
        return FALSE;
    }
    //ջ��ָ��++,�Ա�����µ�Ԫ��
    seqStack->top++;
    //���²����Ԫ�ظ�ֵ��ջ��
    seqStack->elements[seqStack->top]=element;
    seqStack->length++;
    return TRUE;
}

/**��ָ�뷽ʽ���س�ջ��Ԫ��,����ֵΪ��ջ�Ľ��*/
int PopSeqStack(SeqStack * seqStack,ElementType * element)
{
    if(seqStack->top==-1){
        printf("��ջ,��ջʧ��!\n");
        return FALSE;
    }
    //����ջ��ָ���Ԫ��
    *element=seqStack->elements[seqStack->top];
    seqStack->top--;
    seqStack->length--;
    return TRUE;
}

/**���ջ*/
void ClearSeqStack(SeqStack * seqStack)
{
    seqStack->top=-1;
    seqStack->length=0;
}

/**����ջ��Ԫ��*/
void GetSeqStackTopElement(SeqStack * seqStack,ElementType * element)
{
    if(seqStack->top==-1){
        printf("��ջ,��ջʧ��!\n");
        return;
    }
    *element=seqStack->elements[seqStack->top];
}
