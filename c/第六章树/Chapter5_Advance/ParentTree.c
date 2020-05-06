#include "ParentTree.h"

/** ��ʼ������ */
void InitPTree(PTree * tree){
    tree->root = -1;
    tree->length = 0;
}

/** ������ */
void DestoryPTree(PTree * tree){
    if(tree){
        free(tree);
    }
}

/** ������ */
void CreatePTree(PTree * tree){
    printf("�������������");
    scanf("%d", &(tree->length));
    printf("���������ֵ��˫����ţ�\n");

    tree->root = 0;
    for(int i = tree->root; i < tree->length; i++){
        ElementType * elem = (ElementType *)malloc(sizeof(ElementType));
        int parentPos;
        elem->id = i + 1;
        printf("�������%d������ֵ��", i + 1);
        scanf("%s", elem->name);
        tree->node[i].data = *elem;
        printf("�������%d������˫��λ�ã�", i + 1);
        //scanf("%d", &tree->node[i].parent);
        scanf("%d", &parentPos);
        //Ϊ��㸳ֵ
        AssignPTree(&(tree->node[i]), parentPos, *elem);
    }
    tree->node[tree->root].parent = -1;         //�����˫������Ϊ-1
    printf("�����ɹ���%d\n", tree->length);
    for(int i = 0; i < tree->length; i++){
        printf("[%d, %s, %d] ", tree->node[i].data.id, tree->node[i].data.name, tree->node[i].parent);
    }
}

/** Ϊ���ڵ㸳ֵ */
void AssignPTree(PNode * node, int parent, ElementType data){
    node->data = data;
    node->parent = parent;
}

/** �������Ƿ�Ϊ�� */
int IsPTreeEmpty(PTree tree){
    return tree.length == 0;
}

/** ����������� */
int GetPTreeDepth(PTree tree){
    if(IsPTreeEmpty(tree) == 1) return 0;
    int max = 0;    //������
    //˼·��������㼯�ϣ���¼ÿ��������ȣ�ȡ��������е�������
    for(int i = tree.root; i < tree.length; i++){
        int height = 1; //�Ӹ���㿪ʼ���߶�����Ϊ1
        int node = tree.node[i].parent;
        while(node != -1){//node��Ϊ�����ʱ��������
            node = tree.node[node].parent;  //ͨ��˫�׵�λ���ҵ�˫�׽�㣬����¼��˫��
            height++;   //ÿ�α����߶�+1
        }
        if(max < height){
            max = height;
        }
    }
    return max;
}

/*���������*/
void ZOrderPTree(PTree tree){
    int level = 1;
    printf("��%d�㣺", level);
    printf("[%d, %s] ", tree.node[tree.root].data.id, tree.node[tree.root].data.name);
    level++;
    int depth = GetPTreeDepth(tree);
    //����������Ժ��ÿ�����
    printf("\n��%d�㣺", level);
    for(int i = 0; i < tree.length; i++){
        //���ҵ�i���������к��ӽ��(ע�⣺�洢˳��Ҫ��˫��λ��һ���ں���ǰ��)
        int flag = 0;       //���б�ʶ
        for(int j = i + 1; j < tree.length; j++){
            if(tree.node[j].parent == i){//˫��λ��==i�����ҵ�λ��i���ĺ��ӽ��
                printf("[%d, %s] ", tree.node[j].data.id, tree.node[j].data.name);
                flag = 1;
            }
        }
        if(flag == 1 && level < depth){
            level++;
            printf("\n��%d�㣺", level);
        }
    }
}

/** ���Ժ���  */
void TestPTree(){
    PTree tree;
    InitPTree(&tree);
//  ��������˳��
//�������������7
//���������ֵ��˫����ţ�
//�������1������ֵ��A
//�������1������˫��λ�ã�-1
//�������2������ֵ��B
//�������2������˫��λ�ã�0
//�������3������ֵ��C
//�������3������˫��λ�ã�0
//�������4������ֵ��D
//�������4������˫��λ�ã�1
//�������5������ֵ��E
//�������5������˫��λ�ã�1
//�������6������ֵ��F
//�������6������˫��λ�ã�2
//�������7������ֵ��G
//�������7������˫��λ�ã�2
//[1, A, -1] [2, B, 0] [3, C, 0] [4, D, 1] [5, E, 1] [6, F, 2] [7, G, 2]
//���������
//��1�㣺[1, A]
//��2�㣺[2, B] [3, C]
//��3�㣺[4, D] [5, E] [6, F] [7, G]
    CreatePTree(&tree);
    printf("��ȣ�%d\n", GetPTreeDepth(tree));
    printf("���������\n");
    ZOrderPTree(tree);
}
