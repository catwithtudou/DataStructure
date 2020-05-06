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
    //printf("请输入根结点: ");
    //容易遗漏的点: 根结点需要事先分配内存
    tree.root=(TreeNode *)malloc(sizeof(TreeNode));
    CreateBinaryTree_Test(tree.root);
    printf("\n\n前序遍历结果: \n");
    PreOrderTraverse(tree.root);
    printf("\n\n中序遍历结果: \n");
    InOrderTraverse(tree.root);
    printf("\n\n非递归的中序遍历: \n");
    InOrederTraverse_Re(tree.root);
    printf("\n\n后序遍历结果: \n");
    PostOrderTraverse(tree.root);
    printf("\n\n层次遍历结果: \n");
    ZorderTraverse(tree.root);
    free(tree.root);
}

void TestSeqTree()
{
    SeqTree tree;
    InitSeqTree(tree);
    printf("请输入根结点内容: ");
    CreateSeqTree(tree,0);
    for(int i=0;i<15;i++){
        printf("%d, ",tree[i]);
    }
    printf("\n");
    printf("总结点数: %d\n",GetSeqTreeLength(tree));
    printf("当前深度: %d\n",GetSeqTreeDepth(tree));

}
