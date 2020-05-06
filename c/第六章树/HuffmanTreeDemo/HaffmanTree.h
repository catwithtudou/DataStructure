#ifndef HAFFMANTREE_H_INCLUDED
#define HAFFMANTREE_H_INCLUDED

/**
 *         Huffman����˳��洢
 *         ����������ѹ���ļ�����Ҫ˼·:
 *         1.��ȡĳ���ı��ļ�,ͳ���ļ��и���ַ����ֵĴ�����ΪȨ��
 *         2.������������,����ÿ���ַ���Ӧ�ı���,Ȼ�󽫱��뱣�浽ѹ���ļ���
 *         3.�ļ���ѹ��ʵ�ʾ��ǽ�ѹ���ļ���������ٱ��浽��ѹ���ļ��Ĺ���
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define HALF_MAX 128
#define ASCII_SIZE 128   //ascii�������:0-127

/** ����������� */
typedef struct haffNode{
    char data;        //������Ž���ַ���������
    int weight;       //Ȩ��
    struct haffNode * leftChild;
    struct haffNode * rightChild;
}HaffNode;

/** ��˳��ṹ�洢�������-���������ַ�ӳ���*/
HaffNode node[MAX_SIZE];

/** ���������������ӽ�������*/
HaffNode left[HALF_MAX];

/** �������������Һ��ӽ�������*/
HaffNode right[HALF_MAX];

/** ʹ�ö�ά�������洢ĳ���ַ��Ĺ���������,���е�һά���±��������ַ���ASCII��*/
char code[MAX_SIZE][HALF_MAX];

/**
 *  �����������
 *  @param node   �������
 *  @param length �������ĳ���
 */
void CreateHaffmanTree(HaffNode * node,int length);

/** ð������,Ĭ����Ȩֵ��С�������� */
void SortHaffmanNode(HaffNode * node,int length);

/**
 *�������(ѹ��)
 *@param node �������
 *@param tempCode �������ַ�����(KeppCode)
 *@param index ��ǰ�����ַ������±�
 */
void Coding(HaffNode * node,char * tempCode,int index);

/**
 *�������(��ѹ)
 *@param flag 0/1��־
 *@param node �������
 */
HaffNode * UnCoding(HaffNode * node,int flag);

#endif // HAFFMANTREE_H_INCLUDED
