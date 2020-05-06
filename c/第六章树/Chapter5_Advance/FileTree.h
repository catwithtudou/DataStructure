#ifndef FILETREE_H_INCLUDED
#define FILETREE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: �����ֵܱ�ʾ����ʵ��Ӧ��-��ȡ�ļ�Ŀ¼��
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "LinkedQueue.h"
#include "LinkedStack.h"

/** �ļ�/Ŀ¼���� */
typedef enum fileType{
    TYPE_FILE,      //�ļ�����
    TYPE_FOLDER     //�ļ�������
}FileType;

/** �ļ���� */
typedef struct fileNode{
    char fileName[1024];            //�ļ�/Ŀ¼��������׺
    FileType type;                  //�ļ���Ŀ¼������
    struct fileNode * firstChild;   //���ӽ��
    struct fileNode * nextSibling ; //�ֵܽ��
    struct fileNode * parent;       //˫�׽��
}FileNode, * FileTree;

/** Ϊ�ļ����������ڴ�ռ䣨��㹤�������� */
FileNode * FileNodeFactory();

/**
 * ���ļ�Ŀ¼�������ڴ棨�����ļ�����
 * @param path
 * @param rootNode
 * @param preNode
 * @param currNode
 * @param depth
 */
void ReverseCatalogueToTree(char * path, FileNode * rootNode, FileNode * preNode, FileNode * currNode, int depth);

/** ��������ļ��� */
void ZOrderTraverse(FileTree tree);

/** ����ĳ����� */
void Visit(FileTree tree,FileNode* node,char (*content)[1000],int *j);

/** ���ļ��б������ṹ��Ϣ */
void SaveTreeStructure(FileTree tree);

void PrintDir(char * dir, int depth);

void TestFileTree();






#endif // FILETREE_H_INCLUDED
