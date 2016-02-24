#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

template <typename Container>
void populateContainer(Container& cont)
{
	cont = {1,2,3,4,5};
}

int main()
{
	vector<int> vec;
	populateContainer(vec);

	int lowerLimit = numeric_limits<short>::min();
	int upperLimit = numeric_limits<short>::max();

	replace_if(vec.begin(), vec.end(), [=](int i){ return i < lowerLimit; }, lowerLimit);
	replace_if(vec.begin(), vec.end(), [=](int i){ return i > upperLimit; }, upperLimit);

	for_each(vec.cbegin(), vec.cend(),
		[](int i){ cout << i << " "; });
	cout << endl;

	return 0;
}
