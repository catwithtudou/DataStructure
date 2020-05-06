#include <stdio.h>
#include <stdlib.h>
#include "SeqTree.h"
#include "BinaryTree.h"
#include "Brother.h"
void TestSeqTree();

void TestBinaryTree();
int main()
{
    printf("Hello world!\n");
    //TestSeqTree();
    //TestBinaryTree();
    //TestCBTree();
    PrintDir("F:\\Test",0);
    return 0;
}

void TestBinaryTree()
{
    BinaryTree tree;
    InitBinaryTree(&tree);
    //printf("����������: ");
    //������©�ĵ�: �������Ҫ���ȷ����ڴ�
    tree.root=(TreeNode *)malloc(sizeof(TreeNode));
    CreateBinaryTree_Test(tree.root);
    printf("\n\nǰ��������: \n");
    PreOrderTraverse(tree.root);
    printf("\n\n����������: \n");
    InOrderTraverse(tree.root);
    printf("\n\n�ǵݹ���������: \n");
    InOrederTraverse_Re(tree.root);
    printf("\n\n����������: \n");
    PostOrderTraverse(tree.root);
    printf("\n\n��α������: \n");
    ZorderTraverse(tree.root);
    free(tree.root);
}

void TestSeqTree()
{
    SeqTree tree;
    InitSeqTree(tree);
    printf("��������������: ");
    CreateSeqTree(tree,0);
    for(int i=0;i<15;i++){
        printf("%d, ",tree[i]);
    }
    printf("\n");
    printf("�ܽ����: %d\n",GetSeqTreeLength(tree));
    printf("��ǰ���: %d\n",GetSeqTreeDepth(tree));

}
