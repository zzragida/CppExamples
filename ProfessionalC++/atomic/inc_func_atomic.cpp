#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <atomic>

using namespace std;

void func(atomic<int>& counter)
{
	for (int i = 0; i < 10000; ++i) {
		++counter;
	}
}

int main()
{
	atomic<int> counter(0);
	vector<thread> threads;

	for (int i = 0; i < 10; ++i) {
		threads.push_back(thread{ func, ref(counter) });
	}

	for (auto& t : threads) {
		t.join();
	}

	cout << "Result = " << counter << endl;

	return 0;
}
