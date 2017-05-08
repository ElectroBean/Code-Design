#include <iostream>
#include <random>

void sort(int* aArray, int aArraySize);
void Bogosort(int* aArray, int aArraySize);
void shuffle(int* aArray, int aArraysize);
int randRange(unsigned int min, unsigned int max);
bool checkOrder(int* aArray, int aArraySize);

void main()
{
	const int iArraySize = 10;
	int iArray[iArraySize] = { 12, 32, 4, 1, 22, 35, 1, 23, 15 ,7 };
	//sort(iArray, iArraySize);
	Bogosort(iArray, iArraySize);

	//for (int i = 0; i < iArraySize; i++)
	//{
	//	std::cout << iArray[i] << ", ";
	//}
	std::cout << "\n";
	system("pause");
}

void sort(int* aArray, int aArraySize)
{
	bool sorting = true;
	if (aArraySize == 0)
	{
		std::cout << "Array is empty" << std::endl;
	}
	else
	{
		while (sorting)
		{
			sorting = false;
			for (int i = 0; i < aArraySize - 1; i++)
			{
				int temp = 0;
				if (aArray[i] > aArray[i + 1])
				{
					temp = aArray[i];
					aArray[i] = aArray[i + 1];
					aArray[i + 1] = temp;
					sorting = true;
				}
			}
		}
	}
}

void Bogosort(int* aArray, int aArraySize)
{
	bool isInOrder = false;

	while (!isInOrder)
	{
		shuffle(aArray, aArraySize);
		for (int i = 0; i < aArraySize; i++)
		{
			std::cout << aArray[i] << ", ";
		}
		std::cout << "\n";

		if (checkOrder(aArray, aArraySize))
		{
			isInOrder = true;
		}
	}
}

void shuffle(int* aArray, int aArraysize)
{
	int temp = 0;
	for (int i = 0; i < aArraysize; i++)
	{
		int rand = randRange(0, aArraysize - 1);
		temp = aArray[rand];
		aArray[rand] = aArray[i];
		aArray[i] = temp;
	}
}

int randRange(unsigned int min, unsigned int max)
{
	std::random_device rand;
	std::mt19937 eng(rand());
	std::uniform_int_distribution<> range(min, max);
	return(range(eng));
}

bool checkOrder(int* aArray, int aArraySize)
{
	for (int i = 0; i < aArraySize - 1; i++)
	{
		if (aArray[i] > aArray[i + 1])
		{
			return false;
		}
	}
	return true;
}