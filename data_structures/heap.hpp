#include <cassert>
#include <functional>
#include <utility>
#include <vector>

namespace
{
	size_t get_index_left  (const size_t index) { return index * 2 + 1; }
	size_t get_index_right (const size_t index) { return index * 2 + 2; }
	size_t get_index_parent(const size_t index) { return (index - 1) / 2; }
}

template <typename T, typename Comparator>
class Heap
{
private:
	std::vector<T> nodes_;

public:
	bool empty() const
	{
		return nodes_.empty();
	}

	T & peek()
	{
		assert(not empty());
		return nodes_.front();
	}

	const T & peek() const
	{
		return peek();
	}

	void push(const T & data)
	{
		nodes_.push_back(data);
		heapify_up();
	}

	void pop()
	{
		assert(not empty());
		using std::swap;
		swap(nodes_.front(), nodes_.back());
		nodes_.pop_back();
		heapify_down();
	}

private:
	bool has_child_left (const size_t index) const { return get_index_left(index) < nodes_.size(); }
	bool has_child_right(const size_t index) const { return get_index_right(index) < nodes_.size(); }
	bool has_parent     (const size_t index) const { return index > 0; }

	T & get_child_left (const size_t index) { assert(has_child_left(index));  return nodes_[get_index_left(index)]; }
	T & get_child_right(const size_t index) { assert(has_child_right(index)); return nodes_[get_index_right(index)]; }
	T & get_parent     (const size_t index) { assert(has_parent(index));      return nodes_[get_index_parent(index)]; }

	void heapify_up()
	{
		auto index = nodes_.size() - 1;

		while (has_parent(index))
		{
			const auto parent_index = get_index_parent(index);
			if (nodes_[index] < nodes_[parent_index])
			{
				using std::swap;
				swap(nodes_[index], nodes_[parent_index]);
			}
			index = parent_index;
		}
	}

	void heapify_down()
	{
		auto index = 0;

		while (has_child_left(index))
		{
			// which child is smaller?
			auto child_index = get_index_left(index);
			if (has_child_right(index))
			{
				if (Comparator()(get_child_right(index), get_child_left(index)))
				{
					child_index = get_index_right(index);
				}
			}

			if (not Comparator()(nodes_[index], nodes_[child_index]))
			{
				using std::swap;
				swap(nodes_[index], nodes_[child_index]);
			}

			index = child_index;
		}
	}
};

template <typename T>
using MinHeap = Heap<T, std::less<T>>;

template <typename T>
using MaxHeap = Heap<T, std::greater<T>>;
