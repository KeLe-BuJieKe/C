#pragma once
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

template<class K,class V>
struct AVLTreeNode	//三叉链
{
	AVLTreeNode* m_left;
	AVLTreeNode* m_right;
	AVLTreeNode* m_parent;

	pair<K, V>m_kv;
	int m_bf;	//平衡因子


	AVLTreeNode(const pair<K, V>&kv)
		: m_left(nullptr), m_right(nullptr), m_parent(nullptr)
		, m_kv(kv), m_bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V>node;
public:
	AVLTree():m_root(nullptr)
	{}

	AVLTree(const AVLTree<K,V>& obj)
	{
		m_root = copy(obj.m_root,nullptr);
	}

	AVLTree<K,V>& operator=(const AVLTree<K,V>& obj)
	{
		if (this != &obj)
		{
			AVLTree<K,V>temp = obj;	//调用拷贝构造
			std::swap(temp.m_root, this->m_root);
		}
		return *this;
	}

	node* copy( node* root,node*parent) //递归利用中序来做深拷贝
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		node* copyNode = new node(root->m_kv);
		copyNode->m_parent = parent;
		copyNode->m_left = copy(root->m_left,root);
		copyNode->m_right = copy(root->m_right,root);
		return copyNode;
	}

	~AVLTree() //利用后序来释放结点
	{
		if (m_root == nullptr)
		{
			return;
		}
		node* cur = m_root;
		node* prev = nullptr;
		stack<node*>s;
		while (cur != nullptr || !s.empty())
		{
			while (cur != nullptr)	//一直把左结点放进栈中
			{
				s.push(cur);
				cur = cur->m_left;
			}
			cur = s.top();
			s.pop();
			//cur->m_right==prev 这个判断很重要，防止访问完右结点时，来回横跳
			if (cur->m_right == nullptr || cur->m_right == prev)
			{
				prev = cur;
				cur->m_bf = 0;
				cur->m_left = nullptr;
				cur->m_parent = nullptr;
				cur->m_right = nullptr;
				delete cur;
				cur = nullptr;
			}
			else
			{
				s.push(cur);
				cur = cur->m_right;
			}
		}
	}

	//传进来的是不平衡的结点的指针
	void RotateL(node* parent)	//左旋
	{
		node* subR = parent->m_right;	//出问题的右结点
		node* subRL = subR->m_left;		//出问题的右结点的左结点

		parent->m_right = subRL;		//首先先将我们的parent的右指向subRL
		if (subRL != nullptr)			//再将subRL的父亲指向parent结点，但这样要判断一下是否是空指针，如果subRL是空指针的话，
										//那么解引用它会出现问题
		{
			subRL->m_parent = parent;
		}

		node* curParent = parent->m_parent;	//拿一个结点存储parent的父亲
		parent->m_parent = subR;			//再使得parent的父亲指针指向它原先的右结点(subR)

		subR->m_left = parent;				//在让subR的左指向parent
		if (parent == m_root)				//在这里得判断一下它是否为根，如果parent为根的话，那么我们的根结点指针也得改变
											//并且将subR的父亲指针置为空，此时subR此时为根结点
		{
			m_root = subR;
			subR->m_parent = nullptr;
		}
		else
		{									//如果不为头节点，那么我们只需要将subR的父亲指针指向parent之前的父亲结点
			if (curParent->m_left == parent)
			{
				curParent->m_left = subR;
			}
			else
			{
				curParent->m_right = subR;
			}
			subR->m_parent = curParent;
		}
		subR->m_bf = parent->m_bf = 0;	//更新平衡因子
	}

	void RotateLR(node* parent)
	{
		node* subL = parent->m_left;
		node* subLR = subL->m_right;
		int bf = subLR->m_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 1)
		{
			parent->m_bf =0;
			subL->m_bf = -1;
			subLR->m_bf = 0;
		}
		else if (bf == -1)
		{
			parent->m_bf = 1;
			subL->m_bf = 0;
			subLR->m_bf = 0;
		}
		else if (bf == 0)
		{
			parent->m_bf = 0;
			subL->m_bf = 0;
			subLR->m_bf = 0;
		}
	}

	void RotateR(node* parent)	//右旋
	{
		node* subL = parent->m_left;
		node* subLR = subL->m_right;

		parent->m_left = subLR;
		if (subLR != nullptr)
		{
			subLR->m_parent = parent;
		}

		node* curParent = parent->m_parent;
		parent->m_parent = subL;

		subL->m_right = parent;
		if (parent==m_root)
		{
			m_root = subL;
			subL->m_parent = nullptr;
		}
		else
		{
			if (curParent->m_left == parent)
			{
				curParent->m_left = subL;
			}
			else
			{
				curParent->m_right = subL;
			}
			subL->m_parent = curParent;
		}
		//为什么subLR的平衡因子不需要改变呢？
		//因为它的左右子树的平衡并没有被改变，所以不需要改变其平衡因子。
		//只需要更改这里出现问题的parent结点与subL结点的平衡因子
		subL->m_bf = parent->m_bf = 0;	//更新平衡因子
	}

	void RotateRL(node* parent)
	{
		node* subR = parent->m_right;
		node* subRL = subR->m_left;
		int bf = subRL->m_bf;

		RotateR(subR);
		RotateL(parent);
		if (bf == 1)
		{
			parent->m_bf = -1;
			subRL->m_bf = 0;
			subR->m_bf = 0;
		}
		else if (bf == -1)
		{
			parent->m_bf = 0;
			subRL->m_bf = 0;
			subR->m_bf = 1;
		}
		else if (bf == 0)
		{
			parent->m_bf = 0;
			subRL->m_bf = 0;
			subR->m_bf = 0;
		}
	}
	V& operator[](const K& key)
	{
		pair<node*, bool>ret = insert(make_pair(key, V()));
		return ret.first->m_kv.second;
	}


	pair<node*,bool> insert(const pair<K, V>& kv)
	{
		if (m_root == nullptr)		//1、如果平衡二叉树为空时，直接再我们的根结点指针创建一个结点
		{
			this->m_root = new node(kv);
			return make_pair(m_root,true);
		}
		else
		{
			//2、如果不为空，我们就按搜索树的规则进行寻找一个位置进行插入
			node* parent = nullptr;					
			node* cur = m_root;
			while (cur != nullptr)
			{
				if (cur->m_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->m_right;
				}
				else if (cur->m_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->m_left;
				}
				else
				{
					return make_pair(cur,false);
				}
			}
			//这里的parent不会造成空指针崩溃的情况
			//当头指针就与我们插入的元素相同时，在上面则会直接return false，不会来到这一步
			//到了这里判断我们要插入的值是比我们的parent值谁的大
			//如果比我的key值大，则创建一个新的结点插入到parent右边。否则插入到parent左边。
			node*newnode = new node(kv);
			cur = newnode;
			if (parent->m_kv.first < kv.first)
			{
				parent->m_right = cur;
				cur->m_parent = parent;
			}
			else
			{
				parent->m_left = cur;
				cur->m_parent = parent;
			}


			//3、更新我们的平衡因子
			while (parent != nullptr)	//我们要一直更新，有可能更新到根结点，如果更新到根结点时，根结点的parent为nullptr,此时就停止循环
			{
				if (parent->m_left == cur)	//如果在我们的左边添加的结点我们就--，右边++
				{
					--parent->m_bf;
				}
				else
				{
					++parent->m_bf;
				}

				if (parent->m_bf == 0)	//如果此时的平衡因子为0了，说明此时已经是平衡的了，不需要任何的处理
				{
					break;
				}
				else if (parent->m_bf== 1 || parent->m_bf== -1)	//如果此时为 -1 或者 1时
																//就说明此时某一边填加了一个新的结点，有可能导致上层结点不平衡
																//我们要继续往上更新平衡因子
				{
					cur = parent;
					parent = parent->m_parent;
				}
				else if (parent->m_bf == 2 || parent->m_bf == -2)	//如果等于 2 或 -2时，那么此时就会发现此时我们的平衡搜索二叉树不平衡了
																	//我们要进行旋转， 让它重新变的平衡
				{
					if (parent->m_bf == 2)		
					{
						if (cur->m_bf == 1)  //左旋 路径是直线
						{
							RotateL(parent);
						}
						else if (cur->m_bf == -1) //右左双旋 路径是折线
						{
							RotateRL(parent);
						}

					}
					else if(parent->m_bf== -2)
					{
						if (cur->m_bf == -1)   //右旋 路径是直线
						{
							RotateR(parent);
						}
						else if(cur->m_bf == 1) ////左右双旋 路径是折线
						{
							RotateLR(parent);
						}
					}

					//旋转完成后，parent所在的树的高度恢复到了插入节点前高度
					//如果是子树，对上层没有影响，更新结束。
					break;
				}

			}
			return make_pair(newnode, true);
		}
	}
	int depth(node*& root) 
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftHeight = depth(root->m_left);
		int rightHeight = depth(root->m_right);
		return max(depth(root->m_left), depth(root->m_right)) + 1;
		//leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _isBalance(node* &root)	
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHeight = depth(root->m_left);
		int rightHeight = depth(root->m_right);

		return abs(leftHeight - rightHeight) < 2
			&& _isBalance(root->m_left)
			&& _isBalance(root->m_right);
	}

	bool isBalance()	
	{
		return _isBalance(m_root);
	}

	void _Inorder( node* &root) 
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->m_left);
		cout << root->m_kv.first << " : " << root->m_kv.second << endl;
		_Inorder(root->m_right);
	}
	void Inorder() 
	{
		_Inorder(m_root);
		cout << endl;
	}
private:
	node* m_root;	//根结点
};

