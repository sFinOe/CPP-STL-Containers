#ifndef STACK_HPP
# define STACK_HPP
#include <common.hpp>
#include <vector.hpp>

namespace ft
{
	// stack is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO (last-in first-out) data structure.
	// Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.
	// The functions push and pop add and remove elements from the stack, respectively.
	// The function top returns a reference to the top element in the stack.

	// T : type of the elements of the container
	// Container : container type (vector) will be used to implement the stack
	template <class T, class Container = ft::vector<T> >

	class stack
	{
		public :

			/********* member types *********/

			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;
		
		protected :
				// container to hold the elements of the stack (vector)
				container_type _container;

		public :

			/********* constructor and destructor *********/

			// copy constructor (deep copy) new obj idenpendent from the old one
			stack( const stack& other ){
				_container = other._container;
			}
			explicit stack(const container_type& ctnr = container_type()) : _container(ctnr) {} // if no argument is passed, the default constructor of the container is called (vector) create empty cntr
			//else the constructor of the container is called with the argument passed
			// destructor
			// we dont need to do anytging here because the container (vector) will be destroyed automatically
			~stack() {}

			stack& operator=( const stack& other ){
				_container = other._container;
				return (*this);
			}

			container_type get_container() const{
				return (_container);
			}

			/********* member functions *********/

			// empty() returns whether the stack is empty: i.e. whether its size is zero.
			bool empty() const{
				return (_container.empty());
			}
			// size() returns the number of elements in the stack.
			size_type size() const{
				return (_container.size());
			}
			// top() returns a reference to the top element in the stack.
			reference top(){
				return (_container.back());
			}
			 // top() returns a reference to the top element in the stack.
			const_reference top() const{
				return (_container.back());
			}
			// push() adds a new element at the top of the stack, above its current top element. The content of this new element is initialized to val.
			void push(const value_type& val){
				_container.push_back(val);
			}
			// pop() removes the element on top of the stack, effectively reducing its size by one.
			void pop(){
				_container.pop_back();
			}
	};


			/*********operator overloads *********/

			// friend bool operator means that the function is not a member of the class but it has access to the private or protected members of the class
			// so the oprator funtion can access data of stack to make a comparison 
			template <class T, class Container>
			bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs.get_container() == rhs.get_container());
			}

			template <class T, class Container>
			bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs.get_container() != rhs.get_container());
			}

			template <class T, class Container>
			bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs.get_container() < rhs.get_container());
			}

			template <class T, class Container>
			bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs.get_container() <= rhs.get_container());
			}

			template <class T, class Container>
			bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs.get_container() > rhs.get_container());
			}

			template <class T, class Container>
			bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs.get_container() >= rhs.get_container());
			}

}



#endif