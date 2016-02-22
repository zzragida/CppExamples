#include <new>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

class PleaseTerminateMe {};

void myNewHandler()
{
	cerr << __FILE__ << "(" << __LINE__
			 << "): Unable to allocate memory" << endl;
	throw PleaseTerminateMe();
}

int main()
{
	try
	{
		new_handler oldHandler = set_new_handler(myNewHandler);

		int numInts = numeric_limits<int>::max();
		int* ptr = new int[numInts];
	}
	catch (const PleaseTerminateMe&)
	{
		cerr << __FILE__ << "(" << __LINE__
				 << "): Terminating program" << endl;
		return 1;
	}

	return 0;
}
