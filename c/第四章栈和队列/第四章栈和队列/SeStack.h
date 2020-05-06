#ifndef SESTACK_H_INCLUDED
#define SESTACK_H_INCLUDED

/**
*    第四章栈和队列示例
*    定义顺序栈结构
*/
#include<stdio.h>
#include<stdlib.h>
#include"Element.h"

/**定义栈的顺序存储方式*/
typedef struct SeqStack {
    ElementType elements[MAX_SIZE]; //顺序栈中用来存放数据元素的数组
    int top;                        //栈顶(数组中的下标),若为-1则说明栈为空
    int length;                     //当前栈的元素个数
}SeqStack;

/**初始化栈*/
void InitSeqStack(SeqStack * seqStack);

/**向栈中压入元素,返回压入的结构(True1,False0)*/
int PushSeqStack(SeqStack * seqStack,ElementType element);

/**以指针方式返回出栈的元素,返回值为出栈的结果*/
int PopSeqStack(SeqStack * seqStack,ElementType * element);

/**清空栈*/
void ClearSeqStack(SeqStack * seqStack);

/**栈是否为空*/
int IsNullSeqStack(SeqStack * seqStack);

/**返回栈顶元素*/
void GetSeqStackTopElement(SeqStack * seqStack,ElementType * element);

#endif // SESTACK_H_INCLUDED
