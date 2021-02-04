#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>


//�ж�i�ǲ����������Ǿͷ���1�����Ƿ���0
int is_prime(int j)
{
	for (int i = 2; i <= sqrt(j); i++)
	{
		if (i % j == 0)
		{
			return 0;
		}
	}
	return 1;
}


//�ж�����
//1.�ܱ�4�������Ҳ��ܱ�100����������
//2.�ܱ�400����������
void leap_year(int i)
{
	int count = 0;

	if (i % 4 == 0 && i % 100 != 0)
	{
		count++;
		printf("%d ", i);
	}
	else if (i % 400 == 0)
	{
		count++;
		printf("%d ", i);
	}
	printf("����Ϊ��%d", count);
}


/*1.����������KiKi����ĳ��ĳ���ж����죬��������ʵ�֡�������ݺ��·ݣ�������һ��������ж����졣
�����������������룬һ���������������ֱ��ʾ��ݺ��·ݣ��ÿո�ָ���
������������ÿ�����룬���Ϊһ�У�һ����������ʾ��һ��������ж�����*/
//int main()
//{
//    int year = 0;
//    int month = 0;
//    while (scanf("%d %d", &year, &month) != EOF)
//    {
//        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//        {
//            if (month == 2)
//            {
//                printf("%d\n", 29);
//            }
//            else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//            {
//                printf("%d\n", 31);
//            }
//            else
//            {
//                printf("%d\n", 30);
//            }
//        }
//        else
//        {
//            if (month == 2)
//            {
//                printf("%d\n", 28);
//            }
//            else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//            {
//                printf("%d\n", 31);
//            }
//            else
//            {
//                printf("%d\n", 30);
//            }
//        }
//    }
//    return 0;
//}



/*2.��������������Ա�����ֳ���֡���7λ���٣��Ӽ�������������ɼ���ÿ��7���������ٷ��ƣ���ȥ��һ����߷ֺ�һ����ͷ֣����ÿ���ƽ���ɼ���
����������һ�У�����7��������0~100��������7���ɼ����ÿո�ָ���
���������һ�У����ȥ����߷ֺ���ͷֵ�ƽ���ɼ���С�������2λ��ÿ��������С�*/
//#include<stdio.h>
//int main()
//{
//    float sum = 0;
//    int score[7] = {};
//    for (int i = 0; i < 7; i++)
//    {
//        scanf("%d ", &score[i]);
//        sum += score[i];
//    }
//
//    int min = 100;
//    int max = 0;
//    for (int j = 0; j < 7; j++)
//    {
//        if (max < score[j])
//        {
//            max = score[j];
//        }
//        if (min > score[j])
//        {
//            min = score[j];
//        }
//    }
//    printf("%.2f", (sum - max - min) / 5.0);
//    return 0;
//}



/*3.����������ʵ��һ���������ж�һ�����ǲ�����������������ʵ�ֵĺ�����ӡ100��200֮���������*/
//void is_prime(int n, int m)
//{
//	for (int i = n; i <=m; i++)
//	{
//		bool prime = true;
//		for(int j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				prime = false;
//				break;
//			}
//		}
//		if (true == prime)
//		{
//			printf("%d ", i);
//		}
//	}
//}
//int main()
//{
//	int a1, a2;
//	printf("������һ����Χ��");
//	scanf("%d %d", &a1, &a2);
//	is_prime(a1, a2);
//	return 0;
//}



/*4.���������������ж�����*/
//void is_leap(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		printf("%d������", year);
//	}
//	else
//	{
//		printf("%d��������", year);
//	}
//}
//int main()
//{
//	int year = 0;
//	printf("������һ����ݣ�");
//	scanf("%d", &year);
//	is_leap(year);
//	return 0;
//}



/*5.����������ʵ��һ��������������������������*/
//void swap(int*x, int*y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int main()
//{
//	int x=0,y=0;
//	printf("��������Ҫ���������֣�\n");
//	scanf("%d%d", &x, &y);
//	printf("����ǰx=%d y=%d\n", x, y);
//	swap(&x, &y);
//	printf("������x=%d y=%d\n", x, y);
//	return 0;
//}



/*6.����������ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
�磺����9�����9*9�ھ������12�����12*12�ĳ˷��ھ���*/
//void _99multiplication(int n)
//{
//	for (int i = 1; i<=n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%-2d*%-2d=%-4d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int m;
//	printf("����������Ҫ��ӡ���ٽ׳˷���\n");
//	scanf("%d", &m);
//	_99multiplication(m);
//}



/*7.����������KiKi����5���ˣ��Ѿ��ܹ���ʶ100���ڵķǸ����������Ҳ����ܹ����� 100 ���ڵķǸ������ļӷ����㡣
������BoBo��ʦ����KiKi�ڽ��д��ڵ���100���������ļ���ʱ���������£�
1.ֻ���������������λ�����磺��KiKi��˵1234�ȼ���34��
2.������������ڵ��� 100����ôKIKIҲ�������������������λ���������λ��ʮλΪ0����ֻ������λ��
���磺45+80 = 25
Ҫ������Ǹ����� a�� b��ģ��KiKi������������� a+b ��ֵ��
*/
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d", (a + b) % 100);
//	return 0;
//}


/*8.��������������һ����������Ҫ��õ��ø������ĸ�λ����*/
//#include<stdio.h>
//int main()
//{
//	float f = 0;
//	scanf("%f", &f);
//	printf("%d", (int)f % 10);       //ͨ��ǿתΪint�ͣ����������С����ʧ��Ȼ���10ȡ��õ���λ��
//	return 0;
//}



/*9.����������һ��Լ��3.156��107s��Ҫ�������������䣬��ʾ������϶����롣*/
//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	printf("%lld",(long long)age * 31560000);   //long long�����롢�����ʽΪlld  ����int�ͷ�Χ��С��ǿ��װ����long long���
//	return 0;
//}



/*10.������������������seconds (0< seconds < 100,000,000)������ת����Сʱ�����Ӻ��롣
���������һ�У�������������������Ϊ����������Ӧ��Сʱ����������������������Ϊ�㣩���м���һ���ո������*/
//#include<stdio.h>
//int main()
//{
//	int seconds = 0;
//	scanf("%d", &seconds);
//	printf("%d %d %d", seconds / 3600, seconds % 3600 / 60, seconds % 3600 % 60);
//	return 0;
//}


/*11.������������������һ��ѧ����3�Ƴɼ�������Ļ�������ѧ�����ܳɼ��Լ�ƽ���ɼ���*/
//#include<stdio.h>
//int main()
//{
//	float a = 0, b = 0, c = 0;
//	scanf("%f%f%f", &a, &b, &c);
//	printf("%.2f %.2f", a + b + c, (a + b + c) / 3);
//	return 0;
//}


/*12.����������BMIָ���������ع����������������ƽ���ó������֣���Ŀǰ�����ϳ��õĺ����������ݳ̶��Լ��Ƿ񽡿���һ����׼��
���������һ�У�BMIָ����������λС������*/
//int main()
//{
//	int height;
//	int weight;
//	scanf("%d%d", &weight, &height);
//	if (height != 0)
//	{
//		float bmi = weight / ((height / 100.00) * (height / 100.00));
//		printf("%.2f", bmi);
//	}
//
//	return 0;
//}


/*13.��������������һ������İ뾶��������������������������ʽΪ V = 4/3*��r3������ ��= 3.1415926��
����������һ�У��ø�������ʾ������İ뾶��
���������һ�У�����������С�������3λ��*/
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	const double PI = 3.1415926;
//	float r = 0;
//	scanf("%f", &r);
//	printf("%.3f", 4 / 3.0 * PI * pow(r, 3));
//	return 0;
//}


/*14.����������ʵ����ĸ�Ĵ�Сдת�����������������
�����������������룬ÿһ�������д��ĸ��
������������ÿ�����������Ӧ��Сд��ĸ��*/
//#include<stdio.h>
//int main()
//{
//	char c = '0';
//	while (scanf("%c", &c) != EOF)
//	{
//		getchar();       //����\n��Ӱ��
//		printf("%c\n", c + 32);
//	}
//	return 0;
//}