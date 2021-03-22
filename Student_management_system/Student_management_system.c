#include"Student_management_system.h"

//新建一个学生结点
Student* CreateStuent(const char *_Department,const char *_name,const char *_class)
{
	Student* newNode = (Student*)malloc(sizeof(Student));
	if (newNode == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	strcpy(newNode->_Department,_Department);
	strcpy(newNode->_name , _name);
	strcpy(newNode->_class ,_class);
	newNode->next = NULL;
	return newNode;
}

//销毁
void DestoryStudent(Student** pps)
{

}

//添加学生
void AddStudent(Student** pps)
{
	char Department[_Department_Max];	//存储学院信息
	printf("请输入学院\n");
	scanf("%s", Department);


	char name[_Name_Max];				//存储学生姓名
	printf("请输入姓名\n");
	scanf("%s", name);


	char Class[_Class_Max];				//存储学生班级
	printf("请输入班级\n");
	scanf("%s", Class);

	//头插
	Student* newNode = CreateStuent(Department, name, Class);
	if (*pps == NULL)
	{
		*pps = newNode;
	}
	else
	{
		newNode->next = *pps;
		*pps = newNode;
	}
	printf("添加成功\n");
	system("pause");
	system("cls");
}

//显示学生
void ShowStudent(const Student** pps)
{
	Student* cur = *pps;
	if (cur == NULL)
	{
		printf("数据为NULL\n");
	}
	while (cur != NULL)
	{
		printf("姓名：%-20s 班级:%-20s 学院:%-30s\n", cur->_name, cur->_class, cur->_Department);
		cur = cur->next;
	}
	system("pause");
	system("cls");
}

//删除学生
void DeleteStudent(Student** pps)
{

}

//按名字查找
Student* SearchStudent(Student** pps)
{
	printf("请输入您要查找的名字\n");
	char name[20];
	scanf("%s", name);
	Student* cur = *pps;
	while (cur != NULL)
	{
		if (strcmp(cur->_name, name) == 0)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//修改
void ModifyStudent(Student** pps)
{

}

//保存
void saveStudent(Student* ps)
{

}