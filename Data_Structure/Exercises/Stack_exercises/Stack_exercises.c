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


/*225. 用队列实现栈
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。
实现 MyStack 类：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
注意：
你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
示例：
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]
解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
链接：https://leetcode-cn.com/problems/implement-stack-using-queues/*/

/*
typedef int QueueDataType;
typedef struct QueueNode
{
	//数据域
	QueueDataType _data;

	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	//队头指针
	QueueNode* _head;

	//队尾指针
	QueueNode* _tail;
}Queue;

//初始化
void QueueInit(Queue* pQ)
{
	assert(pQ != NULL);
	pQ->_head = NULL;
	pQ->_tail = NULL;
}

//销毁
void QueueDestory(Queue* pQ)
{
	assert(NULL != pQ);

	while (NULL != pQ->_head)
	{
		QueueNode* next = pQ->_head->_next;
		free(pQ->_head);
		pQ->_head = next;
	}
	pQ->_head = NULL;
	pQ->_tail = NULL;
}

//入队
void QueuePush(Queue* pQ, const QueueDataType x)
{
	assert(NULL != pQ);
	//创建一个新的结点，并赋予值
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("分配空间失败\n");
		exit(-1);
	}
	else
	{
		newNode->_data = x;
		newNode->_next = NULL;
	}


	if (pQ->_head == NULL)
	{
		pQ->_head = pQ->_tail = newNode;
	}
	else
	{
		pQ->_tail->_next = newNode;
		pQ->_tail = newNode;
	}
}

//出队
void QueuePop(Queue* pQ)
{
	assert(pQ!=NULL);
	assert(pQ->_head != NULL);
	QueueNode* next = pQ->_head->_next;
	free(pQ->_head);
	pQ->_head= next;
	if (pQ->_head == NULL)
	{
		 pQ->_tail = NULL;
	}
}

//取队头元素
QueueDataType QueueFront(Queue* pQ)
{
	assert(pQ != NULL);
	assert(pQ->_head != NULL);
	return pQ->_head->_data;
}

//取队尾元素
QueueDataType QueueBack(Queue* pQ)
{
	assert(pQ != NULL);
	assert(pQ->_tail != NULL);
	return pQ->_tail->_data;
}

//判断队是否为空，true表示队为空，false表示队不空
bool QueueEmpty(Queue* pQ)
{
	assert(pQ != NULL);
	if (pQ->_head == NULL)
	{
		return true;
	}
	return false;
}

//队中元素得个数
int QueueSize(Queue* pQ)
{
	assert(pQ != NULL);
	QueueNode* cur = pQ->_head;
	int size = 0;
	while (cur!=NULL)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

typedef struct
{
	Queue _Q1;
	Queue _Q2;
} MyStack;

// Initialize your data structure here.

MyStack* myStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_Q1);
	QueueInit(&st->_Q2);
	return st;
}

// Push element x onto stack. 
void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->_Q1))
	{
		QueuePush(&obj->_Q1, x);
	}
	else
	{
		QueuePush(&obj->_Q2, x);
	}
}

// Removes the element on top of the stack and returns that element.
int myStackPop(MyStack* obj)
{
	Queue* empty = &obj->_Q1;
	Queue* Noempty = &obj->_Q2;
	if (QueueEmpty(&obj->_Q2))
	{
		empty = &obj->_Q2;
		Noempty = &obj->_Q1;
	}

	while (QueueSize(Noempty) > 1)
	{
		QueuePush(empty, QueueFront(Noempty));
		QueuePop(Noempty);
	}
	int top = QueueFront(Noempty);
	QueuePop(Noempty);
	return top;
}

// Get the top element. 
int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->_Q1))
	{
		return QueueBack(&obj->_Q1);
	}
	else
	{
		return QueueBack(&obj->_Q2);
	}


}

//Returns whether the stack is empty.
bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->_Q1) && QueueEmpty(&obj->_Q2);
}

void myStackFree(MyStack* obj)
{
	QueueDestory(&obj->_Q1);
	QueueDestory(&obj->_Q2);
	free(obj);
}
*/