#include"SList.h"

void TestSList()
{
	struct SListNode* phead = NULL;

	//����β��
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(&phead);

	//����βɾ
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(&phead);

	//����ͷ��
	SListPushFront(&phead, 5);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 3);
	SListPrint(&phead);

	//����ͷɾ
	SListPopFront(&phead);
	SListPrint(&phead);


	//���Ե��������
	struct SListNode* pos=SListFind(phead, 4);
	if (pos!= NULL)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}

	//�������޸�
	SListModify(&phead, 4, 3);
	SListPrint(&phead);
	SListModify(&phead,  3, 4 );
	SListPrint(&phead);


	//���Ե�������posλ��֮�����x
	SListInsertAfter(pos, 2);
	SListPrint(&phead);
	

	//���Ե�����ɾ��posλ��֮���ֵ
	struct SListNode* pos1 = SListFind(phead, 4);
	SListEraseAfter(pos1);
	SListPrint(&phead);
}

int main()
{
	TestSList();
	return 0;
}