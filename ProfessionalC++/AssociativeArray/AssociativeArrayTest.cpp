#include "AssociativeArray.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	AssociativeArray arr;
	arr["Key1"] = 11;
	arr["Key2"] = 22;
	arr["Key3"] = 33;

	try
	{
		cout << arr["Key1"] << endl;
		cout << arr["Key2"] << endl;

		const AssociativeArray& c = arr;
		cout << c["Key3"] << endl;
		cout << c["Key4"] << endl;
	}
	catch (const invalid_argument& ex)
	{
		cout << "Caught exception: " << ex.what() << endl;
	}

	return 0;
}
