#ifndef BROTHERTREE_H_INCLUDED
#define BROTHERTREE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: ���ĺ����ֵܱ�ʾ��
 *  Description: �ŵ����ںͶ������Ķ��������ʾ��ȫһ�������ڽ�һ������ṹת��Ϊ����������
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#include "Element.h"

typedef struct cBNode{
    ElementType data;               //������
    struct cBNode * firstChild;     //���ӽ��
    struct cBNode * nextSibling;    //�ֵܽ��
}CBNode, * CBTree;

/** ��ʼ������ */
void InitCBTree(CBTree * tree);

/** ������ */
void CreateCBTree(CBNode ** node);

/** ���������� */
int GetCBTreeDepth(CBTree tree);

/** ������ */
void DestroyCBTree(CBTree * tree);

/** ��������� */
void PreOrderCBTree(CBNode *node);

/** ��������� */
void InOrderCBTree(CBNode *node);

/** ��������� */
void PostOrderCBTree(CBNode *node);

void TestCBTree();
#endif // BROTHERTREE_H_INCLUDED
