#define _CRT_SECURE_NO_WARNINGS 1


/*1.��ҵ����:�������
��ҵ����:����Ļ�ϴ�ӡ������ǡ�
1
1 1
1 2 1
1 3 3 1
����*/
//#include<stdio.h>
//void yangHuiTriangle(int n)
//{
//	int arr[20][20];
//	for (int i = 0; i < n; i++)          //�����߶���ʼ��Ϊ1
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;                //1��2�ж���1�������Ѿ��ѵ�1�к͵�2�г�ʼ��Ϊ1��
//	}
//	/*�������������ʾЧ����һ�����������Σ���������߶���1
//    ������ǵĸ������ڣ�ÿ�����������Ϸ�����֮��*/
//	for (int i = 2; i <=n; i++)          //�ӵ����п�ʼ�仯
//	{
//		for (int j = 1; j<i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//
//	//��ӡ
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	yangHuiTriangle(n);
//	return 0;
//}


/*2.��ҵ���⣺������
��ҵ���ݣ��ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
����Ϊ4�����ɷ��Ĺ���:
A˵�������ҡ� B˵����C�� C˵����D�� D˵��C�ں�˵����֪3����˵���滰��1����˵���Ǽٻ���
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�*/
//#include<stdio.h>
//int main()
//{
//    int k = 0;
//    for (k == 'A'; k <= 'D'; k++)//��A��ʼ�ж�
//    {
//        if ((k != 'A') + (k == 'C') + (k == 'D') + (k != 'D') == 3)//�����ֵ�����
//        {
//            printf("k=%c\n", k);
//        }
//    }
//    return 0;
//}


/*3.��ҵ����:������
��ҵ����:5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�*/
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if ((a * b * c * d * e == 120) && (a + b + c + d + e == 15))  //�����ظ�
//							{
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//							}
//
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}


/*4.��������ִ�н����*/
#include<stdio.h>
int main()
{
    const char str1[] = "hello bit.";
    const char str2[] = "hello bit.";
    const char* str3 = "hello bit.";
    const char* str4 = "hello bit.";

    //str1��str2���������飬����Ĳ�����ʽ�ǽ��ұ߳����ַ��������ݿ������������������������ռ䣬ֻ��������ͬ������str1 != str2��
    if (str1 == str2)
    {
        printf("str1 and str2 are same\n");
    }
    else
    {
        printf("str1 and str2 are not same\n");
    }
    //��str3��str4������ָ�룬�������ڴ�����ʱ�򣬻Ὣ��ͬ�ĳ����ַ�������ͬһ����ַ�����ԣ�str3��str4ָ�����ͬһ�������ַ���������str3 == str4
    if (str3 == str4)
    {
        printf("str3 and str4 are same\n");
    }
    else
    {
        printf("str3 and str4 are not same\n");
    }
    return 0;
}