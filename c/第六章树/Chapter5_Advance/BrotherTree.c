#include "BrotherTree.h"
#include "LinkedQueue.h"

static int id = 0;

/** ��ʼ������ */
void InitCBTree(CBTree * tree){
    *tree = (CBTree)malloc(sizeof(CBNode));
    (*tree)->firstChild = NULL;
    (*tree)->nextSibling = NULL;
}

/** ������ */
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
    //printf("����Ľ����Ϣ��[%d, %s] \n", (*node)->data.id, (*node)->data.name);
    printf("�����볤�ӽ�㣺");
    CreateCBTree(&((*node)->firstChild));
    printf("�������ֵܽ�㣺");
    CreateCBTree(&((*node)->nextSibling));
}

/** ���������� */
int GetCBTreeDepth(CBTree tree){
    /*ʹ�����Ĳ�����������������*/
    //ʹ�ö��м�¼���
    LinkedQueue queue;
    InitQueue(&queue);
    enQueue(&queue,tree);//��������

    int zorder = 1;//���
    printf("\n��%d�㣺",zorder);
    CBNode* last = tree;
    CBNode* lastchild = tree;
    while(!IsEmpty(&queue)){
        CBNode* node = deQueue(&queue);
        printf("[%s] ",node->data.name);//���ʳ��ӵĽ��

        //�Ƚ����к��ӽ��������
        CBNode *p = node->firstChild;
        while(p){
            enQueue(&queue,p);
            lastchild = p;
            p = p->nextSibling;
        }
        //���к��ӽ�㶼�����ˣ�������һ�㻹�к��ӽ�㣬�������һ��
        if(last == node && !IsEmpty(&queue)){
            zorder++;
            printf("\n��%d�㣺",zorder);
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
//һ�����û�����������ֻ������ͺ������
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

/** ������ */
void DestroyCBTree(CBTree * tree){
    if(*tree != NULL){
        free(*tree);
    }
}

void TestCBTree(){
    CBTree tree;
    InitCBTree(&tree);
    printf("����㣺");
    CreateCBTree(&tree);
    printf("\n");
    printf("��ȣ�%d\n", GetCBTreeDepth(tree));
    printf("\n���������\n");
    PreOrderCBTree(tree);
    printf("\n���������\n");
    InOrderCBTree(tree);
    printf("\n���������\n");
    PostOrderCBTree(tree);

//  �������ݣ�
//                      A
//               /      |     \
//              B       C      D
//             / \     /|\    / \
//            E   F   G H I  J   K
//����㣺A
//�����볤�ӽ�㣺B
//�����볤�ӽ�㣺E
//�����볤�ӽ�㣺
//�������ֵܽ�㣺F
//�����볤�ӽ�㣺
//�������ֵܽ�㣺
//�������ֵܽ�㣺C
//�����볤�ӽ�㣺G
//�����볤�ӽ�㣺
//�������ֵܽ�㣺H
//�����볤�ӽ�㣺
//�������ֵܽ�㣺I
//�����볤�ӽ�㣺
//�������ֵܽ�㣺
//�������ֵܽ�㣺D
//�����볤�ӽ�㣺J
//�����볤�ӽ�㣺
//�������ֵܽ�㣺K
//�����볤�ӽ�㣺
//�������ֵܽ�㣺
//�������ֵܽ�㣺
//�������ֵܽ�㣺
//
//
//��1�㣺[A]
//��2�㣺[B] [C] [D]
//��3�㣺[E] [F] [G] [H] [I] [J] [K] ��ȣ�3
//
//���������
//[1, A] [2, B] [3, E] [4, F] [5, C] [6, G] [7, H] [8, I] [9, D] [10, J] [11, K]
//���������
//
//���������
//[3, E] [4, F] [2, B] [6, G] [7, H] [8, I] [5, C] [10, J] [11, K] [9, D] [1, A]

}
