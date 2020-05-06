#ifndef GRAPHMODEL_H_INCLUDED
#define GRAPHMODEL_H_INCLUDED

/**
 *    ������ͼ��ʾ��
 *    ͼ������ģ��
 */

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
#define INT_MAX 999
#define VISITED 1
#define UNVISITED 0

/** ͼ������ö��*/
typedef enum{
    DG,   //����ͼ
    UDG,  //����ͼ
    DN,   //������
    UDN   //������
}GraphKind;

/** ���ö������������Ϊ�ַ�����-ʹ��ʱ�ǵ÷����ڴ�*/
typedef char * VerTexType;

/** ����Ȩֵ����Ϊ����*/
typedef int ArcType;

/**  ���ص�״̬����*/
typedef int Status;

/** ����ÿ������ķ���״̬ 0-δ����;1-����*/
int visited[MAX_VERTEX];


#endif // GRAPHMODEL_H_INCLUDED
