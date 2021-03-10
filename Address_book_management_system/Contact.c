#include"Contact.h"

//初始化
void InitPerson(struct Addressbooks* Pabs)
{
	Pabs->_size = 0;
	memset(Pabs->_data, 0, sizeof(Pabs->_data));
}


//添加联系人
void addPerson(struct Addressbooks* Pabs)
{
	//判断电话通讯录是否已满
	if (Pabs->_size==Data_Max)
	{
		printf("通讯录已满，添加失败\n");
		return;
	}
	else
	{
		//姓名
		printf("请输入名字：\n");
		scanf("%s", Pabs->_data[Pabs->_size]._name);

		//性别
		printf("请输入性别: 男 or 女 \n");
		while (true)
		{
			scanf("%s", Pabs->_data[Pabs->_size]._sex);
			if (strcmp(Pabs->_data[Pabs->_size]._sex, "男") == 0)
			{
				break;
			}
			else if (strcmp(Pabs->_data[Pabs->_size]._sex, "女") == 0)
			{
				break;
			}
			printf("输入错误，请重现输入\n");
		}

		//年龄
		printf("请输入年龄: \n");
		scanf("%d", &Pabs->_data[Pabs->_size]._age);


		//电话
		printf("请输入联系电话：\n");
		scanf("%s", Pabs->_data[Pabs->_size]._tele);

		//住址
		printf("请输入家庭住址：\n");
		scanf("%s", Pabs->_data[Pabs->_size]._addr);

		//更新通讯录的人数
		Pabs->_size++;
		printf("添加成功\n");
		system("pause");     //请按任意键继续
		system("cls");      //清屏操作
	}
}

//显示所有联系人
void showPerson(const struct Addressbooks* Pabs)
{
	if (Pabs->_size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < Pabs->_size; i++)
		{
			printf("姓名：%s\t", Pabs->_data[i]._name);
			printf("年龄：%-2d\t",  Pabs->_data[i]._age);
			printf("性别：%-5s\t", Pabs->_data[i]._sex);
			printf("电话：%-10s\t", Pabs->_data[i]._tele);
			printf("地址：%-10s\t", Pabs->_data[i]._addr);
			printf("\n");
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1是通讯率  参数2是对比姓名
int isExist(struct Addressbooks* Pabs, char name[])
{
	for (int i = 0; i < Pabs->_size; i++)
	{
		if (strcmp(Pabs->_data[i]._name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void deletePerson(struct Addressbooks* Pabs)
{
	char name[Name_Max];
	printf("请输入您要删除的联系人姓名:\n");
	scanf("%s", name);
	int pos = isExist(Pabs, name);
	if (pos == -1)
	{
		printf("想要删除的联系人不存在\n");
	}
	else
	{
		int i = 0;
		for (i = pos;i < Pabs->_size-1; i++)
		{
			Pabs->_data[i] = Pabs->_data[i + 1];
		}
		Pabs->_size--;
		printf("删除成功\n");
	}
	
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(const struct Addressbooks* Pabs)
{
	char name[Name_Max];
	printf("请输入您要查找的联系人姓名:\n");
	scanf("%s", name);
	int pos = isExist(Pabs,name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("姓名：%s\t", Pabs->_data[pos]._name);
		printf("年龄：%-2d\t", Pabs->_data[pos]._age);
		printf("性别：%-5s\t", Pabs->_data[pos]._sex);
		printf("电话：%-10s\t", Pabs->_data[pos]._tele);
		printf("地址：%-10s\t", Pabs->_data[pos]._addr);
	}
	system("pause");
	system("cls");
}

//修改指定的联系人
void modifyPerson(struct Addressbooks* Pabs)
{
	char name[Name_Max];
	printf("请输入您要修改的联系人姓名:\n");
	scanf("%s", name);
	int pos = isExist(Pabs, name);
	if (pos == -1)
	{
		printf("修改的联系人不存在\n");
	}
	else
	{		//姓名
		printf("请输入名字：\n");
		scanf("%s", Pabs->_data[pos]._name);

		//性别
		printf("请输入性别: 男 or 女 \n");
		while (true)
		{
			scanf("%s", Pabs->_data[pos]._sex);
			if (strcmp(Pabs->_data[pos]._sex, "男") == 0)
			{
				break;
			}
			else if (strcmp(Pabs->_data[pos]._sex, "女") == 0)
			{
				break;
			}
			printf("输入错误，请重现输入\n");
		}

		//年龄
		printf("请输入年龄: \n");
		scanf("%d", &Pabs->_data[pos]._age);

		//电话
		printf("请输入联系电话：\n");
		scanf("%s", Pabs->_data[pos]._tele);

		//住址
		printf("请输入家庭住址：\n");
		scanf("%s", Pabs->_data[pos]._addr);

		printf("修改成功\n");
		system("pause");     //请按任意键继续
		system("cls");      //清屏操作
	}
}

//清空所有联系人
void cleanPerson(struct Addressbooks* Pabs) 
{
	printf("请确定是否要清空所有联系人\n");
	int select = 0;
	printf("1---Yes\n");
	printf("0---No\n");

	scanf("%d", &select);
	if (select == 1)
	{
		Pabs->_size = 0;	//将当前记录联系人数量置为0，做逻辑上的清空
		printf("通讯率已清空\n");
	}
	else
	{
		printf("您已取消清空联系人\n");
	}
	system("pause");
	system("cls");
}
