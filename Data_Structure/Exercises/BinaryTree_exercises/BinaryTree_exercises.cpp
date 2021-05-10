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


/*144. ��������ǰ�����
����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
ʾ�� 1��
���룺root = [1,null,2,3]
�����[1,2,3]

ʾ�� 2��
���룺root = []
�����[]

ʾ�� 3��
���룺root = [1]
�����[1]

ʾ�� 4��
���룺root = [1,2]
�����[1,2]

ʾ�� 5��
���룺root = [1,null,2]
�����[1,2]
��ʾ��
���нڵ���Ŀ�ڷ�Χ [0, 100] ��
-100 <= Node.val <= 100
���ף��ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
���ӣ�https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

*/

/*
����һ���ݹ鷨
//������Ľ��������Ա�����malloc�����ռ��С
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

������������

�������
*/




/*94. ���������������
����һ���������ĸ��ڵ� root ���������� ���� ������
ʾ�� 1��
���룺root = [1,null,2,3]
�����[1,3,2]

ʾ�� 2��
���룺root = []
�����[]

ʾ�� 3��
���룺root = [1]
�����[1]

ʾ�� 4��
���룺root = [1,2]
�����[2,1]

ʾ�� 5��
���룺root = [1,null,2]
�����[1,2]
��ʾ��
���нڵ���Ŀ�ڷ�Χ [0, 100] ��
-100 <= Node.val <= 100
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
���ӣ�https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
*/

/*
����һ���ݹ鷨
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



������������

�������
*/




/*
145. �������ĺ������
����һ������������������ ���� ������
ʾ��:
����: [1,null,2,3]
   1
    \
     2
    /
   3
���: [3,2,1]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
���ӣ�https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
*/

/*
����һ���ݹ鷨
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


������������

�������
*/




/*572. ��һ����������
���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ����������s��һ���ڵ������ڵ���������
s Ҳ���Կ����������һ��������
ʾ�� 1:
�������� s:
     3
    / \
   4   5
  / \
 1   2
�������� t��
   4 
  / \
 1   2
���� true����Ϊ t �� s ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��

ʾ�� 2:
�������� s��
     3
    / \
   4   5
  / \
 1   2
    /
   0
�������� t��

   4
  / \
 1   2
���� false��
���ӣ�https://leetcode-cn.com/problems/subtree-of-another-tree/
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
    //�����������ÿ���ڵ㣬ÿ���ڵ���������subRoot���Ƚ�
    if(NULL==root||NULL==subRoot)
    {
        return false;
    }

    if(isSameTree(root,subRoot))
    {
        return true;
    }

    //ÿ���ڵ㶼����Ϊ�����ĸ���������ָ�subRoot�Ƚ�
    return  isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}
*/



/*
��Ŀ����
��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
��������:
�������1���ַ��������Ȳ�����100��
�������:
�����ж���������ݣ�����ÿ�����ݣ�
����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
ÿ��������ռһ�С�
ʾ��1
����
abc##de#g##f###
���
c b e g d f a
*/

/*
˼·������������Ĺ����й���ÿһ���ڵ�
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

-----------------���Դ���-------------------
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
110. ƽ�������
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
�����У�һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����true

ʾ�� 2��
���룺root = [1,2,2,3,3,null,null,4,4]
�����false

ʾ�� 3��
���룺root = []
�����true
���ӣ�https://leetcode-cn.com/problems/balanced-binary-tree/
*/

/* 
//����һ����������ж�ÿ���ڵ�����������ĸ߶Ȳ�ֵ�Ƿ�С��2
//ʱ�临�Ӷȣ�O(N^2)
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



//��������
//ʱ�临�Ӷȣ�O(N)
bool _isBalanced(struct TreeNode* root,int *pHeight)
{
    if(root==NULL)
    {
        *pHeight=0;
        return true;
    }

    //����
    //���ж������������ж�������
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

    //ͬʱ�ٰѵ�ǰ���ĸ߶ȴ�����һ�㸸��
    *pHeight=fmax(rightHeight,leftHeight)+1;

    return abs(leftHeight-rightHeight)<2;
}
bool isBalanced(struct TreeNode* root)
{
    int height=0;
    return _isBalanced(root,&height);
}

*/