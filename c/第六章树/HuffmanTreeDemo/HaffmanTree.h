#ifndef HAFFMANTREE_H_INCLUDED
#define HAFFMANTREE_H_INCLUDED

/**
 *         Huffman树的顺序存储
 *         哈夫曼编码压缩文件的主要思路:
 *         1.读取某个文本文件,统计文件中哥哥字符出现的次数作为权重
 *         2.构建哈夫曼树,生成每个字符对应的编码,然后将编码保存到压缩文件中
 *         3.文件解压缩实际就是将压缩文件翻译过来再保存到解压缩文件的过程
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define HALF_MAX 128
#define ASCII_SIZE 128   //ascii码的数量:0-127

/** 哈夫曼树结点 */
typedef struct haffNode{
    char data;        //用来存放结点字符的数据域
    int weight;       //权重
    struct haffNode * leftChild;
    struct haffNode * rightChild;
}HaffNode;

/** 以顺序结构存储的树结点-编码解码的字符映射表*/
HaffNode node[MAX_SIZE];

/** 用来保存所有左孩子结点的数组*/
HaffNode left[HALF_MAX];

/** 用来保存所有右孩子结点的数组*/
HaffNode right[HALF_MAX];

/** 使用二维数组来存储某个字符的哈夫曼编码,其中第一维的下标就是这个字符的ASCII码*/
char code[MAX_SIZE][HALF_MAX];

/**
 *  构造哈夫曼树
 *  @param node   结点数组
 *  @param length 结点数组的长度
 */
void CreateHaffmanTree(HaffNode * node,int length);

/** 冒泡排序,默认以权值大小降序排量 */
void SortHaffmanNode(HaffNode * node,int length);

/**
 *编码过程(压缩)
 *@param node 结点数组
 *@param tempCode 编码后的字符数组(KeppCode)
 *@param index 当前操作字符数组下标
 */
void Coding(HaffNode * node,char * tempCode,int index);

/**
 *译码过程(解压)
 *@param flag 0/1标志
 *@param node 结点数组
 */
HaffNode * UnCoding(HaffNode * node,int flag);

#endif // HAFFMANTREE_H_INCLUDED
