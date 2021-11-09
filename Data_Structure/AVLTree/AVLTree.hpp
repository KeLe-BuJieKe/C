#pragma once
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

template<class K,class V>
struct AVLTreeNode	//������
{
	AVLTreeNode* m_left;
	AVLTreeNode* m_right;
	AVLTreeNode* m_parent;

	pair<K, V>m_kv;
	int m_bf;	//ƽ������


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
			AVLTree<K,V>temp = obj;	//���ÿ�������
			std::swap(temp.m_root, this->m_root);
		}
		return *this;
	}

	node* copy( node* root,node*parent) //�ݹ����������������
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

	~AVLTree() //���ú������ͷŽ��
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
			while (cur != nullptr)	//һֱ������Ž�ջ��
			{
				s.push(cur);
				cur = cur->m_left;
			}
			cur = s.top();
			s.pop();
			//cur->m_right==prev ����жϺ���Ҫ����ֹ�������ҽ��ʱ�����غ���
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

	//���������ǲ�ƽ��Ľ���ָ��
	void RotateL(node* parent)	//����
	{
		node* subR = parent->m_right;	//��������ҽ��
		node* subRL = subR->m_left;		//��������ҽ�������

		parent->m_right = subRL;		//�����Ƚ����ǵ�parent����ָ��subRL
		if (subRL != nullptr)			//�ٽ�subRL�ĸ���ָ��parent��㣬������Ҫ�ж�һ���Ƿ��ǿ�ָ�룬���subRL�ǿ�ָ��Ļ���
										//��ô�����������������
		{
			subRL->m_parent = parent;
		}

		node* curParent = parent->m_parent;	//��һ�����洢parent�ĸ���
		parent->m_parent = subR;			//��ʹ��parent�ĸ���ָ��ָ����ԭ�ȵ��ҽ��(subR)

		subR->m_left = parent;				//����subR����ָ��parent
		if (parent == m_root)				//��������ж�һ�����Ƿ�Ϊ�������parentΪ���Ļ�����ô���ǵĸ����ָ��Ҳ�øı�
											//���ҽ�subR�ĸ���ָ����Ϊ�գ���ʱsubR��ʱΪ�����
		{
			m_root = subR;
			subR->m_parent = nullptr;
		}
		else
		{									//�����Ϊͷ�ڵ㣬��ô����ֻ��Ҫ��subR�ĸ���ָ��ָ��parent֮ǰ�ĸ��׽��
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
		subR->m_bf = parent->m_bf = 0;	//����ƽ������
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

	void RotateR(node* parent)	//����
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
		//ΪʲôsubLR��ƽ�����Ӳ���Ҫ�ı��أ�
		//��Ϊ��������������ƽ�Ⲣû�б��ı䣬���Բ���Ҫ�ı���ƽ�����ӡ�
		//ֻ��Ҫ����������������parent�����subL����ƽ������
		subL->m_bf = parent->m_bf = 0;	//����ƽ������
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
		if (m_root == nullptr)		//1�����ƽ�������Ϊ��ʱ��ֱ�������ǵĸ����ָ�봴��һ�����
		{
			this->m_root = new node(kv);
			return make_pair(m_root,true);
		}
		else
		{
			//2�������Ϊ�գ����ǾͰ��������Ĺ������Ѱ��һ��λ�ý��в���
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
			//�����parent������ɿ�ָ����������
			//��ͷָ��������ǲ����Ԫ����ͬʱ�����������ֱ��return false������������һ��
			//���������ж�����Ҫ�����ֵ�Ǳ����ǵ�parentֵ˭�Ĵ�
			//������ҵ�keyֵ���򴴽�һ���µĽ����뵽parent�ұߡ�������뵽parent��ߡ�
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


			//3���������ǵ�ƽ������
			while (parent != nullptr)	//����Ҫһֱ���£��п��ܸ��µ�����㣬������µ������ʱ��������parentΪnullptr,��ʱ��ֹͣѭ��
			{
				if (parent->m_left == cur)	//��������ǵ������ӵĽ�����Ǿ�--���ұ�++
				{
					--parent->m_bf;
				}
				else
				{
					++parent->m_bf;
				}

				if (parent->m_bf == 0)	//�����ʱ��ƽ������Ϊ0�ˣ�˵����ʱ�Ѿ���ƽ����ˣ�����Ҫ�κεĴ���
				{
					break;
				}
				else if (parent->m_bf== 1 || parent->m_bf== -1)	//�����ʱΪ -1 ���� 1ʱ
																//��˵����ʱĳһ�������һ���µĽ�㣬�п��ܵ����ϲ��㲻ƽ��
																//����Ҫ�������ϸ���ƽ������
				{
					cur = parent;
					parent = parent->m_parent;
				}
				else if (parent->m_bf == 2 || parent->m_bf == -2)	//������� 2 �� -2ʱ����ô��ʱ�ͻᷢ�ִ�ʱ���ǵ�ƽ��������������ƽ����
																	//����Ҫ������ת�� �������±��ƽ��
				{
					if (parent->m_bf == 2)		
					{
						if (cur->m_bf == 1)  //���� ·����ֱ��
						{
							RotateL(parent);
						}
						else if (cur->m_bf == -1) //����˫�� ·��������
						{
							RotateRL(parent);
						}

					}
					else if(parent->m_bf== -2)
					{
						if (cur->m_bf == -1)   //���� ·����ֱ��
						{
							RotateR(parent);
						}
						else if(cur->m_bf == 1) ////����˫�� ·��������
						{
							RotateLR(parent);
						}
					}

					//��ת��ɺ�parent���ڵ����ĸ߶Ȼָ����˲���ڵ�ǰ�߶�
					//��������������ϲ�û��Ӱ�죬���½�����
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
	node* m_root;	//�����
};

