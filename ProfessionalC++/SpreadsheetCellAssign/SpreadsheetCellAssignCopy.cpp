#include "SpreadsheetCell.h"

int main()
{
	SpreadsheetCell myCell(5);
	SpreadsheetCell anotherCell(myCell);
	SpreadsheetCell aThirdCell = myCell;
	anotherCell = myCell;

	SpreadsheetCell myCell2(5);
	string s1;
	s1 = myCell2.getString();

	SpreadsheetCell myCell3(5);
	string s2 = myCell3.getString();

	return 0;
}
