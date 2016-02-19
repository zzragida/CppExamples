#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass(int& ref) : mRef(ref) {}
	int getRef() const { return mRef; }

protected:
	int& mRef;
};

int main()
{
	int i = 123;
	MyClass m(i);
	cout << "i=" << i << ",m=" << m.getRef() << endl;

	return 0;
}
