#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<limits.h>
#include<stack>
using namespace std;


//Key模型
template<class K>
class BSTreeNode
{
public:
	BSTreeNode(const K&key):m_left(nullptr), m_right(nullptr),m_key(key)
	{

	}
	BSTreeNode<K>* m_left;
	BSTreeNode<K>* m_right;
	K m_key;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> node;
public:
	BSTree():m_root(nullptr)
	{

	}
	BSTree(const BSTree<K> &obj)
	{
		m_root = copy(obj.m_root);
	}
	BSTree<K>& operator=(const BSTree<K>& obj)
	{
		if (this != &obj)
		{
			BSTree<K>temp = obj;	//调用拷贝构造
			std::swap(temp.m_root, this->m_root);
		}
		return *this;
	}
	node* copy(const node*root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		node* copyNode = new node(root->m_key);
		copyNode->m_left = copy(root->m_left);
		copyNode->m_right = copy(root->m_right);
		return copyNode;
	}
	~BSTree()
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
			while (cur!= nullptr)	//一直把左结点放进栈中
			{
				s.push(cur);
				cur = cur->m_left;
			}
			cur = s.top();
			s.pop();
			//cur->m_right==prev 这个判断很重要，防止访问完右结点时，来回横跳
			if (cur->m_right==nullptr||cur->m_right==prev)
			{
				prev = cur;
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
	bool insert(const K&key)
	{
		if (m_root == nullptr)
		{
			m_root = new node(key);
			return true;
		}

		node* parent = nullptr;
		node* cur = m_root;
		while (cur!=nullptr)
		{
			if (cur->m_key < key)
			{
				parent = cur;
				cur = cur->m_right;
			}
			else if (cur->m_key > key)
			{
				parent = cur;
				cur = cur->m_left;
			}
			else
			{
				return false;
			}
		}

		if (parent->m_key < key)
		{
			parent->m_right = new node(key);
		}
		else
		{
			parent->m_left = new node(key);
		}
		return true;
	}

	bool find(const K& key)
	{
		if (m_root == nullptr)
		{
			return false;
		}

		node* cur = m_root;
		while (cur != nullptr)
		{
			if (cur->m_key < key)
			{
				cur = cur->m_right;
			}
			else if (cur->m_key > key)
			{
				cur = cur->m_left;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	void Inorder()
	{
		stack<node*>path;
		node* cur = m_root;

		while (cur != nullptr || !path.empty())
		{
			while (cur != nullptr)
			{
				path.push(cur);
				cur = cur->m_left;
			}
			node* temp = path.top();
			path.pop();
			cout << temp->m_key << " ";
			cur = temp->m_right;
		}
		cout << endl;
	}

	bool erase(const K& key)
	{
		if (m_root == nullptr)
		{
			return false;
		}

		node* cur = m_root;
		node* parent = nullptr;		//该结点有可能未空指针，造成错误，已解决
		while (cur!=nullptr)
		{
			if (cur->m_key < key)
			{
				parent = cur;
				cur = cur->m_right;
			}
			else if (cur->m_key > key)
			{
				parent = cur;
				cur = cur->m_left;
			}
			else
			{
				//当这里的结点左右孩子都没有就无所谓了，让其随便进入 情况1 或者 2
				if (cur->m_left == nullptr)		//1、要删除的结点只有右孩子结点
				{
					if (parent != nullptr)
					{
						if (parent->m_right == cur)	//如果你是的右孩子，那么我把我的 右指针 指向 你的右
						{
							parent->m_right = cur->m_right;
						}
						else
						{
							parent->m_left = cur->m_right;	//如果你是的左孩子，那么我把我的 左指针 指向 你的右
						}
					}
					else
					{
						m_root = cur->m_right;
					}

					delete cur;
					cur =nullptr;
				}
				else if(cur->m_right==nullptr)	//2、要删除的结点只有左孩子结点
				{
					if (parent != nullptr)
					{
						if (parent->m_left == cur)	//同理 如果你是的左孩子，那么我把我的 左指针 指向 你的左
						{
							parent->m_left = cur->m_left;
						}
						else
						{
							parent->m_right = cur->m_left;	//如果你是的右孩子，那么我把我的 左指针 指向 你的左
						}
					}
					else
					{
						m_root = cur->m_left;
					}
					delete cur;
					cur = nullptr;
				}
				else    //3、要删除的结点有左、右孩子结点
				{
					node* rightmin = cur->m_right;
					node* rightminparent = nullptr;	//有可能空指针情况,已解决

					while (rightmin->m_left != nullptr)
					{
						rightminparent = rightmin;
						rightmin = rightmin->m_left;
					}	

					if (rightminparent == nullptr)
					{
						cur->m_key = rightmin->m_key;
						cur->m_right = rightmin->m_right;
					}
					else
					{
						cur->m_key = rightmin->m_key;
						rightminparent->m_left = rightmin->m_right;
					}
					delete  rightmin;
					rightmin = nullptr;
					return true;
				}
			}
		}
		return false;
	}

public:
	bool eraseR(const K& key)
	{
		return _eraseR(m_root, key);
	}
private:
	bool _eraseR(node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (root->m_key < key)
		{
			_eraseR(root->m_right, key);
		}
		else if (root->m_key > key)
		{
			_eraseR(root->m_left, key);
		}
		else
		{
			if (nullptr == root->m_left)
			{
				node* del = root;
				root = root->m_right;	//由于这里的root参数是&类型，这一句相当于是root的父亲结点parent的左右指针的一个被赋值为root->m_right
				delete del;
				del = nullptr;
			}
			else if (nullptr == root->m_right)
			{
				node* del = root;
				root = root->m_left;
				delete del;
				del = nullptr;
			}
			else
			{
				node* Rightmin = root->m_right;	//不能用root直接来遍历，不然会找不到此时的root的右子树
				while (Rightmin->m_left != nullptr)
				{
					Rightmin = Rightmin->m_left;
				}
				K min = Rightmin->m_key;	//转化思路：我们原来是要删除有左右子树的结点，转换成删除删除结点的右子树的最小节点
				_eraseR(root->m_right, min);
				root->m_key = min;
			}
			return true;
		}
	}

public:
	bool isBSTree()
	{
		return _isBSTree(m_root);
	}
private:
	bool _isBSTree(node*& root) const
	{
		if (root == nullptr)
		{
			return true;
		}
		stack<node*>st;
		node* cur = root;
		int prev = INT_MIN + 1;
		while (!st.empty() || cur != nullptr)
		{
			if (cur != nullptr)
			{
				st.push(cur);
				cur = cur->m_left;
			}
			cur = st.top();
			st.pop();
			if (cur->m_key <= prev)
			{
				return false;
			}
			prev = cur->m_key;
			cur = cur->m_right;
		}
		return true;
	}

public:
	void InorderR()
	{
		_InorderR(m_root);
		cout << endl;
	}
private:
	void _InorderR(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InorderR(root->m_left);
		cout << root->m_key << "  ";
		_InorderR(root->m_right);
	}

public:
	bool findR(const K& key)
	{
		return _findR(m_root, key);
	}
private:
	bool _findR(const node* root,const K & key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->m_key < key)
		{
			return _findR(root->m_right, key);
		}
		else  if (root->m_key > key)
		{
			return _findR(root->m_left, key);
		}
		else
		{
			return  true;
		}
	}

public:
	bool insertR(const K& key)
	{
		return _insertR(m_root, key);
	}
private:
	//实现这个方法的关键是这个引用，当此时的root等于nullptr，相当于上一级的root->left或者root->right，此时被我们用该引用new node(key)
	bool _insertR(node*& root, const K& key) 
	{
		if (root == nullptr)
		{
			root = new node(key);
			return true;
		}
		if (root->m_key < key)
		{
			return _insertR(root->m_right, key);
		}
		else  if (root->m_key > key)
		{
			return _insertR(root->m_left, key);
		}
		else
		{
			return false;
		}
	}

private:
	node* m_root;	//搜索二叉树根结点
};
