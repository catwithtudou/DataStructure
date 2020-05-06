#include "BinaryTree.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

/** ����ʵ�ֽ��id�������� */
static int id=0;

/** ��ʼ���ն����� */
void InitBinaryTree(BinaryTree * tree)
{
    tree->root=NULL;
    tree->depth=0;
    tree->length=0;
    tree->diameter=0;
}

/** ��������� - �ⲿ��Ҫ���ȶԽ������ڴ� */
int CreateBinaryTree(TreeNode * root)
{
    //�������Ϊ�����˳���������
    if(!root) return 0;
    char inputName[NAME_SIZE];
    gets(inputName);
    //�û�����س���ʾ������ǰ�����Ĵ���
    if(strcmp(inputName,"\0")==0) return 0;
    //������ǰ���
    root->data.id=++id;
    strcpy(root->data.name,inputName);
    //Ϊ�������ҽ����׼�� - Ϊ���ҽ��ָ������ڴ�
    root->left=(TreeNode *)malloc(sizeof(TreeNode));
    root->right=(TreeNode *)malloc(sizeof(TreeNode));
    //�ֱ�ݹ鴴����������������
    printf("����: ");
    if(CreateBinaryTree(root->left)==0){
        //���ٴ�����������Ч������������ڴ�
        free(root->left);
        root->left=NULL;
    }
    printf("�ҽ��: ");
    if(CreateBinaryTree(root->right)==0){
        free(root->right);
        root->right=NULL;
    }
    return 1;
}

/** ģ���û������˳�� */
char * nodeNames[]={"A","B","D","#","#","E","#","#","C","F","#","#","G","#","#"};

/** */
static int nodeNameIndex=0;

/** ���԰�Ĵ������� */
int CreateBinaryTree_Test(TreeNode * root){
        //�������Ϊ�����˳���������
    if(!root) return 0;
    char inputName[NAME_SIZE];
    //gets(inputName);
    strcpy(inputName,nodeNames[nodeNameIndex++]);
    //�û�����س���ʾ������ǰ�����Ĵ���
    if(strcmp(inputName,"#")==0) return 0;
    //������ǰ���
    root->data.id=++id;
    strcpy(root->data.name,inputName);
    //Ϊ�������ҽ����׼�� - Ϊ���ҽ��ָ������ڴ�
    root->left=(TreeNode *)malloc(sizeof(TreeNode));
    root->right=(TreeNode *)malloc(sizeof(TreeNode));
    //�ֱ�ݹ鴴����������������
    //printf("����: ");
    if(CreateBinaryTree_Test(root->left)==0){
        //���ٴ�����������Ч������������ڴ�
        free(root->left);
        root->left=NULL;
    }
    //printf("�ҽ��: ");
    if(CreateBinaryTree_Test(root->right)==0){
        free(root->right);
        root->right=NULL;
    }
    return 1;
}

/** ǰ�����: Ҳ�����ȸ����������������ǰ������;Ҳ���Լ�����-��-��*/
void PreOrderTraverse(TreeNode * node)
{
    //�ȷ��ʸ����,Ȼ�����������,������������
    if(node){
        printf("[%d,%s]-",node->data.id,node->data.name);
        PreOrderTraverse(node->left);
        PreOrderTraverse(node->right);
    }
}

/**�������:Ҳ�����и�������;Ҳ���Լ�����-��-��*/
void InOrderTraverse(TreeNode * node)
{
    if(node){
        InOrderTraverse(node->left);
        printf("[%d,%s]-",node->data.id,node->data.name);
        InOrderTraverse(node->right);
    }
}

/** �ǵݹ鷽ʽ���������*/
void InOrederTraverse_Re(TreeNode * node)
{
    //˼·:
    //������������,���ȷ�������,�������ֿ��Կ���һ�������
    //Ȼ������������ӽ��Ϊ�յĽ��,������ͬ�Ĺ������������
    LinkedStack linkedStack;
    InitLinkedStack(&linkedStack);
    TreeNode * root=node;
    //currNode��������ÿ����ջ�Ľ��ָ��
    TreeNode * currNode=(TreeNode *)malloc(sizeof(TreeNode));
    //����Ҫһ����ʱָ��,����ȷ������ͷŵ����������ڴ�
    TreeNode * tempNode=currNode;

    while(root||IsLinkedStackEmpty(&linkedStack)){
        if(root){
            Push(&linkedStack,root);
            root=root->left;
        }else{
            //�ѵ�
            Pop(&linkedStack,&currNode);
            printf("[%d,%s]-",currNode->data.id,currNode->data.name);
            root=currNode->right;
        }
    }

    free(tempNode);
}

/** �������:Ҳ�������������;Ҳ���Լ�����-��-��*/
void PostOrderTraverse(TreeNode * node)
{
    if(node){
        PostOrderTraverse(node->left);
        PostOrderTraverse(node->right);
        printf("[%d,%s]-",node->data.id,node->data.name);
    }
}

/** ��α���:����Ҫ�ݹ�,����ʱ��Ҫ�õ����� */
void ZorderTraverse(TreeNode * node)
{
    LinkedQueue queue;
    InitLinkedQueue(&queue);
    //��������
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
