#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	vector<double> doubleVector(10, 0.0);
	double max = numeric_limits<double>::lowest();

	for (size_t i = 0; i < 10; i++)
	{
		cout << "Enter score " << i + 1 << ": ";
		cin >> doubleVector[i];
		if (doubleVector[i] > max)
		{
			max = doubleVector[i];
		}
	}

	max /= 100.0;
	for (size_t i = 0; i < 10; i++)
	{
		doubleVector[i] /= max;
		cout << doubleVector[i] << " ";
	}
	cout << endl;

	return 0;
}
