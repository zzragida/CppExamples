#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vectorOne = {1,2,3,4,5};
	vector<int> vectorTwo = {6,7,8,9,0};
	vector<int> vectorMerged;

	// sort
	sort(vectorOne.begin(), vectorOne.end());
	sort(vectorTwo.begin(), vectorTwo.end());

	vectorMerged.resize(vectorOne.size() + vectorTwo.size());
	merge(vectorOne.cbegin(), vectorOne.cend(),
				vectorTwo.cbegin(), vectorTwo.cend(),
				vectorMerged.begin());
	cout << "Merged vector: ";
	for_each(vectorMerged.cbegin(), vectorMerged.cend(), [](int i){ cout << i << " "; });
	cout << endl;

	int num = 5;
	if (binary_search(vectorMerged.cbegin(), vectorMerged.cend(), num))
	{
		cout << num << " is in the vector" << endl;
	}
	else
	{
		cout << num << " is not in the vector" << endl;
	}

	return 0;
}
