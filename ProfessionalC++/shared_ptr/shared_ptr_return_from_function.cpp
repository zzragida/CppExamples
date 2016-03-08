#include <iostream>
#include <memory>

using namespace std;

class Simple
{
public:
	Simple() { cout << "constructor" << endl; }
	virtual ~Simple() { cout << "deconstructor" << endl; }
};

shared_ptr<Simple> func()
{
	auto ptr = make_shared<Simple>();
	return ptr;
}

int main()
{
	shared_ptr<Simple> p = func();

	return 0;
}
