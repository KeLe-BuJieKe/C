#define _CRT_SECURE_NO_WARNINGS 1

//1.���³�������н����
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



//ʽ��7*15=133���������õ��Ǽ�����
//(7n^0)*(n^1+5n^0)=n^2+3n^1+3n^0
//�ⷽ��x=8����x=-4(����)

 

//�������ָ�������Ľ����
//#include<stdio.h>
//int f(int a)
//{
//	int b = 0;
//	static int c = 3;
//	a = c++, b++;
//	//a=c++��b++�ȼ���a=c++��b++
//	//a=��c++��b++���ȼ���a=b++��
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



//�������ָ�������Ľ����
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



//�㷨��
//��д������Ҫ�����õ���������ͷ��㣩
/*
struct ListNode* reverseList(struct ListNode* head)
{
    //�����������ǿ�ָ�룬����ֻ��һ��Ԫ�ص�ʱ��
    //����Ҫ����
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    struct ListNode*cur=head;
    struct ListNode*next=head->next;
    struct ListNode*newhead=NULL;

    while(cur!=NULL)
    {
        //ͷ��
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


//������
//������վ�ھ���ǰ��̧�����֣�̧�����֣����ž����е��Լ�������̧������ʱ�����е��Լ�̧����ƺ������֡�
//���ǵ�����ͷʱ�����е��Լ�Ҳ����ͷ�������ǵ�ͷ��Ϊʲô�����е�Ӱ���ƺ��ߵ������ң�ȴû�еߵ����£�
/*
���º����ҵĶ��岻ͬ����������ԳƵģ���������ת�ԳƵ�
*/ 