#include"SeqList.h"


//测试头尾插入、删除
void testSeqList()
{
	struct SeqList s;
	//初始化
	SeqListInit(&s);

	//测试尾插
	printf("测试尾插\n");
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPrint(&s);

	//测试尾删
	printf("测试尾删\n");
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	//测试头插
	printf("测试头插\n");
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);

	//测试头删
	printf("测试头删\n");
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//测试任意位置的插入
	printf("测试任意位置的插入\n");
	SeqListInsert(&s, 2, 0);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 3);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 10);
	SeqListPrint(&s);

	//测试任意位置的删除
	printf("测试任意位置的删除\n");
	SeqListErase(&s, 7);
	SeqListPrint(&s);

	//测试顺序表查找
	int key;
	printf("请输入您要查找的数字\n");
	scanf("%d", &key);
	int ret = SeqListFind(&s, key);
	if (ret != -1)
	{
		printf("数字%d的下标为：%d\n",key, ret);
	}
	else
	{
		printf("数字%d不存在\n",key);
	}
}


int main()
{
	testSeqList();
	return 0;
}