#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void calling_lambda_expressions1()
{
    int n = [](int x, int y) { return x + y; }(5, 4);
    cout << n << endl;
}

void calling_lambda_expressions2()
{
    list<int> numbers;
    numbers.push_back(13);
    numbers.push_back(17);
    numbers.push_back(42);
    numbers.push_back(46);
    numbers.push_back(99);

    const list<int>::const_iterator result =
        find_if(numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });

    if (result != numbers.end())
    {
        cout << "The first even number in the list is " << *result << endl;
    }
    else
    {
        cout << "The list contains no even numbers." << endl;
    }
}