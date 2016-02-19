#include <boost/lambda/lambda.hpp>
#include <iostream>

using namespace std;
using namespace boost::lambda;

int main()
{
	list<int> v(10);

	for_each(v.begin(), v.end(), cout << _1);

	return 0;
}
