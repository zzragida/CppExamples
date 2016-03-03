#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class MovableClass
{
public:
	MovableClass()
	{
		cout << "Default constructor" << endl;
	}

	MovableClass(const MovableClass& src)
	{
		cout << "Copy constructor" << endl;
	}

	MovableClass(MovableClass&& src)
	{
		cout << "Move constructor" << endl;
	}

	MovableClass& operator=(const MovableClass& rhs)
	{
		cout << "Copy assignment operator" << endl;
		return *this;
	}

	MovableClass& operator=(MovableClass&& rhs)
	{
		cout << "Move assignment operator" << endl;
		return *this;
	}
};

int main()
{
	vector<MovableClass> vec;
	MovableClass mc;

	vec.push_back(mc);
	vec.push_back(mc);

	cout << "-----" << endl;
	vector<MovableClass> vecOne(vec.begin(), vec.end());
	cout << "-----" << endl;
	
	vector<MovableClass> vecTwo(make_move_iterator(vec.begin()),
															make_move_iterator(vec.end()));
	cout << "-----" << endl;

	return 0;
}
