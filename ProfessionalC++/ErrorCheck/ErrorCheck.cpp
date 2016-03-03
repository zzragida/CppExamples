#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter number on seperate lines to add."
			 << "Use Control+D to finish (Control+Z in Windows)." << endl;
	int sum = 0;

	if (!cin.good())
	{
		cerr << "Standard input is in a bad state!" << endl;
		return 1;
	}

	int number;
	while (true)
	{
		cin >> number;
		if (cin.good())
		{
			sum += number;
		}
		else if (cin.eof())
		{
			break;
		}
		else
		{
			cin.clear();
			string badToken;
			cin >> badToken;
			cerr << "WARNING: Bad input encountered: " << badToken << endl;
		}
	}

	cout << "The sum is " << sum << endl;
	
	return 0;
}
