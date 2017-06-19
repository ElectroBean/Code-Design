#include "BinaryTree.h"
#include "TreeNode.h"


BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}


BinaryTree::~BinaryTree()
{
}

bool BinaryTree::GetIsEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return true;
	}
	else return false;
}

void BinaryTree::Insert(Node* root, int a_nValue)
{
	if (root->m_nData > a_nValue)
	{
		if (!root->m_pLeft)
		{
			root->m_pLeft = new Node(a_nValue);
		}
		else
		{
			Insert(root->m_pLeft, a_nValue);
		}
	}
	else
	{
		if (!root->m_pRight)
		{
			root->m_pRight = new Node(a_nValue);
		}
		else
		{
			Insert(root->m_pRight, a_nValue);
		}
	}
}

bool BinaryTree::Remove(int a_nValue)
{
	return this->RemoveHelper(NULL, this->m_pRoot, a_nValue);
}

void BinaryTree::Add(int value)
{
	if (m_pRoot)
	{
		this->Insert(m_pRoot, value);
	}
	else
	{
		m_pRoot = new Node(value);
	}
}

bool BinaryTree::RemoveHelper(Node* parent, Node* current, int value)
{
	if (!current) return false;
	if (current->m_nData == value) {
		if (current->m_pLeft == NULL || current->m_pRight == NULL) {
			Node* temp = current->m_pLeft;
			if (current->m_pRight) temp = current->m_pRight;
			if (parent) {
				if (parent->m_pLeft == current) {
					parent->m_pLeft = temp;
				}
				else {
					parent->m_pRight = temp;
				}
			}
			else {
				this->m_pRoot = temp;
			}
		}
		else {
			Node* validSubs = current->m_pRight;
			while (validSubs->m_pLeft) {
				validSubs = validSubs->m_pLeft;
			}
			int temp = current->m_nData;
			current->m_nData = validSubs->m_nData;
			validSubs->m_nData = temp;
			return RemoveHelper(current, current->m_pRight, temp);
		}
		delete current;
		return true;
	}
	return RemoveHelper(current, current->m_pLeft, value) ||
		   RemoveHelper(current, current->m_pRight, value);
}