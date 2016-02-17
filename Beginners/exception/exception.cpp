#include <iostream>
#include <stdexcept>

double divideNumbers(double inNumerator, double inDenominator)
{
	if (inDenominator == 0)
	{
		throw std::exception();
	}
	return inNumerator / inDenominator;
}

int main()
{
	try
	{
		std::cout << divideNumbers(2.5, 0.5) << std::endl;
		std::cout << divideNumbers(2.5, 0) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Exception caught" << std::endl;
	}

	return 0;
}
