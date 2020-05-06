#include "AdjListGraph.h"

/** 采用邻接表表示法创建无向图*/
Status CreateUDG_AdjList(AdjListGraph * G)
{
    G->kind=UDG;
    printf("请输入顶点数量: ");
    scanf("%d",&G->vexCount);
    printf("请输入边的数量: ");
    scanf("%d",&G->edgeCount);
    printf("请依次输入顶点信息\n");
    for(int i=0;i<G->vexCount;i++){
        G->vexes[i].vex=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点%d: ",i);
        scanf("%s",G->vexes[i].vex);
        //初始化邻接表,把边置空
        G->vexes[i].firstEdge=NULL;
    }
    printf("请输入顶点和邻接点信息,构建邻接表\n");
    for(int i=0;i<G->edgeCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点: ");
        scanf("%s",vex1);
        printf("邻接点: ");
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

/** 采用邻接表表示法创建有向图*/
Status CreateDG_AdjList(AdjListGraph * G)
{
    G->kind=DG;
    printf("请输入顶点数量: ");
    scanf("%d",&G->vexCount);
    printf("请输入边的数量: ");
    scanf("%d",&G->edgeCount);
    printf("请依次输入顶点信息\n");
    for(int i=0;i<G->vexCount;i++){
        G->vexes[i].vex=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点%d: ",i);
        scanf("%s",G->vexes[i].vex);
        //初始化邻接表,把边置空
        G->vexes[i].firstArc=NULL;   //把firstArc作为出边指针
        G->vexes[i].firstEdge=NULL;  //把firstEdge作为入边指针
    }
    printf("请输入顶点和邻接点信息,构建邻接表\n");
    for(int i=0;i<G->edgeCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点: ");
        scanf("%s",vex1);
        printf("邻接点: ");
        scanf("%s",vex2);
        int x=LocateVex_AdjList(G,vex1);
        int y=LocateVex_AdjList(G,vex2);
        if(x==-1||y==-1){
            free(vex1);
            free(vex2);
            return  ERROR;
        }
        //生成边结点的邻接表(出边)
        ArcNode * arcNode=(ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjVex=y;
        arcNode->nextArc=G->vexes[x].firstArc;
        G->vexes[x].firstArc=arcNode;
        arcNode->weight=0;
        //生成边结点的邻接表(入边)
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


/** 采用邻接表表示法创建有向网*/
Status CreateDN_AdjList(AdjListGraph * G)
{
    G->kind=DN;
    printf("请输入顶点数量: ");
    scanf("%d",&G->vexCount);
    printf("请输入边的数量: ");
    scanf("%d",&G->edgeCount);
    printf("请依次输入顶点信息\n");
    for(int i=0;i<G->vexCount;i++){
        G->vexes[i].vex=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点%d: ",i);
        scanf("%s",G->vexes[i].vex);
        //初始化邻接表,把边置空
        G->vexes[i].firstArc=NULL;   //把firstArc作为出边指针
        G->vexes[i].firstEdge=NULL;  //把firstEdge作为入边指针
    }
    printf("请输入顶点和邻接点信息,构建邻接表\n");
    for(int i=0;i<G->edgeCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点: ");
        scanf("%s",vex1);
        printf("邻接点: ");
        scanf("%s",vex2);
        int value;
        printf("权值: ");
        scanf("%d",&value);
        int x=LocateVex_AdjList(G,vex1);
        int y=LocateVex_AdjList(G,vex2);
        if(x==-1||y==-1){
            free(vex1);
            free(vex2);
            return  ERROR;
        }
        //生成边结点的邻接表(出边)
        ArcNode * arcNode=(ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjVex=y;
        arcNode->nextArc=G->vexes[x].firstArc;
        G->vexes[x].firstArc=arcNode;
        arcNode->weight=value;
        //生成边结点的邻接表(入边)
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


/** 返回顶点x在顶点数组中的下标,没有找到返回-1*/
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

/** 基于邻接表的深度优先搜索*/
void DFSTraverse_ALG(AdjListGraph G)
{
    //初始化访问状态数组
    for(int i=0;i<G.vexCount;i++){
        visited[i]=UNVISITED;
    }
    for(int i=0;i<G.vexCount;i++){
        if(!visited[i]){
            DFS_ALG(G,i);   //如果某个顶点没有被访问过,就递归访问这个顶点
        }
    }
}

/** 深度优先遍历的核心函数 index-当前遍历的顶点(邻接点)下标*/
void DFS_ALG(AdjListGraph G,int index)
{
    printf(" -> %s",G.vexes[index].vex);
    visited[index]=VISITED;          //设置index下标的顶点被访问
    if(G.kind==UDG||G.kind==UDN){
        EdgeNode * eNode=G.vexes[index].firstEdge;
        while(eNode){
            if(!visited[eNode->adjVex]){   //如果邻接点未访问,就递归访问
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
//     //无向图
//    Status status=CreateUDG_AdjList(&G);
//    for(int i=0;i<G.vexCount;i++){
//        VNode vNode=G.vexes[i];
//        printf("顶点: %s",vNode.vex);
//        EdgeNode * eNode=vNode.firstEdge;
//        while(eNode){
//            printf(" -> %d",eNode->adjVex);
//            eNode=eNode->nextEdge;
//        }
//        printf("\n");
//    }
//    //有向图
//    Status status=CreateDG_AdjList(&G);
//    printf("邻接表: \n");
//    for(int i=0;i<G.vexCount;i++){
//        VNode vNode=G.vexes[i];
//        ArcNode * arcNode=vNode.firstArc;
//        printf("顶点 %s: ",vNode.vex);
//        while(arcNode){
//            printf(" -> %d",arcNode->adjVex);
//            arcNode=arcNode->nextArc;
//        }
//        printf("\n");
//    }
//    printf("逆邻接表: \n");
//    for(int i=0;i<G.vexCount;i++){
//        VNode vNode=G.vexes[i];
//        ArcNode * arcNode=vNode.firstEdge;
//        printf("顶点 %s: ",vNode.vex);
//        while(arcNode){
//            printf(" <- %d",arcNode->adjVex);
//            arcNode=arcNode->nextEdge;
//        }
//        printf("\n");
//    }
    //有向网
    Status status=CreateDN_AdjList(&G);
    printf("邻接表: \n");
    for(int i=0;i<G.vexCount;i++){
        VNode vNode=G.vexes[i];
        ArcNode * arcNode=vNode.firstArc;
        printf("顶点 %s: ",vNode.vex);
        while(arcNode){
            printf(" -> %d(%d)",arcNode->adjVex,arcNode->weight);
            arcNode=arcNode->nextArc;
        }
        printf("\n");
    }
    printf("逆邻接表: \n");
    for(int i=0;i<G.vexCount;i++){
        VNode vNode=G.vexes[i];
        ArcNode * arcNode=vNode.firstEdge;
        printf("顶点 %s: ",vNode.vex);
        while(arcNode){
            printf(" <- %d(%d)",arcNode->adjVex,arcNode->weight);
            arcNode=arcNode->nextEdge;
        }
        printf("\n");
    }

    printf("邻接表实现的深度优先遍历\n");
    DFSTraverse_ALG(G);

}
