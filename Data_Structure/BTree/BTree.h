#pragma once
#include <iostream>

namespace ZJ
{
	template<class K, class V, size_t M>
	class BTreeNode
	{
	public:
		// ���ӵ������عؼ��ֵ�������һ��
		/*		std::pair<K, V>  _kvs[M - 1];
		BTreeNode<K, V, M>* _subs[M];//��ǰ��ĺ����б�
		*/
		//�������
		std::pair<K, V>  _kvs[M];//�ؼ���
		BTreeNode<K, V, M>* _subs[M + 1];//��ǰ��ĺ����б�
		BTreeNode<K, V, M>* _parent;//����
		//��¼��ǰ�ڵ�洢�˶��ٸ�ֵ
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
				while (i < cur->_kvSize)  //���M�ϴ󣬻��ɶ��ֲ��Ҹ���
				{
					if (cur->_kvs[i].first < key)//����ȵ�ǰλ�õ�key��������
					{
						++i;
					}
					else if (cur->_kvs[i].first > key)//����ȵ�ǰλ��С����������ȥ��
					{
						break;
					}
					else //�ҵ���
					{
						return std::make_pair(cur, i);
					}
				}
				parent = cur;
				cur = cur->_subs[i];
			}

			//û���ҵ�
			return std::make_pair(parent, -1);
		}
	private:
		// ��cur�������һ��kv��sub
		void _Insert(Node* cur, const std::pair<K, V>& kv, Node* sub)
		{
			//��kv�ҵ����ʵ�λ�ò����ȥ
			int i = cur->_kvSize - 1;
			//����ֱ�Ӳ��������˼��
			while (i >= 0)
			{
				if (cur->_kvs[i].first < kv.first)
				{
					break;
				}
				else
				{
					//kv[i]����Ų����kv[i]���Һ���ҲŲ��
					cur->_kvs[i + 1] = cur->_kvs[i];
					cur->_subs[i + 2] = cur->_subs[i + 1];
					--i;
				}
			}
			cur->_kvs[i + 1] = kv;
			cur->_subs[i + 2] = sub;
			cur->_kvSize++;

			if (sub != nullptr) //���¸�ָ��  
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
			if (ret.second >= 0) //�������ظ���
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
					// ��kv���뵽cur��ָ��Ľڵ���
					_Insert(cur, newkv, sub);
					if (cur->_kvSize < M)
					{
						return true;
					}
					else //���ˣ���Ҫ����
					{
						Node* newnode = new Node; //���ѳ�һ���ֵܽ��

						//�ҵ�cur�ڵ���м�λ��,�����Ұ�������ֵܽ��
						int mid = M >> 1;
						int i = mid + 1;
						int j = 0;
						for (; i < M; ++i, ++j)
						{
							newnode->_kvs[j] = cur->_kvs[i]; 
							cur->_kvs[i] = std::pair<K, V>();
							newnode->_subs[j] = cur->_subs[i]; //��������
							cur->_subs[i] = nullptr;
							if (newnode->_subs[j] != nullptr)
							{
								newnode->_subs[j]->_parent = newnode;
							}
							++newnode->_kvSize;
						}// for end
						//���������Һ���,�����¸���
						newnode->_subs[j] = cur->_subs[i];
						if (newnode->_subs[j] != nullptr)
						{
							newnode->_subs[j]->_parent = newnode;
						}
						newkv = cur->_kvs[mid]; //���ѳ����ĸ�
						cur->_kvs[mid] = std::pair<K, V>();
						cur->_kvSize -= (newnode->_kvSize + 1);

						/*
						1.���û�и��ף�˵��cur���Ǹ�����ô���Ǿͷ��Ѳ����µĸ�
						2.����и��ף���ô��Ҫ��cur�ĸ��׵��в���һ���ؼ��ֺͺ���
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
							//������ȥ����newkv��newnode��ת���ɵ����߼�
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
