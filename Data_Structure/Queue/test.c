#include"Queue.h"

void test()
{
	Queue qu;
	//���Գ�ʼ��
	QueueInit(&qu);

	//�������
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	QueuePush(&qu, 4);

	//�����п�
	while (!QueueEmpty(&qu))
	{
		//����ȡ��ͷԪ��
		printf("%d ", QueueFront(&qu));

		//���Գ���
		QueuePop(&qu);
	}
	printf("\n");


	//while (!QueueEmpty(&qu))
	//{
	//	//����ȡ��βԪ��
	//	printf("%d ", QueueBack(&qu));

	//	//���Գ���
	//	QueuePop(&qu);
	////}
	//printf("\n");

	printf("����Ԫ�ظ���Ϊ��%d\n", QueueSize(&qu));

	//��������
	QueueDestory(&qu);
}


int main()
{
	test();
	system("pause");
	return 0;
}