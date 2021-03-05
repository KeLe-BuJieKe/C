#include"SList.h"

// 单链表打印
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

//创建新结点
struct SListNode* CreatSListNode(const SListDataType x)
{
	struct SListNode* newNode = (struct SListNode*)malloc(sizeof(struct SListNode));
	if (NULL == newNode)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}


// 单链表尾插
void SListPushBack(struct SListNode** pplist, const SListDataType x)
{
	struct SListNode* newNode = CreatSListNode(x);
	if (*pplist == NULL)	//如果传进来的是空指针，则直接创建新结点连接
	{
		*pplist = newNode;
	}
	else
	{
		//如果该里面有元素，不是空指针，则循环到该链表最后一个元素，并创建新结点连接
		struct SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

// 单链表的尾删
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
		struct SListNode* tail = *pplist;	//记录要删除的指针地址
		struct SListNode* prev = NULL;		//记录tail的前一个指针的地址
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		//把删除的前一个位置的next改为NULL
		prev->next = NULL;
	}
}



// 单链表的头插
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

	//更简洁的写法其实写这俩行就行，上面的方便我自己理解
	//	如果头结点为NULL的话，newNode->next直接把它赋值为NULL，因为此时它只有一个元素
	//	newNode->next = (*pplist);
	//	*pplist = newNode;
}


// 单链表头删
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


// 单链表查找
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



//单链表修改
//把Modify_value修改为target_value
void SListModify(struct SListNode** pplist, const SListDataType Modify_value, const SListDataType target_value)
{
	struct SListNode* pos=SListFind(*pplist, Modify_value);
	if (pos != NULL)
	{
		pos->data = target_value;
	}
	else
	{
		printf("修改失败\n");
	}
}


//单链表在pos位置之后插入x
void SListInsertAfter(struct SListNode* pos, const SListDataType x)
{
	assert(NULL != pos);
	struct SListNode* newNode = CreatSListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}


//单链表删除pos位置之后的值
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
