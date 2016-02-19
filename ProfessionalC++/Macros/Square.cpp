#include <iostream>

using namespace std;

#define SQUARE(x) ((x) * (x))

int main()
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(2 + 3) << endl;

	return 0;
}
