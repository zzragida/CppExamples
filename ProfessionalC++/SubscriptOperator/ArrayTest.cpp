#include "Array.h"
#include <iostream>

using namespace std;

void printArray(const Array& arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	Array arr;
	for (size_t i = 0; i < 10; i++)
		arr[i] = 100;

	printArray(arr, 10);

	return 0;
}
