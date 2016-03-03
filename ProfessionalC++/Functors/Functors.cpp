#include <string>

using namespace std;

class FunctionObject
{
public:
	int operator() (int param);
	void operator() (string& str) {}
	int doSquare(int param);
};

int FunctionObject::operator() (int param)
{
	return doSquare(param);
}

int FunctionObject::doSquare(int param)
{
	return param * param;
}

int main()
{
	int x = 3, xSquared, xSquaredAgain;
	FunctionObject square;

	xSquared = square(x);
	xSquaredAgain = square.doSquare(x);

	return 0;
}
