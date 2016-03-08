#include <iostream>

using namespace std;

void doubleInts(int* theArray, size_t inSize)
{
	for (size_t i = 0; i < inSize; i++) {
		theArray[i] *= 2;
	}
}

int main()
{
	size_t arrSize = 4;
	int* heapArray = new int[arrSize];
	heapArray[0] = 1;
	heapArray[1] = 5;
	heapArray[2] = 3;
	heapArray[3] = 4;
	doubleInts(heapArray, arrSize);

	for (size_t i = 0; i < arrSize; i++) {
		cout << heapArray[i] << " ";
	}
	cout << endl;

	delete [] heapArray;
	heapArray = nullptr;

	int stackArray[] = {5, 7, 9, 11};
	for (auto i : stackArray) {
		cout << i << " ";
	}
	cout << endl;

	arrSize = sizeof(stackArray) / sizeof(stackArray[0]);
	doubleInts(stackArray, arrSize);
	for (auto i : stackArray) {
		cout << i << " ";
	}
	cout << endl;

	doubleInts(&stackArray[0], arrSize);
	for (auto i : stackArray) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
