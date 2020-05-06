#ifndef SEQTREE_H_INCLUDED
#define SEQTREE_H_INCLUDED

/**
*        第六章树的示例
*        树的顺序存储结构-一般只用于完全二叉树,这样可以避免内存浪费
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/** 一维数组能够存放的最大结点数 */
#define MAX_SIZE 1024

/** 定义顺序树类型 */
typedef char SeqTree[MAX_SIZE];

/** 初始化空二叉树 */
void InitSeqTree(SeqTree tree);

/** 创建完全二叉树,i为数组中的下标 */
void CreateSeqTree(SeqTree tree,int i);

/** 获取树的根结点元素 */
char GetSeqTreeRoot(SeqTree tree);

/** 获取树的结点总数*/
int GetSeqTreeLength(SeqTree tree);

/** 获取树的深度*/
int  GetSeqTreeDepth(SeqTree tree);

#endif // SEQTREE_H_INCLUDED
