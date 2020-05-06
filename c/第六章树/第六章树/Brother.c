#include"Brother.h"

/** 初始化空树(参数为二级指针)*/
void InitCBTree(CBTree * tree)
{
    *tree=(CBTree *)malloc(sizeof(CBTree));
    (*tree)->firstChild=NULL;
    (*tree)->nextSibling=NULL;
}

static int id=0;

/** 构造树*/
void CreateCBTree(CBNode ** node)
{
    char inputName[255];
    gets(inputName);
    //判断用户输入的是否回车键
    if(strcmp(inputName,"\0")==0)return ;
    if(*node==NULL){
        *node=(CBNode *)malloc(sizeof(CBNode));
        (*node)->firstChild=NULL;
        (*node)->nextSibling=NULL;
    }
    //为结点赋值
    (*node)->data.id=++id;
    strcpy((*node)->data.name,inputName);
    //分别遍历输入长子结点和兄弟结点
    printf("请输入长子结点: ");
    CreateCBTree(&(*node)->firstChild);
    printf("请输入兄弟结点: ");
    CreateCBTree(&(*node)->nextSibling);

}

/** 先序遍历 */
void PreOrderCBTree(CBNode * node)
{
    if(node!=NULL){
        printf("[%d,%s] ",node->data.id,node->data.name);
        CBNode * p =node->firstChild;
        PreOrderCBTree(p);
        while(p){
            p=p->nextSibling;
            PreOrderCBTree(p);
        }
    }
}

void TestCBTree(){
    CBTree tree;
    InitCBTree(&tree);
    printf("根结点: ");
    CreateCBTree(&tree);
    printf("先序遍历: \n");
    PreOrderCBTree(tree);
    printf("层序遍历: \n");
    printf("\n深度:%d\n",GetCBTreeDepth(tree));
}

/** 获得数的深度-利用了层序遍历的代码 */
int  GetCBTreeDepth(CBTree tree)
{
    //使用树的层序遍历计算树的深度
    LinkedQueue1 queue; //用来记录结点的队列
    InitLinkedQueue1(&queue);
    InQueue1(&queue,tree); //根结点入队

    int zorder=1;   //层号
    printf("\n第%d层: ",zorder);
    CBNode * last=tree;   //每轮遍历时的最后一个结点
    CBNode * lastchild=tree; //每轮遍历时最后一个子结点
    while(!IsLinkedQueue1(&queue)){
        CBNode * node=OutQueue1(&queue); //出队
        printf("[%d,%s] ",node->data.id,node->data.name);
        //将当前出队结点的子结点入队,等待出队打印
        CBNode * tempNode=node->firstChild;//拿到长子结点
        while(tempNode){
            InQueue1(&queue,tempNode);  //子结点入队
            lastchild=tempNode;
            tempNode=tempNode->nextSibling;
        }
        //所有孩子结点都出队了,并且下一层还有孩子结点,就进入下一层
        if(last==node && !IsLinkedQueue1(&queue)){
            zorder++;
            printf("\n第%d层: ",zorder);
            last=lastchild;
        }
    }
    return zorder;
}

