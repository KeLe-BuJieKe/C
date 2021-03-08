#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int StackDataType;
typedef struct Stack
{
	StackDataType* _array;	//动态数组
	int _top;			//栈顶下标
	int	_capacity;		//容量大小
}stack;

//动态数组的初始化
void StackInit(stack* pst);

//销毁
void StackDestory(stack* pst);

//入栈
void StackPush(stack* pst, const StackDataType x);

//出栈
void StackPop(stack* pst);

//获取数据的个数
int StackSize(stack* pst);

//判空
//返回true是空，返回false为非空
bool StackEmpty(stack* pst);

//获取栈顶元素
StackDataType StarkTop(stack* pst);