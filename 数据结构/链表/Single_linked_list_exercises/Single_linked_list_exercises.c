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




