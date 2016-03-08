#include <iostream>

using namespace std;

char** allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray = new char*[xDimension];

	for (size_t i = 0; i < xDimension; i++) {
		myArray[i] = new char[yDimension];
	}

	return myArray;
}

void releaseCharacterBoard(char** myArray, size_t xDimension)
{
	for (size_t i = 0; i < xDimension; i++) {
		delete [] myArray[i];
	}

	delete [] myArray;
}

int main()
{
	char** board = allocateCharacterBoard(7, 13);
	releaseCharacterBoard(board, 7);

	return 0;
}
