#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Scale
{
public:
    explicit Scale(int scale) : _scale(scale) {}

    void ApplyScale(const vector<int>& v) const
    {
        for_each(v.begin(), v.end(), [=](int n) { cout << n * _scale << endl; });
    }

private:
    int _scale;
};

void function_lambda_expression()
{
    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);

    Scale s(3);
    s.ApplyScale(values);
}