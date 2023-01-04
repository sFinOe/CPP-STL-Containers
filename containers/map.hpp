#ifndef MAP_HPP
#define MAP_HPP
#include <common.hpp>



namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public :

			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<Key, T> value_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef bst_node<value_type> node_type;
			typedef bst_node<value_type>* node_pointer;
			
			// iterator

			typedef typename ft::Bst<value_type, key_compare>::iterator iterator;
			typedef typename ft::Bst<value_type, key_compare>::const_iterator const_iterator;
			typedef typename ft::Bst<value_type, key_compare>::reverse_iterator reverse_iterator;
			typedef typename ft::Bst<value_type, key_compare>::const_reverse_iterator const_reverse_iterator;

			class value_compare
			{
				friend class map;
				protected :
					/*protected constructor because it is intended to 
					be used only as a base class for comparison classes used by the map
					that why we use friend*/
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public :

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					// if x < y return true
					bool operator()(const value_type& x, const value_type& y) const{
						return comp(x.first, y.first);
					}
			};
	
		private :
			allocator_type _alloc;
			key_compare _comp;
			Bst<value_type, key_compare> _tree;
			size_type _size;

			

		public :

			/********** Constructors **********/

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(), _size(0) {}
			template <class InputIterator> 
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) : _alloc(alloc), _comp(comp), _tree(), _size(0){
				while (first != last){
					_tree.insert(*first);
					first++;
					_size++;
				}
			}

			map (const map& x){
				*this = x;
			}

			~map(){
				_tree.clear();
			}

			map& operator=( const map& other ){
				_tree = other._tree;
				_size = other._size;
				return *this;
			}

			allocator_type get_allocator() const{
				return _alloc;
			}


			/********** Modifiers **********/


			ft::pair<iterator, bool> insert( const value_type& value ){
				ft::pair<iterator, bool> res = _tree.insert(value);
				if (res.second == true)
					_size++;
				return res;
			}

			iterator insert(iterator pos, const value_type& value){
				(void)pos;
				ft::pair<iterator, bool> res = _tree.insert(value);
				if (res.second == true)
					_size++;
				return res.first;
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0){

				while (first != last && first != _tree.nil()){
					ft::pair<iterator, bool> res = _tree.insert(*first);
					if (res.second == true)
						_size++;
					first++;
				}
			}

			void erase(iterator pos){
				if (_tree.find_node(pos->first) != _tree.nil())
					_size--;
				_tree.erase(pos->first);
			}

			size_type erase(const Key& key){
				if (_tree.find_node(key) != _tree.nil())
					_size--;
				return _tree.erase(key);
			}
			
			void erase (iterator first, iterator last){
				while (first != last && first != _tree.nil()){
					_tree.erase(first->first);
					first = _tree.begin();
					_size--;
				}
			}

			void clear(){
				_tree.clear();
				_size = 0;
			}

			void swap (map& x){
				_tree.swap(x._tree);
			}


			/********** Capacity **********/

			bool empty() const{
				if (_size == 0)
					return true;
				return false;
			}

			size_type size() const{
				return _size;
			}

			size_type max_size() const{
				if (sizeof(long) == 8){
					size_t max = (std::pow(2, 64) / sizeof(T)) / 2;
					return (max - 2075258708292324557);
				}
				else{
					size_t max = (std::pow(2, 32) / sizeof(T)) / 2;
					return (max - 2075258708292324557);
				}
			}


			/********** Element access **********/

			T &operator[](const Key &key){
				iterator it = _tree.find(key);
				if (it == _tree.end()){
					_tree.insert(ft::make_pair(key, T()));
					it = _tree.find(key);
					_size++;
				}
				return it->second;
			}
			mapped_type& at (const key_type& k){
				iterator it = _tree.find(k);
				if (it == _tree.end())
					throw std::out_of_range("map::at");
				return it->second;
			}
			const mapped_type& at (const key_type& k) const{
				iterator it = _tree.find(k);
				if (it == _tree.end())
					throw std::out_of_range("map::at");
				return it->second;
			}

			/********** Iterator **********/


			iterator begin(){
				return iterator(_tree.begin());
			}

			const_iterator begin() const{
				return const_iterator(_tree.begin());
			}

			iterator end(){
				return iterator(_tree.end());
			}

			const_iterator end() const{
				return const_iterator(_tree.end());
			}

			reverse_iterator rbegin(){
				return reverse_iterator(_tree.rbegin());
			}

			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(_tree.rbegin());
			}

			reverse_iterator rend(){
				return reverse_iterator(_tree.rend());
			}

			const_reverse_iterator rend() const{
				return const_reverse_iterator(_tree.rend());
			}

			/********** Lookup **********/

			iterator find (const key_type& k){
				return _tree.find(k);
			}

			const_iterator find (const key_type& k) const{
				return const_iterator(_tree.find(k),  _tree.nil());
			}

			size_type count (const key_type& k) const{
				return _tree.count(k);
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ){
				iterator first = lower_bound(key);
				iterator last = upper_bound(key);
				return ft::make_pair(first, last);
			}


			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{
				const_iterator first = lower_bound(key);
				const_iterator last = upper_bound(key);
				return ft::make_pair(first, last);
			}

			iterator lower_bound (const key_type& k){
				// find element equal or greater than given key
				return _tree.lower_bound(k);
			}

			const_iterator lower_bound (const key_type& k) const{
				// find element equal or greater than given key
				return const_iterator(_tree.lower_bound(k));
			}

			iterator upper_bound (const key_type& k){
				// find element greater than given key
				return iterator(_tree.upper_bound(k), _tree.nil());
			}

			const_iterator upper_bound (const key_type& k) const{
				// find element greater than given key
				return const_iterator(_tree.upper_bound(k), _tree.nil());
			}

			value_compare value_comp() const{
				return value_compare(_comp);
			}

			key_compare key_comp() const{
				return key_compare(_comp);
			}
			

	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator ite = lhs.end();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it2 = rhs.begin();
		while (it != ite){
			if (*it != *it2)
				return false;
			it++;
			it2++;
		}
		return true;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator ite = lhs.end();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it2 = rhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator ite2 = rhs.end();
		while (it != ite && it2 != ite2){
			if (*it < *it2)
				return true;
			else if (*it2 < *it)
				return false;
			it++;
			it2++;
		}
		if (it == ite && it2 != ite2)
			return true;
		return false;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap ( ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y ){
		x.swap(y);
	}

}



#endif