#include "HaffmanTree.h"


/**
 *  �����������
 *  @param node ����������(��)���
 *  @param length �������ĳ���
 */
void CreateHaffmanTree(HaffNode * node,int length)
{
    if(length<=1){
        return ;
    }
    SortHaffmanNode(node,length);
    //����һ����Node���������λ�����ɵĸ����
    HaffNode parent;
    left[length]=node[length-1];   //�����,length-1����Ȩ����С�Ľ��
    right[length]=node[length-2];
    parent.weight=left[length].weight+right[length].weight;
    parent.leftChild=&left[length];
    parent.rightChild=&right[length];
    //parent����data���ø�ֵ
    //�������ڶ�λ�滻ΪParent���,���鳤��-1,�ݹ鴴����������
    node[length-2]=parent;
    CreateHaffmanTree(node,length-1);
}

/** ð������,Ĭ����Ȩֵ��С�������� */
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
 *�������(ѹ��)
 *@param node �������
 *@param tempCode �������ַ�����(KeppCode)
 *@param index ��ǰ�����ַ������±�
 */
void Coding(HaffNode * node,char * tempCode,int index)
{
    if(!node)return;
    //����Ҷ���
    if(node->leftChild==NULL||node->rightChild==NULL){
        //�����븴�Ƶ�����������ȥ
        tempCode[index]='\0';   //{'0','0','\0'};
        strcpy(code[node->data-0],tempCode);
        return;
    }

    //���֧����Ϊ'0',�ҷ�֧����Ϊ'1'
    tempCode[index]='0';
    Coding(node->leftChild,tempCode,index+1);
    tempCode[index]='1';
    Coding(node->rightChild,tempCode,index+1);
}

/**
 *�������(��ѹ)
 *@param flag 0/1��־
 *@param node �������
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
