#include"DList.h"


//测试代码
void test1()
{
	struct DList* phead=NULL;

	//测试初始化头结点
	phead = InitDList();

	//测试尾插
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushBack(phead, 4);
	DListPrint(phead);


	//测试尾删
	DListPopBack(phead);
	DListPopBack(phead);
	DListPopBack(phead);
	DListPopBack(phead);
	DListPrint(phead);

	//测试头插
	DListPushFront(phead,100);
	DListPushFront(phead, 1);
	DListPushFront(phead, 101);
	DListPrint(phead);

	//测试头删
	DListPopFront(phead);
	DListPopFront(phead);
	DListPopFront(phead);
	DListPrint(phead);


}

void test2()
{
	struct DList* phead = NULL;

	//测试初始化头结点
	phead = InitDList();

	//测试尾插
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushBack(phead, 4);
	DListPrint(phead);


	//测试查找x位置并在x的前面插入
	DListInsert(phead,3, 5);
	DListPrint(phead);

	//测试在x的位置删除
	DListErase(phead, 3);
	DListPrint(phead);


	DListDestory(&phead);
}

int main()
{
	test1();

	test2();

	return 0;
}