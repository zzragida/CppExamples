#include "Muffin.h"

using namespace std;

string Muffin::getDescription() const
{
	return mDesc;
}

void Muffin::setDescription(const string& inDesc)
{
	mDesc = inDesc;
}

int Muffin::getSize() const
{
	return mSize;
}

void Muffin::setSize(int inSize)
{
	mSize = inSize;
}

bool Muffin::getHasChocolateChips() const
{
	return mHasChocolateChips;
}

void Muffin::setHasChocolateChips(bool inChips)
{
	mHasChocolateChips = inChips;
}

void Muffin::output()
{
	printf("%s, Size is %d, %s\n", getDescription().c_str(), getSize(),    
     (getHasChocolateChips() ? "has chips" : "no chips"));
}

Muffin createMuffin(istringstream& inStream)
{
	Muffin muffin;
	
	string description;
	int size;
	bool hasChips;

	inStream >> description >> size >> boolalpha >> hasChips;
	muffin.setSize(size);
	muffin.setDescription(description);
	muffin.setHasChocolateChips(hasChips);

	return muffin;
}
