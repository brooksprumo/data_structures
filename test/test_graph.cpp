#include <data_structures/graph.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Graph is empty")
{
	Graph<int> g;

	REQUIRE(g.empty());
}

TEST_CASE("Graph can add")
{
	Graph<int> g;

	g.add(1);
	REQUIRE_FALSE(g.empty());
}

TEST_CASE("Graph can check contents")
{
	Graph<int> g;

	g.add(2);
	REQUIRE(g.contains(2));
	REQUIRE_NOTHROW(g.get(2));

	REQUIRE_FALSE(g.contains(3));
	REQUIRE_THROWS(g.get(3));
}

TEST_CASE("Graph can add connections")
{
	Graph<int> g;
	auto & node1 = g.add(1);
	auto & node2 = g.add(2);
	node1.add_connection(node2);

	REQUIRE(*node1.connected_nodes[0] == node2);
}
