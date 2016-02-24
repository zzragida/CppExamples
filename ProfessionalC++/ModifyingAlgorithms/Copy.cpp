#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename Container>
void populateContainer(Container& cont)
{
	cont = {1,2,3,4,5};
}

int main()
{
	vector<int> vec1, vec2;
	populateContainer(vec1);

	vec2.resize(vec1.size());

	// copy
	copy(vec1.cbegin(), vec1.cend(), vec2.begin());
	for_each(vec2.cbegin(), vec2.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	// copy_backward
	copy_backward(vec1.cbegin(), vec1.cend(), vec2.end());
	for_each(vec2.cbegin(), vec2.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	// copy_if
	auto endIterator = copy_if(vec1.begin(), vec1.end(), vec2.begin(),
		[](int i){ return i%2 == 0;});
	vec2.erase(endIterator, vec2.end());
	for_each(vec2.cbegin(), vec2.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	// copy_n
	size_t cnt = 3;
	copy_n(vec1.cbegin(), cnt, vec2.begin());
	for_each(vec2.cbegin(), vec2.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	// partition_copy
	vector<int> vecOdd, vecEven;
	vecOdd.resize(vec1.size());
	vecEven.resize(vec1.size());

	auto pairIters = partition_copy(vec1.cbegin(), vec1.cend(),
			vecEven.begin(), vecOdd.begin(),
			[](int i){ return i%2 == 0; });
	
	vecEven.erase(pairIters.first, vecEven.end());
	vecOdd.erase(pairIters.second, vecOdd.end());

	cout << "Event numbers: ";
	for_each(vecEven.cbegin(), vecEven.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	cout << "Odd numbers: ";
	for_each(vecOdd.cbegin(), vecOdd.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	return 0;
}
