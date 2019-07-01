#include <cassert>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Graph
{
public:
	struct Node
	{
		std::vector<Node*> connected_nodes;
		T data;

		explicit Node(const T & the_data) : data{the_data} {}

		void add_connection(Node & node)
		{
			connected_nodes.push_back(&node);
		}

		bool operator==(const Node & other) const
		{
			return data == other.data;
		}
		bool operator==(const T & other_data) const
		{
			return data == other_data;
		}
	};
	
private:
	std::vector<Node> nodes_;

public:
	bool empty() const
	{
		return nodes_.empty();
	}

	bool contains(const T & data)
	{
		auto iter = find(data);
		return iter != end(nodes_);
	}

	Node & get(const T & data)
	{
		auto iter = find(data);
		if (iter == end(nodes_)) throw std::out_of_range("node not found");
		return *iter;
	}

	Node & add(const T & data)
	{
		if (contains(data)) return get(data);

		nodes_.emplace_back(data);
		return nodes_.back();
	}

private:
	auto find(const T & data)
	{
		return std::find(begin(nodes_), end(nodes_), data);
	}
};
