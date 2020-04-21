#pragma once
#include <deque>
using namespace std;
template<class T,class containor=deque<T>>
class queue
{
public:
	void push(const T& num)
	{
		_con.push_back(num);
	}
	void pop()
	{
		_con.pop_front();
	}

	T& front()
	{
		return _con.front();
	}

	T& back()
	{
		return _con.back();
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
	containor _con;
};