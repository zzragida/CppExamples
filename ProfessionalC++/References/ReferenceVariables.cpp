int main()
{
	int x = 3, y = 4, z = 5;
	int& xRef = x;
	xRef = 10;

	const int& unnamedRef2 = 5;

	xRef = y;

	int& zRef = z;
	zRef = xRef;

	int* intP;
	int*& ptrRef = intP;
	ptrRef = new int;
	*ptrRef = 5;

	int* xPtr = &xRef;
	*xPtr = 100;

	return 0;
}
