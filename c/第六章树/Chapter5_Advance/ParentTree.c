#include "ParentTree.h"

/** 初始化空树 */
void InitPTree(PTree * tree){
    tree->root = -1;
    tree->length = 0;
}

/** 销毁树 */
void DestoryPTree(PTree * tree){
    if(tree){
        free(tree);
    }
}

/** 构造树 */
void CreatePTree(PTree * tree){
    printf("请输入结点个数：");
    scanf("%d", &(tree->length));
    printf("请输入结点的值及双亲序号：\n");

    tree->root = 0;
    for(int i = tree->root; i < tree->length; i++){
        ElementType * elem = (ElementType *)malloc(sizeof(ElementType));
        int parentPos;
        elem->id = i + 1;
        printf("请输入第%d个结点的值：", i + 1);
        scanf("%s", elem->name);
        tree->node[i].data = *elem;
        printf("请输入第%d个结点的双亲位置：", i + 1);
        //scanf("%d", &tree->node[i].parent);
        scanf("%d", &parentPos);
        //为结点赋值
        AssignPTree(&(tree->node[i]), parentPos, *elem);
    }
    tree->node[tree->root].parent = -1;         //根结点双亲设置为-1
    printf("创建成功：%d\n", tree->length);
    for(int i = 0; i < tree->length; i++){
        printf("[%d, %s, %d] ", tree->node[i].data.id, tree->node[i].data.name, tree->node[i].parent);
    }
}

/** 为树节点赋值 */
void AssignPTree(PNode * node, int parent, ElementType data){
    node->data = data;
    node->parent = parent;
}

/** 返回树是否为空 */
int IsPTreeEmpty(PTree tree){
    return tree.length == 0;
}

/** 返回树的深度 */
int GetPTreeDepth(PTree tree){
    if(IsPTreeEmpty(tree) == 1) return 0;
    int max = 0;    //最大深度
    //思路：遍历结点集合，记录每个结点的深度，取所有深度中的最大深度
    for(int i = tree.root; i < tree.length; i++){
        int height = 1; //从根结点开始，高度至少为1
        int node = tree.node[i].parent;
        while(node != -1){//node不为根结点时继续遍历
            node = tree.node[node].parent;  //通过双亲的位置找到双亲结点，并记录下双亲
            height++;   //每次遍历高度+1
        }
        if(max < height){
            max = height;
        }
    }
    return max;
}

/*层序遍历树*/
void ZOrderPTree(PTree tree){
    int level = 1;
    printf("第%d层：", level);
    printf("[%d, %s] ", tree.node[tree.root].data.id, tree.node[tree.root].data.name);
    level++;
    int depth = GetPTreeDepth(tree);
    //遍历根结点以后的每个结点
    printf("\n第%d层：", level);
    for(int i = 0; i < tree.length; i++){
        //查找第i个结点的所有孩子结点(注意：存储顺序要求双亲位置一定在孩子前面)
        int flag = 0;       //换行标识
        for(int j = i + 1; j < tree.length; j++){
            if(tree.node[j].parent == i){//双亲位置==i：即找到位置i结点的孩子结点
                printf("[%d, %s] ", tree.node[j].data.id, tree.node[j].data.name);
                flag = 1;
            }
        }
        if(flag == 1 && level < depth){
            level++;
            printf("\n第%d层：", level);
        }
    }
}

/** 测试函数  */
void TestPTree(){
    PTree tree;
    InitPTree(&tree);
//  测试输入顺序：
//请输入结点个数：7
//请输入结点的值及双亲序号：
//请输入第1个结点的值：A
//请输入第1个结点的双亲位置：-1
//请输入第2个结点的值：B
//请输入第2个结点的双亲位置：0
//请输入第3个结点的值：C
//请输入第3个结点的双亲位置：0
//请输入第4个结点的值：D
//请输入第4个结点的双亲位置：1
//请输入第5个结点的值：E
//请输入第5个结点的双亲位置：1
//请输入第6个结点的值：F
//请输入第6个结点的双亲位置：2
//请输入第7个结点的值：G
//请输入第7个结点的双亲位置：2
//[1, A, -1] [2, B, 0] [3, C, 0] [4, D, 1] [5, E, 1] [6, F, 2] [7, G, 2]
//层序遍历：
//第1层：[1, A]
//第2层：[2, B] [3, C]
//第3层：[4, D] [5, E] [6, F] [7, G]
    CreatePTree(&tree);
    printf("深度：%d\n", GetPTreeDepth(tree));
    printf("层序遍历：\n");
    ZOrderPTree(tree);
}
