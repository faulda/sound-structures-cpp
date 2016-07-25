// File: vector_unittest.cpp

#include "array.hpp"
#include "catch_test_wrapper.hpp"


TEST_CASE("Arrays can be constructed", "[Array]")
{
	Array<int> v(1);

	REQUIRE(v.size() == 1);
}


TEST_CASE("Array elements can be set with operator[]", "[Array]")
{
	Array<int> a(5);
	a[0] = 0;
	a[1] = 1; 
	a[2] = 2; 
	a[3] = 3; 
	a[4] = 4; 
	REQUIRE(a.size() == 5);

	a[0] = 5;

	REQUIRE(a.size() == 5);
	REQUIRE(a[0] == 5);
	REQUIRE(a[1] == 1);
	REQUIRE(a[2] == 2);
	REQUIRE(a[3] == 3);
	REQUIRE(a[4] == 4);

	a[1] = 6;
	a[2] = 7;
	a[3] = 8;
	a[4] = 9;

	REQUIRE(a.size() == 5);
	REQUIRE(a[0] == 5);
	REQUIRE(a[1] == 6);
	REQUIRE(a[2] == 7);
	REQUIRE(a[3] == 8);
	REQUIRE(a[4] == 9);
}
