#include <stdexcept>
#include <iostream>

using namespace std;

class Base
{
public:
	virtual void func() throw(runtime_error) { cout << "Base!"; }
};

class Derived : public Base
{
public:
	virtual void func() throw(exception) { cout << "Derived!"; }	 // ERROR
};

int main()
{
	return 0;
}
