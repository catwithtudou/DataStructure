#include "LinkStack.h"

/**初始化链栈*/
void InitLinkedStack(LinkedStack * linkedStack)
{
    linkedStack->top=NULL;
    linkedStack->length=0;
}

/**压栈链栈*/
int PushLinkedStack(LinkedStack * linkedStack,ChessMan element)
{
    //创建一个新结点
    StackNode * newNode=(StackNode *)malloc(sizeof(StackNode));
    newNode->data=element;
    //新结点的next指向当前的栈顶
    newNode->next=linkedStack->top;
    linkedStack->top=newNode;
    linkedStack->length++;
    return TRUE;

}

/**出栈链栈*/
int PopLinkedStack(LinkedStack * linkedStack,ChessMan * element)
{
    //首先判断是否为空
    if(linkedStack->top==NULL){
        printf("栈顶为空,无法出栈!\n");
        return FALSE;
    }
    //返回栈顶元素
    *element=linkedStack->top->data;
    //记录出栈操作前的栈顶指针
    StackNode * popNode=linkedStack->top;
    //栈顶指针下移一位
    linkedStack->top=linkedStack->top->next;
    //释放原栈顶
    free(popNode);
    linkedStack->length--;
    return TRUE;
}


/**清空栈-遍历栈中的每个元素并释放结点空间*/
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

/**销毁栈*/
void DestroyLinkedStack(LinkedStack * linkedStack)
{
    //先清空栈
    ClearLinkedStack(linkedStack);
    free(linkedStack);
    linkedStack=NULL;
}

/**得到栈顶元素*/
void GetLinkedStackTopElement(LinkedStack * linkedStack,ChessMan * element)
{
    if(linkedStack->top==NULL){
        printf("空栈!\n");
        return;
    }
    *element=linkedStack->top->data;

}
