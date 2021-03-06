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
/*
struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    //当头结点为NULL或者k<=0时，返回空指针
    if (head == NULL || k <= 0)
    {
        return NULL;
    }
    struct ListNode* slow = head;  //慢指针  始终与快指针相隔k-1个结点
    struct ListNode* fast = head;  //快指针

    //--k   循环k-1次
    //k--   循环k  次
    while (--k)
    {
        //当输入的k大于该链表的结点数时，返回NULL        
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        else
        {
            return NULL;
        }
    }

    //循环到fast快指针最后一个，此时与慢指针相隔k-1个结点
    //慢指针此位置就是倒数第k个结点的位置
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
*/


//智力题
//13个球一个天平，现知道只有一个和其他的重量不同，问怎样称才能用三次就找到那个球？

/*
先分为3组每组球的个数为4、4、5
第1次
先让两个4个球相互称量，看那别重，那边重一点，那么下一次就称量重的那组；
如果俩个球重量相等，则下一次称5个球的那组

第2次
如果称的是4个球的，则再分为2组数量为别为2、2，再看那边重，取重的那一组
如果称的是5个球的，则再分为3组数量分别为2、2、1，再让2与2的称量看那别重，取重的一边；如果俩边相等，则不再需要称量，1的那组就是我们要找的球

第3次
如果称的是2个球的，则分别放在天平两边，看那边重，重的那边则为我们所要找的球
*/