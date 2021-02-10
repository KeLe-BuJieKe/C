#define _CRT_SECURE_NO_WARNINGS 1


//#include<stdio.h>
//#include<stdlib.h>	
////声明一个结构体类型
////声明一个学生类型，是想过学生类型来创建学生变量（对象）
////描述学生：属性-名字+电话+性别+年龄
//struct stu
//{
//	char name[20];          //姓名
//	char sex[10];           //性别
//	char phone[20];         //电话
//	int age;                //年龄
//}s3,s4;					    //全局变量
//
//struct stu s3;   //全局变量
//int main()
//{
//	//创建的结构体局部变量
//	struct stu s1;
//	system("pause");
//	return 0;
//}



//结构体内存对齐
/*考点 如何计算？ 首先得掌握结构体的对齐规则：
1. 第一个成员在与结构体变量偏移量为0的地址处。
2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
VS中默认的值为8					Linux中的默认值为4
3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所
有最大对齐数（含嵌套结构体的对齐数）的整数倍。
*/
//#include<stdio.h>
////练习1
//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
////练习2
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
////练习3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
////练习4-结构体嵌套问题
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
////设置默认对齐数为4
//#pragma pack(4)
//struct s
//{
//	char c1;
//	double d;
//};
//#pragma pack()                      
////取消设置的默认对齐数
//
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));             //---------12
//
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));             //---------8
//
//	struct S3 s3 = { 0 };
//	printf("%d\n", sizeof(struct S3));      //---------16
//
//
//	printf("%d\n",sizeof(struct S4));       //----------32
//
//
//	//更改了默认对齐数
//	printf("%d\n", sizeof(struct s));       //-----------12
//	return 0;
//}



#include<stdio.h>
#include<stddef.h>
struct S
{
	char c;
	int i;
	double d;
};
int main()
{
	//offsetof----------计算偏移量是多少
	//offsetof是一个宏，不是函数
	//头文件为----------#include<stddef.h>
	printf("%d\n",offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));
	return 0;
}


//offsetof模拟实现