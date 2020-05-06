#include <stdio.h>
#include <stdlib.h>
#include "SeqString.h"

void TestSeqString();

void TestBF();

void TestKMP();

void TestVirus();
/**������⺯��,����1��ʾ��Ⱦ,����0��ʾδ��Ⱦ*/
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
    char tempVirus[child.length*2+1];//Ԥ��һ��\0��λ��
    for(int i=0;i<child.length*2;i++){
        tempVirus[i]=child.ch[i%child.length];
    }
    tempVirus[child.length*2]='\0';

    for(int i=0;i<child.length;i++){
        //ÿ��ȡ����Ϊ�ִ����ȵĴ����бȽ�
        char virus[child.length+1];
        for(int j=i;j<i+child.length;j++){
            virus[j-i]=tempVirus[j];
        }
        virus[child.length]='\0';
        //ת���ɶѴ�,������ƥ��
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
    //������Ⱦ���
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
    printf("����DNA����: ");
    for(int i=0;i<10;i++){
        PrintHeapString(&persons_h[i]);
        printf(", ");
    }
    printf("\n");
    printf("����DNA����: ");
        for(int i=0;i<10;i++){
        PrintHeapString(&persons_h[i]);
        printf(", ");
    }
    printf("\n");

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Virus_Check(persons_h[i],virus_h[j])){
                printf("�������DNA:%s\tƥ��Ĳ���DNA:%s\n",persons[i],virus[j]);
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
    printf("ƥ����: %d\n",KMPCompare(&parent,&child,1));
}

void TestBF()
{
    HString parent;
    HString child;
    StrAssign_HeapString(&parent,"ABC ADS DSASADD");
    StrAssign_HeapString(&child,"ADa");
    printf("ƥ����: %d\n",BFCompare(&parent,&child,1));
}

void TestSeqString()
{
   // HString str;  //��ʹ��*����ΪҪ��������ڴ�,��Ҫʹ������Ҫfree(str)
    HString * str=(HString *)malloc(sizeof(HString));
    int flag1=StrAssign_HeapString(str,"abcdfg");
    PrintHeapString(str);

    HString * str1=(HString *)malloc(sizeof(HString));
    int flag=StrCopy_HeapString(str1,str);
    printf("\n���ƺ��str1: ");
    PrintHeapString(str1);
    printf("\n");

    StrAssign_HeapString(str1,"abdgdd");
    printf("str str1�ȽϽ��:%d\n",StrCompare_HeapString(str,str1));

    HString * str2=(HString *)malloc(sizeof(HString));
    Concat_HeapString(str2,str1,str);
    printf("���Ӳ���: \n");
    PrintHeapString(str2);

    HString * str3=(HString *)malloc(sizeof(HString));
    SubString_HeapString(str3,str2,3,3);
    printf("\n��ȡ����: \n");
    PrintHeapString(str3);

    printf("\nstr3��str2�Ǵ�%dλ�ÿ�ʼ��ȡ�� ",Index_HeapString(str2,str3,1));

    printf("\nɾ������: \n");
    Delete_HeapString(str3,1,2);
    PrintHeapString(str3);

    printf("\n�������: \n");
    Insert_HeapString(str2,str3,2);
    PrintHeapString(str3);

    printf("\n�滻����: \n");

    free(str3);
    free(str2);
    free(str1);
    free(str);
}
