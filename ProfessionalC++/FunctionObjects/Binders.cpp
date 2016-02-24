#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main()
{
	vector<int> myVector = {1,2,3,4,5,6,7};

	auto end = myVector.end();
	auto it = find_if(myVector.begin(), end,
			bind(greater_equal<int>(), placeholders::_1, 100));

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
