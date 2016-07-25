// File: vector_unittest.cpp

#include "vector.hpp"
#include "catch_test_wrapper.hpp"


TEST_CASE("vectors can be constructed", "[Vector]")
{
	Vector<int> v;
	
	REQUIRE(v.size() == 0);
}


TEST_CASE("Vector can push back elements", "[Vector]")
{
	Vector<int> v;

	REQUIRE(v.size() == 0);

	SECTION("pushing back items changes the size")
	{
		v.push_back(0);

		REQUIRE(v.size() == 1);

		v.push_back(1);

		REQUIRE(v.size() == 2);

		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		REQUIRE(v.size() == 5);
	}

	SECTION("pushing back items puts them on the back of the Vector")
	{
		v.push_back(0);

		REQUIRE(v[0] == 0);

		v.push_back(1);

		REQUIRE(v[0] == 0);
		REQUIRE(v[1] == 1);
	}
}


TEST_CASE("Vector can push back Vectors", "[Vector]")
{
	Vector<int> v;
	REQUIRE(v.size() == 0);

	Vector<int> to_push_back;
	to_push_back.push_back(0);
	to_push_back.push_back(1);

	SECTION("pushing back Vectors changes the size")
	{
		v.push_back(to_push_back);
		REQUIRE(v.size() == to_push_back.size());

		v.push_back(to_push_back);
		REQUIRE(v.size() == 2 * to_push_back.size());
	}

	SECTION("pushing back Vectors puts them on the back of the Vector")
	{
		v.push_back(to_push_back);

		REQUIRE(v[0] == to_push_back[0]);
		REQUIRE(v[1] == to_push_back[1]);

		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		REQUIRE(v.size() == 5);
	}
}


TEST_CASE("Vector can pop_back elements", "[Vector]")
{
	Vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	REQUIRE(v.size() == 6);

	SECTION("popping back items changes the size")
	{
		v.pop_back();

		REQUIRE(v.size() == 5);

		v.pop_back(); 
		v.pop_back();
		
		REQUIRE(v.size() == 3);
	}

	SECTION("popping back items takes them off the back of the Vector")
	{
		v.pop_back();

		REQUIRE(v.size() == 5);
		REQUIRE(v[0] == 0);
		REQUIRE(v[1] == 1);
		REQUIRE(v[2] == 2);
		REQUIRE(v[3] == 3);
		REQUIRE(v[4] == 4);

		v.pop_back();
		v.pop_back();

		REQUIRE(v.size() == 3);
		REQUIRE(v[0] == 0);
		REQUIRE(v[1] == 1);
		REQUIRE(v[2] == 2);

		v.pop_back();
		v.pop_back();
		v.pop_back();

		REQUIRE(v.size() == 0);
	}
}


TEST_CASE("Vector can be cleared", "[Vector]")
{
	Vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	REQUIRE(v.size() == 6);

	SECTION("Clearing items changes the size")
	{
		v.clear();

		REQUIRE(v.size() == 0);
	}

	SECTION("Pushing back onto a cleared vector changes size and items")
	{
		v.clear();
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);

		REQUIRE(v.size() == 3);
		REQUIRE(v[0] == 6);
		REQUIRE(v[1] == 7);
		REQUIRE(v[2] == 8);
	}
}


TEST_CASE("Vector elements can be set with operator[]", "[Vector]")
{
	Vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	REQUIRE(v.size() == 5);

	v[0] = 5;

	REQUIRE(v.size() == 5);
	REQUIRE(v[0] == 5);
	REQUIRE(v[1] == 1);
	REQUIRE(v[2] == 2);
	REQUIRE(v[3] == 3);
	REQUIRE(v[4] == 4);

	v[1] = 6;
	v[2] = 7;
	v[3] = 8;
	v[4] = 9;

	REQUIRE(v.size() == 5);
	REQUIRE(v[0] == 5);
	REQUIRE(v[1] == 6);
	REQUIRE(v[2] == 7);
	REQUIRE(v[3] == 8);
	REQUIRE(v[4] == 9);
}


TEST_CASE("Vector can be resized", "[Vector]")
{
	Vector<int> v;

	REQUIRE(v.size() == 0);

	SECTION("can increase size by resizing")
	{
		v.resize(5);
		REQUIRE(v.size() == 5);
	}

	SECTION("can increase with all new element")
	{
		v.resize(5, -1);
		REQUIRE(v.size() == 5);
		REQUIRE(v[0] == -1);
		REQUIRE(v[1] == -1);
		REQUIRE(v[2] == -1);
		REQUIRE(v[3] == -1);
		REQUIRE(v[4] == -1);
	}

	SECTION("can increase with some new elements")
	{
		v.resize(5, -1);
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		REQUIRE(v.size() == 10);
		REQUIRE(v[0] == -1);
		REQUIRE(v[1] == -1);
		REQUIRE(v[2] == -1);
		REQUIRE(v[3] == -1);
		REQUIRE(v[4] == -1);
		REQUIRE(v[5] == 0);
		REQUIRE(v[6] == 1);
		REQUIRE(v[7] == 2);
		REQUIRE(v[8] == 3);
		REQUIRE(v[9] == 4);
		
	}

	SECTION("can decrease size with resize")
	{
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		REQUIRE(v.size() == 5);

		v.resize(3, -1);
		REQUIRE(v[0] == 0);
		REQUIRE(v[1] == 1);
		REQUIRE(v[2] == 2);

		v.resize(1);
		REQUIRE(v[0] == 0);
	}
}
