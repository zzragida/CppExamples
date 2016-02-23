#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	vector<double> doubleVector(10);
	double max = numeric_limits<double>::lowest();

	for (size_t i = 0; true; i++)
	{
		double temp;
		cout << "Enter score " << i + 1 << ": ";
		cin >> temp;
		if (temp == -1)
		{
			break;
		}

		doubleVector.push_back(temp);
		if (temp > max)
		{
			max = temp;
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
