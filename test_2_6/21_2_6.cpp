#define _CRT_SECURE_NO_WARNINGS 1

//����memcpy()����
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[10];
//	//����1----Ŀ�ĵ�   ����2----Դͷ  ������----�������ֽڴ�С
//  //memcpy---�����������������ֲ���ص��ڴ���~
//	memcpy(arr2, arr1, 16);
//
//	return 0;
//}

//ģ��ʵ��memcpy()
//����1----Ŀ�ĵ�   ����2----Դͷ  ������----�������ֽڴ�С
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
/*----------------���Դ���--------------------------*/
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




//����memmove()��������������ص��ڴ���~
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	//��1��2��3��4������3��4��5��6��
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
/*����1----Ŀ�ĵ�   ����2----Դͷ  ������----�������ֽڴ�С*/
//	memmove(arr + 2, arr, 16);
//	return 0;
//}

//ģ��ʵ��memmove()
//#include<stdio.h>
//#include<assert.h>
/*����1----Ŀ�ĵ�   ����2----Դͷ  ������----�������ֽڴ�С*/
//void* my_memmove(void* dest, const void* src, size_t size)
//{
//	assert(dest != NULL && src != NULL);
//	void* temp = dest;
//	if (dest<src)
//	{
//		/*��ǰ��󿽱�*/
//		while (size--)
//		{
//			*(char*)dest = *(char*)src;
//			(char*)dest+1;
//			(char*)src+1;
//		}
//	}
//	else
//	{
//		/*�Ӻ���ǰ����*/
//		while (size--)
//		{
//			*((char*)dest + size) = *((char*)src+size);
//
//		}
//	}
//	return temp;
//}
/*----------------���Դ���--------------------------*/
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




//����memcmp()
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


//����memset()
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20] = { 0 };
	//ֻ�����ڳ�ʼ��-----�ַ�
	memset(arr, '*', 20);
	return 0;
}
