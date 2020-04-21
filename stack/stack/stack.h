#pragma once
using namespace std;
#include<deque>

template<class T,class container = deque<int>>
class stack
{
public:
	void push(const T& num)
	{
		_con.push_back(num);
	}

	T& top()
	{
		return _con.back();
	}

	void pop()
	{
		_con.pop_back();
	}

	size_t size()
	{
		return _con.size();
	}

	bool empty()
	{
		return _con.empty();
	}
private:
	container _con;
};