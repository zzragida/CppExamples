#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
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
	vector<int> vectorOne, vectorTwo;
	populateContainer(vectorOne);

	back_insert_iterator<vector<int>> inserter(vectorTwo);

	remove_copy_if(vectorOne.begin(), vectorOne.end(), inserter,
			[](int i){ return i == 100; });

	copy(vectorTwo.begin(), vectorTwo.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
