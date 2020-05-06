#ifndef SESTACK_H_INCLUDED
#define SESTACK_H_INCLUDED

/**
*    ������ջ�Ͷ���ʾ��
*    ����˳��ջ�ṹ
*/
#include<stdio.h>
#include<stdlib.h>
#include"Element.h"

/**����ջ��˳��洢��ʽ*/
typedef struct SeqStack {
    ElementType elements[MAX_SIZE]; //˳��ջ�������������Ԫ�ص�����
    int top;                        //ջ��(�����е��±�),��Ϊ-1��˵��ջΪ��
    int length;                     //��ǰջ��Ԫ�ظ���
}SeqStack;

/**��ʼ��ջ*/
void InitSeqStack(SeqStack * seqStack);

/**��ջ��ѹ��Ԫ��,����ѹ��Ľṹ(True1,False0)*/
int PushSeqStack(SeqStack * seqStack,ElementType element);

/**��ָ�뷽ʽ���س�ջ��Ԫ��,����ֵΪ��ջ�Ľ��*/
int PopSeqStack(SeqStack * seqStack,ElementType * element);

/**���ջ*/
void ClearSeqStack(SeqStack * seqStack);

/**ջ�Ƿ�Ϊ��*/
int IsNullSeqStack(SeqStack * seqStack);

/**����ջ��Ԫ��*/
void GetSeqStackTopElement(SeqStack * seqStack,ElementType * element);

#endif // SESTACK_H_INCLUDED
