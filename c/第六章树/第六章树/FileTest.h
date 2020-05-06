#ifndef FILETEST_H_INCLUDED
#define FILETEST_H_INCLUDED
/**
*      ����������ʾ��
*      �ļ�Ŀ¼����ʾ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/fcntl.h>


typedef enum fileType{
    TYPE_FIFE,           //�ļ�����
    TYPE_FOLDER         //�ļ�������
}FileType;


/** �ļ���� */
typedef struct fileNode{
    char fileName[1024];   //�ļ�|Ŀ¼��,����׺
    struct fileNode * firstChild;
    struct fileNode * nextSibling;
    struct FileNode * parent;
}FileNode,* FileTree;

/**
 *   ��ӡ������Ŀ¼�ṹ
 *   @param dir ������Ŀ¼�ַ���
 *   @param depth Ҫ��ӡ��Ŀ¼���
 */
void PrintDir(char * dir,int depth);

#endif // FILETEST_H_INCLUDED
