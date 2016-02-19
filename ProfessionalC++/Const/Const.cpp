#include <cstdlib>

const double PI = 3.14159;

void func(const int param)
{
}

class BigClass;
void doSomething(const BigClass& arg)
{
}

void constInOne()
{
	const int* ip;
	ip = new int[10];
}

void constIntTwo()
{
	int const* ip;
	ip = new int[10];
}

void constPtrOne()
{
	int* const ip = nullptr;
	ip[4] = 5;
}

void constPtrTwo()
{
	int* const ip = new int[10];
	ip[4] = 5;
}

void constInPtrOne()
{
	int const* const ip = nullptr;
}

void constIntPtrTwo()
{
	const int* const ip = nullptr;
}

void manyLevelConst()
{
	const int * const * const * const ip = nullptr;
}

int main()
{
	int* ip;
	ip = new int[10];
	ip[4] = 5;

	int z;
	const int& zRef = z;

	return 0;
}
