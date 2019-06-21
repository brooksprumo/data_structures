#include <cassert>

template <typename T>
class BinaryTree
{
	struct Node
	{
		Node * left = nullptr;
		Node * right = nullptr;
		T data;

		explicit Node(const T & the_data) : data{the_data} {}

		void insert(const T & the_data)
		{
			if (the_data < data)
			{
				if (left == nullptr)
				{
					left = new Node(the_data);
				}
				else
				{
					left->insert(the_data);
				}
			}
			else
			{
				if (right == nullptr)
				{
					right = new Node(the_data);
				}
				else
				{
					right->insert(the_data);
				}
			}
		}

		bool contains(const T & the_data) const
		{
			if (the_data == data)
			{
				return true;
			}
			else if (the_data < data)
			{
				if (left == nullptr)
				{
					return false;
				}
				else
				{
					return left->contains(the_data);
				}
			}
			else
			{
				if (right == nullptr)
				{
					return false;
				}
				else
				{
					return right->contains(the_data);
				}
			}
		}
	};
	
private:
	Node * root_ = nullptr;

public:
	~BinaryTree()
	{
		if (empty())
		{
			return;
		}

		delete_node(root_);
		root_ = nullptr;
	}

	bool empty() const
	{
		return root_ == nullptr;
	}

	void insert(const T & data)
	{
		if (empty())
		{
			root_ = new Node(data);
			return;
		}

		root_->insert(data);
	}

	bool contains(const T & data) const
	{
		if (empty())
		{
			return false;
		}
		
		return root_->contains(data);
	}

private:
	void delete_node(Node * node)
	{
		if (node->left != nullptr)
		{
			delete_node(node->left);
		}
		if (node->right != nullptr)
		{
			delete_node(node->right);
		}
		delete node;
	}
};
