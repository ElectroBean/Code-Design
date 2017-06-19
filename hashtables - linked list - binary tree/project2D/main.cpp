#include "Application2D.h"
#include <iostream>
#include "HashTable.h"
#include "BinaryTree.h"
#include "LinkedList.h"

using namespace std;

int main() {
	int key, value = 0;
	bool isRunning = true;
	char endtheGameLoop = 'q';
	HashTable hashTable;
	BinaryTree tree;
	LinkedList<int> list;
	tree.Add(10);
	tree.Add(11);
	tree.Add(9);
	tree.Add(5);
	tree.Add(15);
	tree.Remove(10);
	tree.Delete(5);
	list.push_front(10);
	list.push_back(5);
	list.push_back(7);
	list.push_front(22);
	list.remove(22);

	while (isRunning)
	{
		cout << "enter element to be inserted: ";
		cin >> value;
		cout << "\n";
	
		cout << "enter key to insert at: ";
		cin >> key;
		cout << "\n";
	
		hashTable.Insert(key, value);
		cout << "enter key to delete: ";
		cin >> key;
		cout << "\n";
		hashTable.Delete(key);
		isRunning = false;
	}
	
	// allocation
	auto app = new Application2D();
	
	// initialise and loop
	app->run("AIE", 1280, 720, false);
	
	// deallocation
	delete app;
	

	//system("pause");
	return 0;
}