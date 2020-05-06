#ifndef FILETEST_H_INCLUDED
#define FILETEST_H_INCLUDED
/**
*      第六章树的示例
*      文件目录操作示例
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/fcntl.h>


typedef enum fileType{
    TYPE_FIFE,           //文件类型
    TYPE_FOLDER         //文件夹类型
}FileType;


/** 文件结点 */
typedef struct fileNode{
    char fileName[1024];   //文件|目录名,含后缀
    struct fileNode * firstChild;
    struct fileNode * nextSibling;
    struct FileNode * parent;
}FileNode,* FileTree;

/**
 *   打印给定的目录结构
 *   @param dir 给定的目录字符串
 *   @param depth 要打印的目录深度
 */
void PrintDir(char * dir,int depth);

#endif // FILETEST_H_INCLUDED
