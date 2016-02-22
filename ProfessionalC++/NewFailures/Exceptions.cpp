#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	int* ptr;
	int numInts = 10;

	try
	{
		ptr = new int[numInts];
	}
	catch (const bad_alloc& e)
	{
		cout << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory" << endl;
		return 1;
	}

	return 0;
}
