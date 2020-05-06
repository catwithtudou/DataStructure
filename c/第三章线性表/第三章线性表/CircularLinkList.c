#include "CircularLinkList.h"

/** ָ��λ�ò���Ԫ��*/
void InsertCircularLinkList(CircularLinkList * clList,int pos,ElementType data)
{
    //����һ���ս��
    CircularNode * node=(CircularNode *)malloc(sizeof(CircularNode));
    node->data=data;
    node->next=NULL;
    if(pos==1){
        node->next=clList->next;
        if(!node->next){
            //��β���������Ϊ0
            node->next=node;
        }else{
            //�����Ϊ0
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
    //����Ĳ��ǵ�һ���ڵ�
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
        printf("������Ϊ��,û�����ݿ��Դ�ӡ!");
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
            //�ҵ����һ���ڵ�,�ı���ָ�����ָ��
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
    //��ʹ��ѭ������i������ѭ������ķ���
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
    printf("������Ϊ��,û�����ݿ��Դ�ӡ!");
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
