#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<limits.h>
//Keyģ��
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
			while (cur!= nullptr)	//һֱ������Ž�ջ��
			{
				s.push(cur);
				cur = cur->m_left;
			}
			cur = s.top();
			s.pop();
			//cur->m_right==prev ����жϺ���Ҫ����ֹ�������ҽ��ʱ�����غ���
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

	void _Inorder(node *root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->m_left);
		cout << root->m_key << "  ";
		_Inorder(root->m_right);
	}
	void Inorder()
	{
		_Inorder(m_root);
		cout << endl;
	}
  bool _isBSTree(node*& root)
  {
    if(root==nullptr)
    {
      return true;
    }
    stack<node*>st;
    node*cur=root;
    int prev=INT_MIN+1;
    while(!st.empty()||cur!=nullptr)
    {
      if(cur!=nullptr)
      {
        st.push(cur);
        cur=cur->m_left;
      }
      cur=st.top();
      st.pop();
      if(cur->m_key<=prev)
      {
        return false;
      }
      prev=cur->m_key;
      cur=cur->m_right;
    }
    return true;
  }
  
  bool isBSTree()
  {
    return _isBSTree(m_root);
  }

	bool erase(const K& key)
	{
		if (m_root == nullptr)
		{
			return false;
		}

		node* cur = m_root;
		node* parent = nullptr;		//�ý���п���δ��ָ�룬��ɴ����ѽ��
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
				//������Ľ�����Һ��Ӷ�û�о�����ν�ˣ����������� ���1 ���� 2
				if (cur->m_left == nullptr)		//1��Ҫɾ���Ľ��ֻ���Һ��ӽ��
				{
					if (parent != nullptr)
					{
						if (parent->m_right == cur)	//������ǵ��Һ��ӣ���ô�Ұ��ҵ� ��ָ�� ָ�� �����
						{
							parent->m_right = cur->m_right;
						}
						else
						{
							parent->m_left = cur->m_right;	//������ǵ����ӣ���ô�Ұ��ҵ� ��ָ�� ָ�� �����
						}
					}
					else
					{
						m_root = cur->m_right;
					}

					delete cur;
					cur =nullptr;
				}
				else if(cur->m_right==nullptr)	//2��Ҫɾ���Ľ��ֻ�����ӽ��
				{
					if (parent != nullptr)
					{
						if (parent->m_left == cur)	//ͬ�� ������ǵ����ӣ���ô�Ұ��ҵ� ��ָ�� ָ�� �����
						{
							parent->m_left = cur->m_left;
						}
						else
						{
							parent->m_right = cur->m_left;	//������ǵ��Һ��ӣ���ô�Ұ��ҵ� ��ָ�� ָ�� �����
						}
					}
					else
					{
						m_root = cur->m_left;
					}
					delete cur;
					cur = nullptr;
				}
				else    //3��Ҫɾ���Ľ�������Һ��ӽ��
				{
					node* rightmin = cur->m_right;
					node* rightminparent = nullptr;	//�п��ܿ�ָ�����,�ѽ��

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
private:
	node* m_root;	//���������������
};
