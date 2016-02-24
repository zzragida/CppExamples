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
			not1(bind2nd(greater_equal<int>(), 100)));

	// lambda
	it = find_if(myVector.begin(), end, [](int i){ return i < 100; });

	if (it == end)
	{
		cout << "All perfect sources" << endl;
	}
	else
	{
		cout << "Found a less than perfect score of " << *it << endl;
	}
	
	return 0;
}
