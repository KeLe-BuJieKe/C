#define _CRT_SECURE_NO_WARNINGS 1

/*
104. ��������������
����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ����
���������� [3,9,20,null,null,15,7]��
    3
   / \
  9  20
    /  \
   15   7
�������������� 3 ��
���ӣ�https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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



/*965. ��ֵ������
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
ʾ�� 1��
���룺[1,1,1,1,1,null,1]
�����true

ʾ�� 2��
���룺[2,2,2,5,2]
�����false
��ʾ��
�������Ľڵ�����Χ�� [1, 100]��
ÿ���ڵ��ֵ������������ΧΪ [0, 99] ��
���ӣ�https://leetcode-cn.com/problems/univalued-binary-tree/
*/

/*
bool isUnivalTree(struct TreeNode* root)
{
    if(root==NULL)
    {
        return true;
    }
    //�����Һ�������һ���븸�׽���ֵ����ȷ���false
    if((root->left&&root->val!=root->left->val)||(root->right&&root->val!=root->right->val))
    {
        return false;
    }
    return isUnivalTree(root->left)&&isUnivalTree(root->right);

}
*/




/*100. ��ͬ����
�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
ʾ�� 1��
���룺p = [1,2,3], q = [1,2,3]
�����true

ʾ�� 2��
���룺p = [1,2], q = [1,null,2]
�����false

ʾ�� 3��
���룺p = [1,2,1], q = [1,1,2]
�����false
��ʾ��
�������ϵĽڵ���Ŀ���ڷ�Χ [0, 100] ��
-104 <= Node.val <= 104
���ӣ�https://leetcode-cn.com/problems/same-tree/
*/

/*
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(NULL==p&&NULL==q)
    {
        return true;
    }
    //�ж��Ƿ�p��q����״�ṹ�Ƿ���ͬ
    //����p = [1,2], q = [1,null,2]
    if(NULL==p||NULL==q)
    {
        return false;
    }
    //�ṹ��ͬ�����ж�����ֵ�Ƿ���ͬ������ͬ����false����ͬ�����ж���һ��
    if(p->val!=q->val)
    {
        return false;
    }
    //ֵ��ͬ�������ж�p����������q����������p����������q���������Ƿ���ͬ
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);

}
*/




/*226. ��ת������
��תһ�ö�������
ʾ����
���룺
     4
   /   \
  2     7
 / \   / \
1   3 6   9
�����
     4
   /   \
  7     2
 / \   / \
9   6 3   1
���ӣ�https://leetcode-cn.com/problems/invert-binary-tree/
*/

/*
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    //˼·��
    //�Ȱ��������Ľ�㷭ת
    //�ٰ��������Ľ�㷭ת
    //����ٰ������������������巭ת
    struct TreeNode*left=invertTree(root->left);
    struct TreeNode*right=invertTree(root->right);

    root->left=right;
    root->right=left;
    return root;
}
*/




/*101. �Գƶ�����
����һ����������������Ƿ��Ǿ���ԳƵġ�
���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

    1
   / \
  2   2
 / \ / \
3  4 4  3
����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

    1
   / \
  2   2
   \   \
   3    3
���ӣ�https://leetcode-cn.com/problems/symmetric-tree/   
*/
/*
 //����һ��
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


��������
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    //˼·��
    //�Ȱ��������Ľ�㷭ת
    //�ٰ��������Ľ�㷭ת
    //����ٰ������������������巭ת
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
    //�ж��Ƿ�p��q����״�ṹ�Ƿ���ͬ
    //����p = [1,2], q = [1,null,2]
    if(NULL==p||NULL==q)
    {
        return false;
    }
    //�ṹ��ͬ�����ж�����ֵ�Ƿ���ͬ������ͬ����false����ͬ�����ж���һ��
    if(p->val!=q->val)
    {
        return false;
    }
    //ֵ��ͬ�������ж�p����������q����������p����������q���������Ƿ���ͬ
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);

}
bool isSymmetric(struct TreeNode* root)
{
    invertTree(root->left);
    return isSameTree(root->left,root->right);
}
*/