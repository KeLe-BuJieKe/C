#pragma once
#include <iostream>

namespace ZJ
{
	template<class K, class V, size_t M>
	class BTreeNode
	{
	public:
		// 孩子的数量必关键字的数量多一个
		/*		std::pair<K, V>  _kvs[M - 1];
		BTreeNode<K, V, M>* _subs[M];//当前层的孩子列表
		*/
		//方便分裂
		std::pair<K, V>  _kvs[M];//关键字
		BTreeNode<K, V, M>* _subs[M + 1];//当前层的孩子列表
		BTreeNode<K, V, M>* _parent;//父亲
		//记录当前节点存储了多少个值
		size_t _kvSize;

		BTreeNode() :_parent(nullptr), _kvSize(0)
		{
			for (size_t i = 0; i < M + 1; ++i)
			{
				_subs[i] = nullptr;
			}
		}
	};

	template<class K, class V, size_t M>
	class BTree
	{
		typedef BTreeNode<K, V, M> Node;
	private:
		Node* _root;
	public:
		BTree():_root(nullptr)
		{}

		std::pair<Node*, int> Find(const K& key)  const 
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				int i = 0; 
				while (i < cur->_kvSize)  //如果M较大，换成二分查找更快
				{
					if (cur->_kvs[i].first < key)//如果比当前位置的key大，往右走
					{
						++i;
					}
					else if (cur->_kvs[i].first > key)//如果比当前位置小，则往左孩子去找
					{
						break;
					}
					else //找到了
					{
						return std::make_pair(cur, i);
					}
				}
				parent = cur;
				cur = cur->_subs[i];
			}

			//没有找到
			return std::make_pair(parent, -1);
		}
	private:
		// 往cur里面插入一个kv和sub
		void _Insert(Node* cur, const std::pair<K, V>& kv, Node* sub)
		{
			//将kv找到合适的位置插入进去
			int i = cur->_kvSize - 1;
			//根据直接插入排序的思想
			while (i >= 0)
			{
				if (cur->_kvs[i].first < kv.first)
				{
					break;
				}
				else
				{
					//kv[i]往后挪动，kv[i]的右孩子也挪动
					cur->_kvs[i + 1] = cur->_kvs[i];
					cur->_subs[i + 2] = cur->_subs[i + 1];
					--i;
				}
			}
			cur->_kvs[i + 1] = kv;
			cur->_subs[i + 2] = sub;
			cur->_kvSize++;

			if (sub != nullptr) //更新父指针  
			{
				sub->_parent = cur;
			}
		}
	public:
		bool Insert(const std::pair<K, V>& kv)
		{
			if (this->_root == nullptr)
			{
				this->_root = new Node;
				this->_root->_kvs[0] = kv;
				++this->_root->_kvSize;
				return true;
			}


			std::pair<Node*, int> ret = this->Find(kv.first);
			if (ret.second >= 0) //不能有重复的
			{
				return false;
			}
			else
			{
				Node* cur = ret.first;
				std::pair<K, V> newkv = kv;
				Node* sub = nullptr;
				while (true)
				{
					// 将kv插入到cur所指向的节点中
					_Insert(cur, newkv, sub);
					if (cur->_kvSize < M)
					{
						return true;
					}
					else //满了，需要分裂
					{
						Node* newnode = new Node; //分裂出一个兄弟结点

						//找到cur节点的中间位置,拷贝右半区间给兄弟结点
						int mid = M >> 1;
						int i = mid + 1;
						int j = 0;
						for (; i < M; ++i, ++j)
						{
							newnode->_kvs[j] = cur->_kvs[i]; 
							cur->_kvs[i] = std::pair<K, V>();
							newnode->_subs[j] = cur->_subs[i]; //拷贝左孩子
							cur->_subs[i] = nullptr;
							if (newnode->_subs[j] != nullptr)
							{
								newnode->_subs[j]->_parent = newnode;
							}
							++newnode->_kvSize;
						}// for end
						//拷贝最后的右孩子,并更新父亲
						newnode->_subs[j] = cur->_subs[i];
						if (newnode->_subs[j] != nullptr)
						{
							newnode->_subs[j]->_parent = newnode;
						}
						newkv = cur->_kvs[mid]; //分裂出来的根
						cur->_kvs[mid] = std::pair<K, V>();
						cur->_kvSize -= (newnode->_kvSize + 1);

						/*
						1.如果没有父亲，说明cur就是跟，那么我们就分裂产生新的根
						2.如果有父亲，那么就要向cur的父亲当中插入一个关键字和孩子
						*/
						if (cur->_parent == nullptr)
						{
							this->_root = new Node;
							this->_root->_kvs[0] = newkv;
							this->_root->_subs[0] = cur;
							this->_root->_subs[1] = newnode;
							cur->_parent = _root;
							newnode->_parent = this->_root;
							this->_root->_kvSize++;
							return true;
						}
						else
						{
							//往父亲去插入newkv和newnode，转换成迭代逻辑
							sub = newnode;
							cur = cur->_parent;
						}
					}// if else end
				}// while end
			} // if else end
			return false;
		}//func end

		~BTree()
		{}
	};
}
