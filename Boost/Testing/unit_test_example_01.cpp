#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test1 )
{
	BOOST_TEST( 2 == 1 );
}


BOOST_AUTO_TEST_CASE( test2 )
{
	int i = 0;

	BOOST_TEST( i == 2 );
	BOOST_TEST( i == 0 );
}
