#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

/**
*    ����������ʾ��
*    �����
*/

#include"ElementType.h"

/** �����*/
typedef struct treeNode{
    ElementType data; //������������
    struct treeNode * left;   //������
    struct treeNode * right;  //������
}TreeNode;

#endif // TREENODE_H_INCLUDED
