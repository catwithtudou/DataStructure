#include "LinkStack.h"

/**��ʼ����ջ*/
void InitLinkedStack(LinkedStack * linkedStack)
{
    linkedStack->top=NULL;
    linkedStack->length=0;
}

/**ѹջ��ջ*/
int PushLinkedStack(LinkedStack * linkedStack,ChessMan element)
{
    //����һ���½��
    StackNode * newNode=(StackNode *)malloc(sizeof(StackNode));
    newNode->data=element;
    //�½���nextָ��ǰ��ջ��
    newNode->next=linkedStack->top;
    linkedStack->top=newNode;
    linkedStack->length++;
    return TRUE;

}

/**��ջ��ջ*/
int PopLinkedStack(LinkedStack * linkedStack,ChessMan * element)
{
    //�����ж��Ƿ�Ϊ��
    if(linkedStack->top==NULL){
        printf("ջ��Ϊ��,�޷���ջ!\n");
        return FALSE;
    }
    //����ջ��Ԫ��
    *element=linkedStack->top->data;
    //��¼��ջ����ǰ��ջ��ָ��
    StackNode * popNode=linkedStack->top;
    //ջ��ָ������һλ
    linkedStack->top=linkedStack->top->next;
    //�ͷ�ԭջ��
    free(popNode);
    linkedStack->length--;
    return TRUE;
}


/**���ջ-����ջ�е�ÿ��Ԫ�ز��ͷŽ��ռ�*/
void ClearLinkedStack(LinkedStack * linkedStack)
{
    StackNode * tempNode;
    while(linkedStack->top){
        tempNode=linkedStack->top;
        linkedStack->top=linkedStack->top->next;
        free(tempNode);
        linkedStack->length--;
    }
}

/**����ջ*/
void DestroyLinkedStack(LinkedStack * linkedStack)
{
    //�����ջ
    ClearLinkedStack(linkedStack);
    free(linkedStack);
    linkedStack=NULL;
}

/**�õ�ջ��Ԫ��*/
void GetLinkedStackTopElement(LinkedStack * linkedStack,ChessMan * element)
{
    if(linkedStack->top==NULL){
        printf("��ջ!\n");
        return;
    }
    *element=linkedStack->top->data;

}
