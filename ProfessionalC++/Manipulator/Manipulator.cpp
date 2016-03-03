#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main()
{
	bool myBool = true;
	cout << "This is the default: " << myBool << endl;
	cout << "This should be true: " << boolalpha << myBool << endl;
	cout << "This should be 1: " << noboolalpha << myBool << endl;

	// Simulate "%6d" with streams
	int i = 123;
	printf("This should be '   123': %6d\n", i);
	cout << "This should be '   123': " << setw(6) << i << endl;

	// Simulate "%06d" with streams
	printf("This should be '000123': %06d\n", i);
	cout << "This should be '000123': " << setfill('0') << setw(6) << i << endl;
	// Fill with *
	cout << "This should be '***123': " << setfill('*') << setw(6) << i << endl;

	// Reset fill character
	cout << setfill(' ');

	// Use methods
	cout.precision(5);
	cout << "This should be '1.2346': " << 1.234567 << endl;

	// Floating point values
	double dbl = 1.452;
	double dbl2 = 5;
	cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl;
	cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl;

	// Format numbers according to your location
	cout.imbue(locale(""));
	cout << "This is 1234567 formatted according to your localtion: " << 1234567 << endl;

	return 0;
}
