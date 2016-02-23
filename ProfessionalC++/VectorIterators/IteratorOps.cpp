#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> intVector(10, 0);

	auto it = intVector.begin();
	it += 5;
	--it;
	*it = 4;

	for (auto& n : intVector)
	{
		cout << n << endl;
	}

	return 0;
}
