#include"Queue.h"

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