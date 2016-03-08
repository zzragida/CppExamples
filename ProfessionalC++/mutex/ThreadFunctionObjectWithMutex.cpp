#include <mutex>
#include <thread>
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
			lock_guard<mutex> lock(mMutex);
			cout << "Counter " << mId << " has value " << i << endl;
		}
	}

protected:
	int mId;
	int mNumIterations;
	static mutex mMutex;
};

mutex Counter::mMutex;


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
