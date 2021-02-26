#include"SList.h"

void TestSList()
{
	struct SListNode* phead = NULL;

	//测试尾插
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(&phead);

	//测试尾删
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(&phead);

	//测试头插
	SListPushFront(&phead, 5);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 3);
	SListPrint(&phead);

	//测试头删
	SListPopFront(&phead);
	SListPrint(&phead);


	//测试单链表查找
	struct SListNode* pos=SListFind(phead, 4);
	if (pos!= NULL)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}

	//单链表修改
	SListModify(&phead, 4, 3);
	SListPrint(&phead);
	SListModify(&phead,  3, 4 );
	SListPrint(&phead);


	//测试单链表在pos位置之后插入x
	SListInsertAfter(pos, 2);
	SListPrint(&phead);
	

	//测试单链表删除pos位置之后的值
	struct SListNode* pos1 = SListFind(phead, 4);
	SListEraseAfter(pos1);
	SListPrint(&phead);
}

int main()
{
	TestSList();
	return 0;
}