#define _CRT_SECURE_NO_WARNINGS 1

/*1.������������ʹ���ۼƳ˷��Ļ����ϣ�ͨ����λ���㣨<<��ʵ��2��n�η��ļ��㡣
�����������������룬ÿһ����������n��0 <= n < 31����
������������ÿ�����������Ӧ��2��n�η��Ľ����*/
//#include<stdio.h>
//int main()
//{
//    int a;
//    while (scanf("%d", &a) != EOF)
//    {
//        //1�����ƶ�aλ
//        printf("%d\n", 1<<a);     //�����ƶ�һλ����ԭ����������  ���磺2�����ƶ�һλ�͵���4
//    }
//    return 0;
//}


/*2.����������BoBo����һ�����̣�������n��δ�򿪵����̣�
KiKiϲ�������̣���һʱ�䷢�������̡�KiKiÿh�����ܺȹ�һ�����̣�
����KiKi�ںȹ�һ������֮ǰ�������һ������ô����m���Ӻ��ж��ٺ�δ�򿪵����̣�*/
//#include<stdio.h>
//int main()
//{
//    int n;   //һ����n��
//    int h;   //h���Ӻ���һ������
//    int m;   //����m����
//    
//    while (scanf("%d %d %d",&n,&h,&m)!= EOF)
//    {
//        if (m % h == 0)
//        {
//            printf("%d", n - m / h );
//        }
//        else
//        {
//            printf("%d", n - m / h-1);
//        }
//    }
//    return 0;
//}


/*3.�����������ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ*/
//#include<stdio.h>
//void print(int m)
//{
//	if (m > 9)
//	{
//		print(m / 10);
//	}
//	printf("%d ", m%10);
//	
//}
//int main()
//{
//	int x;
//	printf("��������Ҫ��ӡ�����֣�");
//	scanf("%d", &x);
//	print(x);
//	return 0;
//}


/*4.�����������ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩*/
//#include<stdio.h>
//int fac1(int n)   //�ݹ�
//{
//	if (n<=1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n* fac1(n - 1);
//	}
//}
//
//int fac2(int n)  //�ǵݹ�
//{
//	int temp = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		temp *= i;
//	}
//	return temp;
//}
//int main()
//{
//	int x;
//	printf("����������Ҫ�󼸵Ľ׳ˣ�");
//	scanf("%d", &x);
//	int f1=fac1(x);
//	printf("�ݹ�:  %d\n", f1);
//	int f2=fac2(x);
//	printf("�ǵݹ�:%d", f2);
//	return 0;
//}


/*5.�����������ݹ�ͷǵݹ�ֱ�ʵ��strlen*/
//#include<stdio.h>
//int my_strlen1(char *arr)   //�ݹ�
//{
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen1(++arr);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int my_strlen2(char* arr)   //�ǵݹ�
//{
//	int count = 0;
//	while(*arr != '\0')
//	{
//		++arr;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "dasfas";
//	int  temp1=my_strlen1(arr);  //�ݹ�
//	printf("�ݹ�:  %d\n", temp1);
//	int  temp2=my_strlen2(arr);  //�ǵݹ�
//	printf("�ǵݹ�:%d", temp2);
//	return 0;
//}


/*6.�����������ַ������򣨵ݹ�ʵ�֣�
��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������*/
//#include<stdio.h>
//#include<string.h>
//void reverse_string(char*arr)
//{
//	int len = strlen(arr);
//	char temp = *arr;
//	*arr = *(arr + len - 1);
//	*(arr + len - 1) = '\0';
//
//	if (strlen(arr + 1) >= 2)
//	{
//		reverse_string(arr + 1);
//	}
//	*(arr + len - 1) = temp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}


/*7.����������дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
���룺1729�������19*/
//#include<stdio.h>
//int DigitSum(int num)
//{
//	while (num % 10)
//	{
//		if (num < 9)
//		{
//			return num;
//		}
//		return num % 10 + DigitSum(num / 10);
//	}
//}
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	int temp=DigitSum(num);
//	printf("%d", temp);
//}


/*8.������������дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�*/
//#include<stdio.h>
//double pow(double n, double k)
//{
//	if (k==0)           //ͨ���ж�k��ϵ�����Ƿ�Ϊ0��Ϊ���ֱ�ӷ���1
//	{
//		return 1;
//	}
//	return n * pow(n, k - 1);
//	
//}
//int main()
//{
//	double n, k;
//	scanf("%lf%lf", &n,&k);
//	double temp=pow(n, k);
//	printf("%lf", temp);
//	return 0;
//}


/*9.��������������쳲�������
�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
���磺
���룺5  �����5
���룺10�� �����55
���룺2�� �����1*/
//#include<stdio.h>
//int Fib1(int num)          //�ݹ�
//{
//	if (num <= 2)
//	{
//		return 1;
//	}
//	return Fib1(num - 1)+Fib1(num - 2);
//}
//
//int Fib2(int num)          //�ǵݹ�
//{
//	int a = 1, b = 1, c = 1;
//	while (num > 2)
//	{
//		c = a + b;        
//		a = b;
//		b = c;
//		num--;
//	}
//	return c;
//}
//
//int main()
//{
//	int num;
//	printf("����������Ҫ�鿴�ĵڼ���쳲���������");
//	scanf("%d", &num);
//	int temp1=Fib1(num);     //�ݹ�
//	printf("%d\n", temp1);
//
//	int temp2 = Fib2(num);   //�ǵݹ�
//	printf("%d", temp2);
//	return 0;
//}


/*10.����������ѧ����Ϣ����ϵͳ��ѧУ��ѧ�������Ҫ���ߣ�����һ��ѧ��������Ϣ���£�
����-Jack������-18���Ա�-Man���밴����������ĸ�ʽ�����ѧ������Ϣ��*/
//#include<stdio.h>
//int main()
//{
//    printf("Name    Age    Gender\n");
//    printf("---------------------\n");
//    printf("Jack    18     man\n");
//    return 0;
//}


/*11.�����������Ӽ�������5��ѧ���ĳɼ����������������ǵ�ƽ���ɼ���������������һλС������
��������:һ�У���������5����������Χ0~100�����ÿո�ָ���
�������:һ�У����5������ƽ����������һλС������*/
//#include<stdio.h>
//int main()
//{
//    int arr[5] = { 0 };
//    float sum = 0;
//    for (int i = 0; i < 5; i++)
//    {
//        scanf("%d", &arr[i]);
//        sum += arr[i];
//    }
//    printf("%.1f", sum / 5.0);
//    return 0;
//}


/*12.�����������Ӽ�����������һ���ַ�������ж��Ƿ�����ĸ��������Сд����
��������:�������룬ÿ���������һ���ַ���
�������:���ÿ�����룬������ַ�����ĸ��YES�����ǣ�NO����*/
//#include<stdio.h>
//int main()
//{
//    char c = '0';
//    while (scanf("%c", &c) != EOF)
//    {
//        if (c >= 'A' && c <= 'Z' || c>='a' && c <= 'z')
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//        getchar();            //�������з���Ӱ��
//    }
//    return 0;
//}


/*13.����������BMIָ��������������ָ�����������ع����������������ƽ���ó�������
���磺һ���˵����Ϊ1.75�ף�����Ϊ68ǧ�ˣ�����BMI=68/(1.75^2)=22.2��ǧ��/��^2����
��BMIָ��Ϊ18.5��23.9ʱ�������������ʾ������ڽ������ա�����ж����彡�������
��������:һ�У�����һ���˵����أ�ǧ�ˣ�����ߣ��ף����м���һ���ո�ָ���
�������:һ�У��������Normal(����)��Abnormal(������)��*/
//#include<stdio.h>
//int main()
//{
//    float height;
//    float weight;
//    scanf("%f%f", &weight, &height);
//    float bmi = weight / (height * height);
//    if (bmi >= 18.5 && bmi <= 23.9)
//    {
//        printf("Normal\n");
//    }
//    else
//    {
//        printf("Abnormal\n");
//    }
//    return 0;
//}