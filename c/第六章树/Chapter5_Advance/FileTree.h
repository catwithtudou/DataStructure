#ifndef FILETREE_H_INCLUDED
#define FILETREE_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: 孩子兄弟表示法的实际应用-读取文件目录树
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "LinkedQueue.h"
#include "LinkedStack.h"

/** 文件/目录类型 */
typedef enum fileType{
    TYPE_FILE,      //文件类型
    TYPE_FOLDER     //文件夹类型
}FileType;

/** 文件结点 */
typedef struct fileNode{
    char fileName[1024];            //文件/目录名，含后缀
    FileType type;                  //文件或目录的类型
    struct fileNode * firstChild;   //长子结点
    struct fileNode * nextSibling ; //兄弟结点
    struct fileNode * parent;       //双亲结点
}FileNode, * FileTree;

/** 为文件树结点分配内存空间（结点工厂函数） */
FileNode * FileNodeFactory();

/**
 * 将文件目录树读入内存（创建文件树）
 * @param path
 * @param rootNode
 * @param preNode
 * @param currNode
 * @param depth
 */
void ReverseCatalogueToTree(char * path, FileNode * rootNode, FileNode * preNode, FileNode * currNode, int depth);

/** 层序遍历文件树 */
void ZOrderTraverse(FileTree tree);

/** 访问某个结点 */
void Visit(FileTree tree,FileNode* node,char (*content)[1000],int *j);

/** 在文件中保存树结构信息 */
void SaveTreeStructure(FileTree tree);

void PrintDir(char * dir, int depth);

void TestFileTree();






#endif // FILETREE_H_INCLUDED
