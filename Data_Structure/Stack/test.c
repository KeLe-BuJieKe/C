#include"stack.h"

void test()
{
	stack st;

	//测试栈的初始化
	StackInit(&st);

	//测试入栈
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	//遍历栈中元素
	while (!StackEmpty(&st))	//判断栈中是否为空
	{
		//获取栈顶元素
		printf("%d ", StackTop(&st));

		//测试出栈
		StackPop(&st);
	}

	//测试销毁栈
	StackDestory(&st);


}

int main()
{
	test();
	system("pause");
	return 0;
}