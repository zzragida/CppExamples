#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> intVector;

	auto it = intVector.end();
	*it = 10;

	vector<int> vectorOne(10);
	vector<int> vectorTwo(10);

	for (auto it = vectorTwo.begin(); it != vectorOne.end(); ++it)
	{
	}
}
