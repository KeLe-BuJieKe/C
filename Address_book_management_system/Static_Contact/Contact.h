#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//各个数据的最大容量
enum Max
{
	Name_Max = 20,
	Sex_Max = 6,
	Tele_Max=12,
	Addr_Max=30,
	Data_Max=1000
};

//联系人信息结构体
struct PeoInfo
{
	char _name[Name_Max];		//姓名
	int _age;					//年龄
	char _sex[Sex_Max];			//性别
	char _tele[Tele_Max];		//电话
	char _addr[Addr_Max];		//地址
};

//通讯录结构体
struct Addressbooks
{
	struct PeoInfo _data[Data_Max];		//静态通讯录
	int _size;							//记录当前存有多少个联系人
};

//初始化
void InitPerson(struct Addressbooks* Pabs);

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1是通讯率  参数2是对比姓名
int isExist(struct Addressbooks* Pabs, char name[]);

//添加联系人
void addPerson(struct Addressbooks* Pabs);

//显示所有联系人
void showPerson(const struct Addressbooks* Pabs);

//删除联系人
void deletePerson(struct Addressbooks* Pabs);

//查找联系人
void findPerson(const struct Addressbooks* Pabs);

//修改指定的联系人
void modifyPerson(struct Addressbooks* Pabs);

//清空所有联系人
void cleanPerson(struct Addressbooks* Pabs);

//排序联系人
void sortPerson(struct Addressbooks* Pabs);