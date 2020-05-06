#include"DoublyLinkList.h"

/**��˫�������е�ָ��λ�ò���Ԫ��*/
void InsertDoublyLinkList(DoublyLinkList * dlList,int pos,ElementType element)
{
    //�����սڵ�
    DoublyNode * node=(DoublyNode *)malloc(sizeof(DoublyNode));
    node->data=element;
    node->prev=NULL;
    node->next=NULL;
    //�ڵ�һ��λ�ò���ڵ�
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
        if(currNode->next){//���ǰ׺�ڵ�ǿ�(��Ϊ�վͱ�ʾû�к�̽ڵ���)
            //������λ�ô���ǰ׺�ڵ�ָ���½ڵ�
            currNode->next->prev=node;
        }
    node->next=currNode->next;
    currNode->next=node;
    dlList->length++;
    }
}

/**ɾ��˫������ָ��λ�õ�Ԫ�ز�����*/
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
                //����еڶ����ڵ�,��ô���õڶ����ڵ��ǰ׺�ڵ�ΪNull
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

/**����˫��������ָ��λ�õ�������*/
ElementType GetDoublyLinkList(DoublyLinkList * dlList,int pos)
{
       DoublyNode * node=dlList->next;
       for(int i=1;node&&i<pos;i++){
        node=node->next;
       }
       return node->data;
}

/**����˫��������ĳ���ڵ��ǰ�ýڵ�ָ��*/
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
        printf("����Ϊ��,û�����ݿ��Դ�ӡ\n");
        dlList->length=0;
        return;
    }
    DoublyNode * node=dlList->next;
    for(int i=0;i<dlList->length;i++){
        printf("%d\t%s\n",node->data.id,node->data.name);
        node=node->next;
    }
}
