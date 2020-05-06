#include "FileTest.h"

/**
 *   ��ӡ������Ŀ¼�ṹ
 *   @param dir ������Ŀ¼�ַ���
 *   @param depth Ҫ��ӡ��Ŀ¼���
 */
void PrintDir(char * dir,int depth){
    DIR * dirPtr;  //Ŀ¼ָ��
    if((dirPtr = opendir(dir))==NULL){
        sprintf(stderr,"�޷���Ŀ¼:<%s>\n", dir);
    }
    struct dirent * dirContent; //Ŀ¼����
    while((dirContent=readdir(dirPtr))!=NULL){
        //�����ļ���Ϊһ���������������
        if(strcmp(dirContent->d_name,".")==0||strcmp(dirContent->d_name,"..")==0){
            continue;
        }
        char fullName[1024];
        sprintf(fullName,"%s\\%s",dir,dirContent->d_name);
        printf("��ǰ�ļ���: %s\n",fullName);
        //������ļ���,��Ҫ��ȡ��Ŀ¼(�ݹ�)
        struct stat statInfo; //��ǰ�ļ���Ŀ¼����Ϣ
         if((stat(fullName,&statInfo))==-1){
            sprintf(stderr,"�޷���ȡ�ļ�<%s>����ϸ��Ϣ!\n",fullName);
        }
        //�̶��÷�
        if((statInfo.st_mode&S_IFMT)==S_IFDIR){
            printf("\t��Ŀ¼!\n");
            PrintDir(fullName,++depth);
        }
        else if((statInfo.st_mode&S_IFMT)==S_IFREG){
            printf("\t��һ���ļ�,��ռ�ռ�:%ld\n",statInfo.st_size);
        }

    }
}
