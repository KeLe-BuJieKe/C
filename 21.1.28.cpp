#define _CRT_SECURE_NO_WARNINGS 1

/*1.����������������ѭ������*/
//#include <stdio.h>
//int main()
//{
/*���ھֲ�����i��ar[10]��������ڴ��ջ�ϣ�ջ�����ڴ�����ǣ���ʹ�ø�λ��ַ���Ŀռ䣬��ʹ�õ�λ���Ŀռ䡣
���ȴ�������i�ڴ�������ʱ��ֻҪ�����ʵ���Խ��ͻᵼ��ѭ������������Խ����ʣ��Ӷ�ѭ��������i�����ı䣬�ͻᵼ����ѭ��
Ҳ����˵arr[12]���ĵ�ַ��������žֲ�����i�ģ�һ����Ϊarr[12]=0Ҳ���ǵ���i=0������0��ʼѭ��������һ��ѭ�����������ѭ��������
*/
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };           
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}


/*2.����������ģ��ʵ�ֿ⺯��strlen*/
//#include<stdio.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[10] = "asdsad";
//	printf("%d", my_strlen(arr));
//	return  0;
//}


/*3.����������ģ��ʵ�ֿ⺯��strcpy*/
//#include<stdio.h>
//char* my_strcpy(char *destination,const char *str)
//{
//	char* temp = destination;
//	while (*destination++ = *str++)
//	{
//
//	}
//	return  temp;
//}
//int main()
//{
//	char arr1[20] ="abcdefg";
//	char arr2[20]="abcd123";
//	printf("%s", my_strcpy(arr2,arr1));
//	return 0;
//}


/*4.��ҵ���⣺��������ʹ����ȫ����λ��ż��ǰ�档
��Ŀ������һ���������飬ʵ��һ��������
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�*/
//#include<stdio.h>
//void Adjust_array(int *arr,int len)
//{
//	int frist=0, end=len-1,temp=0;
//	while (frist < end)
//	{
//		while ((frist < end)&& (arr[frist] % 2 != 0))
//		{
//				frist++;
//		}
//		while ((frist < end) &&(arr[end] % 2 == 0))
//		{
//			end--;
//		}
//		if (frist < end)
//		{
//			temp = arr[frist];
//			arr[frist] =arr[end];
//			arr[end] =temp;
//		}
//	}
//
//}
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Adjust_array(arr, len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


/*5.��Ŀ����:����:�Ȳ����� 2��5��8��11��14��������
����:������N >0    ���:��Ȳ�����ǰN���
����Ϊ�������룬��ʹ��while(cin>>)����ʽ��ȡ����
��������:����һ����������
�������:���һ����Ӻ��������*/
//#include<stdio.h>
//int sumAsq(int m)
//{
//    return m * (4 + (m - 1) * 3) / 2;
//}
//int main()
//{
//    int m = 0;
//    while (scanf("%d", &m) != EOF)
//    {
//        printf("%d\n", sumAsq(m));
//    }
//
//    return 0;
//}


/*6.��Ŀ����:�ҳ������ַ����д�д�ַ�(��'A' - 'Z')�ĸ�����
�������� :���⺬�ж�����������,����ÿ������������һ�У������ͳ�Ƶ��ַ���
������� :����ÿ�����������һ�������������ַ����д�д��ĸ�ĸ���*/
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char c[10000] = { '\0' };
//    while (gets(c) != NULL)    //getsû�н��ܵ��ַ���ʱ����ֵ----------NULL
//    {
//        int count = 0;
//        int n = strlen(c);
//        for (int i = 0; i < n; i++)
//        {
//            if (c[i] >= 'A' && c[i] <= 'Z')
//            {
//                count++;
//            }
//        }
//        printf("%d\n", count);
//    }
//    return 0;
//}


/*7.��Ŀ����������һ��������������������ַ�������ʽ�������
���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
��������:����һ��int����
�������:������������ַ�������ʽ�������*/
//#include<stdio.h>
//void print(char* c)
//{
//    if (*c != '\0')
//    {
//        print(c + 1);
//    }
//    if (*c != '\0')
//    {
//        printf("%c", *c);
//    }
//        
//}
//int main()
//{
//    char c[20];
//    scanf("%s", &c);
//    print(c);
//    return 0;
//}


/*8.��Ŀ����������һ��ֻ����Сд��ĸ���ַ�����Ȼ��������ַ�����ת����ַ��������ַ������Ȳ�����1000��
�������� :����һ�У�Ϊһ��ֻ����Сд��ĸ���ַ�����
������� :������ַ�����ת����ַ�����*/
//#include<stdio.h>
//#include<string.h>
//void print(char* ch)
//{
//    int len = strlen(ch);
//    for (int i = len - 1; i >= 0; i--)
//    {
//        printf("%c", ch[i]);
//
//    }
//}
//int main()
//{
//    char arr[1000];
//    gets(arr);   //gets()��ȡһ���ַ���
//    print(arr);
//    return 0;
//}


/*9.��Ŀ�������û���¼��վ��ͨ����Ҫע�ᣬһ����Ҫ�����������롣�����ж���������������Ƿ�һ�£�һ�������same������һ�������different��
��������:ÿ���������ÿո�ֿ����ַ�������һ��Ϊ���룬�ڶ���Ϊ�ظ����롣
�������:ÿ�����һ���ַ�������same����different������*/
//#include<stdio.h>
//int main()
//{
//    char s1[100], s2[100];
//    scanf("%s %s", &s1, &s2);
//    if (strcmp(s1, s2) == 0)
//    {
//        printf("same\n");
//    }
//    else
//    {
//        printf("different\n");
//    }
//    return 0;
//}


/*10.��Ŀ������д��һ�����򣬽���һ����������ֵ���������ֵ�Ľ�������ֵ�����С�������ֵ���ڵ���5,����ȡ����С��5��������ȡ����
��������:����һ����������ֵ
�������:�������ֵ�Ľ�������ֵ*/
//#include<stdio.h>
//int main()
//{
//    float f;
//    scanf("%f", &f);
//    int a = (int)f;    //�õ�������λ
//
//    if ((f - a) >= 0.5)
//    {
//        printf("%d", a + 1);
//    }
//    else
//    {
//        printf("%d", a);
//    }
//    return 0;
//}


/*11.��Ŀ����������һ��int�͵����������������int���������ڴ��д洢ʱ1�ĸ�����
��������:����һ��������int���ͣ�
�������:�����ת����2���ƺ����1�ĸ���*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    scanf("%d", &num);
//    int count = 0;
//    while (num)
//    {
//        count++;
//        num = num & (num - 1);
//    }
//    printf("%d", count);
//    return 0;
//}


/*12.��Ŀ����:�����ַ������һ�����ʵĳ��ȣ������Կո������
��������:����һ�У�����Ҫ������ַ������ǿգ�����С��5000��
�������:���һ����������ʾ�����ַ������һ�����ʵĳ��ȡ�*/
//#include<stdio.h>
//#include<string.h>
//int str(char* str1)
//{
//    int  len = strlen(str1);
//    int count = 0;
//    while ((str1[len - 1]) != ' ')
//    {
//        if (len-1>= 0)
//        {
//            count++;
//            len--;
//        }
//        else
//        {
//            break;
//        }
//    }
//    return count;
//}
//int main()
//{
//    char arr[5000];
//    gets(arr);
//    printf("%d", str(arr));
//    return 0;
//}


/*13.��Ŀ��������10��������Ҫ������ʱ���������10������ӡ������������������ǰ��������෴��˳���ӡ��10������
�������� :һ�У�����10����������Χ - 231~231 - 1�����ÿո�ָ���
������� :һ�У�������������10���������ÿո�ָ���*/
//#include<stdio.h>
//int main()
//{
//    int arr[10];
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 9; i >= 0; i--)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}