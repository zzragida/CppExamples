#include <map>
#include <iostream>

using namespace std;

void func(const map<int, int>& m)
{
	auto iter = m.find(1);
	if (iter != m.end())
		cout << iter->second << endl;
}

int main()
{
	map<int, int> m;
	m[1] = 11;
	m[2] = 22;
	m[3] = 33;
	func(m);

	return 0;
}
