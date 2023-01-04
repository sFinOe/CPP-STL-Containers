#ifndef SET_HPP
#define SET_HPP
#include <common.hpp>

namespace ft
{
	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set
	{
		public :
			
			typedef Key key_type;
			typedef ft::pair<Key, Key> value_type;
			typedef Key key_value;
			typedef size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;

			// iterator
		
			typedef typename ft::Set_Bst<value_type, key_compare>::iterator iterator;
			typedef typename ft::Set_Bst<value_type, key_compare>::const_iterator const_iterator;
			typedef typename ft::Set_Bst<value_type, key_compare>::reverse_iterator reverse_iterator;
			typedef typename ft::Set_Bst<value_type, key_compare>::const_reverse_iterator const_reverse_iterator;

		private :
			allocator_type _alloc;
			key_compare _comp;
			Set_Bst<value_type, key_compare> _tree;
			size_type _size;

		public :

			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(), _size(0) {}

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(), _size(0) {
				insert(first, last);
			}

			set (const set& x) : _alloc(x._alloc), _comp(x._comp), _tree(x._tree), _size(x._size) {}

			~set() {}

			set& operator= (const set& x) {
				if (this != &x) {
					_alloc = x._alloc;
					_comp = x._comp;
					_tree = x._tree;
					_size = x._size;
				}
				return *this;
			}

			iterator begin() {
				return _tree.begin();
			}

			const_iterator begin() const {
				return _tree.begin();
			}

			iterator end() {
				return _tree.end();
			}

			const_iterator end() const {
				return _tree.end();
			}

			reverse_iterator rbegin() {
				return _tree.rbegin();
			}

			const_reverse_iterator rbegin() const {
				return _tree.rbegin();
			}

			reverse_iterator rend() {
				return _tree.rend();
			}

			const_reverse_iterator rend() const {
				return _tree.rend();
			}

			bool empty() const {
				return _size == 0;
			}

			size_type size() const {
				return _size;
			}

			size_type max_size() const{
				if (sizeof(long) == 8){
					size_t max = (std::pow(2, 64) / sizeof(Key)) / 2;
					return (max - 2075258708292324557);
				}
				else{
					size_t max = (std::pow(2, 32) / sizeof(Key)) / 2;
					return (max - 2075258708292324557);
				}
			}

			ft::pair<iterator,bool> insert (const key_value& val) {
				ft::pair<iterator, bool> ret;
				ret = _tree.insert(ft::make_pair(val, val));
				ret.second = ret.first != _tree.end();
				if (ret.second)
					_size++;
				return ret;
			}

			iterator insert (iterator position, const key_value& val) {
				(void)position;
				return insert(val).first;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				while (first != last && first != _tree.nil()) {
					insert(*first);
					first++;
				}
			}

			void erase (iterator position) {
				_tree.erase(*position);
				_size--;
			}

			size_type erase (const key_value& k) {
				size_type ret = _tree.erase(k);
				_size -= ret;
				return ret;
			}

			void erase (iterator first, iterator last) {
				while (first != last && first != _tree.nil()) {
					erase(*first);
					first = _tree.begin();
				}
			}

			void swap (set& x) {
				_tree.swap(x._tree);
			}

			void clear() {
				_tree.clear();
				_size = 0;
			}

			key_compare key_comp() const {
				return _comp;
			}

			value_compare value_comp() const {
				return value_compare(_comp);
			}

			iterator find (const key_value& k) {
				return _tree.find(k);
			}

			const_iterator find (const key_value& k) const {
				return _tree.find(k);
			}

			size_type count (const key_value& k) const {
				return _tree.count(k);
			}

			iterator lower_bound (const key_value& k) {
				return _tree.lower_bound(k);
			}

			const_iterator lower_bound (const key_value& k) const {
				return _tree.lower_bound(k);
			}

			iterator upper_bound (const key_value& k) {
				return _tree.upper_bound(k);
			}

			const_iterator upper_bound (const key_value& k) const {
				return _tree.upper_bound(k);
			}

			ft::pair<const_iterator,const_iterator> equal_range (const key_value& k) const {

				const_iterator first = lower_bound(k);
				const_iterator second = upper_bound(k);
				return ft::make_pair(first, second);

			}

			ft::pair<iterator,iterator> equal_range (const key_value& k) {

				iterator first = lower_bound(k);
				iterator second = upper_bound(k);
				return ft::make_pair(first, second);
			}

	};

	template <class Key, class Compare, class Alloc>
	bool operator== (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class Compare, class Alloc>
	bool operator!= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<  (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class Compare, class Alloc>
	bool operator<= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>  (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) {
		return rhs < lhs;
	}

	template <class Key, class Compare, class Alloc>
	bool operator>= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class Key, class Compare, class Alloc>
	void swap (set<Key,Compare,Alloc>& x, set<Key,Compare,Alloc>& y) {
		x.swap(y);
	}


}

#endif