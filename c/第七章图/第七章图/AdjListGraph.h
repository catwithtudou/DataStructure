#ifndef ADJLISTGRAPH_H_INCLUDED
#define ADJLISTGRAPH_H_INCLUDED

/**
 *    ������ͼ��ʾ��
 *    �ڽӱ��ʾ��
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** ��/���Ľ��*/
typedef struct node{
    int adjVex;         //�ñ�ָ���������ڽӵ���±�
    struct node * nextEdge; //ָ����һ���ߵ�ָ��
    struct node * nextArc;  //ָ����һ��������ָ��
    ArcType weight;         //Ȩ��
}EdgeNode,ArcNode;

/** ������*/
typedef struct vexNode{
    VerTexType vex;    //����ֵ
    EdgeNode * firstEdge; //ָ���һ���ߵ�ָ��
    ArcNode  * firstArc;  //ָ���һ������ָ��
}VNode,AdjList[MAX_VERTEX];

/** �ڽӱ�ʵ�ֵ�ͼ�ṹ*/
typedef struct adjGraph{
    AdjList vexes;   //��������
    int vexCount;    //��������
    /*union{
        int edgeCount; //ͼ�ı���
        int arcCount;  //ͼ�Ļ���
    };*/
    int edgeCount; //ͼ�ı���
    int arcCount;  //ͼ�Ļ���
    GraphKind kind;//ͼ������
}AdjListGraph;


/** �����ڽӱ��ʾ����������ͼ*/
Status CreateUDG_AdjList(AdjListGraph * G);

/** ���ض���x�ڶ��������е��±�,û���ҵ�����-1*/
int LocateVex_AdjList(AdjListGraph * G,VerTexType vex);

/** �����ڽӱ��ʾ����������ͼ*/
Status CreateDG_AdjList(AdjListGraph * G);

/** �����ڽӱ��ʾ������������*/
Status CreateDN_AdjList(AdjListGraph * G);

/** ������ȱ����ĺ��ĺ��� index-��ǰ�����Ķ���(�ڽӵ�)�±�*/
void DFS_ALG(AdjListGraph G,int index);

/** �����ڽӱ�������������*/
void DFSTraverse_ALG(AdjListGraph G);


void TestAdjListGraph();
#endif // ADJLISTGRAPH_H_INCLUDED
