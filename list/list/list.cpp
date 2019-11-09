#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
namespace L
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;

		_list_node(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};

	template<class T, class Ref, class Ptr>
	class _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> Self;
	public:
		_list_iterator(node* node)
			:_node(node)
		{}

		Ref operator*() //内置类型
		{
			return _node->_data;
		}

		Ptr operator->() //自定义类型
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			_list_iterator<T,Ref,Ptr> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		//it1 !=  it2
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	//private:
		node* _node;
	};


	template<class T>
	class list
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
	public:
		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		list<T>& operator=(const list<T>& l)
		{
			clear();//不要忘记清理之前的
			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
			return *this;


		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void push_back(const T& x)//尾插
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;//先找出尾元素

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//insert(end(),x);
		}

		void pop_back()//尾删
		{
	    	node* tail = _head->_prev->_prev;
			tail->_next = _head;
			_head->_prev = tail;
			//erase(--end());
		}

		void push_front(const T& x)//头插
		{
			insert(begin(),x);
		}

		void pop_front()//头删
		{
			erase(begin());
		}

		iterator erase(iterator pos)
		{
			node* cur = pos._node;
			assert(cur != _head);

			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;

			delete cur;
			return iterator(next);
		}

		void insert(iterator pos,const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		void print_list()
		{
			auto it = begin();
			while (it != end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{ 
			return iterator(_head);//list的 end 就是 _head
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}
	private:
		node* _head;
	};

}

void test()
{
	L::list<int> l1;
	L::list<int> l2;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	l1.print_list();
	l1.pop_back();
	l1.push_front(25);
	l1.pop_front();
	l1.print_list();

	/*L::list<int> l2(l1);
	l2 = l1;
	l2.print_list();*/
}
int main()
{
	test();
	system("pause");
	return 0;
}
