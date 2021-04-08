#define _CRT_SECURE_NO_WARNINGS 1



/*题目：移除链表元素
删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-linked-list-elements/
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
//        //情况一 ：如果链表头连续几个都是要删除的值
//        ToDelete = head;
//        head = head->next;
//        free(ToDelete);
//    }
//
//    struct ListNode* cur = head;   //当前节点
//    struct ListNode* prev = NULL;  //保存删除节点的前一节点
//    while (cur != NULL)
//    {
//        if (cur->val == val)
//        {
//            prev->next = cur->next;  //连接删除节点的下一个节点
//            ToDelete = cur;          //把要删除的节点赋给ToDelete
//            cur = cur->next;         //让cur指向删除节点的下一个节点
//            free(ToDelete);        //删除等于val的节点
//        }
//        else
//        {
//            //如果当前节点cur->val与val不相等，把当前指针cur，赋值给prev
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}




/*题目：反转链表
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//迭代法：三指针
/*
struct ListNode* reverseList(struct ListNode* head)
{
    //当穿进来的是空指针，或者只有一个元素的时候
    //不需要逆置
    if (NULL == head || head->next == NULL)
    {
        return head;
    }

    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;

    while (n2 != NULL)
    {
        //反转
        n2->next = n1;

        //迭代
        n1 = n2;
        n2 = n3;
        //当n3为空，n3的next无法访问，会出错
        if (n3 != NULL)
        {
            n3 = n3->next;
        }
    }
    return n1;
}
*/


/*头插迭代：具体思路就是，取cur头插到以newhead为头的新链表中
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


/*题目：链表的中间结点
给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
示例 1：
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
链接：https://leetcode-cn.com/problems/middle-of-the-linked-list/
*/

/*额外要求：当被要求只能遍历一遍链表时 
方法：快慢指针
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
    //当链表中只有一个结点时，直接返回head
    if (head->next == NULL)
    {
        return head;
    }

    struct ListNode* slow = head;  //慢指针 一次走一步
    struct ListNode* fast = head;  //快指针 一次走两步
    while (fast && fast->next)
    {
        slow = slow->next;

        fast = fast->next->next;
    }
    return slow;
}
*/



/*题目：链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点
示例：
给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*额外要求：当被要求只能遍历一遍链表时 
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



/*21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：
输入：l1 = [], l2 = []
输出：[]
示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/
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
    //当l1与l2都为空时，返回l2，此时相当于返回NULL
    //当l1为NULL，l2不为空时，返回l2
    //当l1不为NULL，l2为空时，返回l1，
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
    //先让新创建的头，指向l1与l2中的最小值的结点
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

    //取小的进行尾插
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



