#define _CRT_SECURE_NO_WARNINGS 1


//1.深度理解sizeof和strlen
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//1.数组名单独放在sizeof()内部，数组名表示整个数组，计算的是整个数组的大小，单位是字节
//2.&数组名，数组名表示整个数组，取出的是整个数组的地址
//除上面2种情况之外，所有的数组名都是数组首元素的地址
//sizeof操作符是计算操作数所占空间的大小，计算大小时，不在乎内存中放的值

//strlen()库函数---求【字符串】长度
//只使用于：字符串，字符数组，求长度的时候，只关注'\0'
//int main()
//{	
	//1.一维数组
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));         // sizeof(a)==16---数组名单独放在sizeof内部，计算的是数组总大小
	//printf("%d\n", sizeof(a + 0));     // sizeof(a + 0)==4/8---a+0是第一个元素的地址
	//printf("%d\n", sizeof(*a));        // sizeof(*a)==4---*a就是数组a的首元素
	//printf("%d\n", sizeof(a + 1));     // sizeof(a + 1)==4/8---a+1是数组第二个元素的地址
	//printf("%d\n", sizeof(a[1]));      // sizeof(a[1])==4---a[1]就是数组的第二个元素
	//printf("%d\n", sizeof(&a));        // sizeof(&a)==4/8---&a是数组的地址，但是只要是地址就是4/8个字节
	//printf("%d\n", sizeof(*&a));       // sizeof(*&a)==16---sizeof(*&a)==sizeof(a)，计算的是数组总大小
	//printf("%d\n", sizeof(&a+1));      // sizeof(&a + 1)==4/8---是一个地址，指向的是数组之后的空间
	//printf("%d\n", sizeof(&a[0]));     // sizeof(&a[0])==4/8---是首元素地址
	//printf("%d\n", sizeof(&a[0]+1));   // sizeof(&a[0] + 1)==sizeof(a[1])==4/8---是数组第二个元素的地址


	//2.1字符数组
	//char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));         // sizeof(arr)==6---数组名arr，单独放在sizeof内部，计算的是数组总大小
	//printf("%d\n", sizeof(arr + 0));     // sizeof(arr + 0)==4/8---arr是数组首元素的地址，地址就是4/8
	//printf("%d\n", sizeof(*arr));        // sizeof(*arr)==1---*arr是数组首元素，计算的是首元素大小
	//printf("%d\n", sizeof(arr[1]));      // sizeof(arr[1])==1---arr[1]数组的第二个元素
	//printf("%d\n", sizeof(&arr));        // sizeof(&arr)==4/8---&arr虽然是数组的地址，但是只要是地址就是4/8个字节
	//printf("%d\n", sizeof(&arr + 1));    // sizeof(&arr + 1)==4/8---&arr+1跳过了整个数组，指向了数组之后，但还是地址
	//printf("%d\n", sizeof(&arr[0] + 1)); // sizeof(&arr[0] + 1)==4/8---&arr[0] + 1是第二个元素的地址


	//printf("%d\n", strlen(arr));         // strlen(arr)==随机值---因为arr数组中原本没有'\0',就会在数组arr后继续找'\0'
	//printf("%d\n", strlen(arr+0));       // strlen(arr + 0)==随机值
	////printf("%d\n", strlen(*arr));      // error,应该传递地址进去，而不是传字符进去
	////printf("%d\n", strlen(arr[1]));    // error,应该传递地址进去，而不是传字符进去
	//printf("%d\n", strlen(&arr));        // strlen(&arr)==随机值
	//printf("%d\n", strlen(&arr+1));      // strlen(&arr + 1)==随机值
	//printf("%d\n", strlen(&arr[0]+1));   // strlen(&arr[0] + 1)==随机值


	//2.2字符串
	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));           // sizeof(arr)==7---计算的是arr数组的总大小
	//printf("%d\n", sizeof(arr + 0));       // sizeof(arr + 0)==4/8---arr+0是数组arr的首元素地址
	//printf("%d\n", sizeof(*arr));          // sizeof(*arr)==1---首元素大小
	//printf("%d\n", sizeof(arr[1]));        // sizeof(arr[1])==1---arr第二个元素的大小
	//printf("%d\n", sizeof(&arr));          // sizeof(&arr)==4/8---&arr是数组的地址
	//printf("%d\n", sizeof(&arr + 1));      // sizeof(&arr + 1)==4/8---&arr+1跳过了整个数组，指向了数组之后，但还是地址
	//printf("%d\n", sizeof(&arr[0] + 1));   // sizeof(&arr[0] + 1)==4/8---第二个元素地址


	//printf("%d\n", strlen(arr));           // strlen(arr)==6
	//printf("%d\n", strlen(arr + 0));       // strlen(arr + 0)==6
	////printf("%d\n", strlen(*arr));        // error
	////printf("%d\n", strlen(arr[1]));      // error
	//printf("%d\n", strlen(&arr));          // strlen(&arr)==6
	//printf("%d\n", strlen(&arr + 1));      // strlen(&arr + 1)==随机值	
	//printf("%d\n", strlen(&arr[0] + 1));   // strlen(&arr[0] + 1)==5


	//2.3字符串
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));         // sizeof(p)==4/8---p就是个指针变量
	//printf("%d\n", sizeof(p + 1));     // sizeof(p + 1)==4/8---p + 1是的地址
	//printf("%d\n", sizeof(*p));        // sizeof(*p)==1---p是字符指针，*p访问一个字节
	//printf("%d\n", sizeof(p[0]));      // sizeof(p[0])==sizeof(*p)==sizeof(*(p+0))==1
	//printf("%d\n", sizeof(&p));        // sizeof(&p)==4/8---&p是地址
	//printf("%d\n", sizeof(&p + 1));    // sizeof(&p + 1)==4/8---&p+1是指向p后边空间的地址
	//printf("%d\n", sizeof(&p[0] + 1)); // sizeof(&p[0] + 1)==4/8---&p[0]+1就是第二个元素的地址

	//printf("%d\n", strlen(p));         // strlen(p)==6
	//printf("%d\n", strlen(p + 1));     // strlen(p + 1)==5
	////printf("%d\n", strlen(*p));      // error
	////printf("%d\n", strlen(p[0]));    // error
	//printf("%d\n", strlen(&p));        // strlen(&p)==随机值
	//printf("%d\n", strlen(&p + 1));    // strlen(&p + 1)==随机值
	//printf("%d\n", strlen(&p[0] + 1)); // strlen(&p[0] + 1)==5


	//3.二维数组
	//int a[3][4] = { 0 };
	////printf("%p\n", &a[0][0]);
	////printf("%p\n", a[0]+1);
	////对于二维数组，数组名单独放在sizeof内部，数组名表示整个数组，计算的是整个数组的大小
	//printf("%d\n", sizeof(a));            // sizeof(a)==48
	//printf("%d\n", sizeof(a[0][0]));	  // sizeof(a[0][0])==4
	//printf("%d\n", sizeof(a[0]));         // sizeof(a[0])==16---a[0]是第一行的数组名，第一行的数组名单独放在sizeof内部
	//                                      // 计算的是第一行这个数组的总大小

	//printf("%d\n", sizeof(a[0] + 1));     // sizeof(a[0] + 1)==4/8---arr[0]作为第一行的数组名，并没有单独放在sizeof内部
	//                                      // 所以数组名相当于数组首元素的地址，就是第一行第一个元素的地址
	//                                      // a[0]+1---是第一行第二个元素的地址
	//
	//printf("%d\n", sizeof(*(a[0] + 1)));  // sizeof(*(a[0] + 1))==4---第一行第二个元素的大小
	//printf("%d\n", sizeof(a + 1));        // sizeof(a + 1)==4/8---a作为二维数组的数组名，并没有&，也没有单独放在sizeof内部
	//                                      // 那么数组名a就是首元素（第1行）的地址
	//                                      // 所以a+1，也就是第2行的地址

	//printf("%d\n", sizeof(*(a + 1)));     // sizeof(*(a + 1))==16---第二行的大小 *(a+1)==a[1]
	//printf("%d\n", sizeof(&a[0] + 1));    // sizeof(&a[0] + 1)==4/8---&arr[0]是第一行的地址，+1就是第二行的地址
	//printf("%d\n", sizeof(*(&a[0] + 1))); // sizeof(*(&a[0] + 1))==16---计算的是第二行的大小
	//printf("%d\n", sizeof(*a));           // sizeof(*a)==16---*a==*(a+0)==a[0]
	//                                      // a是二维数组得到数组名，没有&，也没有单独放在sizeof内部
	//                                      // 所以a是二维数组首元素的地址，就是第一行的地址
	//                                      // *a就是第一行的大小

	//printf("%d\n", sizeof(a[3]));         // sizeof(a[3])==16
	//                                      // a[3] - 明确了类型就可以计算大小
	//return 0;
//}


//2.问题描述：输出的是什么？
//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	/**(a + 1)等同于a[1]，第一个是2，a的类型是int [5]，&a的类型就是int(*)[5]，是个数组指针。
//	所以给int(*)[5]类型加一，相当于加了一个int [5]的长度。也就是这个指针直接跳过了a全部的元素，
//	直接指在了刚好越界的位置上，然后转换成了int *后再减一，相当于从那个位置向前走了一个int，
//	从刚好越觉得位置回到了5的地址处，所以第二个是5*/
//	printf("%d,%d", *(a + 1), *(ptr - 1));  //*(a + 1)---2    *(ptr - 1)----5
//	return 0;
//}



//3.问题描述：输出的是什么？
//#include<stdio.h>	
//struct Test
//{
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;

////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	p = (struct Test*)0x00100000;
//	printf("%p\n", p + 0x1);                  //p是结构体的指针，0x100000+20 = 0x00100014
//	printf("%p\n", (unsigned long)p + 0x1);   //0x00100000+1 = 0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);   //0x00100000+4 = 0x100004
//
//	return 0;
//}


//4.问题描述：输出的是什么？
//#include<stdio.h>	
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *)(&a + 1);
//	int *ptr2 = (int *)((int)a+1);

//	/*本平台vs2019是小端存储
//	内存    a  ptr2                                  ptr1
//	        ↓  ↓                                      ↓
//	低地址处 01 00 00 00 | 02 00 00 00 | 03 00 00 00 | 04 00 00 00     高地址处*/
//	printf("%x,%x", ptr1[-1], *ptr2); //ptr1[-1]---00 00 00 04    *ptr2---02 00 00 00   %x打印前面的0会省略
//	return 0;
//}


//5.问题描述：输出的是什么？
//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0,1), (2,3),(4, 5) };
//	//简化后int a[3][2] = { 1, 3, 5 };
//	//1 3
//	//5 0 
//	//0 0
//	int *p;
//	p = a[0];
//	printf("%d", p[0]); //p[0]----1
//	return 0;
//}


//6.问题描述：输出的是什么？
//#include<stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;

//	//小地址减大地址------等于-4
//	//然后将-4以%p形式打印
//	//也就是打印-4的补码
//	//1111 1111 1111 1111 1111 1111 1111 1100-----补码
//	//  F    F   F     F    F    F    F    C
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	/*
//	------------------------------------------------------------------------
//	                                                p[4][2]      a[4][2]
//	 												↓ 	         ↓
//	| | | | | |   | | | | | |   | | | | | |   | | | |▢|▢|   |▢|▢|■| | |
//	   a[0] ↑       a[1]↑           ↑   a[2]    ↑a[3]          a[4]
//	↑       ↑           ↑           ↑           ↑
//	p=a     p+1         p+2         p+3         p+4
//	-----------------------------------------------------------------------
//	*/
//
//	return 0;
//}


//7.问题描述：输出的是什么？
//#include<stdio.h>	
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *ptr1 = (int *)(&aa + 1);
//	int *ptr2 = (int *)(*(aa + 1));

//	/*&aa的类型是int (*)[2][5]，加一操作会导致跳转一个int [2][5]的长度，
//	直接跑到刚好越界的位置。减一以后回到最后一个位置10处。*(aa + 1)相当于aa[1]，也就是第二行的首地址，
//	自然是6的位置。减一以后由于多维数组空间的连续性，会回到上一行末尾的5处。*/
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1)); //*(ptr1 - 1)---10  *(ptr2 - 1)---5
//	return 0;
//}


//8.问题描述：输出的是什么？
//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work", "at", "alibaba" };
//	char** pa = a;
//	pa++;
//  //*pa==at;
//	printf("%s\n", *pa);
//	return 0;
//}



/* 9.作业标题：字符串左旋 */
/*作业内容：实现一个函数，可以左旋字符串中的k个字符，k可以大于字符串长度
例如:
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB. */
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//char* reverseLeftstr(char* str, int k)
//{
//	assert(str != NULL);
//	int len = (int)strlen(str);
//	char* temp = (char*)malloc(len + 1);
//	int pos = k % len;   //断开位置的下标
//	strcpy(temp, str + pos);
//	strncat(temp, str, pos);
//	temp[len] = '\0';
//	return temp;
//}
//int main()
//{
//
//	char* s = "ABCD";
//	printf("%s", reverseLeftstr(s, 7));
//
//	return 0;
//}


//10.问题描述:字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
//比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
//如果n大于等于传进去的字符串长度则返回原来的字符串s
#include<string.h>
#include<stdio.h>
#include<assert.h>
char* reverseLeftWords(char* s, int n)
{
	assert(s != NULL);
	int len = (int)strlen(s);
	char* temp = (char*)malloc(len + 1);
	if (n > 0 && n < len && len>0)
	{
		strcpy(temp, s + n);
		strncat(temp, s, n);
		temp[len] = '\0';
		return temp;
	}
	return s;
}
int main()
{

	char* s = "ABCD";
	printf("%s", reverseLeftWords(s, 8));

	return 0;
}
