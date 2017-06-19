#pragma once
class HashA
{
public:
	HashA(int Key, int Value);
	~HashA();

	int GetKey();
	int GetValue();

private: 
	int key; 
	int value;
};

