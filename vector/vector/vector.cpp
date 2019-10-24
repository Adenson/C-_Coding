#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<algorithm>
#include<string.h>
using namespace std;
namespace V
{
	template<class T>
	class vector
	{
	public:

		typedef T* iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		vector(const vector<T>& v)
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
		}

		void Swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}

		vector<int>& operator=(vector<int> v)
		{
			Swap(v);
			return *this;

			//or
			//vector<int>& operator=(vector<int>& v)
			//{
			//	if (this != &v)
			//	{
			//		vector tmp(v);
			//		Swap(tmp);
			//	}
			//	return *this;
			//}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		void insert(iterator pos, const T& x)
			//此处的pos可能会导致迭代器失效
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2: capacity() * 2;
				reserve(newcapacity);
				pos = _start + n; //如果发生了增容，需要重置pos
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

		void push_back(const T& x)
		{
			//if (_finish == _end_of_storage)
			//{
			//	size_t newcapacity = capacity() == 0 ? 2: capacity() * 2;
			//	reserve(newcapacity);
			//}
			//*_finish = x;
			//++_finish;

		   insert(end(), x);
		}

	     void erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			iterator begin = pos + 1;
			while (begin != end())
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			//return pos;
		}

		void pop_back()
		{
			/*assert(_finish > _start);
			--_finish;*/
			erase(end()-1); 
		}

		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			while (_finish != _finish + n)
			{
				*_finish = value;
				++_finish;
			}
		}

		T& operator[](size_t index)
		{
			return _start[index];
		}

		const T& operator[](size_t index) const
		{
			return _start[index];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t count = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*count);
					delete[]_start;
				}
			   _start = tmp;
			   _finish = _start + count;
			   _end_of_storage = _start + n;
		    }
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		iterator rebgin()
		{
			return _finish;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}

void test1()
{
    V::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	V::vector<int> v2;
	v2.push_back(7);
	v2.push_back(8);
	v2.push_back(9);
	v2.push_back(10);

    //V::vector<int> v2(v1);

	//v1.Swap(v2);

	//v1 = v2;

	//V::vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	//v1.insert(pos, 100);

	//V::vector<int>::iterator pos1 = find(v1.begin(), v1.end(), 3);
	//v1.erase(pos1);

	//cout << v1.size() << endl;
	//cout << v1.capacity() << endl;
	//cout << v1.begin() << endl;
	//cout << v1.end() << endl;

	v1.pop_back();

	for (auto x : v1)
	{
		cout << x << " ";
	}
	cout << endl;

	//for (auto x : v2)
	//{
	//	cout << x << " ";
	//}
	//cout << endl;
}

void test2()
{
	V::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	V::vector<int> v2;
	v2.push_back(7);
	v2.push_back(8);
	v2.push_back(9);
	v2.push_back(10);

	V::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;


	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << ' ';//相当于 V1.operator[](i) ->v1.operator[](&v1,i)
	}
	cout << endl;


	for (auto x : v1)
	{
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	test1();
	//test2();
	system("pause");
	return 0;
}