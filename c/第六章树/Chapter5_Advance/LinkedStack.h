#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#include <stdio.h>
#include "TreeNode.h"

/** ջ��� */
typedef struct stackNode{
    TreeNode * data;
    struct stackNode * next;
}StackNode;

/** ��ջ�ṹ */
typedef struct {
    StackNode * top;    //ջ��ָ��
    int length;         //ջ�е�Ԫ�����������ȣ�
}LinkedStack;

/** ��ʼ����ջ */
void InitStack(LinkedStack * linkedStack);

/** ѹջ */
int Push(LinkedStack * linkedStack, TreeNode * node);

/** ��ջ */
int Pop(LinkedStack * linkedStack, TreeNode ** node);

/** �Ƿ�Ϊ�� */
int IsLinkedStackEmpty(LinkedStack linkedStack);

/** ���ջ */
void ClearLinkedStack(LinkedStack * linkedStack);

/** ����ջ */
void DestroyLinkedStack(LinkedStack * linkedStack);








#endif // LINKEDSTACK_H_INCLUDED
