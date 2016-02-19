#include <iostream>
#include <initializer_list>

using namespace std;

int makeSum(initializer_list<int> list)
{
	int total = 0;
	for (auto iter = list.begin(); iter != list.end(); ++iter)
		total += (*iter);
	return total;
}

int main()
{
	cout << makeSum({1, 2, 3}) << endl;
	cout << makeSum({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
	return 0;
}
