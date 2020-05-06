#include "LinkedStack.h"

/** ��ʼ����ջ */
void InitStack(LinkedStack * linkedStack){
    linkedStack->top = NULL;
    linkedStack->length = 0;
}

/** ѹջ */
int Push(LinkedStack * linkedStack, TreeNode * node){
    StackNode * tempStackNode = (StackNode *)malloc(sizeof(StackNode));
    tempStackNode->data = node;
    tempStackNode->next = linkedStack->top;
    linkedStack->top = tempStackNode;
    linkedStack->length++;
    return 1;
}

/** ��ջ */
int Pop(LinkedStack * linkedStack, TreeNode ** node){
    StackNode * tempNode;
    if(IsLinkedStackEmpty(*linkedStack) == 1){
        return 0;
    }
    *node = linkedStack->top->data;
    //printf("node:[%d, %s] ", (*node)->data.id, (*node)->data.name);
    tempNode = linkedStack->top;
    linkedStack->top = linkedStack->top->next;
    free(tempNode);
    linkedStack->length--;
    return 1;
}

/** �Ƿ�Ϊ�� */
int IsLinkedStackEmpty(LinkedStack linkedStack){
    return linkedStack.top == NULL ? 1 : 0;
}

void ClearLinkedStack(LinkedStack * linkedStack){
    StackNode * node;
    while(linkedStack->top){
        node = linkedStack->top;
        linkedStack->top = linkedStack->top->next;
        free(node);
        linkedStack->length--;
    }
}

/** ����ջ */
void DestroyLinkedStack(LinkedStack * linkedStack){
    ClearLinkedStack(linkedStack);
    free(linkedStack);
    linkedStack = NULL;
}
