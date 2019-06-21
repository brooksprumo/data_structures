#include <data_structures/queue2.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Queue2 is empty")
{
	Queue2<int> q;

	REQUIRE(q.empty());
}

TEST_CASE("Queue2 can push and pop")
{
	Queue2<int> q;

	q.push(1);
	REQUIRE_FALSE(q.empty());

	q.push(2);
	REQUIRE_FALSE(q.empty());

	auto x = q.pop();
	REQUIRE_FALSE(q.empty());
	REQUIRE(x == 1);

	x = q.pop();
	REQUIRE(q.empty());
	REQUIRE(x == 2);
}

TEST_CASE("Queue2 can peek")
{
	Queue2<int> q;
	q.push(1);
	q.push(2);

	auto x = q.peek();
	REQUIRE_FALSE(q.empty());
	REQUIRE(x == 1);
}

TEST_CASE("Queue2 destructor clears stack")
{
	Queue2<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	REQUIRE_FALSE(q.empty());

	q.~Queue2();
	REQUIRE(q.empty());
}
