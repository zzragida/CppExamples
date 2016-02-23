#include <vector>
#include <string>
#include <memory>

using namespace std;

class Element
{
public:
	Element() {}
	virtual ~Element() {}
};


int main()
{
	// Builtin classes
	vector<string> stringVector1(10, "hello");

	// Default ctor
	vector<int> intVector1;

	// Heap vector
	vector<Element>* elementVector1 = new vector<Element>(10);
	delete elementVector1;

	// Heap vector with smart pointer
	shared_ptr<vector<Element>> elementVector2(new vector<Element>(10));

	// Initialize Elements
	vector<int> intVector2(10, 100);

	// initializer_list
	vector<int> intVector3({1,2,3,4,5,6,});

	// Uniform initialization
	vector<int> intVector4 = {1,2,3,4,5,6};

	// User defined classes
	vector<Element> elementVector3;

	return 0;
}
