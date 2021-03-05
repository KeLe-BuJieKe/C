#include"DList.h"

//创建新结点
struct DList* CreatDListNode(const DListDataType x)
{
	struct DList* newNode = (struct DList*)malloc(sizeof(struct DList));
	if (NULL == newNode)
	{
		//如果开辟失败，直接暴力退出
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


//初始化
struct DList* InitDList()
{
	//创建头结点，并把prev与next指向自己，形成双向循环链表
	struct DList* phead = CreatDListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//清理
void DListClear(struct DList* phead)
{
	assert(phead != NULL);
	//清理所以数据结点，保留头结点，可以继续使用
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

//销毁
void DListDestory(struct DList** phead)
{
	assert(*phead != NULL);
	DListClear(*phead);
	free(*phead);
	*phead = NULL;
}



//遍历链表
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



//尾插
void DListPushBack(struct DList* phead,const DListDataType x)
{
	assert(phead != NULL);
	struct DList* newNode = CreatDListNode(x);
	struct DList* tail = phead->prev;

	//先把原来链表的最后结点的next指向新结点
	tail->next = newNode;
	//再把新结点的prev指向原先链表的最后的结点
	newNode->prev = tail;

	//把头指针的prev指向新结点
	phead->prev = newNode;
	//再把新结点的next域指向头结点
	newNode->next = phead;
}


//尾删
void DListPopBack(struct DList* phead)
{
	assert(phead != NULL);
	//当phead的next指向自己时，就不在删除
	assert(phead->next != phead);


	struct DList* ToDelete = phead->prev;	//指向删除的位置
	struct DList* tail = ToDelete->prev;	//指向即将成为尾的位置

	phead->prev = tail;
	tail->next = phead;

	free(ToDelete);
	ToDelete = NULL;
}


//头插
void DListPushFront(struct DList* phead, const DListDataType x)
{
	assert(phead != NULL);
	struct DList* first = phead->next;
	struct DList* newNode = CreatDListNode(x);

	//把头结点的next指向新创建的结点，再把新创建的结点的next指向原来第一个结点
	phead->next = newNode;
	newNode->next = first;
	
	//把原来第一个结点的prev指向新创建的结点，再把新创建结点的prev指向头结点
	first->prev = newNode;
	newNode->prev = phead;
}


//头删
void DListPopFront(struct DList* phead)
{
	assert(phead != NULL);
	//当phead的next指向自己时，就不再删除
	assert(phead->next != phead);


	struct DList* ToDelete = phead->next;		//指向删除的位置
	struct DList* first = ToDelete->next;		//指向即将成为头的位置

	phead->next = first;
	first->prev = phead;

	free(ToDelete);
	ToDelete = NULL;
}


//查找
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


//在x的前面插入
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
		printf("插入失败\n");
	}
}


//删除x的位置	
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
		printf("删除失败\n");
	}
}