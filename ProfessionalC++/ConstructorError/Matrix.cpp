#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(unsigned int width, unsigned int height) throw(bad_alloc)
	: mWidth(width), mHeight(height), mMatrix(nullptr)
{
	mMatrix = new Element*[width];
	unsigned int i = 0;

	try 
	{
		for (i = 0; i < height; ++i)
			mMatrix[i] = new Element[height];
	} 
	catch (...) 
	{
		cout << "Exception caught in constructor, cleaning up..." << endl;
	
		for (unsigned int j = 0; j < i; ++j)
			delete [] mMatrix[j];
		delete [] mMatrix;
		mMatrix = nullptr;

		throw bad_alloc();
	}
}

Matrix::~Matrix()
{
	for (unsigned int i = 0; i < mHeight; ++i)
		delete [] mMatrix[i];
	delete [] mMatrix;
	mMatrix = nullptr;
}
