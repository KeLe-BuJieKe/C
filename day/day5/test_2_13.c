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
/*
struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    //��ͷ���ΪNULL����k<=0ʱ�����ؿ�ָ��
    if (head == NULL || k <= 0)
    {
        return NULL;
    }
    struct ListNode* slow = head;  //��ָ��  ʼ�����ָ�����k-1�����
    struct ListNode* fast = head;  //��ָ��

    //--k   ѭ��k-1��
    //k--   ѭ��k  ��
    while (--k)
    {
        //�������k���ڸ�����Ľ����ʱ������NULL        
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        else
        {
            return NULL;
        }
    }

    //ѭ����fast��ָ�����һ������ʱ����ָ�����k-1�����
    //��ָ���λ�þ��ǵ�����k������λ��
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
*/


//������
//13����һ����ƽ����֪��ֻ��һ����������������ͬ���������Ʋ��������ξ��ҵ��Ǹ���

/*
�ȷ�Ϊ3��ÿ����ĸ���Ϊ4��4��5
��1��
��������4�����໥���������Ǳ��أ��Ǳ���һ�㣬��ô��һ�ξͳ����ص����飻
���������������ȣ�����һ�γ�5���������

��2��
����Ƶ���4����ģ����ٷ�Ϊ2������Ϊ��Ϊ2��2���ٿ��Ǳ��أ�ȡ�ص���һ��
����Ƶ���5����ģ����ٷ�Ϊ3�������ֱ�Ϊ2��2��1������2��2�ĳ������Ǳ��أ�ȡ�ص�һ�ߣ����������ȣ�������Ҫ������1�������������Ҫ�ҵ���

��3��
����Ƶ���2����ģ���ֱ������ƽ���ߣ����Ǳ��أ��ص��Ǳ���Ϊ������Ҫ�ҵ���
*/