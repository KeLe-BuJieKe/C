#include"Student_management_system.h"
void menu()
{
	printf("-------------------------------------\n");
	printf("-------------ѧ������ϵͳ------------\n");
	printf("------1.���ѧ��    2.���ѧ��-------\n");
	printf("------3.����ѧ��    4.�޸�ѧ��-------\n");
	printf("------5.��ʾѧ��    0.�˳�   --------\n");
	printf("-------------------------------------\n");
}

enum Operation
{
	_Exit_,
	_Add_,
	_Delete_,
	_Search_,
	_Modify_,
	_Show_
};

int main()
{
	Student* head = NULL;
	//��ʼ��
	
	while (true)
	{
		menu();
		int select = 0;
		printf("��ѡ����Ĳ���\n");
		scanf("%d", &select);
		switch (select)
		{
		case _Add_:
			AddStudent(&head);
			break;
		case _Delete_:
			DestoryStudent(&head);
			break;
		case _Search_:
			show_SingleStudent(SearchStudent(&head));
			break;
		case _Modify_:
			ModifyStudent(&head);
			break;
		case _Show_:
			ShowStudent(&head);
			break;
		case _Exit_:
			DestoryStudent(&head);
			printf("���˳�����ӭ�´�ʹ��\n");
			exit(0);
		default :
			printf("�����������������\n");
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}