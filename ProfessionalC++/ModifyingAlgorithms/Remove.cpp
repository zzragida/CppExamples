#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void removeEmptyStrings(vector<string>& strings)
{
	auto it = remove_if(strings.begin(), strings.end(),
		[](const string& str){ return str.empty(); });

	strings.erase(it, strings.end());
}

int main()
{
	vector<string> vec = {"", "one", "", "two", "three", "four"};

	for (auto& str : vec)
		cout << str << " ";
	cout << endl;

	removeEmptyStrings(vec);

	for (auto& str : vec)
		cout << str << " ";
	cout << endl;

	return 0;
}
