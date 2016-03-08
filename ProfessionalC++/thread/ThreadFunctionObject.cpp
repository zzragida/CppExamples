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
			cout << "Counter " << mId << " has value ";
			cout << i << endl;
		}
	}

protected:
	int mId;
	int mNumIterations;
};


int main()
{
	cout.sync_with_stdio(true);

	thread t1{Counter(1, 2000)};
	Counter c(2, 1200);
	thread t2(c);

	thread t3(Counter(3, 1000));

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
