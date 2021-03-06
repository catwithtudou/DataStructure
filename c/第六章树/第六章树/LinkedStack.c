#include "LinkedStack.h"

/** ��ʼ����ջ */
void InitLinkedStack(LinkedStack * linkedStack)
{
    linkedStack->top=NULL;
    linkedStack->length=0;
}

/** ��ջ */
int Push(LinkedStack * linkedStack,TreeNode * node)
{
    StackNode * tempNode=(StackNode *)malloc(sizeof(StackNode));
    tempNode->data=node;
    tempNode->next=linkedStack->top;
    linkedStack->top=tempNode;
    linkedStack->length++;
    return 1;

}

/** ��ջ */
int Pop(LinkedStack * linkedStack,TreeNode ** node)
{
    StackNode * tempNode;
    if(linkedStack->top==NULL||linkedStack->length==0){
        return 0;
    }
    *node=linkedStack->top->data;
    tempNode=linkedStack->top;
    linkedStack->top=linkedStack->top->next;
    free(tempNode);
    tempNode=NULL;
    linkedStack->length--;
    return 1;
}

int IsLinkedStackEmpty(LinkedStack * linkedStack)
{
        if(linkedStack->top==NULL||linkedStack->length==0){
        return 0;
    }
    return 1;
}
