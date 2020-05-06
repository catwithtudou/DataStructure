#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED

/**
*       第四章栈和队列示例
*       定义链栈数据结构及常用操作
*/


#include<stdio.h>
#include<stdlib.h>
#include"Element.h"


/**链栈的节点*/
typedef struct StackNode{
    ChessMan data;    //结点中保存的元素
    struct StackNode * next;//指向下一个结点的指针
}StackNode;

/**链栈结构*/
typedef struct LinkedStack{
    StackNode * top;   //栈顶指针
    int length;        //链栈长度(元素个数)

}LinkedStack;

/**初始化链栈*/
void InitLinkedStack(LinkedStack * linkedStack);

/**压栈链栈*/
int PushLinkedStack(LinkedStack * linkedStack,ChessMan element);

/**出栈链栈*/
int PopLinkedStack(LinkedStack * linkedStack,ChessMan * element);

/**清空栈-遍历栈中的每个元素并释放结点空间*/
void ClearLinkedStack(LinkedStack * linkedStack);

/**销毁栈*/
void DestroyLinkedStack(LinkedStack * linkedStack);

/**得到栈顶元素*/
void GetLinkedStackTopElement(LinkedStack * linkedStack,ChessMan * element);

#endif // LINKSTACK_H_INCLUDED
