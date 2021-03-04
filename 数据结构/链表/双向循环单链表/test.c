#include"DList.h"


//���Դ���
void test1()
{
	struct DList* phead=NULL;

	//���Գ�ʼ��ͷ���
	phead = InitDList();

	//����β��
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushBack(phead, 4);
	DListPrint(phead);


	//����βɾ
	DListPopBack(phead);
	DListPopBack(phead);
	DListPopBack(phead);
	DListPopBack(phead);
	DListPrint(phead);

	//����ͷ��
	DListPushFront(phead,100);
	DListPushFront(phead, 1);
	DListPushFront(phead, 101);
	DListPrint(phead);

	//����ͷɾ
	DListPopFront(phead);
	DListPopFront(phead);
	DListPopFront(phead);
	DListPrint(phead);


}

void test2()
{
	struct DList* phead = NULL;

	//���Գ�ʼ��ͷ���
	phead = InitDList();

	//����β��
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushBack(phead, 4);
	DListPrint(phead);


	//���Բ���xλ�ò���x��ǰ�����
	DListInsert(phead,3, 5);
	DListPrint(phead);

	//������x��λ��ɾ��
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