#include <cassert>

template <typename T>
class List
{
	struct Node
	{
		Node * prev = nullptr;
		Node * next = nullptr;
		T data;

		explicit Node(const T & the_data) : data{the_data} {}
	};
	
private:
	Node * head_ = nullptr;
	Node * tail_ = nullptr;

public:
	~List()
	{
		while (not empty())
		{
			pop_front();
		}
	}

	bool empty() const
	{
		return head_ == nullptr;
	}

	void push_front(const T & the_data)
	{
		if (empty())
		{
			push_empty(the_data);
		}
		else
		{
			auto node = new Node(the_data);
			node->next = head_;
			head_->prev = node;
			head_ = node;
		}
	}

	void push_back(const T & the_data)
	{
		if (empty())
		{
			push_empty(the_data);
		}
		else
		{
			auto node = new Node(the_data);
			node->prev = tail_;
			tail_->next = node;
			tail_ = node;
		}
	}

	void pop_front()
	{
		assert(not empty());
		const auto node = head_;
		head_ = head_->next;
		if (head_ != nullptr)
		{
			head_->prev = nullptr;
		}
		delete node;
	}

	void pop_back()
	{
		assert(not empty());
		const auto node = tail_;
		tail_ = tail_->prev;
		if (tail_ != nullptr)
		{
			tail_->next = nullptr;
		}
		delete node;
	}

	T & peek_front()
	{
		assert(not empty());
		return head_->data;
	}

	const T & peek_front() const
	{
		return peek_front();
	}

	T & peek_back()
	{
		assert(not empty());
		return tail_->data;
	}

	const T & peek_back() const
	{
		return peek_back();
	}

private:
	void push_empty(const T & the_data)
	{
		assert(empty());
		head_ = new Node(the_data);
		tail_ = head_;
	}
};
