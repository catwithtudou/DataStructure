#ifndef BROTHERTREE_H_INCLUDED
#define BROTHERTREE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: 树的孩子兄弟表示法
 *  Description: 优点在于和二叉树的二叉链表表示完全一样，便于将一般的树结构转换为二叉树处理
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#include "Element.h"

typedef struct cBNode{
    ElementType data;               //数据域
    struct cBNode * firstChild;     //长子结点
    struct cBNode * nextSibling;    //兄弟结点
}CBNode, * CBTree;

/** 初始化空树 */
void InitCBTree(CBTree * tree);

/** 构造树 */
void CreateCBTree(CBNode ** node);

/** 获得树的深度 */
int GetCBTreeDepth(CBTree tree);

/** 销毁树 */
void DestroyCBTree(CBTree * tree);

/** 先序遍历树 */
void PreOrderCBTree(CBNode *node);

/** 中序遍历树 */
void InOrderCBTree(CBNode *node);

/** 后序遍历树 */
void PostOrderCBTree(CBNode *node);

void TestCBTree();
#endif // BROTHERTREE_H_INCLUDED
