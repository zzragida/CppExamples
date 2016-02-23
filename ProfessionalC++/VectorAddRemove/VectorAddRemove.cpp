#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

void printVector(const vector<int>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	vector<int> vectorOne = {1,2,3,5};
	vector<int> vectorTwo;

	vectorOne.insert(vectorOne.begin() + 3, 4);

	for (int i = 6; i <= 10; i++)
	{
		vectorTwo.push_back(i);
	}

	printVector(vectorOne);
	printVector(vectorTwo);

	vectorOne.insert(vectorOne.end(), vectorTwo.begin(), vectorTwo.end());
	printVector(vectorOne);

  vectorOne.erase(vectorOne.begin() + 1, vectorOne.begin() + 5);
  printVector(vectorOne);

  vectorTwo.clear();

  vectorTwo.insert(vectorTwo.begin(), 10, 100);

  vectorTwo.pop_back();

  printVector(vectorTwo);

	return 0;
}
