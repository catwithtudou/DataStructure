#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#include <stdio.h>
#include "TreeNode.h"

/** 栈结点 */
typedef struct stackNode{
    TreeNode * data;
    struct stackNode * next;
}StackNode;

/** 链栈结构 */
typedef struct {
    StackNode * top;    //栈顶指针
    int length;         //栈中的元素总数（长度）
}LinkedStack;

/** 初始化链栈 */
void InitStack(LinkedStack * linkedStack);

/** 压栈 */
int Push(LinkedStack * linkedStack, TreeNode * node);

/** 出栈 */
int Pop(LinkedStack * linkedStack, TreeNode ** node);

/** 是否为空 */
int IsLinkedStackEmpty(LinkedStack linkedStack);

/** 清空栈 */
void ClearLinkedStack(LinkedStack * linkedStack);

/** 销毁栈 */
void DestroyLinkedStack(LinkedStack * linkedStack);








#endif // LINKEDSTACK_H_INCLUDED
