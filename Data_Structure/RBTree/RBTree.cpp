#include"RBTree.h"
#include<time.h>
#include<vector>
int main()
{
	int arr[] = { 16,3,7,11,9,26,18,14,15 };
	int arr1[] = { 4,2,6,1,3,5,15,7,16,14 };

	RBTree<int, int>rb;
	for (auto& e : arr)
	{
		rb.insert(make_pair(e, e));
	}

	rb.Inorder();
	cout << rb.IsValidRBTree() << endl;
	system("pause");
	return 0;
}