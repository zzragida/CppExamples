#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

int main()
{
	auto start = system_clock::now();
	double d = 0;
	for (int i = 0; i < 100000; i++)
		d += sqrt(sin(i) * cos(i));
	auto end = system_clock::now();
	auto diff = end - start;

	cout << duration<double, milli>(diff).count() << "ms" << endl;

	return 0;
}
