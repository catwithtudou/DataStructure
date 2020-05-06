#include "MatrixGraph.h"

/** ʹ���ڽӾ����ʾ����������ͼ*/
/**
  *   ����ͼ���ص�
  *   1.����ͼ���ڽӾ����ǶԳ�
  *   2.����i�Ķ�=��i��(��)��1�ĸ���
  */
Status CreateUDG(MatrixGraph * G)
{
    G->kind=UDG;  //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("����������ͼ�Ķ�����: ");
    scanf("%d",&G->verTexCount);
    printf("������ߵ�����: ");
    scanf("%d",&G->arcCount);
    printf("�������붥����Ϣ\n");
    for(int i=0;i<G->verTexCount;i++){
        G->verTexs[i]=(VerTexType)malloc(sizeof(char)*10);
        printf("����%d: ",i);
        scanf("%s",G->verTexs[i]);
    }
    //��ʼ���ڽӾ���,���бߵ�Ȩֵ����Ϊ0
    for(int i=0;i<G->verTexCount;i++){
        for(int j=0;j<G->verTexCount;j++){
            G->arcs[i][j]=0;
        }
    }
    printf("�����붥����ڽӶ�����Ϣ,�����ڽӾ���\n");
    for(int i=0;i<G->arcCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("����: ");
        scanf("%s",vex1);
        printf("�ڽӵ�: ");
        scanf("%s",vex2);
        //�ֱ������������ڶ��������е�����
        int x=locateVex(G,vex1);
        int y=locateVex(G,vex2);
        if(x==-1||y==-1){
            return  ERROR;
        }
        G->arcs[x][y]=1;
        G->arcs[y][x]=1;

        free(vex1);
        free(vex2);
    }
    return OK;
}


/** ����ĳ�������ڶ��㼯���е��±�(0��ʼ),�����ڷ���-1*/
int locateVex(MatrixGraph * G,VerTexType vex)
{
    int index=0;
    while(index<G->verTexCount){
        if(strcmp(G->verTexs[index],vex)==0){
            break;
        }
        index++;
    }
    return index==G->verTexCount ? -1:index;
}


/** ʹ���ڽӾ����ʾ����������ͼ*/
/**
 *   ����ͼ���ص�:
 *   1.����ͼ���ڽӾ����п��ܲ��ǶԳƵ�
 *   2.����ĳ���=��i��Ԫ��֮��;��������=��i��Ԫ��֮��
 *   3.����Ķ�=��i��Ԫ��֮��+��i��Ԫ��֮��
 */
Status CreateDG(MatrixGraph * G)
{
    G->kind=DG;  //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("����������ͼ�Ķ�����: ");
    scanf("%d",&G->verTexCount);
    printf("������ߵ�����: ");
    scanf("%d",&G->arcCount);
    printf("�������붥����Ϣ\n");
    for(int i=0;i<G->verTexCount;i++){
        G->verTexs[i]=(VerTexType)malloc(sizeof(char)*10);
        printf("����%d: ",i);
        scanf("%s",G->verTexs[i]);
    }
    //��ʼ���ڽӾ���,���бߵ�Ȩֵ����Ϊ0
    for(int i=0;i<G->verTexCount;i++){
        for(int j=0;j<G->verTexCount;j++){
            G->arcs[i][j]=0;
        }
    }
    printf("�����붥����ڽӶ�����Ϣ,�����ڽӾ���\n");
    for(int i=0;i<G->arcCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("����: ");
        scanf("%s",vex1);
        printf("�ڽӵ�: ");
        scanf("%s",vex2);
        //�ֱ������������ڶ��������е�����
        int x=locateVex(G,vex1);
        int y=locateVex(G,vex2);
        if(x==-1||y==-1){
            return  ERROR;
        }
        G->arcs[x][y]=1;   // ����ͼ���ڽӾ����п��ܲ��Գ�
        //G->arcs[y][x]=1;

        free(vex1);
        free(vex2);
    }
    return OK;
}

/** ʹ���ڽӾ����ʾ������������*/
Status CreateDN(MatrixGraph * G)
{
        G->kind=DN;  //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("�������������Ķ�����: ");
    scanf("%d",&G->verTexCount);
    printf("������ߵ�����: ");
    scanf("%d",&G->arcCount);
    printf("�������붥����Ϣ\n");
    for(int i=0;i<G->verTexCount;i++){
        G->verTexs[i]=(VerTexType)malloc(sizeof(char)*10);
        printf("����%d: ",i);
        scanf("%s",G->verTexs[i]);
    }
    //��ʼ���ڽӾ���,���бߵ�Ȩֵ����Ϊ�����
    for(int i=0;i<G->verTexCount;i++){
        for(int j=0;j<G->verTexCount;j++){
            G->arcs[i][j]=INT_MAX;
        }
    }
    printf("�����붥����ڽӶ�����Ϣ,�����ڽӾ���\n");
    for(int i=0;i<G->arcCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("����: ");
        scanf("%s",vex1);
        printf("�ڽӵ�: ");
        scanf("%s",vex2);
        //�ֱ������������ڶ��������е�����
        int x=locateVex(G,vex1);
        int y=locateVex(G,vex2);
        if(x==-1||y==-1){
            return  ERROR;
        }
        int value;
        printf("������Ȩֵ: ");
        scanf("%d",&value);
        G->arcs[x][y]=value;   // ����ͼ���ڽӾ����п��ܲ��Գ�
        //G->arcs[y][x]=1;
        free(vex1);
        free(vex2);
    }
    return OK;
}


/** �ڽӾ���������������*/
void DFSTraverse_AMG(MatrixGraph  G)
{
    //��ʼ��״̬����
    for(int i=0;i<G.verTexCount;i++){
        visited[i]=UNVISITED; //��ʼ״̬����Ϊδ����
    }
    //DFS����
    for(int i=0;i<G.verTexCount;i++){
        if(!visited[i]){
            //���ĳ������δ����
            //���ñ�������
            DFS_AMG(G,i);
        }
    }
}

/** DFS�����㷨,indexΪ���������ĳ�������±�*/
void DFS_AMG(MatrixGraph G,int index)
{
    printf(" -> %s",G.verTexs[index]);   //���ʵ�ǰ����
    visited[index]=VISITED;              //���ĵ�ǰ����ķ���״̬
    for(int i=FirstAdjVex_AMG(G,G.verTexs[index]);i
    ;i=SecondAdjVex_AMG(G,G.verTexs[index],G.verTexs[i])){
        if(!visited[i]){
            DFS_AMG(G,i);   //���û�з��ʹ�������ݹ��������
        }
    }
}


/** ���ض���vex�������еĵ�һ���ڽӵ��±�*/
int FirstAdjVex_AMG(MatrixGraph G,VerTexType vex)
{
    int i=locateVex(&G,vex);   //�ҵ�����vex�ڶ��������е��±�
    if(i==-1)return ERROR;
    int defaultWeight;         //Ĭ��Ȩ��
    defaultWeight= G.kind<=1 ? 0 : INT_MAX;  //ͼ/��
    for(int j=0;j<G.verTexCount;j++){
        //����ͼ���ڽӾ������붥��vex�ĵ�һ���ڽӵ��±�
        if(G.arcs[i][j]!=defaultWeight){
            return j;
        }
    }
    return 0;
}

/** �����붥��vex1�ڽӵ���һ���ڽӵ�(��vex2����һ���ڽӵ�),û�оͷ���-1*/
int SecondAdjVex_AMG(MatrixGraph G,VerTexType vex1,VerTexType vex2)
{
    int index1=locateVex(&G,vex1);
    int index2=locateVex(&G,vex2);
    if(index1==-1||index2==-1)return -1;
    int defaultWeight;
    defaultWeight=G.kind<=1 ? 0 :INT_MAX;
    for(int i= index2+1;i<G.verTexCount;i++){
        if(G.arcs[index1][i] != defaultWeight){
            return i;
        }
    }
    return 0;
}

void TestMatrixGraph()
{
    MatrixGraph G;
    //��������ͼ
   //Status status=CreateUDG(&G);
    //��������ͼ
   //Status status=CreateDG(&G);
    //����������
    Status status=CreateDN(&G);
    if(status==ERROR){
        printf("����ͼʧ��,���������! \n");
        return;
    }
    printf("��ӡͼ���ڽӾ���: \n");
    printf("\t");
    for(int i=0;i<G.verTexCount;i++){
        printf("\t%s",G.verTexs[i]);
    }
    printf("\n");
    for(int i=0;i<G.verTexCount;i++){
        printf("\t%s",G.verTexs[i]);
        for(int j=0;j<G.verTexCount;j++){
            if(G.arcs[i][j]==INT_MAX){
                printf("\t��");
            }else{
            printf("\t%d",G.arcs[i][j]);
            }
        }
        printf("\n");
    }
    printf("������ȱ���:\n");
    DFSTraverse_AMG(G);
}
