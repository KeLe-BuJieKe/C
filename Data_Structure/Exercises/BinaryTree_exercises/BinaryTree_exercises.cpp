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
int maxDepth(struct TreeNode* root)
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