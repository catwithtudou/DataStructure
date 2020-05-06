#include "StaticLinkList.h"


/**初始化链表*/
void InitStaticLinkList(StaticLinkList slList)
{
    for(int i=0;i<MAX_SIZE_SSL;i++){
        slList[i].next=i+1;
        slList[i].data.id=-1;
        slList[i].data.name=NULL;
    }
    //将最后一个节点置空
    slList[MAX_SIZE_SSL-1].next=0;
    //将备用链表的尾节点置为空
    slList[MAX_SIZE_SSL-2].next=0;
}

/**向指定位置插入元素*/
int InsertStaticLinkList(StaticLinkList slList,int pos,ElementType element)
{
    if(pos<1||pos>GetStaticLinkList(slList)+1){
        return ERROR;
    }
    int cursor=MAX_SIZE_SSL-1;//拿到第一个元素的下标
    //需要判断cursor的范围是否合法
    //分配内存
    int newIndex=mallocSSL(slList);
    if(newIndex){
         slList[newIndex].data=element;
         //找到newIndex的前缀节点
         for(int i=1;i<=pos-1;i++){
            cursor=slList[cursor].next;
         }
    slList[newIndex].next=slList[cursor].next;
    slList[cursor].next=newIndex;
    return OK;
    }
    return ERROR;
}

/**为静态链表分配一个空间的内存,返回ERROR表示分配失败*/
int mallocSSL(StaticLinkList slList)
{
    //拿到第一个空闲节点下标(备用链表下标)
    int cursor=slList[0].next;
    if(cursor){
        slList[0].next=slList[cursor].next;
    }
    return cursor;
}

/**删除链表指定位置的元素*/
int DeleteStaticLinkList(StaticLinkList slList,int pos)
{
    printf("%d\n",GetStaticLinkList(slList));
    if(pos<1||pos>GetStaticLinkList(slList)){
        printf("111\n");
        return ERROR;
    }
    //通过循环找到要删除位置的前缀节点
    int cursor=MAX_SIZE_SSL-1;
    for(int i=1;i<=pos-1;i++){
        printf("2222\n");
        cursor=slList[cursor].next;
    }
    int delIndex=slList[cursor].next;
    slList[cursor].next=slList[delIndex].next;
    //释放空间
    FreeStaticLinkList(slList,delIndex);
    return OK;
}

/**获得静态链表的长度*/
int GetStaticLinkList(StaticLinkList slList)
{
    int count=0;
    int cursor=slList[MAX_SIZE_SSL-1].next;
    while(cursor){
        cursor=slList[cursor].next;
        count++;
    }
    return count;
}

/**回收原始数组中指定下标的空间*/
void FreeStaticLinkList(StaticLinkList slList,int index)
{
    //将下标为index的空闲节点回收到备用链表
    slList[index].next=slList[0].next;
    //将0号元素的next节点指向备用链表的第一个节点,表示Index节点空闲
    slList[0].next=index;
}

void PrintStaticLinkList(StaticLinkList slList)
{
    for(int i=0;i<MAX_SIZE_SSL;i++){
        printf("i:%d\tnext:%d\tid:%d\tname:%s\n",i,slList[i].next,slList[i].data.id,slList[i].data.name);
    }
}
