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
	//int arr[] = { 16,3,7,11,9,26,18,14,15 };
	//int arr[] = { 18,15,26,14,16 };
	//int arr[] = { 60,40,70,20,55,65,81,10,30 };
	vector<int>arr(110);
	int j = 1;
	for (auto& e : arr)
	{
		e = j++;
	}
	AVLTree<int, int>avlt1;
	
	for (auto& e : arr)
	{
		avlt1.insert(make_pair(e, e));
	}

	//avlt1.Inorder();
	//cout << avlt1.isBalance() << endl;
	//AVLTree<int, int>avlt2(avlt1);
	//avlt1.Erase(26);
	//avlt1.Erase(26);
	//avlt1.Erase(55);
	int i = 1;
	
	for (auto& e : arr)
	{
		avlt1.Erase(e);
		//avlt1.Inorder();
		cout<<i++<<"   "<< avlt1.isBalance() << endl;
		cout << endl;
	}
}

void test2()
{
	//int arr[] = {50,30,60,55,75};
	int arr[] = { 60,40,80,30,55,70,90,85,100 };
	//int arr[] = { 60,40,90,30,55,80,100,50,58 };
	AVLTree<int, int>avlt1;

	for (auto& e : arr)
	{
		avlt1.insert(make_pair(e, e));
	}

	//avlt1.Inorder();
	//cout << avlt1.isBalance() << endl;
	AVLTree<int, int>avlt2(avlt1);
	//avlt1.Erase(30);
	//avlt1.Erase(70);
	//avlt1.Erase(30);

	for (auto& e : arr)
	{
		avlt1.Erase(e);
		avlt1.Inorder();
		cout << avlt1.isBalance() << endl;
		cout << endl;
	}
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}