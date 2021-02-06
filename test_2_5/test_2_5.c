#define _CRT_SECURE_NO_WARNINGS 1

//iscntrl-----检查所传的字符是否是控制字符。
//#include<stdio.h>
//#include<ctype.h>
//void test()
//{
//	char arr[20] = "avcdde\0 avc";
//	int i = 0;
//	/* 输出字符串直到控制字符 \0 */
//	while (!iscntrl(arr[i]))
//	{
//		putchar(arr[i]);
//		i++;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}


//tolower------大写字符转小写
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	char arr[20] = { 0 };
//	gets(arr);//Hello Bit!
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))            //islower-----判断是不是小写字母a~z
//		{
//			arr[i] = tolower(arr[i]);   //tolower------大写字符转小写
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//
//	return 0;
//}


//toupper---- - 小写字符转大写
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	char arr[20] = {0};
//	gets(arr);
//	int i = 0;
//	while (arr[i])
//	{
//		if (islower(arr[i]))   //isupper----判断是不是大写字母A~Z
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//	return  0;
//}


/*作业标题：字符串旋转结果
作业内容：写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如:给定s1 =AABCD和s2 = BCDAA,返回1
     给定s1=abcd 和s2=ACBD，  ,返回0.
     AABCD左旋一个字符得到ABCDA
     AABCD左旋两个字符得到BCDAA
     AABCD右旋一个字符得到DAABC*/
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//void reverse_str(char*left, char* right)
//{
//    assert(left!=NULL&&right!=NULL);
//    while (left<right)
//    {
//        char temp = *left;
//        *left = *right;
//        *right = temp;
//        left++;
//        right--;
//    }
//}
//
//char *str_move(const char* str, int k)
//{
//    assert(str != NULL);
//    int len = strlen(str);
//    reverse_str(str, str + k-1);
//    reverse_str(str + k, str + len - 1);
//    reverse_str(str, str + len - 1);
//    return (char *)str;
//}
//
//int is_str_move(const char*str1,const char*str2)
//{
//    assert(str1!= NULL &&str2!= NULL);
//    int len = strlen(str1);
//    while (len--)
//    {
//        str_move(str1, 1);
//        if (strcmp(str1, str2) == 0)
//        {
//            return 1;
//        }
//    }
//    return 0;
//}
//int main()
//{
//    char arr1[] = "ABCDE";
//    char arr2[] = "CDEAB";
//    //str_move(arr1, 2);
//    if (is_str_move(arr1, arr2))
//    {
//        printf("Yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//    return 0;
//}



/*作业标题:杨氏矩阵
作业内容:有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
要求：时间复杂度小于O(N);*/
#include<stdio.h>
int search(int arr[][3], int key,int row,int col)
{
    int x=0,y=col-1;
    while (x<=row-1&&y>=0)
    {
        if (arr[x][y] < key)
        {
            x++;
        }
        else if (arr[x][y] > key)
        {
            y--;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}
int main()
{
    int arr[3][3] = { 3,4,5,6,7,8,9,10,11 };
    if (search(arr, 8,3,3) == 1)
    {
        printf("存在\n");
    }
    else
    {
        printf("不存在\n");
    }
    return 0;
}