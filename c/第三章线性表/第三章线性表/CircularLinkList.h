#ifndef CIRCULARLINKLIST_H_INCLUDED
#define CIRCULARLINKLIST_H_INCLUDED
/**
*  ���ݽṹ�ڶ���ѭ������ʾ��
*  �ص�:β�ڵ��ָ����ָ���һ���ڵ�
*  �ŵ�:����ڵ������������ṹ
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "DataElement.h"
/**ѭ������Ľڵ�*/
typedef struct CircularNode{
   ElementType    data;                  //������
   struct CircularNode * next;       //ָ���¸��ڵ��ָ����
}CircularNode;

/**ѭ������ṹ*/
typedef struct CircularLinkList{
 CircularNode * next; //ָ���һ���ڵ��ָ��,ͷָ��
 int length;
}CircularLinkList;

void InsertCircularLinkList(CircularLinkList * clList,int pos,ElementType data);

void InitCircularLinkList(CircularLinkList * clList,ElementType * data,int length);

//ɾ��������ָ��λ�õ�Ԫ��
ElementType DeleteCircularLinkList(CircularLinkList * clList,int pos);

//����Ԫ�����ݷ��ض�Ӧ�Ľڵ�ָ��
CircularNode * GetCircularLinkListNode(CircularLinkList * clList,ElementType element);

//ͨ��������ĳ���ڵ�ѭ����������������
void PrintCircularLinkListByNode(CircularLinkList * clList,CircularNode * node);

void PrintCircularLinkList(CircularLinkList * clList);
#endif // CIRCULARLINKLIST_H_INCLUDED
