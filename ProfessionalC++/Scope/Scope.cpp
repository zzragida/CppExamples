#include <iostream>

using namespace std;

class Demo
{
public:
	static int get() { return 5; }
};

int get() { return 10; }

namespace NS
{
	int get() { return 20; }
};

int main()
{
	Demo* pd = new Demo();
	Demo d;

	cout << pd->get() << endl;
	cout << d.get() << endl;
	cout << NS::get() << endl;
	cout << Demo::get() << endl;
	cout << ::get() << endl;
	cout << get() << endl;

	return 0;
}
