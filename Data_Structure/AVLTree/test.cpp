#include"AVLTree.hpp"
#include<vector>
#include<time.h>
void test()
{
	int arr[] = { 16,3,7,11,9,26,18,14,15 };
	int arr1[] = { 4,2,6,1,3,5,15,7,16,14 };


	AVLTree<int, int>avlt;

	for (auto& e : arr1)
	{
		avlt[e] = e;
	}

	avlt.Inorder();
	cout << avlt.isBalance() << endl;
}

void test1()
{
	int arr[] = { 16,3,7,11,9,26,18,14,15 };


	AVLTree<int, int>avlt1;
	
	for (auto& e : arr)
	{
		avlt1.insert(make_pair(e, e));
	}

	avlt1.Inorder();
	cout << avlt1.isBalance() << endl;
	AVLTree<int, int>avlt2(avlt1);

	avlt2.Inorder();
	cout << avlt2.isBalance() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}