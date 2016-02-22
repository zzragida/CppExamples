#include <iostream>

using namespace std;

int main()
{
	int* ptr;
	int numInts = 10;

	ptr = new(nothrow) int[numInts];
	if (ptr == nullptr)
	{
		cerr << __FILE__ << "(" << __LINE__
				 << "): Unable to allocate memory" << endl;
		return 1;
	}

	return 0;
}
