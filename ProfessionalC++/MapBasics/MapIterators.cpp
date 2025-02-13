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

	for (auto iter = dataMap.cbegin(); iter != dataMap.cend(); ++iter)
	{
		cout << iter->second.getVal() << endl;
	}

	for (auto& p : dataMap)
	{
		cout << p.second.getVal() << endl;
	}

	for (map<int, Data>::const_iterator iter = dataMap.begin();
			 iter != dataMap.end(); ++iter)
	{
		cout << iter->second.getVal() << endl;
	}

	return 0;
}
