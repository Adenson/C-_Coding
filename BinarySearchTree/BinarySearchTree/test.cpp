#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream >
using namespace std;
#include"BinarySearchTree.h"
void TestBSTree()
{
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : arr)
	{
		t.InsertR(e);
	}
	BSTreeNode<int>* node = t.FindR(1);
	if (node)
	{
		cout << node->_key << endl;
	}
	t.InOrder();
	t.erase(2);
	t.erase(8);
	t.erase(1);
	t.erase(7);
	t.erase(5);
	t.InOrder();

	for (auto e : arr)//测试删除根节点的时候是否会出错
	{
		t.erase(e);
	}
}
int main()
{
	TestBSTree();
	system("pause");
	return 0;
}
