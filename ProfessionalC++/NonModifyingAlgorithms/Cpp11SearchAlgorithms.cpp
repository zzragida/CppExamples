#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec = {0,0,0,1,0,2,0};
	auto begin = vec.cbegin();
	auto end = vec.cend();

	// find a element != 0
	auto it = find_if_not(begin, end, [](int i){ return i == 0; });

	// find min and max with 1 algorithm
	auto minmax = minmax_element(begin, end);
	cout << "Min = " << *(minmax.first) << 
					" and max = " << *(minmax.second) << endl;

	// all_of()
	vector<int> vec2 = {1,1,1,1};
	if (all_of(vec2.cbegin(), vec2.cend(), [](int i){ return i == 1; }))
	{
		cout << "All elements are == 1" << endl;
	}
	else
	{
		cout << "Not all elements are == 1" << endl;
	}

	// any_of()
	vector<int> vec3 = {0,0,1,0};
	if (any_of(vec3.cbegin(), vec3.cend(), [](int i){ return i == 1; }))
	{
		cout << "At least one element == 1" << endl;
	}
	else
	{
		cout << "No elements are == 1" << endl;
	}

	// none_of()
	vector<int> vec4 = {0,0,0,0};
	if (none_of(vec4.cbegin(), vec4.cend(), [](int i){ return i == 1; }))
	{
		cout << "At least one element != 1" << endl;
	}
	else
	{
		cout << "Some elements are == 1" << endl;
	}
	
	// partition_point()
	vector<int> vec5 = {1,1,0,4,5,6};
	auto point = partition_point(vec5.cbegin(), vec5.cend(),
		[](int i){ return i == 1; });
	cout << "Partition point at position " << (point - vec5.cbegin()) << endl;

	return 0;
}
