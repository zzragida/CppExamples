#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{	
	vector<int> vec = {1,2};
	list<int> list = {5,6,7,8,9};

	if (list.size() < vec.size())
	{
		return 1;
	}

	return 0;
}
