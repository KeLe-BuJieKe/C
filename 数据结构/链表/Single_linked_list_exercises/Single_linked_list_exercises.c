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




