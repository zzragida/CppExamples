#include "AssociativeArray.h"
#include <stdexcept>

using namespace std;

AssociativeArray::AssociativeArray()
{
}

AssociativeArray::~AssociativeArray()
{
}

int& AssociativeArray::operator[](const std::string& key)
{
	for (auto iter = mData.begin(); iter != mData.end(); ++iter)
	{
		if (iter->mKey == key)
			return iter->mValue;
	}
	return mData.insert(mData.end(), Element(key, 0))->mValue;
}

const int& AssociativeArray::operator[](const std::string& key) const
{
	for (auto iter = mData.begin(); iter != mData.end(); ++iter)
	{
		if (iter->mKey == key)
			return iter->mValue;
	}
	throw invalid_argument("Key '" + key + "' doesn't exist");
}
