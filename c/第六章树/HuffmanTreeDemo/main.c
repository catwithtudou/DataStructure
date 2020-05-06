#include <stdio.h>
#include <stdlib.h>
#include "HaffmanTree.h"
int main()
{
    unsigned char saveChar=0;    //���浽�������ļ����޷����ַ�
    unsigned char tempChar;

    printf("ʹ�ù�������ʵ���ı��ļ���ѹ��:(��ʱֻ֧��Ӣ���ļ�)");
    FILE * inputFile=fopen("input.txt","r"); //�������ļ�
    FILE * zipedFile=fopen("ziped.txt","wb");//����ѹ������ļ�

    int fileLength = 0;  //�ļ��д�ŵ��ַ�����
    int asciiCount[ASCII_SIZE]={0}; //���0-127���ַ����ֵĴ���-Ȩ����
    //��ȡ�������ļ�,ͳ�Ƹ��ַ����ֵĴ���
    char readChar;
    while((readChar=fgetc(inputFile))!=EOF){
        //���ַ���ȡ�ַ�
        fileLength++;
        //��ȡ�����ַ�����ΪasciiCOunt������±�
        asciiCount[readChar-0]++;  //asciiCount[(int)readChar]++;

    }
    int num=0;    //�������(������)
    for(int i=0;i<ASCII_SIZE;i++){
        if(asciiCount[i]!=0){
            node[num].data=i;
            node[num].weight=asciiCount[i];
            num++;
        }
    }
    //������������
    CreateHaffmanTree(node,num);
    //���й���������
    char tempCode[HALF_MAX];
    Coding(node,tempCode,0);

    //��λ�����뱣�浽�ļ�zipedFile�ļ�
    num=0;
    fseek(inputFile,0L,0); //�ļ�ָ�븴λ
    int zipedLength=0;     //ѹ������ַ�����
    while((readChar=fgetc(inputFile))!=EOF){
        //������ȡ��������ַ�����("10","111","1101",....)
        for(int i=0;i<strlen(code[(int)readChar]);i++){
            //'1'-'0'->00110001-001100010=0000 0001
            //������Ϊ'1'ʱ,ͨ�������������ӵ��ֽڵ����λ
            //00000001 00000011
            saveChar |=code[(int)readChar][i]-'0';
            num++;
            if(num==8){
                //ÿ8λд��һ���ļ�
                fwrite(&saveChar,sizeof(unsigned char),1,zipedFile);
                zipedLength++;
                num=0;
                saveChar=0;
            }else{
                saveChar <<=1;  //saveChar-saveChar<<1; 11->110

            }
        }
    }
    //������ʣ��ı��벻��8λ,���ƶ�������˴չ�8λ
    if(num<8){
        saveChar=saveChar<<(8-num);
        fwrite(&saveChar,sizeof(unsigned char),1,zipedFile);
        saveChar=0;
    }
    fclose(inputFile);
    fclose(zipedFile);
    printf("ѹ���ɹ�:ѹ��ǰ�ַ�����:%d\tѹ�����ַ�����:%d\n",fileLength,zipedLength);
    printf("ѹ����:%.2f%%\n",(double)zipedLength/(double)fileLength * 100);

    printf("\nʹ�ù�������ʵ�ֽ�ѹ��:\n");   //��ȡѹ������ļ�
    zipedFile=fopen("ziped.txt","rb");
    FILE * resultFile=fopen("result.txt","w");   //��ѹ������ļ�
    num=0;  //����������
    HaffNode * currNode=&node[0];
    while(fread(&readChar,sizeof(unsigned char),1,zipedFile)){
        if(fileLength==num){
            break;
        }
        //����readChar�е�ÿ������������
        for(int i=0;i<8;i++){
            tempChar=readChar&128;  //ȡreadChar�����λ(128��10000000)
            tempChar>>=7;           //tempChar����7λ
            readChar<<=1;           //���λ�Ѿ���ȡ,��������1λ
            currNode=UnCoding(currNode,tempChar-0);
            //�ж�Ҷ���
            if(currNode->leftChild==NULL||currNode->rightChild==NULL){
                fprintf(resultFile,"%c",currNode->data);
                num++;
                currNode=&node[0];  //ÿ�ҵ�һ��Ҷ���,��ǰ�ڵ������,ָ������
            }
        }
    }
    fclose(inputFile);
    fclose(zipedFile);
    printf("��ѹ�����,��鿴�ļ�:result.txt\n");

    return 0;
}
