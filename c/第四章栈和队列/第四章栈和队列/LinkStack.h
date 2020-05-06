#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED

/**
*       ������ջ�Ͷ���ʾ��
*       ������ջ���ݽṹ�����ò���
*/


#include<stdio.h>
#include<stdlib.h>
#include"Element.h"


/**��ջ�Ľڵ�*/
typedef struct StackNode{
    ChessMan data;    //����б����Ԫ��
    struct StackNode * next;//ָ����һ������ָ��
}StackNode;

/**��ջ�ṹ*/
typedef struct LinkedStack{
    StackNode * top;   //ջ��ָ��
    int length;        //��ջ����(Ԫ�ظ���)

}LinkedStack;

/**��ʼ����ջ*/
void InitLinkedStack(LinkedStack * linkedStack);

/**ѹջ��ջ*/
int PushLinkedStack(LinkedStack * linkedStack,ChessMan element);

/**��ջ��ջ*/
int PopLinkedStack(LinkedStack * linkedStack,ChessMan * element);

/**���ջ-����ջ�е�ÿ��Ԫ�ز��ͷŽ��ռ�*/
void ClearLinkedStack(LinkedStack * linkedStack);

/**����ջ*/
void DestroyLinkedStack(LinkedStack * linkedStack);

/**�õ�ջ��Ԫ��*/
void GetLinkedStackTopElement(LinkedStack * linkedStack,ChessMan * element);

#endif // LINKSTACK_H_INCLUDED
