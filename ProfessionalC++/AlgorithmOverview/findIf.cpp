#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool perfectScore(int num)
{
	return (num >= 100);
}

int main()
{
	vector<int> myVector = {1,2,3,4,5,6,7};

	auto end = myVector.end();
	auto it = find_if(myVector.begin(), end, perfectScore);
	if (it == end)
	{
		cout << "No perfect scores" << endl;
	}
	else
	{
		cout << "Found a perfect score of " << *it << endl;
	}

	// lambda expression
	it = find_if(myVector.begin(), end, [](int i){ return i >= 100; });
	if (it == end)
	{
		cout << "No perfect scores" << endl;
	}
	else
	{
		cout << "Found a perfect score of " << *it << endl;
	}

	return 0;
}
