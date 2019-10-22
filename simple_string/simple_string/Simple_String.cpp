#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class My_string//普通写法
{
public:
	My_string(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	~My_string()
	{
		delete[]_str;
	}

	My_string(const My_string& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	My_string& operator = (const My_string& s)
	{
		if (this != &s)
		{
			delete[]_str;
			_str = new char[strlen(s._str) + 1];
		    strcpy(_str, s._str);
		}
		return *this;
	}
private:
	char* _str;
};


class My_string1//现代写法
{
public:
	My_string1(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	~My_string1()
	{
		delete[]_str;
	}

	My_string1(const My_string1& s)
		:_str(nullptr)
	{
		My_string1 tmp(s._str);//构建tmp临时对象，出了作用域就自己销毁了
		swap(_str, tmp._str);
	}

	My_string1& operator = (const My_string1& s)
	{
		if (this != &s)
		{
			My_string1 tmp(s._str);
			swap(_str, tmp._str);
		}
		return *this;
	}

	//赋值还可以这样子：
	//My_string1& operator = ( My_string1 s)//不能传引用了
	//{
	//	if (this != &s)
	//	{
	//		swap(_str, s._str);
	//	}
	//	return *this;
	//}
private:
	char* _str;
};
void test2()
{
	My_string s4("hello");
	My_string s5(s4);
	My_string s6 = s5;
}
void test1()
{
	My_string1 s1("hello");
	My_string1 s2(s1);
	My_string1 s3 = s2;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}