#ifndef DOUBLYLINKLIST_H_INCLUDED
#define DOUBLYLINKLIST_H_INCLUDED

/**
*    双向链表示例
*    在单链表的基础上增加了前缀节点,一定程度上提升了查找元素的性能
*    在查找元素时可以反向查找前缀节点
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"


/**双向链表的节点,包含一个数据域,两个指针域*/
typedef struct DoublyNode{
    ElementType data;
    struct DoublyNode * prev;//指向前缀节点
    struct DoublyNode * next;//指向后继节点
}DoublyNode;

/**双向链表*/
typedef struct DoublyLinkList{
    int length;
    DoublyNode * next;
}DoublyLinkList;

/**向双向链表中的指定位置插入元素*/
void InsertDoublyLinkList(DoublyLinkList * dlList,int pos,ElementType element);

/**删除双向链表指定位置的元素并返回*/
ElementType DeleteDoublyLinkList(DoublyLinkList * dlList,int pos);

/**返回双向链表中指定位置的数据域*/
ElementType GetDoublyLinkList(DoublyLinkList * dlList,int pos);

/**返回双向链表中某个节点的前置节点指针*/
DoublyNode * GetDoublyPrevNode(DoublyNode * node);


void PrintDoublyLinkList(DoublyLinkList * dlList);
#endif // DOUBLYLINKLIST_H_INCLUDED
