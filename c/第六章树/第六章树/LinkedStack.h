#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED


/**
*    ����������ʾ��
*    Ϊ��ʵ�ַǵݹ鷽ʽ�Ķ����������,�����Զ���һ����ջ�ṹ
*/

#include "TreeNode.h"
#include <stdio.h>

/** ջ��� */
typedef struct stackNode{
    TreeNode * data; //������-��֮ǰʵ�ֵ���ջ������ͬ
    struct stackNode * next;  //ָ����

}StackNode;

/** ��ջ */
typedef struct{
  StackNode * top;  //ջ��ָ��
  int length;       //ջ����
}LinkedStack;

/** ��ʼ����ջ */
void InitLinkedStack(LinkedStack * linkedStack);

/** ��ջ */
int Push(LinkedStack * linkedStack,TreeNode * node);

/** ��ջ */
int Pop(LinkedStack * linkedStack,TreeNode ** node);

int IsLinkedStackEmpty(LinkedStack * linkedStack);
#endif // LINKEDSTACK_H_INCLUDED
