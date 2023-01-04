#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include <common.hpp>

using namespace std;

namespace ft
{
	
	template <typename T, typename V>
	class map_iterator
	{
		public :

		typedef T node_type;
		typedef T* node_pointer;
		typedef typename ft::iterator_traits<V*>::difference_type difference_type;
		typedef typename ft::iterator_traits<V*>::value_type value_type;
		typedef typename ft::iterator_traits<V*>::pointer pointer;
		typedef typename ft::iterator_traits<V*>::reference reference;
		typedef std::bidirectional_iterator_tag iterator_category;


		protected :
			node_pointer _node;
			node_pointer _nil;

		public :

			map_iterator() : _node(NULL), _nil(NULL) {}
			map_iterator(node_pointer nil) : _node(NULL), _nil(nil) {}
			map_iterator(node_pointer node, node_pointer nil) : _node(node), _nil(nil) {}
			map_iterator(const map_iterator& other, node_pointer nil) : _node(other._node), _nil(nil) {}
			~map_iterator() {}

			map_iterator& operator=(const map_iterator& other){
				_node = other._node;
				_nil = other._nil;
				return *this;
			}

			operator map_iterator<const T, const V>() const {
        	    return (map_iterator<const T, const V>(this->_node, this->_nil));
        	}

			reference operator*() const{
				return _node->value;
			}
			// make it work with map only

			pointer operator->() const{
				return &_node->value;

			}

			map_iterator& operator++(){						
				if (_node->right != _nil){
					// if node have right we go deep left in right
					_node = _node->right;
					while (_node->left != _nil)
						_node = _node->left;
				}
				else{
					// if node have no right we go to next parent
					node_pointer tmp = _node->parent;
					while (tmp != NULL && _node == tmp->right){
						_node = tmp;
						tmp = tmp->parent;
						if (tmp == NULL){
							tmp = _nil;
							break;
						}
					}
					_node = tmp;
				}
				return *this;
			}

			map_iterator operator++(int){
				map_iterator tmp(*this);
				operator++();
				return tmp;
			}

			map_iterator& operator--(){
				if (_node->left != _nil){
					// if node have left we go deep right in left
					_node = _node->left;
					while (_node->right != _nil){
						_node = _node->right;
					}
				}
				else{
					// if node have no left we go to next parent
					node_pointer tmp = _node->parent;
					if (_node == _nil){
						tmp = _node->parent;
						_node = tmp;
						return *this;
					}
					while (tmp != _nil && _node == tmp->left){
						_node = tmp;
						tmp = tmp->parent;
						if (tmp == NULL){
							tmp = _nil;
							break;
						}
					}
					_node = tmp;
					
				}
				return *this;
			}

			map_iterator operator--(int){
				map_iterator tmp(*this);
				operator--();
				return tmp;
			}

			bool operator==(const map_iterator& other) const{
				return _node == other._node;
			}

			bool operator!=(const map_iterator& other) const{
				return _node != other._node;
			}
				
	};

}



#endif