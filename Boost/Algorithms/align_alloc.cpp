#include <boost/align/aligned_alloc.hpp>

int main()
{
	void* p = boost::alignment::aligned_alloc(16, 100);
	if (p)
	{
		boost::alignment::aligned_free(p);
	}
	return 0;
}
