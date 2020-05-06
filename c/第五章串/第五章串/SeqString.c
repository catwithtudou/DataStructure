#include"SeqString.h"


/**初始化堆字符串*/
void InitString_HeapString(HString * str)
{
    str->ch=NULL;
    str->length=0;
}

/**为串str赋值,值为字符串常量chars*/
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


/**为串srcStr中的内容复制到串destStr中*/
Status StrCopy_HeapString(HString *destStr,HString * srcStr)
{
    InitString_HeapString(destStr);
    if(IsEmpty_HeapString(srcStr)){
        printf("要复制的字符串srcStr不能为空!\n");
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

/**比较两个堆字符串的大小:str1==str2 返回0 : < -1 : > 1*/
Status StrCompare_HeapString(HString * str1,HString * str2)
{
    for(int i=0;i<str1->length&&i<str2->length;i++){
        //遇到不同的字符就直接比较ASCII码
        if(str1->ch[i]!=str2->ch[i]){
            if(str1->ch[i]>str2->ch[i])return GT;
            else return LT;
        }
    }
    //字符都相等但长度不等,就比较长度
    return str1->length-str2->length;
}

/**连接两个字符串,连接的结果以串destStr返回*/
Status Concat_HeapString(HString * destStr,HString * str1,HString * str2)
{
     InitString_HeapString(destStr);
     destStr->length=str1->length+str2->length;
     destStr->ch=(char *)malloc(sizeof(char)* destStr->length);
     if(!destStr->ch){
        exit(OVERFLOW);
     }
     //复制第一个串
     for(int i=0;i<str1->length;i++){
        destStr->ch[i]=str1->ch[i];
     }
     //复制第二个串
     for(int i=0;i<str2->length;i++){
        destStr->ch[i+str1->length]=str2->ch[i];
     }
     return OK;
}


/**在pos位置处截取len长度的字符串到串destStr*/
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

/** 返回从Pos位置开始的子串child在父串parent中的位置*/
int Index_HeapString(HString * parent,HString * child,int pos)
{
    if(pos<0) return 0;
    HString * subString=(HString *)malloc(sizeof(HString));
    InitString_HeapString(subString);
    int i=pos;  //记录起始的位置
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

/**从Pos位置处删除长度len*/
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
    //缩小分配空间
    str->ch=(char *)realloc(str->ch,str->length*sizeof(char));
    return OK;
}


/**向指定的位置插入串insertStr */
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

/**将串str中的oldStr替换成newStr*/
Status Replace_HeapString(HString * str,HString old,HString newStr)
{
    if(IsEmpty_HeapString(str)) return ERROR;
    //从第一个位置查找到oldStr的位置
    int pos=Index_HeapString(str,&old,1);
    while(pos!=0){
        Delete_HeapString(str,pos,old.length);
        Insert_HeapString(&newStr,str,pos);
        pos+=newStr.length;
        pos=Index_HeapString(str,&old,pos);
    }
    return OK;
}

/**清空堆字符串*/
Status ClearString_HeapString(HString * str)
{
     if(str->length==0||!str->ch){
        return TRUE;
     }
     return FALSE;
}


/**打印堆字符串*/
void PrintHeapString(HString * str)
{
    if(!str->ch||!str->length){
        printf("堆字符串为空!\n");
        return;
    }
    for(int i=0;i<str->length;i++){
        printf("%c",str->ch[i]);
    }
}

/**BF算法*/
int BFCompare(HString * parent,HString * child,int pos)
{
    int i=pos;    //用于主串parent中的起始位置
    int j=1;      //用于字串child中的起始位置
    while(i<=parent->length&&j<=child->length){
        if(parent->ch[i-1]==child->ch[j-1]){
            i++;
            j++;
        }else{
            i=i-j+2;   //i回溯到上次匹配的首位的下一位
            j=1;
        }
    }
    if(j>child->length){
        return i-child->length;
    }
    return 0;
}

/**返回Next数组(部分匹配表)*/
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

/**KMP算法*/
int KMPCompare(HString * parent,HString * child,int pos)
{
    int next[255];  //用来存放部分匹配值
    Get_Next(*child,next);//首先处理字串,计算出部分匹配值
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





