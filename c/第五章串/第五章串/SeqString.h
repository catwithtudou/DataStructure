#ifndef SEQSTRING_H_INCLUDED
#define SEQSTRING_H_INCLUDED

/**
*      �����´�
*      ����˳��ṹʵ��
*/

#include "StatusLib.h"
#include <string.h>

#define MAX_SIZE 255
/*
typedef struct{
    char ch[MAX_SIZE+1];   //������ʽʵ���ַ�����˳��洢�ṹ-ȱ������˷ѿռ�
    int length;
}SString;
*/

/**���Ķ�ʽ˳��洢�ṹ(Heap) */
typedef struct{
    char * ch;    //����Ƿǿմ�,��ô�Ͱ���ָ�����ȷ����ڴ�,����chָ��Null
    int length;   //����ǰ����
}HString;


/**��ʼ�����ַ���*/
void InitString_HeapString(HString * str);


/**��ӡ���ַ���*/
void PrintHeapString(HString * str);

/**Ϊ��str��ֵ,ֵΪ�ַ�������chars*/
Status StrAssign_HeapString(HString * str,char * chars);

/**�Ƚ��������ַ����Ĵ�С:str1==str2 ����0 : < -1 : > 1*/
Status StrCompare_HeapString(HString * str1,HString * str2);

/**���������ַ���,���ӵĽ���Դ�destStr����*/
Status Concat_HeapString(HString * destStr,HString * str1,HString * str2);

/**��posλ�ô���ȡlen���ȵ��ַ�������destStr*/
Status SubString_HeapString(HString *destStr,HString * str,int pos, int length);

/** ���ش�Posλ�ÿ�ʼ���Ӵ�child�ڸ���parent�е�λ��*/
int Index_HeapString(HString * parent,HString * child,int pos);

/**��Posλ�ô�ɾ������len*/
Status Delete_HeapString(HString * str,int pos,int len);

/**��ָ����λ�ò��봮insertStr */
Status Insert_HeapString(HString * insertStr,HString * str,int pos);

/**����str�е�oldStr�滻��newStr*/
Status Replace_HeapString(HString * str,HString old,HString newStr);

/**��ն��ַ���*/
Status ClearString_HeapString(HString * str);

/**Ϊ��srcStr�е����ݸ��Ƶ���destStr��*/
Status StrCopy_HeapString(HString *destStr,HString * srcStr);

Status IsEmpty_HeapString(HString * str);

/**BF�㷨*/
int BFCompare(HString * parent,HString * child,int pos);

/**����Next����(����ƥ���)*/
void Get_Next(HString  child,int * next);

/**KMP�㷨*/
int KMPCompare(HString * parent,HString * child,int pos);

#endif // SEQSTRING_H_INCLUDED
