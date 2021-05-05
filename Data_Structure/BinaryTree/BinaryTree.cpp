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
	//������������ΪNULL������Ҷ�ӽ��
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
	1.�ȰѸ������
	2.����ͷ�����ݣ������������Һ������
	�ص㣺���������Ƚ��ȳ������ʣ�Ȼ����һ�����ʱ�򣬴�����һ��
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
	/*�ܽ᣺��ȫ�����������ߣ��ڵ��������ģ������������Ժ�
	����ȫ�ǿվ�����ȫ����������������зǿգ���ô�Ͳ���*/
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
		printf("�������ʧ��\n");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}



