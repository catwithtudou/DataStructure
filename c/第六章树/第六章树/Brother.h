#ifndef BROTHER_H_INCLUDED
#define BROTHER_H_INCLUDED

/**
*    ����������ʾ��
*    ���ĺ����ֵܱ�ʾ��.�ŵ����ںͶ������Ķ���������ȫһ��,���ڽ�һ������ṹת��Ϊ����������
*/
#include<string.h>
#include "BrotherLinkedQueue.h"

/*
/** �����ֵܽ��
typedef struct cbNode{
    ElementType data;
    struct cbNode * firstChild;  //���ӽ��
    struct cbNode * nextSibling; //�ֵܽ��
}CBNode,*CBTree;
*/
/** ��ʼ������(����Ϊ����ָ��)*/
void InitCBTree(CBTree * tree);

/** ������*/
void CreateCBTree(CBNode ** node);

/** ������� */
void PreOrderCBTree(CBNode * node);

void TestCBTree();

/** ����������-�����˲�������Ĵ��� */
int  GetCBTreeDepth(CBTree tree);

#endif // BROTHER_H_INCLUDED
