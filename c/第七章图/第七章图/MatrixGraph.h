#ifndef MATRIXGRAPH_H_INCLUDED
#define MATRIXGRAPH_H_INCLUDED


/**
 *    ������ͼ��ʾ��
 *    ����(�ڽӾ���)��ʾ��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** ͼ���ڽӾ���洢��ʾ*/
typedef struct {
    VerTexType verTexs[MAX_VERTEX];       //��������
    ArcType arcs[MAX_VERTEX][MAX_VERTEX]; //�ڽӾ���(Ȩ����)
    int verTexCount;    //ͼ�Ķ�����
    int arcCount;       //ͼ�ı�/����
    GraphKind kind;     //ͼ������
}MatrixGraph;

/** ʹ���ڽӾ����ʾ����������ͼ*/
Status CreateUDG(MatrixGraph * G);

/** ����ĳ�������ڶ��㼯���е��±�(0��ʼ),�����ڷ���-1*/
int locateVex(MatrixGraph * G,VerTexType vex);

/** ʹ���ڽӾ����ʾ����������ͼ*/
Status CreateDG(MatrixGraph * G);

/** ʹ���ڽӾ����ʾ������������*/
Status CreateDN(MatrixGraph * G);

/** �ڽӾ���������������*/
void DFSTraverse_AMG(MatrixGraph  G);

/** DFS�����㷨,indexΪ���������ĳ�������±�*/
void DFS_AMG(MatrixGraph G,int index);

/** ���ض���vex�������еĵ�һ���ڽӵ��±�*/
int FirstAdjVex_AMG(MatrixGraph G,VerTexType vex);

/** �����붥��vex1�ڽӵ���һ���ڽӵ�(��vex2����һ���ڽӵ�),û�оͷ���-1*/
int SecondAdjVex_AMG(MatrixGraph G,VerTexType vex1,VerTexType vex2);



void TestMatrixGraph();


#endif // MATRIXGRAPH_H_INCLUDED
