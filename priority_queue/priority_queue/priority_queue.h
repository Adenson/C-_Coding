#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Less
{
public:
	bool operator()(T x1, T x2)
	{
		return x1 < x2;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(T x1, T x2)
	{
		return x1 > x2;
	}
};

template<class T,class container = vector<T>,class cmp = Less<T>>
class priority_queue
{
public:
	void adjustUp(size_t& index)
	{
		cmp cmp;
		size_t child = index;
		size_t parent = (child - 1) / 2;
		while (child > 0)
		{
			//if (_con[parent] < _con[index])
			if (cmp(_con[parent],_con[index]))
			{
				swap(_con[index], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void push(const T& num)
	{
		_con.push_back(num);
		size_t index = _con.size() - 1;
		adjustUp(index);
	}

	T& top()
	{
		return _con.front();
	}

	void adjustDown(size_t index)
	{
		cmp cmp;
		size_t parent = index;
		size_t child = parent * 2 + 1;
		while (child < _con.size())
		{
			if (child + 1 < _con.size() && cmp(_con[child], _con[child + 1]))
			{
				child++;
			}
			if (cmp(_con[parent],_con[child]))
			{
				swap(_con[parent], _con[child]);
				parent = child;
				child = parent * 2 + 1;		
			}
			else{
				break;
			}
		}
	}

	void pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		adjustDown(0);
	}

	bool empty()
	{
		return _con.empty();
	}
private:
	container _con;
};