#ifndef STATUSLIB_H_INCLUDED
#define STATUSLIB_H_INCLUDED

/**
*       �����´�ʾ��
*       �γ����״̬�뼰�꺯���Ķ���
*/

#include <stdio.h>
#include <stdlib.h>

/** ״̬�� */
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define EQ 0   //=
#define GT 1   //>
#define LT -1  //<
#ifndef STATUS_H_  //��ϵͳ���Ѿ�������״̬��Ķ���,�Ͳ����ظ�����
#define OVERFLOW  -2  //��ջ���� �������ܱ�ʾ���������
#define UNDERFLOW -3  //��ջ���� �������ܱ�ʾ����С����
#endif // STATUS_H_

typedef int Status; //�Զ���һ��״̬��ʶ������




#endif // STATUSLIB_H_INCLUDED
