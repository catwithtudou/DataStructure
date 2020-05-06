#include "BrotherTree.h"
#include "LinkedQueue.h"

static int id = 0;

/** 初始化空树 */
void InitCBTree(CBTree * tree){
    *tree = (CBTree)malloc(sizeof(CBNode));
    (*tree)->firstChild = NULL;
    (*tree)->nextSibling = NULL;
}

/** 构造树 */
void CreateCBTree(CBNode ** node){
    char inputName[255];
    gets(inputName);
    if(strcmp(inputName, "\0") == 0){
        return;
    }
    if(*node == NULL){
        *node = (CBNode *)malloc(sizeof(CBNode));
        (*node)->firstChild = NULL;
        (*node)->nextSibling = NULL;
    }
    (*node)->data.id = ++id;
    strcpy((*node)->data.name, inputName);
    //printf("输入的结点信息：[%d, %s] \n", (*node)->data.id, (*node)->data.name);
    printf("请输入长子结点：");
    CreateCBTree(&((*node)->firstChild));
    printf("请输入兄弟结点：");
    CreateCBTree(&((*node)->nextSibling));
}

/** 获得树的深度 */
int GetCBTreeDepth(CBTree tree){
    /*使用树的层序遍历计算树的深度*/
    //使用队列记录结点
    LinkedQueue queue;
    InitQueue(&queue);
    enQueue(&queue,tree);//根结点入队

    int zorder = 1;//层号
    printf("\n第%d层：",zorder);
    CBNode* last = tree;
    CBNode* lastchild = tree;
    while(!IsEmpty(&queue)){
        CBNode* node = deQueue(&queue);
        printf("[%s] ",node->data.name);//访问出队的结点

        //先将所有孩子结点加入队列
        CBNode *p = node->firstChild;
        while(p){
            enQueue(&queue,p);
            lastchild = p;
            p = p->nextSibling;
        }
        //所有孩子结点都出队了，并且下一层还有孩子结点，则进入下一层
        if(last == node && !IsEmpty(&queue)){
            zorder++;
            printf("\n第%d层：",zorder);
            last = lastchild;
        }
    }
    return zorder;
}

void PreOrderCBTree(CBNode *node){
    if(node != NULL){
        printf("[%d, %s] ", node->data.id, node->data.name);
        CBNode *p = node->firstChild;
        PreOrderCBTree(p);
        while(p){
            p = p->nextSibling;
            PreOrderCBTree(p);
        }
    }
}
//一般的树没有中序遍历，只有先序和后序遍历
void InOrderCBTree(CBNode *node){}

void PostOrderCBTree(CBNode *node){
    if(node != NULL){
        CBNode *p = node->firstChild;
        PostOrderCBTree(p);
        while(p){
            p = p->nextSibling;
            PostOrderCBTree(p);
        }
        printf("[%d, %s] ", node->data.id, node->data.name);
    }
}

/** 销毁树 */
void DestroyCBTree(CBTree * tree){
    if(*tree != NULL){
        free(*tree);
    }
}

void TestCBTree(){
    CBTree tree;
    InitCBTree(&tree);
    printf("根结点：");
    CreateCBTree(&tree);
    printf("\n");
    printf("深度：%d\n", GetCBTreeDepth(tree));
    printf("\n先序遍历：\n");
    PreOrderCBTree(tree);
    printf("\n中序遍历：\n");
    InOrderCBTree(tree);
    printf("\n后序遍历：\n");
    PostOrderCBTree(tree);

//  测试数据：
//                      A
//               /      |     \
//              B       C      D
//             / \     /|\    / \
//            E   F   G H I  J   K
//根结点：A
//请输入长子结点：B
//请输入长子结点：E
//请输入长子结点：
//请输入兄弟结点：F
//请输入长子结点：
//请输入兄弟结点：
//请输入兄弟结点：C
//请输入长子结点：G
//请输入长子结点：
//请输入兄弟结点：H
//请输入长子结点：
//请输入兄弟结点：I
//请输入长子结点：
//请输入兄弟结点：
//请输入兄弟结点：D
//请输入长子结点：J
//请输入长子结点：
//请输入兄弟结点：K
//请输入长子结点：
//请输入兄弟结点：
//请输入兄弟结点：
//请输入兄弟结点：
//
//
//第1层：[A]
//第2层：[B] [C] [D]
//第3层：[E] [F] [G] [H] [I] [J] [K] 深度：3
//
//先序遍历：
//[1, A] [2, B] [3, E] [4, F] [5, C] [6, G] [7, H] [8, I] [9, D] [10, J] [11, K]
//中序遍历：
//
//后序遍历：
//[3, E] [4, F] [2, B] [6, G] [7, H] [8, I] [5, C] [10, J] [11, K] [9, D] [1, A]

}
