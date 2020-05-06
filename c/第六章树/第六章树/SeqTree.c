#include"SeqTree.h"

/** 初始化 */
void InitSeqTree(SeqTree tree)
{
    //将字符数组中的每个元素都设置为空字符
    for(int i=0;i<MAX_SIZE;i++){
        tree[i]='\0';
    }
}

/** 创建完全二叉树,i为数组中的下标 */
void CreateSeqTree(SeqTree tree,int i)
{
    char ch;
    ch=getchar();
    fflush(stdin);
    if(ch=='^'){
        //输入^符号表示结束当前结点的输入
        tree[i]='\0';
        return;
    }
    tree[i]=ch;
    //某个结点输入完毕后,还需要让用户输入左孩子和右孩子
    printf("左孩子结点: ");
    CreateSeqTree(tree,2*i+1);//递归
    printf("右孩子结点: ");
    CreateSeqTree(tree,2*(i+1));
}

/** 获取树的根结点元素 */
char GetSeqTreeRoot(SeqTree tree)
{
    return tree[0];
}

/** 获取树的结点总数*/
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


/** 获取树的深度*/
int GetSeqTreeDepth(SeqTree tree)
{
    int depth=0;
    int len=GetSeqTreeLength(tree);
    while((int)pow(2,depth)-1<len){
        depth++;
    }
    return depth;
}
