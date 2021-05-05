#include"BinaryTree.h"



void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_left);
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	
	return root == NULL ? 0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right)+1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//当左右子树都为NULL，才是叶子结点
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->_left, k - 1)+BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL || root->_data == x)
	{
		return root;
	}

	BTNode* ret1 = BinaryTreeFind(root->_left, x);
	BTNode* ret2 = BinaryTreeFind(root->_right, x);
	
	if (NULL == ret1)
	{
		return ret2;
	}	
	return ret1;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		cout << "NULL  ";
		return;
	}

	printf("%c  ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}


void BinaryTreeInOrder(BTNode* root)
{

	if (root == NULL)
	{
		cout << "NULL  ";
		return;
	}

	BinaryTreeInOrder(root->_left);
	printf("%c  ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		cout << "NULL  ";
		return;
	}

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c  ", root->_data);

}

void BinaryTreeLevelOrder(BTNode* root)
{
	/*
	1.先把根入队列
	2.出队头的数据，并把他的左右孩子入队
	特点：借助队列先进先出的性质，然后上一层出的时候，带入下一层
	*/
	queue<BTNode*>q;
	if (root != NULL)
	{
		q.push(root);
	}

	while (!q.empty())
	{
		BTNode* Front=q.front();
		q.pop();
		cout << Front->_data << "  ";
		if (NULL != Front->_left)
		{
			q.push(Front->_left);
		}

		if (NULL != Front->_right)
		{
			q.push(Front->_right);
		}

	}
}

bool BinaryTreeComplete(BTNode* root)
{
	queue<BTNode*>q;
	if (root != NULL)
	{
		q.push(root);
	}
	else
	{
		return false;
	}
	/*总结：完全二叉树层序走，节点是连续的，当出到空了以后，
	后面全是空就是完全二叉树，如果后面有非空，那么就不是*/
	while (!q.empty())
	{
		BTNode* Front = q.front();
		q.pop();
		if (NULL == Front)
		{
			break;
		}
		q.push(Front->_left);
		q.push(Front->_right);
	}

	while (!q.empty())
	{
		BTNode* temp = q.front();
		q.pop();
		if (temp != NULL)
		{
			return false;
		}
	}
	return true;
}



BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* newNode =(BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		printf("创建结点失败\n");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}



