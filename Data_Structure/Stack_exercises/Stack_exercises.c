#define _CRT_SECURE_NO_WARNINGS 1
/*20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。
示例 1：
输入：s = "()"
输出：true
示例 2：
输入：s = "()[]{}"
输出：true
示例 3：
输入：s = "(]"
输出：false
示例 4：
输入：s = "([)]"
输出：false
示例 5：
输入：s = "{[]}"
输出：true
链接：https://leetcode-cn.com/problems/valid-parentheses/*/
/*
#include<stdio.h>
#include<stdlib.h>
typedef char StackDataType;
typedef struct Stack
{
	StackDataType* _array;	//动态数组
	int _top;			//栈顶下标
	int	_capacity;		//容量大小
}stack;
//动态数组的初始化
void StackInit(stack* pst)
{
	assert(pst != NULL);
	pst->_array = (StackDataType*)malloc(sizeof(StackDataType) * 4);
	if (pst->_array == NULL)
	{
		printf("初始化失败\n");
		exit(-1);
	}
	pst->_capacity = 4;
	pst->_top = 0;
}

//销毁
void StackDestory(stack* pst)
{
	free(pst->_array);
	pst->_array = NULL;
	pst->_top = 0;
	pst->_capacity = 0;
}

//入栈
void StackPush(stack* pst, const StackDataType x)
{
	assert(pst != NULL);
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;	//扩充容量至原来的二倍
		StackDataType* temp = (StackDataType*)realloc(pst->_array, sizeof(StackDataType) * pst->_capacity);
		if (temp == NULL)	//如果扩容失败则退出程序
		{
			printf("扩容失败\n");
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

//出栈
void StackPop(stack* pst)
{
	assert(pst != NULL);
	assert(pst->_top > 0);
	--pst->_top;
}

//获取栈顶元素
StackDataType StackTop(stack* pst)
{
	assert(pst != NULL);
	assert(pst->_top > 0);
	return pst->_array[pst->_top - 1];
}

//判空
//返回true是空，返回false为非空
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


