#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
	virtual string getDescription() { return "Book"; }
	virtual int getHeight() { return 120; }
};

class Paperback : public Book
{
public:
	virtual string getDescription()
	{
		return "Paperback " + Book::getDescription();
	}
};

class Romance : public Paperback
{
public:
	virtual string getDescription()
	{
		return "Romance " + Paperback::getDescription();
	}
	virtual int getHeight() { return Paperback::getHeight() / 2; }
};

class Technical : public Book
{
public:
	virtual string getDescription()
	{
		return "Technical " + Book::getDescription();
	}
};


int main()
{
	Romance novel;
	Book book;

	cout << novel.getDescription() << endl;
	cout << book.getDescription() << endl;
	cout << novel.getHeight() << endl;
	cout << book.getHeight() << endl;

	return 0;
}
