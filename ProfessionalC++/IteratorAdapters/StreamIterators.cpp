#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	for (int i = 0; i < 100; i++) 
	{
		vec.push_back(i);
	}

	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
