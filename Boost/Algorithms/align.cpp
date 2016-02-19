#include <boost/align/align.hpp>
#include <boost/align/alignment_of.hpp>
#include <new>

struct alignas(16) type 
{
	float data[4];
};

void use(void* ptr, std::size_t size)
{
	auto p = boost::alignment::align(16, sizeof(type), ptr, size);
	if (p) 
	{
		auto q = ::new(p) type;
		q->~type();
	}
}

int main()
{
	char c[64];
	use(c, sizeof c);
}
