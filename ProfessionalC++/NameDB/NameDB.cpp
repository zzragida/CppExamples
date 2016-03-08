#include "NameDB.h"
#include <fstream>

using namespace std;

NameDB::NameDB(const string& nameFile) throw (invalid_argument)
{
	ifstream inFile(nameFile.c_str());
	if (!inFile) {
		throw invalid_argument("Unable to open file");
	}

	string name;
	while (inFile >> name) {
		if (!nameExistsAndIncrement(name)) {
			addNewName(name);
		}
	}
	inFile.close();
}

bool NameDB::nameExistsAndIncrement(const string& name)
{
	auto res = mNames.find(name);
	if (res != mNames.end()) {
		res->second++;
		return true;
	}
	return false;
}

void NameDB::addNewName(const string& name)
{
	mNames[name] = 1;
}

int NameDB::getNameRank(const string& name) const
{
	int num = getAbsoluteNumber(name);
	if (num == -1) {
		return -1;
	}

	int rank = 1;
	for (auto it = mNames.cbegin(); it != mNames.cend(); ++it) {
		if (it->second > num) {
			rank++;
		}
	}

	return rank;
}

int NameDB::getAbsoluteNumber(const string& name) const
{
	auto res = mNames.find(name);
	if (res != mNames.end()) {
		return res->second;
	}
	return -1;
}
