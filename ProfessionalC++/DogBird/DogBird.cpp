#include <iostream>

using namespace std;

class Dog
{
public:
	virtual void bark() { cout << "woof!" << endl; }
	virtual void eat() { cout << "The dog has eaten." << endl; }
};

class Bird
{
public:
	virtual void chirp() { cout << "chirp!" << endl; }
	virtual void eat() { cout << "The bird has eaten." << endl; }
};

class DogBird : public Dog, public Bird
{
};


int main()
{
	DogBird animal;

	animal.bark();
	animal.chirp();
	//animal.eat(); // Ambiguous call to method eat()
	static_cast<Dog>(animal).eat();
	animal.Dog::eat();

	return 0;
}
