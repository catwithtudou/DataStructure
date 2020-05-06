#include"Brother.h"

/** ��ʼ������(����Ϊ����ָ��)*/
void InitCBTree(CBTree * tree)
{
    *tree=(CBTree *)malloc(sizeof(CBTree));
    (*tree)->firstChild=NULL;
    (*tree)->nextSibling=NULL;
}

static int id=0;

/** ������*/
void CreateCBTree(CBNode ** node)
{
    char inputName[255];
    gets(inputName);
    //�ж��û�������Ƿ�س���
    if(strcmp(inputName,"\0")==0)return ;
    if(*node==NULL){
        *node=(CBNode *)malloc(sizeof(CBNode));
        (*node)->firstChild=NULL;
        (*node)->nextSibling=NULL;
    }
    //Ϊ��㸳ֵ
    (*node)->data.id=++id;
    strcpy((*node)->data.name,inputName);
    //�ֱ�������볤�ӽ����ֵܽ��
    printf("�����볤�ӽ��: ");
    CreateCBTree(&(*node)->firstChild);
    printf("�������ֵܽ��: ");
    CreateCBTree(&(*node)->nextSibling);

}

/** ������� */
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
    printf("�����: ");
    CreateCBTree(&tree);
    printf("�������: \n");
    PreOrderCBTree(tree);
    printf("�������: \n");
    printf("\n���:%d\n",GetCBTreeDepth(tree));
}

/** ����������-�����˲�������Ĵ��� */
int  GetCBTreeDepth(CBTree tree)
{
    //ʹ�����Ĳ�����������������
    LinkedQueue1 queue; //������¼���Ķ���
    InitLinkedQueue1(&queue);
    InQueue1(&queue,tree); //��������

    int zorder=1;   //���
    printf("\n��%d��: ",zorder);
    CBNode * last=tree;   //ÿ�ֱ���ʱ�����һ�����
    CBNode * lastchild=tree; //ÿ�ֱ���ʱ���һ���ӽ��
    while(!IsLinkedQueue1(&queue)){
        CBNode * node=OutQueue1(&queue); //����
        printf("[%d,%s] ",node->data.id,node->data.name);
        //����ǰ���ӽ����ӽ�����,�ȴ����Ӵ�ӡ
        CBNode * tempNode=node->firstChild;//�õ����ӽ��
        while(tempNode){
            InQueue1(&queue,tempNode);  //�ӽ�����
            lastchild=tempNode;
            tempNode=tempNode->nextSibling;
        }
        //���к��ӽ�㶼������,������һ�㻹�к��ӽ��,�ͽ�����һ��
        if(last==node && !IsLinkedQueue1(&queue)){
            zorder++;
            printf("\n��%d��: ",zorder);
            last=lastchild;
        }
    }
    return zorder;
}

