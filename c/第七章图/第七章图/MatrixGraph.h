#ifndef MATRIXGRAPH_H_INCLUDED
#define MATRIXGRAPH_H_INCLUDED


/**
 *    第七章图的示例
 *    数组(邻接矩阵)表示法
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** 图的邻接矩阵存储表示*/
typedef struct {
    VerTexType verTexs[MAX_VERTEX];       //顶点数组
    ArcType arcs[MAX_VERTEX][MAX_VERTEX]; //邻接矩阵(权数组)
    int verTexCount;    //图的顶点数
    int arcCount;       //图的边/弧数
    GraphKind kind;     //图的类型
}MatrixGraph;

/** 使用邻接矩阵表示法创建无向图*/
Status CreateUDG(MatrixGraph * G);

/** 返回某个顶点在顶点集合中的下标(0开始),不存在返回-1*/
int locateVex(MatrixGraph * G,VerTexType vex);

/** 使用邻接矩阵表示法创建有向图*/
Status CreateDG(MatrixGraph * G);

/** 使用邻接矩阵表示法创建有向网*/
Status CreateDN(MatrixGraph * G);

/** 邻接矩阵的深度优先搜索*/
void DFSTraverse_AMG(MatrixGraph  G);

/** DFS核心算法,index为深度搜索的某个顶点下标*/
void DFS_AMG(MatrixGraph G,int index);

/** 返回顶点vex所在行中的第一个邻接点下标*/
int FirstAdjVex_AMG(MatrixGraph G,VerTexType vex);

/** 返回与顶点vex1邻接的另一个邻接点(除vex2的下一个邻接点),没有就返回-1*/
int SecondAdjVex_AMG(MatrixGraph G,VerTexType vex1,VerTexType vex2);



void TestMatrixGraph();


#endif // MATRIXGRAPH_H_INCLUDED
