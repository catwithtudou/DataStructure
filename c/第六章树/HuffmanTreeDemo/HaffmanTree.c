#include "HaffmanTree.h"


/**
 *  构造哈夫曼树
 *  @param node 哈夫曼树的(根)结点
 *  @param length 结点数组的长度
 */
void CreateHaffmanTree(HaffNode * node,int length)
{
    if(length<=1){
        return ;
    }
    SortHaffmanNode(node,length);
    //构建一个以Node数组最后两位结点组成的父结点
    HaffNode parent;
    left[length]=node[length-1];   //排序后,length-1就是权重最小的结点
    right[length]=node[length-2];
    parent.weight=left[length].weight+right[length].weight;
    parent.leftChild=&left[length];
    parent.rightChild=&right[length];
    //parent结点的data不用赋值
    //将倒数第二位替换为Parent结点,数组长度-1,递归创建哈夫曼树
    node[length-2]=parent;
    CreateHaffmanTree(node,length-1);
}

/** 冒泡排序,默认以权值大小降序排量 */
void SortHaffmanNode(HaffNode * node,int length)
{
    HaffNode tempNode;
    for(int i=0;i<length-1;i++)
    for(int j=0;j<length-1-i;j++){
        if(node[j].weight<node[j+1].weight){
            tempNode=node[j];
            node[j]=node[j+1];
            node[j+1]=tempNode;
        }
    }
}

/**
 *编码过程(压缩)
 *@param node 结点数组
 *@param tempCode 编码后的字符数组(KeppCode)
 *@param index 当前操作字符数组下标
 */
void Coding(HaffNode * node,char * tempCode,int index)
{
    if(!node)return;
    //处理叶结点
    if(node->leftChild==NULL||node->rightChild==NULL){
        //将编码复制到编码数组中去
        tempCode[index]='\0';   //{'0','0','\0'};
        strcpy(code[node->data-0],tempCode);
        return;
    }

    //左分支编码为'0',右分支编码为'1'
    tempCode[index]='0';
    Coding(node->leftChild,tempCode,index+1);
    tempCode[index]='1';
    Coding(node->rightChild,tempCode,index+1);
}

/**
 *译码过程(解压)
 *@param flag 0/1标志
 *@param node 结点数组
 */
HaffNode * UnCoding(HaffNode * node,int flag)
{
    if(flag==0){
        return node->leftChild;
    }
    if(flag==1){
        return node->rightChild;
    }
    return NULL;
}
