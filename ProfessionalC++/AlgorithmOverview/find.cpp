#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> myVector = {1,2,3,4,5,6,7};

	auto it = find(myVector.begin(), myVector.end(), 5);
	if (it != myVector.end())
	{
		cout << "find 5 in myVector" << endl;
	}

	return 0;
}
