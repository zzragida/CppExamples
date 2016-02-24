#include <iostream>
#include <functional>

using namespace std;

function<int(void)> multiplyBy2Lambda(int x)
{
	return [=]{ return 2*x; };
}

int main()
{
	auto fn = multiplyBy2Lambda(5);
	cout << fn() << endl;

	return 0;
}
