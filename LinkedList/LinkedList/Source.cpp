#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list(10);
	list.push_front(10);
	list.push_back(19);
	list.clear();
	list.insert(5, 10);
	bool empty = list.empty();

	for (auto i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	std::cout << empty << std::endl;
	system("pause");
}