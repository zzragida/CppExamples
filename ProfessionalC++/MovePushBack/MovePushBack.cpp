#include <vector>
#include <string>

using namespace std;

class Element
{
public:
	Element(int i, string str) : mI(i), mStr(str) {}

protected:
	int mI;
	string mStr;
};

int main()
{
	vector<Element> vec;

	Element myElement(12, "Twelve");
	vec.push_back(myElement);

	vec.push_back(Element(12, "Twelve"));
	vec.push_back({12, "Twelve"});

	return 0;
}
