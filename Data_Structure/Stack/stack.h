#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int StackDataType;
typedef struct Stack
{
	StackDataType* _array;	//��̬����
	int _top;			//ջ���±�
	int	_capacity;		//������С
}stack;

//��̬����ĳ�ʼ��
void StackInit(stack* pst);

//����
void StackDestory(stack* pst);

//��ջ
void StackPush(stack* pst, const StackDataType x);

//��ջ
void StackPop(stack* pst);

//��ȡ���ݵĸ���
int StackSize(stack* pst);

//�п�
//����true�ǿգ�����falseΪ�ǿ�
bool StackEmpty(stack* pst);

//��ȡջ��Ԫ��
StackDataType StarkTop(stack* pst);