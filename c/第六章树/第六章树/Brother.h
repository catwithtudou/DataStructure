#ifndef BROTHER_H_INCLUDED
#define BROTHER_H_INCLUDED

/**
*    第六章树的示例
*    树的孩子兄弟表示法.优点在于和二叉树的二叉链表完全一样,便于将一般的树结构转换为二叉树处理
*/
#include<string.h>
#include "BrotherLinkedQueue.h"

/*
/** 孩子兄弟结点
typedef struct cbNode{
    ElementType data;
    struct cbNode * firstChild;  //长子结点
    struct cbNode * nextSibling; //兄弟结点
}CBNode,*CBTree;
*/
/** 初始化空树(参数为二级指针)*/
void InitCBTree(CBTree * tree);

/** 构造树*/
void CreateCBTree(CBNode ** node);

/** 先序遍历 */
void PreOrderCBTree(CBNode * node);

void TestCBTree();

/** 获得数的深度-利用了层序遍历的代码 */
int  GetCBTreeDepth(CBTree tree);

#endif // BROTHER_H_INCLUDED
