#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename Type>
ostream& operator<<(ostream& os, const vector<Type>& v)
{
	os << "[ ";
	copy(v.begin(), v.end(), ostream_iterator<Type>(os, " "));
	os << "]";
	return os;
}

int main()
{
	auto const succ = [](int x) { return x + 1; };
	vector<int> v1{1, 2, 3, 4};
	vector<int> v2;

	transform(v1.begin(), v1.end(), back_inserter(v2), succ);
	cout << v2 << endl;
}
