#define _CRT_SECURE_NO_WARNINGS 1


/*malloc函数*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	
//	int n;
//	scanf("%d", &n);
//	//malloc向内存申请n个整形空间
//	/*这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针。
//	如果开辟成功，则返回一个指向开辟好空间的指针。
//	如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。*/
//	int* p = (int*)malloc(n*sizeof(int));
//	
//	if (NULL == p)
//	{
//		//打印错误信息
//		printf("%s",strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			*(p + i) = i;
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用时
//	//还给操作系统
//	/*free函数用来释放动态开辟的内存。
//	如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。
//	如果参数 ptr 是NULL指针，则函数什么事都不做*/
//	free(p);
//	p = NULL;
//	return 0;
//}





/*calloc函数*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	/*C语言还提供了一个函数叫 calloc ， calloc 函数也用来动态内存分配。原型如下：
//	void *calloc( size_t num, size_t size );
//	函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。
//	与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0。*/
//	int n;
//	scanf("%d", &n);
//	//calloc向内存申请n个整形空间
//	int* p = (int*)calloc(n,sizeof(int));
//	
//	if (NULL == p)
//	{
//		//打印错误信息
//		printf("%s",strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			//calloc把申请内存的值全部初始化为0
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放空间
//	free(p);
//	p = NULL;
//	return 0;
//}




/*realloc函数*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	int* p = (int*)malloc(20);
	if (NULL == p)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i)=i;
		}
	}
	//就是在使用malloc开辟的20个字符空间
	//假设这里，20个字节不能满足我们的需求了，希望我们能够有40个字节的空间，这里我们就可以使用remalloc来调整动态开辟的内存
	//函数原型----void *realloc( void *memblock, size_t size );
	//void *memblock-----需要调整的内存地址   size_t size-----调整之后新的大小
	//返回值为调整之后的内存起始位置	


	//realloc使用的注意事项
	//1.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
	//2.如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重现找一个新的内存区域
	//  开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间，最后返回新开辟的内存空间地址
	//3.得用一个新的变量来接收realloc函数的返回值

	int* ptr =(int *)realloc(p, 40);
	//防止开辟失败，使得原来的p找不到了
	if (NULL != ptr)
	{
		p = ptr;

		//使用扩展的内存块
		int i = 0;
		for (int i = 5; i < 10; i++)
		{
			*(p + i) = i;
		}

		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}

	//释放内存
	free(p);
	p = NULL;
	return 0;
}