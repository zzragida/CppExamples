#include <utility>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	pair<string, int> myPair("hello", 5), myOtherPair;

	myOtherPair.first = "hello";
	myOtherPair.second = 6;

	pair<string, int> myThirdPair(myOtherPair);

	if (myPair < myOtherPair)
	{
		cout << "myPair is less than myOtherPair" << endl;
	}
	else
	{
		cout << "myPair is greater than or equal to myOtherPair" << endl;
	}

	if (myOtherPair == myThirdPair)
	{
		cout << "myOhterPair is equal to myThirdPair" << endl;
	}
	else
	{
		cout << "myOtherPair is not equal to myThirdPair" << endl;
	}

	pair<int, int> aPair = make_pair(5, 10);
	auto sSecondPair = make_pair(5, 10);

	return 0;
}
