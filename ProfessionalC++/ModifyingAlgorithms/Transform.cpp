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

void print(int elem)
{
	cout << elem << " ";
}

int main()
{
	vector<int> vec;
	populateContainer(vec);

	// normal
	cout << "The vector contents are: " << endl;
	for_each(vec.begin(), vec.end(), &print);
	cout << endl;

	transform(vec.begin(), vec.end(), vec.begin(),
		bind2nd(plus<int>(), 100));
	cout << "The vector contents are: " << endl;
	for_each(vec.begin(), vec.end(), &print);
	cout << endl;

	// lambda
	populateContainer(vec);
	cout << "The vector contents are: " << endl;
	for (auto& i : vec) cout << i << " ";
	cout << endl;

	transform(vec.begin(), vec.end(), vec.begin(),
		[](int i){ return i+100; });
	cout << "The vector contents are: " << endl;
	for (auto& i : vec) cout << i << " ";
	cout << endl;

	return 0;
}
