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

		Node* newNode = new Node(kv);
		cur = newNode;
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
		while (parent)
		{
			// 更新双亲的平衡因子
			if (cur == parent->_right)
			{
				parent->_bf += 1;
			}
			else
			{
				parent->_bf -= 1;
			}

			// 更新后检测双亲的平衡因子
			if (parent->_bf == -1 || parent->_bf == 1)
			{
				// 插入前双亲的平衡因子是0，插入后双亲的平衡因为为1 或者 -1 ，说明以双亲为根的二叉树的高度增加了一层，因此需要继续向上调整 
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 0)
			{
				// 插入后双亲的平衡因为为0，说明以双亲为根的二叉树的高度并没有增加，直接退出
				break;
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				// 插入后双亲的平衡因子为+2 或者 -2，违反了AVL树的平衡性，需要对以pParent为根的树进行旋转处理
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);//右旋
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);//左旋
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);//先左旋再右旋
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);//先右旋再左旋
				}
				else
				{
					assert(false);
				}
				break;
			}
		}
		return make_pair(newNode, true);
	} 

	void RotateL(Node* parent)//左旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;

		if (subRL)//判断是否为空，如果不判断就会出错
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* grandfather = parent->_parent;
		parent->_parent = subR;

		//考虑 parent 的父亲结点是否为根节点 root
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (grandfather->_left == parent)
			{
				grandfather->_left = subR;
			}
			if (grandfather->_right == parent)
			{
				grandfather->_right = subR;
			}
			subR->_parent = grandfather;
		}
		subR->_bf = parent->_bf = 0;
	}

	void RotateR(Node* parent)//右旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)//一定要判断是否为空
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		Node* grandfather = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (grandfather->_left == parent)
			{
				grandfather->_left = subL;
			}
			if (grandfather->_right == parent)
			{
				grandfather->_right = subL;
			}
		   subL->_parent = grandfather;
		}
		parent->_bf = subL->_bf = 0;
	}
	
	void RotateLR(Node* parent)//先左旋再右旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;//最终平衡因子的改变主要是因为插入结点后 subLR 的平衡因子发生改变
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}
	
	void RotateRL(Node* parent)//先右旋再左旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;//最终平衡因子的改变主要是因为插入结点后 subRL 的平衡因子发生改变
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
	}

	int getHeight(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			int leftHeight = getHeight(root->_left);
			int rightHeight = getHeight(root->_right);
			return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}
	}

	bool _isBalance(Node* root)//判断是否为平衡二叉搜索树
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftHeight = getHeight(root->_left);
		int rightHeight = getHeight(root->_right);
		if (rightHeight - leftHeight != root->_bf)//检验平衡因子是否正常
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}
		return abs(leftHeight - rightHeight) <= 1 
				&& _isBalance(root->_left) 
				&& _isBalance(root->_right);
	}

	bool isBalance()
	{
		return _isBalance(_root);
	}
private:
	Node* _root;
};