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

	//�ݹ����
	bool _InsertR(Node*& root, const K& key)//�������òſ��Բ����ȥ
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

	//�ǵݹ����
	bool Insert(const K& key)
	{
		if (_root == nullptr)//�޽��ʱ
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;//ע��Ҫ�����ﶨ��һ��parent����ǰһ����㣬����������ϲ���ʵ�ֲ���
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
				return false;//��������������ͬ�������ٴβ���
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

	//�������
	void InOrder()//���õݹ�ʱ����Ҫ�ٴζ���һ��_InOrder(),��Ϊ�������������޷�����
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

	//�ǵݹ����
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

	//�ݹ����
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

	//ɾ��
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
				//1.��Ϊ�գ�����Ҳ��������С�����

				if (cur->left == nullptr)
				{
					if (parent == nullptr)//����Ҫ�ж�ɾ���Ľ��ĸ����Ƿ�Ϊ�գ���ֹ���ڵ������Ϊ����Ҫɾ�����ڵ��ʱ�򣬺���� parent ���������
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
				//2.��Ϊ�գ�����Ҳ��������С�����
				else if (cur->right == nullptr)
				{
					if (parent == nullptr)//����Ҫ�ж�ɾ���Ľ��ĸ����Ƿ�Ϊ�գ���ֹ���ڵ���Һ���Ϊ����Ҫɾ�����ڵ��ʱ�򣬺���� parent ���������
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
				//3.���Ҷ���Ϊ��
				else
				{
					Node* lessParent = cur;//����� lessParent ����Ϊ��ʼ��Ϊ�գ�Ӧ�ÿ���ѭ���������ȥ��ʱ��ͻ����
					Node* lessRight = cur->right;
					while (lessRight->left)
					{
						lessParent = lessRight;
						lessRight = lessRight->left;
					}
					cur->_key = lessRight->_key;
					del = lessRight;
					if (lessParent->left == lessRight)//�����滻Ӧ��ɾ�����Ľ����ܻ����Һ���
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