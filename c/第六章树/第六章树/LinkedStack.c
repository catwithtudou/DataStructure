#include "LinkedStack.h"

/** 初始化链栈 */
void InitLinkedStack(LinkedStack * linkedStack)
{
    linkedStack->top=NULL;
    linkedStack->length=0;
}

/** 入栈 */
int Push(LinkedStack * linkedStack,TreeNode * node)
{
    StackNode * tempNode=(StackNode *)malloc(sizeof(StackNode));
    tempNode->data=node;
    tempNode->next=linkedStack->top;
    linkedStack->top=tempNode;
    linkedStack->length++;
    return 1;

}

/** 出栈 */
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
