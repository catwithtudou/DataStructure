#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

/************************************************************************
 *  Project:
 *  Function: ����Ԫ��
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 255
#define MAX_SIZE 1024

typedef struct ElementType{
    int id;
    char name[NAME_SIZE];
}ElementType;
#endif // ELEMENT_H_INCLUDED
