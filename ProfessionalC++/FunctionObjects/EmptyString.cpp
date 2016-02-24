#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void findEmptyString(const vector<string>& strings)
{
	auto end = strings.end();

	// c++ mem_fn
	auto it = find_if(strings.begin(), end, mem_fn(&string::empty));

	// lambda
	it = find_if(strings.begin(), end,
			[](const string& str) { return str.empty(); });

	if (it == end)
	{
		cout << "No empty string" << endl;
	}
	else
	{
		cout << "Empty string at position: " << it - strings.begin() << endl;
	}
}

int main()
{
	vector<string> myVector;

	string one = "blah";
	string two = "";
	
	myVector.push_back(one);
	myVector.push_back(one);
	myVector.push_back(two);
	myVector.push_back(one);

	findEmptyString(myVector);

	return 0;
}
