#define _CRT_SECURE_NO_WARNINGS 1


//���³������н��Ŷ��
//#include<stdio.h>
//int change(int* px)
//{
//	int y = 8;
//	y -= *px;
//	px = &y;			//�ı���px��ָ�򣬲�û�иı�ԭ��*px��ֵ
//	return 0;
//}
//int main()
//{
//	int xx = 3;
//	int *py = &xx;
//	change(py);
//	printf("%d\n", *py);				//*py==3
//	return 0;
//}



//���³����������Ϊ��
//#include<stdio.h>
//#define cir(r) r*r
//int  main()
//{
//	int a = 1;
//	int b = 2;
//	int t;
//	t = cir(a + b);			//�滻�ı�ʱ������r���滻��a + b,�����������ʵ���ϱ���ˣ� printf ("%d\n",a + b * a + b );
//	//t==5
//	//�����ͱȽ������ˣ����滻�����ı��ʽ��û�а���Ԥ��Ĵ��������ֵ��
//	//�ں궨���ϼ����������ţ������������ɵĽ���ˣ�
//	//#define SQUARE(x) (x) * (x)
//	printf("%d\n", t);
//	return 0;
//}



//����Ĵ����У�����testִ����Ϻ󣬴�ӡ�Ľ���� ��
#include<stdio.h>
unsigned long g_ulGlobal = 0;
void globalinit(unsigned long ulArg)
{
	ulArg = 0x01;
	return 0;
}
int main()
{
	globalinit(g_ulGlobal);
	printf("%d\n", g_ulGlobal);   //0
	return 0;
}


//�㷨��
/*��һ�ŵ�������д����������k�����*/

//�������


//������
//13����һ����ƽ����֪��ֻ��һ����������������ͬ���������Ʋ��������ξ��ҵ��Ǹ���

//�������