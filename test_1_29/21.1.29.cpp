#define _CRT_SECURE_NO_WARNINGS 1

/*1.��дstrlen����*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* frist = str;
//	while (*str != '\0')        
//	{
//		str++;
//	}
//	return str - frist;         //����ָ��-ָ��ķ����õ��ַ��ĸ���
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n",my_strlen(arr));
//	system("pause");
//	return 0;
//}


/*2.���õݹ�ķ��������ַ������򣬲���� */
//#include<stdio.h>
//#include<string.h>
//void reverse_string(char* arr)
//{
//	int len = strlen(arr);
//	char tmp = *arr;
//	*arr = *(arr + len - 1);
//	*(arr + len - 1) = '\0';
//	if (strlen(arr + 1) >= 2)
//	{
//		reverse_string(arr + 1);
//	}
//	*(arr + len - 1) = tmp;
//}
//
//int main()
//{
//	char arr[100];
//	gets(arr);   //gets()��ȡһ���ַ���
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}


/*3.��Ŀ������������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ���
����5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�
Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
��������:�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1<=n<=100������ʾС�����ϵĿ���ˮƿ����n=0��ʾ�����������ĳ���Ӧ��������һ�С�
�������:����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��*/
//#include<stdio.h>
//int main()
//{
//    int empty_bottle;
//    while (scanf("%d", &empty_bottle) && (empty_bottle != 0))
//    {
//        int sum = 0;
//        while (empty_bottle >= 3)
//        {
//            sum += empty_bottle / 3;
//            empty_bottle = empty_bottle / 3 + empty_bottle % 3;
//            if (empty_bottle + 1 == 3)    //����2��ƿʱ�����ϰ��һƿ���������3����ƿ���Ϳ����ڻ�һƿ���������ϰ�
//            {
//                sum += 1;
//            }
//        }
//
//        printf("%d\n", sum);
//    }
//}


/*4.��Ŀ��������һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�
�����ж������ݡ���������:����int�ͱ�ʾmonth
�������:�����������int��*/
//#include<stdio.h>
//int fib(int month)                             //쳲����������ֳ���������
//{
//    int a = 1, b = 1, c = 1;
//    while (month > 2)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//        month--;
//    }
//    return c;
//}
//int main()
//{
//    int month;
//    while (scanf("%d", &month) != EOF)
//    {
//        printf("%d\n", fib(month));
//    }
//    return 0;
//}


//��չ
//�������쳲���������
//#include<stdio.h>
//#include<stdlib.h>
//long long fib(size_t n)
//{
//	long long* fibArray =malloc(sizeof(long long) * (n + 1));
//	fibArray[0] = 0;
//	if (0 == n)
//	{
//		return fibArray;
//	}
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	long long*arr=fib(n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ",arr[i] );
//	}
//	system("pause");
//	return 0;
//}



/*5.��Ŀ����:������������ڣ���������һ��ĵڼ��졣��
���������ж��飬ע��ѭ������
��������:������У�ÿ�пո�ָ�ֱ����꣬�£���
�������:�ɹ�:����outDay��������ĵڼ���;
ʧ��:����-1*/
//#include<stdio.h>
//int Calculation_day(int year, int month, int day)
//{
//    int sum = 0;
//    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//    {
//        days[1] += 1;
//    }
//    if (day > days[month - 1])
//    {
//        return -1;
//    }
//    else
//    {
//        for (int i = 0; i < month - 1; i++)
//        {
//            sum += days[i];
//        }
//        sum += day;
//    }
//    return sum;
//}
//int main()
//{
//    int year, month, day;
//    while (~scanf("%d%d%d", &year, &month, &day))
//    {
//        printf("%d\n", Calculation_day(year, month, day));
//    }
//    return 0;
//}


/*6.��Ŀ����:����10���������ֱ�ͳ����������������ĸ�����
��������:����10����������Χ-231~231-1�����ÿո�ָ���
�������:���У���һ�������������ڶ��и��������������ʽ��������
ʾ��1
����:-1 2 3 -6 7 8 -1 6 8 10
���:positive:7
negative:3*/
//#include<stdio.h>
//int main()
//{
//    int arr[10];
//    int Positive = 0;
//    int negative = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//        if (arr[i] > 0)
//        {
//            Positive++;
//        }
//        if (arr[i] < 0)
//        {
//            negative++;
//        }
//    }
//    printf("positive:%d\n", Positive);
//    printf("negative:%d\n", negative);
//    return 0;
//}


/*7.��Ŀ����:KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ��������ɵ�����������ͼ����
��������:�������룬һ��������3~20������ʾ���������αߵĳ��ȣ������ֵ�������Ҳ��ʾ���������
�������:���ÿ�����룬�����������ɵĶ�Ӧ���ȵ����������Σ�ÿ�����ֺ�����һ���ո�
ʾ��������:4
���:1
1 2
1 2 3
1 2 3 4*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (~scanf("%d", &num))
//    {
//        for (int i = 1; i <= num; i++)
//        {
//            for (int j = 1; j <= i; j++)
//            {
//                printf("%d ", j);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}


/*8.��Ŀ����������NxM���󣬾���Ԫ�ؾ�Ϊ�������������д������Ԫ��֮�͡�
��������:��һ��ΪN M(N: ����������M: ��������,��M,N<=10)����������N��Ϊ������С�
�������:һ�У����д������Ԫ��֮�͡�*/
//#include<stdio.h>
//int main()
//{
//    int arr[10][10], m, n, sum = 0;
//    scanf("%d%d", &m, &n);
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//            if (arr[i][j] > 0)
//            {
//                sum += arr[i][j];
//            }
//        }
//
//    }
//    printf("%d", sum);
//    return 0;
//}


/*9.��Ŀ����������һ���������У��ж��Ƿ����������У�����ָ�����е�������С����������ߴӴ�С����
��������:��һ������һ������N(3��N��50)��
�ڶ�������N���������ÿո�ָ�N��������
�������:���Ϊһ�У���������������sorted���������unsorted��*/
//#include<stdio.h>
//int main()
//{
//    int num, arr[50];
//    scanf("%d", &num);
//    for (int i = 0; i < num; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int j = 2; j < num; j++)
//    {
//        if (arr[0] < arr[1])    //����
//        {
//            if (arr[j - 1] > arr[j])
//            {
//                printf("unsorted\n");
//                break;
//            }
//            else if (j == num - 1)
//            {
//                printf("sorted\n");
//            }
//        }
//        else                  //����
//        {
//            if (arr[j - 1] < arr[j])
//            {
//                printf("unsorted\n");
//                break;
//            }
//            else if (j == num - 1)
//            {
//                printf("sorted\n");
//            }
//        }
//    }
//    return 0;
//}


/*10.��Ŀ��������һ���������У��������ظ�������������ɾ��ָ����ĳһ�����������ɾ��ָ������֮������У�������δ��ɾ�����ֵ�ǰ��λ��û�з����ı䡣
��������:��һ������һ������(0��N��50)��
�ڶ�������N�������������ÿո�ָ���N��������
������������Ҫ����ɾ����һ��������
�������:���Ϊһ�У�ɾ��ָ������֮������С�*/
//#include<stdio.h>
//int main()
//{
//    int n, k, arr1[50], arr2[50];
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    scanf("%d", &k);
//    int q = 0;
//    for (int j = 0; j < n; j++)
//    {
//        if (arr1[j] != k)
//        {
//            arr2[q++] = arr1[j];
//        }
//    }
//    for (int m = 0; m < q; m++)
//    {
//        printf("%d ", arr2[m]);
//    }
//    return 0;
//}