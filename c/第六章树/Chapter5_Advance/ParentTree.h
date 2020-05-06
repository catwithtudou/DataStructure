#ifndef PARENTTREE_H_INCLUDED
#define PARENTTREE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: ����˫�ױ�ʾ��
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#include "Element.h"
#define MAX_TREE_SIZE 1024

/** ˫�׽�� */
typedef struct Pode{
    ElementType data;               //������
    int parent;                     //˫��λ��(�±�)
}PNode;

/** ˫�ױ�ʾ�������ṹ */
typedef struct {
    PNode node[MAX_TREE_SIZE];      //�������
    int root;                       //����λ��(�±�)
    int length;                     //�����
}PTree;

/** ��ʼ������ */
void InitPTree(PTree * tree);

/** ������ */
void CreatePTree(PTree * tree);

/** Ϊ���ڵ㸳ֵ */
void AssignPTree(PNode * node, int parent, ElementType data);

/** �������Ƿ�Ϊ�� */
int IsPTreeEmpty(PTree tree);

/** ����������� */
int GetPTreeDepth(PTree tree);

/** ������ */
void DestoryPTree(PTree * tree);

/*���������*/
void ZOrderPTree(PTree tree);

/** ���Ժ���  */
void TestPTree();



#endif // PARENTTREE_H_INCLUDED
