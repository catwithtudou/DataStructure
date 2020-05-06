#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkList.h"
#include "StaticLinkList.h"
#include "DoublyLinkList.h"
ElementType dataArray[]={
{1,"����"},
{2,"������"},
{3,"����ѽ"},
{4,"������"},
};
void TestCircularLinkList();

void TestStaticLinkList();

void TestDoublyLinkList();
int main()
{
    printf("Hello world!\n");
    //TestCircularLinkList();
    //TestStaticLinkList();
    TestDoublyLinkList();
    return 0;
}

void TestDoublyLinkList()
{
    DoublyLinkList * dlList=(DoublyLinkList*)malloc(sizeof(DoublyLinkList));
    dlList->length=0;
    dlList->next=NULL;
    InsertDoublyLinkList(dlList,1,dataArray[0]);
    InsertDoublyLinkList(dlList,2,dataArray[1]);
    PrintDoublyLinkList(dlList);
    printf("ɾ���ڶ���λ�õ�Ԫ��:\n");
    DeleteDoublyLinkList(dlList,2);
    PrintDoublyLinkList(dlList);


}

void TestStaticLinkList()
{
    StaticLinkList slList;
    InitStaticLinkList(slList);
    PrintStaticLinkList(slList);
    ElementType element1;
    element1.id=123;
    element1.name="������";
    ElementType element2;
    element2.id=125;
    element2.name="����";
    ElementType element3;
    element3.id=127;
    element3.name="��";
    int flag=InsertStaticLinkList(slList,1,element1);
    int flag1=InsertStaticLinkList(slList,1,element2);
    int flag2=InsertStaticLinkList(slList,1,element3);
    printf("����Ԫ�غ�:\n");
    PrintStaticLinkList(slList);
    int flag3=DeleteStaticLinkList(slList,2);
    printf("ɾ��2��Ԫ��:\n");
    PrintStaticLinkList(slList);
}

void TestCircularLinkList()
{
    CircularLinkList * clList=(CircularLinkList *)malloc(sizeof(CircularLinkList));
    clList->length=0;
    clList->next=NULL;
    //InsertCircularLinkList(clList,1,dataArray[1]);
   InitCircularLinkList(clList,dataArray,4);
   //ElementType data=DeleteCircularLinkList(clList,1);
    PrintCircularLinkList(clList);
    ElementType elem;
    elem.id=3;
    elem.name="����ѽ";
    CircularNode * node=GetCircularLinkListNode(clList,elem);
    printf("������ѽ��ʼ����:\n");
    PrintCircularLinkListByNode(clList,node);
}
