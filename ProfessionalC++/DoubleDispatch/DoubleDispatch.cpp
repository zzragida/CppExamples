#include <iostream>

using namespace std;

class Fish;
class Bear;
class Dinosaur;

class Animal
{
public:
	virtual bool eats(const Animal& inPrey) const = 0;

	virtual bool eatenBy(const Bear& inBear) const = 0;
	virtual bool eatenBy(const Fish& inFish) const = 0;
	virtual bool eatenBy(const Dinosaur& inDinosaur) const = 0;
};

class Bear : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const
	{
		return inPrey.eatenBy(*this);
	}

	virtual bool eatenBy(const Bear& inBear) const
	{
		return false;
	}

	virtual bool eatenBy(const Fish& inFish) const
	{
		return false;
	}

	virtual bool eatenBy(const Dinosaur& inDinosaur) const
	{
		return true;
	}
};


class Fish : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const
	{
		return inPrey.eatenBy(*this);
	}

	virtual bool eatenBy(const Bear& inBear) const
	{
		return true;
	}

	virtual bool eatenBy(const Fish& inFish) const
	{
		return true;
	}

	virtual bool eatenBy(const Dinosaur& inDinosaur) const
	{
		return true;
	}
};


class Dinosaur : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const
	{
		return inPrey.eatenBy(*this);
	}

	virtual bool eatenBy(const Bear& inBear) const
	{
		return false;
	}

	virtual bool eatenBy(const Fish& inFish) const
	{
		return false;
	}

	virtual bool eatenBy(const Dinosaur& inDinosaur) const
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
