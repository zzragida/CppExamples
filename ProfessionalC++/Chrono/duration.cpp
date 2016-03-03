#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	duration<long, ratio<60>> d1(123);
	cout << d1.count() << endl;

	duration<double> d2;
	d2 = d2.max();
	cout << d2.count() << endl;

	duration<long, ratio<60>> d3(10);
	duration<long, ratio<1>> d4(14);

	if (d3 > d4)
		cout << "d3 > d4" << endl;
	else
		cout << "d3 == d4" << endl;
	
	++d4;
	d4 *= 2;

	duration<double, ratio<60>> d5 = d3 + d4;

	duration<long, ratio<1>> d6 = d3 + d4;
	cout << d3.count() << " minutes + " << d4.count() << " seconds = "
			 << d5.count() << " minutes or "
			 << d6.count() << " seconds" << endl;

	duration<long> d7;
	duration<double, ratio<60>> d8(d7);
	cout << d7.count() << " seconds = " << d8.count() << " minutes" << endl;

	auto t = hours(1) + minutes(23) + seconds(45);
	cout << seconds(t).count() << " seconds" << endl;

	return 0;
}
