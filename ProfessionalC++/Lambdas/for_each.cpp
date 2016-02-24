#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec = {1,2,3,4,5};
	int index = 0;
	for_each(vec.begin(), vec.end(),
			[&index](int i){ cout << "Value " << (index++) << ": " << i << endl; });

	return 0;
}
