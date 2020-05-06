#ifndef STATICLINKLIST_H_INCLUDED
#define STATICLINKLIST_H_INCLUDED

/**
*  ��̬������
*  ��̬����Ķ���ͳ��ò���
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

#define MAX_SIZE_SSL 10
#define OK 1
#define ERROR 0

/**��̬����-�ṹ����*/
typedef struct {
    ElementType data; //������
    int next;         //int cursor,�α�.���Ϊ0��ʾ��ָ��
}StaticLinkList[MAX_SIZE_SSL];

/**��ʼ������*/
void InitStaticLinkList(StaticLinkList slList);

/**��ָ��λ�ò���Ԫ��*/
int InsertStaticLinkList(StaticLinkList slList,int pos,ElementType element);

/**Ϊ��̬�������һ���ռ���ڴ�,����ERROR��ʾ����ʧ��*/
int mallocSSL(StaticLinkList slList);

/**��þ�̬����ĳ���*/
int GetStaticLinkList(StaticLinkList slList);

/**����ԭʼ������ָ���±�Ŀռ�*/
void FreeStaticLinkList(StaticLinkList slList,int index);

/**ɾ������ָ��λ�õ�Ԫ��*/
int DeleteStaticLinkList(StaticLinkList slList,int pos);

void PrintStaticLinkList(StaticLinkList slList);

#endif // STATICLINKLIST_H_INCLUDED
