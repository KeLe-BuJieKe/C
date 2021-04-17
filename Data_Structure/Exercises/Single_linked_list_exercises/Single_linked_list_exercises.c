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

    //如果后面有好几个也不会有问题，因为原来的链表就是链接在一起的
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
86. 分隔链表
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。
示例 1：
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：
输入：head = [2,1], x = 2
输出：[1,2]
链接：https://leetcode-cn.com/problems/partition-list/
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
    //第一种特殊情况；当head为空时，直接返回head
    if(head==NULL)
    {
        return head;
    }

    //创建两个头结点和两个尾指针
    //尾指针一直指向链表的末尾
    struct ListNode*smallhead,*smalltail,*bighead,*bigtail;
    smallhead=smalltail=(struct ListNode*)malloc(sizeof(struct ListNode));
    bighead=bigtail=(struct ListNode*)malloc(sizeof(struct ListNode));
    bigtail->next=NULL;
    smalltail->next=NULL;

    struct ListNode*cur=head;
    //判断cur->val与x谁大，如果比x小的放到小的链表中，比x大的放到大的链表中
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
    //这一步很关键，如果最后面还有一个数比x要小，则有可能成环，必须把bigtail置为NULL
    //1 4 3 2 5 2这个例子中 bigtail->val等于5时
    //也就是bigtail->next仍然指向2
    //但2这个数要放到小的链表中，会造成2和5成环
    bigtail->next=NULL;

    //把小的尾连接大的头连接到一起，形成一条单链表
    smalltail->next=bighead->next;
    //把新的头赋值给head
    head=smallhead->next;
    
    //释放两个头结点
    free(smallhead);    
    free(bighead);

    return head;
}*/


/*
面试题 02.06. 回文链表
编写一个函数，检查输入的链表是否是回文的。
示例 1：
输入： 1->2
输出： false 
示例 2：
输入： 1->2->2->1
输出： true 
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
链接：https://leetcode-cn.com/problems/palindrome-linked-list-lcci/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 //找中间结点的函数
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

//翻转一个链表如原来1->2->3->NULL
//翻转为           NULL<-1-<2-<3
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

//判断是否为回文
bool isPalindrome(struct ListNode* head)
{
    //思路先找到中间结点之后，在翻转中间结点之后的结点，在进行比较
    struct ListNode* mid = middleNode(head);
    struct ListNode* rhead = reverseList(mid);

    //有两种情况
    //1.当链表的结点个数为偶数时，则刚好结束，俩边的个数相同

    //2.当链表的结点个数为奇数时，后半部分会多出一个结点
    //比如1->2->1   被翻转为1->1->2
    //此时head指向第一个1   rhead指向第二个1 它们相等则 
    //head=head->next; rhead=rhead->next;
    //但此时上面语句的head->next仍然还是指向的是2，我们并没有改变第一个结点(1)这个数字的next
    //所以head此时指向与rhead指向的是同一个地址，数值肯定相同
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


/*160. 相交链表
编写一个程序，找到两个单链表相交的起始节点。
如下面的两个链表：
在节点 c1 开始相交。
示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，
链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

示例 2：
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，
链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。

示例 3：
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。

注意：
如果两个链表没有交点，返回 NULL.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
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
    int lenA = 0, lenB = 0;      //分别表示链表A与链表B的长度
    //计算链表A的长度
    while (curA != NULL)
    {
        lenA++;
        curA = curA->next;
    }
    //计算链表B的长度
    while (curB != NULL)
    {
        lenB++;
        curB = curB->next;
    }

    //abs取绝对值lenA-lenB
    int dif = abs(lenA - lenB);

    curA = headA;
    curB = headB;

    //让长的先走差距步，再同时走
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

    //如果两个链表其中有一个结点相交了，就返回那个结点
    //入宫不相交，两个链表就会一直迭代到NULL相等时，退出这个循环，在返回NULL
    while (curA != curB)
    {
        curA = curA->next;
        curB = curB->next;

    }

    return curA;
}*/


/*141. 环形链表
给定一个链表，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
如果链表中存在环，则返回 true 。 否则，返回 false 。
进阶：
你能用 O(1)（即，常量）内存解决此问题吗？
示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
提示：
链表中节点的数目范围是 [0, 104]
-105 <= Node.val <= 105
pos 为 -1 或者链表中的一个 有效索引 。
链接：https://leetcode-cn.com/problems/linked-list-cycle/
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
    struct ListNode* slow = head;     //慢指针
    struct ListNode* fast = head;     //快指针

    //慢指针一次走一步，快指针一次走两步
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
1.为什么slow走一步，fast走两步，他们一定会在环里面相遇，会不会永远追不上?请证明！
答：
不会，假设slow进环的时候，fast与slow的距离是N，紧接着追击的过程中（fast追slow）
fast向前走两步，slow走一步，他们每次一走，它们之间的距离就会缩小1
由一开始相距N，到后面相距0


2.slow走一步，fast走3步？走4步？走x步行不行？为什么？请证明！
答:
针对奇数步：如果slow进环时，slow与fast的差距N是奇数，且环的长度是偶数，那么它们两在环里面就会一直打圈，追不上。
针对偶数步：相反如果slow进环时，slow与fast的差距N是偶数，且环的长度是奇数，那么它们两也会在环里面一直打圈，追不上。

*/

/*
142. 环形链表 II
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
说明：不允许修改给定的链表。
进阶：
你是否可以使用 O(1) 空间解决此题？
示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
提示：
链表中节点的数目范围在范围 [0, 104] 内-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/
*/

/*
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode* slow = head;     //慢指针
    struct ListNode* fast = head;     //快指针

    //慢指针一次走一步，快指针一次走两步
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //相遇结点
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
138. 复制带随机指针的链表
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。
例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。
返回复制链表的头节点。
用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。
示例 1：
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

示例 4：
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
提示：
0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
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
    //处理特殊情况，当链表为NULL时，则直接返回空，也就是头节点
    if(NULL==head)
    {
        return head;
    }

    //1.拷贝节点挂在原节点的后面，建立起对应关系
    struct Node*cur=head;
    while(cur!=NULL)
    {
        //指向cur的下一个的指针
        struct Node*next=cur->next;
        struct Node*copyNode=(struct Node*)malloc(sizeof(struct Node));
        copyNode->val=cur->val;
        cur->next=copyNode;
        copyNode->next=next;
        cur=next;
    }

    //2.处理copy节点random
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

    //3.拷贝节点取下来链接到一起，恢复原链表
    cur=head;

    //创建一个带哨兵位的头节点，方便我们进行尾插
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
    //释放头结点
    struct Node*deleteHead=copyHead;
    copyHead=copyHead->next;
    free(deleteHead);
    return copyHead;
}
*/


/*
83. 删除排序链表中的重复元素
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
返回同样按升序排列的结果链表。
示例 1：
输入：head = [1,1,2]
输出：[1,2]

示例 2：
输入：head = [1,1,2,3,3]
输出：[1,2,3]
提示：
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
*/

/*
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    //当头指针为NULL，不需要排序
    //或者head->next==NULL时，链表中只有一个结点，不需要进行排序
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
82. 删除排序链表中的重复元素 II
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，
只保留原始链表中 没有重复出现 的数字。返回同样按升序排列的结果链表。
示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]

示例 2：
输入：head = [1,1,1,2,3]
输出：[2,3]
提示：
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
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
    //特殊情况：当传进来的链表为空或者只有一个节点，就表明不可能会有重复的节点
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //创建一个哨兵位的头结点，并把它与传进来的链表进行链接，以方便插入
    struct ListNode* temphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    temphead->next = head;

    struct ListNode* prev = temphead;
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;
    while (next != NULL)
    {
        if (cur->val == next->val)
        {
            //如果相等，则判断next之后的节点是否也是该数，是就继续走，不是则跳出循环
            while (next != NULL)
            {
                next = next->next;
                if (next != NULL && next->val != cur->val)
                {
                    break;
                }
            }
            //从cur到next这个前闭后开的区间内，这些节点的val都是重复出现的数，要把它删除
            while (next != NULL && cur->val != next->val)
            {
                struct ListNode* del = cur;
                cur = cur->next;
                free(del);
            }
            //到了这里next一定是与cur->val不相等了，把prev->next链接上
            prev->next = next;
        }
        else
        {

            prev->next = cur;
            prev = prev->next;
            cur = next;
        }
        //如果next==NULL了，则不需要往下遍历了，不然会有空指针的问题
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
147. 对链表进行插入排序
对链表进行插入排序。
插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
插入排序算法：
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
示例 1：
输入: 4->2->1->3
输出: 1->2->3->4

示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5
链接：https://leetcode-cn.com/problems/insertion-sort-list/
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
    //特殊情况：当该链表为空或者只有一个元素时，则不需要排序
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //创建一个哨兵位的头结点，方便插入
    struct ListNode* temphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    temphead->next = head;    //使该哨兵位的头结点，链接上创建的传进来的链表
    //未开始排序的那部分
    struct ListNode* cur = head->next;
    //tail表示temphead这个链表排好序那部分的尾
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