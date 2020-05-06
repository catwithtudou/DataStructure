#ifndef PARENTTREE_H_INCLUDED
#define PARENTTREE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: 树的双亲表示法
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#include "Element.h"
#define MAX_TREE_SIZE 1024

/** 双亲结点 */
typedef struct Pode{
    ElementType data;               //数据域
    int parent;                     //双亲位置(下标)
}PNode;

/** 双亲表示法的树结构 */
typedef struct {
    PNode node[MAX_TREE_SIZE];      //结点数组
    int root;                       //根的位置(下标)
    int length;                     //结点数
}PTree;

/** 初始化空树 */
void InitPTree(PTree * tree);

/** 构造树 */
void CreatePTree(PTree * tree);

/** 为树节点赋值 */
void AssignPTree(PNode * node, int parent, ElementType data);

/** 返回树是否为空 */
int IsPTreeEmpty(PTree tree);

/** 返回树的深度 */
int GetPTreeDepth(PTree tree);

/** 销毁树 */
void DestoryPTree(PTree * tree);

/*层序遍历树*/
void ZOrderPTree(PTree tree);

/** 测试函数  */
void TestPTree();



#endif // PARENTTREE_H_INCLUDED
