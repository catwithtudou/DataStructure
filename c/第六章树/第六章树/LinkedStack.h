#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED


/**
*    第六章树的示例
*    为了实现非递归方式的二叉链表遍历,我们自定义一个链栈结构
*/

#include "TreeNode.h"
#include <stdio.h>

/** 栈结点 */
typedef struct stackNode{
    TreeNode * data; //数据域-与之前实现的链栈有所不同
    struct stackNode * next;  //指针域

}StackNode;

/** 链栈 */
typedef struct{
  StackNode * top;  //栈顶指针
  int length;       //栈长度
}LinkedStack;

/** 初始化链栈 */
void InitLinkedStack(LinkedStack * linkedStack);

/** 入栈 */
int Push(LinkedStack * linkedStack,TreeNode * node);

/** 出栈 */
int Pop(LinkedStack * linkedStack,TreeNode ** node);

int IsLinkedStackEmpty(LinkedStack * linkedStack);
#endif // LINKEDSTACK_H_INCLUDED
