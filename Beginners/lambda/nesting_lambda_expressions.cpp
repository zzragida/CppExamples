#include <iostream>

using namespace std;

void nesting_lambda_expressions()
{
    int timestwoplusthree = [](int x) { return [](int y) { return y * 2; }(x)+3; }(5);

    cout << timestwoplusthree << endl;
}