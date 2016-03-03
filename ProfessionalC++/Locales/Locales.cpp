#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
	locale loc("");

	if (loc.name().find("en_US") == string::npos &&
			loc.name().find("United States") == string::npos)
	{
		wcout << L"Can't not support U.S." << endl;
	}
	else
	{
		wcout << L"Welcome U.S. English" << endl;
	}

	return 0;
}
