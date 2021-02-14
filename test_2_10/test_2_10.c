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
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//char* change(char* str)
//{
//	assert(str != NULL);
//	int len = strlen(str);  //全部字符的个数
//	int count = 0;  //空格的个数
//	char arr[] = "%20";
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] == ' ')
//		{
//			count++;
//		}
//	}
//	char* s = (char*)malloc(len+ count*3-count);
//	int size = 0;
//	for (int j = 0; j < len; j++)
//	{
//		if (str[j] != ' ')
//		{
//			s[size++] = str[j];
//			
//		}
//		else
//		{
//			s[size++] = '%';
//			s[size++] = '2';
//			s[size++] = '0';
//			
//		}
//	}
//	s[size] = '\0';
//	strcpy(str, s);
//	return str;
//}
//int main()
//{
//	char arr[30]= "abc defgx yz";
//	change(arr);
//	printf("%s\n", arr);
//	return 0;
//}


//答案做法
//#include<stdio.h>
//void ReplaceBlank(char* str, int len)
//{
//	int MLen = 0;//计算字符的个数
//	int NumBlank=0;//计算空格的数组
//	int IndexofMLen=0;
//	int Indexofnew=0;
//	int newlen=0;
//	int i=0;//从0号下标开始遍历
//	if(str==NULL||len<=0)
//	{
//		return;
//	}
//	while(str[i]!='\0')
//	{
//		++MLen;
//		if(str[i]==' ')
//		{
//			++NumBlank;
//		}
//		++i;
//	}
//	newlen=MLen+NumBlank*2;//a%20b%20c%20dabcd
//	if(newlen>len)//newlen是扩充后数组的大小，所以一定要大于len原来大小，不然放不下
//	{
//		return;
//	}
//	IndexofMLen=MLen;
//	Indexofnew=newlen;
//	while(IndexofMLen>=0&&Indexofnew>IndexofMLen)
//	{
//		if(str[IndexofMLen]==' ')
//		{
//			str[Indexofnew--]='0';
//			str[Indexofnew--] = '2';
//			str[Indexofnew--] = '%';
//		}	
//		else 
//		{
//			str[Indexofnew--] = str[IndexofMLen]; 
//		}
//		--IndexofMLen; 
//	}
//}
//int main()
//{ 
//	char str[30] = "abc defgx yz"; 
//	int len = (sizeof(str) / sizeof(str[0])); 
//	ReplaceBlank(str, len);
//	printf("%s\n", str); 
//	return 0; 
//}




/*智力题
A、B、C、D四个人，要在夜里过一座桥。他们通过这座桥分别需要耗时1、2、5、10分钟，只有一支手电，并且同时最多只能俩个人一起过桥。
请问，如何安排，能够在17分钟内这四个人都过桥？*/

//后期填坑