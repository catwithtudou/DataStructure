#ifndef DOUBLYLINKLIST_H_INCLUDED
#define DOUBLYLINKLIST_H_INCLUDED

/**
*    ˫������ʾ��
*    �ڵ�����Ļ�����������ǰ׺�ڵ�,һ���̶��������˲���Ԫ�ص�����
*    �ڲ���Ԫ��ʱ���Է������ǰ׺�ڵ�
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"


/**˫������Ľڵ�,����һ��������,����ָ����*/
typedef struct DoublyNode{
    ElementType data;
    struct DoublyNode * prev;//ָ��ǰ׺�ڵ�
    struct DoublyNode * next;//ָ���̽ڵ�
}DoublyNode;

/**˫������*/
typedef struct DoublyLinkList{
    int length;
    DoublyNode * next;
}DoublyLinkList;

/**��˫�������е�ָ��λ�ò���Ԫ��*/
void InsertDoublyLinkList(DoublyLinkList * dlList,int pos,ElementType element);

/**ɾ��˫������ָ��λ�õ�Ԫ�ز�����*/
ElementType DeleteDoublyLinkList(DoublyLinkList * dlList,int pos);

/**����˫��������ָ��λ�õ�������*/
ElementType GetDoublyLinkList(DoublyLinkList * dlList,int pos);

/**����˫��������ĳ���ڵ��ǰ�ýڵ�ָ��*/
DoublyNode * GetDoublyPrevNode(DoublyNode * node);


void PrintDoublyLinkList(DoublyLinkList * dlList);
#endif // DOUBLYLINKLIST_H_INCLUDED
