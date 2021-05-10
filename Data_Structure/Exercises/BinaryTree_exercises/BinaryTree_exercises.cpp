#define _CRT_SECURE_NO_WARNINGS 1

/*
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
*/

/*
int max (struct TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int leftMaxDeep=maxDepth(root->left);
    int rightMaxDeep=maxDepth(root->right);
    return leftMaxDeep>rightMaxDeep?leftMaxDeep+1:rightMaxDeep+1;
}
*/



/*965. 单值二叉树
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。
示例 1：
输入：[1,1,1,1,1,null,1]
输出：true

示例 2：
输入：[2,2,2,5,2]
输出：false
提示：
给定树的节点数范围是 [1, 100]。
每个节点的值都是整数，范围为 [0, 99] 。
链接：https://leetcode-cn.com/problems/univalued-binary-tree/
*/

/*
bool isUnivalTree(struct TreeNode* root)
{
    if(root==NULL)
    {
        return true;
    }
    //若左右孩子其中一个与父亲结点的值不相等返回false
    if((root->left&&root->val!=root->left->val)||(root->right&&root->val!=root->right->val))
    {
        return false;
    }
    return isUnivalTree(root->left)&&isUnivalTree(root->right);

}
*/




/*100. 相同的树
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1：
输入：p = [1,2,3], q = [1,2,3]
输出：true

示例 2：
输入：p = [1,2], q = [1,null,2]
输出：false

示例 3：
输入：p = [1,2,1], q = [1,1,2]
输出：false
提示：
两棵树上的节点数目都在范围 [0, 100] 内
-104 <= Node.val <= 104
链接：https://leetcode-cn.com/problems/same-tree/
*/

/*
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(NULL==p&&NULL==q)
    {
        return true;
    }
    //判断是否p和q的形状结构是否相同
    //比如p = [1,2], q = [1,null,2]
    if(NULL==p||NULL==q)
    {
        return false;
    }
    //结构相同后，在判断它的值是否相同，不相同返回false，相同继续判断下一个
    if(p->val!=q->val)
    {
        return false;
    }
    //值相同，继续判断p的左子树与q的左子树、p的右子树与q的右子树是否相同
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);

}
*/




/*226. 翻转二叉树
翻转一棵二叉树。
示例：
输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1
链接：https://leetcode-cn.com/problems/invert-binary-tree/
*/

/*
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    //思路：
    //先把左子树的结点翻转
    //再把右子树的结点翻转
    //最后再把左子树与右子树整体翻转
    struct TreeNode*left=invertTree(root->left);
    struct TreeNode*right=invertTree(root->right);

    root->left=right;
    root->right=left;
    return root;
}
*/




/*101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
链接：https://leetcode-cn.com/problems/symmetric-tree/   
*/
/*
 //方法一：
bool _isSymmetric(struct TreeNode* _left,struct TreeNode* _right)
{

    if(_left==NULL&&_right==NULL)
    {
        return true;
    }

    if(_left==NULL||_right==NULL)
    {
        return false;
    }

    return _left->val==_right->val&&_isSymmetric(_left->left,_right->right)
    &&_isSymmetric(_left->right,_right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if(root==NULL)
    {
        return false;
    }

    return  _isSymmetric(root->left,root->right);
}


方法二：
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    //思路：
    //先把左子树的结点翻转
    //再把右子树的结点翻转
    //最后再把左子树与右子树整体翻转
    struct TreeNode*left=invertTree(root->left);
    struct TreeNode*right=invertTree(root->right);

    root->left=right;
    root->right=left;
    return root;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(NULL==p&&NULL==q)
    {
        return true;
    }
    //判断是否p和q的形状结构是否相同
    //比如p = [1,2], q = [1,null,2]
    if(NULL==p||NULL==q)
    {
        return false;
    }
    //结构相同后，在判断它的值是否相同，不相同返回false，相同继续判断下一个
    if(p->val!=q->val)
    {
        return false;
    }
    //值相同，继续判断p的左子树与q的左子树、p的右子树与q的右子树是否相同
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);

}
bool isSymmetric(struct TreeNode* root)
{
    invertTree(root->left);
    return isSameTree(root->left,root->right);
}
*/


/*144. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]

示例 5：
输入：root = [1,null,2]
输出：[1,2]
提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
进阶：递归算法很简单，你可以通过迭代算法完成吗？
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

*/

/*
方法一：递归法
//求该树的结点个数，以便我们malloc创建空间大小
int TreeSize(struct TreeNode* root)
{
    return NULL == root ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void _preorder(struct TreeNode* root, int* array, int* i)
{
    if (NULL == root)
    {
        return;
    }
    array[(*i)++] = root->val;
    _preorder(root->left, array, i);
    _preorder(root->right, array, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = TreeSize(root);
    int* array = (int*)malloc(sizeof(struct TreeNode) * (*returnSize));
    int i = 0;
    _preorder(root, array, &i);
    return array;
}

方法二：迭代

后期填坑
*/




/*94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[2,1]

示例 5：
输入：root = [1,null,2]
输出：[1,2]
提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
*/

/*
方法一：递归法
 int TreeSize(struct TreeNode*root)
 {
    return root==NULL?0:TreeSize(root->left)+TreeSize(root->right)+1;
 }

void _inorderTraversal(struct TreeNode*root,int *array,int *pi)
{
    if(NULL==root)
    {
        return;
    }
    _inorderTraversal(root->left,array,pi);
    array[(*pi)++]=root->val;
    _inorderTraversal(root->right,array,pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize=TreeSize(root);
    int *resultArray=(int *)malloc(sizeof(struct TreeNode)*(*returnSize));
    int i=0;
    _inorderTraversal(root,resultArray,&i);
    return resultArray;
}



方法二：迭代

后期填坑
*/




/*
145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。
示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3
输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
*/

/*
方法一：递归法
 int TreeSize(struct TreeNode*root)
 {
    return root==NULL?0:TreeSize(root->left)+TreeSize(root->right)+1;
 }

void _postorderTraversal(struct TreeNode*root,int *array,int *pi)
{
    if(NULL==root)
    {
        return;
    }
    _postorderTraversal(root->left,array,pi);
    _postorderTraversal(root->right,array,pi);
    array[(*pi)++]=root->val;

}



int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize=TreeSize(root);
    int *resultArray=(int *)malloc(sizeof(struct TreeNode)*(*returnSize));
    int i=0;
    _postorderTraversal(root,resultArray,&i);
    return resultArray;
}


方法二：迭代

后期填坑
*/




/*572. 另一个树的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括s的一个节点和这个节点的所有子孙。
s 也可以看做它自身的一棵子树。
示例 1:
给定的树 s:
     3
    / \
   4   5
  / \
 1   2
给定的树 t：
   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：
     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。
链接：https://leetcode-cn.com/problems/subtree-of-another-tree/
*/

/*
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(NULL==p&&NULL==q)
    {
        return true;
    }

    if(NULL==p||NULL==q)
    {
        return false;
    }

    return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    //遍历这棵树的每个节点，每个节点做子树跟subRoot作比较
    if(NULL==root||NULL==subRoot)
    {
        return false;
    }

    if(isSameTree(root,subRoot))
    {
        return true;
    }

    //每个节点都会作为子树的根在这里出现跟subRoot比较
    return  isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}
*/



/*
题目描述
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
输入描述:
输入包括1行字符串，长度不超过100。
输出描述:
可能有多组测试数据，对于每组数据，
输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
每个输出结果占一行。
示例1
输入
abc##de#g##f###
输出
c b e g d f a
*/

/*
思路：在先序遍历的过程中构建每一个节点
#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    struct TreeNode*left;
    struct TreeNode*right;
    char val;
};

struct TreeNode*CreatTree(char *str,int *pi,const int size)
{
    if(str[(*pi)]=='#'||*pi>=size)
    {
        (*pi)++;
        return NULL;
    }
    struct TreeNode*CurnewNode=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    CurnewNode->val=str[*pi];
    (*pi)++;

    CurnewNode->left=CreatTree(str,pi,size);
    CurnewNode->right=CreatTree(str,pi,size);
    return CurnewNode;
}

void BinaryTreeInOrder(struct TreeNode*root)
{
    if(root==NULL)
    {
        return;
    }
    BinaryTreeInOrder(root->left);
    printf("%c ",root->val);
    BinaryTreeInOrder(root->right);

}

-----------------测试代码-------------------
int main()
{
    char str[100];
    scanf("%s",str);
    int arraySize=strlen(str);
    int i=0;
    struct TreeNode*root=CreatTree(str, &i,arraySize);
    BinaryTreeInOrder(root);
    return 0;
}
*/




/*
110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：true

示例 2：
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false

示例 3：
输入：root = []
输出：true
链接：https://leetcode-cn.com/problems/balanced-binary-tree/
*/

/* 
//方法一：先序遍历判断每个节点的左右子树的高度差值是否小于2
//时间复杂度：O(N^2)
int maxTreeDepth(struct TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }

    int leftDepth=maxTreeDepth(root->left);
    int rightDepth=maxTreeDepth(root->right);

    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
}

bool isBalanced(struct TreeNode* root)
{
    if(NULL==root)
    {
        return true;
    }

    int leftDepth=maxTreeDepth(root->left);
    int rightDepth=maxTreeDepth(root->right);

    return abs(leftDepth-rightDepth)<2&&isBalanced(root->left)&&isBalanced(root->right);
}



//方法二：
//时间复杂度：O(N)
bool _isBalanced(struct TreeNode* root,int *pHeight)
{
    if(root==NULL)
    {
        *pHeight=0;
        return true;
    }

    //后序
    //先判断左子树，在判断右子树
    int leftHeight=0;
    if(_isBalanced(root->left,&leftHeight)==false)
    {
        return false;
    }

    int rightHeight=0;
    if(_isBalanced(root->right,&rightHeight)==false)
    {
        return false;
    }

    //同时再把当前树的高度带给上一层父亲
    *pHeight=fmax(rightHeight,leftHeight)+1;

    return abs(leftHeight-rightHeight)<2;
}
bool isBalanced(struct TreeNode* root)
{
    int height=0;
    return _isBalanced(root,&height);
}

*/