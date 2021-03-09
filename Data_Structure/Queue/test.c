#include"Queue.h"

void test()
{
	Queue qu;
	//测试初始化
	QueueInit(&qu);

	//测试入队
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	QueuePush(&qu, 4);

	//测试判空
	while (!QueueEmpty(&qu))
	{
		//测试取队头元素
		printf("%d ", QueueFront(&qu));

		//测试出队
		QueuePop(&qu);
	}
	printf("\n");


	//while (!QueueEmpty(&qu))
	//{
	//	//测试取队尾元素
	//	printf("%d ", QueueBack(&qu));

	//	//测试出队
	//	QueuePop(&qu);
	////}
	//printf("\n");

	printf("队中元素个数为：%d\n", QueueSize(&qu));

	//测试销毁
	QueueDestory(&qu);
}


int main()
{
	test();
	system("pause");
	return 0;
}