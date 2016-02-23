#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int arr[10];
	vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	vec.insert(vec.end(), arr, arr + 10);

	for (auto& i : vec)
	{
		cout << i << " ";
	}

	return 0;
}
