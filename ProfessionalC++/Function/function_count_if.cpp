#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(int num)
{
	return num % 2 == 0;
}

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i);

	auto f2 = isEven;
	int cnt = count_if(vec.begin(), vec.end(), f2);
	cout << cnt << " even numbers" << endl;

	return 0;
}
