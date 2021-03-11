#define _CRT_SECURE_NO_WARNINGS 1
/*20. ��Ч������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺�����ű�������ͬ���͵������űպϡ������ű�������ȷ��˳��պϡ�
ʾ�� 1��
���룺s = "()"
�����true
ʾ�� 2��
���룺s = "()[]{}"
�����true
ʾ�� 3��
���룺s = "(]"
�����false
ʾ�� 4��
���룺s = "([)]"
�����false
ʾ�� 5��
���룺s = "{[]}"
�����true
���ӣ�https://leetcode-cn.com/problems/valid-parentheses/*/
/*
#include<stdio.h>
#include<stdlib.h>
typedef char StackDataType;
typedef struct Stack
{
	StackDataType* _array;	//��̬����
	int _top;			//ջ���±�
	int	_capacity;		//������С
}stack;
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

//��ȡջ��Ԫ��
StackDataType StackTop(stack* pst)
{
	assert(pst != NULL);
	assert(pst->_top > 0);
	return pst->_array[pst->_top - 1];
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

bool isValid(char * s)
{
	stack st;
	StackInit(&st);
	bool temp;
	while(*s!='\0')
	{
		if(*s=='('||*s=='['||*s=='{')
		{
			StackPush(&st,*s);
		}
		else
		{
			if(StackEmpty(&st))
			{
				temp=false;
				break;
			}
			char top=StackTop(&st);

			if(top!='['&&*s==']')
			{
				temp=false;
				break;
			}
			if(top!='('&&*s==')')
			{
				temp=false;
				break;
			}
			if(top!='{'&&*s=='}')
			{
				temp=false;
				break;
			}
			StackPop(&st);
		}
		s++;
	}
	if(*s=='\0')
	{
		temp=StackEmpty(&st);
	}
	StackDestory(&st);
	return temp;

}
*/


