#include <string>

using std::string;

class SpreadsheetCell
{
public:
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(const string& initialValue);
	SpreadsheetCell(const SpreadsheetCell& src);
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	void set(double inValue);
	void set(const string& inString);

	double getValue() const { mNumAccesses++; return (mValue); }
	string getString() const { mNumAccesses++; return (mString); }

	static string doubleToString(double inValue);
};
