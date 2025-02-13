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
	dataMap[1] = Data(4);
	dataMap[1] = Data(6);

	auto it = dataMap.find(1);
	if (it != dataMap.end())
	{
		it->second.setVal(100);
	}

	return 0;
}
