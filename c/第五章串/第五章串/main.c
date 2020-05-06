#include <stdio.h>
#include <stdlib.h>
#include "SeqString.h"

void TestSeqString();

void TestBF();

void TestKMP();

void TestVirus();
/**病毒检测函数,返回1表示感染,返回0表示未感染*/
int Virus_Check(HString parent,HString child);

int main()
{
    printf("Hello world!\n");
    //TestSeqString();
    //TestBF();
    //TestKMP();
    TestVirus();
    return 0;
}

int Virus_Check(HString parent,HString child)
{
    char tempVirus[child.length*2+1];//预留一个\0的位置
    for(int i=0;i<child.length*2;i++){
        tempVirus[i]=child.ch[i%child.length];
    }
    tempVirus[child.length*2]='\0';

    for(int i=0;i<child.length;i++){
        //每次取长度为字串长度的串进行比较
        char virus[child.length+1];
        for(int j=i;j<i+child.length;j++){
            virus[j-i]=tempVirus[j];
        }
        virus[child.length]='\0';
        //转换成堆串,与主串匹配
        HString virus_h;
        InitString_HeapString(&virus_h);
        StrAssign_HeapString(&virus_h,virus);
        if(KMPCompare(&parent,&virus_h,1)!=0){
            return 1;
        }
    }
    return 0;
}

void TestVirus()
{
    //病毒感染检测
    char *persons[]={
        "bbaabbba","aaabbbba","abceaabb","abaabcea","cdabbbab",
        "cabbbbab","bcdedbda","bdedbccda","cdcdcdec","cdccdcce"
    };
    char *virus[]={
        "baa","bae","aabb","aacc","abcd","aacd",
        "abcde","acc","cde","cced"
    };
    HString persons_h[10];
    HString virus_h[10];
    for(int i=0;i<10;i++){
        InitString_HeapString(&persons_h[i]);
        InitString_HeapString(&virus_h[i]);
        StrAssign_HeapString(&persons_h[i],persons[i]);
        StrAssign_HeapString(&virus_h[i],virus[i]);
    }
    printf("人类DNA样本: ");
    for(int i=0;i<10;i++){
        PrintHeapString(&persons_h[i]);
        printf(", ");
    }
    printf("\n");
    printf("病毒DNA样本: ");
        for(int i=0;i<10;i++){
        PrintHeapString(&persons_h[i]);
        printf(", ");
    }
    printf("\n");

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Virus_Check(persons_h[i],virus_h[j])){
                printf("检测样本DNA:%s\t匹配的病毒DNA:%s\n",persons[i],virus[j]);
            }
        }
    }


}


void TestKMP()
{
    HString parent;
    HString child;
    StrAssign_HeapString(&parent,"ABC ADS DSASADD");
    StrAssign_HeapString(&child,"ADS");
    printf("匹配结果: %d\n",KMPCompare(&parent,&child,1));
}

void TestBF()
{
    HString parent;
    HString child;
    StrAssign_HeapString(&parent,"ABC ADS DSASADD");
    StrAssign_HeapString(&child,"ADa");
    printf("匹配结果: %d\n",BFCompare(&parent,&child,1));
}

void TestSeqString()
{
   // HString str;  //不使用*是因为要另外分配内存,若要使用则需要free(str)
    HString * str=(HString *)malloc(sizeof(HString));
    int flag1=StrAssign_HeapString(str,"abcdfg");
    PrintHeapString(str);

    HString * str1=(HString *)malloc(sizeof(HString));
    int flag=StrCopy_HeapString(str1,str);
    printf("\n复制后的str1: ");
    PrintHeapString(str1);
    printf("\n");

    StrAssign_HeapString(str1,"abdgdd");
    printf("str str1比较结果:%d\n",StrCompare_HeapString(str,str1));

    HString * str2=(HString *)malloc(sizeof(HString));
    Concat_HeapString(str2,str1,str);
    printf("连接操作: \n");
    PrintHeapString(str2);

    HString * str3=(HString *)malloc(sizeof(HString));
    SubString_HeapString(str3,str2,3,3);
    printf("\n截取操作: \n");
    PrintHeapString(str3);

    printf("\nstr3在str2是从%d位置开始截取的 ",Index_HeapString(str2,str3,1));

    printf("\n删除操作: \n");
    Delete_HeapString(str3,1,2);
    PrintHeapString(str3);

    printf("\n插入操作: \n");
    Insert_HeapString(str2,str3,2);
    PrintHeapString(str3);

    printf("\n替换操作: \n");

    free(str3);
    free(str2);
    free(str1);
    free(str);
}
