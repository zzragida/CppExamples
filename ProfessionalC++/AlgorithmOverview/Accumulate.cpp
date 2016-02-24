#include <numeric>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double arithmeticMean(const vector<int>& nums)
{
	double sum = accumulate(nums.begin(), nums.end(), 0);
	return sum / nums.size();
}

int product(int num1, int num2)
{
	return num1 * num2;
}

double geometricMean(const vector<int>& nums)
{
	double mult = accumulate(nums.begin(), nums.end(), 1, product);
	return pow(mult, 1.0 / nums.size());
}

double geometricMeanLambda(const vector<int>& nums)
{
	double mult = accumulate(nums.begin(), nums.end(), 1,
			[](int num1, int num2){ return num1 * num2; });
	return pow(mult, 1.0 / nums.size());
}

int main()
{
	vector<int> myVector = {1,2,3,4,5,6};

	cout << "The arithmetic mean is " << arithmeticMean(myVector) << endl;
	cout << "The geometric mean is " << geometricMean(myVector) << endl;
	cout << "The geometric mean (Lambda Expression) is " << geometricMeanLambda(myVector) << endl;
}
