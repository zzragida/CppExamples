#include <iostream>
#include <functional>

using namespace std;

void high_order_lambda_expressions()
{
    auto addtwointegers = [](int x) -> function<int(int)> {
        return [=](int y) { return x + y; };
    };

    auto higherorder = [](const function<int(int)>& f, int z) {
        return f(z) * 2;
    };

    auto answer = higherorder(addtwointegers(7), 8);

    cout << answer << endl;
}