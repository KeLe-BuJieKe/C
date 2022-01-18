#pragma once
#include<iostream>
#include<stack>
using namespace std;

//�ڵ����ɫ
enum class Color
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
	Color m_col;	//�ڵ���ɫ


	RBTreeNode(const pair<K, V>& kv)
		: m_left(nullptr), m_right(nullptr), m_parent(nullptr)
		, m_kv(kv),m_col(Color::RED)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	RBTree() :m_root(nullptr)
	{}
	RBTree(const RBTree<K, V>& obj)
	{
		m_root = copy(obj.m_root, nullptr);
	}

	RBTree<K, V>& operator=(const RBTree<K, V>& obj)
	{
		if (this != &obj)
		{
			RBTree<K, V>temp = obj;	//���ÿ�������
			std::swap(temp.m_root, this->m_root);
		}
		return *this;
	}

	Node* copy(Node* root, Node* parent) //�ݹ����������������
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* copyNode = new Node(root->m_kv);
		copyNode->m_parent = parent;
		copyNode->m_left = copy(root->m_left, copyNode);
		copyNode->m_right = copy(root->m_right, copyNode);
		return copyNode;
	}

	~RBTree() //���ú������ͷŽ��
	{
		if (m_root == nullptr)
		{
			return;
		}
		Node* cur = m_root;
		Node* prev = nullptr;
		stack<Node*>s;
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
	void RotateL(Node* parent)	//����
	{
		Node* subR = parent->m_right;	//��������ҽ��
		Node* subRL = subR->m_left;		//��������ҽ�������

		parent->m_right = subRL;		//�����Ƚ����ǵ�parent����ָ��subRL
		if (subRL != nullptr)			//�ٽ�subRL�ĸ���ָ��parent��㣬������Ҫ�ж�һ���Ƿ��ǿ�ָ�룬���subRL�ǿ�ָ��Ļ���
										//��ô�����������������
		{
			subRL->m_parent = parent;
		}

		Node* curParent = parent->m_parent;	//��һ�����洢parent�ĸ���
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



	void RotateR(Node* parent)	//����
	{
		Node* subL = parent->m_left;
		Node* subLR = subL->m_right;

		parent->m_left = subLR;
		if (subLR != nullptr)
		{
			subLR->m_parent = parent;
		}

		Node* curParent = parent->m_parent;
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


	//bool insert(const pair<K, V>& kv)
	//{
	//	if (m_root == nullptr)
	//	{
	//		m_root = new Node(kv);
	//		m_root->m_col = Color::BLACK;	//���ڵ����ɫ����Ϊ��
	//		return true;
	//	}
	//	else
	//	{
	//		Node* parent = nullptr;	
	//		Node* cur = m_root;
	//		while (cur!=nullptr)
	//		{
	//			if (cur->m_kv.first < kv.first)
	//			{
	//				parent = cur;
	//				cur = cur->m_right;
	//			}
	//			else if (cur->m_kv.first > kv.first)
	//			{
	//				parent = cur;
	//				cur = cur->m_left;
	//			}
	//			else
	//			{
	//				return false;
	//			}
	//		}

	//		cur = new Node(kv);	//Ĭ�Ϲ��캯����ɫ��ʼ��ΪRED��
	//		if (parent->m_kv.first > kv.first)  //�ж��²���Ľڵ���Ҫ���뵽���ǵ���߻����ұߣ����ø��ڵ��ָ����������
	//		{
	//			parent->m_left = cur;
	//			cur->m_parent = parent;
	//		}
	//		else
	//		{
	//			parent->m_right = cur;
	//			cur->m_parent = parent;
	//		}


	//		while (parent != nullptr && parent->m_col == Color::RED)	//��Ϊ���ǲ������ɫ�Ǻ�ɫ�������ǵĸ��׽ڵ����ɫҲΪ��ʱ��Ҫһֱ���ϵ�����ɫ
	//		{
	//			//�������˻����ɻ���������游�ڵ�Ϊʲô���ж���Ϊ��ָ����������������ǿ�ָ�룬��������ǲ��ǻ���ɿ�ָ����ʱ����أ�
	//			//��ʵ��Ȼ��������ǵĽڵ��в���ǰֻ��ͷ�ڵ�һ������ô���Ͳ�����뵽���ѭ������
	//			//��Ϊ���ڵ����ɫΪ ��
	//			//�����ʱ�����������������ڵ㣬�ڶ����ڵ㲻�����ڸ��ڵ����߻����ұߡ�
	//			//��ʱ��ô���Ǽ�������һ���ڵ��ڸ��������
	//			//��ô�������Ҫ�����Ԫ���ǲ��뵽�������ұߣ���ô��ʱ���Ǻ�����ͬ������������������ѭ������
	//			//������뵽�ڶ����ڵ�����棬��ô��ʱ��Ȼparent����ɫΪ�գ��������ǵ� �游�ڵ�(grandfather)����Ϊ��
	//			//���������������ﲻ��Ҫ�ж����Ƿ�Ϊ��ָ����������������ɿ�ָ���������
	//			Node* grandfather=parent->m_parent;	//�游

	//			//Ҫ���ʲô��ɫ�ؼ�������uncle�����������ҵ������λ����������
	//			if (grandfather->m_left == parent)  //�ж�
	//			{
	//				Node* uncle = grandfather->m_right;
	//				//��һ�������������� ��Ϊ ��
	//				if (uncle != nullptr && uncle->m_col == Color::RED)
	//				{
	//					grandfather->m_col = Color::RED;
	//					parent->m_col = uncle->m_col = Color::BLACK;

	//					//Ϊʲô��cur=grandfather��������parent�أ�
	//					//������Ϊ��ʱ���������parent����ɫ��ɺ�ɫ����ɫʱ������ڵ�Ͳ���Ҫ�ж��ˡ�
	//					//�����parent��ʼ���Ͳ��ܼ������ϸ����ˡ���ֱ����ֹѭ����
	//					//���Ǵ����Ǹոձ�ɺ�ɫ��grandfather�ڵ㿪ʼ���п��ܴ�ʱgrandfather�ڵ��Ϊ��
	//					//�����ϲ�ÿ��·���ĺ�ɫ�ڵ���Ŀ��ͬ��������
	//					cur = grandfather;			//�������ϸ�����ɫ
	//					parent = cur->m_parent;
	//				}
	//				//�ڶ� ��������������岻���� �� ���������Ϊ ��
	//				else
	//				{
	//					//˫�� -> ����
	//					if (parent->m_right == cur)	//�ж�·���Ƿ������ߣ���������߾���Ҫ��������������
	//					{						//������ɺ󣬽�parentָ����curָ���ָ����ģ���Ϊcur��parent����Դ����ˣ���Ȼ����ִ���
	//						RotateL(parent);
	//						std::swap(parent, cur);
	//					}

	//					//�����п����ǵ������������ת������
	//					RotateR(grandfather);
	//					grandfather->m_col = Color::RED;
	//					parent->m_col = Color::BLACK;

	//					//��Ϊ������������ ��ɫ���Ǻ�ɫ��֮�󶼲���Ӱ����ÿ��·���ĺ�ɫ�ڵ����
	//					break;	//����дҲ���Բ�д
	//				}
	//			}
	//			else
	//			{
	//				//��ʱuncle�����壩�ڵ������ǵ����
	//				Node* uncle = grandfather->m_left;
	//				//��һ�������������� ��Ϊ ��
	//				if (uncle != nullptr && uncle->m_col == Color::RED)
	//				{
	//					grandfather->m_col = Color::RED;
	//					parent->m_col = uncle->m_col = Color::BLACK;

	//					cur = grandfather;			//�������ϸ�����ɫ
	//					parent = cur->m_parent;
	//				}
	//				//�ڶ� ��������������岻���� �� ���������Ϊ ��
	//				else
	//				{
	//					//˫�� -> ����
	//					if (parent->m_left == cur)	//�ж�·���Ƿ������ߣ���������߾���Ҫ��������������
	//					{						//������ɺ󣬽�parentָ����curָ���ָ����ģ���Ϊcur��parent����Դ����ˣ���Ȼ����ִ���
	//						RotateR(parent);
	//						std::swap(parent, cur);
	//					}

	//					//�����п����ǵ������������ת������
	//					RotateL(grandfather);
	//					grandfather->m_col = Color::RED;
	//					parent->m_col = Color::BLACK;

	//					//��Ϊ������������ ��ɫ���Ǻ�ɫ��֮�󶼲���Ӱ����ÿ��·���ĺ�ɫ�ڵ����
	//					break;	//����дҲ���Բ�д
	//				}
	//			}
	//		}
	//	}
	//	m_root->m_col = Color::BLACK;	//ʼ����ͷ�ڵ����ɫΪ��
	//	return true;
	//}

	//���뿴����
	std::pair<Node*, bool> insert(const std::pair<K, V>& kv)
	{
		if (m_root == nullptr)
		{
			m_root = new Node(kv);
			m_root->m_col = Color::BLACK;
			return std::make_pair(m_root, true);
		}

		Node* parent = nullptr;
		Node* cur = m_root;
		while (cur != nullptr)
		{
			if (cur->m_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->m_left;
			}
			else if (cur->m_kv.second < kv.first)
			{
				parent = cur;
				cur = cur->m_right;
			}
			else
			{
				return std::make_pair(cur, false);
			}
		}

		Node* newNode = new Node(kv);
		if (parent->m_kv.first > kv.first)
		{
			parent->m_left = newNode;
			newNode->m_parent = parent;
		}
		else
		{
			parent->m_right = newNode;
			newNode->m_parent = parent;
		}
		cur = newNode;

		while (parent != nullptr && parent->m_col == Color::RED)
		{
			Node* grandFather = parent->m_parent;
			if (parent == grandFather->m_left) //���һ�����������Ϊ��
			{
				Node* uncle = grandFather->m_right;
				if (uncle != nullptr && uncle->m_col == Color::RED)
				{
					uncle->m_col = parent->m_col = Color::BLACK;
					grandFather->m_col = Color::RED;
					cur = grandFather;
					parent = cur->m_parent;
				}
				else
				{
					if (cur == parent->m_left) //�������������ڻ��߲���
					{
						RotateR(grandFather);
						grandFather->m_col = Color::RED;
						parent->m_col = Color::BLACK;
					}
					else
					{
						RotateL(parent);
						RotateR(grandFather);
						cur->m_col = Color::BLACK;
						grandFather->m_col = Color::RED;
					}
					break;
				}

			}
			else
			{
				Node* uncle = grandFather->m_left;
				if (uncle != nullptr && uncle->m_col == Color::RED)
				{
					uncle->m_col = parent->m_col = Color::BLACK;
					grandFather->m_col = Color::RED;
					cur = grandFather;
					parent = cur->m_parent;
				}
				else
				{
					if (cur == parent->m_left)
					{
						RotateR(parent);
						RotateL(grandFather);
						grandFather->m_col = Color::RED;
						cur->m_col = Color::BLACK;
					}
					else
					{
						RotateL(grandFather);
						grandFather->m_col = Color::RED;
						parent->m_col = Color::BLACK;
					}

					break;
				}
			}
		}
		m_root->m_col = Color::BLACK;
		return std::make_pair(newNode, true);
	}

	//ɾ������ ɾ�����ֵ�
	bool erase(const K& key)
	{
		//���ڱ���������
		Node* parent = nullptr;
		Node* cur = m_root;
		//���ڱ��ʵ�ʵĴ�ɾ����㼰�丸���
		Node* delParentPos = nullptr;
		Node* delPos = nullptr;
		while (cur != nullptr)
		{
			if (key < cur->m_kv.first) //����keyֵС�ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->m_left;
			}
			else if (key > cur->m_kv.first) //����keyֵ���ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->m_right;
			}
			else //�ҵ��˴�ɾ�����
			{
				if (cur->m_left == nullptr) //��ɾ������������Ϊ��
				{
					if (cur == m_root) //��ɾ������Ǹ����
					{
						m_root = m_root->m_right; //�ø�������������Ϊ�µĸ����
						if (m_root)
						{
							m_root->m_parent = nullptr;
							m_root->m_col = Color::BLACK; //�����Ϊ��ɫ
						}
						delete cur; //ɾ��ԭ�����
						return true;
					}
					else
					{
						delParentPos = parent; //���ʵ��ɾ�����ĸ����
						delPos = cur; //���ʵ��ɾ���Ľ��
					}
					break; //���к�����ĵ����Լ�����ʵ��ɾ��
				}
				else if (cur->m_right == nullptr) //��ɾ������������Ϊ��
				{
					if (cur == m_root) //��ɾ������Ǹ����
					{
						m_root = m_root->m_left; //�ø�������������Ϊ�µĸ����
						if (m_root)
						{
							m_root->m_parent = nullptr;
							m_root->m_col = Color::BLACK; //�����Ϊ��ɫ
						}
						delete cur; //ɾ��ԭ�����
						return true;
					}
					else
					{
						delParentPos = parent; //���ʵ��ɾ�����ĸ����
						delPos = cur; //���ʵ��ɾ���Ľ��
					}
					break; //���к�����ĵ����Լ�����ʵ��ɾ��
				}
				else //��ɾ������������������Ϊ��
				{
					//�滻��ɾ��
					//Ѱ�Ҵ�ɾ���������������keyֵ��С�Ľ����Ϊʵ��ɾ�����
					Node* minParent = cur;
					Node* minRight = cur->m_right;
					while (minRight->m_left != nullptr)
					{
						minParent = minRight;
						minRight = minRight->m_left;
					}
					cur->m_kv.first = minRight->m_kv.first; //����ɾ������key��ΪminRight��key
					cur->m_kv.second = minRight->m_kv.second; //����ɾ������value��ΪminRight��value
					delParentPos = minParent; //���ʵ��ɾ�����ĸ����
					delPos = minRight; //���ʵ��ɾ���Ľ��
					break; //���к�����ĵ����Լ�����ʵ��ɾ��
				}
			}
		}

		if (delPos == nullptr) //delPosû�б��޸Ĺ���˵��û���ҵ���ɾ�����
		{
			return false;
		}

		//��¼��ɾ����㼰�丸��㣨���ں���ʵ��ɾ����
		Node* del = delPos;
		Node* delP = delParentPos;

		//��������� Ϊ��ɾ����ɫ�������ָ������������
		if (delPos->m_col == Color::BLACK) //ɾ�����Ǻ�ɫ���
		{
			if (delPos->m_left != nullptr) //��ɾ�������һ����ɫ�����ӣ��������Ǻ�ɫ��
			{
				delPos->m_left->m_col = Color::BLACK; //�������ɫ�����ӱ�ڼ���
			}
			else if (delPos->m_right != nullptr) //��ɾ�������һ����ɫ���Һ��ӣ��������Ǻ�ɫ��
			{
				delPos->m_right->m_col = Color::BLACK; //�������ɫ���Һ��ӱ�ڼ���
			}
			else //��ɾ���������Ҿ�Ϊ��
			{
				while (delPos != m_root) //����һֱ�����������
				{
					if (delPos == delParentPos->m_left) //��ɾ��������丸��������
					{
						Node* brother = delParentPos->m_right; //�ֵܽ�����丸�����Һ���
						//���һ��brotherΪ��ɫ
						if (brother->m_col == Color::RED)
						{
							delParentPos->m_col = Color::RED;
							brother->m_col = Color::BLACK;
							RotateL(delParentPos);
							//��Ҫ��������
							brother = delParentPos->m_right; //����brother�������ڱ�ѭ����ִ����������Ĵ���������
						}

						//�������brotherΪ��ɫ���������Һ��Ӷ��Ǻ�ɫ������ һ��Ϊ��һ��Ϊ��ʱ
						//�������߶�ΪNIL���������߶�Ϊ��ʱ
						if (((brother->m_left == nullptr) || (brother->m_left->m_col == Color::BLACK))
							&& ((brother->m_right == nullptr) || (brother->m_right->m_col == Color::BLACK)))
						{
							brother->m_col = Color::RED;
							if (delParentPos->m_col == Color::RED)
							{
								delParentPos->m_col = Color::BLACK;
								break;
							}
							else
							{
								//��Ҫ��������
								delPos = delParentPos;
								delParentPos = delPos->m_parent;
							}
						}
						else
						{
							//�������brotherΪ��ɫ�����������Ǻ�ɫ��㣬�Һ����Ǻ�ɫ����Ϊ��
							if ((brother->m_right == nullptr) || (brother->m_right->m_col == Color::BLACK))
							{
								brother->m_left->m_col = Color::BLACK;
								brother->m_col = Color::RED;
								RotateR(brother);
								//��Ҫ��������
								brother = delParentPos->m_right; //����brother������ִ����������ĵĴ���������
							}

							//����ģ�brotherΪ��ɫ�������Һ����Ǻ�ɫ���
							brother->m_col = delParentPos->m_col;
							delParentPos->m_col = Color::BLACK;
							brother->m_right->m_col = Color::BLACK;
							RotateL(delParentPos);
							break; //�����ִ����Ϻ����һ������
						}
					}
					else //delPos == delParentPos->m_right //��ɾ��������丸�����Һ���
					{
						Node* brother = delParentPos->m_left; //�ֵܽ�����丸��������
						//���һ��brotherΪ��ɫ
						if (brother->m_col == Color::RED) //brotherΪ��ɫ
						{
							delParentPos->m_col = Color::RED;
							brother->m_col = Color::BLACK;
							RotateR(delParentPos);
							//��Ҫ��������
							brother = delParentPos->m_left; //����brother�������ڱ�ѭ����ִ����������Ĵ���������
						}

						//�������brotherΪ��ɫ���������Һ��Ӷ��Ǻ�ɫ����Ϊ��
						if (((brother->m_left == nullptr) || (brother->m_left->m_col == Color::BLACK))
							&& ((brother->m_right == nullptr) || (brother->m_right->m_col == Color::BLACK)))

						{
							brother->m_col = Color::RED;
							if (delParentPos->m_col == Color::RED)
							{
								delParentPos->m_col = Color::BLACK;
								break;
							}
							else
							{
								//��Ҫ��������
								delPos = delParentPos;
								delParentPos = delPos->m_parent;
							}
						}
						else
						{
							//�������brotherΪ��ɫ�������Һ����Ǻ�ɫ��㣬�����Ǻ�ɫ����Ϊ��
							if ((brother->m_left == nullptr) || (brother->m_left->m_col == Color::BLACK))
							{
								brother->m_right->m_col = Color::BLACK;
								brother->m_col = Color::RED;
								RotateL(brother);
								//��Ҫ��������
								brother = delParentPos->m_left; //����brother������ִ����������ĵĴ���������
							}

							//����ģ�brotherΪ��ɫ�����������Ǻ�ɫ���
							brother->m_col = delParentPos->m_col;
							delParentPos->m_col = Color::BLACK;
							brother->m_left->m_col = Color::BLACK;
							RotateR(delParentPos);
							break; //�����ִ����Ϻ����һ������
						}
					}
				}
			}
		}

		//����ɾ�����ĺ�����ɾ����㸸�׵����ӹ�ϵ
		if (del->m_left == nullptr) //ʵ��ɾ������������Ϊ��
		{
			if (del == delP->m_left) //ʵ��ɾ��������丸��������
			{
				delP->m_left = del->m_right;
				if (del->m_right != nullptr)
				{
					del->m_right->m_parent = delP;
				}
			}
			else //ʵ��ɾ��������丸�����Һ���
			{
				delP->m_right = del->m_right;
				if (del->m_right != nullptr)
				{
					del->m_right->m_parent = delP;
				}
			}
		}
		else //ʵ��ɾ������������Ϊ��
		{
			if (del == delP->m_left) //ʵ��ɾ��������丸��������
			{
				delP->m_left = del->m_left;
				if (del->m_left != nullptr)
				{
					del->m_left->m_parent = delP;
				}
			}
			else //ʵ��ɾ��������丸�����Һ���
			{
				delP->m_right = del->m_left;
				if (del->m_left != nullptr)
				{
					del->m_left->m_parent = delP;
				}
			}
		}

		//��󽫽��ɾ��
		delete del;
		return true;
	}

	void _Inorder(Node*& root)
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

	//�ж��Ƿ�Ϊ�����
	bool IsRBTree()
	{
		if (m_root == nullptr) //�����Ǻ����
		{
			return true;
		}
		if (m_root->m_col == Color::RED)
		{
			cout << "error�������Ϊ��ɫ" << endl;
			return false;
		}

		//������·����Ϊ��ɫ�����Ŀ�Ĳο�ֵ
		Node* cur = m_root;
		int BlackCount = 0;
		while (cur)
		{
			if (cur->m_col == Color::BLACK)
				BlackCount++;
			cur = cur->m_left;
		}

		int count = 0;
		return _IsRBTree(m_root, count, BlackCount);
	}

	//�ж��Ƿ�Ϊ��������Ӻ���
	bool _IsRBTree(Node* root, int count, int BlackCount)
	{
		if (root == nullptr) //��·���Ѿ�������
		{
			if (count != BlackCount)
			{
				cout << "error����ɫ������Ŀ�����" << endl;
				return false;
			}
			return true;
		}

		if (root->m_col == Color::RED && root->m_parent->m_col == Color::RED)
		{
			cout << "error�����������ĺ�ɫ���" << endl;
			return false;
		}
		if (root->m_col == Color::BLACK)
		{
			count++;
		}
		return _IsRBTree(root->m_left, count, BlackCount) && _IsRBTree(root->m_right, count, BlackCount);
	}

	Node* find(const K&kv) 
	{
		if (m_root == nullptr)
		{
			return nullptr;
		}
		Node* cur = m_root;
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
	Node* m_root;	//�����
};