#include <iostream>

using namespace std;

void incr(int& value)
{
	cout << "increment with lvalue reference" << endl;
	++value;
}

void incr(int&& value)
{
	cout << "increment with rvalue reference" << endl;
	++value;
}

int main()
{
	int a = 10, b = 20;

	// Increment a named variable
	incr(a);
	cout << "a= " << a << ", b=" << b << endl;

	// Increment an expression
	incr(a + b);
	cout << "a= " << a << ", b=" << b << endl;

	// Increment a literal
	incr(3);
	cout << "a= " << a << ", b=" << b << endl;

	// Increment a named variable and force to use rvalue reference method
	incr(std::move(b));
	cout << "a= " << a << ", b=" << b << endl;

	return 0;
}
