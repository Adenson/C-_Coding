#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<assert.h>
#include"AVLTree.h"

void test_AVLTree()
{
	AVLTree<int, int> at;
	//int test_arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int test_arr1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto& num : test_arr1)
	{
		at.Insert(make_pair(num, num));
	}
	cout << at.isBalance() << endl;
}
int main()
{
	test_AVLTree();
	system("pause");
	return 0;
}