#ifndef SET_RBTREE_HPP
#define SET_RBTREE_HPP
#include <common.hpp>
#include <set_iterator.hpp>


namespace ft
{

	template <typename T, typename Compare = std::less<T> ,typename Alloc = std::allocator<T> ,
			typename Node = ft::bst_node<T>, typename Node_Alloc = std::allocator<Node> >
	class Set_Bst
	{
		public :

			typedef typename T::first_type Key;
			typedef typename T::second_type Value;
			typedef T value_type;
			typedef Node_Alloc  node_alloc;
			typedef Alloc alloc;
			typedef size_t size_type;
			typedef Compare key_compare;
			typedef Node* node_pointer;
			typedef ft::set_iterator<Node, Key> iterator;
			typedef ft::set_iterator<const Node, const Key> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		protected :
	
			key_compare _comp;
			node_alloc _node_alloc;
			Node *_root;
			Node *_nil;


		public :

			Set_Bst (const node_alloc &alloc = node_alloc())
			{
				(void)alloc;
				_nil = _node_alloc.allocate(1);
				_nil->color = BLACK;
				_nil->left = NULL;
				_nil->right = NULL;
				_root = _nil;
				_root->parent = NULL;
				_root->left = _nil;
				_root->right = _nil;
			}

			void right_rotate(Node *x)
			{
				Node *y = x->left;
				x->left = y->right;
				if (y->right != _nil)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			void left_rotate(Node *x)
			{
				/* rotate Y (X->right) with X*/
				Node *y = x->right;
				// x takes y's left child
				x->right = y->left;
				// update y's left child's parent (X)
				if (y->left != _nil)
					y->left->parent = x;
				// Y takes X's parent
				y->parent = x->parent;
				// if X's parent is NULL, Y is the new root
				if (x->parent == NULL)
					_root = y;
				// update X's parent's child with Y
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				// X becomes Y's left child
				y->left = x;
				// update X's parent with Y
				x->parent = y;
			}

			void fix_insert(Node *node)
			{
				while (node != _root && node->parent->color == RED)
				{
					/*left rotation moves
					check if parent of newnode is left child*/
					if (node->parent == node->parent->parent->left) {
						Node *node_parent_brother = node->parent->parent->right;
						if (node_parent_brother->color == RED) {
							/*case 1 - 
							if parent brother is red then recolor both parents and grandparent*/	
							node->parent->color = BLACK;
							node_parent_brother->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else {
							// means right brother is black
							/*case 3 - 
							if parent brother is black then we need to do left right rotation*/
							if (node == node->parent->right) {
								node = node->parent;
								left_rotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							right_rotate(node->parent->parent);
						}
					}
					else {
						// means parent brother is right child
						Node *node_parent_brother = node->parent->parent->left;
						if (node_parent_brother->color == RED) {
							/*case 2 -
							if parent brother is red then recolor both parents and grandparent*/
							node->parent->color = BLACK;
							node_parent_brother->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else {
							// means left brother is black
							if (node == node->parent->left) {
								/*case 4 - 
							if parent brother is black then we need to do right left rotation*/
								node = node->parent;
								right_rotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							left_rotate(node->parent->parent);
						}
					}
				}
				// make root black
				_root->color = BLACK;
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{
				Node *node = find_node(value.first);
				
				if (node != _nil)
					return ft::make_pair(iterator(node), false);
				node_pointer new_node = _node_alloc.allocate(1);
				Node *y = NULL;
				Node *x = _root;
				_node_alloc.construct(new_node, Node(value,  NULL, _nil, _nil, RED));
				while (x != _nil)
				{
					y = x;
					if (_comp(new_node->value.first, x->value.first))
						x = x->left;
					else
						x = x->right;
				}
				// newnode gets its parent
				new_node->parent = y;
				if (y == NULL)
					_root = new_node;
				// parent gets its new child by comparing the newnode's value with the parent's value
				else if (_comp(new_node->value.first, y->value.first))
					y->left = new_node;
				else
					y->right = new_node;
				// means that the new node is the root
				if (new_node->parent == NULL) {
					new_node->color = BLACK;
					return ft::make_pair(iterator(new_node), true);
				}
				// check if parent is a root then return
				if (new_node->parent->parent == NULL)
					return ft::make_pair(iterator(new_node), true);
				
				fix_insert(new_node);
				return ft::make_pair(iterator(new_node), true);
			}

			Node *find_node(const  Key& key)
			{
				Node *node = _root;
				while (node != _nil)
				{
					if (key == node->value.first)
						return node;
					else if (_comp(key, node->value.first))
						node = node->left;
					else
						node = node->right;
				}
				return _nil;
			}

			void transplant(Node *node, Node *v)
			{
				// if node is root then v becomes root
				if (node->parent == NULL)
					_root = v;
				else if (node == node->parent->left)
					node->parent->left = v;
				else
					node->parent->right = v;
				v->parent = node->parent;
			}

			Node *minimum(Node *node)
			{
				while (node->left != _nil)
					node = node->left;
				return node;
			}

			void fix_delete(Node *node)
			{
				while (node != _root && node->color == BLACK) {
					if (node == node->parent->left) {
						Node *brother = node->parent->right;
						// if borther is red
						if (brother->color == RED) {
							// case 2 - node's sibling is red - recolor and rotate
							brother->color = BLACK;
							node->parent->color = RED;
							left_rotate(node->parent);
							// update node brother to new brother after rotation
							brother = node->parent->right;
						}
						// if brother childs are black
						if (brother->left->color == BLACK && brother->right->color == BLACK) {
							/*(case 3 - 4) - node's sibling is black and both of node's sibling's children are black
							push black to parent and recolor*/
							brother->color = RED;
							// move double black to parent (if parent is root then it will be black)
							node = node->parent;
						}
						// brother left child is red and right child is black (case 5 - case 6)
						else {
							if (brother->right->color == BLACK) {
								/*case 5 - node's sibling is black, node's sibling's left child is red, and node's sibling's right child is black
								right rotation and recolor*/
								brother->left->color = BLACK;
								brother->color = RED;
								right_rotate(brother);
								// update node brother to new brother after rotation
								brother = node->parent->right;
							}
							/*case 6 - node's sibling is black and node's sibling's right child is red
							left rotation and recolor*/
							// red parent of (case 4)
							brother->color = node->parent->color;
							// if parent is red then brother will be red and parent will be black
							node->parent->color = BLACK;
							brother->right->color = BLACK;
							left_rotate(node->parent);
							// double black is fixed in case 6 *
							node = _root;
						}
					}
					else
					{
						Node *brother = node->parent->left;
						// if brother is red
						if (brother->color == RED)
						{
							// case 2 - node's sibling is red - recolor and rotate
							brother->color = BLACK;
							node->parent->color = RED;
							right_rotate(node->parent);
							// update node brother to new brother after rotation
							brother = node->parent->left;
						}
						// if brother childs are black
						if (brother->right->color == BLACK && brother->left->color == BLACK)
						{
							/*(case 3 - 4) - node's sibling is black and both of node's sibling's children are black */
							brother->color = RED;
							node = node->parent;
						}
						else
						{
							// brother right child is red and left child is black (case 5 - case 6)
							if (brother->left->color == BLACK)
							{
								/*case 5 - node's sibling is black, node's sibling's right child is red, and node's sibling's left child is black */
								brother->right->color = BLACK;
								brother->color = RED;
								left_rotate(brother);
								// update node brother to new brother after rotation
								brother = node->parent->left;
							}
							/*case 6 - node's sibling is black and node's sibling's left child is red */
							brother->color = node->parent->color;
							node->parent->color = BLACK;
							brother->left->color = BLACK;
							right_rotate(node->parent);
							// double black is fixed in case 6 *
							node = _root;
						}
					}
				}
				node->color = BLACK;
			}

			void erase(Node *node)
			{
				Node *y = node;
				Node *x = _nil;
				int y_original_color = y->color;
				/*check if node have one child and no child*/
				if (node->left == _nil) {
					x = node->right;
					transplant(node, node->right);
				}
				else if (node->right == _nil) {
					x = node->left;
					transplant(node, node->left);
				}
				/* if node have both children then 
				find inorder succerror (min key && leaf node)
				and replace it with delete node*/
				else {
					y = minimum(node->right);
					y_original_color = y->color;
					x = y->right;
					/*successor is a child of target node*/
					if (y->parent == node)
						x->parent = y;
					else
					{
						/*remove y from its current position and
						replace it with its right child*/
						transplant(y, y->right);
						y->right = node->right;
						y->right->parent = y;
					}
					/*remove node from its current position
					and replace it with y*/
					transplant(node, y);
					// update left child
					y->left = node->left;
					// update parent of left child
					y->left->parent = y;
					y->color = node->color;
				}
				// if double black fix it
				if (y_original_color == BLACK){
					fix_delete(x);
				}
				// destroy node
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				
			}

			size_type erase(const  Key& key)
			{
				Node *node = find_node(key);
				if (node == _nil)
					return 0;
				erase(node);
				return 1;
			}

			void clear(Node *node)
			{
				if (_root->parent == NULL)
					return;
				clear(node->left);
				clear(node->right);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void clear(){

				clear(_root);
			}

			void swap(Set_Bst& other)
			{
				std::swap(_root, other._root);
				std::swap(_nil, other._nil);
			}

			/********** ITERATORS ************/

			iterator begin()
			{
				Node *node = _root;
				while (node->left != _nil){
					node = node->left;
				}
				return iterator(node, _nil);
			}

			iterator end()
			{
				Node *node = _root;
				while (node->right != _nil){
					node = node->right;
				}
				_nil->parent = node;
				_nil->value = node->value;
				return iterator(_nil, _nil);
			}

			const_iterator begin() const
			{
				Node *node = _root;
				while (node->left != _nil){
					node = node->left;
				}
				return const_iterator(node, _nil);
			}

			const_iterator end() const
			{
				Node *node = _root;
				while (node->right != _nil){
					node = node->right;
				}
				_nil->parent = node;
				_nil->value = node->value;
				return const_iterator(_nil, _nil);
			}

			reverse_iterator rbegin()
			{
				Node *node = _root;
				while (node->right != _nil){
					node = node->right;
				}
				_nil->parent = node;
				return reverse_iterator(iterator(_nil, _nil));
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			/********** Lookup ************/

			size_type count (const Key& key) const
			{
				if (find(key) == end())
					return 0;
				return 1;
			}

			iterator find(const Key& key)
			{
				Node *node = _root;
				while (node != _nil){
					if (node->value.first == key)
						return iterator(node, _nil);
					else if (node->value.first < key)
						node = node->right;
					else
						node = node->left;
				}
				return iterator(_nil, _nil);
			}

			const_iterator find( const Key& key ) const{
				Node *node = _root;
				while (node != _nil){
					if (node->value.first == key)
						return const_iterator(node, _nil);
					else if (node->value.first < key)
						node = node->right;
					else
						node = node->left;
				}
				return const_iterator(_nil, _nil);
			}

			iterator lower_bound(const Key& key)
			{
				Node *node = _root;
				while (node != _nil){
					if (node->value.first == key)
						return iterator(node, _nil);
					else if (node->value.first < key)
						node = node->right;
					else
						node = node->left;
				}
				return iterator(_nil, _nil);
			}

			iterator upper_bound(const Key& key)
			{
				iterator it = lower_bound(key);
        		while (it != end() && !(key < *it))
        		    ++it;
        		return it;
			}

			/*    additions     */

			node_pointer nil() const{
				return _nil;
			}

	};
}

#endif