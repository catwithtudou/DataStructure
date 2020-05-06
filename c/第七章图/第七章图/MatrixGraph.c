#include "MatrixGraph.h"

/** 使用邻接矩阵表示法创建无向图*/
/**
  *   无向图的特点
  *   1.无向图的邻接矩阵是对称
  *   2.顶点i的度=第i行(列)中1的个数
  */
Status CreateUDG(MatrixGraph * G)
{
    G->kind=UDG;  //设置当前创建图的类型为无向图
    printf("请输入无向图的顶点数: ");
    scanf("%d",&G->verTexCount);
    printf("请输入边的数量: ");
    scanf("%d",&G->arcCount);
    printf("依次输入顶点信息\n");
    for(int i=0;i<G->verTexCount;i++){
        G->verTexs[i]=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点%d: ",i);
        scanf("%s",G->verTexs[i]);
    }
    //初始化邻接矩阵,所有边的权值设置为0
    for(int i=0;i<G->verTexCount;i++){
        for(int j=0;j<G->verTexCount;j++){
            G->arcs[i][j]=0;
        }
    }
    printf("请输入顶点和邻接顶点信息,构建邻接矩阵\n");
    for(int i=0;i<G->arcCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点: ");
        scanf("%s",vex1);
        printf("邻接点: ");
        scanf("%s",vex2);
        //分别获得两个顶点在顶点数组中的坐标
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


/** 返回某个顶点在顶点集合中的下标(0开始),不存在返回-1*/
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


/** 使用邻接矩阵表示法创建有向图*/
/**
 *   有向图的特点:
 *   1.有向图的邻接矩阵有可能不是对称的
 *   2.顶点的出度=第i行元素之和;顶点的入度=第i列元素之和
 *   3.顶点的度=第i行元素之和+第i列元素之和
 */
Status CreateDG(MatrixGraph * G)
{
    G->kind=DG;  //设置当前创建图的类型为有向图
    printf("请输入有向图的顶点数: ");
    scanf("%d",&G->verTexCount);
    printf("请输入边的数量: ");
    scanf("%d",&G->arcCount);
    printf("依次输入顶点信息\n");
    for(int i=0;i<G->verTexCount;i++){
        G->verTexs[i]=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点%d: ",i);
        scanf("%s",G->verTexs[i]);
    }
    //初始化邻接矩阵,所有边的权值设置为0
    for(int i=0;i<G->verTexCount;i++){
        for(int j=0;j<G->verTexCount;j++){
            G->arcs[i][j]=0;
        }
    }
    printf("请输入顶点和邻接顶点信息,构建邻接矩阵\n");
    for(int i=0;i<G->arcCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点: ");
        scanf("%s",vex1);
        printf("邻接点: ");
        scanf("%s",vex2);
        //分别获得两个顶点在顶点数组中的坐标
        int x=locateVex(G,vex1);
        int y=locateVex(G,vex2);
        if(x==-1||y==-1){
            return  ERROR;
        }
        G->arcs[x][y]=1;   // 有向图的邻接矩阵有可能不对称
        //G->arcs[y][x]=1;

        free(vex1);
        free(vex2);
    }
    return OK;
}

/** 使用邻接矩阵表示法创建有向网*/
Status CreateDN(MatrixGraph * G)
{
        G->kind=DN;  //设置当前创建图的类型为有向图
    printf("请输入有向网的顶点数: ");
    scanf("%d",&G->verTexCount);
    printf("请输入边的数量: ");
    scanf("%d",&G->arcCount);
    printf("依次输入顶点信息\n");
    for(int i=0;i<G->verTexCount;i++){
        G->verTexs[i]=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点%d: ",i);
        scanf("%s",G->verTexs[i]);
    }
    //初始化邻接矩阵,所有边的权值设置为无穷大
    for(int i=0;i<G->verTexCount;i++){
        for(int j=0;j<G->verTexCount;j++){
            G->arcs[i][j]=INT_MAX;
        }
    }
    printf("请输入顶点和邻接顶点信息,构建邻接矩阵\n");
    for(int i=0;i<G->arcCount;i++){
        VerTexType vex1=(VerTexType)malloc(sizeof(char)*10);
        VerTexType vex2=(VerTexType)malloc(sizeof(char)*10);
        printf("顶点: ");
        scanf("%s",vex1);
        printf("邻接点: ");
        scanf("%s",vex2);
        //分别获得两个顶点在顶点数组中的坐标
        int x=locateVex(G,vex1);
        int y=locateVex(G,vex2);
        if(x==-1||y==-1){
            return  ERROR;
        }
        int value;
        printf("请输入权值: ");
        scanf("%d",&value);
        G->arcs[x][y]=value;   // 有向图的邻接矩阵有可能不对称
        //G->arcs[y][x]=1;
        free(vex1);
        free(vex2);
    }
    return OK;
}


/** 邻接矩阵的深度优先搜索*/
void DFSTraverse_AMG(MatrixGraph  G)
{
    //初始化状态数组
    for(int i=0;i<G.verTexCount;i++){
        visited[i]=UNVISITED; //初始状态设置为未访问
    }
    //DFS遍历
    for(int i=0;i<G.verTexCount;i++){
        if(!visited[i]){
            //如果某个顶点未访问
            //调用遍历方法
            DFS_AMG(G,i);
        }
    }
}

/** DFS核心算法,index为深度搜索的某个顶点下标*/
void DFS_AMG(MatrixGraph G,int index)
{
    printf(" -> %s",G.verTexs[index]);   //访问当前顶点
    visited[index]=VISITED;              //更改当前顶点的访问状态
    for(int i=FirstAdjVex_AMG(G,G.verTexs[index]);i
    ;i=SecondAdjVex_AMG(G,G.verTexs[index],G.verTexs[i])){
        if(!visited[i]){
            DFS_AMG(G,i);   //如果没有访问过则继续递归调用搜索
        }
    }
}


/** 返回顶点vex所在行中的第一个邻接点下标*/
int FirstAdjVex_AMG(MatrixGraph G,VerTexType vex)
{
    int i=locateVex(&G,vex);   //找到顶点vex在顶点数组中的下标
    if(i==-1)return ERROR;
    int defaultWeight;         //默认权重
    defaultWeight= G.kind<=1 ? 0 : INT_MAX;  //图/网
    for(int j=0;j<G.verTexCount;j++){
        //搜索图的邻接矩阵中与顶点vex的第一个邻接点下标
        if(G.arcs[i][j]!=defaultWeight){
            return j;
        }
    }
    return 0;
}

/** 返回与顶点vex1邻接的另一个邻接点(除vex2的下一个邻接点),没有就返回-1*/
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
    //创建无向图
   //Status status=CreateUDG(&G);
    //创建有向图
   //Status status=CreateDG(&G);
    //创建有向网
    Status status=CreateDN(&G);
    if(status==ERROR){
        printf("创建图失败,请检查后重试! \n");
        return;
    }
    printf("打印图的邻接矩阵: \n");
    printf("\t");
    for(int i=0;i<G.verTexCount;i++){
        printf("\t%s",G.verTexs[i]);
    }
    printf("\n");
    for(int i=0;i<G.verTexCount;i++){
        printf("\t%s",G.verTexs[i]);
        for(int j=0;j<G.verTexCount;j++){
            if(G.arcs[i][j]==INT_MAX){
                printf("\t∞");
            }else{
            printf("\t%d",G.arcs[i][j]);
            }
        }
        printf("\n");
    }
    printf("深度优先遍历:\n");
    DFSTraverse_AMG(G);
}
