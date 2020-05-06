#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

/**
*    第六章树的示例
*    二叉链表的实现
*/

#include "TreeNode.h"
#include <string.h>

/** 二叉链表 */
typedef struct {
    TreeNode * root;     //二叉链的根结点
    int length;          //二叉链表结点的总数
    int depth;           //二叉链表的深度
    int diameter;        //直径 - 从叶结点到叶结点的最长路径(某些考试会涉及)
}BinaryTree;

/** 初始化空二叉树 */
void InitBinaryTree(BinaryTree * tree);

/** 构造二叉树 - 外部需要事先对结点分配内存(返回0表示创建失败) */
int CreateBinaryTree(TreeNode * root);

/** 前序遍历: 也叫做先根遍历、先序遍历、前序周游;也可以记做根-左-右*/
void PreOrderTraverse(TreeNode * node);

/** 测试版的创建函数 */
int CreateBinaryTree_Test(TreeNode * root);

/**中序遍历:也叫做中根遍历等;也可以记做左-根-右*/
void InOrderTraverse(TreeNode * node);

/** 非递归方式的中序遍历*/
void InOrederTraverse_Re(TreeNode * node);

/** 后序遍历:也叫做后根遍历等;也可以记做左-右-根*/
void PostOrderTraverse(TreeNode * node);

/** 层次遍历:不需要递归,遍历时需要用到队列 */
void ZorderTraverse(TreeNode * node);
#endif // BINARYTREE_H_INCLUDED
