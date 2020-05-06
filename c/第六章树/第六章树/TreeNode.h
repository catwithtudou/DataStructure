#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

/**
*    第六章树的示例
*    树结点
*/

#include"ElementType.h"

/** 树结点*/
typedef struct treeNode{
    ElementType data; //树结点的数据域
    struct treeNode * left;   //左子树
    struct treeNode * right;  //右子树
}TreeNode;

#endif // TREENODE_H_INCLUDED
