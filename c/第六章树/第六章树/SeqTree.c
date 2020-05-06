#include"SeqTree.h"

/** ��ʼ�� */
void InitSeqTree(SeqTree tree)
{
    //���ַ������е�ÿ��Ԫ�ض�����Ϊ���ַ�
    for(int i=0;i<MAX_SIZE;i++){
        tree[i]='\0';
    }
}

/** ������ȫ������,iΪ�����е��±� */
void CreateSeqTree(SeqTree tree,int i)
{
    char ch;
    ch=getchar();
    fflush(stdin);
    if(ch=='^'){
        //����^���ű�ʾ������ǰ��������
        tree[i]='\0';
        return;
    }
    tree[i]=ch;
    //ĳ�����������Ϻ�,����Ҫ���û��������Ӻ��Һ���
    printf("���ӽ��: ");
    CreateSeqTree(tree,2*i+1);//�ݹ�
    printf("�Һ��ӽ��: ");
    CreateSeqTree(tree,2*(i+1));
}

/** ��ȡ���ĸ����Ԫ�� */
char GetSeqTreeRoot(SeqTree tree)
{
    return tree[0];
}

/** ��ȡ���Ľ������*/
int GetSeqTreeLength(SeqTree tree)
{
    int len=0;
    for(int i=0;i<MAX_SIZE;i++){
        if(tree[i]=='\0'){
            continue;
        }
        len++;
    }
    return len;
}


/** ��ȡ�������*/
int GetSeqTreeDepth(SeqTree tree)
{
    int depth=0;
    int len=GetSeqTreeLength(tree);
    while((int)pow(2,depth)-1<len){
        depth++;
    }
    return depth;
}
