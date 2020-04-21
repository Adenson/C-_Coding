#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void test_Mystack()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
	printf("%d\n", s.top());
}
int main()
{
	test_Mystack();
	system("pause");
	return 0;
}