#include "BinaryTree.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

/** 用来实现结点id的自增长 */
static int id=0;

/** 初始化空二叉树 */
void InitBinaryTree(BinaryTree * tree)
{
    tree->root=NULL;
    tree->depth=0;
    tree->length=0;
    tree->diameter=0;
}

/** 构造二叉树 - 外部需要事先对结点分配内存 */
int CreateBinaryTree(TreeNode * root)
{
    //根结点若为空则退出创建过程
    if(!root) return 0;
    char inputName[NAME_SIZE];
    gets(inputName);
    //用户输入回车表示结束当前子树的创建
    if(strcmp(inputName,"\0")==0) return 0;
    //创建当前结点
    root->data.id=++id;
    strcpy(root->data.name,inputName);
    //为输入左右结点做准备 - 为左右结点指针分配内存
    root->left=(TreeNode *)malloc(sizeof(TreeNode));
    root->right=(TreeNode *)malloc(sizeof(TreeNode));
    //分别递归创建左子树和右子树
    printf("左结点: ");
    if(CreateBinaryTree(root->left)==0){
        //不再创建这个结点则效果结点更分配的内存
        free(root->left);
        root->left=NULL;
    }
    printf("右结点: ");
    if(CreateBinaryTree(root->right)==0){
        free(root->right);
        root->right=NULL;
    }
    return 1;
}

/** 模仿用户输入的顺序 */
char * nodeNames[]={"A","B","D","#","#","E","#","#","C","F","#","#","G","#","#"};

/** */
static int nodeNameIndex=0;

/** 测试版的创建函数 */
int CreateBinaryTree_Test(TreeNode * root){
        //根结点若为空则退出创建过程
    if(!root) return 0;
    char inputName[NAME_SIZE];
    //gets(inputName);
    strcpy(inputName,nodeNames[nodeNameIndex++]);
    //用户输入回车表示结束当前子树的创建
    if(strcmp(inputName,"#")==0) return 0;
    //创建当前结点
    root->data.id=++id;
    strcpy(root->data.name,inputName);
    //为输入左右结点做准备 - 为左右结点指针分配内存
    root->left=(TreeNode *)malloc(sizeof(TreeNode));
    root->right=(TreeNode *)malloc(sizeof(TreeNode));
    //分别递归创建左子树和右子树
    //printf("左结点: ");
    if(CreateBinaryTree_Test(root->left)==0){
        //不再创建这个结点则效果结点更分配的内存
        free(root->left);
        root->left=NULL;
    }
    //printf("右结点: ");
    if(CreateBinaryTree_Test(root->right)==0){
        free(root->right);
        root->right=NULL;
    }
    return 1;
}

/** 前序遍历: 也叫做先根遍历、先序遍历、前序周游;也可以记做根-左-右*/
void PreOrderTraverse(TreeNode * node)
{
    //先访问根结点,然后遍历左子树,最后遍历右子树
    if(node){
        printf("[%d,%s]-",node->data.id,node->data.name);
        PreOrderTraverse(node->left);
        PreOrderTraverse(node->right);
    }
}

/**中序遍历:也叫做中根遍历等;也可以记做左-根-右*/
void InOrderTraverse(TreeNode * node)
{
    if(node){
        InOrderTraverse(node->left);
        printf("[%d,%s]-",node->data.id,node->data.name);
        InOrderTraverse(node->right);
    }
}

/** 非递归方式的中序遍历*/
void InOrederTraverse_Re(TreeNode * node)
{
    //思路:
    //对任意结点来讲,优先访问左孩子,而左孩子又可以看做一个根结点
    //然后继续访问左孩子结点为空的结点,按照相同的规则访问右子树
    LinkedStack linkedStack;
    InitLinkedStack(&linkedStack);
    TreeNode * root=node;
    //currNode用来保存每个出栈的结点指针
    TreeNode * currNode=(TreeNode *)malloc(sizeof(TreeNode));
    //还需要一个临时指针,用来确保最后释放掉上面分配的内存
    TreeNode * tempNode=currNode;

    while(root||IsLinkedStackEmpty(&linkedStack)){
        if(root){
            Push(&linkedStack,root);
            root=root->left;
        }else{
            //难点
            Pop(&linkedStack,&currNode);
            printf("[%d,%s]-",currNode->data.id,currNode->data.name);
            root=currNode->right;
        }
    }

    free(tempNode);
}

/** 后序遍历:也叫做后根遍历等;也可以记做左-右-根*/
void PostOrderTraverse(TreeNode * node)
{
    if(node){
        PostOrderTraverse(node->left);
        PostOrderTraverse(node->right);
        printf("[%d,%s]-",node->data.id,node->data.name);
    }
}

/** 层次遍历:不需要递归,遍历时需要用到队列 */
void ZorderTraverse(TreeNode * node)
{
    LinkedQueue queue;
    InitLinkedQueue(&queue);
    //根结点入队
    InQueue(&queue,node);
    while(!IsLinkedQueue(&queue)){
        TreeNode * node=OutQueue(&queue);
        printf("[%d,%s]-",node->data.id,node->data.name);
        if(node->left!=NULL){
            InQueue(&queue,node->left);
        }
        if(node->right!=NULL){
            InQueue(&queue,node->right);
        }
    }
}
