#define _CRT_SECURE_NO_WARNINGS 1

//1.运用函数指针数组的计算器
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("↑******************************↓\n");
//	printf("↑  1.add             2.sub     ↓\n");
//	printf("↑  3.mul             4.div     ↓\n");
//	printf("↑  0.exit                      ↓\n");
//	printf("↑******************************↓\n");
//
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int sub(int x, int y)
//{
//	return x - y;
//}
//
//int mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//
//	int input = 0;
//	int x, y;
//	//函数指针数组---转移表
//	//把函数存进函数指针数组
//	int (*pArr[])(int, int) = { 0,add,sub,mul,Div };
//
//	while (true)
//	{
//		menu();
//		printf("请选择：>\n");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//			exit(0);
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入2个操作数：>\n");
//			scanf("%d %d", &x, &y);
//			int ret = pArr[input](x, y);
//			printf("ret=%d\n", ret);
//		}
//		else
//		{
//			printf("选择错误，请重新选择\n");
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}


//2.函数回调的计算器
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("↑******************************↓\n");
//	printf("↑  1.add             2.sub     ↓\n");
//	printf("↑  3.mul             4.div     ↓\n");
//	printf("↑  0.exit                      ↓\n");
//	printf("↑******************************↓\n");
//
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int sub(int x, int y)
//{
//	return x - y;
//}
//
//int mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
////函数传参-函数指针
////回调函数
//void calc(int(* p)(int, int))//函数指针
//{
//	int x, y;
//	printf("请输入2个操作数：>\n");
//	scanf("%d %d", &x, &y);
//	int ret = p(x, y);
//	printf("ret=%d\n", ret);
//}
//int main()
//{
//
//	int input = 0;
//	
//
//	while (true)
//	{
//		menu();
//		printf("请选择：>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(add);   
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			exit(0);
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}


/*3.回调函数*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{	
//		printf("%d ", arr[i]);
//	}
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	//升序
//	//return (*(int *)e1 - *(int*)e2); 
//
//	//降序
//	return (*(int*)e2 - *(int*)e1);
//}
//void test1()
//{
//	//运用qsort 排序一个整形数组
//	int arr[] = { 9,0,5,7,6,1,3,2,8 ,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//需要引头文件---- #include<stdlib.h>
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print(arr, sz);
//}
//
//struct stu
//{
//	char m_name[20];
//	int  age;
//};
//int cmp_age(const void* e1, const void* e2)
//{
//	//按年龄升序
//	return (*(stu*)e1).age - (*(stu*)e2).age;
//
//	//按年龄降序
//	//return (*(stu*)e2).age - (*(stu*)e1).age;
//}
//int cmp_name(const void* e1, const void* e2)
//{
//	//按名字升序
//	return strcmp((*(stu*)e1).m_name,(*(stu*)e2).m_name);
//
//	//按名字降序	
//	//return strcmp((*(stu*)e2).m_name,(*(stu*)e1).m_name);
//}
//
//void test2()
//{
//	//使用qsort函数排序结构体
//	stu arr[] = { {"zhansan",20},{"lisi",30},{"wangwu",10} };
//	int sz=sizeof(arr) / sizeof(arr[0]);
//	//按年龄排序
//	qsort(arr, sz, sizeof(arr[0]), cmp_age);  //-----qsort的第四个参数是函数指针
//
//	//按名字排序
//	qsort(arr, sz, sizeof(arr[0]), cmp_name);
//}
//int main()
//{	
//	//test1();
//	test2();
//	return 0;
//}


//4.用bobble_sort模拟qsort函数
/*void* base----待排序数据的起始位置
size_t size---- 元素个数
size_t width----一个元素的大小
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void _swap(char* buf1, char* buf2, size_t width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		//一个字节一个字节的交换
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, size_t size, size_t width, int (*cmp)(const void* e1, const void* e2))
{
	size_t i = 0;
	for (i = 0; i < size - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			//相邻俩个元素的比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//如果不满足顺序就交换
				_swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

struct stu
{
	char m_name[20];  //名字

	int  age;         //年龄
};

int cmp_age(const void* e1, const void* e2)
{
	//按年龄升序
	return (*(stu*)e1).age - (*(stu*)e2).age;

	//按年龄降序
	//return (*(stu*)e2).age - (*(stu*)e1).age;
}

int cmp_name(const void* e1, const void* e2)
{
	//按名字升序
	return strcmp((*(stu*)e1).m_name, (*(stu*)e2).m_name);

	//按名字降序	
	//return strcmp((*(stu*)e2).m_name,(*(stu*)e1).m_name);
}

void test3()
{
	stu arr[] = { {"zhansan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//按年龄排序
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_age);
	//按名字排序
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_name);
}

int main()
{
	test3();
}