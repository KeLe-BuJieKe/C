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

    //��������кü���Ҳ���������⣬��Ϊԭ�����������������һ���
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

/*
86. �ָ�����
����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�
ʾ�� 1��
���룺head = [1,4,3,2,5,2], x = 3
�����[1,2,2,4,3,5]
ʾ�� 2��
���룺head = [2,1], x = 2
�����[1,2]
���ӣ�https://leetcode-cn.com/problems/partition-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* partition(struct ListNode* head, int x)
{
    //��һ�������������headΪ��ʱ��ֱ�ӷ���head
    if(head==NULL)
    {
        return head;
    }

    //��������ͷ��������βָ��
    //βָ��һֱָ�������ĩβ
    struct ListNode*smallhead,*smalltail,*bighead,*bigtail;
    smallhead=smalltail=(struct ListNode*)malloc(sizeof(struct ListNode));
    bighead=bigtail=(struct ListNode*)malloc(sizeof(struct ListNode));
    bigtail->next=NULL;
    smalltail->next=NULL;

    struct ListNode*cur=head;
    //�ж�cur->val��x˭�������xС�ķŵ�С�������У���x��ķŵ����������
    while(cur)
    {
        if(cur->val<x)
        {
            smalltail->next=cur;
            smalltail=smalltail->next;
        }
        else
        {
            bigtail->next=cur;
            bigtail=bigtail->next;
        }
        cur=cur->next;
    }
    //��һ���ܹؼ����������滹��һ������xҪС�����п��ܳɻ��������bigtail��ΪNULL
    //1 4 3 2 5 2��������� bigtail->val����5ʱ
    //Ҳ����bigtail->next��Ȼָ��2
    //��2�����Ҫ�ŵ�С�������У������2��5�ɻ�
    bigtail->next=NULL;

    //��С��β���Ӵ��ͷ���ӵ�һ���γ�һ��������
    smalltail->next=bighead->next;
    //���µ�ͷ��ֵ��head
    head=smallhead->next;
    
    //�ͷ�����ͷ���
    free(smallhead);    
    free(bighead);

    return head;
}*/


/*
������ 02.06. ��������
��дһ���������������������Ƿ��ǻ��ĵġ�
ʾ�� 1��
���룺 1->2
����� false 
ʾ�� 2��
���룺 1->2->2->1
����� true 
���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
���ӣ�https://leetcode-cn.com/problems/palindrome-linked-list-lcci/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 //���м���ĺ���
struct ListNode* middleNode(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//��תһ��������ԭ��1->2->3->NULL
//��תΪ           NULL<-1-<2-<3
struct ListNode* reverseList(struct ListNode* head)
{

    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;

    while (cur != NULL)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}

//�ж��Ƿ�Ϊ����
bool isPalindrome(struct ListNode* head)
{
    //˼·���ҵ��м���֮���ڷ�ת�м���֮��Ľ�㣬�ڽ��бȽ�
    struct ListNode* mid = middleNode(head);
    struct ListNode* rhead = reverseList(mid);

    //���������
    //1.������Ľ�����Ϊż��ʱ����պý��������ߵĸ�����ͬ

    //2.������Ľ�����Ϊ����ʱ����벿�ֻ���һ�����
    //����1->2->1   ����תΪ1->1->2
    //��ʱheadָ���һ��1   rheadָ��ڶ���1 ��������� 
    //head=head->next; rhead=rhead->next;
    //����ʱ��������head->next��Ȼ����ָ�����2�����ǲ�û�иı��һ�����(1)������ֵ�next
    //����head��ʱָ����rheadָ�����ͬһ����ַ����ֵ�϶���ͬ
    while (head != NULL && rhead != NULL)
    {
        if (head->val != rhead->val)
        {
            return false;
        }
        else
        {
            head = head->next;
            rhead = rhead->next;
        }
    }
    return true;
}*/


/*160. �ཻ����
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
���������������
�ڽڵ� c1 ��ʼ�ཻ��
ʾ�� 1��
���룺intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
�����Reference of the node with value = 8
������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬������������ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ [4,1,8,4,5]��
���� B Ϊ [5,0,1,8,4,5]���� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣

ʾ�� 2��
���룺intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
�����Reference of the node with value = 2
������ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬������������ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ����
���� A Ϊ [0,9,1,2,4]������ B Ϊ [3,2,4]���� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣

ʾ�� 3��
���룺intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
�����null
������ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ [2,6,4]������ B Ϊ [1,5]�����������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
���ͣ������������ཻ����˷��� null��

ע�⣺
�����������û�н��㣬���� NULL.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    int lenA = 0, lenB = 0;      //�ֱ��ʾ����A������B�ĳ���
    //��������A�ĳ���
    while (curA != NULL)
    {
        lenA++;
        curA = curA->next;
    }
    //��������B�ĳ���
    while (curB != NULL)
    {
        lenB++;
        curB = curB->next;
    }

    //absȡ����ֵlenA-lenB
    int dif = abs(lenA - lenB);

    curA = headA;
    curB = headB;

    //�ó������߲�ಽ����ͬʱ��
    if (lenA > lenB)
    {
        while (dif--)
        {
            curA = curA->next;
        }
    }
    else
    {
        while (dif--)
        {
            curB = curB->next;
        }
    }

    //�����������������һ������ཻ�ˣ��ͷ����Ǹ����
    //�빬���ཻ����������ͻ�һֱ������NULL���ʱ���˳����ѭ�����ڷ���NULL
    while (curA != curB)
    {
        curA = curA->next;
        curB = curB->next;

    }

    return curA;
}*/


/*141. ��������
����һ�������ж��������Ƿ��л���
�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
��� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
��������д��ڻ����򷵻� true �� ���򣬷��� false ��
���ף�
������ O(1)�������������ڴ�����������
ʾ�� 1��
���룺head = [3,2,0,-4], pos = 1
�����true
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

ʾ�� 2��
���룺head = [1,2], pos = 0
�����true
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

ʾ�� 3��
���룺head = [1], pos = -1
�����false
���ͣ�������û�л���
��ʾ��
�����нڵ����Ŀ��Χ�� [0, 104]
-105 <= Node.val <= 105
pos Ϊ -1 ���������е�һ�� ��Ч���� ��
���ӣ�https://leetcode-cn.com/problems/linked-list-cycle/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
bool hasCycle(struct ListNode* head)
{
    struct ListNode* slow = head;     //��ָ��
    struct ListNode* fast = head;     //��ָ��

    //��ָ��һ����һ������ָ��һ��������
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
*/

/*
1.Ϊʲôslow��һ����fast������������һ�����ڻ������������᲻����Զ׷����?��֤����
��
���ᣬ����slow������ʱ��fast��slow�ľ�����N��������׷���Ĺ����У�fast׷slow��
fast��ǰ��������slow��һ��������ÿ��һ�ߣ�����֮��ľ���ͻ���С1
��һ��ʼ���N�����������0


2.slow��һ����fast��3������4������x���в��У�Ϊʲô����֤����
��:
��������������slow����ʱ��slow��fast�Ĳ��N���������һ��ĳ�����ż������ô�������ڻ�����ͻ�һֱ��Ȧ��׷���ϡ�
���ż�������෴���slow����ʱ��slow��fast�Ĳ��N��ż�����һ��ĳ�������������ô������Ҳ���ڻ�����һֱ��Ȧ��׷���ϡ�

*/

/*
142. �������� II
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
��� pos �� -1�����ڸ�������û�л���ע�⣬pos ���������ڱ�ʶ�����������������Ϊ�������ݵ������С�
˵�����������޸ĸ���������
���ף�
���Ƿ����ʹ�� O(1) �ռ������⣿
ʾ�� 1��
���룺head = [3,2,0,-4], pos = 1
�������������Ϊ 1 ������ڵ�
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

ʾ�� 2��
���룺head = [1,2], pos = 0
�������������Ϊ 0 ������ڵ�
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

ʾ�� 3��
���룺head = [1], pos = -1
��������� null
���ͣ�������û�л���
��ʾ��
�����нڵ����Ŀ��Χ�ڷ�Χ [0, 104] ��-105 <= Node.val <= 105
pos ��ֵΪ -1 ���������е�һ����Ч����
���ӣ�https://leetcode-cn.com/problems/linked-list-cycle-ii/
*/

/*
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode* slow = head;     //��ָ��
    struct ListNode* fast = head;     //��ָ��

    //��ָ��һ����һ������ָ��һ��������
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //�������
            struct ListNode*meet=fast;
            while(meet!=head)
            {
                meet=meet->next;
                head=head->next;
            }
            return meet;
        }
    }
    return NULL;
}
*/

/*
138. ���ƴ����ָ�������
����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
�½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��
���磬���ԭ�������� X �� Y �����ڵ㣬���� X.random --> Y ����ô�ڸ��������ж�Ӧ�������ڵ� x �� y ��ͬ���� x.random --> y ��
���ظ��������ͷ�ڵ㡣
��һ���� n ���ڵ���ɵ���������ʾ����/����е�����ÿ���ڵ���һ�� [val, random_index] ��ʾ��
val��һ����ʾ Node.val ��������
random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n-1���������ָ���κνڵ㣬��Ϊ  null ��
��Ĵ��� ֻ ����ԭ�����ͷ�ڵ� head ��Ϊ���������
ʾ�� 1��
���룺head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
�����[[7,null],[13,0],[11,4],[10,2],[1,0]]

ʾ�� 2��
���룺head = [[1,1],[2,1]]
�����[[1,1],[2,1]]

ʾ�� 3��
���룺head = [[3,null],[3,0],[3,null]]
�����[[3,null],[3,0],[3,null]]

ʾ�� 4��
���룺head = []
�����[]
���ͣ�����������Ϊ�գ���ָ�룩����˷��� null��
��ʾ��
0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random Ϊ�գ�null����ָ�������еĽڵ㡣
*/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

/*
struct Node* copyRandomList(struct Node* head)
{
    //�������������������ΪNULLʱ����ֱ�ӷ��ؿգ�Ҳ����ͷ�ڵ�
    if(NULL==head)
    {
        return head;
    }

    //1.�����ڵ����ԭ�ڵ�ĺ��棬�������Ӧ��ϵ
    struct Node*cur=head;
    while(cur!=NULL)
    {
        //ָ��cur����һ����ָ��
        struct Node*next=cur->next;
        struct Node*copyNode=(struct Node*)malloc(sizeof(struct Node));
        copyNode->val=cur->val;
        cur->next=copyNode;
        copyNode->next=next;
        cur=next;
    }

    //2.����copy�ڵ�random
    cur=head;
    while(cur!=NULL)
    {
        struct Node*copyNode=cur->next;
        if(cur->random==NULL)
        {
            copyNode->random=NULL;
        }
        else
        {
            copyNode->random=cur->random->next;
        }
        cur=copyNode->next;
    }

    //3.�����ڵ�ȡ�������ӵ�һ�𣬻ָ�ԭ����
    cur=head;

    //����һ�����ڱ�λ��ͷ�ڵ㣬�������ǽ���β��
    struct Node*copyHead=(struct Node*)malloc(sizeof(struct Node));
    struct Node*copyTail=copyHead;
    while(cur!=NULL)
    {
        struct Node*copyNode=cur->next;
        struct Node*next=copyNode->next;

        cur->next=next;
        copyTail->next=copyNode;
        copyTail=copyTail->next;
        cur=next;
    }
    //�ͷ�ͷ���
    struct Node*deleteHead=copyHead;
    copyHead=copyHead->next;
    free(deleteHead);
    return copyHead;
}
*/


/*
83. ɾ�����������е��ظ�Ԫ��
����һ�����������е�����������������ͷ�ڵ� head ������ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ��
����ͬ�����������еĽ������
ʾ�� 1��
���룺head = [1,1,2]
�����[1,2]

ʾ�� 2��
���룺head = [1,1,2,3,3]
�����[1,2,3]
��ʾ��
�����нڵ���Ŀ�ڷ�Χ [0, 300] ��
-100 <= Node.val <= 100
��Ŀ���ݱ�֤�����Ѿ�����������
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
*/

/*
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    //��ͷָ��ΪNULL������Ҫ����
    //����head->next==NULLʱ��������ֻ��һ����㣬����Ҫ��������
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct ListNode*cur=head;
    struct ListNode*next=head->next;
    while(next!=NULL)
    {
        if(cur->val==next->val)
        {
            struct ListNode*ToDelete=next;
            cur->next=next->next;
            next=next->next;
            free(ToDelete);
            ToDelete=NULL;
        }
        else
        {
            cur=next;
            next=next->next;
        }
    }
    return head;
}*/


/*
82. ɾ�����������е��ظ�Ԫ�� II
����һ�����������е�����������������ͷ�ڵ� head ������ɾ�����������д��������ظ�����Ľڵ㣬
ֻ����ԭʼ������ û���ظ����� �����֡�����ͬ�����������еĽ������
ʾ�� 1��
���룺head = [1,2,3,3,4,4,5]
�����[1,2,5]

ʾ�� 2��
���룺head = [1,1,1,2,3]
�����[2,3]
��ʾ��
�����нڵ���Ŀ�ڷ�Χ [0, 300] ��
-100 <= Node.val <= 100
��Ŀ���ݱ�֤�����Ѿ�����������
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    //�����������������������Ϊ�ջ���ֻ��һ���ڵ㣬�ͱ��������ܻ����ظ��Ľڵ�
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //����һ���ڱ�λ��ͷ��㣬�������봫����������������ӣ��Է������
    struct ListNode* temphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    temphead->next = head;

    struct ListNode* prev = temphead;
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;
    while (next != NULL)
    {
        if (cur->val == next->val)
        {
            //�����ȣ����ж�next֮��Ľڵ��Ƿ�Ҳ�Ǹ������Ǿͼ����ߣ�����������ѭ��
            while (next != NULL)
            {
                next = next->next;
                if (next != NULL && next->val != cur->val)
                {
                    break;
                }
            }
            //��cur��next���ǰ�պ󿪵������ڣ���Щ�ڵ��val�����ظ����ֵ�����Ҫ����ɾ��
            while (next != NULL && cur->val != next->val)
            {
                struct ListNode* del = cur;
                cur = cur->next;
                free(del);
            }
            //��������nextһ������cur->val������ˣ���prev->next������
            prev->next = next;
        }
        else
        {

            prev->next = cur;
            prev = prev->next;
            cur = next;
        }
        //���next==NULL�ˣ�����Ҫ���±����ˣ���Ȼ���п�ָ�������
        if (next != NULL)
        {
            next = next->next;
        }
    }

    head = temphead->next;
    free(temphead);
    return head;
}
*/



/*
147. ��������в�������
��������в�������
��������Ķ�����ʾ���ϡ��ӵ�һ��Ԫ�ؿ�ʼ����������Ա���Ϊ�Ѿ����������ú�ɫ��ʾ����
ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ��ú�ɫ��ʾ������ԭ�ؽ�����뵽���ź���������С�
���������㷨��
���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
�ظ�ֱ�������������ݲ�����Ϊֹ��
ʾ�� 1��
����: 4->2->1->3
���: 1->2->3->4

ʾ�� 2��
����: -1->5->3->4->0
���: -1->0->3->4->5
���ӣ�https://leetcode-cn.com/problems/insertion-sort-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* insertionSortList(struct ListNode* head)
{
    //�����������������Ϊ�ջ���ֻ��һ��Ԫ��ʱ������Ҫ����
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //����һ���ڱ�λ��ͷ��㣬�������
    struct ListNode* temphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    temphead->next = head;    //ʹ���ڱ�λ��ͷ��㣬�����ϴ����Ĵ�����������
    //δ��ʼ������ǲ���
    struct ListNode* cur = head->next;
    //tail��ʾtemphead��������ź����ǲ��ֵ�β
    struct ListNode* tail = head;

    while (cur != NULL)
    {
        if (cur->val < tail->val)
        {
            struct ListNode* prev = temphead;
            while (prev->next->val < cur->val)
            {
                prev = prev->next;
            }
            tail->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
        }
        tail = cur;
        cur = cur->next;
    }
    head = temphead->next;
    free(temphead);
    return head;
}
*/