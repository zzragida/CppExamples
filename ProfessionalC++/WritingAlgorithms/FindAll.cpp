#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename InputIterator, typename Predicate>
vector<InputIterator> find_all(InputIterator first, InputIterator last, Predicate pred)
{
	vector<InputIterator> res;

	while (true)
	{
		first = find_if(first, last, pred);
		if (first == last)
			break;
		res.push_back(first);
		++first;
	}

	return res;
}

int main()
{
	vector<int> vec = {3, 4, 5, 4, 5, 6, 5, 8};
	auto all = find_all(vec.begin(), vec.end(), [](int i){ return i == 5; });
	
	cout << "Found " << all.size() << " matching elements: ";
	for (auto it : all)
	{
		cout << it - vec.begin() << " ";
	}
	cout << endl;

	return 0;
}
