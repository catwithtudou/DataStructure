#include "StaticLinkList.h"


/**��ʼ������*/
void InitStaticLinkList(StaticLinkList slList)
{
    for(int i=0;i<MAX_SIZE_SSL;i++){
        slList[i].next=i+1;
        slList[i].data.id=-1;
        slList[i].data.name=NULL;
    }
    //�����һ���ڵ��ÿ�
    slList[MAX_SIZE_SSL-1].next=0;
    //�����������β�ڵ���Ϊ��
    slList[MAX_SIZE_SSL-2].next=0;
}

/**��ָ��λ�ò���Ԫ��*/
int InsertStaticLinkList(StaticLinkList slList,int pos,ElementType element)
{
    if(pos<1||pos>GetStaticLinkList(slList)+1){
        return ERROR;
    }
    int cursor=MAX_SIZE_SSL-1;//�õ���һ��Ԫ�ص��±�
    //��Ҫ�ж�cursor�ķ�Χ�Ƿ�Ϸ�
    //�����ڴ�
    int newIndex=mallocSSL(slList);
    if(newIndex){
         slList[newIndex].data=element;
         //�ҵ�newIndex��ǰ׺�ڵ�
         for(int i=1;i<=pos-1;i++){
            cursor=slList[cursor].next;
         }
    slList[newIndex].next=slList[cursor].next;
    slList[cursor].next=newIndex;
    return OK;
    }
    return ERROR;
}

/**Ϊ��̬�������һ���ռ���ڴ�,����ERROR��ʾ����ʧ��*/
int mallocSSL(StaticLinkList slList)
{
    //�õ���һ�����нڵ��±�(���������±�)
    int cursor=slList[0].next;
    if(cursor){
        slList[0].next=slList[cursor].next;
    }
    return cursor;
}

/**ɾ������ָ��λ�õ�Ԫ��*/
int DeleteStaticLinkList(StaticLinkList slList,int pos)
{
    printf("%d\n",GetStaticLinkList(slList));
    if(pos<1||pos>GetStaticLinkList(slList)){
        printf("111\n");
        return ERROR;
    }
    //ͨ��ѭ���ҵ�Ҫɾ��λ�õ�ǰ׺�ڵ�
    int cursor=MAX_SIZE_SSL-1;
    for(int i=1;i<=pos-1;i++){
        printf("2222\n");
        cursor=slList[cursor].next;
    }
    int delIndex=slList[cursor].next;
    slList[cursor].next=slList[delIndex].next;
    //�ͷſռ�
    FreeStaticLinkList(slList,delIndex);
    return OK;
}

/**��þ�̬����ĳ���*/
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

/**����ԭʼ������ָ���±�Ŀռ�*/
void FreeStaticLinkList(StaticLinkList slList,int index)
{
    //���±�Ϊindex�Ŀ��нڵ���յ���������
    slList[index].next=slList[0].next;
    //��0��Ԫ�ص�next�ڵ�ָ��������ĵ�һ���ڵ�,��ʾIndex�ڵ����
    slList[0].next=index;
}

void PrintStaticLinkList(StaticLinkList slList)
{
    for(int i=0;i<MAX_SIZE_SSL;i++){
        printf("i:%d\tnext:%d\tid:%d\tname:%s\n",i,slList[i].next,slList[i].data.id,slList[i].data.name);
    }
}
