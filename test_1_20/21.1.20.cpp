#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<time.h>
#include<math.h>

int max3(int a, int b, int c)
{
    return a > b ? a : b > c ? b : c;
}


void menu()
{
    printf("---------------------\n");
    printf("     1.����Ϸ        \n");
    printf("     2.�˳���Ϸ      \n");
    printf("---------------------\n");
}


void GuessNum()
{
    srand((unsigned int)time(NULL));
    int m = rand() % 100 + 1;
    while (true)
    {
        int Num;
        cout << "�������" << endl;
        cin >> Num;
        if (m == Num)
        {
            cout << "��ϲ������" << endl;
            break;
        }
        else if (m > Num)
        {

            cout << "��С�ˣ������²�" << endl;
        }
        else
        {
            cout << "�´��ˣ������²�" << endl;
        }
    }
}


//int main()
//{
    //1.����������С���ֵ���ʦBoBo��֪���༶��˭����ѧ�ɼ���ߣ����̰���ʵ�֡�
    //��һ������һ����n������С���ֵİ༶��n��ͬѧ��
    //�ڶ�������n�������ÿո����������༶��ÿ���˵���ѧ�ɼ���
    //һ������������༶����ߵ���ѧ�ɼ���
    //int x, arr[100], max = 0;
    //scanf("%d", &x);
    //for (int i = 0; i <x; i++)
    //{
    //    scanf("%d", &arr[i]);
    //    if (max < arr[i])
    //    {
    //        max = arr[i];
    //    }
    //}
    //printf("%d", max);


    //2.����������С���������һ��1!+2!+3!+...+n!��
    //int n, Fac = 1, sum = 0;
    //scanf("%d", &n);
    //for (int i = 1; i <= n; i++)
    //{
    //    Fac = Fac * i;
    //    sum = sum + Fac;
    //}
    //printf("%d", sum);


    //3.����������С����ѧ�����Զ��庯����BoBo��ʦ�������˸����⣬�������¹�ʽ����m��ֵ��
    //m=max3(a + b, b, c)/max3(a, b + c, c) + max3(a, b, b + c
    //���� max3����Ϊ���������������ֵ���磺 max3(1, 2, 3) ���ؽ��Ϊ3��
    //int a, b, c;
    //float m = 0;
    //scanf("%d %d %d", &a, &b, &c);
    //m =(float) max3(a + b, b, c)*1.0/(max3(a, b + c, c) + max3(a, b, b + c));
    //printf("%f", m);


    //4.����������ȷ����ͬ���������������ڴ���ռ����ֽڣ��������ͬ���������������ڴ���ռ����ֽڣ���
    //��ͬ���������������ڴ���ռ����ֽڣ��������ʽ��������������������е� ? Ϊ��ͬ���������������ڴ���ռ���ֽ�����
    //����������£�
    /* The size of short is ? bytes.
    The size of int is ? bytes.
    The size of long is ? bytes.
    The size of long long is ? bytes.*/

    //printf("The size of short is %d bytes.\n", sizeof(short));        2
    //printf("The size of int is %d bytes.\n", sizeof(int));            4   
    //printf("The size of long is %d bytes.\n", sizeof(long));          4
    //printf("The size of long long is %d bytes.\n", sizeof(long long));8


    //5.����������������������a��b (��10,000 < a,b < 10,000)������a����b�������̺�������
    //int a = 0, b = 0;
    //scanf("%d%d", &a, &b);
    //printf("%d %d", a / b, a % b);


    //6.�����������������ʽ��(-8+22)��a-10+c��2�������У�a = 40��c = 212��
    //int a = 40;
    //int c = 212;
    //int ret = (-8 + 22) * a - 10 + c / 2;
    //printf("%d\n", ret);


    //7.����������KiKi��֪���Ѿ�������������a��b��c�ܷ񹹳������Σ�����ܹ��������Σ��ж������ε����ͣ��ȱ������Ρ����������λ���ͨ�����Σ���
    //int  a, b, c;
    //while (scanf("%d%d%d", &a, &b, &c) != EOF)
    //{
    //    if (a + b > c && a + c > b && c + b > a)
    //    {
    //        if (a == b && b == c)
    //        {
    //            printf("Equilateral triangle!\n"); //�ȱ�
    //        }
    //        else if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
    //        {
    //            printf("Isosceles triangle!\n");//����
    //        }
    //        else
    //        {
    //            printf("Ordinary triangle!\n");//��ͨ
    //        }
    //    }
    //    else
    //    {
    //        //����
    //        printf("Not a triangle!\n");
    //    }
    //}


    //8.����������KiKiд��һ�������Hello world!���ĳ���BoBo��ʦ������printf�����з���ֵ�����ܰ���д���������printf(��Hello world!��)�ķ���ֵ��
    //printf�ķ���ֵ���ַ��ĸ���
    //int a = printf("Hello world!");
    //printf("\n");
    //printf("%d", a);


    //9.��������������3�Ƴɼ���Ȼ������Ƴɼ�������ɼ�Ϊ������ʽ��
    //int score1 = 0, score2 = 0, score3 = 0;
    //scanf("%d%d%d", &score1, &score2, &score3);
    //printf("score1=%d,score2=%d,score3=%d", score1, score2, score3);


    //10.�������������ݸ�����������3����a, b, c��0 < a, b, c < 100,000�������������ε��ܳ��������
    //int a = 0, b = 0, c = 0;
    //scanf("%d%d%d",&a,&b,&c);
    //float len =a+b+c;
    //float p = (a + b + c) / 2.0;
    //float area = sqrt(p * (p - a) * (p - b) * (p - c));
    //printf("circumference=%.2f area=%.2f", len, area);


    //11.����������.KiKi�μ������ġ���ѧ������Ŀ��ԣ�������ж������е���߷֡��Ӽ���������������������ʾ�ķ���������ж����е���߷֡�
    //�������룬ÿ�������������������ʾ�ķ�����0~100�����ÿո�ָ���
    //int a, b, c;
    //while (scanf("%d%d%d", &a, &b, &c) != EOF)
    //{
    //    printf("%d\n", (a > b ? a : b) > c ? (a > b ? a : b) : c);
    //}


    //12.����������KiKi�������ĸ��Сдת������һ���ַ����ж����Ƿ�Ϊ��д��ĸ������ǣ�����ת����Сд��ĸ����֮��ת��Ϊ��д��ĸ��
    //char c = '0';
    //while (scanf("%c", &c) != EOF)
    //{
    //    if (c >= 'A' && c <= 'Z')
    //        printf("%c\n", c + 32);
    //    else if (c >= 'a' && c <= 'z')
    //        printf("%c\n", c - 32);
    //}


    //13.������������������Ϸ 
//    int select = 0;
//    while (true)
//    {
//        menu();
//        scanf("%d", &select);
//        switch (select)
//        {
//        case 1:
//            GuessNum();
//            system("pause");
//            system("cls");
//            break;
//        case 0:
//            exit(0);
//        default:
//            printf("������������������\n");
//            system("pause");
//            system("cls");
//            break;
//        }
//    }
//
//    return 0;
//}


//14.������������������һ��ѧ����ѧ�ţ��Լ�3�ƣ�C���ԣ���ѧ��Ӣ��ɼ�������Ļ�������ѧ����ѧ�ţ�3�Ƴɼ���
//#include<stdio.h>
//int main()
//{
//    
//    int no;
//    float English_score;
//    float C;
//    float math_score;
//    scanf("%d;%f,%f,%f\n", &no, &C, &English_score, &math_score);
//    printf("The each subject score of  No. %d is %.2f, %.2f, %.2f.", no, C, English_score,math_score);
//    return 0;
//
//}
//    


//15.����������BoBo��KiKi�ַ��������ַ�������ʾ���ַ����ڴ�����ASCII����ʽ�洢��BoBo����һ�������KiKi��ת������ASCII��Ϊ��Ӧ�ַ���������ǡ�
//73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33
//#include<stdio.h>
//int main()
//{
//    printf("%c%c%c%c%c%c%c%c%c%c%c%c", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105,116, 33);
//    return 0;
//}


//16.��������������������������Χ-231~231-1�������������������
//#include<stdio.h>
//int main()
//{
//    int a;
//    int b;
//    int temp;
//    scanf("a=%d,b=%d", &a, &b);
//    temp = b;
//    b = a;
//    a = temp;
//    printf("a=%d,b=%d", a, b);
//    return 0;
//}


//17.��������������һ���˵ĳ������ڣ����������գ������������е��ꡢ�¡��շֱ������
//���У���һ��Ϊ������ݣ��ڶ���Ϊ�����·ݣ�������Ϊ�������ڡ����ʱ����·ݻ�����Ϊ1λ������Ҫ��1λ��ǰ�油0��
//#include<stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%4d%2d%2d", &a, &b, &c);
//    printf("year=%d\nmonth=%02d\ndate=%02d\n", a, b, c);
//    return 0;
//}


//18.����������BoBo��KiKi�ַ��������ַ�������ʾ���ַ����ڴ�����ASCII����ʽ�洢��
//BoBo����һ�������KiKi������һ���ַ���������ַ���Ӧ��ASCII�롣
//#include<stdio.h>
//int main()
//{
//    char c;
//    scanf("%c", &c);
//    printf("%d", c);
//    return 0;
//}
