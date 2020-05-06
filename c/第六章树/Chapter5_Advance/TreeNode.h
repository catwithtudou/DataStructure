#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: 树结点
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#include "Element.h"

/** 树结点 */
typedef struct treeNode{
    ElementType data;           //树结点的数据域
    struct treeNode * left;     //左子树
    struct treeNode * right;    //右子树
}TreeNode;
#endif // TREENODE_H_INCLUDED
