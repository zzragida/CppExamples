#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <set>
#include <iostream>

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
	vector<int> vectorOne;
	set<int> setOne;
	populateContainer(vectorOne);

	insert_iterator<set<int>> inserter(setOne, setOne.begin());

	remove_copy_if(vectorOne.begin(), vectorOne.end(), inserter,
			[](int i){ return i == 100; });

	copy(setOne.begin(), setOne.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
