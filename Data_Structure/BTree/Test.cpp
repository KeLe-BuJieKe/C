#include "BTree.h"


int main()
{
	ZJ::BTree<int, int, 3> t;
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	for (auto& e : a)
	{
		t.Insert(std::make_pair(e, e));
	}
	return 0;
}