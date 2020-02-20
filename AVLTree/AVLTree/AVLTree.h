#include<iostream>
using namespace std;

template<class k, class v>
struct AVLTreeNode
{
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;
	pair<k, v> _kv;
	int _bf;
	AVLTreeNode(const pair<k, v>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class k, class v>
class AVLTree
{
public:
	typedef AVLTreeNode<k, v> Node;

	AVLTree()
		:_root(nullptr)
	{}

	v& operator[](const k& key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, v()));
		return ret.first->_kv.second;
	}
	pair<Node*, bool> Insert(const pair<k, v>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				make_pair(_root, false);
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		return make_pair(cur, true);
	} 
private:
	Node* _root;
};

void test_AVLTree()
{
	AVLTree<int, int> at;
	at.Insert(make_pair(1, 2));
	at.Insert(make_pair(3, 4));
}