#ifndef ADJLISTGRAPH_H_INCLUDED
#define ADJLISTGRAPH_H_INCLUDED

/**
 *    第七章图的示例
 *    邻接表表示法
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** 边/弧的结点*/
typedef struct node{
    int adjVex;         //该边指向这条边邻接点的下标
    struct node * nextEdge; //指向下一条边的指针
    struct node * nextArc;  //指向下一个弧结点的指针
    ArcType weight;         //权重
}EdgeNode,ArcNode;

/** 顶点结点*/
typedef struct vexNode{
    VerTexType vex;    //顶点值
    EdgeNode * firstEdge; //指向第一条边的指针
    ArcNode  * firstArc;  //指向第一条弧的指针
}VNode,AdjList[MAX_VERTEX];

/** 邻接表实现的图结构*/
typedef struct adjGraph{
    AdjList vexes;   //顶点数组
    int vexCount;    //顶点数量
    /*union{
        int edgeCount; //图的边数
        int arcCount;  //图的弧数
    };*/
    int edgeCount; //图的边数
    int arcCount;  //图的弧数
    GraphKind kind;//图的类型
}AdjListGraph;


/** 采用邻接表表示法创建无向图*/
Status CreateUDG_AdjList(AdjListGraph * G);

/** 返回顶点x在顶点数组中的下标,没有找到返回-1*/
int LocateVex_AdjList(AdjListGraph * G,VerTexType vex);

/** 采用邻接表表示法创建有向图*/
Status CreateDG_AdjList(AdjListGraph * G);

/** 采用邻接表表示法创建有向网*/
Status CreateDN_AdjList(AdjListGraph * G);

/** 深度优先遍历的核心函数 index-当前遍历的顶点(邻接点)下标*/
void DFS_ALG(AdjListGraph G,int index);

/** 基于邻接表的深度优先搜索*/
void DFSTraverse_ALG(AdjListGraph G);


void TestAdjListGraph();
#endif // ADJLISTGRAPH_H_INCLUDED
