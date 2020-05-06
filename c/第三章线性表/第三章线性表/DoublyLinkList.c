#include"DoublyLinkList.h"

/**向双向链表中的指定位置插入元素*/
void InsertDoublyLinkList(DoublyLinkList * dlList,int pos,ElementType element)
{
    //创建空节点
    DoublyNode * node=(DoublyNode *)malloc(sizeof(DoublyNode));
    node->data=element;
    node->prev=NULL;
    node->next=NULL;
    //在第一个位置插入节点
    if(pos==1){
        if(dlList->length==0){
            dlList->next=node;
            dlList->length++;
            return;
        }
        node->next=dlList->next;
        dlList->next=node;
        node->next->prev=node;
        dlList->length++;
        return;
    }
    DoublyNode * currNode=dlList->next;
    for(int i=1;i<pos-1&&currNode;i++){
        currNode=currNode->next;
    }
    if(currNode){
        node->prev=currNode;
        if(currNode->next){//如果前缀节点非空(因为空就表示没有后继节点了)
            //将插入位置处的前缀节点指向新节点
            currNode->next->prev=node;
        }
    node->next=currNode->next;
    currNode->next=node;
    dlList->length++;
    }
}

/**删除双向链表指定位置的元素并返回*/
ElementType DeleteDoublyLinkList(DoublyLinkList * dlList,int pos)
{
    ElementType element;
    element.id=-999;
    if(pos==1){
        DoublyNode * node=dlList->next;
        if(node){
            element=node->data;
            dlList->next=node->next;
            if(node->next){
                //如果有第二个节点,那么设置第二个节点的前缀节点为Null
                node->next->prev=NULL;
            }
            free(node);
            dlList->length--;
        }
        return element;
    }
    DoublyNode * node=dlList->next;
    for(int i=1;node&&i<pos;i++){
        node=node->next;
    }
    if(node){
        element=node->data;
        if(node->next){
            node->next->prev=node->prev;
        }
        node->prev->next=node->next;
        free(node);
        dlList->length--;
    }
    return element;
}

/**返回双向链表中指定位置的数据域*/
ElementType GetDoublyLinkList(DoublyLinkList * dlList,int pos)
{
       DoublyNode * node=dlList->next;
       for(int i=1;node&&i<pos;i++){
        node=node->next;
       }
       return node->data;
}

/**返回双向链表中某个节点的前置节点指针*/
DoublyNode * GetDoublyPrevNode(DoublyNode * node)
{
    if(node)
    return node->prev;
    else
    return NULL;
}

void PrintDoublyLinkList(DoublyLinkList * dlList)
{
    if(!dlList){
        printf("链表为空,没有内容可以打印\n");
        dlList->length=0;
        return;
    }
    DoublyNode * node=dlList->next;
    for(int i=0;i<dlList->length;i++){
        printf("%d\t%s\n",node->data.id,node->data.name);
        node=node->next;
    }
}
