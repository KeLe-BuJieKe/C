#include"BinaryTree.h"

int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D= CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');
	
	A->_left = B;
	A->_right = C;
	B->_left = D;
	C->_left = E;
	C->_right = F;	

	BinaryTreePrevOrder(A);
	cout << endl;
	BinaryTreeInOrder(A);
	cout << endl;
	BinaryTreePostOrder(A);
	cout << endl;

	int ret = BinaryTreeSize(A);
	cout << ret << endl;
	ret = BinaryTreeSize(A);
	cout << ret << endl;

	int ret1=BinaryTreeLeafSize(A);
	cout << ret1 << endl;

	int ret2 = BinaryTreeLevelKSize(A,3);
	cout << ret2 << endl;


	BTNode* ret3 = BinaryTreeFind(A, 'C');
	if (ret3 == NULL)
	{
		cout << "Î´ÕÒµ½" << endl;
	}
	else
	{
		cout << ret3->_data << endl;
	}

	BinaryTreeLevelOrder(A);
	cout << endl;


	bool ret4=BinaryTreeComplete(A);
	if (ret4)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}