#include"SeqString.h"


/**��ʼ�����ַ���*/
void InitString_HeapString(HString * str)
{
    str->ch=NULL;
    str->length=0;
}

/**Ϊ��str��ֵ,ֵΪ�ַ�������chars*/
Status StrAssign_HeapString(HString * str,char * chars)
{
    int len=strlen(chars);
    if(!len){
        return ERROR;
    }
    InitString_HeapString(str);
    str->ch=(HString *)malloc(len*sizeof(HString));
    if(!str->ch){
        exit(OVERFLOW);
    }
    for(int i=0;i<len;i++){
        str->ch[i]= chars[i];
    }
    str->length=len;
    return OK;
}


/**Ϊ��srcStr�е����ݸ��Ƶ���destStr��*/
Status StrCopy_HeapString(HString *destStr,HString * srcStr)
{
    InitString_HeapString(destStr);
    if(IsEmpty_HeapString(srcStr)){
        printf("Ҫ���Ƶ��ַ���srcStr����Ϊ��!\n");
        return ERROR;
    }
    destStr->ch=(char *)malloc(srcStr->length*sizeof(char));
    if(!destStr->ch){
        exit(OVERFLOW);
    }
    for(int i=0;i<srcStr->length;i++){
        destStr->ch[i]=srcStr->ch[i];
    }
    destStr->length=srcStr->length;
    return OK;
}

Status IsEmpty_HeapString(HString * str)
{
    if(str->length==0||!str->ch){
        return TRUE;
    }
    return FALSE;
}

/**�Ƚ��������ַ����Ĵ�С:str1==str2 ����0 : < -1 : > 1*/
Status StrCompare_HeapString(HString * str1,HString * str2)
{
    for(int i=0;i<str1->length&&i<str2->length;i++){
        //������ͬ���ַ���ֱ�ӱȽ�ASCII��
        if(str1->ch[i]!=str2->ch[i]){
            if(str1->ch[i]>str2->ch[i])return GT;
            else return LT;
        }
    }
    //�ַ�����ȵ����Ȳ���,�ͱȽϳ���
    return str1->length-str2->length;
}

/**���������ַ���,���ӵĽ���Դ�destStr����*/
Status Concat_HeapString(HString * destStr,HString * str1,HString * str2)
{
     InitString_HeapString(destStr);
     destStr->length=str1->length+str2->length;
     destStr->ch=(char *)malloc(sizeof(char)* destStr->length);
     if(!destStr->ch){
        exit(OVERFLOW);
     }
     //���Ƶ�һ����
     for(int i=0;i<str1->length;i++){
        destStr->ch[i]=str1->ch[i];
     }
     //���Ƶڶ�����
     for(int i=0;i<str2->length;i++){
        destStr->ch[i+str1->length]=str2->ch[i];
     }
     return OK;
}


/**��posλ�ô���ȡlen���ȵ��ַ�������destStr*/
Status SubString_HeapString(HString *destStr,HString * str,int pos, int len)
{
    InitString_HeapString(destStr);
    if(IsEmpty_HeapString(str)){
        return ERROR;
    }
    if(pos<1||pos>str->length||len<0||(pos+len-1)>str->length){
        return ERROR;
    }
    destStr->ch=(char *)malloc(sizeof(char)*len);
    if(!destStr->ch){
        exit(OVERFLOW);
    }
    for(int i=0;i<len;i++){
        destStr->ch[i]=str->ch[pos-1+i];
    }
    destStr->length=len;
    return OK;
}

/** ���ش�Posλ�ÿ�ʼ���Ӵ�child�ڸ���parent�е�λ��*/
int Index_HeapString(HString * parent,HString * child,int pos)
{
    if(pos<0) return 0;
    HString * subString=(HString *)malloc(sizeof(HString));
    InitString_HeapString(subString);
    int i=pos;  //��¼��ʼ��λ��
    while((i+child->length-1)<=parent->length){
        SubString_HeapString(subString,parent,i,child->length);
        if(StrCompare_HeapString(subString,child)!=EQ){
            i++;
        }else{
            return i;
        }
    }
    free(subString);
    return 0;
}

/**��Posλ�ô�ɾ������len*/
Status Delete_HeapString(HString * str,int pos,int len)
{
    if(IsEmpty_HeapString(str))return ERROR;
    if(pos<1||pos+len-1>str->length||len<0){
        return ERROR;
    }
    for(int i=pos-1;i+len<str->length;i++){
        str->ch[i]=str->ch[i+len];
    }
    str->length-=len;
    //��С����ռ�
    str->ch=(char *)realloc(str->ch,str->length*sizeof(char));
    return OK;
}


/**��ָ����λ�ò��봮insertStr */
Status Insert_HeapString(HString * insertStr,HString * str,int pos)
{
    if(pos<1||pos>str->length+1)return ERROR;
    if(IsEmpty_HeapString(str)) return ERROR;
    str->ch=(char *)realloc(str->ch,sizeof(str->length+insertStr->length));
    if(!str->ch) exit(OVERFLOW);
    for(int i=str->length-1;i>=pos-1;i--){
        str->ch[i+insertStr->length]=str->ch[i];
    }
    for(int i=0;i<insertStr->length;i++){
        str->ch[i+pos-1]=insertStr->ch[i];
    }
    str->length+=insertStr->length;
    return OK;
}

/**����str�е�oldStr�滻��newStr*/
Status Replace_HeapString(HString * str,HString old,HString newStr)
{
    if(IsEmpty_HeapString(str)) return ERROR;
    //�ӵ�һ��λ�ò��ҵ�oldStr��λ��
    int pos=Index_HeapString(str,&old,1);
    while(pos!=0){
        Delete_HeapString(str,pos,old.length);
        Insert_HeapString(&newStr,str,pos);
        pos+=newStr.length;
        pos=Index_HeapString(str,&old,pos);
    }
    return OK;
}

/**��ն��ַ���*/
Status ClearString_HeapString(HString * str)
{
     if(str->length==0||!str->ch){
        return TRUE;
     }
     return FALSE;
}


/**��ӡ���ַ���*/
void PrintHeapString(HString * str)
{
    if(!str->ch||!str->length){
        printf("���ַ���Ϊ��!\n");
        return;
    }
    for(int i=0;i<str->length;i++){
        printf("%c",str->ch[i]);
    }
}

/**BF�㷨*/
int BFCompare(HString * parent,HString * child,int pos)
{
    int i=pos;    //��������parent�е���ʼλ��
    int j=1;      //�����ִ�child�е���ʼλ��
    while(i<=parent->length&&j<=child->length){
        if(parent->ch[i-1]==child->ch[j-1]){
            i++;
            j++;
        }else{
            i=i-j+2;   //i���ݵ��ϴ�ƥ�����λ����һλ
            j=1;
        }
    }
    if(j>child->length){
        return i-child->length;
    }
    return 0;
}

/**����Next����(����ƥ���)*/
void Get_Next(HString  child,int * next)
{
    int i=0;
    int j=-1;
    next[0]= -1;
    while(i<child.length){
        if(j==-1||child.ch[i]==child.ch[j]){
            ++i;
            ++j;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}

/**KMP�㷨*/
int KMPCompare(HString * parent,HString * child,int pos)
{
    int next[255];  //������Ų���ƥ��ֵ
    Get_Next(*child,next);//���ȴ����ִ�,���������ƥ��ֵ
    int i=pos-1;
    int j=0;
    while(i<parent->length&&j<child->length){
        if(j==-1||parent->ch[i]==child->ch[j]){
            ++i;
            ++j;
        }else{
            j=next[j];
        }
    }
    if(j==child->length){
        return (i+1)-j;
    }
    return 0;
}





