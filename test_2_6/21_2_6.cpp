#define _CRT_SECURE_NO_WARNINGS 1

//运用memcpy()函数
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[10];
//	//参数1----目的地   参数2----源头  参数三----拷贝的字节大小
//  //memcpy---函数是用来拷贝这种不相关的内存块的~
//	memcpy(arr2, arr1, 16);
//
//	return 0;
//}

//模拟实现memcpy()
//参数1----目的地   参数2----源头  参数三----拷贝的字节大小
//#include<assert.h>
//#include<stdio.h>
//void* my_memcpy(void *dest,const void*src,size_t size)
//{
//	assert(dest != NULL && src != NULL);
//	void* temp = dest;
//	while (size--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return temp;
//}
/*----------------测试代码--------------------------*/
//void test()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[10];
//	my_memcpy(arr2, arr1, 16);
//}
//int main()
//{
//	test1();
//	return 0;
//}




//运用memmove()函数拷贝这种相关的内存块的~
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	//把1、2、3、4拷贝到3、4、5、6上
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
/*参数1----目的地   参数2----源头  参数三----拷贝的字节大小*/
//	memmove(arr + 2, arr, 16);
//	return 0;
//}

//模拟实现memmove()
//#include<stdio.h>
//#include<assert.h>
/*参数1----目的地   参数2----源头  参数三----拷贝的字节大小*/
//void* my_memmove(void* dest, const void* src, size_t size)
//{
//	assert(dest != NULL && src != NULL);
//	void* temp = dest;
//	if (dest<src)
//	{
//		/*从前向后拷贝*/
//		while (size--)
//		{
//			*(char*)dest = *(char*)src;
//			(char*)dest+1;
//			(char*)src+1;
//		}
//	}
//	else
//	{
//		/*从后向前拷贝*/
//		while (size--)
//		{
//			*((char*)dest + size) = *((char*)src+size);
//
//		}
//	}
//	return temp;
//}
/*----------------测试代码--------------------------*/
//void test2()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr + 2, arr, 16);
//}
//int main()
//{
//	test2();
//	return 0;
//}




//运用memcmp()
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr1[]={ 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,6,7 };
//	int temp=memcmp(arr1, arr2, 8);
//	printf("%d", temp);
//	return 0;
//}


//运用memset()
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20] = { 0 };
	//只适用于初始化-----字符
	memset(arr, '*', 20);
	return 0;
}
