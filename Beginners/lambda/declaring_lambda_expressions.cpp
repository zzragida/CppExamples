#include <functional>
#include <iostream>

using namespace std;

void declaring_lambda_expressions1()
{
    auto f1 = [](int x, int y) { return x + y; };
    cout << f1(2, 3) << endl;

    function<int(int, int)> f2 = [](int x, int y) { return x + y; };
    cout << f2(3, 4) << endl;
}

void declaring_lambda_expressions2()
{
    int i = 3;
    int j = 5;

    function<int(void)> f = [i, &j] { return i + j; };

    i = 22;
    j = 44;

    cout << f() << endl;
}