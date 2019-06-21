#include <data_structures/binary_tree.hpp>
#include <catch2/catch.hpp>

TEST_CASE("BinaryTree is empty")
{
	BinaryTree<int> t;

	REQUIRE(t.empty());
}

TEST_CASE("BinaryTree can insert")
{
	BinaryTree<int> t;

	t.insert(1);
	REQUIRE_FALSE(t.empty());

	t.insert(2);
	REQUIRE_FALSE(t.empty());

	t.insert(3);
	REQUIRE_FALSE(t.empty());

	t.insert(4);
	REQUIRE_FALSE(t.empty());
}

TEST_CASE("BinaryTree can check contents")
{
	BinaryTree<int> t;

	t.insert(5);
	t.insert(3);
	t.insert(8);
	t.insert(4);
	t.insert(9);
	t.insert(1);
	t.insert(6);
	t.insert(7);
	t.insert(2);

	REQUIRE(t.contains(1));
	REQUIRE(t.contains(2));
	REQUIRE(t.contains(3));
	REQUIRE(t.contains(4));
	REQUIRE(t.contains(5));
	REQUIRE(t.contains(6));
	REQUIRE(t.contains(7));
	REQUIRE(t.contains(8));
	REQUIRE(t.contains(9));
}

TEST_CASE("BinaryTree destructor clears tree")
{
	BinaryTree<int> t;
	t.insert(1);
	t.insert(2);
	t.insert(3);
	t.insert(4);
	t.insert(5);
	REQUIRE_FALSE(t.empty());

	t.~BinaryTree();
	REQUIRE(t.empty());
}
