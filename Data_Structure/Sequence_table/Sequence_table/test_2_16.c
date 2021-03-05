#include"SeqList.h"


//����ͷβ���롢ɾ��
void testSeqList()
{
	struct SeqList s;
	//��ʼ��
	SeqListInit(&s);

	//����β��
	printf("����β��\n");
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

	//����βɾ
	printf("����βɾ\n");
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	//����ͷ��
	printf("����ͷ��\n");
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);

	//����ͷɾ
	printf("����ͷɾ\n");
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//��������λ�õĲ���
	printf("��������λ�õĲ���\n");
	SeqListInsert(&s, 2, 0);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 3);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 10);
	SeqListPrint(&s);

	//��������λ�õ�ɾ��
	printf("��������λ�õ�ɾ��\n");
	SeqListErase(&s, 7);
	SeqListPrint(&s);

	//����˳������
	int key;
	printf("��������Ҫ���ҵ�����\n");
	scanf("%d", &key);
	int ret = SeqListFind(&s, key);
	if (ret != -1)
	{
		printf("����%d���±�Ϊ��%d\n",key, ret);
	}
	else
	{
		printf("����%d������\n",key);
	}
}


int main()
{
	testSeqList();
	return 0;
}