#include<iostream>
#include<string>
using namespace std;
#define MAX 1000                   //添加一个宏定义，方面下次维护更换MAX的值
struct people
{
	string m_Name;               //姓名
	int m_Sex;                   //性别
	int m_Age;                   //年龄
	string m_Phone;              //电话
	string m_Addr;             //地址
};
struct Addressbooks
{
	//嵌套结构体
	struct people perspnArray[MAX];       //通讯录中保存的联系人，MAX最大值为1000
	int m_Size;                   //通讯录中当前记录联系人个数
};
//1、添加联系人功能
void addPerson(Addressbooks *abs)   
{
	//判断电话通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->perspnArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->perspnArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->perspnArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->perspnArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址" << endl;
		string addr;
		cin >> addr;
		abs->perspnArray[abs->m_Size].m_Addr = addr;
		//更新通讯录的人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");     //请按任意键继续
		system("cls");      //清屏操作
	}
}
//2、显示所有联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯率为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名:" << abs->perspnArray[i].m_Name << "\t";
			cout << "性别:" << (abs->perspnArray[i].m_Sex ==1?"男":"女")<< "\t";
			cout << "年龄：" << abs->perspnArray[i].m_Age << "\t";
			cout << "电话：" << abs->perspnArray[i].m_Phone << "\t";
			cout << "住址:" << abs->perspnArray[i].m_Addr << endl;
		}
	}
	system("pause");   //按任意键继续
	system("cls");     //清屏
}
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1是通讯率  参数2是对比姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->perspnArray[i].m_Name==name)
		{
			return i;
		}
	}
	return -1;
}
//3、删除联系人
void deletePerson(Addressbooks* abs)
{
	string name;
	cout << "请输入您要删除的联系人姓名: " << endl;
	cin >> name;
	//若ret=-1，则查无此人；若ret=i，则查到了
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		for (int j=ret; j < abs->m_Size; j++)     //查找到人，要进行删除操作
		{
			abs->perspnArray[j] = abs->perspnArray[j + 1];     //数据前移，覆盖上一个元素的值，从而使得删除操作
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//4、显示联系人
void findPerson(Addressbooks*abs)
{
	cout << "请输入你想要查找的联系人:" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名:" << abs->perspnArray[ret].m_Name << "\t";
		cout << "性别:" << (abs->perspnArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->perspnArray[ret].m_Age << "\t";
		cout << "电话：" << abs->perspnArray[ret].m_Phone << "\t";
		cout << "住址:" << abs->perspnArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5、修改指定的联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) 
	{
		//姓名
		string name;
		cout << "请输入名字：" << endl;
		cin >> name;
		abs->perspnArray[ret].m_Name = name;
		//性别
		cout << "请输入性别: " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1|| sex == 2)
			{
				abs->perspnArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄: " << endl;
		int age = 0;
		cin >>age;
		abs->perspnArray[ret].m_Age = age;
		//联系电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->perspnArray[ret].m_Phone = phone;
		//家庭住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->perspnArray[ret].m_Addr = address;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//6、清空所有联系人
void cleanPerson(Addressbooks* abs)
{
	cout << "请确定是否要清空所有联系人" << endl;
	int Delete;
	cout << "1---Yes" << endl;
	cout << "2---No" << endl;
	cin >> Delete;
	if (Delete==1)
	{
		abs->m_Size = 0; //将当前记录联系人数量置为0，做逻辑上的清空
		cout << "通讯率已清空" << endl;
	}
	else
	{
		cout << "您已取消清空联系人" << endl;
	}

	system("pause");
	system("cls");
}
void shouMenu()
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯率*****" << endl;
	cout << "***********************" << endl;
}
//菜单界面
int main()
{
	Addressbooks abs;    //创建通讯录结构体变量
	abs.m_Size = 0;      //初始化通讯录中当前人员个数
	int select = 0;     //创建用户选择输入的变量
	while (true)
	{
		shouMenu();
		cin >> select;
		switch (select)
		{
		case 1:                 //添加联系人
			addPerson(&abs);
			break;
		case 2:                 //显示联系人
			showPerson(&abs);
			break;
		case 3:                 //删除联系人
			deletePerson(&abs);
			break;
		case 4:                 //查找联系人
			findPerson(&abs);
			break;
		case 5:                 //修改联系人
			modifyPerson(&abs);
			break;
		case 6:                 //清空联系人
			cleanPerson(&abs);
			break;
		case 0:                 //退出通讯录
			cout << "您已退出程序，欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}