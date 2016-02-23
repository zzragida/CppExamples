#include <map>
#include <iostream>

using namespace std;

class Data
{
public:
	Data(int val = 0) { mVal = val; }
	int getVal() const { return mVal; }
	void setVal(int val) { mVal = val; }

protected:
	int mVal;
};

int main()
{
	map<int, Data> dataMap;

	auto ret = dataMap.insert({1, Data(4)});
	if (ret.second)
	{
		cout << "1. Insert succeeded" << endl;
	}
	else
	{
		cout << "1. Insert failed" << endl;
	}

	ret = dataMap.insert(make_pair(1, Data(6)));
	if (ret.second)
	{
		cout << "2. Insert succeeded" << endl;
	}
	else
	{
		cout << "2. Insert failed" << endl;
	}

	return 0;
}
