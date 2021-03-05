#include"DList.h"

//�����½��
struct DList* CreatDListNode(const DListDataType x)
{
	struct DList* newNode = (struct DList*)malloc(sizeof(struct DList));
	if (NULL == newNode)
	{
		//�������ʧ�ܣ�ֱ�ӱ����˳�
		exit(0);
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	return newNode;
}


//��ʼ��
struct DList* InitDList()
{
	//����ͷ��㣬����prev��nextָ���Լ����γ�˫��ѭ������
	struct DList* phead = CreatDListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//����
void DListClear(struct DList* phead)
{
	assert(phead != NULL);
	//�����������ݽ�㣬����ͷ��㣬���Լ���ʹ��
	struct DList* cur = phead->next;
	while (cur != phead)
	{
		struct DList* ToDelete = cur;
		cur = cur->next;
		free(ToDelete);
		ToDelete = NULL;
	}
	phead->next = phead;
	phead->prev = phead;
}

//����
void DListDestory(struct DList** phead)
{
	assert(*phead != NULL);
	DListClear(*phead);
	free(*phead);
	*phead = NULL;
}



//��������
void DListPrint(const struct DList* phead)
{
	assert(phead!= NULL);
	struct DList* cur = phead->next;
	printf("phead->");
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("phead\n");
}



//β��
void DListPushBack(struct DList* phead,const DListDataType x)
{
	assert(phead != NULL);
	struct DList* newNode = CreatDListNode(x);
	struct DList* tail = phead->prev;

	//�Ȱ�ԭ�������������nextָ���½��
	tail->next = newNode;
	//�ٰ��½���prevָ��ԭ����������Ľ��
	newNode->prev = tail;

	//��ͷָ���prevָ���½��
	phead->prev = newNode;
	//�ٰ��½���next��ָ��ͷ���
	newNode->next = phead;
}


//βɾ
void DListPopBack(struct DList* phead)
{
	assert(phead != NULL);
	//��phead��nextָ���Լ�ʱ���Ͳ���ɾ��
	assert(phead->next != phead);


	struct DList* ToDelete = phead->prev;	//ָ��ɾ����λ��
	struct DList* tail = ToDelete->prev;	//ָ�򼴽���Ϊβ��λ��

	phead->prev = tail;
	tail->next = phead;

	free(ToDelete);
	ToDelete = NULL;
}


//ͷ��
void DListPushFront(struct DList* phead, const DListDataType x)
{
	assert(phead != NULL);
	struct DList* first = phead->next;
	struct DList* newNode = CreatDListNode(x);

	//��ͷ����nextָ���´����Ľ�㣬�ٰ��´����Ľ���nextָ��ԭ����һ�����
	phead->next = newNode;
	newNode->next = first;
	
	//��ԭ����һ������prevָ���´����Ľ�㣬�ٰ��´�������prevָ��ͷ���
	first->prev = newNode;
	newNode->prev = phead;
}


//ͷɾ
void DListPopFront(struct DList* phead)
{
	assert(phead != NULL);
	//��phead��nextָ���Լ�ʱ���Ͳ���ɾ��
	assert(phead->next != phead);


	struct DList* ToDelete = phead->next;		//ָ��ɾ����λ��
	struct DList* first = ToDelete->next;		//ָ�򼴽���Ϊͷ��λ��

	phead->next = first;
	first->prev = phead;

	free(ToDelete);
	ToDelete = NULL;
}


//����
struct DList*DListFind(struct DList* phead, const DListDataType x)
{
	assert(phead != NULL);
	struct DList* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//��x��ǰ�����
void DListInsert(struct DList* phead, const DListDataType y,const DListDataType x)
{
	assert(phead != NULL);
	struct DList* pos = DListFind(phead, y);
	if (pos != NULL)
	{
		struct DList* pos_prev = pos->prev;
		struct DList* newNode = CreatDListNode(x);

		pos_prev->next = newNode;
		newNode->prev = pos_prev;

		newNode->next = pos;
		pos->prev = newNode;
	}
	else
	{
		printf("����ʧ��\n");
	}
}


//ɾ��x��λ��	
void DListErase(struct DList* phead, const DListDataType x)
{
	assert(phead != NULL);
	struct DList* pos = DListFind(phead, x);
	if(pos != NULL)
	{
		struct DList* posNext = pos->next;
		struct DList* posPrev = pos->prev;


		posPrev->next = posNext;
		posNext->prev = posPrev;
		free(pos);
		pos=NULL;
	}
	else
	{
		printf("ɾ��ʧ��\n");
	}
}