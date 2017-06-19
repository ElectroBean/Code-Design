#pragma once
#include <iostream>
template<typename T>
class LinkedList
{
public:
	struct Node
	{
		T value;
		Node* next = nullptr;
		Node* previous = nullptr;
	};

	class Iterator
	{
	public:
		Iterator() {}
		Iterator(Node* node) { m_node = node; }
		~Iterator() {}

		bool operator == (const Iterator& other)
		{
			return (m_node == other.m_node);
		}

		bool operator != (const Iterator& other)
		{
			return(m_node != other.m_node);
		}

		Iterator operator ++ ()
		{
			m_node = m_node->next;
			return *this;
		}

		Iterator operator --()
		{
			m_node = m_node->previous;
			return *this;
		}

		Iterator operator ++ (int)
		{
			Iterator temp(m_node);
			m_node = m_node->next;
			return temp;
		}

		T& operator * ()
		{
			return m_node->value;
		}

		T& get()
		{
			return m_node->value;
		}

	public:
		Node* m_node;
	};

	Iterator begin()
	{
		return Iterator(m_first);
	}
	Iterator end()
	{
		if (m_last != nullptr)
			return Iterator(m_last->next);

		else return nullptr;
	}


	//pointer to the first item
	Node* m_first = nullptr;
	//pointer to the lest item
	Node* m_last = nullptr;
	int m_elements = 0;

	LinkedList()
	{

	}
	LinkedList(int startingElements) : m_elements(startingElements)
	{
		//loop through new list that has been created
		for (int i = 0; i < m_elements; i++)
		{
			Node* node = new Node();
			if (i == 0)
				m_last = node;

			//make it point to the first item
			node->next = m_first;

			if (m_first != nullptr)
				m_first->previous = node;

			m_first = node;
		}

	}

	~LinkedList()
	{
		while (m_first != nullptr)
		{
			auto* temp = m_first->next;
			delete m_first;
			m_first = temp;
		}
	}

	void clear()
	{
		while (m_first != nullptr)
		{
			auto* temp = m_first->next;
			delete m_first;
			m_first = temp;
		}
		m_first = m_last = nullptr;
		m_elements = 0;
	}

	int count()
	{
		return m_elements;

	}

	void push_back(const T & value)
	{
		Node* node = new Node();

		node->value = value;

		node->previous = m_last;

		if (m_last == nullptr)
			m_first = node;
		else
			m_last->next = node;

		m_last = node;

		m_elements++;
	}

	void push_front(const T & value)
	{
		Node* node = new Node();

		//set the node value
		node->value = value;
		//set the first node's previous to the new node
		if(m_first)
		m_first->previous = node;

		//set the next of the new node to the first node
		node->next = m_first;

		//if the first node is null
		//set the last node to the new node
		//else
		//set the previous of the first node to the new node
		if (m_first == nullptr)
			m_last = node;
		else
			m_first->previous = node;

		//set the first node to the new node
		m_first = node;


		//add to the number of elements
		m_elements++;

	}

	void pop_back()
	{
		Node* secondLast = m_last->previous;
		//delete the last node
		delete m_last;
		// set the second last node to be the last ndoe
		m_last = secondLast;

		if (m_last == nullptr)
			m_first = nullptr;
		else
			m_last->next = nullptr;

		m_elements--;

	}
	void pop_front()
	{
		Node* second = m_first->next;
		delete m_first;
		m_first = second;

		if (m_first == nullptr)
			m_last = nullptr;
		else
			m_first->previous = nullptr;

		m_elements--;

	}

	//void insert(const T& iterator, const T& value)
	//{
	//	Node* node = new Node();
	//	node->value = value;
	//	T counter = 0;
	//	auto temp = node;
	//	if (m_first == nullptr)
	//	{
	//		m_first = node;
	//	}
	//	else 
	//		temp = m_first;
	//	bool isRunning = false;
	//	//for (int i = 0; i == iterator )
	//	while (!isRunning)
	//	{
	//		
	//		auto next = temp->next;
	//
	//
	//		if (counter == iterator)
	//		{
	//			
	//			std::cout << "hello!";
	//			isRunning = true;
	//		}
	//
	//		temp = next;
	//		counter++;
	//	}
	//}

	bool empty()
	{
		if (m_elements == 0)
		{
			return true;
		}

		return false;
	}

	Node first()
	{
		return first;
	}

	Node last()
	{
		return last;
	}

	void remove(T value)
	{
		Node* currentNode = m_first;
		Node* nextNode = m_first->next;
		Node* previousNode = nullptr;

		//while current isn't null
		while (currentNode != nullptr)
		{
			//if the current value is equal to the arguement 
			if (currentNode->value == value)
			{
				//set next's previous to current's previous(relinking)
				nextNode->previous = currentNode->previous; /// 1st == nullptr?

															//make sure previous isn't null
				if (previousNode != nullptr)
				{
					//link previous to next
					previousNode->next = currentNode->next;
				}
				else
				{
					//set first to next
					m_first = nextNode;
				}

				delete currentNode;
				--m_elements;
			}

			currentNode = nextNode;
			if (currentNode != nullptr)
			{
				nextNode = currentNode->next;
				previousNode = currentNode->previous;
			}
		}
	}

};