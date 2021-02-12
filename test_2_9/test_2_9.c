#define _CRT_SECURE_NO_WARNINGS 1

//位段
/*位段的声明和结构是类似的，有两个不同：
1.位段的成员必须是 int、unsigned int 或signed int 。
2.位段的成员名后边有一个冒号和一个数字。*/
//#include<stdio.h>
//#include<stdlib.h>
///*位段的内存分配
//1. 位段的成员可以是 int unsigned int signed int 或者是 char （属于整形家族）类型
//2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
//3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。
//*/
//struct A			//	A是一个位段类型
//{
//	int _a : 2;		//_a----占2个比特位
//	int _a : 5;		//_b----占5个比特位
//	int _c : 10;	//_c----占10个比特位
//	int _d : 30;	//_d----占30个比特位
//	//一共47个比特位
//	//位段不能大于32
//};
//int main()
//{
//	printf("%d\n", sizeof(struct A));			//------------8
//  //还有个例子在进阶ppt里
//	system("pause");
//	return 0;
//}



//枚举类型
/*我们可以使用 #define 定义常量，为什么非要使用枚举？ 枚举的优点：
1. 增加代码的可读性和可维护性
2. 和#define定义的标识符比较枚举有类型检查，更加严谨。
3. 防止了命名污染（封装）
4. 便于调试
5. 使用方便，一次可以定义多个常量*/
//#include<stdio.h>
//enum color
//{
//	//枚举的可能取值---常量
//	Red,
//	Yellow=5,
//	Blue
//};
//int main()
//{
//	enum Color clr = Blue;//只能拿枚举常量给枚举变量赋值，才不会出现类型的差异。
//	//	clr = 7;-----error
//
//	//					  0		5		6
//	printf("%d %d %d\n", Red, Yellow, Blue);
//	//枚举类型的大小-----一个整形大小（4）
//	printf("%d\n", sizeof(enum color));			//-----4
//	return 0;
//}



//联合-联合体-共用体
/*联合类型的定义:
联合也是一种特殊的自定义类型 这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以
联合也叫共用体）。 比如*/
//#include<stdio.h>
//union un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合体大小的计算
//	/*联合的大小至少是最大成员的大小。
//	当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。*/
//	printf("%d\n", sizeof(union un));			//-----4
//	return 0;
//}



//#include<stdio.h>
//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//int main()
//{
//	//下面输出的结果是什么？
//	printf("%d\n", sizeof(union Un1));		//--------8
//	printf("%d\n", sizeof(union Un2));		//--------16
//	return 0;
//}
