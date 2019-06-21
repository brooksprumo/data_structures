#include <data_structures/heap.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Heap is empty")
{
	MinHeap<int> h;

	REQUIRE(h.empty());
}

TEST_CASE("Heap can push and pop")
{
	MinHeap<int> h;

	h.push(1);
	REQUIRE_FALSE(h.empty());

	h.push(2);
	REQUIRE_FALSE(h.empty());

	h.pop();
	REQUIRE_FALSE(h.empty());

	h.pop();
	REQUIRE(h.empty());
}

TEST_CASE("Heap can peek")
{
	MinHeap<int> h;
	h.push(1);
	h.push(2);
	REQUIRE_FALSE(h.empty());
	REQUIRE(h.peek() == 1);

	h.pop();
	REQUIRE_FALSE(h.empty());
	REQUIRE(h.peek() == 2);
}

TEST_CASE("Heap heapifies correctly")
{
	MinHeap<int> h;

	h.push(9);
	REQUIRE(h.peek() == 9);

	h.push(5);
	REQUIRE(h.peek() == 5);

	h.push(7);
	REQUIRE(h.peek() == 5);

	h.push(4);
	REQUIRE(h.peek() == 4);

	h.push(6);
	REQUIRE(h.peek() == 4);

	h.push(8);
	REQUIRE(h.peek() == 4);

	h.push(2);
	REQUIRE(h.peek() == 2);

	h.push(3);
	REQUIRE(h.peek() == 2);

	h.push(1);
	REQUIRE(h.peek() == 1);

	h.pop();
	REQUIRE(h.peek() == 2);

	h.pop();
	REQUIRE(h.peek() == 3);

	h.pop();
	REQUIRE(h.peek() == 4);

	h.pop();
	REQUIRE(h.peek() == 5);

	h.pop();
	REQUIRE(h.peek() == 6);

	h.pop();
	REQUIRE(h.peek() == 7);

	h.pop();
	REQUIRE(h.peek() == 8);

	h.pop();
	REQUIRE(h.peek() == 9);
}
