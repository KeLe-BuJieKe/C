#include"Queue.h"

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