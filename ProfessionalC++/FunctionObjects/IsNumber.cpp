#include <functional>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

bool isNumber(const string& str)
{
	auto end = str.end();
	
	// lambda
	auto it = find_if(str.begin(), end,
			[](char c){ return !::isdigit(c); });

	// c++ find_if_not
	it = find_if_not(str.begin(), end, ::isdigit);

	return (it == end);
}

int main()
{
	cout << isNumber("12345") << endl;
	cout << isNumber("hello") << endl;
	cout << isNumber("1234a") << endl;

	return 0;
}
