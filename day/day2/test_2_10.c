#define _CRT_SECURE_NO_WARNINGS 1

/*在vs下，这个结构体所占的空间大小是多少字节*/
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct
//{
//	int a;  //4		
//	char b;	//1
//	short c;//2
//	short d;//2
//}AA_t;
//int main()
//{
//	printf("%d\n", sizeof(AA_t));		//----12
//	system("pause");
//	return 0;
//}



//a的值为？
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	a += a *= a -= a / 3;
//	printf("%d\n", a);	//--98
//	return 0;
//}


//以下程序中while循环会发生什么？
//int  main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		if (i < 1)			//i一直等于0，一直死循环
//		{
//			continue;
//		}
//		if (i == 5)
//		{
//			break;
//		}
//		i++;
//	}
//}



/*算法题
要求写一个函数，将字符串中的空格替换成%20.样例："abc defgx yz"转换成abc%20defgx%20yz*/

//自己的做法
#include<stdio.h>
#include<assert.h>
//char* str---数组   int len----数组大小
void  Replace(char* str,int len)
{
	assert(str != NULL && len != 0);
	int i = 0;				//数组下标
	int numlen = 0;			//计算字符个数
	int numBlank = 0;		//计算空格个数
	for (i = 0;str[i] != '\0'; i++)
	{
		numlen++;
		if (str[i] == ' ')
		{
			numBlank++;
		}
	}
	int newlen = numlen + 2 * numBlank;    //扩充的数组大小
	if (newlen > len)					   //扩充的数组大小一定要小于原来数组的总大小，不然会越界
	{
		return;
	}
	int tempnumlen = numlen;
	int tempnewlen = newlen;

	//只用交换到没有空格，也就是tempnewlen==tempnumlen时，提高效率
	while (tempnumlen>=0&&tempnewlen>tempnumlen)
	{
		if(str[tempnumlen]==' ')
		{
			str[tempnewlen--] = '0';
			str[tempnewlen--] = '2';
			str[tempnewlen--] = '%';
		}
		else
		{
			str[tempnewlen--] = str[tempnumlen];
		}
		tempnumlen--;
	}

}
int main()
{
	char arr[30]= "abc defgx yz";
	int len = sizeof(arr) / sizeof(arr[0]);
	Replace(arr,len);
	printf("%s\n", arr);
	return 0;
}



/*智力题
A、B、C、D四个人，要在夜里过一座桥。他们通过这座桥分别需要耗时1、2、5、10分钟，只有一支手电，并且同时最多只能俩个人一起过桥。
请问，如何安排，能够在17分钟内这四个人都过桥？*/

//后期填坑
