#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

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

//my remove
void BinaryTree::Delete(int value)
{
	Node* currentNode = nullptr;
	Node* parentNode = nullptr;

	FindNode(value, &currentNode, &parentNode);
	if (!currentNode)
		return;

	if (currentNode->m_pRight)
	{
		//Find the minimum value node in the right subtree
		Node* pMinNode = currentNode->m_pRight;
		Node* parentNode = currentNode;
		while (pMinNode->m_pLeft)
		{
			parentNode = pMinNode;
			pMinNode = pMinNode->m_pLeft;
		}

		currentNode->m_nData = pMinNode->m_nData;

		if (parentNode->m_pLeft == pMinNode)
		{
			parentNode->m_pLeft = pMinNode->m_pRight;
		}
		else
		{
			parentNode->m_pRight = pMinNode->m_pRight;
		}

		delete pMinNode;
	}
	else
	{
		if (parentNode)
		{
			if (parentNode->m_pLeft == currentNode)
			{
				parentNode->m_pLeft = currentNode->m_pLeft;

			}
			else
			{
				parentNode->m_pRight = currentNode->m_pLeft;

			}
		}
		else
		{
			m_pRoot = currentNode->m_pLeft;

		}

		delete currentNode;
	}
}

void BinaryTree::FindNode(int value, Node** node, Node** aParent)
{
	Node* temp = m_pRoot;
	Node* parent;

	while (temp != NULL)
	{
		if (temp->m_nData == value)
		{
			break;
		}

		if (value > temp->m_nData)
		{
			parent = temp;
			temp = temp->m_pRight;
		}
		else if (value < temp->m_nData)
		{
			parent = temp;
			temp = temp->m_pLeft;
		}
	}


	if (temp == NULL)
	{
		std::cout << "node not found" << std::endl;
	}
	if (temp->m_nData == value)
	{
		*node = temp;
		*aParent = parent;
		std::cout << "node found" << std::endl;
	}
}

//internet remove
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

