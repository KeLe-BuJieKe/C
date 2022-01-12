#pragma once
#include<iostream>
using namespace std;

//节点的颜色
enum class Color
{
	RED,
	BLACK
};

//K-V模型
template<class K,class V>
struct RBTreeNode	//三叉链
{
	RBTreeNode<K,V>* m_left;	//左节点
	RBTreeNode<K,V>* m_right;   //右节点
	RBTreeNode<K,V>* m_parent;  //节点的父结点(红黑树需要 旋转 ，为了实现简单给出的该字段)

	pair<K, V>m_kv; //节点数据
	Color m_col;	//节点颜色


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
	//传进来的是不平衡的结点的指针
	void RotateL(Node* parent)	//左旋
	{
		Node* subR = parent->m_right;	//出问题的右结点
		Node* subRL = subR->m_left;		//出问题的右结点的左结点

		parent->m_right = subRL;		//首先先将我们的parent的右指向subRL
		if (subRL != nullptr)			//再将subRL的父亲指向parent结点，但这样要判断一下是否是空指针，如果subRL是空指针的话，
										//那么解引用它会出现问题
		{
			subRL->m_parent = parent;
		}

		Node* curParent = parent->m_parent;	//拿一个结点存储parent的父亲
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
	}



	void RotateR(Node* parent)	//右旋
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


	bool insert(const pair<K, V>& kv)
	{
		if (m_root == nullptr)
		{
			m_root = new Node(kv);
			m_root->m_col = Color::BLACK;	//根节点的颜色必须为黑
			return true;
		}
		else
		{
			Node* parent = nullptr;	
			Node* cur = m_root;
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

			cur = new Node(kv);	//默认构造函数颜色初始化为RED了
			if (parent->m_kv.first > kv.first)  //判断新插入的节点是要插入到我们的左边还是右边，并用父节点的指针连接起来
			{
				parent->m_left = cur;
				cur->m_parent = parent;
			}
			else
			{
				parent->m_right = cur;
				cur->m_parent = parent;
			}


			while (parent != nullptr && parent->m_col == Color::RED)	//因为我们插入的颜色是红色，当我们的父亲节点的颜色也为红时，要一直向上调整颜色
			{
				//可能有人会有疑惑，这里这个祖父节点为什么不判断它为空指针的情况，并且如果是空指针，下面访问是不是会造成空指针访问崩溃呢？
				//其实不然，如果我们的节点中插入前只有头节点一个，那么它就不会进入到这个循环体里
				//因为根节点的颜色为 黑
				//如果此时这个红黑树中有两个节点，第二个节点不管它在根节点的左边还是右边。
				//此时那么我们假设另外一个节点在根结点的左边
				//那么如果我们要插入的元素是插入到根结点的右边，那么此时我们和上面同样的情况，进步来这个循环体里
				//如果插入到第二个节点的下面，那么此时虽然parent的颜色为空，但是我们的 祖父节点(grandfather)并不为空
				//综上所诉所以这里不需要判断它是否为空指针访问情况，不会造成空指针崩溃现象。
				Node* grandfather=parent->m_parent;	//祖父

				//要变成什么颜色关键看叔叔uncle，所以我们找到叔叔的位置在左还是右
				if (grandfather->m_left == parent)  //判断
				{
					Node* uncle = grandfather->m_right;
					//第一种情况：叔叔存在 且为 红
					if (uncle != nullptr && uncle->m_col == Color::RED)
					{
						grandfather->m_col = Color::RED;
						parent->m_col = uncle->m_col = Color::BLACK;

						//为什么让cur=grandfather，而不是parent呢？
						//这是因为此时这种情况，parent的颜色变成黑色，黑色时，这个节点就不需要判断了。
						//如果从parent开始，就不能继续往上更新了。会直接终止循环。
						//而是从我们刚刚变成红色的grandfather节点开始，有可能此时grandfather节点变为红
						//导致上层每条路径的黑色节点数目不同发生错误。
						cur = grandfather;			//继续往上更新颜色
						parent = cur->m_parent;
					}
					//第二 第三种情况：叔叔不存在 或 叔叔存在且为 黑
					else
					{
						//双旋 -> 单旋
						if (parent->m_right == cur)	//判断路径是否是折线，如果是折线就需要先左旋，在右旋
						{						//左旋完成后，将parent指针与cur指针的指向更改，因为cur与parent的相对次序反了，不然会出现错误
							RotateL(parent);
							std::swap(parent, cur);
						}

						//这里有可能是第三种情况左旋转换而来
						RotateR(grandfather);
						grandfather->m_col = Color::RED;
						parent->m_col = Color::BLACK;

						//因为不管你上面是 红色还是黑色，之后都不会影响其每条路径的黑色节点个数
						break;	//可以写也可以不写
					}
				}
				else
				{
					//此时uncle（叔叔）节点在我们的左边
					Node* uncle = grandfather->m_left;
					//第一种情况：叔叔存在 且为 红
					if (uncle != nullptr && uncle->m_col == Color::RED)
					{
						grandfather->m_col = Color::RED;
						parent->m_col = uncle->m_col = Color::BLACK;

						cur = grandfather;			//继续往上更新颜色
						parent = cur->m_parent;
					}
					//第二 第三种情况：叔叔不存在 或 叔叔存在且为 黑
					else
					{
						//双旋 -> 单旋
						if (parent->m_left == cur)	//判断路径是否是折线，如果是折线就需要先右旋，在左旋
						{						//右旋完成后，将parent指针与cur指针的指向更改，因为cur与parent的相对次序反了，不然会出现错误
							RotateR(parent);
							std::swap(parent, cur);
						}

						//这里有可能是第三种情况右旋转换而来
						RotateL(grandfather);
						grandfather->m_col = Color::RED;
						parent->m_col = Color::BLACK;

						//因为不管你上面是 红色还是黑色，之后都不会影响其每条路径的黑色节点个数
						break;	//可以写也可以不写
					}
				}
			}
		}
		m_root->m_col = Color::BLACK;	//始终让头节点的颜色为黑
		return true;
	}

	//删除函数 删除看兄弟
	bool erase(const K& key)
	{
		//用于遍历二叉树
		Node* parent = nullptr;
		Node* cur = m_root;
		//用于标记实际的待删除结点及其父结点
		Node* delParentPos = nullptr;
		Node* delPos = nullptr;
		while (cur != nullptr)
		{
			if (key < cur->m_kv.first) //所给key值小于当前结点的key值
			{
				//往该结点的左子树走
				parent = cur;
				cur = cur->m_left;
			}
			else if (key > cur->m_kv.first) //所给key值大于当前结点的key值
			{
				//往该结点的右子树走
				parent = cur;
				cur = cur->m_right;
			}
			else //找到了待删除结点
			{
				if (cur->m_left == nullptr) //待删除结点的左子树为空
				{
					if (cur == m_root) //待删除结点是根结点
					{
						m_root = m_root->m_right; //让根结点的右子树作为新的根结点
						if (m_root)
						{
							m_root->m_parent = nullptr;
							m_root->m_col = Color::BLACK; //根结点为黑色
						}
						delete cur; //删除原根结点
						return true;
					}
					else
					{
						delParentPos = parent; //标记实际删除结点的父结点
						delPos = cur; //标记实际删除的结点
					}
					break; //进行红黑树的调整以及结点的实际删除
				}
				else if (cur->m_right == nullptr) //待删除结点的右子树为空
				{
					if (cur == m_root) //待删除结点是根结点
					{
						m_root = m_root->m_left; //让根结点的左子树作为新的根结点
						if (m_root)
						{
							m_root->m_parent = nullptr;
							m_root->m_col = Color::BLACK; //根结点为黑色
						}
						delete cur; //删除原根结点
						return true;
					}
					else
					{
						delParentPos = parent; //标记实际删除结点的父结点
						delPos = cur; //标记实际删除的结点
					}
					break; //进行红黑树的调整以及结点的实际删除
				}
				else //待删除结点的左右子树均不为空
				{
					//替换法删除
					//寻找待删除结点右子树当中key值最小的结点作为实际删除结点
					Node* minParent = cur;
					Node* minRight = cur->m_right;
					while (minRight->m_left != nullptr)
					{
						minParent = minRight;
						minRight = minRight->m_left;
					}
					cur->m_kv.first = minRight->m_kv.first; //将待删除结点的key改为minRight的key
					cur->m_kv.second = minRight->m_kv.second; //将待删除结点的value改为minRight的value
					delParentPos = minParent; //标记实际删除结点的父结点
					delPos = minRight; //标记实际删除的结点
					break; //进行红黑树的调整以及结点的实际删除
				}
			}
		}

		if (delPos == nullptr) //delPos没有被修改过，说明没有找到待删除结点
		{
			return false;
		}

		//记录待删除结点及其父结点（用于后续实际删除）
		Node* del = delPos;
		Node* delP = delParentPos;

		//调整红黑树 为了删除黑色结点后来恢复红黑树的性质
		if (delPos->m_col == Color::BLACK) //删除的是黑色结点
		{
			if (delPos->m_left != nullptr) //待删除结点有一个红色的左孩子（不可能是黑色）
			{
				delPos->m_left->m_col = Color::BLACK; //将这个红色的左孩子变黑即可
			}
			else if (delPos->m_right != nullptr) //待删除结点有一个红色的右孩子（不可能是黑色）
			{
				delPos->m_right->m_col = Color::BLACK; //将这个红色的右孩子变黑即可
			}
			else //待删除结点的左右均为空
			{
				while (delPos != m_root) //可能一直调整到根结点
				{
					if (delPos == delParentPos->m_left) //待删除结点是其父结点的左孩子
					{
						Node* brother = delParentPos->m_right; //兄弟结点是其父结点的右孩子
						//情况一：brother为红色
						if (brother->m_col == Color::RED)
						{
							delParentPos->m_col = Color::RED;
							brother->m_col = Color::BLACK;
							RotateL(delParentPos);
							//需要继续处理
							brother = delParentPos->m_right; //更新brother（否则在本循环中执行其他情况的代码会出错）
						}

						//情况二：brother为黑色，且其左右孩子都是黑色结点或者 一边为空一变为黑时
						//甚至两边都为NIL，就是两边都为空时
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
								//需要继续处理
								delPos = delParentPos;
								delParentPos = delPos->m_parent;
							}
						}
						else
						{
							//情况三：brother为黑色，且其左孩子是红色结点，右孩子是黑色结点或为空
							if ((brother->m_right == nullptr) || (brother->m_right->m_col == Color::BLACK))
							{
								brother->m_left->m_col = Color::BLACK;
								brother->m_col = Color::RED;
								RotateR(brother);
								//需要继续处理
								brother = delParentPos->m_right; //更新brother（否则执行下面情况四的代码会出错）
							}

							//情况四：brother为黑色，且其右孩子是红色结点
							brother->m_col = delParentPos->m_col;
							delParentPos->m_col = Color::BLACK;
							brother->m_right->m_col = Color::BLACK;
							RotateL(delParentPos);
							break; //情况四执行完毕后调整一定结束
						}
					}
					else //delPos == delParentPos->m_right //待删除结点是其父结点的右孩子
					{
						Node* brother = delParentPos->m_left; //兄弟结点是其父结点的左孩子
						//情况一：brother为红色
						if (brother->m_col == Color::RED) //brother为红色
						{
							delParentPos->m_col = Color::RED;
							brother->m_col = Color::BLACK;
							RotateR(delParentPos);
							//需要继续处理
							brother = delParentPos->m_left; //更新brother（否则在本循环中执行其他情况的代码会出错）
						}

						//情况二：brother为黑色，且其左右孩子都是黑色结点或为空
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
								//需要继续处理
								delPos = delParentPos;
								delParentPos = delPos->m_parent;
							}
						}
						else
						{
							//情况三：brother为黑色，且其右孩子是红色结点，左孩子是黑色结点或为空
							if ((brother->m_left == nullptr) || (brother->m_left->m_col == Color::BLACK))
							{
								brother->m_right->m_col = Color::BLACK;
								brother->m_col = Color::RED;
								RotateL(brother);
								//需要继续处理
								brother = delParentPos->m_left; //更新brother（否则执行下面情况四的代码会出错）
							}

							//情况四：brother为黑色，且其左孩子是红色结点
							brother->m_col = delParentPos->m_col;
							delParentPos->m_col = Color::BLACK;
							brother->m_left->m_col = Color::BLACK;
							RotateR(delParentPos);
							break; //情况四执行完毕后调整一定结束
						}
					}
				}
			}
		}

		//链接删除结点的孩子与删除结点父亲的链接关系
		if (del->m_left == nullptr) //实际删除结点的左子树为空
		{
			if (del == delP->m_left) //实际删除结点是其父结点的左孩子
			{
				delP->m_left = del->m_right;
				if (del->m_right != nullptr)
				{
					del->m_right->m_parent = delP;
				}
			}
			else //实际删除结点是其父结点的右孩子
			{
				delP->m_right = del->m_right;
				if (del->m_right != nullptr)
				{
					del->m_right->m_parent = delP;
				}
			}
		}
		else //实际删除结点的右子树为空
		{
			if (del == delP->m_left) //实际删除结点是其父结点的左孩子
			{
				delP->m_left = del->m_left;
				if (del->m_left != nullptr)
				{
					del->m_left->m_parent = delP;
				}
			}
			else //实际删除结点是其父结点的右孩子
			{
				delP->m_right = del->m_left;
				if (del->m_left != nullptr)
				{
					del->m_left->m_parent = delP;
				}
			}
		}

		//最后将结点删除
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

	bool IsValidRBTree()
	{
		Node* pRoot = m_root;
		// 空树也是红黑树
		if (nullptr == pRoot)
		{
			return true;
		}
		// 检测根节点是否满足情况
		if (Color::BLACK != pRoot->m_col)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur!=nullptr)
		{
			if (Color::BLACK == pCur->m_col)
			{
				blackCount++;
			}
			pCur = pCur->m_left;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
	{
		//走到nullptr之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}
		// 统计黑色节点的个数
		if (Color::BLACK == pRoot->m_col)
		{
			k++;
		}
		// 检测当前节点与其双亲是否都为红色
		Node* pParent = pRoot->m_parent;
		if (pParent && Color::RED == pParent->m_col && Color::RED == pRoot->m_col)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->m_left, k, blackCount) &&
			_IsValidRBTree(pRoot->m_right, k, blackCount);
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
	Node* m_root;	//根结点
};
