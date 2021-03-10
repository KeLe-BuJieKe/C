#include"Contact.h"

//������
enum Option
{
	Exit,		
	_Add,
	_Show,
	_Delete,
	_Search,
	_Modify,
	_Clean
};

//�˵�
void menu()
{
	printf("***********************\n");
	printf("*****1�������ϵ��*****\n");
	printf("*****2����ʾ��ϵ��*****\n");
	printf("*****3��ɾ����ϵ��*****\n");
	printf("*****4��������ϵ��*****\n");
	printf("*****5���޸���ϵ��*****\n");
	printf("*****6�������ϵ��*****\n");
	printf("*****0���˳�ͨѶ��*****\n");
	printf("***********************\n");
}

void test()
{
	struct Addressbooks abs;
	//��ʼ��
	InitPerson(&abs);
	while (true)
	{
		menu();
		printf("������Ҫѡ��Ĳ�����\n");
		int select = 0;
		scanf("%d", &select);
		switch (select)
		{
		case _Add:
			addPerson(&abs);
			break;
		case _Show:
			showPerson(&abs);
			break;
		case _Delete:
			deletePerson(&abs);
			break;
		case _Search:
			findPerson(&abs);
			break;
		case _Modify:
			modifyPerson(&abs);
			break;
		case _Clean:
			cleanPerson(&abs);
			break;
		case Exit:
			printf("�����˳����򣬻�ӭ�´�ʹ��\n");
			system("pause");     //�밴���������
			exit(0);
		default:
			printf("�����������������\n");
			system("pause");     //�밴���������
			system("cls");      //��������
			break;
		}
	}
}


int main()
{
	test();
	return 0;
}