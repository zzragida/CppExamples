#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

double geometricMean(const vector<int>& nums)
{
	double mult = accumulate(nums.begin(), nums.end(), 1,
			multiplies<int>());
	return pow(mult, 1.0 / nums.size());
}

int main()
{
	plus<int> myPlus;

	int res = myPlus(4, 5);
	cout << res << endl;

	vector<int> myVector = {1,2,3,4,5,6,7,8};

	cout << "The geometric mean is " << geometricMean(myVector) << endl;

	return 0;
}
