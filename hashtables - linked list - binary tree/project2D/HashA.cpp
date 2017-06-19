#include "HashA.h"



HashA::HashA(int Key, int Value)
{
	this->key = Key;
	this->value = Value;
}


HashA::~HashA()
{
}

int HashA::GetKey()
{
	return key;
}

int HashA::GetValue()
{
	return value;
}
