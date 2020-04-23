#define _CRT_SECURE_NO_WARNINGS 1
#include"priority_queue.h"
void test_priority_queue()
{
	priority_queue<int,vector<int>,Less<int>> pq;
	pq.push(4);
	pq.push(1);
	pq.push(2);
	pq.push(3);
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
}
int main()
{
	test_priority_queue();
	system("pause");
	return 0;
}