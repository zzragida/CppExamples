#include <memory>
#include <iostream>

using namespace std;

class Nothing
{
public:
	Nothing() { cout << "Nothing::Nothing()" << endl; }
	~Nothing() { cout << "Nothing::~Nothing()" << endl; }
};

void doubleDelete()
{
	Nothing* t = new Nothing();
	shared_ptr<Nothing> smartPtr1(t);
	shared_ptr<Nothing> smartPtr2(t);
}

void noDoubleDelete()
{
	Nothing* t = new Nothing();
	shared_ptr<Nothing> smartPtr1(t);
	shared_ptr<Nothing> smartPtr2 = smartPtr1;
}

int main()
{
	doubleDelete();
	cout << endl;
	noDoubleDelete();

	return 0;
}
