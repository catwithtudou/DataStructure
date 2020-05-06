#include "SeStack.h"

/**初始化栈*/
void InitSeqStack(SeqStack * seqStack)
{
    seqStack->top=-1;//栈顶指向-1的下标
    seqStack->length=0;
}

/**向栈中压入元素,返回压入的结构(True1,False0)*/
int PushSeqStack(SeqStack * seqStack,ElementType element)
{
    if(seqStack->top==MAX_SIZE-1){
        printf("满栈,压栈操作失败!\n");
        return FALSE;
    }
    //栈顶指针++,以便加入新的元素
    seqStack->top++;
    //将新插入的元素赋值给栈顶
    seqStack->elements[seqStack->top]=element;
    seqStack->length++;
    return TRUE;
}

/**以指针方式返回出栈的元素,返回值为出栈的结果*/
int PopSeqStack(SeqStack * seqStack,ElementType * element)
{
    if(seqStack->top==-1){
        printf("空栈,出栈失败!\n");
        return FALSE;
    }
    //返回栈顶指向的元素
    *element=seqStack->elements[seqStack->top];
    seqStack->top--;
    seqStack->length--;
    return TRUE;
}

/**清空栈*/
void ClearSeqStack(SeqStack * seqStack)
{
    seqStack->top=-1;
    seqStack->length=0;
}

/**返回栈顶元素*/
void GetSeqStackTopElement(SeqStack * seqStack,ElementType * element)
{
    if(seqStack->top==-1){
        printf("空栈,出栈失败!\n");
        return;
    }
    *element=seqStack->elements[seqStack->top];
}
