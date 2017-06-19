#pragma once

class HashA;
const int TABLE_SIZE = 100;

class HashTable
{
public:
	HashTable();
	~HashTable();

	int Hash(int Key);
	void Insert(int Key, int Value);
	void Delete(int Key);

private:
	HashA** table;
};

