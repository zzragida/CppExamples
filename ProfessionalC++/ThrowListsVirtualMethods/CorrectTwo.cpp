#include <stdexcept>
#include <iostream>

using namespace std;

class Base
{
public:
	virtual void func() throw(exception) { cout << "Base!"; }
};

class Derived : public Base
{
public:
	virtual void func() throw(exception, runtime_error) 
	{ cout << "Derived!"; }
};

int main()
{
	return 0;
}
