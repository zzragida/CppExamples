#include <thread>
#include <iostream>

using namespace std;

int main()
{
	cout.sync_with_stdio(true);

	thread t1([](int id, int numIterations) {
		for (int i = 0; i < numIterations; ++i) {
			cout << "Counter " << id << " has value " << i << endl;
		}
	}, 1, 5);

	t1.join();

	return 0;
}
