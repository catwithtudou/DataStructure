#include "AdjListGraph.h"

/** �����ڽӱ��ʾ����������ͼ*/
Status CreateUDG_AdjList(AdjListGraph * G)
{
    G->kind=UDG;
    printf("�����붥������: ");
    scanf("%d",&G->vexCount);
    printf("������ߵ�����: ");
    scanf("%d",&G->edgeCount);
    printf("���������붥����Ϣ\n");
    for(int i=0;i<G->vexCount;i++){
        G->vexes[i].vex=(VerTexType)malloc(sizeof(char)*10);
        printf("����%d: ",i);
        scanf("%s",G->vexes[i].vex);
        //��ʼ���ڽӱ�,�ѱ��ÿ�
        G->vexes[i].firstEdge=NULL;
    }
    printf("�����붥����ڽӵ���Ϣ,�����ڽӱ�\n");
    for(int i=0;i<G->edgeCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("����: ");
        scanf("%s",vex1);
        printf("�ڽӵ�: ");
        scanf("%s",vex2);
        int x=LocateVex_AdjList(G,vex1);
        int y=LocateVex_AdjList(G,vex2);
        if(x==-1||y==-1){
            free(vex1);
            free(vex2);
            return  ERROR;
        }
        EdgeNode * edgeNode=(EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex=x;
        edgeNode->nextEdge=G->vexes[y].firstEdge;
        edgeNode->weight=0;
        G->vexes[y].firstEdge=edgeNode;
        edgeNode=(EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex=y;
        edgeNode->nextEdge=G->vexes[x].firstEdge;
        edgeNode->weight=0;
        G->vexes[x].firstEdge=edgeNode;
        free(vex1);
        free(vex2);
    }
    return OK;
}

/** �����ڽӱ��ʾ����������ͼ*/
Status CreateDG_AdjList(AdjListGraph * G)
{
    G->kind=DG;
    printf("�����붥������: ");
    scanf("%d",&G->vexCount);
    printf("������ߵ�����: ");
    scanf("%d",&G->edgeCount);
    printf("���������붥����Ϣ\n");
    for(int i=0;i<G->vexCount;i++){
        G->vexes[i].vex=(VerTexType)malloc(sizeof(char)*10);
        printf("����%d: ",i);
        scanf("%s",G->vexes[i].vex);
        //��ʼ���ڽӱ�,�ѱ��ÿ�
        G->vexes[i].firstArc=NULL;   //��firstArc��Ϊ����ָ��
        G->vexes[i].firstEdge=NULL;  //��firstEdge��Ϊ���ָ��
    }
    printf("�����붥����ڽӵ���Ϣ,�����ڽӱ�\n");
    for(int i=0;i<G->edgeCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("����: ");
        scanf("%s",vex1);
        printf("�ڽӵ�: ");
        scanf("%s",vex2);
        int x=LocateVex_AdjList(G,vex1);
        int y=LocateVex_AdjList(G,vex2);
        if(x==-1||y==-1){
            free(vex1);
            free(vex2);
            return  ERROR;
        }
        //���ɱ߽����ڽӱ�(����)
        ArcNode * arcNode=(ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjVex=y;
        arcNode->nextArc=G->vexes[x].firstArc;
        G->vexes[x].firstArc=arcNode;
        arcNode->weight=0;
        //���ɱ߽����ڽӱ�(���)
        EdgeNode * edgeNode=(EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex=x;
        edgeNode->nextEdge=G->vexes[y].firstEdge;
        edgeNode->weight=0;
        G->vexes[y].firstEdge=edgeNode;


        free(vex1);
        free(vex2);
    }
    return OK;
}


/** �����ڽӱ��ʾ������������*/
Status CreateDN_AdjList(AdjListGraph * G)
{
    G->kind=DN;
    printf("�����붥������: ");
    scanf("%d",&G->vexCount);
    printf("������ߵ�����: ");
    scanf("%d",&G->edgeCount);
    printf("���������붥����Ϣ\n");
    for(int i=0;i<G->vexCount;i++){
        G->vexes[i].vex=(VerTexType)malloc(sizeof(char)*10);
        printf("����%d: ",i);
        scanf("%s",G->vexes[i].vex);
        //��ʼ���ڽӱ�,�ѱ��ÿ�
        G->vexes[i].firstArc=NULL;   //��firstArc��Ϊ����ָ��
        G->vexes[i].firstEdge=NULL;  //��firstEdge��Ϊ���ָ��
    }
    printf("�����붥����ڽӵ���Ϣ,�����ڽӱ�\n");
    for(int i=0;i<G->edgeCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("����: ");
        scanf("%s",vex1);
        printf("�ڽӵ�: ");
        scanf("%s",vex2);
        int value;
        printf("Ȩֵ: ");
        scanf("%d",&value);
        int x=LocateVex_AdjList(G,vex1);
        int y=LocateVex_AdjList(G,vex2);
        if(x==-1||y==-1){
            free(vex1);
            free(vex2);
            return  ERROR;
        }
        //���ɱ߽����ڽӱ�(����)
        ArcNode * arcNode=(ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjVex=y;
        arcNode->nextArc=G->vexes[x].firstArc;
        G->vexes[x].firstArc=arcNode;
        arcNode->weight=value;
        //���ɱ߽����ڽӱ�(���)
        EdgeNode * edgeNode=(EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex=x;
        edgeNode->nextEdge=G->vexes[y].firstEdge;
        edgeNode->weight=value;
        G->vexes[y].firstEdge=edgeNode;


        free(vex1);
        free(vex2);
    }
    return OK;
}


/** ���ض���x�ڶ��������е��±�,û���ҵ�����-1*/
int LocateVex_AdjList(AdjListGraph * G,VerTexType vex)
{
    int index=-1;
    for(int i=0;i<G->vexCount;i++){
        if(strcmp(vex,G->vexes[i].vex)==0){
            index=i;
            break;
        }
        //index++;
    }
    return index;
}

/** �����ڽӱ�������������*/
void DFSTraverse_ALG(AdjListGraph G)
{
    //��ʼ������״̬����
    for(int i=0;i<G.vexCount;i++){
        visited[i]=UNVISITED;
    }
    for(int i=0;i<G.vexCount;i++){
        if(!visited[i]){
            DFS_ALG(G,i);   //���ĳ������û�б����ʹ�,�͵ݹ�����������
        }
    }
}

/** ������ȱ����ĺ��ĺ��� index-��ǰ�����Ķ���(�ڽӵ�)�±�*/
void DFS_ALG(AdjListGraph G,int index)
{
    printf(" -> %s",G.vexes[index].vex);
    visited[index]=VISITED;          //����index�±�Ķ��㱻����
    if(G.kind==UDG||G.kind==UDN){
        EdgeNode * eNode=G.vexes[index].firstEdge;
        while(eNode){
            if(!visited[eNode->adjVex]){   //����ڽӵ�δ����,�͵ݹ����
                DFS_ALG(G,eNode->adjVex);
            }
            eNode =eNode->nextEdge;
        }
    }
    if(G.kind==DG||G.kind==DN){
        ArcNode * aNode=G.vexes[index].firstArc;
        while(aNode){
            if(!visited[aNode->adjVex]){
                DFS_ALG(G,aNode->adjVex);
            }
            aNode=aNode->nextArc;
        }
    }

}

void TestAdjListGraph()
{
     AdjListGraph G;
//     //����ͼ
//    Status status=CreateUDG_AdjList(&G);
//    for(int i=0;i<G.vexCount;i++){
//        VNode vNode=G.vexes[i];
//        printf("����: %s",vNode.vex);
//        EdgeNode * eNode=vNode.firstEdge;
//        while(eNode){
//            printf(" -> %d",eNode->adjVex);
//            eNode=eNode->nextEdge;
//        }
//        printf("\n");
//    }
//    //����ͼ
//    Status status=CreateDG_AdjList(&G);
//    printf("�ڽӱ�: \n");
//    for(int i=0;i<G.vexCount;i++){
//        VNode vNode=G.vexes[i];
//        ArcNode * arcNode=vNode.firstArc;
//        printf("���� %s: ",vNode.vex);
//        while(arcNode){
//            printf(" -> %d",arcNode->adjVex);
//            arcNode=arcNode->nextArc;
//        }
//        printf("\n");
//    }
//    printf("���ڽӱ�: \n");
//    for(int i=0;i<G.vexCount;i++){
//        VNode vNode=G.vexes[i];
//        ArcNode * arcNode=vNode.firstEdge;
//        printf("���� %s: ",vNode.vex);
//        while(arcNode){
//            printf(" <- %d",arcNode->adjVex);
//            arcNode=arcNode->nextEdge;
//        }
//        printf("\n");
//    }
    //������
    Status status=CreateDN_AdjList(&G);
    printf("�ڽӱ�: \n");
    for(int i=0;i<G.vexCount;i++){
        VNode vNode=G.vexes[i];
        ArcNode * arcNode=vNode.firstArc;
        printf("���� %s: ",vNode.vex);
        while(arcNode){
            printf(" -> %d(%d)",arcNode->adjVex,arcNode->weight);
            arcNode=arcNode->nextArc;
        }
        printf("\n");
    }
    printf("���ڽӱ�: \n");
    for(int i=0;i<G.vexCount;i++){
        VNode vNode=G.vexes[i];
        ArcNode * arcNode=vNode.firstEdge;
        printf("���� %s: ",vNode.vex);
        while(arcNode){
            printf(" <- %d(%d)",arcNode->adjVex,arcNode->weight);
            arcNode=arcNode->nextEdge;
        }
        printf("\n");
    }

    printf("�ڽӱ�ʵ�ֵ�������ȱ���\n");
    DFSTraverse_ALG(G);

}
