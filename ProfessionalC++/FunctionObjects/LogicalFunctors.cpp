#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

bool allTrue(const vector<bool>& flags)
{
	return accumulate(flags.begin(), flags.end(), true,
			logical_and<bool>());
}

bool anyTrue(const vector<bool>& flags)
{
	return accumulate(flags.begin(), flags.end(), false,
			logical_or<bool>());
}

int main()
{
	vector<bool> myVector = {false, true, false, true, true};

	cout << "allTrue? " << (allTrue(myVector) ? "yes" : "no") << endl;
	cout << "anyTrue? " << (anyTrue(myVector) ? "yes" : "no") << endl;

	return 0;
}
