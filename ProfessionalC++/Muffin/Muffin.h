#include <iostream>
#include <sstream>
#include <string>

class Muffin
{
public:
	std::string getDescription() const;
	void setDescription(const std::string& inDesc);
	int getSize() const;
	void setSize(int inSize);
	bool getHasChocolateChips() const;
	void setHasChocolateChips(bool inChips);

	void output();

protected:
	std::string mDesc;
	int mSize;
	bool mHasChocolateChips;
};

Muffin createMuffin(std::istringstream& inStream);
