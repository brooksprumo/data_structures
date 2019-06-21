#include "list.hpp"
#include <cassert>

template <typename T>
class Stack
{
private:
	List<T> list_;

public:
	bool empty() const
	{
		return list_.empty();
	}

	void push(const T & data)
	{
		list_.push_front(data);
	}

	T & pop()
	{
		assert(not empty());
		T & data = list_.peek_front();
		list_.pop_front();
		return data;
	}

	T & peek()
	{
		assert(not empty());
		return list_.peek_front();
	}

	const T & peek() const
	{
		return peek();
	}
};
