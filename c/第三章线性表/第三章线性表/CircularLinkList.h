#ifndef CIRCULARLINKLIST_H_INCLUDED
#define CIRCULARLINKLIST_H_INCLUDED
/**
*  数据结构第二章循环链表示例
*  特点:尾节点的指针域指向第一个节点
*  优点:任意节点遍历整个链表结构
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "DataElement.h"
/**循环链表的节点*/
typedef struct CircularNode{
   ElementType    data;                  //数据域
   struct CircularNode * next;       //指向下个节点的指针域
}CircularNode;

/**循环链表结构*/
typedef struct CircularLinkList{
 CircularNode * next; //指向第一个节点的指针,头指针
 int length;
}CircularLinkList;

void InsertCircularLinkList(CircularLinkList * clList,int pos,ElementType data);

void InitCircularLinkList(CircularLinkList * clList,ElementType * data,int length);

//删除并返回指定位置的元素
ElementType DeleteCircularLinkList(CircularLinkList * clList,int pos);

//根据元素内容返回对应的节点指针
CircularNode * GetCircularLinkListNode(CircularLinkList * clList,ElementType element);

//通过给定的某个节点循环遍历出整个链表
void PrintCircularLinkListByNode(CircularLinkList * clList,CircularNode * node);

void PrintCircularLinkList(CircularLinkList * clList);
#endif // CIRCULARLINKLIST_H_INCLUDED
