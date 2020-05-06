#ifndef STATICLINKLIST_H_INCLUDED
#define STATICLINKLIST_H_INCLUDED

/**
*  静态链表案例
*  静态链表的定义和常用操作
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

#define MAX_SIZE_SSL 10
#define OK 1
#define ERROR 0

/**静态链表-结构数组*/
typedef struct {
    ElementType data; //数据域
    int next;         //int cursor,游标.如果为0表示无指向
}StaticLinkList[MAX_SIZE_SSL];

/**初始化链表*/
void InitStaticLinkList(StaticLinkList slList);

/**向指定位置插入元素*/
int InsertStaticLinkList(StaticLinkList slList,int pos,ElementType element);

/**为静态链表分配一个空间的内存,返回ERROR表示分配失败*/
int mallocSSL(StaticLinkList slList);

/**获得静态链表的长度*/
int GetStaticLinkList(StaticLinkList slList);

/**回收原始数组中指定下标的空间*/
void FreeStaticLinkList(StaticLinkList slList,int index);

/**删除链表指定位置的元素*/
int DeleteStaticLinkList(StaticLinkList slList,int pos);

void PrintStaticLinkList(StaticLinkList slList);

#endif // STATICLINKLIST_H_INCLUDED
