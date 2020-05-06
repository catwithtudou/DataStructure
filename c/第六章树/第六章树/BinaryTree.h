#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

/**
*    ����������ʾ��
*    ���������ʵ��
*/

#include "TreeNode.h"
#include <string.h>

/** �������� */
typedef struct {
    TreeNode * root;     //�������ĸ����
    int length;          //���������������
    int depth;           //������������
    int diameter;        //ֱ�� - ��Ҷ��㵽Ҷ�����·��(ĳЩ���Ի��漰)
}BinaryTree;

/** ��ʼ���ն����� */
void InitBinaryTree(BinaryTree * tree);

/** ��������� - �ⲿ��Ҫ���ȶԽ������ڴ�(����0��ʾ����ʧ��) */
int CreateBinaryTree(TreeNode * root);

/** ǰ�����: Ҳ�����ȸ����������������ǰ������;Ҳ���Լ�����-��-��*/
void PreOrderTraverse(TreeNode * node);

/** ���԰�Ĵ������� */
int CreateBinaryTree_Test(TreeNode * root);

/**�������:Ҳ�����и�������;Ҳ���Լ�����-��-��*/
void InOrderTraverse(TreeNode * node);

/** �ǵݹ鷽ʽ���������*/
void InOrederTraverse_Re(TreeNode * node);

/** �������:Ҳ�������������;Ҳ���Լ�����-��-��*/
void PostOrderTraverse(TreeNode * node);

/** ��α���:����Ҫ�ݹ�,����ʱ��Ҫ�õ����� */
void ZorderTraverse(TreeNode * node);
#endif // BINARYTREE_H_INCLUDED
