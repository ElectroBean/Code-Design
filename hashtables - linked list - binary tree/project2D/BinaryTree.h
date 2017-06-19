#pragma once

class BinaryTree
{
	struct Node;
public:
	BinaryTree();
	~BinaryTree();

	bool GetIsEmpty() const;
	void Insert(Node* root, int a_nValue);
	bool Remove(int a_nValue);
	void Add(int value);
	void Delete(int value);
	void FindNode(int value, Node* node, Node* aParent);

	bool RemoveHelper(Node * parent, Node * current, int value);

public:
	struct Node
	{
		Node(int nValue) :
			m_nData(nValue),
			m_pLeft(nullptr),
			m_pRight(nullptr)
		{}

		Node* m_pLeft;
		Node* m_pRight;
		int m_nData;
	};

	// the root node of the tree
	Node* m_pRoot;
};