#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void readIntegerFile(const string& fileName, vector<int>& dest)
	throw (invalid_argument, runtime_error)
{
	ifstream istr;
	int temp;

	istr.open(fileName.c_str());
	if (istr.fail())
	{
		string error = "Unable to open file " + fileName;
		throw invalid_argument(error);
	}

	while (istr >> temp)
	{
		dest.push_back(temp);
	}

	if (istr.eof())
	{
		istr.close();
	}
	else
	{
		istr.close();
		string error = "Unable to read file " + fileName;
		throw runtime_error(error);
	}
}

int main()
{
	vector<int> myInts;
	const string fileName = "IntegerFile.txt";

	try
	{
		readIntegerFile(fileName, myInts);
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << endl;
		return 1;
	}
	catch (const runtime_error& e)
	{
		cerr << e.what() << endl;
		return 1;
	}

	for (size_t i = 0; i < myInts.size(); i++)
	{
		cout << myInts[i] << " ";
	}
	cout << endl;

	return 0;
}
