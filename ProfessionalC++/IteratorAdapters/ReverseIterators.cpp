#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

template <typename Container>
void populateContainer(Container& cont)
{
	for (int i = 0; i < 200; ++i)
	{
		cont.push_back(i);
	}
}

int main()
{
	vector<int> vec;
	populateContainer(vec);

	int num = 150;
	
	auto it1 = find(vec.begin(), vec.end(), num);
	auto it2 = find(vec.rbegin(), vec.rend(), num);

	if (it1 != vec.end()) {
		cout << "Found " << num << " at position " << it1 - vec.begin()
				 << " going forward." << endl;
		cout << "Found " << num << " at position "
				 << it2.base() - 1 - vec.begin() << " going backward." << endl;
	} else {
		cout << "Failed to find " << num << endl;
	}

	return 0;
}
