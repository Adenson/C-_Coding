template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* left;
	BSTreeNode<K>* right;
	K _key;

	BSTreeNode(const K& key)
		:_key(key)
		, left(nullptr)
		, right(nullptr)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	//递归插入
	bool _InsertR(Node*& root, const K& key)//加上引用才可以插入进去
	{
		if (root == nullptr)
		{
			root = new Node(key);
		}
		if (root->_key < key)
		{
			return _InsertR(root->right, key);
		}
		else if (root->_key > key)
		{
			return _InsertR(root->left, key);
		}
		else
		{
			return false;
		}
	}
	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	//非递归插入
	bool Insert(const K& key)
	{
		if (_root == nullptr)//无结点时
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;//注意要在这里定义一个parent保存前一个结点，最后在连接上才能实现插入
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return false;//不允许与树中相同的数据再次插入
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->right = cur;
		}
		else
		{
			parent->left = cur;
		}
		return true;
	}

	//中序遍历
	void InOrder()//调用递归时候，需要再次定义一个_InOrder(),因为对象在类外面无法传参
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->left);
		cout << root->_key << " ";
		_InOrder(root->right);
	}

	//非递归查找
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->right;
			}
			else if (cur->_key > key)
			{
				cur = cur->left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	//递归查找
	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->_key == key)
		{
			return root;
		}
		else if (root->_key < key)
		{
			return _FindR(root->right, key);
		}
		else if (root->_key > key)
		{
			return _FindR(root->left, key);
		}
	}
	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	//删除
	bool erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				Node* del = cur;
				//1.左为空（里面也包含两种小情况）

				if (cur->left == nullptr)
				{
					if (parent == nullptr)//这里要判断删除的结点的父亲是否为空，防止根节点的左孩子为空且要删除根节点的时候，后面对 parent 操作会出错
					{
						_root = cur->right;
					}
					else
					{
						if (parent->left == cur)
						{
							parent->left = cur->right;
						}
						else
						{
							parent->right = cur->right;
						}
					}
				}
				//2.右为空（里面也包含两种小情况）
				else if (cur->right == nullptr)
				{
					if (parent == nullptr)//这里要判断删除的结点的父亲是否为空，防止根节点的右孩子为空且要删除根节点的时候，后面对 parent 操作会出错
					{
						_root = cur->left;
					}
					else
					{
						if (parent->left == cur)
						{
							parent->left = cur->left;
						}
						else
						{
							parent->right = cur->left;
						}
					}
				}
				//3.左右都不为空
				else
				{
					Node* lessParent = cur;//这里的 lessParent 不能为初始化为空，应该考虑循坏如果不进去的时候就会出错
					Node* lessRight = cur->right;
					while (lessRight->left)
					{
						lessParent = lessRight;
						lessRight = lessRight->left;
					}
					cur->_key = lessRight->_key;
					del = lessRight;
					if (lessParent->left == lessRight)//用来替换应该删除结点的结点可能还有右孩子
					{
						lessParent->left = lessRight->right;
					}
					else
					{
						lessParent->right = lessRight->right;
					}
				}
				delete del;
				return true;
			}
		}
		return false;
	}
private:
	Node* _root;
};