#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	vector<string> stringVector(10, "hello");
	
	for (auto it = stringVector.cbegin();
			 it != stringVector.cend(); ++it)
	{
		cout << *it << endl;
	}
}
