#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

void testCallback(const vector<int>& vec, const function<bool(int)>& callback)
{
	for (auto i : vec)
	{
		if (!callback(i))
			break;
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
	int index = 0;

	generate(vec.begin(), vec.end(), [&index]{ return ++index; });
	for_each(vec.begin(), vec.end(), [](int i){ cout << i << " "; });
	cout << endl;
	testCallback(vec, [](int i){ return i < 6; });
}
