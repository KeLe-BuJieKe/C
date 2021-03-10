#include"Contact.h"

//操作数
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

//菜单
void menu()
{
	printf("***********************\n");
	printf("*****1、添加联系人*****\n");
	printf("*****2、显示联系人*****\n");
	printf("*****3、删除联系人*****\n");
	printf("*****4、查找联系人*****\n");
	printf("*****5、修改联系人*****\n");
	printf("*****6、清空联系人*****\n");
	printf("*****0、退出通讯率*****\n");
	printf("***********************\n");
}

void test()
{
	struct Addressbooks abs;
	//初始化
	InitPerson(&abs);
	while (true)
	{
		menu();
		printf("请输入要选择的操作：\n");
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
			printf("您已退出程序，欢迎下次使用\n");
			system("pause");     //请按任意键继续
			exit(0);
		default:
			printf("输入错误，请重新输入\n");
			system("pause");     //请按任意键继续
			system("cls");      //清屏操作
			break;
		}
	}
}


int main()
{
	test();
	return 0;
}