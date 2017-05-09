#include <iostream>
#include <random>

void sort(int* aArray, int aArraySize);
void Bogosort(int* aArray, int aArraySize);
void shuffle(int* aArray, int aArraysize);
int randRange(unsigned int min, unsigned int max);
bool checkOrder(int* aArray, int aArraySize);
void QuickSort(int* a, int low, int high);
int partition(int* a, int low, int high);

void main()
{
	const int iArraySize = 10;
	int iArray[iArraySize] = { 12, 32, 4, 1, 22, 35, 1, 23, 15 ,7 };
	//sort(iArray, iArraySize);
	Bogosort(iArray, iArraySize);
	//QuickSort(iArray, 1, 35);

	for (int i = 0; i < iArraySize; i++)
	{
		std::cout << iArray[i] << ", ";
	}
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
	int count = 1;

	while (!isInOrder)
	{
		shuffle(aArray, aArraySize);
		std::cout << count << ": ";
		for (int i = 0; i < aArraySize; i++)
		{
			count++;
			std::cout <<  aArray[i] << ", ";
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

void QuickSort(int* a, int low, int high)
{
	if (low < high)
	{
		int p = partition(a, low, high);
		QuickSort(a, low, p);
		QuickSort(a, p + 1, high);
	}
}

int partition(int* a, int low, int high)
{
	int pivot = a[low];
	int leftwall = low;

	for (int j = low + 1; j < high; j++)
	{
		if (a[j] < pivot)
		{
			std::swap(a[j], a[leftwall]);

			leftwall = leftwall + 1;
		}
	}

	int temp = pivot;
	pivot = a[leftwall];
	a[leftwall] = temp;

	return leftwall;
}








