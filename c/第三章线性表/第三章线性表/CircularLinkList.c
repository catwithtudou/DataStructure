#include "CircularLinkList.h"

/** 指定位置插入元素*/
void InsertCircularLinkList(CircularLinkList * clList,int pos,ElementType data)
{
    //创建一个空结点
    CircularNode * node=(CircularNode *)malloc(sizeof(CircularNode));
    node->data=data;
    node->next=NULL;
    if(pos==1){
        node->next=clList->next;
        if(!node->next){
            //如何插入链表长度为0
            node->next=node;
        }else{
            //如果不为0
            CircularNode * lastNode=clList->next;
            for(int i=1;i<clList->length;i++){
                lastNode=lastNode->next;
            }
            lastNode->next=node;
        }
        clList->next=node;
        clList->length++;
        return;
    }
    //插入的不是第一个节点
    CircularNode * currNode=clList->next;
    for(int i=1;currNode&&i<pos-1;i++){
        currNode=currNode->next;
    }
    if(currNode){
        node->next=currNode->next;
        currNode->next=node;
        clList->length++;
        if(pos==clList->length){
            node->next=clList->next;
        }
    }
}

void PrintCircularLinkList(CircularLinkList * clList)
{
    if(clList->length==0||!clList->next){
        printf("链表长度为空,没有内容可以打印!");
        clList->length=0;
        return;
    }
    CircularNode * node=clList->next;
    for(int i=0;i<clList->length;i++){
        printf("%d\t%s\n",node->data.id,node->data.name);
        node=node->next;
    }
}

ElementType DeleteCircularLinkList(CircularLinkList * clList,int pos)
{
      ElementType data;
      data.id=-999;
      if(pos==1){
        CircularNode * node=clList->next;
        if(node){
            //找到最后一个节点,改变其指针域的指向
            data=node->data;
            CircularNode * lastNode=clList->next;
            for(int i=1;i<clList->length;i++){
                lastNode=lastNode->next;
            }
            clList->next=node->next;
            lastNode->next=clList->next;
            free(node);
            clList->length--;
        }
        return;
      }
      CircularNode * preNode;
      CircularNode * node=clList->next;
      for(int i=1;node&&i<pos;i++){
        preNode=node;
        node=node->next;
      }
      if(node){
        data=node->data;
        preNode->next=node->next;
        free(node);
        clList->length--;
      }
      return data;
}

CircularNode * GetCircularLinkListNode(CircularLinkList * clList,ElementType element)
{
    CircularNode * node=clList->next;
    if(!node){
        return NULL;
    }
    //不使用循环变量i来遍历循环链表的方法
    do{
        if(element.id==node->data.id&&strcmp(element.name,node->data.name)==0){
            return node;
        }
        node=node->next;
    }while(node!= clList->next);
    return NULL;
}

void PrintCircularLinkListByNode(CircularLinkList * clList,CircularNode * node)
{
   if(!node||!clList->next){
    printf("链表长度为空,没有内容可以打印!");
    return;
   }
   CircularNode * oriNode= node;
   do{
       printf("%d\t%s\n",node->data.id,node->data.name);
       node=node->next;
   }while(node !=oriNode);
}

void InitCircularLinkList(CircularLinkList * clList,ElementType * data,int length)
{
    for(int i=0;i<length;i++){
        InsertCircularLinkList(clList,i+1,data[i]);
    }
}
