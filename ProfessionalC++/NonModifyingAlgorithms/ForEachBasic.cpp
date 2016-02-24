#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

void printPair(const pair<int, int>& elem)
{
	cout << elem.first << "->" << elem.second << endl;
}

int main()
{
	map<int, int> m;

	// normal
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(6, 60));

	for_each(m.cbegin(), m.cend(), printPair);

	// lambda
	map<int, int> m1 = {{4, 40}, {5, 50}, {6, 60}};
	for_each(m1.cbegin(), m1.cend(), [](const pair<int, int>& p) {
		cout << p.first << "->" << p.second << endl;
	});

	return 0;
}
