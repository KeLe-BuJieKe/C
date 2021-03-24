#include"Student_management_system.h"
void menu()
{
	printf("-------------------------------------\n");
	printf("-------------学生管理系统------------\n");
	printf("------1.添加学生    2.清空学生-------\n");
	printf("------3.查找学生    4.修改学生-------\n");
	printf("------5.显示学生    0.退出   --------\n");
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
	//初始化
	
	while (true)
	{
		menu();
		int select = 0;
		printf("请选择你的操作\n");
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
			printf("已退出，欢迎下次使用\n");
			exit(0);
		default :
			printf("输入错误请重新输入\n");
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}