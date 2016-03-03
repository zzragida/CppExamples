#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	time_point<steady_clock> tp1;
	tp1 += minutes(10);

	auto d1 = tp1.time_since_epoch();
	duration<double> d2(d1);
	cout << d2.count() << " seconds" << endl;

	return 0;
}
