#include <thread>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

class Data
{
public:
	void operator()()
	{
		call_once(mOnceFlag, &Data::init, this);
		cout << "work" << endl;
	}

protected:
	void init()
	{
		cout << "init()" << endl;
		mMemory = new char[24];
	}

	mutable once_flag mOnceFlag;
	mutable char* mMemory;
};

int main()
{
	cout.sync_with_stdio(true);

	Data d;
	vector<thread> threads;

	for (int i = 0; i < 10; ++i) {
		threads.push_back(thread{ref(d)});
	}

	for (auto& t : threads) {
		t.join();
	}
	
	cout << "Done" << endl;

	return 0;
}
