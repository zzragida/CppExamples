#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class SumAndProd : public unary_function<int, void>
{
public:
	SumAndProd() : sum(0), prod(1) {}
	void operator()(int elem)
	{
		sum += elem;
		prod *= elem;
	}

	int sum;
	int prod;
};

int main()
{
	vector<int> vec = {1,2,3,4,5};

	// normal
	SumAndProd func;
	func = for_each(vec.cbegin(), vec.cend(), func);
	cout << "The sum is " << func.sum << endl;
	cout << "The product is " << func.prod << endl;

	// lambda
	int sum = 0;
	int prod = 1;
	for_each(vec.cbegin(), vec.cend(),
		[&](int i){ sum += i; prod *= i; });

	return 0;
}
