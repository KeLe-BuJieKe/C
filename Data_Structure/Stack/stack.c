#include"stack.h"


//��̬����ĳ�ʼ��
void StackInit(stack* pst)
{
	assert(pst != NULL);
	pst->_array = (StackDataType*)malloc(sizeof(StackDataType) * 4);
	if (pst->_array == NULL)
	{
		printf("��ʼ��ʧ��\n");
		exit(-1);
	}
	pst->_capacity = 4;
	pst->_top = 0;
}

//����
void StackDestory(stack* pst)
{
	free(pst->_array);
	pst->_array = NULL;
	pst->_top = 0;
	pst->_capacity = 0;
}

//��ջ
void StackPush(stack* pst, const StackDataType x)
{
	assert(pst != NULL);
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;	//����������ԭ���Ķ���
		StackDataType* temp = (StackDataType*)realloc(pst->_array, sizeof(StackDataType) * pst->_capacity);
		if (temp == NULL)	//�������ʧ�����˳�����
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		else
		{
			pst->_array = temp;
		}
	}

	pst->_array[pst->_top] = x;
	pst->_top++;
}

//��ջ
void StackPop(stack* pst)
{
	assert(pst != NULL);
	assert(pst->_top > 0);
	--pst->_top;
}

//��ȡ���ݵĸ���
int StackSize(stack* pst)
{
	assert(pst != NULL);
	return pst->_top;
}

//�п�
//����true�ǿգ�����falseΪ�ǿ�
bool StackEmpty(stack* pst)
{
	assert(pst != NULL);
	if (pst->_top == 0)
	{
		return true;
	}
	return false;
}


//��ȡջ��Ԫ��
StackDataType StackTop(stack* pst)
{
	assert(pst != NULL);
	assert(pst->_top > 0);
	return pst->_array[pst->_top - 1];
}