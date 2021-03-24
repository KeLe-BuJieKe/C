#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
enum Max
{
	_Department_Max = 30,
	_Name_Max = 20,
	_Class_Max=20
};

typedef struct Student
{
	char _Department[_Department_Max];	//存储学院信息
	char _name[_Name_Max];				//存储学生姓名
	char _class[_Class_Max];			//存储学生班级
	struct Student* next;				//指向下一个学生
}Student;

//新建一个学生结点
Student* CreateStuent(const char* _Department, const char* _name, const char* _class);

//销毁
void DestoryStudent(Student** ps);

//添加学生
void AddStudent(Student**pps);

//显示学生
void ShowStudent(const Student** pps);

//判断该学生是否存在
Student* is_Exist(Student** pps, char  name[]);


//显示查找到的了人的信息
void show_SingleStudent(const Student* pps);

//查找
Student* SearchStudent(Student** pps);

//修改
void ModifyStudent(Student** pps);

//保存
void saveStudent(Student** pps);

