#include <iostream>

using namespace std;

class Simple
{
public:
	Simple() { mIntPtr = new int(); }
	virtual ~Simple() { delete mIntPtr; }

	void setIntPtr(int inInt) { *mIntPtr = inInt; }

protected:
	int* mIntPtr;
};

void doSomething(Simple*& outSimplePtr)
{
	outSimplePtr = new Simple();
}

int main()
{
	Simple* simplePtr = new Simple();

	doSomething(simplePtr);

	delete simplePtr;

	return 0;
}
