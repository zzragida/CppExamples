#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<double> doubleVector;
	double max = numeric_limits<double>::lowest();

	for (size_t i = 0; true; i++)
	{
		double temp;
		cout << "Enter score " << i + 1 << ": ";
		cin >> temp;
		if (temp > max)
		{
			max = temp;
		}
	}

	max /= 100.0;
	for (vector<double>::iterator iter = doubleVector.begin();
			 iter != doubleVector.end(); ++iter)
	{
		*iter /= max;
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
