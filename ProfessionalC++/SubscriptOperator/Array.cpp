#include "Array.h"
#include <stdexcept>

using namespace std;

Array::Array()
{
	mSize = kAllocSize;
	mElems = new int[mSize];
	initializeElements();
}

Array::~Array()
{
	delete [] mElems;
	mElems = nullptr;
}

void Array::initializeElements()
{
	for (size_t i = 0; i < mSize; ++i)
		mElems[i] = 0;
}

void Array::resize(size_t newSize)
{
	int* oldElems = mElems;
	size_t oldSize = mSize;

	mSize = newSize;
	mElems = new int[newSize];
	initializeElements();

	for (size_t i = 0; i < oldSize; ++i)
	{
		mElems[i] = oldElems[i];
	}

	delete [] oldElems;
}

int& Array::operator[](size_t x)
{
	if (x < 0)
		throw out_of_range("");

	if (x >= mSize)
	{
		resize(x + kAllocSize);
	}

	return mElems[x];
}

const int& Array::operator[](size_t x) const
{
	if (x < 0 || x >= mSize)
		throw out_of_range("");
	return mElems[x];
}
