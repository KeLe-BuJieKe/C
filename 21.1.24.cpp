#define _CRT_SECURE_NO_WARNINGS 1


/*1.����������ʵ��һ�������������ð������*/
//#include<stdio.h>
//void Bubble_sort(int *arr,int len)
//{
//	bool flag = true;
//	for (int i = 0; i < len-1; i++)
//	{
//		for (int j = 0; j <len-i- 1; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//				flag = false;
//			}
//		}
//		if (true == flag)
//		{
//			return;
//		}
//	}
//}
//int main()
//{
//	int arr[10];
//	int len = sizeof(arr) / sizeof(arr[0]);       //�����鳤��
//	for (int i = 0; i < len; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	Bubble_sort(arr,len);
//	printf("�����");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}


/*2.��������������һ���������飬��ɶ�����Ĳ���
ʵ�ֺ���init() ��ʼ������Ϊȫ0
ʵ��print()  ��ӡ�����ÿ��Ԫ��
ʵ��reverse()  �����������Ԫ�ص����á�
Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
*/
//#include<stdio.h>
//void init(int *arr,int row,int value)    //���һά����ĳ�ʼ��  
//{
//	for (int i = 0; i < row; i++)
//	{
//			arr[i] = value;
//	}
//}
//
//void print(int *arr,int row)            //��Զ�ά����Ĵ�ӡ  
//{
//	for (int j = 0; j <row; j++)
//	{
//		printf("%d ", arr[j]);
//	}
//}
//void Reverse(int *arr, int len)
//{
//	for (int i = 0,j = len - 1; i < j; i++, j--)
//	{
//		int temp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = temp;
//	}
//}
//int main()
//{
//	int arr[5] = {1,2,3,4,5};
//	init(arr, 5, 0);
//	Reverse(arr, 5);
//	print(arr, 5);
//}


/*3.����������������A�е����ݺ�����B�е����ݽ��н�����������һ����*/
//#include<stdio.h>
//void swap(int* arr1, int* arr2,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//}
//int main()
//{
//	int arrA[5] = {1,2,3,4,5};
//	int arrB[5] = {99,88,77,66,55};
//	int len = sizeof(arrA) / sizeof(arrA[0]);
//	swap(arrA, arrB,len);
//	for (int i = 0; i < 5;i++)
//	{
//		printf("%d %d\n", arrA[i],arrB[i]);
//	}
//	return 0;
//}


/*4.��Ŀ����:�Ӽ�������a, b, c��ֵ����̼��㲢���һԪ���η���ax2 + bx + c = 0�ĸ�����a = 0ʱ�������Not quadratic equation������a �� 0ʱ�����ݡ� = b2 - 4*a*c������������㲢������̵ĸ���
��������:�������룬һ�У���������������a, b, c����һ���ո�ָ�����ʾһԪ���η���ax2 + bx + c = 0��ϵ����
�������:���ÿ�����룬���һ�У����һԪ���η���ax2 + bx +c = 0�ĸ��������
���a = 0�������Not quadratic equation����
���a ��  0�������������
�� = 0��������ʵ����ȣ������ʽΪ��x1=x2=...��
��  > 0��������ʵ�����ȣ������ʽΪ��x1=...;x2=...������x1  <=  x2��
��  < 0����������������������x1=ʵ��-�鲿i;x2=ʵ��+�鲿i����x1���鲿ϵ��С�ڵ���x2���鲿ϵ����
ʵ��Ϊ0ʱ����ʡ�ԡ�ʵ��= -b / (2*a),�鲿= sqrt(-�� ) / (2*a)
����ʵ������Ҫ��ȷ��С�����2λ�����֡�����֮��û�пո�*/
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    float a, b, c;
//    while (scanf("%f %f %f", &a, &b, &c) != EOF)
//    {
//        if (a == 0)
//        {
//            printf("Not quadratic equation\n");
//        }
//        else
//        {
//            float f = b * b - 4 * a * c;
//            if (f == 0)
//            {
//                printf("x1=x2=%.2f\n", -b / (2 * a));
//            }
//            else if (f > 0)
//            {
//                float x1 = (-b - sqrt(f)) / (2 * a);
//                float x2 = (-b + sqrt(f)) / (2 * a);
//                printf("x1=%.2f;x2=%.2f\n", x1, x2);
//            }
//            else
//            {
//                float m =(-b)/ (2 * a);
//                float n =sqrt(-f) /(2 * a);
//                printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", m, n, m, n);
//            }
//        }
//    }
//    return 0;
//}


/*5.��Ŀ����:KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ�á�*����ɵ��߶�ͼ����
��������:�������룬һ��������1~100������ʾ�߶γ��ȣ�����*����������
�������:���ÿ�����룬���ռһ�У��á�*����ɵĶ�Ӧ���ȵ��߶Ρ�*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (scanf("%d,", &num) != EOF)
//    {
//        for (int i = 0; i < num; i++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*6.��Ŀ����:KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ�á�*����ɵ�������ͼ����
��������:�������룬һ��������1~20������ʾ�����εĳ��ȣ�Ҳ��ʾ���������
�������:���ÿ�����룬����á�*����ɵĶ�Ӧ�߳��������Σ�ÿ����*��������һ���ո�*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (scanf("%d,", &num) != EOF)
//    {
//        for (int j = 0; j < num; j++)
//        {
//            for (int i = 0; i < num; i++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}


/*7.��Ŀ����:KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ�á�*����ɵ�ֱ��������ͼ����
��������:�������룬һ��������2~20������ʾֱ��������ֱ�Ǳߵĳ��ȣ�����*����������Ҳ��ʾ���������
�������:���ÿ�����룬����á�*����ɵĶ�Ӧ���ȵ�ֱ�������Σ�ÿ����*��������һ���ո�*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (scanf("%d,", &num) != EOF)
//    {
//        for (int j = 0; j < num; j++)
//        {
//            for (int i = 0; i <= j; i++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}


/*8.��Ŀ����:���굽���������Ϣӭ�����ꡣ
��������:��
�������:Happy New Year*2019* */
//#include<stdio.h>
//int main()
//{
//    printf("Happy New Year*2019*");
//    return 0;
//}


/*9.��Ŀ����:����һ���ǳ��򵥵���Ŀ�����ڿ������̵Ļ���������ǧ���������Ŷ������Ϊһ�У�
�������ÿո�ָ����ĸ�����a��b��c��d��0 < a, b, c, d < 100,000�������Ϊһ�У�Ϊ��(a+b-c)*d���ļ�������
��������:����Ϊһ�У��ÿո�ָ����ĸ�����a��b��c��d��0 < a, b, c, d < 100,000����
�������:���Ϊһ�У�Ϊ��(a+b-c)*d���ļ�������*/
//#include<stdio.h>
//int main()
//{
//    int a, b, c, d;
//    scanf("%d%d%d%d", &a, &b, &c, &d);
//    printf("%d", (a + b - c) * d);
//    return 0;
//}


/*10.��Ŀ����:�и����ϵͳ��¼���û���������Ϊ���û�����admin�����룺admin�����û������û��������룬�ж��Ƿ��¼�ɹ���
��������:����������ݣ�ÿ���������ÿո�ֿ����ַ�������һ��Ϊ�û������ڶ���λ���롣
�������:���ÿ������������ݣ����Ϊһ�У�һ���ַ�������Login Success!����Login Fail!������*/
//#include<stdio.h>
//int main()
//{
//    char name[20] = "admin";
//    char password[20] = "admin";
//    char name1[20];
//    char password1[20];
//    while (scanf("%s %s", name1, password1) != EOF)
//    {
//        if (strcmp(name, name1) == 0 && strcmp(password, password1) == 0)
//        {
//            printf("Login Success!\n");
//        }
//        else
//        {
//            printf("Login Fail!\n");
//        }
//    }
//    return 0;
//}


/*11.��Ŀ����
�ж�һ�������Ƿ���5������һ��ͦ�򵥵����⣬�����KiKi���ǲ����Լ����������ҵ������д���룬��Ͱ�����ɡ�
��������:�������һ������M��1��M��100,000����
�������:�������һ�У����M���Ա�5���������YES���������NO�������Сд���У���*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    scanf("%d", &num);
//    if (num % 5 == 0)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//    return 0;
//}


/*12.��Ŀ����:�Ӽ�������5���˵���ߣ��ף��������ǵ�ƽ����ߣ��ף���
��������:һ�У���������5����ߣ���Χ0.00~2.00�����ÿո�ָ���
�������:һ�У����ƽ����ߣ�������λС����*/
//#include<stdio.h>
//int main()
//{
//    float arr[5];
//    float f = 0.0;
//    for (int i = 0; i < 5; i++)
//    {
//        scanf("%f", &arr[i]);
//        f += arr[i];
//    }
//    printf("%.2f", f / 5.0);
//    return 0;
//}