#include"stack.h"

void test()
{
	stack st;

	//����ջ�ĳ�ʼ��
	StackInit(&st);

	//������ջ
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	//����ջ��Ԫ��
	while (!StackEmpty(&st))	//�ж�ջ���Ƿ�Ϊ��
	{
		//��ȡջ��Ԫ��
		printf("%d ", StackTop(&st));

		//���Գ�ջ
		StackPop(&st);
	}

	//��������ջ
	StackDestory(&st);


}

int main()
{
	test();
	system("pause");
	return 0;
}