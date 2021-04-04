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


/*225. �ö���ʵ��ջ
�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨ���е�ȫ�����ֲ�����push��top��pop �� empty����
ʵ�� MyStack �ࣺ
void push(int x) ��Ԫ�� x ѹ��ջ����
int pop() �Ƴ�������ջ��Ԫ�ء�
int top() ����ջ��Ԫ�ء�
boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
ע�⣺
��ֻ��ʹ�ö��еĻ������� ���� Ҳ���� push to back��peek/pop from front��size �� is empty ��Щ������
����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���б����� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�
ʾ����
���룺
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
�����
[null, null, null, 2, 2, false]
���ͣ�
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // ���� 2
myStack.pop(); // ���� 2
myStack.empty(); // ���� False
���ӣ�https://leetcode-cn.com/problems/implement-stack-using-queues/*/

/*
typedef int QueueDataType;
typedef struct QueueNode
{
	//������
	QueueDataType _data;

	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	//��ͷָ��
	QueueNode* _head;

	//��βָ��
	QueueNode* _tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pQ)
{
	assert(pQ != NULL);
	pQ->_head = NULL;
	pQ->_tail = NULL;
}

//����
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

//���
void QueuePush(Queue* pQ, const QueueDataType x)
{
	assert(NULL != pQ);
	//����һ���µĽ�㣬������ֵ
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("����ռ�ʧ��\n");
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

//����
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

//ȡ��ͷԪ��
QueueDataType QueueFront(Queue* pQ)
{
	assert(pQ != NULL);
	assert(pQ->_head != NULL);
	return pQ->_head->_data;
}

//ȡ��βԪ��
QueueDataType QueueBack(Queue* pQ)
{
	assert(pQ != NULL);
	assert(pQ->_tail != NULL);
	return pQ->_tail->_data;
}

//�ж϶��Ƿ�Ϊ�գ�true��ʾ��Ϊ�գ�false��ʾ�Ӳ���
bool QueueEmpty(Queue* pQ)
{
	assert(pQ != NULL);
	if (pQ->_head == NULL)
	{
		return true;
	}
	return false;
}

//����Ԫ�صø���
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