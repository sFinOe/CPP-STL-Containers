#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <common.hpp>
#include <vector_iterator.hpp>

namespace ft 
{

	template < class _T, class _Alloc = allocator<_T> >
	class vector
	{
		/********** Private Member variables **********/
	
		_T* _data;
		size_t _size;
		size_t _capacity;
		_Alloc _alloc;

		public:

			/********** Member types **********/

			typedef _T value_type;
			typedef _Alloc	allocator_type;
			typedef typename _Alloc::reference reference;
			typedef typename _Alloc::const_reference const_reference;
			typedef typename _Alloc::pointer pointer;
			typedef typename _Alloc::const_pointer const_pointer;
			typedef size_t size_type;

			typedef ft::vector_iterator<value_type> iterator;
			typedef ft::vector_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		

			/********** Member functions **********/
	
			// Constructors

			// empty container constructor (default constructor)
			// Constructs an empty container, with no elements.
			explicit vector (const allocator_type& alloc = allocator_type()){
				(void)alloc;
				_data = NULL;
				_size = 0;
				_capacity = 0;
			}
			// fill constructor
			// Constructs a container with n elements. Each element is a copy of val.

			// size_type n (int) how many element will allocate
			//value_type val (value type container will hold for example <int>)
			// allocator_type refrence to allocator for manage memory
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				(void)alloc;
				_data = NULL;
				_size = 0;
				_capacity = 0;
				assign(n, val);
			}
			// range constructor
			// Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value>::type* = 0){
				(void)alloc;
				_data = NULL;
				_size = 0;
				_capacity = 0;
				assign(first, last);
			}
			// copy constructor
			// Constructs a container with a copy of each of the elements in x, in the same order.
			vector (const vector& x){
				_data = NULL;
				_size = 0;
				_capacity = 0;
				assign(x.begin(), x.end());
			}

			// Destructor

			~vector(){
				clear();
			}


			vector& operator= (const vector& x){
				assign(x.begin(), x.end());
				return *this;
			}

			allocator_type get_allocator() const{
				return _alloc;
			}

			/************ Element access  **********/

			// Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.


			reference operator[] (size_type n){
				return _data[n];
			}

			const_reference operator[] (size_type n) const{
				return _data[n];
			}
	

      		reference at (size_type n){
				if (n >= _size)
					throw std::out_of_range("out of range");
				return _data[n];
			}
			const_reference at (size_type n) const{
				if (n >= _size)
					throw std::out_of_range("out of range");
				return _data[n];
			}

			reference front(){
				return _data[0];
			}

			const_reference front() const{
				return _data[0];
			}

			reference back(){
				return _data[_size - 1];
			}

			const_reference back() const{
				return _data[_size - 1];
			}

			value_type* data(){
				return _data;
			}

			const value_type* data() const{
				return _data;
			}


		/************* Iterators ***************/
		


			 iterator begin(){
				return iterator(_data);
			 }

			 iterator end(){
				return iterator(_data + _size);
			 }

			 const_iterator begin() const {
				return const_iterator(_data);
			 }

			 const_iterator end() const {
				return const_iterator(_data + _size);
			 }

			reverse_iterator rbegin(){
				return reverse_iterator(end());
			}

			reverse_iterator rend(){
				return reverse_iterator(begin());
			}

			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(end());
			}

			const_reverse_iterator rend() const{
				return const_reverse_iterator(begin());
			}

			/********** Modifiers ************/

			void clear(){
				// here i destroy all the of vector elements that are not needed anymore
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_size = 0;
			}

			iterator erase (iterator position){
				size_t index = position - begin();
				// here i shift the elements to the left to fill the gap
				for (size_t i = index; i < _size - 1; i++){
					_data[i] = _data[i + 1];
				}
				// here i destroy the elements that are not needed anymore
				for (size_t i = _size - 1; i < _size; i++)
					_alloc.destroy(_data + i);
				_size--;
				return iterator(_data + index);
			}
			template <class InputIterator>
			iterator erase (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_t index = first - begin();
				size_t range = last - first;
				// here i shift the elements to the left to fill the gap
				for (size_t i = index; i < _size - range; i++){
					_data[i] = _data[i + range];
				}
				// here i destroy the elements that are not needed anymore
				for (size_t i = _size - range; i < _size; i++)
					_alloc.destroy(_data + i);
				_size -= range;
				return iterator(_data + index);
			}

			void push_back (const value_type& val){
				if (_size == _capacity){
					size_t capacity = _capacity == 0 ? 1 : _capacity * 2;
					reserve(capacity);
				}
				_data[_size] = val;
				_size++;
				
			}

			void pop_back(){
				// here i destroy the last element _size - 1 because the index starts from 0
				_alloc.destroy(_data + _size - 1);
				_size--;
			}

			void swap (vector& x){
				// i create a temporary vector to store the values of the current vector
				_T* tmp_data = _data;
				size_t tmp_size = _size;
				size_t tmp_capacity = _capacity;
				_data = x._data;
				_size = x._size;
				_capacity = x._capacity;
				x._data = tmp_data;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
			}

			void resize (size_type n, value_type val = value_type()){
				// if n smaller than size i destroy the elements that are not needed anymore
				if (n < _size){
					for (size_t i = n; i < _size; i++)
						_alloc.destroy(_data + i);
					_size = n;
				}
				// if n bigger than size i push back val
				else if (n > _size){
					for (size_t i = _size; i < n; i++){
						if (_capacity == _size){
							size_t capacity = _capacity == 0 ? 1 : _capacity + 1;
							reserve(capacity);
						}
						_data[_size] = val;
						_size++;
					}
				}
			}


			/////////////// ASSIGN ///////////////////

			// assign for iterators range if the type is not an integral type
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				clear();
				while (first != last)
				{
					if ( _size == _capacity){
						size_t capacity = _capacity == 0 ? 1 : _capacity + 1;
						reserve(capacity);
					}
					_data[_size] = *first;
					_size++;
					first++;
				}
			}

			// assign for integral type if the type is an integral type (n, val) (int , long long ...)
			void assign (size_type n, const value_type& val){
				clear();
				for (size_t i = 0; i < n; i++){
					if ( _size == _capacity){
						size_t capacity = _capacity == 0 ? 1 : _capacity + 1;
						reserve(capacity);
					}
					_data[_size] = val;
					_size++;
				}
			}
		
			/////////////// INSERT ///////////////////

			// from iterator pos will insert _T val // std::vector<int> v{1, 2, 3}; v.insert(v.begin() + 1, 0); => {1, 0, 2, 3}
			iterator insert (iterator position, const value_type& val){
				size_t pos = position - begin();
				// if the vector is full need to reallocate more memory
				if ( _size == _capacity){
					size_t capacity = _capacity == 0 ? 1 : _capacity * 2;
					reserve(capacity);
					position = begin() + pos;
				}
				// move all the elements to the right by one position to make space for the new element to be inserted
				for (size_t i = _size; i > pos; i--)
					_data[i] = _data[i - 1];
				_data[pos] = val;
				_size++;
				return begin() + pos;
			}
			// from iterator pos will insert _T val with n times // std::vector<int> v{1, 2, 3}; v.insert(v.begin() + 1, 2, 0); => {1, 0, 0, 2, 3}
			void insert (iterator position, size_type n, const value_type& val){
				// cout << "insert" << endl;
				size_t pos = position - begin();
				if (_capacity == 0)
					reserve(n);
				else if (_size + n > _capacity){
					reserve(_capacity * 2);
					position = begin() + pos;
				}
				// move all the elements to the right by n positions to make space for the new elements to be inserted
				for (size_t i = _size; i > pos; i--)
					_data[i + n - 1] = _data[i - 1];
				// insert the new elements
				for (size_t i = 0; i < n; i++)
					_data[pos + i] = val;
				_size += n;
			}

			// from iterator pos will insert the range [first, last) // std::vector<int> v{1, 2, 3}; v.insert(v.begin() + 1, v.begin(), v.end()); => {1, 1, 2, 3, 2, 3, 2, 3}
			template <typename InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_t pos = position - begin();
				// get the distance between the two iterators and move all the elements to the right by the distance to make space for the new elements to be inserted
				size_t distance = last - first;
				if (_capacity == 0)
					reserve(distance);
				else if (_size + distance > _capacity){
					// if the vector is full need to reallocate more memory
					reserve((_capacity * 2) + distance);
					position = begin() + pos;
				}
				for (size_t i = _size; i > pos; i--)
					_data[(i + distance) - 1] = _data[i - 1];
				for (size_t i = 0; i < distance; i++)
					_data[pos + i] = *first++;
				_size += (distance);
			}

		

			/****************** Capacity ******************/

			void reserve (size_type n){

				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity){
					_T *tmp = _data;
					_data = _alloc.allocate(n);
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(_data + i, tmp[i]);
					_capacity = n;
					_alloc.deallocate(tmp, _capacity);
				}
			}

			bool empty() const{
				return (_size == 0);
			}

			size_type capacity() const{
				return (_capacity);
			}

			size_type size() const{
				return (_size);
			}

			size_type max_size() const{
				if (sizeof(long) == 8){
					size_t max = (std::pow(2, 64) / sizeof(_T)) / 2;
					return (max - 1);
				}
				else{
					size_t max = (std::pow(2, 32) / sizeof(_T)) / 2;
					return (max - 1);
				}
			}

	};

	/**************** Non-member Functions *********************/

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() < rhs.size())
			return (true);
		else if (lhs.size() > rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] < rhs[i])
				return (true);
			else if (lhs[i] > rhs[i])
				return (false);
		return (false);
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs < rhs));
	}


}

#endif
