#ifndef GRAPHMODEL_H_INCLUDED
#define GRAPHMODEL_H_INCLUDED

/**
 *    第七章图的示例
 *    图的数据模型
 */

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
#define INT_MAX 999
#define VISITED 1
#define UNVISITED 0

/** 图的类型枚举*/
typedef enum{
    DG,   //有向图
    UDG,  //无向图
    DN,   //有向网
    UDN   //无向网
}GraphKind;

/** 设置顶点的数据类型为字符串型-使用时记得分配内存*/
typedef char * VerTexType;

/** 设置权值类型为整型*/
typedef int ArcType;

/**  返回的状态类型*/
typedef int Status;

/** 保存每个顶点的访问状态 0-未访问;1-访问*/
int visited[MAX_VERTEX];


#endif // GRAPHMODEL_H_INCLUDED
