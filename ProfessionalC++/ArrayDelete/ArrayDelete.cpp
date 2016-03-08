#include <iostream>

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called" << endl; }
	virtual ~Simple() { cout << "Simple destructor called" << endl; }
};

int main()
{
	Simple* mySimpleArray = new Simple[4];
	delete [] mySimpleArray;
	mySimpleArray = nullptr;

	size_t arrSize = 4;
	Simple** mySimplePtrArray = new Simple*[arrSize];

	for (size_t i = 0; i < arrSize; i++) {
		mySimplePtrArray[i] = new Simple();
	}

	for (size_t i = 0; i < arrSize; i++) {
		delete mySimplePtrArray[i];
	}

	delete [] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	return 0;
}
