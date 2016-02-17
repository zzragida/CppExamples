#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<string> myVector = {"A first string", "A second string"};
	myVector.push_back("A third string");
	myVector.push_back("The last string in the vector");

	for (auto iterator = myVector.begin(); iterator != myVector.end(); ++iterator)
	{
		cout << *iterator << endl;
	}

	for (auto& str : myVector)
	{
		cout << str << endl;
	}

	return 0;
}
