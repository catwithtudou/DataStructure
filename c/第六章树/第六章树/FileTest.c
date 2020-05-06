#include "FileTest.h"

/**
 *   打印给定的目录结构
 *   @param dir 给定的目录字符串
 *   @param depth 要打印的目录深度
 */
void PrintDir(char * dir,int depth){
    DIR * dirPtr;  //目录指针
    if((dirPtr = opendir(dir))==NULL){
        sprintf(stderr,"无法打开目录:<%s>\n", dir);
    }
    struct dirent * dirContent; //目录内容
    while((dirContent=readdir(dirPtr))!=NULL){
        //跳过文件名为一个点和两个点的情况
        if(strcmp(dirContent->d_name,".")==0||strcmp(dirContent->d_name,"..")==0){
            continue;
        }
        char fullName[1024];
        sprintf(fullName,"%s\\%s",dir,dirContent->d_name);
        printf("当前文件名: %s\n",fullName);
        //如果是文件夹,需要读取子目录(递归)
        struct stat statInfo; //当前文件或目录的信息
         if((stat(fullName,&statInfo))==-1){
            sprintf(stderr,"无法获取文件<%s>的详细信息!\n",fullName);
        }
        //固定用法
        if((statInfo.st_mode&S_IFMT)==S_IFDIR){
            printf("\t是目录!\n");
            PrintDir(fullName,++depth);
        }
        else if((statInfo.st_mode&S_IFMT)==S_IFREG){
            printf("\t是一般文件,所占空间:%ld\n",statInfo.st_size);
        }

    }
}
