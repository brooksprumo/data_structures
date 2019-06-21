#include <data_structures/queue.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Queue is empty")
{
	Queue<int> q;

	REQUIRE(q.empty());
}

TEST_CASE("Queue can push and pop")
{
	Queue<int> q;

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

TEST_CASE("Queue can peek")
{
	Queue<int> q;
	q.push(1);
	q.push(2);

	auto x = q.peek();
	REQUIRE_FALSE(q.empty());
	REQUIRE(x == 1);
}

TEST_CASE("Queue destructor clears stack")
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	REQUIRE_FALSE(q.empty());

	q.~Queue();
	REQUIRE(q.empty());
}
