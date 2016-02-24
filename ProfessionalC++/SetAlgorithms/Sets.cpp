#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec1 = {1,2,3,4,5,6,7,8};
	vector<int> vec2 = {6,7,8,9,0};
	vector<int> result;

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	cout << "Set 1: ";
	for_each(vec1.cbegin(), vec1.cend(), [](int i){ cout << i << " "; });
	cout << endl;
	cout << "Set 2: ";
	for_each(vec2.cbegin(), vec2.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	if (includes(vec1.cbegin(), vec1.cend(), vec2.cbegin(), vec2.cend()))
	{
		cout << "The second set is a subset of the first" << endl;
	}
	if (includes(vec2.cbegin(), vec2.cend(), vec1.cbegin(), vec1.cend()))
	{
		cout << "The first set is a subset of the second" << endl;
	}

	result.resize(vec1.size() + vec2.size());

	// union
	auto newEnd = set_union(vec1.cbegin(), vec1.cend(), 
													vec2.cbegin(), vec2.cend(), 
													result.begin());
	cout << "The union is : ";
	for_each(result.begin(), newEnd, [](int i){ cout << i << " "; });
	cout << endl;

	// intersection
	newEnd = set_intersection(vec1.cbegin(), vec1.cend(),
														vec2.cbegin(), vec2.cend(), 
														result.begin());
	cout << "The intersection is : ";
	for_each(result.begin(), newEnd, [](int i){ cout << i << " "; });
	cout << endl;

	// difference
	newEnd = set_difference(vec1.cbegin(), vec1.cend(),
													vec2.cbegin(), vec2.cend(), 
													result.begin());
	cout << "The difference is : ";
	for_each(result.begin(), newEnd, [](int i){ cout << i << " "; });
	cout << endl;

	// symmetric difference
	newEnd = set_symmetric_difference(vec1.cbegin(), vec1.cend(),
																		vec2.cbegin(), vec2.cend(), 
																		result.begin());
	cout << "The symmetric difference is : ";
	for_each(result.begin(), newEnd, [](int i){ cout << i << " "; });
	cout << endl;
	
	return 0;
}
