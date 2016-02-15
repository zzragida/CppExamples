#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void eh_lambda_expression()
{
    vector<int> elements(3);

    vector<int> indices(3);
    indices[0] = 0;
    indices[1] = -1;
    indices[2] = 2;

    try
    {
        for_each(indices.begin(), indices.end(), [&](int index) {
            elements.at(index) = index;
        });
    }
    catch (const out_of_range& e)
    {
        cerr << "Caught " << e.what() << endl;
    }
}