#ifndef RD_NODE_HPP
# define RD_NODE_HPP
# include <common.hpp>

namespace ft
{
	template <typename T>
	class bst_node
	{
		public:

		typedef T	value_type;

		value_type value;
		bst_node *parent;
		bst_node *left;
		bst_node *right;
		int color;
	
		bst_node(value_type data, bst_node *parent, bst_node *left, bst_node *right, bool color) : 
			value(data), parent(parent), left(left), right(right), color(color) {}

	};
}


#endif