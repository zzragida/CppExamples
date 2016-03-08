#include <iostream>

using namespace std;

typedef bool(*YesNoFunc)(int, int);

bool intEqual(int item1, int item2)
{
	return item1 == item2;
}

bool bothOdd(int item1, int item2)
{
	return item1 % 2 == 1 && item2 % 2 == 1;
}

void findMatches(int values1[], int values2[], size_t numValues, YesNoFunc inFunc)
{
	for (size_t i = 0; i < numValues; i++) {
		if (inFunc(values1[i], values2[i])) {
			cout << "Match found at position " << i 
					 << " (" << values1[i] << ", " << values2[i] << ")" << endl;
		}
	}
}

int main()
{
	int arr1[] = {2, 5, 6, 9, 10, 1, 1};
	int arr2[] = {4, 4, 2, 9, 0, 3, 4};
	int arrSize = sizeof(arr1) / sizeof(arr1[0]);

	cout << "Calling findMatches() using intEqual():" << endl;
	findMatches(arr1, arr2, arrSize, &intEqual);

	cout << endl;

	cout << "Calling findMatches() using bothOdd():" << endl;
	findMatches(arr1, arr2, arrSize, &bothOdd);

	return 0;
}
