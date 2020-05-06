#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: �����
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#include "Element.h"

/** ����� */
typedef struct treeNode{
    ElementType data;           //������������
    struct treeNode * left;     //������
    struct treeNode * right;    //������
}TreeNode;
#endif // TREENODE_H_INCLUDED
