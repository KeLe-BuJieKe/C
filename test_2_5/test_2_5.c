#define _CRT_SECURE_NO_WARNINGS 1

//iscntrl-----����������ַ��Ƿ��ǿ����ַ���
//#include<stdio.h>
//#include<ctype.h>
//void test()
//{
//	char arr[20] = "avcdde\0 avc";
//	int i = 0;
//	/* ����ַ���ֱ�������ַ� \0 */
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


//tolower------��д�ַ�תСд
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	char arr[20] = { 0 };
//	gets(arr);//Hello Bit!
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))            //islower-----�ж��ǲ���Сд��ĸa~z
//		{
//			arr[i] = tolower(arr[i]);   //tolower------��д�ַ�תСд
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//
//	return 0;
//}


//toupper---- - Сд�ַ�ת��д
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	char arr[20] = {0};
//	gets(arr);
//	int i = 0;
//	while (arr[i])
//	{
//		if (islower(arr[i]))   //isupper----�ж��ǲ��Ǵ�д��ĸA~Z
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//	return  0;
//}


/*��ҵ���⣺�ַ�����ת���
��ҵ���ݣ�дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
����:����s1 =AABCD��s2 = BCDAA,����1
     ����s1=abcd ��s2=ACBD��  ,����0.
     AABCD����һ���ַ��õ�ABCDA
     AABCD���������ַ��õ�BCDAA
     AABCD����һ���ַ��õ�DAABC*/
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



/*��ҵ����:���Ͼ���
��ҵ����:��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
Ҫ��ʱ�临�Ӷ�С��O(N);*/
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
        printf("����\n");
    }
    else
    {
        printf("������\n");
    }
    return 0;
}