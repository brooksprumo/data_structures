#include <data_structures/list.hpp>
#include <catch2/catch.hpp>

TEST_CASE("List is empty")
{
	List<int> l;

	REQUIRE(l.empty());
}

TEST_CASE("List can push and pop front")
{
	List<int> l;

	l.push_front(1);
	REQUIRE_FALSE(l.empty());
	l.push_front(2);
	REQUIRE_FALSE(l.empty());
	REQUIRE(l.peek_front() == 2);
	REQUIRE(l.peek_back() == 1);

	l.pop_front();
	REQUIRE_FALSE(l.empty());
	REQUIRE(l.peek_front() == 1);
	REQUIRE(l.peek_back() == 1);

	l.pop_front();
	REQUIRE(l.empty());
}

TEST_CASE("List can push and pop back")
{
	List<int> l;

	l.push_back(1);
	REQUIRE_FALSE(l.empty());
	l.push_back(2);
	REQUIRE_FALSE(l.empty());
	REQUIRE(l.peek_front() == 1);
	REQUIRE(l.peek_back() == 2);

	l.pop_back();
	REQUIRE_FALSE(l.empty());
	REQUIRE(l.peek_front() == 1);
	REQUIRE(l.peek_back() == 1);

	l.pop_front();
	REQUIRE(l.empty());
}

TEST_CASE("List can peek")
{
	List<int> l;
	l.push_front(1);
	l.push_back(2);
	REQUIRE_FALSE(l.empty());

	REQUIRE(l.peek_front() == 1);
	REQUIRE(l.peek_back() == 2);
}

TEST_CASE("List destructor clears list")
{
	List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	REQUIRE_FALSE(l.empty());

	l.~List();
	REQUIRE(l.empty());
}

TEST_CASE("List can be reversed, empty")
{
	List<int> l;
	REQUIRE(l.empty());

	l.reverse();

	REQUIRE(l.empty());
}

TEST_CASE("List can be reversed, single element")
{
	List<int> l;
	l.push_back(1);
	REQUIRE_FALSE(l.empty());

	l.reverse();

	REQUIRE(l.peek_front() == 1);
}

TEST_CASE("List can be reversed, multiple elements")
{
	List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	REQUIRE_FALSE(l.empty());

	l.reverse();

	REQUIRE(l.peek_front() == 4);
	l.pop_front();
	REQUIRE(l.peek_front() == 3);
	l.pop_front();
	REQUIRE(l.peek_front() == 2);
	l.pop_front();
	REQUIRE(l.peek_front() == 1);
}
