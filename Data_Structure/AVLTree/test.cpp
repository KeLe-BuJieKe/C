#include"AVLTree.hpp"

void test()
{
	int arr[] = { 16,3,7,11,9,26,18,14,15 };
	int arr1[] = { 4,2,6,1,3,5,15,7,16,14 };
	AVLTree<int, int>avlt;
	for (auto& e : arr)
	{
		avlt.insert(make_pair(e,e));
	}
	avlt.Inorder();
	cout << avlt.isBalance() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}