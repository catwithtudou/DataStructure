#ifndef SEQTREE_H_INCLUDED
#define SEQTREE_H_INCLUDED

/**
*        ����������ʾ��
*        ����˳��洢�ṹ-һ��ֻ������ȫ������,�������Ա����ڴ��˷�
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/** һά�����ܹ���ŵ�������� */
#define MAX_SIZE 1024

/** ����˳�������� */
typedef char SeqTree[MAX_SIZE];

/** ��ʼ���ն����� */
void InitSeqTree(SeqTree tree);

/** ������ȫ������,iΪ�����е��±� */
void CreateSeqTree(SeqTree tree,int i);

/** ��ȡ���ĸ����Ԫ�� */
char GetSeqTreeRoot(SeqTree tree);

/** ��ȡ���Ľ������*/
int GetSeqTreeLength(SeqTree tree);

/** ��ȡ�������*/
int  GetSeqTreeDepth(SeqTree tree);

#endif // SEQTREE_H_INCLUDED
