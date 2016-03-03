#include <iostream>

class Array
{
public:
	Array();
	virtual ~Array();

	int& operator[](size_t x);
	const int& operator[](size_t x) const;

protected:
	static const size_t kAllocSize = 4;
	void resize(size_t newSize);
	void initializeElements();
	int *mElems;
	size_t mSize;

private:
	Array(const Array& src);
	Array& operator=(const Array& rhs);
};
