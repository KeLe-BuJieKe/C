#define _CRT_SECURE_NO_WARNINGS 1


//如下程序运行结果哦是
//#include<stdio.h>
//int change(int* px)
//{
//	int y = 8;
//	y -= *px;
//	px = &y;			//改变了px的指向，并没有改变原来*px的值
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



//以下程序的输出结果为？
//#include<stdio.h>
//#define cir(r) r*r
//int  main()
//{
//	int a = 1;
//	int b = 2;
//	int t;
//	t = cir(a + b);			//替换文本时，参数r被替换成a + b,所以这条语句实际上变成了： printf ("%d\n",a + b * a + b );
//	//t==5
//	//这样就比较清晰了，由替换产生的表达式并没有按照预想的次序进行求值。
//	//在宏定义上加上两个括号，这个问题便轻松的解决了：
//	//#define SQUARE(x) (x) * (x)
//	printf("%d\n", t);
//	return 0;
//}



//下面的代码中，函数test执行完毕后，打印的结果是 ？
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


//算法题
/*有一张单链表，编写函数求倒数第k个结点*/

//后期填坑


//智力题
//13个球一个天平，现知道只有一个和其他的重量不同，问怎样称才能用三次就找到那个球？

//后期填坑