#define _CRT_SECURE_NO_WARNINGS 1

/*1.���������������������������������������Ƹ�ʽ�ж��ٸ�λ��ͬ
��������:��������
�������:�����Ʋ�ͬλ�ĸ���*/
//#include<stdio.h>
//int diff_bit(int m, int n)
//{
//    int count = 0, c = 0;
//    c = m ^ n;
//    for (int i = 0; i < 32; i++)
//    {
//        if (((c >> i) & 1) == 1)   //c�����ƶ�һλ��������һλ��1��c&1������ǰ��ľͱ����0��ֻʣ���һλ�������1����count++
//        {
//            count++;
//        }
//    }
//    return count;
//}
//int main()
//{
//    int x, y;
//    scanf("%d%d", &x, &y);
//    printf("%d", diff_bit(x, y));
//    return 0;
//}


/*2.��ҵ���⣺��ӡ���������Ƶ�����λ��ż��λ
��ҵ���ݣ���ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������*/
//#include<stdio.h>
//void bitprintf(int x)
//{
//	printf("����λ��\n");
//	for (int j = 31; j>0; j = j - 2)
//	{
//		printf("%d ", (x>>j) & 1);
//	}
//	printf("\n");
//	printf("ż��λ��\n");
//	for (int i = 30; i>=0; i=i-2)
//	{
//		//Ϊʲô��ѡ��<<,����Ϊ����һλ������������ұ߲�0
//		//�ᵼ�´�ӡ���������ֶ���0
//		printf("%d ", (x>>i)&1);           //��������iλ����&1���õ����һλ����������0����1����1�ʹ�ӡ1������ʹ�ӡ0
//	}
//}
//int main()
//{
//	int x;
//	printf("������һ������");
//	scanf("%d", &x);
//	bitprintf(x);
//	return 0;
//}


/*3.������������������1�ĸ���
����һ���������������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/
/*����һ
ȱ�ݣ�������ʲô���ݣ�ѭ����Ҫִ��32��
*/
//#include<stdio.h>
//int NumberOf1(int m)
//{
//    int count = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        if (((m >> i) & 1) == 1)  
//        {
//            count++;
//        }
//    }
//    return count;
//}
////������
////˼·���������ڵ��������ݽ��а�λ������
////���ַ�ʽ�����ݵĶ����Ʊ���λ���м���1��ѭ����ѭ�����Σ������м������λ���㣬���������Ƚϸ�Ч
//int NumberOf1_(int n)
//{
//    int count = 0;                //���磺10�Ķ�����---1010    ��һ��ѭ����n=1010&1001=1000  n�͵���8  
//                                  //                           �ڶ���ѭ����n=1000&0111=0000  n�͵���0
//    while (n)
//    {
//        n = n & (n - 1);
//        count++;
//    }
//    return count;
//}
//int main()
//{
//    int x;
//    printf("������һ������");
//    scanf("%d", &x);
//    //����һ
//    printf("%d\n",NumberOf1(x));
//    //������
//    printf("%d\n", NumberOf1_(x));
//}

//4.�������Ľ���ǣ��� ��
/*������
arr�������ڴ��еĴ洢��ʽΪ��
0x00ECFBF4:  01 00 00 00
0x00ECFBF8:  02 00 00 00
0x00ECFBFC:  03 00 00 00
0x00ECFC00:  04 00 00 00
0x00ECFC04:  05 00 00 00
ָ��p������Ϊshort*���͵ģ����pÿ��ֻ�����������ֽڣ�forѭ�������������ݽ����޸�ʱ��һ�η��ʵ��ǣ�
arr[0]�ĵ������ֽڣ�arr[0]�ĸ������ֽڣ�arr[1]�ĵ������ֽڣ�arr[1]�ĸ������ֽڣ��ʸı�֮���������������£�
0x00ECFBF4:  00 00 00 00
0x00ECFBF8:  00 00 00 00
0x00ECFBFC:  03 00 00 00
0x00ECFC00:  04 00 00 00
0x00ECFC04:  05 00 00 00
������ӡ��0   0   3   4   5
*/
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;        //���ڴ˷�������֤�Ժ󲻷�
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}


/*5.��ҵ���⣺ʹ��ָ���ӡ��������
��ҵ����дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
arr��һ������һά���顣*/
//#include<stdio.h>
//void _printf(int *arr,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *arr);
//		arr++;
//	}
//}
//int main()
//{
//	int arr[5] = {1,2,3,4,5};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	_printf(arr, len);    // ����������������Ԫ�صĵ�ַ
//	return 0;
//}


/*6.�����������ַ�����
��һ���ַ���str�����ݵߵ��������������str�ĳ��Ȳ�����100���ַ���*/

//����һ���ݹ飩
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


//��������ѭ����
//#include<stdio.h>
//#include<string.h>
//void reverse_string(char* str)
//{
//    int len = strlen(str);
//    int left = 0, right = len - 1;
//    while (left < right)
//    {
//        char temp = str[left];
//        str[left] = str[right];
//        str[right] = temp;
//        left++;
//        right--;
//    }
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


/*7.��ҵ����:�������
��ҵ����:��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
���磺2+22+222+2222+22222*/
//#include<stdio.h>
//int Sn(int a)
//{
//	int temp = 0, sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		temp = a + temp*10;
//		sum += temp;
//	}
//	return sum;	
//}
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	printf("ǰ5���Ϊ%d",Sn(a));
//	return 0;
//}


/*8.��ҵ����:��ӡˮ�ɻ���
��ҵ���ݣ����0��100000֮������С�ˮ�ɻ������������
��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ���������:153��1^3��5^3��3^3����153��һ����ˮ�ɻ�������*/
//#include<stdio.h>
//#include<math.h>
//int Power(int i)        //��λ��
//{
//	int temp =i,count=1;
//	while (temp/10)
//	{
//		count++;
//		temp=temp / 10;
//	}
//	return count;
//}
//void Narcissistic_number()
//{
//	for (int i =0; i < 100000; i++)
//	{
//		int sum = 0,temp=i;
//		while (temp)
//		{
//			sum += pow(temp% 10, Power(i));
//			temp = temp / 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//}
//int main()
//{
//	Narcissistic_number();
//	return 0;
//}



/*9.��ҵ���⣺��ӡ����*/
//#include<stdio.h>
//void printf_diamond()
//{
//	for (int i =0; i<13; i+=2)
//	{
//		for (int j = 0; j < 13 - i; j += 2)
//		{
//			printf("  ");
//		}
//		for (int k = 0; k < i + 1; k++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i <11; i += 2)
//	{
//		printf("  ");
//		for (int j = 0; j <=i; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 0; k < 11 - i; k++)
//		{
//			printf(" *");
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	printf_diamond();
//	return 0;
//}


/*10.��ҵ����:����ˮ����
��ҵ����:����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣���*/
//����һ
//#include<stdio.h>
//int Drink_soda(int money)
//{
//	int sum=money;              //�ȳ�ʼ��Ϊmoney����Ϊ�ж���Ǯ�Ϳ��Ժȶ���ƿ��ˮ
//	int empty_bottle= money;    //һ��ʼ�ж���Ǯ���ж��ٸ���ƿ�����Գ�ʼΪmoney
//	while (empty_bottle>1)
//	{
//		sum +=empty_bottle/ 2;     //����ÿ�غϿ�ƿ����������2
//		empty_bottle =empty_bottle/ 2 + empty_bottle% 2;   //--------����ÿ�غϻ�����ˮ��+ʣ���ƿ
//	}
//	return sum;
//}
//int main()
//{
//	int money;
//	printf("���������ж���Ǯ��");
//	scanf("%d", &money);
//	printf("%d", Drink_soda(money));
//	return 0;
//}
// ������������������ˮ����ƿ�ӻ��Ĺ���Ļ������Է��֣���ʵ���Ǹ��Ȳ����У�money*2-1
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	//����2
//	if (money <= 0)
//	{
//		total = 0;
//	}
//	else
//	{
//		total = money * 2 - 1;
//	}
//	printf("total = %d\n", total);
//
//
//	return 0;
//}

/*11.������������һ���ַ���str���*/
//#include<stdio.h>
//#include<string.h>
//ѭ������
//void print(char* ch)
//{
//    int len = strlen(ch);
//    for (int i = len-1; i>=0; i--)
//    {
//        printf("%c", ch[i]);
//
//    }
//}

//�ݹ鷽��
//void print(char* ch)
//{
//	if(*ch!= '\0')
//	{
//		print(ch + 1);
//	}
//	if (*ch != '\0')
//	{
//		printf("%c", *ch);
//	}
//	
//}
//int main()
//{
//    char arr[100];
//    gets(arr);   //gets()��ȡһ���ַ���
//    print(arr);
//    return 0;
//}