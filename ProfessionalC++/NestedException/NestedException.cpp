#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

class MyException : public exception, public nested_exception
{
public:
	MyException(const char* msg) : mMsg(msg) {}
	virtual ~MyException() noexcept {}
	virtual const char* what() const noexcept { return mMsg.c_str(); }

protected:
	string mMsg;
};

void doSomething()
{
	try
	{
		throw runtime_error("Throwing a runtime_error exception");
	}
	catch (const runtime_error& e)
	{
		cout << __func__ << " caught a runtime_error" << endl;
		cout << __func__ << " throwing MyException" << endl;
		throw_with_nested(MyException("MyException with nested runtime_error"));
	}
}

int main()
{
	try
	{
		doSomething();
	}
	catch (const MyException& e)
	{
		cout << __func__ << " caught MyException: " << e.what() << endl;

		try
		{
			rethrow_if_nested(e);
		}
		catch (const runtime_error& e)
		{
			cout << "\tNested exception: " << e.what() << endl;
		}
	}

	return 0;
}
