#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

template<class T>
void fillVector(vector<int>& vec, T rndGen)
{
	generate(vec.begin(), vec.end(), rndGen);
}

int main()
{
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(1, 99);
	auto gen = bind(dist, eng);
	vector<int> vec(10);
	
	fillVector(vec, gen);
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	return 0;
}
