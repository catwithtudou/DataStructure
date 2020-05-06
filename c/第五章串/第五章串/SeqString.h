#ifndef SEQSTRING_H_INCLUDED
#define SEQSTRING_H_INCLUDED

/**
*      第五章串
*      串的顺序结构实现
*/

#include "StatusLib.h"
#include <string.h>

#define MAX_SIZE 255
/*
typedef struct{
    char ch[MAX_SIZE+1];   //定长方式实现字符串的顺序存储结构-缺点就是浪费空间
    int length;
}SString;
*/

/**串的堆式顺序存储结构(Heap) */
typedef struct{
    char * ch;    //如果是非空串,那么就按照指定长度分配内存,否则ch指向Null
    int length;   //串当前长度
}HString;


/**初始化堆字符串*/
void InitString_HeapString(HString * str);


/**打印堆字符串*/
void PrintHeapString(HString * str);

/**为串str赋值,值为字符串常量chars*/
Status StrAssign_HeapString(HString * str,char * chars);

/**比较两个堆字符串的大小:str1==str2 返回0 : < -1 : > 1*/
Status StrCompare_HeapString(HString * str1,HString * str2);

/**连接两个字符串,连接的结果以串destStr返回*/
Status Concat_HeapString(HString * destStr,HString * str1,HString * str2);

/**在pos位置处截取len长度的字符串到串destStr*/
Status SubString_HeapString(HString *destStr,HString * str,int pos, int length);

/** 返回从Pos位置开始的子串child在父串parent中的位置*/
int Index_HeapString(HString * parent,HString * child,int pos);

/**从Pos位置处删除长度len*/
Status Delete_HeapString(HString * str,int pos,int len);

/**向指定的位置插入串insertStr */
Status Insert_HeapString(HString * insertStr,HString * str,int pos);

/**将串str中的oldStr替换成newStr*/
Status Replace_HeapString(HString * str,HString old,HString newStr);

/**清空堆字符串*/
Status ClearString_HeapString(HString * str);

/**为串srcStr中的内容复制到串destStr中*/
Status StrCopy_HeapString(HString *destStr,HString * srcStr);

Status IsEmpty_HeapString(HString * str);

/**BF算法*/
int BFCompare(HString * parent,HString * child,int pos);

/**返回Next数组(部分匹配表)*/
void Get_Next(HString  child,int * next);

/**KMP算法*/
int KMPCompare(HString * parent,HString * child,int pos);

#endif // SEQSTRING_H_INCLUDED
