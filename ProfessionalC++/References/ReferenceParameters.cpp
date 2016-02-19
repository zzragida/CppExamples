#include <iostream>

using namespace std;

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

int main()
{
	int x = 5, y = 6;
	swap(x, y);
	cout << "x=" << x << ",y=" << y << endl;

	int* xp = &x, *yp = &y;
	swap(*xp, *yp);
	cout << "x=" << x << ",y=" << y << endl;

	return 0;
}
