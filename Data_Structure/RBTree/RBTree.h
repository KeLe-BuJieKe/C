#pragma once
#include<iostream>
using namespace std;

//�ڵ����ɫ
enum class Colour
{
	RED,
	BLACK
};

//K-Vģ��
template<class K,class V>
struct RBTreeNode	//������
{
	RBTreeNode<K,V>* m_left;	//��ڵ�
	RBTreeNode<K,V>* m_right;   //�ҽڵ�
	RBTreeNode<K,V>* m_parent;  //�ڵ�ĸ����(�������Ҫ ��ת ��Ϊ��ʵ�ּ򵥸����ĸ��ֶ�)

	pair<K, V>m_kv; //�ڵ�����
	Colour m_c;	//�ڵ���ɫ


	RBTreeNode(const pair<K, V>& kv)
		: m_left(nullptr), m_right(nullptr), m_parent(nullptr)
		, m_kv(kv),m_c(Colour::RED)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> node;
public:
	RBTree() :m_root(nullptr)
	{}
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
		if (parent == m_root)
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

	}


	bool insert(const pair<K, V>& kv)
	{
		if (m_root == nullptr)
		{
			m_root = new node(kv);
			m_root->m_c = Colour::BLACK;	//���ڵ����ɫ����Ϊ��
			return true;
		}
		else
		{
			node* parent = nullptr;	
			node* cur = m_root;
			while (cur!=nullptr)
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
					return false;
				}
			}

			cur = new node(kv);	//Ĭ�Ϲ��캯����ɫ��ʼ��ΪRED��
			if (parent->m_kv.first > kv.first)  //�ж��²���Ľڵ���Ҫ���뵽���ǵ���߻����ұߣ����ø��ڵ��ָ����������
			{
				parent->m_left = cur;
				cur->m_parent = parent;
			}
			else
			{
				parent->m_right = cur;
				cur->m_parent = parent;
			}


			while (parent != nullptr && parent->m_c == Colour::RED)	//��Ϊ���ǲ������ɫ�Ǻ�ɫ�������ǵĸ��׽ڵ����ɫҲΪ��ʱ��Ҫһֱ���ϵ�����ɫ
			{
				//�������˻����ɻ���������游�ڵ�Ϊʲô���ж���Ϊ��ָ����������������ǿ�ָ�룬��������ǲ��ǻ���ɿ�ָ����ʱ����أ�
				//��ʵ��Ȼ��������ǵĽڵ��в���ǰֻ��ͷ�ڵ�һ������ô���Ͳ�����뵽���ѭ������
				//��Ϊ���ڵ����ɫΪ ��
				//�����ʱ�����������������ڵ㣬�ڶ����ڵ㲻�����ڸ��ڵ����߻����ұߡ�
				//��ʱ��ô���Ǽ�������һ���ڵ��ڸ��������
				//��ô�������Ҫ�����Ԫ���ǲ��뵽�������ұߣ���ô��ʱ���Ǻ�����ͬ������������������ѭ������
				//������뵽�ڶ����ڵ�����棬��ô��ʱ��Ȼparent����ɫΪ�գ��������ǵ� �游�ڵ�(grandfather)����Ϊ��
				//���������������ﲻ��Ҫ�ж����Ƿ�Ϊ��ָ����������������ɿ�ָ���������
				node* grandfather=parent->m_parent;	//�游

				//Ҫ���ʲô��ɫ�ؼ�������uncle�����������ҵ������λ����������
				if (grandfather->m_left == parent)  //�ж�
				{
					node* uncle = grandfather->m_right;
					//��һ�������������� ��Ϊ ��
					if (uncle != nullptr && uncle->m_c == Colour::RED)
					{
						grandfather->m_c = Colour::RED;
						parent->m_c = uncle->m_c = Colour::BLACK;

						//Ϊʲô��cur=grandfather��������parent�أ�
						//������Ϊ��ʱ���������parent����ɫ��ɺ�ɫ����ɫʱ������ڵ�Ͳ���Ҫ�ж��ˡ�
						//�����parent��ʼ���Ͳ��ܼ������ϸ����ˡ���ֱ����ֹѭ����
						//���Ǵ����Ǹոձ�ɺ�ɫ��grandfather�ڵ㿪ʼ���п��ܴ�ʱgrandfather�ڵ��Ϊ��
						//�����ϲ�ÿ��·���ĺ�ɫ�ڵ���Ŀ��ͬ��������
						cur = grandfather;			//�������ϸ�����ɫ
						parent = cur->m_parent;
					}
					//�ڶ� ��������������岻���� �� ���������Ϊ ��
					else
					{
						//˫�� -> ����
						if (parent->m_right == cur)	//�ж�·���Ƿ������ߣ���������߾���Ҫ��������������
						{						//������ɺ󣬽�parentָ����curָ���ָ����ģ���Ϊcur��parent����Դ����ˣ���Ȼ����ִ���
							RotateL(parent);
							std::swap(parent, cur);
						}

						//�����п����ǵ������������ת������
						RotateR(grandfather);
						grandfather->m_c = Colour::RED;
						parent->m_c = Colour::BLACK;

						//��Ϊ������������ ��ɫ���Ǻ�ɫ��֮�󶼲���Ӱ����ÿ��·���ĺ�ɫ�ڵ����
						break;	//����дҲ���Բ�д
					}
				}
				else
				{
					//��ʱuncle�����壩�ڵ������ǵ����
					node* uncle = grandfather->m_left;
					//��һ�������������� ��Ϊ ��
					if (uncle != nullptr && uncle->m_c == Colour::RED)
					{
						grandfather->m_c = Colour::RED;
						parent->m_c = uncle->m_c = Colour::BLACK;

						cur = grandfather;			//�������ϸ�����ɫ
						parent = cur->m_parent;
					}
					//�ڶ� ��������������岻���� �� ���������Ϊ ��
					else
					{
						//˫�� -> ����
						if (parent->m_left == cur)	//�ж�·���Ƿ������ߣ���������߾���Ҫ��������������
						{						//������ɺ󣬽�parentָ����curָ���ָ����ģ���Ϊcur��parent����Դ����ˣ���Ȼ����ִ���
							RotateR(parent);
							std::swap(parent, cur);
						}

						//�����п����ǵ������������ת������
						RotateL(grandfather);
						grandfather->m_c = Colour::RED;
						parent->m_c = Colour::BLACK;

						//��Ϊ������������ ��ɫ���Ǻ�ɫ��֮�󶼲���Ӱ����ÿ��·���ĺ�ɫ�ڵ����
						break;	//����дҲ���Բ�д
					}
				}
			}
		}
		m_root->m_c = Colour::BLACK;	//ʼ����ͷ�ڵ����ɫΪ��
		return true;
	}

	void _Inorder(node*& root)
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

	bool IsValidRBTree()
	{
		node* pRoot = m_root;
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
		{
			return true;
		}
		// �����ڵ��Ƿ��������
		if (Colour::BLACK != pRoot->m_c)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		node* pCur = pRoot;
		while (pCur!=nullptr)
		{
			if (Colour::BLACK == pCur->m_c)
			{
				blackCount++;
			}
			pCur = pCur->m_left;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(node* pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�nullptr֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (Colour::BLACK == pRoot->m_c)
		{
			k++;
		}
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		node* pParent = pRoot->m_parent;
		if (pParent && Colour::RED == pParent->m_c && Colour::RED == pRoot->m_c)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->m_left, k, blackCount) &&
			_IsValidRBTree(pRoot->m_right, k, blackCount);
	}
  //����keyֵ�������Ƿ����
	node* find(const K&kv) 
	{
		if (m_root == nullptr)
		{
			return nullptr;
		}
		node* cur = m_root;
		while (cur != nullptr)
		{
			if (cur->m_kv.first > kv)
			{
				cur = cur->m_left;
			}
			else if (cur->m_kv.first < kv)
			{
				cur = cur->m_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

private:
	node* m_root;	//�����
};
