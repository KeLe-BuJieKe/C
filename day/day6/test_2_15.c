#define _CRT_SECURE_NO_WARNINGS 1

//1.以下程序的运行结果是
//#include<stdio.h>
//int fun(int a, int b)
//{
//	if (a > b)
//	{
//		return a + b;
//	}
//	else
//	{
//		return a - b;
//	}
//}
//int main()
//{
//	int a = 4;
//	int x = 3, y = 8, z = 6, r;
//	r = fun(fun(x, y), 2 * z);			//r== -17
//	printf("%d\n", r);
//	return 0;
//}



//式中7*15=133成立，则用的是几进制
//(7n^0)*(n^1+5n^0)=n^2+3n^1+3n^0
//解方程x=8或者x=-4(舍弃)

 

//下面程序指向后输出的结果是
//#include<stdio.h>
//int f(int a)
//{
//	int b = 0;
//	static int c = 3;
//	a = c++, b++;
//	//a=c++，b++等价于a=c++和b++
//	//a=（c++，b++）等价于a=b++，
//	return a;
//}
//int main()
//{
//	int  a = 2, k, i;
//	for (i = 0; i < 2; i++)
//	{
//		k = f(a++);			//k==4
//
//	}
//	printf("%d\n", k);
//	return 0;
//}



//下面程序指向后输出的结果是
//#include<stdio.h>
//int x = 3;
//void inc()
//{
//	static int x = 1;
//	x *=(x + 1);
//	printf("%d", x);		//2 6
//	return;
//}
//int main()
//{
//	int i;
//	for (i = 1; i < x; i++)
//	{
//		inc();
//	}
//	return 0;
//}



//算法题
//编写函数，要求逆置单链表（不带头结点）
/*
struct ListNode* reverseList(struct ListNode* head)
{
    //当穿进来的是空指针，或者只有一个元素的时候
    //不需要逆置
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    struct ListNode*cur=head;
    struct ListNode*next=head->next;
    struct ListNode*newhead=NULL;

    while(cur!=NULL)
    {
        //头插
        cur->next=newhead;
        newhead=cur;

        cur=next;
        if(next!=NULL)
        {
            next=next->next;
        }
    }
    return newhead;
}
*/


//智力题
//假设你站在镜子前，抬起左手，抬起右手，看着镜子中的自己。当你抬起左手时，镜中的自己抬起的似乎是右手。
//可是当你仰头时，镜中的自己也在仰头，而不是低头。为什么镜子中的影像似乎颠倒了左右，却没有颠倒上下？
/*
上下和左右的定义不同，上下是面对称的，左右是旋转对称的
*/ 