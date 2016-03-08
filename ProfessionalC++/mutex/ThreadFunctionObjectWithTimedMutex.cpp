#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: mId(id), mNumIterations(numIterations)
	{
	}

	void operator()() const
	{
		for (int i = 0; i < mNumIterations; ++i) {
			unique_lock<timed_mutex> lock(mTimedMutex, chrono::milliseconds(200));
			if (lock) {
				cout << "Counter " << mId << " has value " << i << endl;
			} else {
			}
		}
	}

protected:
	int mId;
	int mNumIterations;
	static timed_mutex mTimedMutex;
};

timed_mutex Counter::mTimedMutex;

int main()
{
	cout.sync_with_stdio(true);	// Make sure cout is thread-safe

	thread t1{Counter(1, 20)};
	Counter c(2, 12);
	thread t2(c);

	thread t3(Counter(3, 10));

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
