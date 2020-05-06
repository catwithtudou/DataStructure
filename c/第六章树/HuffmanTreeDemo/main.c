#include <stdio.h>
#include <stdlib.h>
#include "HaffmanTree.h"
int main()
{
    unsigned char saveChar=0;    //保存到二进制文件的无符号字符
    unsigned char tempChar;

    printf("使用哈夫曼树实现文本文件的压缩:(暂时只支持英文文件)");
    FILE * inputFile=fopen("input.txt","r"); //待解码文件
    FILE * zipedFile=fopen("ziped.txt","wb");//编码压缩后的文件

    int fileLength = 0;  //文件中存放的字符个数
    int asciiCount[ASCII_SIZE]={0}; //存放0-127个字符出现的次数-权数组
    //读取待编码文件,统计各字符出现的次数
    char readChar;
    while((readChar=fgetc(inputFile))!=EOF){
        //逐字符读取字符
        fileLength++;
        //读取到的字符就作为asciiCOunt数组的下标
        asciiCount[readChar-0]++;  //asciiCount[(int)readChar]++;

    }
    int num=0;    //结点数量(计数器)
    for(int i=0;i<ASCII_SIZE;i++){
        if(asciiCount[i]!=0){
            node[num].data=i;
            node[num].weight=asciiCount[i];
            num++;
        }
    }
    //创建哈夫曼树
    CreateHaffmanTree(node,num);
    //进行哈夫曼编码
    char tempCode[HALF_MAX];
    Coding(node,tempCode,0);

    //逐位将编码保存到文件zipedFile文件
    num=0;
    fseek(inputFile,0L,0); //文件指针复位
    int zipedLength=0;     //压缩后的字符数量
    while((readChar=fgetc(inputFile))!=EOF){
        //遍历读取到的这个字符编码("10","111","1101",....)
        for(int i=0;i<strlen(code[(int)readChar]);i++){
            //'1'-'0'->00110001-001100010=0000 0001
            //当编码为'1'时,通过或操作将其添加到字节的最低位
            //00000001 00000011
            saveChar |=code[(int)readChar][i]-'0';
            num++;
            if(num==8){
                //每8位写入一次文件
                fwrite(&saveChar,sizeof(unsigned char),1,zipedFile);
                zipedLength++;
                num=0;
                saveChar=0;
            }else{
                saveChar <<=1;  //saveChar-saveChar<<1; 11->110

            }
        }
    }
    //如果最后剩余的编码不足8位,就移动到最左端凑够8位
    if(num<8){
        saveChar=saveChar<<(8-num);
        fwrite(&saveChar,sizeof(unsigned char),1,zipedFile);
        saveChar=0;
    }
    fclose(inputFile);
    fclose(zipedFile);
    printf("压缩成功:压缩前字符个数:%d\t压缩后字符个数:%d\n",fileLength,zipedLength);
    printf("压缩比:%.2f%%\n",(double)zipedLength/(double)fileLength * 100);

    printf("\n使用哈夫曼树实现解压缩:\n");   //读取压缩后的文件
    zipedFile=fopen("ziped.txt","rb");
    FILE * resultFile=fopen("result.txt","w");   //解压缩后的文件
    num=0;  //计数器清零
    HaffNode * currNode=&node[0];
    while(fread(&readChar,sizeof(unsigned char),1,zipedFile)){
        if(fileLength==num){
            break;
        }
        //遍历readChar中的每个二进制数字
        for(int i=0;i<8;i++){
            tempChar=readChar&128;  //取readChar的最高位(128即10000000)
            tempChar>>=7;           //tempChar右移7位
            readChar<<=1;           //最高位已经被取,所以左移1位
            currNode=UnCoding(currNode,tempChar-0);
            //判断叶结点
            if(currNode->leftChild==NULL||currNode->rightChild==NULL){
                fprintf(resultFile,"%c",currNode->data);
                num++;
                currNode=&node[0];  //每找到一个叶结点,当前节点就重置,指向根结点
            }
        }
    }
    fclose(inputFile);
    fclose(zipedFile);
    printf("解压缩完成,请查看文件:result.txt\n");

    return 0;
}
