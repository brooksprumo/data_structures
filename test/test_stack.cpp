#include <data_structures/stack.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Stack is empty")
{
	Stack<int> s;

	REQUIRE(s.empty());
}

TEST_CASE("Stack can push and pop")
{
	Stack<int> s;

	s.push(1);
	REQUIRE_FALSE(s.empty());

	s.push(2);
	REQUIRE_FALSE(s.empty());

	auto x = s.pop();
	REQUIRE_FALSE(s.empty());
	REQUIRE(x == 2);

	x = s.pop();
	REQUIRE(s.empty());
	REQUIRE(x == 1);
}

TEST_CASE("Stack can peek")
{
	Stack<int> s;
	s.push(1);
	s.push(2);

	auto x = s.peek();
	REQUIRE_FALSE(s.empty());
	REQUIRE(x == 2);
}

TEST_CASE("Stack destructor clears stack")
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	REQUIRE_FALSE(s.empty());

	s.~Stack();
	REQUIRE(s.empty());
}
