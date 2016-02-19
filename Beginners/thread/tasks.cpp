#include <iostream>
#include <future>
#include <chrono>

using namespace std;

int square(int x)
{
	return x * x;
}

int main()
{
	auto a = async(&square, 10);
	int v = a.get();

	cout << "The thread returned " << v << endl;

	return 0;
}
