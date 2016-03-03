#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

int main()
{
	system_clock::time_point tpoint = system_clock::now();
	time_t tt = system_clock::to_time_t(tpoint);
	tm* t = localtime(&tt);
	char buffer[80] = {0};
	strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
	cout << buffer << endl;

	return 0;
}
