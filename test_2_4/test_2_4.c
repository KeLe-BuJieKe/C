#define _CRT_SECURE_NO_WARNINGS 1

/*1.问题描述：输出什么*/
//#include<stdio.h>
//int main()
//{
//    const char* c[] = { "ENTER","NEW","POINT","FIRST" };
//    char** cp[] = { c + 3,c + 2,c + 1,c };
//    char*** cpp = cp;
//    printf("%s\n", **++cpp);               //**++cpp---------POINT
//    printf("%s\n", *-- * ++cpp + 3);       //*-- * ++cpp + 3-----------ER
//    printf("%s\n", *cpp[-2] + 3);          //*cpp[-2] + 3------ST
//    printf("%s\n", cpp[-1][-1] + 1);       // cpp[-1][-1] + 1------EW
//    return 0;
//}


//2.模拟实现库函数strcmp
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* str1,const char*str2)
//{
//	assert(str1!=NULL&&str2 != NULL);
//	while (*str1==*str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > * str2)
//	{
//		return 1;
//	}
//	return -1;
//}
////---------测试代码-------------------------
//int main()
//{
//	printf("%d", my_strcmp("ABCD", "ABC"));
//	return 0;
//}


//3.作业标题：模拟实现strcpy
//#include<assert.h>
//#include<stdio.h>
//char* my_strcpy(char *str1,const char*str2)
//{
//	assert(str1!=NULL&&str2 != NULL);	
//	int* str = str1;
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return str;
//}
////---------测试代码-------------------------
//int main()
//{
//	char str1[20] = "Hellow ";
//	char str2[20] = "World";
//	printf("%s", my_strcpy(str1,str2));
//	return 0;
//}


//4.作业标题:模拟实现strcat
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char *str1,const char *str2)
//{
//	assert(str1 != NULL && str2 != NULL);
//	char* str = str1;
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return str;
//}
////---------测试代码-------------------------
//int main()
//{
//		char str1[20] = "Hellow ";
//		char str2[20] = "World";
//		printf("%s", my_strcat(str1,str2));
//
//}


//5.作业标题:模拟实现strlen
//#include<assert.h>
//#include<stdio.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	size_t count = 0;
//	while (*str++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
////---------测试代码-------------------------
//int main()
//{
//	char str[20] = "ABCD";
//	printf("%u", my_strlen(str));
//	return 0;
//}


//6.作业标题:模拟实现strncpy
//#include<stdio.h>
//#include<assert.h>
//char*my_strncpy(char *str1,const char *str2,size_t count)
//{
//	assert(str1 != NULL && str2 != NULL);
//	char* str = str1;
//	while (count && (*str1++=*str2++)!='\0')
//	{
//		count--;
//	}
//	if (count)
//	{
//		while (count--)
//		{
//			*str1++ = '\0';
//		}
//	}
//	return str;
//}
////---------测试代码-------------------------
//int main()
//{
//	char str1[20] = "ABCD";
//	char str2[20] = "EFDG";
//	printf("%s",my_strncpy(str1,str2,3));
//	return 0;
//}


//7.作业标题:模拟实现strncat(连接俩个字符串)
//#include<stdio.h>
//#include<assert.h>
//char*my_strncat(char* str1, const char* str2, size_t count)
//{
//	assert(str1!=NULL && str2!=NULL);
//	char* str = str1;
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (count--)
//	{
//		if ((*str1++ = *str2++) == 0)
//		{
//			return str;
//		}
//	}
//	*str1 = '\0';
//	return str;
//}
////---------测试代码-------------------------
//int main()
//{
//	char str1[20] = "ABCD";
//	char str2[20] = "EFDG";
//	printf("%s",my_strncat(str1, str2, 3));
//	return 0;
//}


//8.作业标题:模拟实现strstr(字符串中找子字符串)
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 != NULL && str2 != NULL);
//	if (str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	const char* cp = str1;
//	while (*cp)
//	{
//		const char* p1 = cp;
//		const char* p2 = str2;
//		while ((*p1 == *p2) && (*p1 !='\0') && (*p2 !='\0'))
//		{
//			p1++;
//			p2++;
//		}
//		if (*p2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
////---------测试代码-------------------------
//int main()
//{
//	char arr1[] = "abccced";
//	char arr2[] = "";
//	char* temp = my_strstr(arr1, arr2);
//	if (temp != NULL)
//	{
//		printf("%s", temp);
//	}
//	else
//	{
//		printf("找不到");
//	}
//	return 0;
//}


//9.strerror - 错误报告函数
//把错误码转换为对应的错误信息，返回错误信息对应字符串的起始地址
//#include <errno.h>
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	//printf("hehe\n");
//	//判断文件是否打开成功
//	FILE* pf = fopen("test.txt", "r");//file open
//	if (pf == NULL)
//	{
//		printf("fopen: %s\n", strerror(errno));
//		perror("fopen");
//	}
//
//	return 0;
//}


//10.tolower------大写字符转小写    toupper-----小写字符转大写
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20] = { 0 };
	gets(arr);//Hello Bit!
	int i = 0;
	while (arr[i])
	{
		if (isupper(arr[i]))
		{
			arr[i] = tolower(arr[i]);   //tolower------大写字符转小写
		}
		printf("%c", arr[i]);
		i++;
	}

	return 0;
}
