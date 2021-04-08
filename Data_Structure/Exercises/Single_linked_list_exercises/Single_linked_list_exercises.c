#define _CRT_SECURE_NO_WARNINGS 1



/*��Ŀ���Ƴ�����Ԫ��
ɾ�������е��ڸ���ֵ val �����нڵ㡣
ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-linked-list-elements/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* ToDelete = NULL;
//    while (head != NULL && head->val == val)
//    {
//        //���һ ���������ͷ������������Ҫɾ����ֵ
//        ToDelete = head;
//        head = head->next;
//        free(ToDelete);
//    }
//
//    struct ListNode* cur = head;   //��ǰ�ڵ�
//    struct ListNode* prev = NULL;  //����ɾ���ڵ��ǰһ�ڵ�
//    while (cur != NULL)
//    {
//        if (cur->val == val)
//        {
//            prev->next = cur->next;  //����ɾ���ڵ����һ���ڵ�
//            ToDelete = cur;          //��Ҫɾ���Ľڵ㸳��ToDelete
//            cur = cur->next;         //��curָ��ɾ���ڵ����һ���ڵ�
//            free(ToDelete);        //ɾ������val�Ľڵ�
//        }
//        else
//        {
//            //�����ǰ�ڵ�cur->val��val����ȣ��ѵ�ǰָ��cur����ֵ��prev
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}




/*��Ŀ����ת����
��תһ��������
ʾ��:
����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
����:
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-linked-list
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//����������ָ��
/*
struct ListNode* reverseList(struct ListNode* head)
{
    //�����������ǿ�ָ�룬����ֻ��һ��Ԫ�ص�ʱ��
    //����Ҫ����
    if (NULL == head || head->next == NULL)
    {
        return head;
    }

    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;

    while (n2 != NULL)
    {
        //��ת
        n2->next = n1;

        //����
        n1 = n2;
        n2 = n3;
        //��n3Ϊ�գ�n3��next�޷����ʣ������
        if (n3 != NULL)
        {
            n3 = n3->next;
        }
    }
    return n1;
}
*/


/*ͷ�����������˼·���ǣ�ȡcurͷ�嵽��newheadΪͷ����������
struct ListNode* reverseList(struct ListNode* head)
{

    struct ListNode*cur=head;
    struct ListNode*newhead=NULL;

    while(cur!=NULL)
    {
        struct ListNode*next=cur->next;
        cur->next=newhead;
        newhead=cur;
        cur=next;
    }
    return newhead;
}
*/


/*��Ŀ��������м���
����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣
����������м��㣬�򷵻صڶ����м��㡣
ʾ�� 1��
���룺[1,2,3,4,5]
��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
ʾ�� 2��
���룺[1,2,3,4,5,6]
��������б��еĽ�� 4 (���л���ʽ��[4,5,6])
���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣
���ӣ�https://leetcode-cn.com/problems/middle-of-the-linked-list/
*/

/*����Ҫ�󣺵���Ҫ��ֻ�ܱ���һ������ʱ 
����������ָ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* middleNode(struct ListNode* head)
{
    //��������ֻ��һ�����ʱ��ֱ�ӷ���head
    if (head->next == NULL)
    {
        return head;
    }

    struct ListNode* slow = head;  //��ָ�� һ����һ��
    struct ListNode* fast = head;  //��ָ�� һ��������
    while (fast && fast->next)
    {
        slow = slow->next;

        fast = fast->next->next;
    }
    return slow;
}
*/



/*��Ŀ�������е�����k���ڵ�
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
���磬һ�������� 6 ���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������ 1��2��3��4��5��6���������ĵ����� 3 ���ڵ���ֵΪ 4 �Ľڵ�
ʾ����
����һ������: 1->2->3->4->5, �� k = 2.
�������� 4->5.
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*����Ҫ�󣺵���Ҫ��ֻ�ܱ���һ������ʱ 
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



/*21. �ϲ�������������
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
ʾ�� 1��
���룺l1 = [1,2,4], l2 = [1,3,4]
�����[1,1,2,3,4,4]
ʾ�� 2��
���룺l1 = [], l2 = []
�����[]
ʾ�� 3��
���룺l1 = [], l2 = [0]
�����[0]
���ӣ�https://leetcode-cn.com/problems/merge-two-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{   
    //��l1��l2��Ϊ��ʱ������l2����ʱ�൱�ڷ���NULL
    //��l1ΪNULL��l2��Ϊ��ʱ������l2
    //��l1��ΪNULL��l2Ϊ��ʱ������l1��
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    //�����´�����ͷ��ָ��l1��l2�е���Сֵ�Ľ��
    if (l1->val < l2->val)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }

    //ȡС�Ľ���β��
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
    {
        tail->next = l1;
    }
    else if (l2 != NULL)
    {
        tail->next = l2;
    }
    return head;
}
*/



