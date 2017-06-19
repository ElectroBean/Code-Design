#include "HashTable.h"
#include "HashA.h"
#include <iostream>

HashTable::HashTable()
{
	//creating the table under the constructor by setting the size of the table
	table = new HashA*[TABLE_SIZE];
	//setting the table to be NULL without any values
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}
}


HashTable::~HashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != NULL)
		{
			delete table[i];
		}
		else 
			return;
	}
	delete[] table;
}


int HashTable::Hash(int Key)
{
	return Key % TABLE_SIZE;
}

void HashTable::Insert(int Key, int Value)
{
	//using the hash function we need to set the key
	int hash = Hash(Key);
	//while table is null and the getkey is not equal to key
	while (table[hash] != NULL && table[hash]->GetKey() != Key)
	{
		hash = Hash(hash + 1);
	}

	if (table[hash] != NULL)
	{
		delete table[hash];
	}
	//insert the key and value in the hash table
	table[hash] = new HashA(Key, Value);

}

void HashTable::Delete(int Key)
{
	//use the hash function to get they key 
	int hash = Hash(Key);
	// while table is not equal to null 
	while (table[hash] != NULL)
	{
	// if the key we entered is equal to the key in the table break
		if (Key == table[hash]->GetKey())
		{
			break;
		}
			//else loop through until we find the key
		hash = Hash(hash + 1);
	}

	//once found delete the value in the index
	if (table[hash] == NULL)
	{
		std::cout << " the table is empty! " << std::endl;
	}
	else
	{
		delete table[hash];
	}
	

	std::cout << "item deleted" << std::endl;
	//if the table is empty output a message
}
