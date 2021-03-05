#include"SList.h"

// �������ӡ
void SListPrint(const struct SListNode** pplist)
{
	struct SListNode**cur =pplist;
	while ((*cur)!=NULL)
	{
		printf("%d->",(*cur)->data);
		cur = &(*cur)->next;
	}
	printf("NULL\n");
}

//�����½��
struct SListNode* CreatSListNode(const SListDataType x)
{
	struct SListNode* newNode = (struct SListNode*)malloc(sizeof(struct SListNode));
	if (NULL == newNode)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}


// ������β��
void SListPushBack(struct SListNode** pplist, const SListDataType x)
{
	struct SListNode* newNode = CreatSListNode(x);
	if (*pplist == NULL)	//������������ǿ�ָ�룬��ֱ�Ӵ����½������
	{
		*pplist = newNode;
	}
	else
	{
		//�����������Ԫ�أ����ǿ�ָ�룬��ѭ�������������һ��Ԫ�أ��������½������
		struct SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

// �������βɾ
void SListPopBack(struct SListNode** pplist)
{
	if (NULL == *pplist)
	{
		return;
	}
	else if (NULL == (*pplist)->next)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		struct SListNode* tail = *pplist;	//��¼Ҫɾ����ָ���ַ
		struct SListNode* prev = NULL;		//��¼tail��ǰһ��ָ��ĵ�ַ
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		//��ɾ����ǰһ��λ�õ�next��ΪNULL
		prev->next = NULL;
	}
}



// �������ͷ��
void SListPushFront(struct SListNode**pplist,const SListDataType x)
{
	struct SListNode* newNode = CreatSListNode(x);
	if (NULL == (*pplist))	
	{
		*pplist = newNode;
	}
	else
	{
		newNode->next = (*pplist);
		*pplist = newNode;
	}

	//������д����ʵд�����о��У�����ķ������Լ����
	//	���ͷ���ΪNULL�Ļ���newNode->nextֱ�Ӱ�����ֵΪNULL����Ϊ��ʱ��ֻ��һ��Ԫ��
	//	newNode->next = (*pplist);
	//	*pplist = newNode;
}


// ������ͷɾ
void SListPopFront(struct SListNode** pplist) 
{
	if (NULL == (*pplist))
	{
		return;
	}
	else
	{
		struct  SListNode* head =*pplist;
		*pplist=(*pplist)->next;
		free(head);
		head = NULL;
	}
}


// ���������
struct SListNode* SListFind(struct SListNode*plist,const SListDataType x)
{
	struct SListNode* cur = plist;
	while (NULL != cur)
	{
		if (cur->data== x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}



//�������޸�
//��Modify_value�޸�Ϊtarget_value
void SListModify(struct SListNode** pplist, const SListDataType Modify_value, const SListDataType target_value)
{
	struct SListNode* pos=SListFind(*pplist, Modify_value);
	if (pos != NULL)
	{
		pos->data = target_value;
	}
	else
	{
		printf("�޸�ʧ��\n");
	}
}


//��������posλ��֮�����x
void SListInsertAfter(struct SListNode* pos, const SListDataType x)
{
	assert(NULL != pos);
	struct SListNode* newNode = CreatSListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}


//������ɾ��posλ��֮���ֵ
void SListEraseAfter(struct SListNode* pos)
{
	assert(NULL != pos);
	if (pos->next != NULL)
	{
		struct SListNode* next = pos->next;
		struct SListNode* next_next = next->next;
		pos->next = next_next;
		free(next);
		next = NULL;
	}
}
