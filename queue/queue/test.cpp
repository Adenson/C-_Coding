#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"queue.h"
void Test_Myqueue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.pop();
	cout << q.size() << endl;
	cout << q.empty() << endl;
	cout << q.front() << endl;
}
int main()
{
	Test_Myqueue();
	system("pause");
	return 0;
}