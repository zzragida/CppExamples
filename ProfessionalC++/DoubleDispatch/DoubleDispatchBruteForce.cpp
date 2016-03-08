#include <iostream>
#include <typeinfo>

using namespace std;

class Bear;
class Fish;
class Dinosaur;

class Animal
{
public:
	virtual bool eats(const Animal& inPrey) const = 0;
};

class Bear : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const
	{
		if (typeid(inPrey) == typeid(Bear&)) {
			return false;
		} else if (typeid(inPrey) == typeid(Fish&)) {
			return true;
		} else if (typeid(inPrey) == typeid(Dinosaur&)) {
			return false;
		}
		return false;
	}
};


class Fish : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const
	{
		if (typeid(inPrey) == typeid(Bear&)) {
			return false;
		} else if (typeid(inPrey) == typeid(Fish&)) {
			return true;
		} else if (typeid(inPrey) == typeid(Dinosaur&)) {
			return false;
		}
		return false;
	}
};


class Dinosaur : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const
	{
		return true;
	}
};


int main()
{
	Fish myFish;
	Bear myBear;
	Dinosaur myDino;

	cout << "Fish eats bear? " << myFish.eats(myBear) << endl;
	cout << "Fish eats dino? " << myFish.eats(myDino) << endl;
	cout << "Dino eats bear? " << myDino.eats(myBear) << endl;
	cout << "Bear eats fish? " << myBear.eats(myFish) << endl;

	return 0;
}
