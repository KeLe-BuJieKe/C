#include"BSTree.hpp"


void testNoR()
{
	BSTree<int>b;
	int arr[] = { 5,3,4,1,7,8,2,6,9, 0};
	for (auto& e : arr)
	{
		b.insert(e);
	}
	b.Inorder();

	for (auto& e : arr)
	{
		b.erase(e);
		b.Inorder();
	}
	//b.insert(1);
	//b.Inorder();
	//cout << endl;
	cout << b.isBSTree() << endl;
}

void testR()
{
	BSTree<int>b;
	int arr[] = { 5,3,4,1,7,8,2,6,9, 0 };
	for (auto& e : arr)
	{
		b.insertR(e);
	}
	b.InorderR();
	BSTree<int>b2=b;
	b2.InorderR();
	BSTree<int>b3;
	b3 = b2;
	b3.InorderR();
	//cout << b.findR(3) << endl;

	//for (auto& e : arr)
	//{
	//	b.erase(e);
	//	b.Inorder();
	//}
	//cout << b.findR(3) << endl;

	//cout << endl;
}
int main()
{
	//testNoR();
	testR();
	system("pause");
	return 0;
}