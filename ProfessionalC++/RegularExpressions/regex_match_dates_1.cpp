#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	regex r("^\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])$");
	string str = "2016/03/03";

	if (regex_match(str, r))
		cout << "Valid date" << endl;
	else
		cout << "Invalid date" << endl;

	return 0;
}
