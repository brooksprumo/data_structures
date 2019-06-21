#include "stack.hpp"
#include <cassert>

// this queue is implemented internally with two stacks
template <typename T>
class Queue2
{
private:
	Stack<T> stack_newest_; // elements are in FIFO order (pop() and peek() from this stack)
	Stack<T> stack_oldest_; // elements are in LIFO order (push() to this stack)

public:
	bool empty() const
	{
		return stack_newest_.empty() and stack_oldest_.empty();
	}

	T & peek()
	{
		assert(not empty());
		if (stack_newest_.empty())
		{
			move_elements_to_newest_stack();
		}
		return stack_newest_.peek();
	}

	void push(const T & data)
	{
		stack_oldest_.push(data);
	}

	T & pop()
	{
		assert(not empty());
		if (stack_newest_.empty())
		{
			move_elements_to_newest_stack();
		}
		return stack_newest_.pop();
	}

private:
	void move_elements_to_newest_stack()
	{
		while (not stack_oldest_.empty())
		{
			stack_newest_.push(stack_oldest_.pop());
		}
	}
};
