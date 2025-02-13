#include "SpreadsheetCell.h"
#include <iostream>
#include <cstring>

using namespace std;

static const size_t NOT_FOUND = (size_t)(-1);

template <typename T>
size_t Find(T& value, T* arr, size_t size)
{
	cout << "original" << endl;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == value)
			return i;
	}
	return NOT_FOUND;
}

template <typename T>
size_t Find(T*& value, T** arr, size_t size)
{
	cout << "ptr special" << endl;
	for (size_t i = 0; i < size; i++)
	{
		if (*arr[i] == *value)
			return i;
	}
	return NOT_FOUND;
}

template <>
size_t Find<char*>(char*& value, char** arr, size_t size)
{
	cout << "Specialization" << endl;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i], value) == 0)
			return i;
	}
	return NOT_FOUND;
}

size_t Find(char*& value, char** arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i], value) == 0)
			return i;
	}
	return NOT_FOUND;
}

int main()
{
	size_t res = NOT_FOUND;

	int x = 3, intArr[] = {1, 2, 3, 4};
	size_t sizeArr = sizeof(intArr) / sizeof(int);
	res = Find(x, intArr, sizeArr);
	res = Find<int>(x, intArr, sizeArr);

	double d1 = 5.6, dArr[] = {1.2, 3.4, 5.7, 7.5};
	sizeArr = sizeof(dArr) / sizeof(double);
	res = Find(d1, dArr, sizeArr);
	res = Find<double>(d1, dArr, sizeArr);

	char* word = "two";
	char* arr[] = {"one", "two", "three", "four"};
	sizeArr = sizeof(arr) / sizeof(arr[0]);
	res = Find<char*>(word, arr, sizeArr);
	res = Find(word, arr, sizeArr);

	int *px = &x, *pArr[] = {&x, &x};
	sizeArr = sizeof(pArr) / sizeof(pArr[0]);
	res = Find(px, pArr, sizeArr);

	SpreadsheetCell c1(10), c2[] = { SpreadsheetCell(4), SpreadsheetCell(10) };
	sizeArr = sizeof(c2) / sizeof(c2[0]);
	res = Find(c1, c2, sizeArr);
	res = Find<SpreadsheetCell>(c1, c2, sizeArr);

	SpreadsheetCell *pc1 = &c1;
	SpreadsheetCell *psa[] = {&c1, &c1};
	sizeArr = sizeof(psa) / sizeof(psa[0]);
	res = Find(pc1, psa, sizeArr);

	return 0;
}
