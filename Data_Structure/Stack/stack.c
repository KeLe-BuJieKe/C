#include"stack.h"


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

//获取数据的个数
int StackSize(stack* pst)
{
	assert(pst != NULL);
	return pst->_top;
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


//获取栈顶元素
StackDataType StackTop(stack* pst)
{
	assert(pst != NULL);
	assert(pst->_top > 0);
	return pst->_array[pst->_top - 1];
}